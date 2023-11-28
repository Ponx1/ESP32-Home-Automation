#include "WiFi.h"

boolean checkIfConnected(){
    return WiFi.status() == WL_CONNECTED;
  }

void scanForSSID(){
  Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(5000);
  
  }

boolean connectWifi(const char* ssid, const char* password){
  boolean state = true;
  int i = 0;
  //WiFi.disconnect();
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(3000);
    Serial.print(".");
    if (i > 60){
      Serial.println(WiFi.status());
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state){
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed.");
  }
  return state;
}
