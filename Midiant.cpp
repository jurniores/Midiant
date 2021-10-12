#include <Midiant.h>
#include <Arduino.h>



Midiant::Midiant(int btn){
    this->btn = btn;
    this->ativa = false;
    this->desativa = false;
    this->ativa = false;
    this->aNot = false;
    this->dNot = false;
    this->pot = 0;
    pinMode(btn,INPUT_PULLUP);
};

Midiant::Midiant(int btn, int pot){
    this->btn = btn;
    this->pot = pot;
    this->ativa = false;
    this->desativa = false;
    this->aNot = false;
    this->dNot = false;
    this->validaPot = 0;
    this->valCompare =20;
    pinMode(btn,INPUT_PULLUP);
    pinMode(pot,INPUT);

};
void Midiant::Btn(clickParam* cb){

       
    if(digitalRead(btn)){
     desativa= true;
     aNot = true;
     dNot = false;
     
    }else{
    
    ativa = true;
    dNot = true;
    desativa = false;
    
  }

  if(ativa and desativa){
    ativa = false;
    desativa = false;
    cb(1);
  }
  
  if(dNot and aNot){
    aNot = false;
    dNot = false;
    cb(2);
  }

  
       
    
}

void Midiant::Pot(clickParam* cb){

  
    if(this->pot ==0) return;
  
  
    if(analogRead(this->pot)>(validaPot+valCompare) or analogRead(this->pot)<(validaPot-valCompare)){
      validaPot = analogRead(this->pot);
      
      int midiVal = map(analogRead(this->pot),5,1019,0,127)<3?0:map(analogRead(this->pot),0,1019,0,127);
      
      cb(midiVal);
      return;
    }
  
    
}

void Midiant::BtnCB(click* cb){
   if(digitalRead(btn)){
     desativa= true;
    }else{
    
    ativa = true;
    desativa = false;
    
  }

  if(ativa and desativa){
    ativa = false;
    desativa = false;
    cb();
    delay(70);
    
  }
  
  

}


