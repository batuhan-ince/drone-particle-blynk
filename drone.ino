
#include <blynk.h>


#define BLYNK_PRINT Serial  
#include <blynk.h>
Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
char publishString[40];
unsigned long lastTime = 0UL;


char auth[] = "Your particle token";


BLYNK_WRITE(V0) {
    servo1.writeMicroseconds(createseconds(param.asInt()));
        
}
BLYNK_WRITE(V1) {
    servo2.writeMicroseconds(createseconds(param.asInt()));

        
}
BLYNK_WRITE(V2) {
    servo3.writeMicroseconds(createseconds(param.asInt()));

        
}
BLYNK_WRITE(V3) {
    servo4.writeMicroseconds(createseconds(param.asInt()));

        
}
BLYNK_WRITE(V4) {
    servo5.writeMicroseconds(createseconds(param.asInt()));

        
}

void setup()
{
    Serial.begin(9600);
    delay(5000); 
    Blynk.begin(auth);
    servo1.attach(A0);  
    servo2.attach(A1);
    servo3.attach(A5);
    servo4.attach(A4);
    servo5.attach(A6);

}


int createseconds(int a)
{
    int c=1000+(10)*a;
    return c;
}

void loop()
{
    Blynk.run();
    unsigned long now = millis();
    
    if (now-lastTime>15000UL) {
        lastTime = now;
        sprintf(publishString, "%d:%d:%d:%d:%d", servo1,servo2,servo3,servo4,servo5); 
        Spark.publish("Servo_values", publishString);
    }
}
