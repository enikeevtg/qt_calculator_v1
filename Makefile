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

# FILENAMES
SRC_DIR = ./sources/
ATTEMPT_DIR = $(SRC_DIR)00_attempt_at_writing/
DATA_STRUCT_DIR = $(SRC_DIR)01_data_structs_processing/
EVAL_DIR = $(SRC_DIR)02_evaluations/
SRC = $(wildcard $(DATA_STRUCT_DIR)*.c)
SRC += $(wildcard $(EVAL_DIR)*.c)

UI_DIR = ./05_ui/

BUILD_DIR = ./build/
APP = qt_calculator_v1.app

# BUILD
all: clean install launch

# APP
install:
	$(MK) $(BUILD_DIR)
	cd $(BUILD_DIR) && qmake ../$(SRC_DIR)$(UI_DIR)qt_calculator_v1.pro && make -j6 && make clean && rm -rf .qmake.stash Makefile

launch:
	open $(BUILD_DIR)$(APP)

uninstall:
	rm -rf $(BUILD_DIR)*

dvi:
	open $(SRC_DIR)readme.html

dist:
	tar -zcvf qt_calculator_v1.tar $(ALL_DIRS) Makefile

app_leaks:
	$(LEAKS) $(BUILD_DIR)$(APP)/Contents/MacOS/qt_calculator_v1

# SERVICES
style:
	clang-format --style=google -n *.h $(SRC) $(TESTS_SRC) $(CREDIT_DIR)* $(DEPOSIT_DIR)* $(UI_DIR)*.cpp $(UI_DIR)*.h

gost:
	clang-format --style=google -i *.h $(SRC) $(TESTS_SRC) $(CREDIT_DIR)* $(DEPOSIT_DIR)* $(UI_DIR)*.cpp $(UI_DIR)*.h

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(SRC_DIR)*.o
	@$(RM) ./report/
	@$(RM) *.dSYM
	@$(RM) a.out *.tar
	@$(RM) *.gcno *.gcda
	@$(RM) $(TEST_EXE)
