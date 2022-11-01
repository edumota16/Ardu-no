#define motor_direito 13
#define motor_esquerdo 10
char c;

void setup() {
  Serial.begin(9600);
  pinMode (motor_direito, OUTPUT);
  digitalWrite (motor_direito, LOW);
  pinMode (motor_esquerdo, OUTPUT);
  digitalWrite (motor_esquerdo, LOW);
}

void loop() {
   c=Serial.read();
     if(c == 'A'){
      digitalWrite(motor_esquerdo, HIGH);
      digitalWrite(motor_direito, HIGH);
     }
     if(c == 'a'){
      digitalWrite(motor_esquerdo, LOW);
      digitalWrite(motor_direito, LOW);
     }
     if(c == 'B'){
      digitalWrite(motor_direito, HIGH);
      digitalWrite(motor_esquerdo, LOW);
     }
     if(c == 'b'){
      digitalWrite(motor_direito, LOW);
      digitalWrite(motor_esquerdo, LOW);
     }
    if(c == 'C'){
      digitalWrite(motor_esquerdo, HIGH);
      digitalWrite(motor_direito, LOW);      
     }
     if(c == 'c'){
      digitalWrite(motor_esquerdo, LOW);
      digitalWrite(motor_direito, LOW);      
     }
  }
 
