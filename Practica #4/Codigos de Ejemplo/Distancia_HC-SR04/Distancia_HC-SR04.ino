/*-------------------------------------------------------------------------------
  Practica numero 12 - Medidor de distancia con HC-SR04.
  Desc: Implementando una placa de desarrollo Arduino NANO junto con el sensor 
  ultrasónico HC-SR04 se realizará mediciones de distancia, marcando a cuantos 
  metros o centímetros esta un objeto dentro del rango del sensor, esta se vera 
  desplegada por medio de un LCD 16x2.

  Atzin Inyan Reyes Gutiérrez.
-------------------------------------------------------------------------------*/

// Seccion 1 - Definicion de variables y objetos --------------------------------
// Librerias
#include<Wire.h>
#include <LiquidCrystal_I2C.h>

// Definiciones
#define TRIG 10       // trigger en pin 10
#define ECO 9         // echo en pin 9

// Objetos
LiquidCrystal_I2C lcd(0x27,16,2);

// Variables
float DURACION;
float DISTANCIA;

//-------------------------------------------------------------------------------

// Seccion 2 - Configuracion del arduino ----------------------------------------

void setup() {
  // Iniciacion de Variables
  pinMode(TRIG, OUTPUT);  // trigger como salida
  pinMode(ECO, INPUT);    // echo como entrada
  Serial.begin(9600);
  
  // Iniciacion del LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Mensaje Inicial
  lcd.setCursor(1,0);
  lcd.print(". ArduMedidor ."); // Mensaje a desplegar
  lcd.setCursor(0,1);
  lcd.print("- Iniciando... -"); // Mensaje 2 a desplegar
  delay(3000); // espera 3 segundos con el mensaje estatico

  // Imagen del LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dist:");
  lcd.setCursor(1,1);
  lcd.print("Colocar Objeto"); 
  delay(3000);                  
}

//-------------------------------------------------------------------------------

// Seccion 3 - Loob Infinito ----------------------------------------------------

void loop() {
  // Iniciando Los sensores
  digitalWrite(TRIG, HIGH);       // generacion del pulso a enviar
  delay(1);                       // al pin conectado al trigger
  digitalWrite(TRIG, LOW);        // del sensor

  // Duracion
  DURACION = pulseIn(ECO, HIGH);  // con funcion pulseIn se espera un pulso

  // Distancia
  DISTANCIA = (DURACION/2) / 29.1;    // distancia medida en centimetros

  Serial.println(DISTANCIA);

  // Impresion de variable
  if(DISTANCIA < 500){
    // Metros
    if(DISTANCIA >= 100){
      // Borrar la parte importante
      Borrar();

      // Imprecion en LCD
      lcd.setCursor(6, 0);
      lcd.print(DISTANCIA/100, 2);
      lcd.setCursor(12, 0);
      lcd.print("m");
    }
    
    // centimetros
    else if(DISTANCIA < 100){
      // Borrar la parte importante
      Borrar();

      // Imprecion en LCD
      lcd.setCursor(6, 0);
      lcd.print(DISTANCIA, 2);
      lcd.setCursor(12, 0);
      lcd.print("cm");
    }
  }
  else{
    // Borrar la parte necesaria
    Borrar();

    // Fuera de Rango
    lcd.setCursor(6, 0);
    lcd.print("Fuera Ran.");
  }

  // Retardo
  delay(1000);
}

//-------------------------------------------------------------------------------

// Seccion 4 - Funciones --------------------------------------------------------
void Borrar(){
  for(int i = 6; i <= 15; i++){
    lcd.setCursor(i, 0);
    lcd.print(" ");
  }
}
//-------------------------------------------------------------------------------
