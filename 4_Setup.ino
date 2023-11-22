//=============================================================================================================================================
//SETUP
//=============================================================================================================================================

void setup() {
    Serial.begin(9600);

    Serial.println();
    Serial.println(F("*********************************************************"));
    Serial.println(F("IFCE Campus Limoeiro do Norte"));
    Serial.println(F("Tecnologia em Mecatrônica Industrial"));
    Serial.println(F("Robótica II (S6) - 2023.2"));
    Serial.println(F("Robô seguidor de linha"));
    Serial.println(F("Equipe: Newton Rogério de Freitas Raulino"));
    Serial.println(F("        Weber Lucas Guimarães Chaves"));
    Serial.println(F("*********************************************************"));
    
    pinMode(LED_BUILTIN, OUTPUT);                //Configura o pino do LED
    digitalWrite(LED_BUILTIN, LOW);              //Inicia o LED desligado
    pinMode(PINO_MODO, INPUT_PULLUP);            //Configura o pino identificador do modo de funcionamento
    
    sensores_reflexivos_setup();                 //Configura os Sensores Reflexivos
    motores_stepper_setup();                     //Configura os Motores Stepper
      
    modo = digitalRead(PINO_MODO);               //Identifica o modo de funcionamento
    
    //Modo Rede Neural
    if(modo) {
        modo_rede_neural_setup();                //Realiza o treino da Rede Neural    
        digitalWrite(LED_BUILTIN, HIGH);         //Ao finalizar, liga o LED
    }

    //Modo Normal
    else {
        delay(1000);                             //Aguarda 1 segundo
        digitalWrite(LED_BUILTIN, HIGH);         //Liga o LED
        delay(2000);                             //Aguarda 2 segundos
    }
}

//=============================================================================================================================================