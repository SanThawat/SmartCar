//SAN
#define BLYNK_TEMPLATE_ID "TMPL6Ke5pjJV7"
#define BLYNK_TEMPLATE_NAME "Car"
#define BLYNK_AUTH_TOKEN "Wpg82uCsePelb-pLVzeEaEQ_9eQd6eDS"

#include <Wire.h>  
//#include <UnoWiFiDevEd.h> 
#include <BlynkSimpleEsp32.h> 
#define ssid "OPPO Reno5 5G" //Wifi name
#define pass "abc12345" //Wifi pass
//#define ssid "Por-AIS4GHomeWiFi" 
//#define pass "por150444" 

#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 14 
DHT dht(DHTPIN, DHTTYPE);

int A ;
int B ;
int C ;
int D ;


BLYNK_WRITE(V0){
  A = param.asInt();
}
BLYNK_WRITE(V1){
  B = param.asInt();
}
BLYNK_WRITE(V2){
  C = param.asInt();
}
BLYNK_WRITE(V3){
  D = param.asInt();
}

void setup() {
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin(115200);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

  dht.begin();

}

void loop() {
  Blynk.run();
  if(A == 1){
    forward();
  }
  else if(B == 1){
    backward();
  }
  else if(C == 1){
    left();
  }
  else if(D == 1){
    right();
  }
  else if(A == 0 and B == 0 and C == 0 and D == 0){
    stop();
  }
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  //Blynk.virtualWrite(V4, temperature);  // Send temperature to virtual pin V1
  Blynk.virtualWrite(V4, humidity);     // Send humidity to virtual pin V2

  delay(1000);

}

void forward(){
  digitalWrite(26,0);
  digitalWrite(27,1);
  digitalWrite(18,1);
  digitalWrite(19,0);
}

void backward(){
  digitalWrite(26,1);
  digitalWrite(27,0);
  digitalWrite(18,0);
  digitalWrite(19,1);
}

void right(){
  digitalWrite(26,1);
  digitalWrite(27,0);
  digitalWrite(18,1);
  digitalWrite(19,0);
}

void left(){
  digitalWrite(26,0);
  digitalWrite(27,1);
  digitalWrite(18,0);
  digitalWrite(19,1);
}

void stop(){
  digitalWrite(26,0);
  digitalWrite(27,0);
  digitalWrite(18,0);
  digitalWrite(19,0);
}
