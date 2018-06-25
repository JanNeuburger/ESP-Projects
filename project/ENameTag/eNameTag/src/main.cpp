#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h> // 4.2" b/w

#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#include <ESP8266WiFi.h>

#define user "Prof. -----"
#define login "USERNAME"
#define password "PASSWORD"

GxIO_Class io(SPI, SS, 0, 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io); // default selection of D4(=2), D2(=4)


void setup()
{
    display.init();
}

void loop()
{
    /*WiFi.mode(WIFI_STA);
    WiFi.begin("SSID", "PASSWORD");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }*/


    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeMonoBold24pt7b);
    display.setCursor(0, 0);
    display.println();   
    display.println(user);
    display.setFont(&FreeMonoBold18pt7b);
    display.println("8:00 - 8:50");
    display.println("Raum 105");
    display.update();

    delay(600000);
}