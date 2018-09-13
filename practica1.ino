#define pot A1
#define led_v 2
#define led_a 3
#define led_r 4
#define btn   5
#define led_pe 6
#define led_pr 7
#define buzzer 9

int valorPot = 0;  //variable la cual contendra el valor leido del potenciometro
boolean valor_boton = HIGH; //variable para saber si el boton se ha presionado
float tiempo = 0; // variable para controlar el tiempo de duración del led verde

boolean espera = false;

void setup() {
  //Defi|nicion de los distintos componentes de 
  //nuestro prototipo como entradas o salidas
  Serial.begin(9600);
  pinMode(led_v, OUTPUT);
  pinMode(led_a, OUTPUT);
  pinMode(led_r, OUTPUT);
  pinMode(led_pe, OUTPUT);
  pinMode(led_pr, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn, INPUT);
}


void loop() {
  //Leemos el valor de poteciometro, dicho valor sera utilizado en 
  //conjunto con la variable tiempo para asignar el tiempo que durara 
  //el led verde del semaforo para los automoviles y el rojo de los peatones
    valorPot = analogRead(pot) * 5;
    digitalWrite(led_v, HIGH);
    digitalWrite(led_pr, HIGH);
    if(espera){
      espera= false;
      delay(5000);
    } 
    valor_boton = digitalRead(btn); // guardamos el valor si el boton se presiona
     Serial.println(tiempo);
    while (valor_boton == LOW  || tiempo > valorPot) { //Si el boton es presionado llamamos al metodo secuencia1() que es para iniciar la secuencia del semaforo peatonal.
      secuencia1();
      
    }
  tiempo = tiempo + 0.01;
  
}

void secuencia1() {
  //Secuencia por si el boton es presionado la cual es
  //parpadea el led verde, pasa al amarillo,y encedemos el led rojo
  //asi como apagamos el led rojo del peaton y encendemos el verde
  digitalWrite(led_v, LOW);
  digitalWrite(led_v, HIGH);
  delay(500);
  digitalWrite(led_v, LOW);
  delay(500);
  digitalWrite(led_v, HIGH);
  delay(500);
  digitalWrite(led_v, LOW);
  delay(500);
  digitalWrite(led_v, HIGH);
  delay(500);
  digitalWrite(led_v, LOW);
  delay(500);
  digitalWrite(led_a, HIGH);
  delay(1000);
  digitalWrite(led_a, LOW);
  digitalWrite(led_pr, LOW);
  delay(1000);
  beep();  ////Reproducimos un sonido cuando el semaforo del peaton pasa a verde.
  digitalWrite(led_pe, HIGH);
  digitalWrite(led_r, HIGH);
  delay(valorPot);
  digitalWrite(led_r, LOW);
  digitalWrite(led_pe, LOW);
  delay(1000);
  valor_boton = HIGH;
  valorPot = analogRead(pot) * 5;
  espera = true;
}


//Metodo para emitir tono al cambiar al semaforo del peaton.
void beep()
        {
            analogWrite(buzzer, 128);
            delay(500);                
            analogWrite(buzzer, 0);          
            delay(500);                 
        }
