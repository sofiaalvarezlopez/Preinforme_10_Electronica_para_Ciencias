/**
 * Autora: Maria Sofia Alvarez Lopez - 201729031
 * Parte 4: Compuertas compuestas
 * Itra implementacion para el circuito de la figura 10.8 de la guia
 */
//Variables globales
int D2 = 2; //Representa el pin de entrada D2 (Entrada A).
int D3 = 3; //Representa el pin de entrada D3 (Entrada B).
int D7 = 7; //Representa el pin de salida D7 (Salida C).
int D8 = 8; //Representa el pin de salida D8 (Salida D).
int D9 = 9; //Representa el pin de salida D9 (Salida Y).
int A; //Variable para almacenar lo medido en A.
int B; //Variable para almacenar lo medido en B.
// put your setup code here, to run once:
void setup() {
  //Decimos cuales pines son seniales de entrada y cuales de salida.
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);  

}
// put your main code here, to run repeatedly:
void loop() {
  //Leemos los datos de los pines.
  A = digitalRead(D2);
  B = digitalRead(D3);
  //Convertimos a booleanos.
  boolean boolean_A = convertir(A);
  boolean boolean_B = convertir(B);
  int C = punto_C(boolean_A,boolean_B,D7);
  int D = punto_D(boolean_A,boolean_B,D8);
  punto_Y(C,D,D9);

}
//Implementacion de la compuerta en C
boolean punto_C(boolean A, boolean B, int C){
  boolean lect = !A && B;
  digitalWrite(C,!A && B);
  return lect;
}
//Implementacion de la compuerta en D
boolean punto_D(boolean A, boolean B, int D){
  boolean lect = !B && A;
  digitalWrite(D,!B && A);
  return lect;
}
//Implementacion de la compuerta en Y
void punto_Y(boolean C, boolean D, int Y){
  boolean expr = C || D;
  digitalWrite(Y,expr);
}
//Convierte los valores de HIGH y LOW a TRUE o FALSE
boolean convertir(int A){
  boolean boolean_val = A == HIGH ? true : false;
  return boolean_val;
}
