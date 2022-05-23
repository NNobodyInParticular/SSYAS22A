 // Declaracion de Variables
// Definicion de Pines
#define motorPin  5
#define pot       A2

// Variables
int valorPot  = 0;
int PWM       = 0;

void setup() {
  // Iniciacion de Puertos
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Lectura analogica del Potenciometro
  valorPot = analogRead(pot);

  // Tranformacion lectura a PWM
  PWM = map(valorPot, 0, 1023, 0, 255);

  // Salida del Puerto PWM
  analogWrite(motorPin, PWM);
}
