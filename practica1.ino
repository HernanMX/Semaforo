#define pot A1
#define led_v 2
#define led_a 3
#define led_r 4
#define btn   5
#define led_pe 6

int valorPot= 0;
int var = 0;
boolean valor_boton = HIGH;
float tiempo = 0;

void setup() {
  pinMode(led_v, OUTPUT);
  pinMode(led_a, OUTPUT);
  pinMode(led_r, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}


void loop() {
   digitalWrite(led_pe,LOW);
    digitalWrite(led_r,LOW);
    valorPot=analogRead(pot)*2;
     while(tiempo <= valorPot){ 
     digitalWrite(led_v,HIGH);
      valor_boton = digitalRead(btn);
      while(valor_boton == LOW){
        secuencia1();
      }  
      tiempo = tiempo + 0.01;
     }
     tiempo = 0;
      digitalWrite(led_v,LOW);
      delay(500); 
      digitalWrite(led_v,HIGH);
      delay(500);
      digitalWrite(led_v,LOW);
      delay(500);
      digitalWrite(led_v,HIGH);
      delay(500);
      digitalWrite(led_v,LOW);
      delay(500);
      digitalWrite(led_a,HIGH);
      delay(1000);
      digitalWrite(led_a,LOW);
      delay(1000);
      digitalWrite(led_r,HIGH);
      digitalWrite(led_pe,HIGH);
      delay(3000);
      digitalWrite(led_r,LOW);
      digitalWrite(led_pe,LOW);
      delay(1000);
}

    void secuencia1(){  
      digitalWrite(led_v,LOW);
      digitalWrite(led_v,HIGH);
      delay(500);
      digitalWrite(led_v,LOW);
      delay(500);
      digitalWrite(led_v,HIGH);
      delay(500);
      digitalWrite(led_v,LOW);
      delay(500);
      digitalWrite(led_v,HIGH);
      delay(500);
      digitalWrite(led_v,LOW);
      delay(500);
      digitalWrite(led_a,HIGH);
      delay(1000);
      digitalWrite(led_a,LOW);
      delay(1000);
      digitalWrite(led_pe,HIGH);
      digitalWrite(led_r,HIGH);
      delay(3000);
      digitalWrite(led_r,LOW);
      digitalWrite(led_pe,LOW);
      delay(1000);
      valor_boton = HIGH;
      valorPot=analogRead(pot)*2;
      }

     
