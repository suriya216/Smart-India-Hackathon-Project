#define dayandnight 13
#define led1 15
#define ldr1 34
#define solar1 35
#define ir1 39
#define led2 16
#define ldr2 33
#define solar2 32
#define ir2 22
#define led3 17
#define ldr3 26
#define solar3 25
#define ir3 21
#define led4 5
#define ldr4 4
#define solar4 2
#define ir4 23
#define led5 18
#define ldr5 27
#define solar5 14
#define ir5 19
void setup() {
  Serial.begin(9600);
  pinMode(dayandnight,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(ldr1,INPUT);
  pinMode(solar1,INPUT);
  pinMode(ir1,INPUT);
  pinMode(led2,OUTPUT);
  pinMode(ldr2,INPUT);
  pinMode(solar2,INPUT);
  pinMode(ir2,INPUT);
  pinMode(led3,OUTPUT);
  pinMode(ldr3,INPUT);
  pinMode(solar3,INPUT);
  pinMode(ir3,INPUT);
  pinMode(led4,OUTPUT);
  pinMode(ldr4,INPUT);
  pinMode(solar4,INPUT);
  pinMode(ir4,INPUT);
  pinMode(led5,OUTPUT);
  pinMode(ldr5,INPUT);
  pinMode(solar5,INPUT);
  pinMode(ir5,INPUT);
}

void loop() {
 if(analogRead(dayandnight)<1000)
  {
  analogWrite(led1,10);
  analogWrite(led2,10);
  analogWrite(led3,10);
  analogWrite(led4,10);
  analogWrite(led5,10); 
  Serial.println("Night Time All Lights ON");
  Serial.println("Solar Discharged");
  if(analogRead(ldr1)> 3700 & analogRead(ldr2) > 3700 & analogRead(ldr3) > 3700 & analogRead(ldr4)>3700 & analogRead(ldr5) >3700)
  {
    Serial.println("ALL POST ARE GOOD CONDITION");
  }
  else if(analogRead(ldr1)<3700 )
  {
        Serial.println("POST 1 FAULTED");
  }
  else if(analogRead(ldr2)<3700 )
  {
        Serial.println("POST 2 FAULTED");
  }
   else if(analogRead(ldr3)<3700 )
  {
        Serial.println("POST 3 FAULTED");
  }
  else if(analogRead(ldr4)<3700 )
  {
        Serial.println("POST 4 FAULTED");
  }
  else if(analogRead(ldr5)<3700 )
  {
        Serial.println("POST 5 FAULTED");
  }


  if(digitalRead(ir1)==0)
  {
  analogWrite(led1,255);
  analogWrite(led2,255);
  delay(3000);
  }
  else if (digitalRead(ir2)==0)
  {
  analogWrite(led1,10);
  analogWrite(led2,255);
  analogWrite(led3,255);
   delay(3000);
  }
  else if (digitalRead(ir3)==0)
  {
  analogWrite(led2,10);
  analogWrite(led3,255);
  analogWrite(led4,255);
  delay(3000);
  }
  else if (digitalRead(ir4)==0)
  {
  analogWrite(led3,10);
  analogWrite(led4,255);
  analogWrite(led5,255);
  delay(3000);
  }
  else if (digitalRead(ir5)==0)
  {
  analogWrite(led4,10);
  analogWrite(led5,255);
  delay(3000);
  }
  }
  else if (analogRead(dayandnight)>1000)
  {
  Serial.println("DAY Time All Lights OFF");
  Serial.println("Solar Charging");
  analogWrite(led1,0);
  analogWrite(led2,0);
  analogWrite(led3,0);
  analogWrite(led4,0);
  analogWrite(led5,0); 
  delay(3000);
  }
  delay(10);
}
