//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define motor_direito 13
#define motor_esquerdo 10

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode (motor_direito, OUTPUT);
  digitalWrite (motor_direito, LOW);
  pinMode (motor_esquerdo, OUTPUT);
  digitalWrite (motor_esquerdo, LOW);
 
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  if (cmMsec > 30) {
    digitalWrite (motor_direito, HIGH);
    digitalWrite (motor_esquerdo, HIGH);
  }
  else {
    digitalWrite (motor_direito, LOW);
    digitalWrite (motor_esquerdo, LOW);
    delay (2000);
    digitalWrite (motor_direito, HIGH);
    delay (1300);
  }
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  delay (100);
}
