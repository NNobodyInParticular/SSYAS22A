// Seccion 0 - Sección de descripción de conexiones en puertos ------------------
/* 
  Conexiones del I2C al Arduino:
  I2C ---->  Arduino Nano
  SCL        A5      
  SDA        A4
  VCC        5V
  GND        GND  
*/
//-------------------------------------------------------------------------------

// Declaracion de Variables
// Librerias
#include<Wire.h>
#include <LiquidCrystal_I2C.h>

// Definicion de Pines
#define encoder   3

LiquidCrystal_I2C lcd(0x27,16,2); // dependiendo del fabricante del LCD el codigo 0x27 puede cambiar
                                  // 0x3F , 0x20 , 0x38 ,

// Variables
float RPM = 0;

// Variable interrupcion
volatile int contador = 0;


void setup() {
  // Iniciacion de Puertos
  pinMode(encoder, INPUT);

  // Configuracion de la interrupcion
  attachInterrupt(1, interrupcion, RISING);

  // Iniciacion del LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  //         0123456789012345
  lcd.print(".. ArduGASGAS .."); // Mensaje a desplegar
  lcd.setCursor(0,1);
  //         0123456789012345
  lcd.print("-   ENCODER    -"); // Mensaje 2 a desplegar
  delay(3000); // espera 3 segundos con el mensaje estatico
}

void loop() {
  delay(1000);
  RPM = contador;

  lcd.clear();
  
  // Señalizacion de las Revoluciones por segunto
  lcd.setCursor(0,0);
  lcd.print("RS: ");
  lcd.print(RPM/30);

  // Señalizacion de las Revoluciones por segunto
  lcd.setCursor(10,0);
  lcd.print("F:");
  lcd.print(RPM);

  // Señalizacion de las Revoluciones por Minuto
  lcd.setCursor(0,1);
  lcd.print("RPM: ");
  lcd.print((RPM/30)*60);

  contador = 0;
}

// Interrupciones
void interrupcion(){
  contador++;
}
