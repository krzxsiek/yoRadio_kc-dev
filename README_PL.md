# yoRadio V-Tom (Modded by kc-dev)
[![en](images/english.svg)](README.md)

Dodałem obsługę następujących wyświetlaczy:

- NV3007 428x142 2.79" https://pl.aliexpress.com/item/1005012251243789.html
- ST7789 284x76 2.25" https://aliexpress.com/item/1005009016973081.html

## NV3007 428x142 2.79"

<a href="https://youtu.be/3gqVbwaUH2E?si=ETXbSLO5y7pVvZy1">
    <img src="https://img.youtube.com/vi/3gqVbwaUH2E/maxresdefault.jpg" width="400" alt="NV3007 428x142 2.79&quot; (Layout 1)">
</a>

<a href="https://youtu.be/OIB90S6o9-4?si=mor6tHdsKJRHwaaY">
    <img src="https://img.youtube.com/vi/OIB90S6o9-4/maxresdefault.jpg" width="400" alt="NV3007 428x142 2.79&quot; (Layout 2)">
</a>

## ST7789 284x76 2.25"

<a href="https://youtu.be/pyjyYVzSvXk?si=yCLboO9ejS3hEOCV">
    <img src="https://img.youtube.com/vi/pyjyYVzSvXk/maxresdefault.jpg" width="400" alt="ST7789 284x76 2.25&quot;">
</a>

<a href="images/ST7789_76 v0.8.8 Mod 0.0.6 (24.06.2026).png">
    <img src="images/ST7789_76 v0.8.8 Mod 0.0.6 (24.06.2026).png" width="400" alt="ST7789 284x76 2.25&quot; ## v0.8.8 | Mod 0.0.6 (24.06.2026)">
</a>


## 🔵 Informacje

Dla wyświetlacza **NV3007 2.79" 428x142** przygotowano dwa pliki konfiguracyjne (dwa layouty). <br />- **(Układ 1)** w pliku `src/displays/conf/displayNV3007_142conf.h` <br />- **(Układ 2)** w pliku `src/displays/conf/displayNV3007_142conf.h.kopia` <br />*Aby zmienić układ wystarczy zamienić te pliki nazwami.* 
<br /><br />Obsługa wyświetlacza **NV3007** została dodana do biblioteki **"Adafruit ST7735 and ST7789 Library WITHOUT SD"** na podstawie plików z biblioteki **"Arduino GFX"**. <br /><br /> Oprócz bibliotek i konfiguracji wyświetlacza dodano kilka usprawnień poprawiających wyświetlanie niektórych elementów interfejsu, m.in. przeniesiono adres IP na ekran głośności, aby nie zajmował miejsca na ekranie głównym. <br /><br /> Dodano również możliwość wymuszenia własnej nazwy stacji poprzez dodanie przecinka przed nazwą, np. `,MOJA STACJA`. Jest to przydatne dla stacji, które wysyłają nieprawidłowe dane w metatagach. <br /><br />


# 🔵 Instrukcje dla Arduino IDE (testowałem na wersji 2.3.10)
## 🔹1. Ustawienia ArduinoIDE

<a href="Arduino IDE 2.3.10 settings/PL_ArduinoIDE_USTAWIENIA.png">
    <img src="Arduino IDE 2.3.10 settings/PL_ArduinoIDE_USTAWIENIA.png" alt="Arduino IDE 2.3.10 Settings (PL)" width="300">
</a>

## 🔹2. Instalacja bibliotek
Przenieś foldery bibliotek ręcznie z <br />`yoRadio/.pio/libdeps/esp32-s3-devkitc1-n16r8` <br /><a href="Arduino IDE 2.3.10 settings/libraries_pio.png"><img src="Arduino IDE 2.3.10 settings/libraries_pio.png" alt="Libraries" width="300"></a> <br />do `C:\Users\user\Documents\Arduino\libraries` <br /><a href="Arduino IDE 2.3.10 settings/libraries_arduino.png"><img src="Arduino IDE 2.3.10 settings/libraries_arduino.png" alt="Libraries" width="300"></a>

# 🔵 Przykładowe podłączenie elementów
Przykładowe podłączenie elementów według mojego pliku `myoptions.h` zastosowanym przy jednym z moich projektów. <br/><br/>Wyświetlacz NV3007 (428x142) i ST7789 (284x76) działają przy identycznym podłączeniu pinów. <br/>Różnica jest tylko na pinie BLK jeśli chodzi o obsługę podświetlenia ponieważ działa na odwrót (tzn. ściemnianie i rozjaśnianie w przypadku ST7789 działa na odwróconej zasadzie) <br/><br/>Przy podłączeniu odbiornika IR (KY-022 lub podobnych) polecam wlutować na płytce (jak najbliżej diody IR) kondensatory: 220uF (elektrolityczny), 100nF (ceramiczny) aby odczyty z pilota nie wariowały przez zakłócenia. <br/>⚠️ **Uwaga! Pamiętaj o poprawnym ustawieniu polaryzaji +/- kondensatora elektrolitycznego!** <br/><br/> Moduł DAC GY-PCM5102 zaraz po zakupie wymaga zlutowania zworek (<a href="PCM5102A/jumpers.png">przykład tutaj</a>)
<a href="PCB/yoRadio ESP32-S3-WROOM-1-N16R8-NV3007_ST7789_76_bb.png">
    <img src="PCB/yoRadio ESP32-S3-WROOM-1-N16R8-NV3007_ST7789_76_bb.png" alt="Example connection of elements" width="600">
</a>
<br />

Tak u siebie przylutowałem filtr do modułu KY-022 (nie miałem kondensatora 220uF więc użyłem dwóch 100uF)
<a href="images/KY-022/KY-022_FRONT.jpg">
    <img src="images/KY-022/KY-022_FRONT.jpg" alt=" IR receiver KY-022" width="300">
</a>
<a href="images/KY-022/KY-022_BACK.jpg">
    <img src="images/KY-022/KY-022_BACK.jpg" alt=" IR receiver KY-022" width="300">
</a>


# 🔵 Ramka do druku 3D
Gotowa ramka na wyświetlacz, do użycia przy projektowaniu obudowy do druku 3D. <br/>W dwóch plikach STL: <a href="3D/Frame.stl">Frame.stl</a>, <a href="3D/Frame-clip.stl">Frame-clip.stl</a>

https://makerworld.com/en/models/2924122-frame-for-lcd-nv3007-2-79-428x142-to-yoradio<br/><br/>
<a href="3D/frame1.jpg">
    <img src="3D/frame1.jpg" alt="Frame" width="300">
</a>
<a href="3D/frame2.jpg">
    <img src="3D/frame2.jpg" alt="Frame" width="300">
</a>


# 🔵 Historia zmian modyfikacji kc-dev
## v0.8.8 | Mod 0.0.6 (24.06.2026)
- ST7789_76:
    - <a href="images/ST7789_76 v0.8.8 Mod 0.0.6 (24.06.2026).png">
        <img src="images/ST7789_76 v0.8.8 Mod 0.0.6 (24.06.2026).png" width="300" alt="ST7789 284x76 2.25&quot; ## v0.8.8 | Mod 0.0.6 (24.06.2026)">
    </a> 
    - Dodałem do ekranu widget imienin zastępujący adres IP (gdy włączymy imieniny w opcjach "TOOLS / Nameday", adres IP trafi na ekran głośności), jeśli nie włączymy imienin to dalej będzie wyświetlany adres IP w dotychczasowym miejscu. 
    - Dodałem heapbar pod vu metrem wyświetlający poziom bufora (włączamy opcją "SYSTEM / Audio Info")
    - Naprawiono animację ładowania (na ekranie startowym)
## v0.8.8 | Mod 0.0.5 (22.06.2026)
- Poprawka usuwająca przecinek z początku nazwy stacji (na liście stacji gdy korzystamy z modyfikacji umożliwiającej ustawienie stałej nazwy stacji)
## v0.8.8 | Mod 0.0.4 (22.06.2026)
- Poprawka w bibliotece obsługującej NV3007 (poprawiona wysokość i odstępy podczas obrotu ekranu, ponieważ odstępy między elementami na ekranie były inne po obróceniu ekranu w opcjach)
- NV3007: 
    - Naprawiono pasek heapbar (pasek bufora) i volbar (pasek głośności) dla NV3007
    - Naprawiono animację ładowania (na ekranie startowym)
## v0.8.8 | Mod 0.0.3 (19.06.2026)
- Poprawka konfiguracji NV3007 (pozycja wskaźnika VU) - Wcześniej trzeba było odwrócić ekran, aby wyświetlić go poprawnie.
- Poprawiono czyszczenie wyświetlacza po zatrzymaniu odtwarzania. Wcześniej wskaźnik VU był czyszczony na całej szerokości. Zapobiega to teraz nakładaniu się na elementy stopki, takie jak numer kanału i ikona zasięgu wifi (już nie znikają po zatrzymaniu odtwarzania).
## v0.8.8 | Mod 0.0.2 (13.06.2026)
- Dodano poprawkę dla modułu odbiornika podczerwieni KY-022
- Dodano grafikę z przykładem elementów połączeniowych przygotowanych w programie Fritzing
## v0.8.8 | Mod 0.0.1 (12.06.2026)
- Dodano obsługę NV3007 428x142 2,79" i ST7789 284x76 2,25"
