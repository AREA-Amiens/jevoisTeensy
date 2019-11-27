#include <Arduino.h>

void setup() {
Serial.begin(9600);
Serial2.begin(115200);
Serial2.setTimeout(1000000);

Serial2.println("setmapping2 YUYV 320 240 50.0 JeVois DemoArUco");
Serial2.println("setpar serstyle Normal");
Serial2.println("setpar serlog None");
Serial2.println("setpar serout Hard");
Serial2.println("setpar dopose true");
Serial2.println("streamon");
}
char trame[129];

void loop() {
  if(Serial2.available()>0){

     byte len = Serial2.readBytesUntil('\n', trame, 128);
     trame[0]=len;
     char * debutrame = strtok(trame," \r\n");
     char * id = strtok(NULL," \r\n");
     double posx = atof(strtok(NULL," \r\n"));
     double posy = atof(strtok(NULL," \r\n"));
     double dist = atof(strtok(NULL," \r\n"));

     Serial.print("identifiant: ");
     Serial.println(id);
     Serial.print("posX: ");
     Serial.println(posx);
     Serial.print("posY:");
     Serial.println(posy);
     Serial.print("distance: ");
     Serial.println(dist);
     //Serial.print(len);
  }

  //if(id<<)

}
