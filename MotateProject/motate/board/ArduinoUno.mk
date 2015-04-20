# ----------------------------------------------------------------------------
# This file is part of the Motate project.

ifeq ("$(BOARD)","Uno")
    BASE_BOARD = uno
    DEVICE_DEFINES += MOTATE_BOARD="Uno"
    DEVICE_DEFINES += MOTATE_CONFIG_HAS_USBSERIAL=1
endif

ifeq ("$(BASE_BOARD)","uno")
    _BOARD_FOUND = 1

    FIRST_LINK_SOURCES += $(wildcard ${MOTATE_PATH}/Atmel_avr/*.cpp)

    CHIP = atmega328p
    export CHIP
    CHIP_LOWERCASE = atmega328p

    BOARD_PATH = ${MOTATE_PATH}/board/ArduinoUno
    DEVICE_INCLUDE_DIRS += $(BOARD_PATH)

    PLATFORM_BASE = ${MOTATE_PATH}/platform/atmel_atmega
    include $(PLATFORM_BASE).mk
endif
