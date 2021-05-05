/**
 * Autora: Maria Sofia Alvarez Lopez - 201729031
 * Parte 1: Sensor de temperatura
 * Este codigo digitaliza una señal analoga de temperatura y muestra la medicion en el puerto serial
 */

//Variables globales
int puerto_serial = A2; //Este es el pin del arduino en el que leeremos la senial.
int lectura_sensor; //Variable para almacenar el valor de temperatura (en V) leido por el Arduino.
double temperatura; //Variable para almacenar el valor de la temperatura (en ºC).

// put your setup code here, to run once:
void setup() {
  //Iniciamos la toma de datos a un baud rate de 9600 baud.
  Serial.begin(9600);
  Serial.println("Temperatura (ºC)");

}

// put your main code here, to run repeatedly:
void loop() {
  //Leemos la senial medida en la variable puerto_serial, que oscila entre 0 y 1023
  lectura_sensor = analogRead(puerto_serial);
  //Identificamos el "nivel" que ha sido leido, considerando que la temperatura mas alta corresponde a una medicion de 1024.
  //Multiplicamos por 5000 con el fin de conocer la medicion en miliVoltios.
  float milivoltios = (lectura_sensor/1023.0)*5000;
  //Segun las especificaciones del LM35, 10 mV es 1ºC. 
  temperatura = milivoltios/10;
  //Imprimimos el valor de temperatura medido
  Serial.println(temperatura);
  //Esperamos 100 ms para repetir el loop. Esto nos asegura que estamos tomando aproximadamente 10 datos cada segundo, pues cada 100 ms tomamos 1 dato y 1s = 10*100 ms
  delay(100);
}
