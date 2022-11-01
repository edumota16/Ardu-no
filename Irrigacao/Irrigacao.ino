#define bomba 5
#define sensor A0
int valor_analogico;

void setup() {
  Serial.begin(9600);
  pinMode (bomba, OUTPUT);
  digitalWrite (bomba, LOW);
  pinMode (sensor, INPUT);

}

void loop() {
  valor_analogico = analogRead(sensor);
  Serial.print("\nPorta analogica: \n");
  Serial.print(valor_analogico);
  if (valor_analogico > 600)
  {
    digitalWrite (bomba, HIGH);
    delay (3250);
    digitalWrite (bomba, LOW);
  } else {
    digitalWrite (bomba, LOW);
  }
  delay (10000);
}
