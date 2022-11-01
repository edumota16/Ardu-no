 
#include "Wire.h"
#include <LiquidCrystal.h>
 
#define DS1307_ADDRESS 0x68

const int sensor_temp = A0; 
float temperatura; 

 int porta_rele1 = 7;
 int porta_rele2 = 8;
// Inicializa o LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
byte zero = 0x00; 
 
void setup()
{
 // Define o LCD com 20 colunas e 4 linhas
 lcd.begin(20, 4);
 Wire.begin();
 Serial.begin(9600);

 // define os pinos de saída do relé
 pinMode(porta_rele1, OUTPUT); 
 pinMode(porta_rele2, OUTPUT);
}
void SelecionaDataeHora() // Seta a data e a hora do DS1307
{
 byte segundos = 02; // Valores de 0 a 59
 byte minutos = 50; // Valores de 0 a 59
 byte horas = 10; // Valores de 0 a 23
 byte diadasemana = 4; // Valores de 0 a 6 (0=Domingo, 1 = Segunda...)
 byte diadomes = 20; // Valores de 1 a 31
 byte mes = 6; // Valores de 1 a 12
 byte ano = 19; // Valores de 0 a 99
 Wire.beginTransmission(DS1307_ADDRESS);
 // Stop no CI para que o mesmo possa receber os dados
 Wire.write(zero); 
 
 // As linhas abaixo escrevem no CI os valores de 
 // data e hora que foram colocados nas variaveis acima
 Wire.write(ConverteParaBCD(segundos));
 Wire.write(ConverteParaBCD(minutos));
 Wire.write(ConverteParaBCD(horas));
 Wire.write(ConverteParaBCD(diadasemana));
 Wire.write(ConverteParaBCD(diadomes));
 Wire.write(ConverteParaBCD(mes));
 Wire.write(ConverteParaBCD(ano));
 Wire.write(zero); //Start no CI
 Wire.endTransmission(); 
}
 
byte ConverteParaBCD(byte val)
{ 
 // Converte o número de decimal para BCD
 return ( (val/10*16) + (val%10) );
}
 
byte ConverteparaDecimal(byte val) 
{ 
 // Converte de BCD para decimal
 return ( (val/16*10) + (val%16) );
}
 
void Mostrarelogio()
{
 Wire.beginTransmission(DS1307_ADDRESS);
 Wire.write(zero);
 Wire.endTransmission();
 Wire.requestFrom(DS1307_ADDRESS, 7);
 int segundos = ConverteparaDecimal(Wire.read());
 int minutos = ConverteparaDecimal(Wire.read());
 int horas = ConverteparaDecimal(Wire.read() & 0b111111); 
 int diadasemana = ConverteparaDecimal(Wire.read()); 
 int diadomes = ConverteparaDecimal(Wire.read());
 int mes = ConverteparaDecimal(Wire.read());
 int ano = ConverteparaDecimal(Wire.read());
}
 // Mostra o dia da semana no display
 lcd.setCursor(8, 0);
 switch(diadasemana)
 {
 case 0:lcd.print("Sunday");
 break;
 case 1:lcd.print("Monday");
 break;
 case 2:lcd.print("Tuesday");
 break;
 case 3:lcd.print("Wednesday");
 break;
 case 4:lcd.print("Thursday");
 break;
 case 5:lcd.print("Friday");
 break;
 case 6:lcd.print("Saturday");
 }
 
 // Imprime as mensagens nas linhas do display
 lcd.setCursor(0,0);
 lcd.print("DAY  :");
 lcd.setCursor(0,1);
 lcd.print("DATE :");
 lcd.setCursor(0,2);
 lcd.print("HOUR :");
 lcd.setCursor(0,3);
 lcd.print("ALARM:");

 // Mostra a data atual no display
 lcd.setCursor(8, 1);
 lcd.print("Data : ");
 lcd.setCursor(7,3);
 if (diadomes < 10)
 {lcd.print("0");}
 lcd.print(diadomes);
 lcd.print(".");
 if (mes < 10)
 {lcd.print("0");}
 lcd.print(mes);
 lcd.print(".");
 lcd.print(ano);
  
 // Mostra a hora atual no display
 lcd.setCursor(8, 2);
 if (horas < 10)
 {lcd.print("0");}
 lcd.print(horas);
 lcd.print(":");
 if (minutos < 10)
 {lcd.print("0");}
 lcd.print(minutos);
 lcd.print(":");
 if (segundos < 10)
 {lcd.print("0");}
 lcd.print(segundos);

void loop(){
 temperatura = (float(analogRead(sensor_temp))*5/(1023))/0.01;

  if(horas == 5 & minutos == 00 & diadasemana != 0){
    digitalWrite (porta_rele2, HIGH);
    delay (600000); //mantém o aquecimento ligado por 10 minutos
      if(temperatura > 85){
        digitalWrite(porta_rele2, LOW);
      }
}
  if(horas == 5 & minutos == 00 & diadasemana != 6){
    digitalWrite (porta_rele2, HIGH);
    delay (600000); //mantém o aquecimento ligado por 10 minutos
      if(temperatura > 85){
        digitalWrite(porta_rele2, LOW);
      }
}
  
 if(temperatura < 75 & diadasemana != 0){
    digitalWrite (porta_rele2, HIGH);
    delay(600000); 
    if(temperatura > 85){
      digitalWrite (porta_rele2, LOW);
    }
 }
 if(temperatura < 75 & diadasemana != 6){
    digitalWrite (porta_rele2, HIGH);
    delay(600000); 
    if(temperatura > 85){
      digitalWrite (porta_rele2, LOW);
    }
  }
}
 
 
