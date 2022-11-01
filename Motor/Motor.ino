#define motor 4
void setup() {
  // put your setup code here, to run once:
  pinMode (motor, OUTPUT);
  digitalWrite (motor, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (motor, HIGH);
  
}
