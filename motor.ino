#define ML1 5
#define ML2 4
#define MR1 7
#define MR2 6

#include <SoftwareSerial.h>
SoftwareSerial BT(10,11); //RX.TX

void setup()
{
    pinMode(ML1,OUTPUT);
    pinMode(ML2,OUTPUT);
    pinMode(MR1,OUTPUT);
    pinMode(MR2,OUTPUT);
    Serial.begin(9600);
    BT.begin(38400);

}


void loop()
{
    if(BT.available()>0){
        char cmd = BT.read();
        Serial.println(cmd);
        if(cmd == '8'){
            Serial.println("Front");
            m_Go();
        }
        else if(cmd == '2'){
            Serial.println("Back");
            m_Back();
        }
        else if(cmd == '5'){
            Serial.println("Stop");
            m_Stop();
        }
        else if(cmd == '4'){
            Serial.println("Turn Left");
            m_Left();
        }
        else if(cmd == '6'){
            Serial.println("Turn Right");
            m_Right();
        }
        else if(cmd == '7'){
            Serial.println("LF");
            m_LeftGo();
        }
        else if(cmd == '9'){
            Serial.println("RF");
            m_RightGo();
        }
        else if(cmd == '1'){
            Serial.println("LB");
            m_LeftBack();
        }
        else if(cmd == '3'){
            Serial.println("RB");
            m_RightBack();
        }
    }

    if (Serial.available() > 0){
        char m_cmd = Serial.read();
        if(m_cmd == '8'){
            Serial.println("Front");
            m_Go();
        }
        else if(m_cmd == '2'){
            Serial.println("Back");
            m_Back();
        }
        else if(m_cmd == '5'){
            Serial.println("Stop");
            m_Stop();
        }
        else if(m_cmd == '4'){
            Serial.println("Turn Left");
            m_Left();
        }
        else if(m_cmd == '6'){
            Serial.println("Turn Right");
            m_Right();
        }
        
    }

    
    }
    



void ML1_Go(){
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, HIGH);
    
}

void ML1_Stop(){
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, LOW);
    
}

void ML1_Back(){
    digitalWrite(ML1, HIGH);
    digitalWrite(ML2, LOW);
    
}


void MR1_Go(){
    digitalWrite(MR1, LOW);
    digitalWrite(MR2, HIGH);
    
}


void MR1_Stop(){
    digitalWrite(MR1, LOW);
    digitalWrite(MR2, LOW);
    
}

void MR1_Back(){
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);
    
}

void m_Go(){
    ML1_Go();
    MR1_Go();
}

void m_Stop(){
    ML1_Stop();
    MR1_Stop();
}

void m_Back(){
    ML1_Back();
    MR1_Back();
}

void m_Left(){
    ML1_Back();
    MR1_Go();
}

void m_Right(){
    ML1_Go();
    MR1_Back();
}

void m_LeftGo(){
    ML1_Stop();
    MR1_Go();
}
void m_RightGo(){
    ML1_Go();
    MR1_Stop();
}
void m_LeftBack(){
    ML1_Stop();
    MR1_Back();
}
void m_RightBack(){
    ML1_Back();
    MR1_Stop();
}