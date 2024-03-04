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

WPM_ENABLE = yes

OLED_ENABLE  = yes
OLED_DRIVER = ssd1306
OLED_TIMEOUT = 1000
#OLED_FADE_OUT = yes
#OLED_FADE_OUT_INTERVAL = 6
#OLED_SCROLL_TIMEOUT = 1000
#OLED_BRIGHTNESS = 100
### ANIMATIONS_ENABLE {{{
# And if you want to disable it without turning off the OLED Driver you can simply set
OCEAN_DREAM_ENABLE = yes
LUNA_ENABLE = yes
BONGOCAT_ENABLE = no
CRAB_ENABLE = no # (default)
DEMON_ENABLE = no
DOG_ENABLE = no # is smaller as LUNA_ENABLE (default)
BONGOCAT_KEYBOARD_ENABLE = no # is smaller as BONGOCAT_ENABLE
MUSIC_BARS_ENABLE = no # TODO
ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled_setup.c

  ifdef MUSIC_BARS_ENABLE
    ifeq ($(strip $(MUSIC_BARS_ENABLE)), yes)
      # SRC += music-bars.c animation-utils.c
      OPT_DEFS += -DMUSIC_BARS_ENABLE
    endif
  endif
  ifndef MUSIC_BARS_ENABLE
    # SRC += music-bars.c animation-utils.c
    OPT_DEFS += -DMUSIC_BARS_ENABLE
  endif

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
#}}}
