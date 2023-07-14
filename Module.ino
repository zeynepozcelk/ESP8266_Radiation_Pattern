
#include <ESP8266WiFi.h>
float mean=-75;
void setup() {
delay(100);

  WiFi.begin("ssid", "password");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}
void loop() {

for (int i = -4; i <= 361; i=i+4) {
            
    WiFiClient client;
    if (!client.connect("api.thingspeak.com", 80)) {
       return;
    }
   
    int Angle = i+4;   

for (int j = 0; j < 39; j++) {
 float   Signal=WiFi.RSSI();  
mean =0.05*Signal +0.95*mean;
delay(500);
} 
    // We now create a URL for the request
    String url = "/update?api_key=";
    url += "You API key";
    url += "&field1=";
    url += String(Angle);
    url += "&field2=";
    url += String(mean);
        
     client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + "api.thingspeak.com" + "\r\n" + 
                 "Connection: close\r\n\r\n");
delay(100);   // time to finish Xfer
 // Serial. println(WiFi.RSSI()); //    test
}
int i=10;
while (i < 1000) {
  delay(1000);
}
}