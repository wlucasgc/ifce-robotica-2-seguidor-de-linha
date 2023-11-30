//=============================================================================================================================================
//SETUP
//=============================================================================================================================================

void setup() {
    Serial.begin(115200);

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
    modo = digitalRead(PINO_MODO);               //Identifica o modo de funcionamento
    
    oled_setup();    
    sensores_reflexivos_setup();                 //Configura os Sensores Reflexivos
    motores_stepper_setup();                     //Configura os Motores Stepper

    if(erro) {
        Serial.println(F("Ocorreu um erro durante a inicialização! Reiniciando..."));
        Serial.println(F("*********************************************************"));

        delay(1000);
        ESP.restart();
    }      
    
    Serial.println(F("*********************************************************"));
    
    oled_setup_intro();

    //Modo Rede Neural
    if(modo) {
        modo_rede_neural_setup();                //Realiza o treino da Rede Neural    
        digitalWrite(LED_BUILTIN, HIGH);         //Ao finalizar, liga o LED
    }

    //Modo Normal
    else {
        digitalWrite(LED_BUILTIN, HIGH);         //Liga o LED
    }
}

//=============================================================================================================================================