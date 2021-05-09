/**
 * Autora: Maria Sofia Alvarez Lopez - 201729031
 * Parte 4: Compuertas compuestas
 * Este codigo implementa el circuito de la figura 10.8 de la guia
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
  A = digitalRead(D2);
  B = digitalRead(D3);
  boolean C = punto_C(A,B,D7);
  boolean D = punto_D(A,B,D8);
  punto_Y(C,D,D9);

}
//Implementacion de la compuerta en C
boolean punto_C(int A, int B, int C){
  //Lo primero que hacemos es negar A
  int not_A = A == HIGH ? LOW : HIGH;
  //Ahora hacemos not_A AND B
  not_A == HIGH && B == HIGH ? digitalWrite(C, HIGH) : digitalWrite(C, LOW);
  return convertir(not_A) && convertir(B);
  }
//Implementacion de la compuerta en D
boolean punto_D(int A, int B, int D){
  //Lo primero que hacemos es negar B
  int not_B = B == HIGH ? LOW : HIGH;
  //Ahora hacemos not_B AND A
  not_B == HIGH && A == HIGH ? digitalWrite(D, HIGH) : digitalWrite(D, LOW);
  return convertir(not_B) && convertir(A);
  }
//Implementacion de la compuerta en Y
void punto_Y(boolean C, boolean D, int Y){
  C == true || D == true ? digitalWrite(Y, HIGH) : digitalWrite(Y, LOW);
}
//Convierte los valores de HIGH y LOW a TRUE o FALSE
boolean convertir(int A){
  boolean boolean_val = A == HIGH ? true : false;
  return boolean_val;
}
