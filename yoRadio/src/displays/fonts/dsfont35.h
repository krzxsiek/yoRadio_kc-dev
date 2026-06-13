#ifndef dsfont_h
#define dsfont_h
#include "../../core/options.h"
#if DSP_MODEL == DSP_SSD1322
  #if CLOCKFONT == VT_DIGI_OLD
    #include "VT_DIGI_OLD_20x11s.h"
    #include "TinyFont5.h"
  #else
    #include "VT_DIGI_20x11s.h"
    #include "TinyFont5.h"
  #endif
  #include "DS_DIGI28pt7b.h"
#endif

#if DSP_MODEL == DSP_ST7789_76 || DSP_MODEL==DSP_NV3007_142 /* ST7789_76 and NV3007 mod  ~ kc-dev (12.06.26) */
  #include "VT_DIGI_20x11s.h"
  //#include "DS_DIGI28pt7b_ST7789_76.h"
  #include "VT_DIGI_34x19.h"
#endif

#endif
