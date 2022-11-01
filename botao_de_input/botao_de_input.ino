#define botao 7
#define botaoB 6
#define saida 13
#define saidaB 12

void setup() {
  pinMode (botao, INPUT_PULLUP);
  pinMode (botaoB, INPUT_PULLUP);
  pinMode (saida, OUTPUT);
  pinMode (saidaB, OUTPUT);
  digitalWrite (saida, LOW);
  digitalWrite (saida, LOW);
}

void loop() {
  if (digitalRead (botao) == LOW){
    digitalWrite (saida, HIGH);
    delay (100);
    digitalWrite (saida, LOW);
  }
  if (digitalRead (botaoB) == LOW){
    digitalWrite (saidaB, HIGH);
    delay (100);
    digitalWrite (saidaB, LOW);
  }

} 
