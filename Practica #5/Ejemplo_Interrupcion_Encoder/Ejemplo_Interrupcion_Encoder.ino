// Declaracion de Variables
// Definicion de Pines
#define encoder   3

// Variables
int valorPot  = 0;
int PWM       = 0;
float RPM = 0;

// Variable interrupcion
volatile int contador = 0;


void setup() {
  // Iniciacion de Puertos
  pinMode(encoder, INPUT);

  // Configuracion de la interrupcion
  attachInterrupt(1, interrupcion, RISING);

  // Activavion Comunicacion Serial
  Serial.begin(9600);
  Serial.print ("Inicio Programa");
}

void loop() {
  delay(1000);
  RPM = contador;

  Serial.print("Contador: ");
  Serial.println(contador);
  
  Serial.print("Revoluciones por segundo: ");
  Serial.println(RPM/30);
  
  Serial.print("Revoluciones por minuto: ");
  Serial.println((RPM/30)*60);
  contador = 0;
}

// Interrupciones
void interrupcion(){
  contador++;
}
