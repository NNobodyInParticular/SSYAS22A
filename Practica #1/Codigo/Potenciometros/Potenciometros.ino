/*-------------------------------------------------------------------------------
  Practica numero 01 - Sensores Resistivos de Desplazamiento
  Desc: Emplear una resistencia variable para diseñar un sensor resistivo que 
  permita llevar a cabo la medición del desplazamiento lineal o angular en un 
  sistema móvil y analizar sus características más importantes.

  Atzin Inyan Reyes Gutiérrez.
-------------------------------------------------------------------------------*/

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

// Seccion 1 - Definicion de variables y objetos --------------------------------
// Definiciones
#include<Wire.h>
#include <LiquidCrystal_I2C.h>

#define Volt_Ent 5
#define Lect 1023

LiquidCrystal_I2C lcd(0x27,16,2); // dependiendo del fabricante del LCD el codigo 0x27 puede cambiar
                                  // 0x3F , 0x20 , 0x38 ,

// Variables Enteras
int Lec_A = 0, Lec_B = 0;

// Variables Flotantes
float Volt_A = 0, Volt_B = 0, Volt_Dif = 0;

// Cadena de caracteres
String Volt_Imp = "";

//-------------------------------------------------------------------------------

// Seccion 2 - Configuracion del arduino ----------------------------------------

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  //         0123456789012345
  lcd.print(".. Ardusensor .."); // Mensaje a desplegar
  lcd.setCursor(0,1);
  //         0123456789012345
  lcd.print("-Desplazamiento-"); // Mensaje 2 a desplegar
  delay(3000); // espera 3 segundos con el mensaje estatico
}

//-------------------------------------------------------------------------------

// Seccion 3 - Loob Infinito ----------------------------------------------------

void loop() {
  // Liempieza del LCD
  lcd.clear();
  
  // Lectura de los puertos analogicos del Nano
  Lec_A = analogRead(A3);
  Lec_B = analogRead(A2);
  
  // Conversion del ADC a Voltaje
  Volt_A = (Lec_A * 5.0)/(1023.0);
  Volt_B = (Lec_B * 5.0)/(1023.0);
  lcd.setCursor(0,0);
  lcd.print(Volt_A);
  lcd.setCursor(8,0);
  lcd.print(Volt_B);

  // Diferencia de voltaje entre los dos divisores
  Volt_Dif = Volt_A - Volt_B;

  // Impresion de variables
  //Volt_Imp = String(Volt_Dif, 6);
  
  lcd.setCursor(0,1);
  lcd.print("Voltaje:");
  lcd.setCursor(9,1);
  lcd.print(Volt_Dif);
  delay(500);
}

//-------------------------------------------------------------------------------
