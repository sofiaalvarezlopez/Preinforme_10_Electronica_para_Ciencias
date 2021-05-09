/**
 * Parte 2: Detector de Oscuridad
 * Autora: Maria Sofia Alvarez Lopez - 201729031
 * Este codigo digitaliza dos seniales analogas:
 * A0: Divisor de Voltaje con Potenciometro. A1: Divisor de Voltaje R con Fotocelda.
 * Ademas, activa la senial digital D10 cuando la senial A0 (potenciometro) sea mayor a la de A1 (fotocelda).
 */

int puerto_potenciometro = A0; //El pin en que leeremos la senial analoga del potenciometro.
int puerto_fotocelda = A1; //El pin en que leeremos la senial analoga de la fotocelda.
int salida_digital_LED = 10; //El pin de salida que se activara si la senial del potenciometro (A0) es mayor a la de la fotocelda (A1).
int lectura_potenciometro; //Variable para almacenar la medicion del potenciometro en el canal A0.
int lectura_fotocelda; //Variable para almacenar la medicion de la fotocelda en el canal A1.

// put your setup code here, to run once:
void setup() {
  //Iniciamos la toma de datos a un baud rate de 9600 baud.
  Serial.begin(9600);
  //Configuramos cada uno de los pines: ¿cuales seniales son de entrada y cuales de salida?
  pinMode(puerto_potenciometro, INPUT); //Senial de entrada del potenciometro.
  pinMode(puerto_fotocelda,INPUT); //Senial de entrada de la fotocelda.
  pinMode(salida_digital_LED,OUTPUT); //Senial de salida para encender/apagar el LED.
  //Imprimimos el encabezado
  Serial.print("V(A0) - Pot"); 
  Serial.print(F("\t")); //Separamos el texto con \t -una tabulacion- para 'serial plotter'
  Serial.print("V(A1) - Foto"); //el '3' indica 3 cifras decimales
  Serial.print(F("\n"));       //la ultima lectura debe terminar con un final de linea \n para 'serial plotter'
}

// put your main code here, to run repeatedly:
void loop() {
  //Leemos la senial medida en cada uno de los puertos seriales.
  //Primero, para el potenciometro.
  lectura_potenciometro = analogRead(puerto_potenciometro);
  //Ahora, para la fotocelda
  lectura_fotocelda = analogRead(puerto_fotocelda);
  //De manera similar al caso anterior, debemos convertir las seniales recibidas a voltios. 
  //Debemos identificar el "nivel" que ha sido leido, considerando que el voltaje mas elevado corresponde a 1024.
  //Multiplicamos por 5 con el fin de conocer la medicion en Voltios y dividimos entre 1023.0, haciendo una regla de 3. 
  //Primero para el potenciometro.
  float voltaje_potenciometro = lectura_potenciometro*5.0/1023.0;
  //Ahora, para la fotocelda.
  float voltaje_fotocelda = lectura_fotocelda*5.0/1023.0;
  //Imprimimos los valores obtenidos.
  Serial.print(voltaje_potenciometro,3); //el '3' indica 3 cifras decimales
  Serial.print(F("\t")); //Separamos los valores con \t -una tabulacion- para 'serial plotter'
  Serial.print(voltaje_fotocelda,3); //el '3' indica 3 cifras decimales
  Serial.print(F("\n"));       //la ultima lectura debe terminar con un final de linea \n para 'serial plotter'

  //Debemos encender el LED (i.e. activar la senial del pin D10 del Arduino) cuando la senial del potenciometro sea mayor a la de la fotocelda. 
  if (voltaje_potenciometro > voltaje_fotocelda){
    digitalWrite(salida_digital_LED, HIGH); //Como enviamos una senial HIGH (alta) por el pin digital, el LED se encendera (o se mantendra encendido).
  }
  else{
    digitalWrite(salida_digital_LED, LOW); //Como enviamos una senial LOW (baja) por el pin digital, el LED se apagara (o se mantendra apagado).
  }
  //Esperamos 100 ms para repetir el loop. Esto nos asegura que estamos tomando aproximadamente 10 datos cada segundo, pues cada 100 ms tomamos 1 dato y 1s = 10*100 ms
  delay(100);
}
