// Arduprofe Prueba de Modulo I2C para LCD 2x16 By: http://dinastiatecnologica.com
// Debe instalar la libreria LiquidCrystal_I2C para que le funcione el programa
// Debe descargar la Libreria 
/* 
 Conexiones del I2C al Arduino:
 I2C ---->  Arduino
 SCL        A5      
 SDA        A4
 VCC        5V
 GND        GND  
*/

// Display LCD
#include<Wire.h>
#include <LiquidCrystal_I2C.h>

// Lectura de Temperatura
#include <OneWire.h>
#include <DallasTemperature.h>

// Definiciones
#define DatosSen 4

// Inicializacion de purtos LCD - I2C
LiquidCrystal_I2C lcd(0x27,16,2); // dependiendo del fabricante del LCD el codigo 0x27 puede cambiar
                                  // 0x3F , 0x20 , 0x38 , 

// Iniciacion Sensor
OneWire ObjWire(DatosSen); 

// Se llama a la librería DallasTemperature
DallasTemperature sensor(&ObjWire);

//Variables
float Temperatura = 0;

void setup() {
  // Comunicacion con Objeto OneWire
  sensor.begin();

  // Iniciacion del LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(".. Temp .."); // Mensaje a desplegar
  lcd.setCursor(0,1);
  lcd.print("Prueba LCD 16x2 "); // Mensaje 2 a desplegar
  delay(3000); // espera 3 segundos con el mensaje estatico 
}

void loop() { 
  // Prepara el sensor para la lectura 
  sensor.requestTemperatures();

  // Lectura de temperatura
  //Temperatura = sensor.getTempCByIndex(0);

  // Impresion de la temperatura
  // Primer Renglon
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp. en C");

  // Segundo Renglon
  lcd.setCursor(0, 1);
  lcd.print("C => ");
  lcd.print(sensor.getTempCByIndex(0));

  delay(500);
}
