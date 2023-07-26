QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    01_data_structs_processing/fill_node.c \
    01_data_structs_processing/move_node.c \
    01_data_structs_processing/pop.c \
    01_data_structs_processing/push.c \
    01_data_structs_processing/remove_head_node.c \
    01_data_structs_processing/remove_struct.c \
    02_evaluations/01_convert_infix_to_RPN.c \
    02_evaluations/02_close_bracket_processing.c \
    02_evaluations/03_end_of_expression_processing.c \
    02_evaluations/04_token_processing.c \
    02_evaluations/05_container_packing.c \
    02_evaluations/06_create_mult.c \
    02_evaluations/07_container_sending.c \
    02_evaluations/08_evaluate_expression.c \
    02_evaluations/09_numerical_calculation.c \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    data_structures.h \
    mainwindow.h \
    smart_calc.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
