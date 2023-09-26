#define SENSOR 2 // define pint 2 for sensor
#define ACTION 4 // define pin 4 as for ACTION
#define Buzz 9
#define motor1r 3
#define motor1l 5
int counter = 0;                   // counter value
int counter2 =0;
int langkah = 0;
int upperLimit = 2;      // Upper limit
boolean up = true;// Counter direction flag     
void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(SENSOR, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(ACTION, OUTPUT);// define pin as OUTPUT for ACTION
  pinMode(Buzz, OUTPUT);
  pinMode(motor1r, OUTPUT);
  pinMode(motor1l, OUTPUT);
}
void loop() {
  int L =digitalRead(SENSOR);// read the sensor
  Serial.println(L); 
   if(L ==0 && langkah ==0)               //langkah 2
   {
    Serial.println(" Obstacle detected");
    digitalWrite(motor1r,LOW);
    digitalWrite(motor1l,LOW);
    langkah=1;
    counter = counter +1;
  }
  else if(L>0 && langkah ==0)   //ini syaratnya harus dari flow sensor sebenarnya
  {                             //bukan dari proximity 
    digitalWrite(motor1r,HIGH); //langkah 1
    digitalWrite(motor1l,LOW);
    }
    
  else if(langkah ==1){
    delay(3000); //ini buat waktu buang sampah
    digitalWrite(motor1l,HIGH); //ini harusnya motor 2
    digitalWrite(motor1r,LOW);
    delay(3000);
    digitalWrite(motor1l,LOW);
    digitalWrite(motor1r,LOW);
    delay(3000); //sebenarnya ini buat berhenti sementara menunggu flow sensor
    langkah = 0;
    }
  
  else if(counter ==2){
    delay(3000);
    digitalWrite(ACTION,HIGH);// send singal 
    delay(3000);
    digitalWrite(ACTION,LOW);
    counter2=counter2 +1;
    counter =0;
    }  
    else if(counter2 == 2){
      digitalWrite(Buzz,HIGH);
      delay(3000);
      digitalWrite(Buzz,LOW);
      counter2=0;
    }   
     else if(L>0){
    Serial.println("  === All clear");
     //langkah =0;
     }
}
