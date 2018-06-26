#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h> // 4.2" b/w

#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <string>

#define user "Prof. -----"
String login = "USERNAME";
String password = "PASSWORD";

GxIO_Class io(SPI, SS, 0, 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io); // default selection of D4(=2), D2(=4)


void setup()
{
    display.init();
}

void loop()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin("Neith", "lolsaslol");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    if(WiFi.status() == WL_CONNECTED){
        HTTPClient http;
        String urlrequest = "https://getpo.st/api/example.php?username="+login+"&password="+password;
        http.begin(urlrequest);
        http.GET();
        String payload = http.getString();
        display.fillScreen(GxEPD_WHITE);
        display.setTextColor(GxEPD_BLACK);
        display.setFont(&FreeMonoBold24pt7b);
        display.setCursor(0, 0);
        display.println();   
        display.println(user);
        display.setFont(&FreeMonoBold18pt7b);
        display.println(payload);
        display.println(WiFi.localIP());
        http.end();
    }

    display.update();

    delay(600000);
}