int led=6;
int relay=13;
int pot=A0;
int menyala=0;
int VB = A1; 
int cutof=0;
int pwm12=5;
int rb=0;
int rb12=A2;
int input=A3;
int gate12=0;

void setup () {
  Serial.begin(9600);
  pinMode (led, OUTPUT);
  pinMode (relay, OUTPUT);
  pinMode (7, OUTPUT);
   pinMode (pot, INPUT);
  pinMode (cutof, INPUT);
  pinMode(pwm12, OUTPUT);
  TCCR0B = TCCR0B & B11111000 | B00000010;
}
void loop () {
  menyala=analogRead(A0);
  menyala=map(menyala,0,1023,0,255);
  analogWrite(led,50);
  if (pot > 60)
  {
    analogWrite (led, 50);
  }
  else (pot < 60);
  {
    analogWrite (led, 50);
  }
  Serial.println(led);
  cutof=analogRead(VB);
  cutof=(cutof,0,1023);
  if (cutof < 1000)
  {
    digitalWrite (relay, LOW);
  }
  else (cutof > 1000);
  {
    digitalWrite (relay, HIGH);
  }
//  
//    rb = analogRead(rb12);
//    rb = map(rb, 0, 1023, 0, 255); 
//    gate12 =analogRead(input);
//    gate12 = (gate12, 0, 1023); 
//    if (rb < 120){
//    analogWrite(pwm12, 120);
//    }
//    else if (rb > 120){
//       analogWrite(pwm12, 120);
//    }
//    if (gate12 < 120)
//  {
//    digitalWrite (7, HIGH);
//    
//  }
//  else (gate12 > 120);
//  {
//    digitalWrite (7, LOW);
//    
//  }
}
