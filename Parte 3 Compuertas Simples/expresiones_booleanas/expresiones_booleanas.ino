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
  //Leemos ambos valores en el pin digital.
  A = digitalRead(D2);
  B = digitalRead(D3);
  //Convertimos los valores leidos a booleanos.
  boolean boolean_A = convertir(A);
  boolean boolean_B = convertir(B);
  //NOT
  //D4 != D2; //D4 es la negacion de D2.
  NOT(boolean_A, D4);
  //AND
  //D5 = D2 && D3; //D5 = D2 AND D3.
  AND(boolean_A, boolean_B, D5);
  //OR
  //D6 = D2 || D3; // D6 = D2 OR D3.
  OR(boolean_A, boolean_B, D6);
 
}
//Implementacion del NOT para una entrada A y una salida Y.
void NOT(boolean A, int Y){
  digitalWrite(Y, !A);
}
//Implementacion del AND para dos entradas A,B y una salida Y.
void AND(boolean A, boolean B, int Y){
  digitalWrite(Y, A && B);
}
//Implementacion del OR para dos entradas A,B y una salida Y.
void OR(boolean A, boolean B, int Y){
  digitalWrite(Y, A || B);
}
//Convierte los valores de HIGH y LOW a TRUE o FALSE
boolean convertir(int A){
  boolean boolean_val = A == HIGH ? true : false;
  return boolean_val;
}
