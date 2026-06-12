// clang-format off
/* https://trip5.github.io/ehRadio_myoptions/generator.html?b=ESP32-S3-DevKitC-1_44Pin&r=72,1,2,4,5,6,76,7,8,31,42,43,54,55,58,60,63,65,77&i=1,2,3,4,15,16,17,28,29,30,31,32,33,34,39,48,49&v=9,10,-1,14,4,5,6,40,41,39,48,47,21,3,18,8,7
   https://github.com/VaraiTamas/yoRadio.git
   Használat előtt olvasd el!!! - Read the before use !!!
   https://github.com/VaraiTamas/yoRadio/blob/main/README.md !!!

  - A sor elején a // jel inaktívvá teszi a parancsot ezért a fordító nem veszi figyelembe! 
    Ezzel tudod beállítani a te hardveredmek megfelelő összeállítást.
  - The // sign at the beginning of the line makes the command inactive, so the compiler ignores it! 
    This allows you to set the appropriate configuration for your hardware.
*/

/* 
    Paczka przygotowana pod obsługę wyświetlacza na sterowniku NV3007 2.79' 428x142 
    oraz wyświetlacza ST7789 2.25' 284x76

    Dla wyświetlacza NV3007 2.79' 428x142 są przygotowane dwa pliki konfiguracyjne (dwa layouty),
    można podmienić plik \src\displays\conf\displayNV3007_142conf.h (Układ 1) z plikiem \src\displays\conf\displayNV3007_142conf.h.kopia (Układ 2) wedle uznania ;)

    Obsługa wyświetlacza NV3007 została dodana w bibliotece "Adafruit ST7735 and ST7789 Library WITHOUT SD" na podstawie plików z biblioteki "Arduino GFX"

    Oprócz bibliotek i konfiguracji wyświetlacza, zostało dodanych kilka usprawnień w innych plikach potrzebnych do lepszego wyświetlania 
    niektórych elementów na wyswietlaczu, między innymi adresu IP na ekranie głośności (aby nie zaśmiecał ekranu głównego na którym i tak mamy ograniczoną ilośc miejsca).
    Dodałem też swoją małą modyfikacje umożliwiającą ustawienie na stałe nazwy stacji poprzez dodanie przecinka przed nqazwą stacji ", NAZWA STACJI". 

     ~ Krzysztof Cielma (kc-dev) (09.06.26) 
*/

#ifndef myoptions_h
#define myoptions_h

#ifndef ARDUINO_ESP32S3_DEV
    #define ARDUINO_ESP32S3_DEV
#endif

// #define HEAP_DBG


/* You can set the program language here. - Tutaj możesz ustawić język programu.
   Supported languages: HU NL PL RU EN GR SK DE UA ES. */
#define L10N_LANGUAGE EN

/* Display name days - Pokaż imieniny
Supported languages: HU, PL, NL, GR, DE (UA Local/namedays/namedays_UA.h is not filled in.) */
//#define NAMEDAYS_FILE PL // << Uncomment if you use Polish (or other) language and screen (configuration layout) with name day display - Odkomentuj jeśli używasz języka polskiego (lub innego) i ekranu (układu konfiguracji) z wyświetlaniem imienin

#define USE_BUILTIN_LED false /* The RGB LED does not turn on.. - Dioda LED RGB nie włączy się. */

/* Arduino OTA Support - Wsparcie Arduino OTA */
// #define USE_OTA true                    /* Enable OTA updates from Arduino IDE - Włącz aktualizacje OTA z Arduino IDE */
// #define OTA_PASS "myotapassword12345"   /* OTA password for secure updates - Hasło OTA do bezpiecznych aktualizacji */

/* HTTP Authentication */
// #define HTTP_USER ""                   /* HTTP basic authentication username - Nazwa użytkownika podstawowego uwierzytelniania HTTP */
// #define HTTP_PASS ""                   /* HTTP basic authentication password - Podstawowe hasło uwierzytelniania HTTP */

/*----- LCD DISPLAY - WYŚWIETLACZ LCD -----*/
//#define DSP_MODEL DSP_DUMMY
//#define DSP_MODEL DSP_ST7789            /* Wyświetlacz ST7789V 2` TFT LCD 240x320 */
//#define DSP_MODEL DSP_ST7789_76         /* Wyświetlacz ST7789 2.25` TFT LCD 76x284 */
#define DSP_MODEL DSP_NV3007_142          /* Wyświetlacz NV3007 2.79` TFT LCD 142x428 */
//#define DSP_MODEL DSP_ILI9488
//#define DSP_MODEL DSP_ILI9341
//#define DSP_MODEL DSP_ST7796

/*----- OLED DISPLAY - WYŚWIETLACZ OLED -----*/
// #define DSP_MODEL      DSP_SSD1322

/*----- DISPLAY PIN SETS - ZESTAW PINÓW WYŚWIETLACZA -----*/
#define TFT_DC         9                  /* może być DC, RS */
#define TFT_CS         10                 /* może być CS pin ( ) */
#define TFT_RST        -1                 /* SPI RST pin (-1 jeśli połączono z EN/RST) */
#define BRIGHTNESS_PIN 14           /* może być BLK, BL - Pin do regulacji jasności (wyjście 0 - 3v3) */
/*
   GPIO 11 - MOSI    może być SDA, DIN, SDI
   GPIO 12 - CLK     może być SCLK, SCL, SCK, CLK
   GPIO 13 - MISO  // Nie podłączać do wyświetlacza LCD!!! - Do not connect to the LCD display!!! 
*/

/*----- Touch ISP -----*/
// #define TS_MODEL TS_MODEL_XPT2046
// #define TS_CS    3

/*----- Touch I2C -----*/
// #define TS_MODEL TS_MODEL_FT6X36
// #define TS_SCL      7
// #define TS_SDA      8
// #define TS_INT     17 

/*----- Touch corrections -----*/
// #define X_TOUCH_MIRRORING
// #define Y_TOUCH_MIRRORING

/*----- NEXTION DISPLAY serial port -----*/
// #define NEXTION_RX			15
// #define NEXTION_TX			16

/*----- PCM5102A  DAC -----*/
/* 
   W przypadku modułu "DAC GY-PCM5102 " pinu SCK nie podłączamy, zworka na SCK ma być zlutowana, tak samo jak zworki z tyłu płyty też muszą być odpowiednio skonfigurowane.
   W folderze PCM5102A są pliki z instrukcją
*/
#define I2S_DOUT 4  /*  = DIN   */                                                                      /* Może być też 17 | Domyślnie 4 */
#define I2S_BCLK 5  /*  = BCLK   może być BCK         Bit clock - Zegar bitowy */                        /* Może być też 16 | Domyślnie 5 */
#define I2S_LRC  6  /*  = WSEL   może być LCK, LRCK   Left Right Clock - Zegar lewy prawy */             /* Może być też 18 | Domyślnie 6 */

/*----- ENCODER 1 - POKRĘTŁO 1 ------*/ // BC11 lub KY-040
#define ENC_BTNR 41  // S2    lub   DT
#define ENC_BTNL 40  // S1    lub   CLK
#define ENC_BTNB 39  // KEY   lub   SW
// #define ENC_INTERNALPULLUP    true

/*----- ENCODER 2 - POKRĘTŁO 2 ------*/ // BC11 lub KY-040
#define ENC2_BTNR 47  // S2    lub   DT
#define ENC2_BTNL 48  // S1    lub   CLK
#define ENC2_BTNB 21  // KEY   lub   SW
// #define ENC2_INTERNALPULLUP   true

/*----- BUTTONS - PRZYCISKI ------*/
#define BTN_LEFT  16    // PREV
#define BTN_RIGHT 7     // NEXT
#define BTN_UP    17    // VOL UP
#define BTN_DOWN  18    // VOL DOWN
#define BTN_CENTER 15   // PLAY/STOP/MODE
#define BTN_INTERNALPULLUP true

/*----- CLOCK MODUL RTC DS3132 - MODUŁ ZEGARA RTC DS3132 -----*/
// #define RTC_SCL			     7
// #define RTC_SDA			     8
// #define RTC_MODULE DS3231

/*----- REMOTE CONTROL INFRARED RECEIVER - PILOT -----*/
/*----- To wake from sleep, you must use GPIO 2, because GPIO 38 is not an RTC pin. It must be connected via the PCB! -----*/
/*----- Aby wybudzić urządzenie ze stanu uśpienia, należy użyć GPIO 2, ponieważ GPIO 38 nie jest pinem RTC. Musi być podłączony przez płytkę drukowaną! -----*/
#define IR_PIN 2  //38

/*----- SD CARD - KARTA PAMIĘCI -----*/
// #define SDC_CS     18
// #define SDSPISPEED 4000000 /* 4MHz - Slower speed to prevent display flicker on shared SPI bus */

/*----- The color display displays a grayscale image -----*/
/*----- Wyświetla obraz w skali szarości na kolorowym wyświetlaczu. -----*/
// #define THEME_GRAY

/*----- Inactive segments of the clock, true or false. -----*/
/*----- Wyświetlanie nieaktywnego segmentu w numerach zegara true -> włącz, false -> wyłącz. -----*/
#define CLOCKFONT_MONO

/*----- Define 12-hour time format. -----*/
/*----- Zdefiniuj 12-godzinny format czasu. -----*/
// #define AM_PM_STYLE

/*----- Turn on the original seven-segment font. -----*/
/*----- Włącza oryginalną czcionkę zegara siedmiosegmentowego. -----*/
// #define CLOCKFONT VT_DIGI_OLD

/*----- Speaks the time using Google TTS voice in the specified language and every specified minute. -----*/
/*----- Podaje godzinę za pomocą głosu Google TTS w określonym języku i co określoną minutę. -----*/
#define CLOCK_TTS_ENABLED     false    // Enabled (true) or disabled (false)
                                       // Włączone (true) lub wyłączone (false)
#define CLOCK_TTS_LANGUAGE    "PL"     // Language ( EN, HU, PL, NL, DE, RU, RO ,FR, GR)
                                       // Język
#define CLOCK_TTS_INTERVAL_MINUTES 15  // How many times a minute does it say.
                                       // Ile razy na minutę ma być wypowiadane?

/*----- With this setting there is no scrolling on the weather bar. -----*/
/*----- Przy tym ustawieniu pasek pogody nie będzie przewijany. -----*/
//#define WEATHER_FMT_SHORT

/*----- With this setting, the full weather report is displayed. -----*/
/*----- Przy tym ustawieniu wyświetlany jest pełny raport pogodowy. -----*/
#define EXT_WEATHER  true

/*----- With this setting, the wind speed will be km/h. -----*/
/*----- Przy tym ustawieniu prędkość wiatru będzie wynosić km/h. -----*/
// #define WIND_SPEED_IN_KMH

/*----- The VU meter supports two types of display modes.
        BOOMBOX_STYLE is the style when the display swings out from the center to two sides. You can set it here.
        If there is a // sign at the beginning of the line, the basic VU meter is working, swinging out from left to right. -----*/
/*----- Miernik VU obsługuje dwa tryby wyświetlania.
        BOOMBOX_STYLE to styl, w którym wyświetlacz wychyla się od środka na dwie strony. Można go ustawić tutaj.
        Jeśli na początku wiersza znajduje się znak //, działa podstawowy miernik VU, który wychyla się od lewej do prawej. -----*/
//#define BOOMBOX_STYLE

/*----- A white bar will appear at the end of the VU meter at the peak values ​​if you enable this. The // at the beginning of the line will disable it. -----*/
/*----- Jeśli włączysz tę funkcję, na końcu miernika VU pojawi się biały pasek przy wartościach szczytowych. Znak // na początku wiersza ją wyłącza. -----*/
#define VU_PEAK

/*----- When selecting from the station list, you do not need to press the rotary encoder button, 
        the channel will automatically change when you exit. (By Zsigmond Becskehazi) -----*/
/*----- Wybierając stację z listy, nie trzeba naciskać obrotowego przycisku enkodera. 
        Kanał zmieni się automatycznie po wyjściu z menu. (Autor: Zsigmond Becskeházi) -----*/
#define DIRECT_CHANNEL_CHANGE

/*----- How long to return to the main screen from the station list. (seconds) -----*/
/*----- Jak długo następuje powrót do ekranu głównego z listy stacji. (sekundy) -----*/
#define STATIONS_LIST_RETURN_TIME 3

/*----- by Maciej Bednarski -----*/
/*---- Activating this will move the cursor up and down in the playlist -----*/
/*---- Aktywacja tej opcji spowoduje przesuwanie kursora w górę i w dół listy odtwarzania -----*/
//#define PLAYLIST_SCROLL_MOVING_CURSOR

/*----- This pin controls the amplifier's power supply. When music is playing, the pin is set to HIGH to control the relay. 
        When music is not playing (stopped or volume is 0), the pin is set to LOW. This change occurs when the screensaver is running. -----*/
/*----- Ustawiony tutaj pin może sterować zasilaniem wzmacniacza audio. Podczas odtwarzania muzyki pin jest w stanie wysokim, 
        co powoduje zasilenie przekaźnika, który włącza zasilanie wzmacniacza. 
        Gdy muzyka nie jest odtwarzana (STOP lub głośność 0), pin jest w stanie niskim.
        Ta zmiana następuje, gdy wygaszacz ekranu jest włączony w trybie „bez odtwarzania”. -----*/
//#define PWR_AMP 2

/*----- by Andrzej Jaroszuk -----*/    
/*----- Stops playback in internet radio mode when the playback buffer runs out. Then restarts playback. -----*/
/*----- Zatrzymuje odtwarzanie w trybie radia internetowego, gdy bufor odtwarzania się zapełni. Następnie wznawia odtwarzanie. -----*/
#define ENABLE_STALL_WATCHDOG

/*----- by Karol Wysocki -----*/  
/*----- Disables the secondary function of the encoder button. Use only if you have two encoders! -----*/
/*----- Wyłącza funkcję drugorzędną przycisku enkodera. Używaj tylko wtedy, gdy masz dwa enkodery! -----*/
//#define ENCODERS_INDEPENDENT

/*----- If this is defined at radio startup, the first channel will always be set. -----*/
/*----- Jeżeli zostanie to zdefiniowane przy uruchamianiu radia, zawsze ustawiony będzie pierwszy kanał. -----*/
//#define ALWAYS_START_FROM_FIRST

/*----- Sleep functions -----*/
/*----- Instead of WAKE_PIN, you can now set two pins for wake-up: WAKE_PIN1 and WAKE_PIN2 -----*/
/*----- This way, you can wake up the device with a remote control and another button. -----*/
/*----- Zamiast WAKE_PIN możesz teraz ustawić dwa piny do wybudzania: WAKE_PIN1 i WAKE_PIN2 -----*/
/*----- W ten sposób możesz wybudzić urządzenie za pomocą pilota i innego przycisku. -----*/
//#define BTN_MODE ENC_BTNB
#define WAKE_PIN1 IR_PIN        // pin IR
//#define WAKE_PIN2 ENC2_BTNB     // pin drugiego enkodera

/*----- by Zsolt Simon -----*/
/*----- Tested on Synology NAS ----- */
// #define USE_DLNA
// #define dlnaHost "192.168.1.200"
// #define dlnaIDX  21

//#define POWER_LED 38      // Button LED pin (will be turned on when player is on)

#endif // myoptions_h
