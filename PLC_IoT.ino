
#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>
#define WIFI_SSID "DHURUVA2"            // WIFI SSID here                                   
#define WIFI_PASSWORD "eeed2022"

#define  host1 "https://pgcresearch.pavantech.in/PLC_IoT/pages/Getstatus.php"

void setup(void)
{
   pinMode(32,OUTPUT);
   pinMode(33,OUTPUT);
   pinMode(25,OUTPUT);
   pinMode(26,OUTPUT);
   Serial.begin(115200); 
Serial.println("Communication Started \n\n");  
delay(1000);
  WiFi.mode(WIFI_STA);           
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                   
Serial.print("Connecting to ");
Serial.print(WIFI_SSID);
while (WiFi.status() != WL_CONNECTED) 
{ Serial.print(".");
    delay(500); }
Serial.println();
Serial.print("Connected to ");
Serial.println(WIFI_SSID);
Serial.print("IP Address is : ");
Serial.println(WiFi.localIP());    //print local IP address

delay(30);

  
  delay(700);

}
void loop() {
  HTTPClient http1;
http1.begin(host1);
  http1.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode1=http1.GET();
  String payload=http1.getString(); // get data from webhost continously
  String led, fan, Tv, Speaker;
  led = payload.substring(0, 1);
  fan = payload.substring(1, 2);
  Tv = payload.substring(2, 3);
  Speaker = payload.substring(3, 4);

  // Print the extracted values
  
//  Serial.println("Fan: " + fan);
//  Serial.println("TV: " + Tv);
//  Serial.println("Speaker: " + Speaker);
    if(led == "1")  
    {
       digitalWrite(32,LOW);
       Serial.println("LED: " + led);
    }
    else if (led == "0") 
    {
      digitalWrite(32,HIGH);
      Serial.println("LED: " + led);
    }

    //*******************************************************

    if(fan == "1")  
    {
       digitalWrite(33,LOW);
    }
    else if (fan == "0") 
    {
      digitalWrite(33,HIGH);
    }

    //******************************************************

    if(Tv == "1")  
    {
       digitalWrite(25,LOW);
    }
    else if (Tv == "0") 
    {
      digitalWrite(25,HIGH);
    }

    //*******************************************************

    if(Speaker == "1")  
    {
       digitalWrite(26,LOW);
    }
    else if (Speaker == "0") 
    {
      digitalWrite(26,HIGH);
    }
  
  delay(100);
}
