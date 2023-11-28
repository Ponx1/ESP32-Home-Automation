#include "WifiHandler.h"
#include <WebServer.h>
#include "index.h"

#define PIN_RELAY1 4
#define PIN_RELAY2 13
#define PIN_RELAY3 18
#define PIN_RELAY4 19
#define PIN_RELAY5 21
#define PIN_RELAY6 22
#define PIN_RELAY7 23
#define PIN_RELAY8 23

/*
 * Relay1 = Patio - Riego
 * Relay2 = Patio - Luz
 * 
 * Relay3 = Sala - Lampara
 * Relay4 = Sala - Ventilador
 */

bool Relay1Status = false;
bool Relay2Status = false;
bool Relay3Status = false;
bool Relay4Status = false;

// WiFi Credentials
const char* ssid = "Ponx";
const char* password = "Chimuela123";

// prototypes
boolean connectWifi();
boolean checkIfConnected();
void scanForSSID();

boolean wifiConnected = false;

WebServer server(80);

void setup()
{
    Serial.begin(115200);
   
    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    
    scanForSSID();
    do{
      Serial.println("Initial setup");
      connectWifi(ssid, password);
    }while(!checkIfConnected());
    

    pinMode(PIN_RELAY1, OUTPUT);
    pinMode(PIN_RELAY2, OUTPUT);
    pinMode(PIN_RELAY3, OUTPUT);
    pinMode(PIN_RELAY4, OUTPUT);

    server.on("/", sendIndex);
    server.on("/Relay1", processRelay1);
    server.on("/Relay2", processRelay2);
    server.on("/Relay3", processRelay3);
    server.on("/Relay4", processRelay4);
    server.begin();
    
    Serial.println("Setup done");
}

void loop()
{
  if(!checkIfConnected()){
    Serial.println("Wifi Disconnected!");
    connectWifi(ssid, password);
  }

  server.handleClient();


  
  delay(1000);
    
}

void sendIndex() {

  Serial.println("sending web page");
  // you may have to play with this value, big pages need more porcessing time, and hence
  // a longer timeout that 200 ms
  server.send(2000, "text/html", INDEX);

}

void processRelay1(){
  Relay1Status = !Relay1Status;
  Serial.println("Toggle relay 1...");
  Serial.print("Current status: ");
  Serial.println(Relay1Status);
  digitalWrite(PIN_RELAY1, Relay1Status);
  server.send(200, "application/json", "{}");
}

void processRelay2(){
  Relay2Status = !Relay2Status;
  Serial.println("Toggle Relay 2...");
  Serial.print("Current status: ");
  Serial.println(Relay2Status);
  digitalWrite(PIN_RELAY2, Relay2Status);
  server.send(200, "application/json", "{}");
}

void processRelay3(){
  Relay3Status = !Relay3Status;
  Serial.println("Toggle Relay 3...");
  Serial.print("Current status: ");
  Serial.println(Relay3Status);
  digitalWrite(PIN_RELAY3, Relay3Status);
  server.send(200, "application/json", "{}");
}

void processRelay4(){
  Relay4Status = !Relay4Status;
  Serial.println("Toggle Relay 4...");
  Serial.print("Current status: ");
  Serial.println(Relay4Status);
  digitalWrite(PIN_RELAY4, Relay4Status);
  server.send(200, "application/json", "{}");
}

void getStatus(){
  String response = "";
  response = "{}";
}
