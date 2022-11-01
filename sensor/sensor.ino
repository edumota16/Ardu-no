#define sensor 0
#define saida 13
#define saidad 12
#define saidat 11

void setup() {
  pinMode (sensor, INPUT);
  pinMode (saida, OUTPUT);
  pinMode (saidad, OUTPUT);
  pinMode (saidat, OUTPUT);
  digitalWrite (saida, LOW);
  digitalWrite (saidad, LOW);
  digitalWrite (saidat, LOW);
  Serial.begin(9600);
  
}

void loop() {
  
  if (analogRead (sensor) >  900){ // se a tensão é maior que 2,5 V
    digitalWrite (saida, HIGH);
    if (analogRead (sensor) > 900){
      digitalWrite (saidad, HIGH);
      if (analogRead (sensor) > 900){
        digitalWrite (saidat, HIGH);
      }
    }
  }
  else{
    digitalWrite (saida, LOW);
    digitalWrite (saidad, LOW);
    digitalWrite (saidat, LOW);
  }
  Serial.print (analogRead (sensor));
  Serial.print ('\n');
  delay (500);
}
