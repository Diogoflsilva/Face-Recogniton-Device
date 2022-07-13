#include "HUSKYLENS.h"
#include "Wire.h"
#include <WiFi.h>
#include <PubSubClient.h>

int DOOR_PIN = 14;
int BUZZER_LED = 25;
int GREEN_LED = 26;

int F = 1;
int DOOR_STATS = 0;

// WiFi
const char *ssid = "YOUR_SSID";
const char *password = "YOUR_PASSWORD";

// MQTT Broker
const char *mqtt_broker = "broker.hivemq.com";
const char *topic = "topic";
const char *mqtt_username = "mqtt_username";
const char *mqtt_password = "";
const int mqtt_port = 1883;
char receivedChar;

WiFiClient espClient;
PubSubClient client(espClient);


// Create HuskyLens object
   HUSKYLENS huskylens; 

  
   void setNewName (String newname, uint8_t ID) 
    {
   while (!huskylens.setCustomName(newname, ID)) 
  {
    Serial.println(F("Custom name failed!"));
    delay(100); 
} 
}


void setup() 
 {
  Serial.begin(115200);  
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER_LED, OUTPUT);
  pinMode(DOOR_PIN, OUTPUT);
  
  // connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  
  //connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  while (!client.connected()) {
      String client_id = "ESP32_FaceID";
      client_id += String(WiFi.macAddress());
      if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
          Serial.println("MQTT connected");
      } else {
          Serial.print("failed with state ");
          Serial.print(client.state());
          delay(2000);
      }
  }
  // publish and subscribe
  client.publish(topic, "ESP32 Face recognition Coneccted");
  client.subscribe(topic);
    
    Wire.begin();
    
    while(!huskylens.begin(Wire));
 {
    Serial.println("Huskylens Connected");
    delay(100); 
  
  }
      delay(100);
    
       setNewName ("Person1", 1);
       setNewName ("Person2", 2);
       setNewName ("Person3", 3);
       setNewName ("Person4", 4);
       
      }
      void loop()
      {
if (!huskylens.request()) {}
  else if(!huskylens.isLearned()) {}
  else if(!huskylens.available()) {}
  else{
    while (huskylens.available()){
      HUSKYLENSResult result = huskylens.read();
      if (result.command == COMMAND_RETURN_BLOCK){
        
        if(result.ID == 1) //Person not allowed in 
       {
        client.publish(topic, "Person1 | Not Allowed");
        client.subscribe(topic);
        
        digitalWrite(BUZZER_LED, HIGH);
        delay(5000);
       } 
        
        else if(result.ID == 2)//Person not allowed in 
       {
        client.publish(topic, "Person2 | Not Allowed");
        client.subscribe(topic);
        
        digitalWrite(BUZZER_LED, HIGH);
        delay(5000);
       }
        
        else if (result.ID == 3)  //Person allowed in
       {
        if ( DOOR_STATS == 0 && F == 1) { 
         client.publish(topic, "Person3 | Allowed");
         client.subscribe(topic);
         
         digitalWrite(GREEN_LED, HIGH);
         
         digitalWrite(DOOR_PIN, HIGH);
         delay(500);
         digitalWrite(DOOR_PIN, LOW);
         
         delay(5000);
         
         digitalWrite(DOOR_PIN, HIGH);
         delay(500);
         digitalWrite(DOOR_PIN, LOW);

         Serial.println(DOOR_STATS);
         delay(2000);
         F = 0;
        }
        
       else
       { 
         client.publish(topic, "Person3 | Allowed");
         client.subscribe(topic);
         
         digitalWrite(GREEN_LED, HIGH);
         
         digitalWrite(DOOR_PIN, HIGH);
         delay(500);
         digitalWrite(DOOR_PIN, LOW);

         DOOR_STATS = 0;
         Serial.println(DOOR_STATS);
         delay(2000);
         F = 1;
         DOOR_STATS == 0;
        }
       }

       

 
        else if (result.ID == 4) //Person allowed in
       {
        if ( DOOR_STATS == 0 && F == 1) { 
         client.publish(topic, "Person4 | Allowed");
         client.subscribe(topic);
         
         digitalWrite(GREEN_LED, HIGH);
         
         digitalWrite(DOOR_PIN, HIGH);
         delay(500);
         digitalWrite(DOOR_PIN, LOW);
         
         delay(5000);
         
         digitalWrite(DOOR_PIN, HIGH);
         delay(500);
         digitalWrite(DOOR_PIN, LOW);

         Serial.println(DOOR_STATS);
         delay(2000);
         F = 0;
        }
        
       else
       { 
         client.publish(topic, "Person4 | Allowed");
         client.subscribe(topic);
         
         digitalWrite(GREEN_LED, HIGH);
         
         digitalWrite(DOOR_PIN, HIGH);
         delay(500);
         digitalWrite(DOOR_PIN, LOW);

         DOOR_STATS = 0;
         Serial.println(DOOR_STATS);
         delay(2000);
         F = 1;
         DOOR_STATS == 0;
        }
       }
      }
     }
    }
   }
