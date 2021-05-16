/**
 * Autora: Maria Sofia Alvarez Lopez - 201729031
 * Parte 3: Compuertas Simples (Version 1).
 * Este codigo implementa las compuertas simples NOT, AND, OR usando condicionales.
 */

//Variables globales
int D2 = 2; //Representa el pin de entrada D2.
int D3 = 3; //Representa el pin de entrada D3.
int D4 = 4; //Representa el pin de salida D4.
int D5 = 5; //Representa el pin de salida D5.
int D6 = 6; //Representa el pin de salida D6.
int puerto_A0 = A0;
int A; //Variable para almacenar la lectura del pin digital D2.
int B; //Variable para almacenar la lectura del pin digital D3.

// put your setup code here, to run once:
void setup() {
  Serial.begin(9600);
  //Decimos cuales pines son seniales de entrada y cuales de salida.
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(puerto_A0, INPUT);
  
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  //Invocamos a cada una de las funciones con sus pines de entrada y salida.
  A = digitalRead(D2);
  B = digitalRead(D3);
  int medida = analogRead(puerto_A0);
  float voltaje = medida*5.0/1023.0;
  Serial.println(voltaje,3);
  //NOT(A,D4);
  //AND(A,B,D5);
  OR(A,B,D6);

}
//Implementacion del NOT para una entrada A y una salida Y.
void NOT(int A, int Y){
  A == HIGH ? digitalWrite(Y,LOW) : digitalWrite(Y,HIGH);
}

//Implementacion del AND para dos entradas A,B y una salida Y.
void AND(int A, int B, int Y){
  A == HIGH && B == HIGH ? digitalWrite(Y, HIGH) : digitalWrite(Y,LOW);
}

//Implementacion del OR para dos entradas A,B y una salida Y.
void OR(int A, int B, int Y){
  A == HIGH || B == HIGH ? digitalWrite(Y, HIGH) : digitalWrite(Y,LOW);
}
