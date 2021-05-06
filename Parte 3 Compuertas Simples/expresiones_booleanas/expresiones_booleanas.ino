/**
 * Autora: Maria Sofia Alvarez Lopez - 201729031
 * Parte 3: Compuertas Simples (Version 1).
 * Este codigo implementa las compuertas simples NOT, AND, OR usando expresiones booleanas.
 */

//Variables globales
int D2 = 2; //Representa el pin de entrada D2.
int D3 = 3; //Representa el pin de entrada D3.
int D4 = 4; //Representa el pin de salida D4.
int D5 = 5; //Representa el pin de salida D5.
int D6 = 6; //Representa el pin de salida D6.
int A; //Variable para almacenar la lectura del pin digital D2.
int B; //Variable para almacenar la lectura del pin digital D3.

// put your setup code here, to run once:
void setup() {
  //Decimos cuales pines son seniales de entrada y cuales de salida.
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

}

// put your main code here, to run repeatedly:
void loop() {
  A = digitalRead(D2);
  B = digitalRead(D3);
  //NOT
  //D4 != D2; //D4 es la negacion de D2.
  digitalWrite(D4, !A);
  //AND
  //D5 = D2 && D3; //D5 = D2 AND D3.
  digitalWrite(D5, A && B);
  //OR
  //D6 = D2 || D3; // D6 = D2 OR D3.
  digitalWrite(D6, A || B);
 
}

//Implementacion del NOT para una entrada A y una salida Y.
void NOT(int A, int Y){
  digitalWrite(Y, !A);
}

//Implementacion del AND para dos entradas A,B y una salida Y.
void AND(int A, int B, int Y){
  digitalWrite(Y, A && B);
}

//Implementacion del OR para dos entradas A,B y una salida Y.
void OR(int A, int B, int Y){
  digitalWrite(Y, A || B);
}
