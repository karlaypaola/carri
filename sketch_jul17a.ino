#include <MotorDriver.h>
#include <SoftwareSerial.h>

SoftwareSerial blue(2, 3); // RX, TX
MotorDriver m;
char letra=0;
char letra2=0;
char letra3=0;
String msj="";
String num="";
int num2=0;
int tam=0;
int bandera=0;
int i;
int caso=0;



void setup() {
Serial.begin(9600);
blue.begin(9600);
}

void loop() {
if(Serial.available()){
  msj="";
  do{
    letra=Serial.read();
    if (letra=='\n'){
      break;}
  else{
   msj=msj+letra;
  }
}while(Serial.available()>0);

 tam=msj.length();
 Serial.println(msj);
 bandera=1;
 } 
  
  if (blue.available()) {
    
while(blue.available()>0){
letra=blue.read();
if(letra=='\n'){
break; }

 else{
   msj=msj+letra;
  }
} 

 tam=msj.length();
    Serial.println(msj);
    bandera=1;
  }

 if(bandera==1){
 for (i=0; i<tam; i++){
  letra2=msj[i];

 if (letra2=='0' ||letra2=='1'||letra2=='2'||letra2=='3'||letra2=='4'||letra2=='5'||letra2=='6'||letra2=='7'||letra2=='8'||letra2=='9'){
  num=num+letra2;
  letra2=0;
 }
 
 if(letra2=='D' ||letra2=='I'  ||letra2=='F' ||letra2=='A' ||letra2=='P'){
    letra3=letra2;
    letra2=0;
 }   
 
  if(letra2=='.'){
   num2 = num.toInt();
  Serial.println(num2);
  
  switch (letra3){
    Serial.print ("switch");

     
     case 'D': //derecha
  if(num2==0){
  m.motor(1,FORWARD,0);
  m.motor(2,FORWARD,200);
  m.motor(3,FORWARD,200);
  m.motor(4,FORWARD,0);

  }
  if(num2>0){
    for( int i=0; num2>i; i++){
  m.motor(1,FORWARD,0);
  m.motor(2,FORWARD,200);
  m.motor(3,FORWARD,200);
  m.motor(4,FORWARD,0);
  delay(750);
  }
  m.motor(1,FORWARD,0);
  m.motor(2,FORWARD,0);
  m.motor(3,FORWARD,0);
  m.motor(4,FORWARD,0);
  }
  
  letra2=0;
  letra3=0;
  num2=0;
  num="";
  break;
  
   case 'I': //Izquierda
  if(num2==0){
  m.motor(1,FORWARD,200);
  m.motor(2,FORWARD,0);
  m.motor(3,FORWARD,0);
  m.motor(4,FORWARD,200);
  }
  if(num2>0){
    for( int i=0; num2>i; i++){
  m.motor(1,FORWARD,200);
  m.motor(2,FORWARD,0);
  m.motor(3,FORWARD,0);
  m.motor(4,FORWARD,200);
  delay(655);
  }
  m.motor(1,FORWARD,0);
  m.motor(2,FORWARD,0);
  m.motor(3,FORWARD,0);
  m.motor(4,FORWARD,0);
  }
  
  letra2=0;
  letra3=0;
  num2=0;
  num="";
  break;
  
   case 'F': //Enfrete
  if(num2==0){
  m.motor(1,FORWARD,200);
  m.motor(2,FORWARD,250);
  m.motor(3,FORWARD,250);
  m.motor(4,FORWARD,200);
 }
 
  if(num2>0){
    for( int i=0; num2>i; i++){
  m.motor(1,FORWARD,200);
  m.motor(2,FORWARD,250);
  m.motor(3,FORWARD,250);
  m.motor(4,FORWARD,200);
  delay(800);
  
  }
  m.motor(1,FORWARD,0);
  m.motor(2,FORWARD,0);
  m.motor(3,FORWARD,0);
  m.motor(4,FORWARD,0);
  }
  
  letra2=0;
  letra3=0;
  num2=0;
  num="";
  break;
  
  
   case 'A': //reversa
  if(num2==0){
  m.motor(1,BACKWARD,180);
  m.motor(2,BACKWARD,245);
  m.motor(3,BACKWARD,245);
  m.motor(4,BACKWARD,180);
  }
  if(num2>0){{
    for( int i=0; num2>i; i++){
  m.motor(1,BACKWARD,180);
  m.motor(2,BACKWARD,245);
  m.motor(3,BACKWARD,245);
  m.motor(4,BACKWARD,180);
  delay(700);
  }
  m.motor(1,FORWARD,0);
  m.motor(2,FORWARD,0);
  m.motor(3,FORWARD,0);
  m.motor(4,FORWARD,0);
  }
  letra2=0;
  letra3=0;
  num2=0;
  num="";
  break;
  

  
   case 'P': //Parar
 if(num2==0){
  m.motor(1,FORWARD,0);
  m.motor(2,FORWARD,0);
  m.motor(3,FORWARD,0);
  m.motor(4,FORWARD,0);
  }
   if(num2>0){
  for( int i=0; num2>i; i++){
  m.motor(1,FORWARD,0);
  m.motor(2,FORWARD,0);
  m.motor(3,FORWARD,0);
  m.motor(4,FORWARD,0);
  delay(550);
  }}
  letra2=0;
  letra3=0;
  num2=0;
  num="";
  break;
  

  default:
  break;
  }
  }
  }
  }
  bandera=0;
  msj="";
  }
  }
  
