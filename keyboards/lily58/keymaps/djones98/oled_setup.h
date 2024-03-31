#pragma once

#include "quantum.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MO4,
  _MO5
};

#ifdef OLED_ENABLE

#    include "oled_driver.h"

#    ifdef LUNA_ENABLE
#        include "luna.h"
#    endif

#    ifdef OCEAN_DREAM_ENABLE
#        include "ocean_dream.h"
#    endif

#    ifdef BONGOCAT_ENABLE
#        include "bongocat.h"
#    endif

#    ifdef CRAB_ENABLE
#        include "animation-utils.h"
#        include "crab.h"
#    endif

#    ifdef DEMON_ENABLE
#        include "animation-utils.h"
#        include "demon.h"
#    endif
#endif
