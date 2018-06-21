#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h> // 2.9" b/w/r

#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

GxIO_Class io(SPI, SS, 0, 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io); // default selection of D4(=2), D2(=4)

void setup()
{
display.init();
}

void loop()
{
display.fillScreen(GxEPD_WHITE);
display.setTextColor(GxEPD_BLACK);
display.setFont(&FreeMonoBold24pt7b);
display.setCursor(0, 0);
display.println();
display.println("Prof. Allsaas");
display.setFont(&FreeMonoBold18pt7b);
display.println("08:55 - 9:45");
display.println("Raum 105");
display.update();
delay (600000);
}