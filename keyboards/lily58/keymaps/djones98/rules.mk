VIA_ENABLE = yes
VIAL_ENABLE = yes

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
BOOTMAGIC_ENABLE = yes
QMK_SETTINGS = yes
NKRO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
LTO_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pk

WPM_ENABLE = yes
OLED_ENABLE  = yes
OLED_DRIVER = ssd1306
OLED_TIMEOUT = 1000
OCEAN_DREAM_ENABLE = no
LUNA_ENABLE = yes
BONGOCAT_ENABLE = no
CRAB_ENABLE = yes
DEMON_ENABLE = no
DOG_ENABLE = no
BONGOCAT_KEYBOARD_ENABLE = no

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled_setup.c
  ifdef DOG_ENABLE
      ifeq ($(strip $(DOG_ENABLE)), yes)
        OPT_DEFS += -DDOG_ENABLE
      endif
  endif
  ifndef DOG_ENABLE
    OPT_DEFS += -DDOG_ENABLE
  endif

  ifdef BONGOCAT_KEYBOARD_ENABLE
      ifeq ($(strip $(BONGOCAT_KEYBOARD_ENABLE)), yes)
        OPT_DEFS += -DBONGOCAT_KEYBOARD_ENABLE
      endif
  endif
  ifndef BONGOCAT_KEYBOARD_ENABLE
    OPT_DEFS += -DBONGOCAT_KEYBOARD_ENABLE
  endif

  ifdef OCEAN_DREAM_ENABLE
      ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
        SRC += ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
      endif
  endif
  ifndef OCEAN_DREAM_ENABLE
      SRC += ocean_dream.c
      OPT_DEFS += -DOCEAN_DREAM_ENABLE
  endif

  ifdef LUNA_ENABLE
      ifeq ($(strip $(LUNA_ENABLE)), yes)
        SRC += luna.c
        OPT_DEFS += -DLUNA_ENABLE
      endif
  endif
  ifndef LUNA_ENABLE
    SRC += luna.c
    OPT_DEFS += -DLUNA_ENABLE
  endif

  ifdef BONGOCAT_ENABLE
    ifeq ($(strip $(BONGOCAT_ENABLE)), yes)
      SRC += bongocat.c
      OPT_DEFS += -DBONGOCAT_ENABLE
    endif
  endif
  ifndef BONGOCAT_ENABLE
    SRC += bongocat.c
    OPT_DEFS += -DBONGOCAT_ENABLE
  endif

  ifdef CRAB_ENABLE
    ifeq ($(strip $(CRAB_ENABLE)), yes)
      SRC += crab.c animation-utils.c
      OPT_DEFS += -DCRAB_ENABLE
    endif
  endif
  ifndef CRAB_ENABLE
    SRC += crab.c animation-utils.c
    OPT_DEFS += -DCRAB_ENABLE
  endif

  ifdef DEMON_ENABLE
    ifeq ($(strip $(DEMON_ENABLE)), yes)
      SRC += demon.c animation-utils.c
      OPT_DEFS += -DDEMON_ENABLE
    endif
  endif
  ifndef DEMON_ENABLE
    SRC += demon.c animation-utils.c
    OPT_DEFS += -DDEMON_ENABLE
  endif

endif

