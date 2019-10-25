#include <WiFi.h>
#include <M5Stack.h>

WiFiClient client;

char thingSpeakAddress[] = "api.thingspeak.com";
String thingtweetAPIKey = "yourapikeyhere";
String tsData;

void setup()
{
  M5.begin();
  WiFi.disconnect();
  delay(1000);
  M5.Lcd.println("START");
   WiFi.begin("yourssid","yourpassword");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    M5.Lcd.println("...");

  }
  M5.Lcd.println("connected");
  M5.Lcd.println((WiFi.localIP()));
  if (client.connect("api.thingspeak.com",80)) {
    tsData = "api_key="+thingtweetAPIKey+"&status="+"This tweet was sent by my #M5Stack";
    client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(tsData.length());
    client.print("\n\n");
    client.print(tsData);
    M5.Lcd.println("Tweet sent");

  }

}


void loop()
{


}
