//Code zum einlesen von Mac-Adressen von verbundenen geräten
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

extern "C" {
#include<user_interface.h>
}

/* configuration  wifi */
const char *ssid = "COblaster";

ESP8266WebServer server(80);

void handleRoot() { 
  server.send(200, "text/html", "<h1>You are connected</h1>");
  String addy = server.client().remoteIP().toString();
  Serial.println(addy);
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");  
}

void loop() {
  server.handleClient();    
  delay(5000);
  client_status();
  delay(4000);
}

void client_status() {

unsigned char number_client;
struct station_info *stat_info;

struct ip_addr *IPaddress;
IPAddress address;
int i=1;

number_client= wifi_softap_get_station_num();
stat_info = wifi_softap_get_station_info();

Serial.print(" Total connected_client are = ");
Serial.println(number_client);

while (stat_info != NULL) {

IPaddress = &stat_info->ip;
address = IPaddress->addr;

Serial.print("client= ");

Serial.print(i);
Serial.print(" ip adress is = ");
Serial.print((address));
Serial.print(" with mac adress is = ");

Serial.print(stat_info->bssid[0],HEX);
Serial.print(stat_info->bssid[1],HEX);
Serial.print(stat_info->bssid[2],HEX);
Serial.print(stat_info->bssid[3],HEX);
Serial.print(stat_info->bssid[4],HEX);
Serial.print(stat_info->bssid[5],HEX);

stat_info = STAILQ_NEXT(stat_info, next);
i++;
Serial.println();

}
delay(500);
}