//Projeto de irrigação automática  B-007 versão Beta (versão para testes )
// Babuino.tec
//vagnerromario@hotmail.com
              
  #define pino_sinal A0
  #define vermelho 7
  #define laranja  6
  #define verde    5
  #define azul     4
  #define bomba    9 
  #define sens     8
  #define buzzer     10
   
  #include <EEPROM.h>
  #include <LiquidCrystal_I2C.h>
  #include <Wire.h>
  int SEC,UMID,add1=15,add=11;
  int HOUR,MINUT,SECOND;

 unsigned int La = 440; //A
unsigned int Si = 466; //B
unsigned int Do = 261; //C
unsigned int Re = 294; //D
unsigned int Mi = 329; //E
unsigned int Fa = 349; //F
unsigned int Sol = 392; //G
unsigned int tempo = 100;

int melodia[] = {660,660,660,510,660,770,380};
int duracaodasnotas[] = {80,80,80,80,80,80,80};
  
  
 LiquidCrystal_I2C lcd(0x3F,16,2);


  int valor_analogico;
  void setup()
{ 
  Wire.begin(); 
  lcd.begin (16,2);
   lcd.backlight();
  Serial.begin(9600);
  pinMode(pino_sinal,INPUT);
  pinMode (vermelho,OUTPUT);
  pinMode (laranja,OUTPUT);
  pinMode (verde,OUTPUT);
  pinMode (azul,OUTPUT);
  pinMode (bomba,OUTPUT);
  pinMode (sens,OUTPUT);
  lcd.clear(); 
  //    lcd.setCursor(0, 0);
  //    lcd.print("TESTE LINHA 1");
  //    lcd.setCursor(0, 1);
  //    lcd.print("TESTE LINHA 2");

  for (int nota = 0; nota < 7; nota++) {

              int duracaodanota = duracaodasnotas[nota];
              tone(buzzer, melodia[nota],duracaodanota);
  //pausa depois das notas
              int pausadepoisdasnotas[] ={150,300,300,100,300,550,575};
              delay(pausadepoisdasnotas[nota]);}
                          noTone(buzzer);l
  tone(buzzer, Si);
  delay(tempo);
  noTone(buzzer);
  tone(buzzer, La);
  delay(tempo);
  noTone(buzzer);
  tone(buzzer, Do);
  delay(tempo);
  noTone(buzzer);

}

void loop()
{

  valor_analogico = // Aqui ler o valor do pino
  analogRead(pino_sinal);// Mostra os valores da leitura do pino na tela 
  Serial.print("Porta Analogica ");
  Serial.println(valor_analogico);
  Serial.print("BOMBA:");
   Serial.print(SEC, DEC );
   Serial.print(UMID, DEC );
  delay(1000);
  digitalWrite(sens,HIGH);
  ativar_boma();
   
//bomba ();
//Para solo umido 

{ 
  
  }
  if(valor_analogico > 0 && valor_analogico <400)
{ //lcd.clear();
   add= 10 ;
   SEC =0;
   EEPROM.write(add,SEC);
   add1= 15 ;
   UMID = 1;
   EEPROM.write(add1,UMID);

  lcd.setCursor(0, 0);
  lcd.print("Circuito Gestor");
  lcd.setCursor(4, 1);
  lcd.print("Solo Umido");
  Serial.print(" Solo Umido  ");
  digitalWrite(vermelho,HIGH);
  digitalWrite(laranja,HIGH);
  digitalWrite(verde,HIGH);
  digitalWrite(azul,HIGH);
  
  }
  if(valor_analogico > 450 && valor_analogico <600)
{ lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Circuito Gestor");
  lcd.setCursor(1, 1);
  lcd.print("Umidade Media");
  Serial.print("Umidade Média");
  digitalWrite(vermelho,HIGH);
  digitalWrite(laranja,HIGH);
  digitalWrite(verde,HIGH);
  digitalWrite(azul,LOW);
  }
  if(valor_analogico > 650 && valor_analogico <800)
{ 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Circuito Gestor");
  lcd.setCursor(4, 1);
  lcd.print("Solo Seco");
  Serial.print("  Solo Seco ");
  digitalWrite(vermelho,HIGH);
  digitalWrite(laranja,HIGH);
  digitalWrite(verde,LOW);
  digitalWrite(azul,LOW);
 
  
  }



  
   if(valor_analogico > 700 && valor_analogico <1023)
{ 
   add= 10 ;
   SEC =1;
   EEPROM.write(add,SEC);
   add1= 15 ;
   UMID = 0;
   EEPROM.write(add1,UMID);


  lcd.setCursor(0, 0);
  lcd.print("Circuito Gestor");
  lcd.setCursor(4, 1);
  lcd.print("Solo Seco ");
  Serial.print("  Solo Seco ");
  digitalWrite(vermelho,HIGH);
  digitalWrite(laranja,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(azul,LOW);
  
  }



/*
 * Essa parte do código não será utilizado neste programa  , 
 * ele possui fins didáticos para usas os casos possíveis 
 * para a execução do programa em determinada situação switch “CASO”

 

  if (Serial.available()) // Esse
 {

  char val = Serial.read();
  switch(val)
 {
  case 'a':
 {

 {

  digitalWrite(vermelho,HIGH);
  digitalWrite(laranja,LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul,LOW);
  delay(2000);
 }
  break;
 }
  case '1':
 {
  digitalWrite(vermelho,LOW);
  digitalWrite(laranja,HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(azul,LOW);
  delay(2000);
  break;
 }
  case 'd':
 {
  digitalWrite(vermelho,LOW);
  digitalWrite(laranja,LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(azul,LOW);
  delay(2000);
  break;
 }
  case 'f':
 {

 {
  digitalWrite(vermelho,LOW);
  digitalWrite(laranja,LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul,HIGH);
  delay(2000);
  break;
 }
  case 'x':
 {

 {

  digitalWrite(vermelho,LOW);
  digitalWrite(laranja,LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);
  delay(500);
  digitalWrite(vermelho,HIGH);
  digitalWrite(laranja,HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(azul,HIGH);
  delay(500);
  digitalWrite(vermelho,LOW);
  digitalWrite(laranja,LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);
  delay(500);
  digitalWrite(vermelho,HIGH);
  digitalWrite(laranja,HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(azul,HIGH);
  delay(500);
 }
  break;
 }

 }
 }
 }
 */
 
}
void ativar_boma()
 {  
  
  if(SEC == 1 && UMID == 0 ) 
  {
  digitalWrite(bomba,HIGH);
  
  }

if(UMID == 1 && SEC == 0 ) 
  {
  
  digitalWrite(bomba,LOW);
  }

 }

