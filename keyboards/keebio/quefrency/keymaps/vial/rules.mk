VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes
LTO_ENABLE = yes
COMBO_ENABLE = no

MCU = atmega32u4
F_CPU = 16000000
ARCH = AVR8
F_USB = $(F_CPU)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
BOOTLOADER = caterina
