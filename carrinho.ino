
#include "Ultrasonic.h"

#define echoPin 13 
#define trigPin 12 
#define motorA1 3   
#define motorA2 5    
#define motorB1 6    
#define motorB2 9    
#define opticPin 11 

int valor = 0; 

Ultrasonic ultrasonic(12, 13);

int distancia = 0;
int velA = 55; 
int velB = 60; 

void setup()   {
  Serial.begin(9600);
  pinMode (echoPin , INPUT ) ;
  pinMode (trigPin , OUTPUT ) ;
  pinMode (motorA1, OUTPUT) ;
  pinMode (motorA2, OUTPUT) ;
  pinMode (motorB1, OUTPUT) ;
  pinMode (motorB2, OUTPUT) ;
  pinMode (opticPin, INPUT) ;

}
void loop()  {
  valor = digitalRead(opticPin);
  while(valor == HIGH) {
     	distancia = ultrasonico();
        if (distancia <= 20){
                drive_stop();
                delay(1000);
         	Distance(velA);
        	valor = digitalRead(opticPin);
         	while(valor==HIGH){
         		drive_frente(velA);
         		delay(100);
         		valor = digitalRead(opticPin);
       		} 
                while (valor==LOW){
                   drive_frente(velA);
       	           delay(100);
       		   valor = digitalRead(opticPin);
  	       }
              drive_esquerda(velA);
              delay(100);
  	}
  
        else {
            drive_esquerda(velA);
            delay(100);
        }
        
    valor = digitalRead(opticPin);
  } 

  while(valor == LOW){
        distancia = ultrasonico();
        if (distancia <= 20){
                drive_stop();
                delay(1000);
         	Distance(velA);
        	valor = digitalRead(opticPin);
         	while(valor == HIGH){
         		drive_frente(velA);
         		delay(100);
         		valor = digitalRead(opticPin);
       		}
               while (valor==LOW){
                   drive_frente(velA);
       	         delay(100);
       		 valor = digitalRead(opticPin);
  	       }
            drive_esquerda(velA);
            delay(100);
        }
        else {
            drive_esquerda(velA);
            delay(100);
        }    
    
    	valor = digitalRead(opticPin);//realizando a leitura no sensor optico
  }
  
  while(valor == HIGH ){
        distancia = ultrasonico();
        if (distancia <= 20){
                drive_stop();
                delay(1000);
         	Distance(velA);
        	valor = digitalRead(opticPin);
         	while(valor==HIGH){
         		drive_frente(velA);
         		delay(100);
         		valor = digitalRead(opticPin);
       		} 
               while (valor==LOW){
                   drive_frente(velA);
       	           delay(100);
       		   valor = digitalRead(opticPin);
  	      }
              drive_esquerda(velA);
              delay(100);
  	}
  
        else {
            drive_direita(velB);
            delay(100);
        }
        
    	valor = digitalRead(opticPin);
  }
   while(valor == LOW ){
       distancia = ultrasonico();
        if (distancia <= 20){
                drive_stop();
                delay(1000);
         	Distance(velA);
        	valor = digitalRead(opticPin);
         	while(valor==HIGH){
         		drive_frente(velA);
         		delay(100);
         		valor = digitalRead(opticPin);
       		}
                while (valor==LOW){
                   drive_frente(velA);
       	           delay(100);
       		   valor = digitalRead(opticPin);
  	       }
              drive_esquerda(velA);
              delay(100);
  	}
  
        else {
            drive_direita(velB);
            delay(100);
        }
     
     
    	valor = digitalRead(opticPin);
  } 
  
}
void Distance(int vel){
    drive_esquerda(vel);
    delay(800);
    drive_direita(vel);
    delay(500);
    drive_frente(vel);
    delay(850);
    drive_direita(vel);
    delay(700);
}

void drive_esquerda(int vel) {          
  analogWrite(motorA1, vel);    
  analogWrite(motorA2, LOW);    
  analogWrite(motorB1, LOW);    
  analogWrite(motorB2, LOW);     

}

void drive_direita(int vel) {           
  analogWrite(motorA1, LOW);     
  analogWrite(motorA2, LOW);     
  analogWrite(motorB1, LOW);      
  analogWrite(motorB2, vel);     
}

void drive_stop() {               
  analogWrite(motorA1, LOW);     
  analogWrite(motorA2, LOW);    
  analogWrite(motorB1, LOW);     
  analogWrite(motorB2, LOW);     
}

void drive_re() {                 
   analogWrite(motorA1, LOW);
   analogWrite(motorA2, velA);
   analogWrite(motorB1, velA);
   analogWrite(motorB2, LOW); 
}

void drive_frente(int vel) {             
   analogWrite(motorA1, vel);
   analogWrite(motorA2, LOW);
   analogWrite(motorB1, LOW);
   analogWrite(motorB2, vel); 
}

int ultrasonico(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int distancia = (ultrasonic.Ranging(CM));
  return(distancia);
}


