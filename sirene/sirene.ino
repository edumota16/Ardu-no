#define a 13
#define b 12


void setup() {
 pinMode (a, OUTPUT);
 pinMode (b, OUTPUT);


 digitalWrite (a, LOW);
 digitalWrite (b, LOW);

}

void loop() {
 digitalWrite (a, HIGH);
 delay (200);
 digitalWrite (a, LOW);
 delay (200); 
 digitalWrite (b, HIGH);
 delay (100);
 digitalWrite (b, LOW);
}
