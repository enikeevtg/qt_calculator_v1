.PHONY: all test gcov gcov_report style gost clean

# UTILITIES
CC = gcc
MK = mkdir -p
RM = rm -rf
OS := $(shell uname)
ifeq ($(OS), Darwin)
	LEAKS = CK_FORK=no leaks --atExit --
	REPORT_OPEN = open
else ifeq ($(OS), Linux)
	LEAKS =
	REPORT_OPEN = xdg-open
endif

# UTILITIES OPTIONS
DEBUG = -DDEBUG
CF = -Wall -Werror -Wextra
STD = -std=c11 -pedantic
ASAN = -g -fsanitize=address
ifeq ($(OS), Darwin)
	TEST_FLAGS = -lcheck
else ifeq ($(OS), Linux)
	TEST_FLAGS = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# FILENAMES
SRC_DIR = ./sources/
BUILD_DIR = build/
ATTEMPT_DIR = $(SRC_DIR)00_attempt_at_writing/
DATA_STRUCT_DIR = $(SRC_DIR)01_data_structs_processing/
EVAL_DIR = $(SRC_DIR)02_evaluations/
SRC = $(wildcard $(DATA_STRUCT_DIR)*.c)
SRC += $(wildcard $(EVAL_DIR)*.c)
TESTS_DIR = $(SRC_DIR)03_tests/
TESTS_SRC = $(wildcard $(TESTS_DIR)*.c)
TEST_EXE = ./tests_runner
APP = qt_calculator_v1.app

# BUILD
all: clean install launch

# TESTS
test: clean
	@$(CC) $(CF) $(ASAN) $(TESTS_SRC) $(SRC) -o $(TEST_EXE) $(TEST_FLAGS)
	$(TEST_EXE)

leaks: clean
	@$(CC) $(CF) $(ASAN) $(TESTS_SRC) $(SRC) -o $(TEST_EXE) $(TEST_FLAGS)
	@$(LEAKS) $(TEST_EXE)

valgrind:

gcov: gcov_report

gcov_report: clean
	@$(CC) $(CF) $(GCOV_FLAGS) $(ASAN) $(TESTS_SRC) $(SRC) -o $(TEST_EXE) $(TEST_FLAGS)
	@$(LEAKS) $(TEST_EXE)
	@lcov -t "./gcov" -o report.info --no-external -c -d .
	@genhtml -o report report.info
	@gcovr -r . --html-details -o ./report/coverage_report.html
	@$(REPORT_OPEN) ./report/index.html
	@rm -rf *.gcno *.gcda gcov_test *.info

# APP
install:
	$(MK) build
	cd $(SRC_DIR) && qmake && make && make clean && mv $(APP) ../$(BUILD_DIR)

launch:
	open $(BUILD_DIR)$(APP)

uninstall:
	rm -rf build

dvi:
	open $(SRC_DIR)readme.html

dist:
	@if [ ! -d build ] ; then echo "creating build" ; make install; fi
	@if [ -d build ] ; then tar -zcvf archive.tar build; else echo "build not exists, error!"; exit 1; fi

app_leaks:
	$(LEAKS) ./$(BUILD_DIR)$(APP)/Contents/MacOS/qt_calculator_v1

# SERVICES
style:
	clang-format --style=google -n $(SRC_DIR)*.h $(SRC_DIR)*.cpp $(SRC) $(TESTS_SRC)

gost:
	clang-format --style=google -i $(SRC_DIR)*.h $(SRC_DIR)*.cpp $(SRC) $(TESTS_SRC)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(SRC_DIR)*.o
	@$(RM) ./report/
	@$(RM) *.dSYM
	@$(RM) a.out *.tar
	@$(RM) *.gcno *.gcda
	@$(RM) $(TEST_EXE)
