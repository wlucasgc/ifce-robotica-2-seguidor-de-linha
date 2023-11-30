//=============================================================================================================================================
//SENSORES REFLEXIVOS IR
//=============================================================================================================================================

//=============================================================================================================================================
//SETUP
//=============================================================================================================================================

void sensores_reflexivos_setup() {
    pinMode(SENSOR_DIREITA, INPUT);                                       //Configura o pino do Sensor Reflexivo IR da direita
    Serial.println(F("> Sensor Reflexivo (Direita)                           OK"));
    
    pinMode(SENSOR_ESQUERDA, INPUT);                                      //Configura o pino do Sensor Reflexivo IR da esquerda
    Serial.println(F("> Sensor Reflexivo (Esquerda)                          OK"));   
}

//=============================================================================================================================================
//LOOP
//=============================================================================================================================================

void sensores_reflexivos_loop() {
    if(sensor_reflexivo_timer.repeat()) {                                 //Verifica se é o momento de executar a rotina...
        sensor_direita_estado = !digitalRead(SENSOR_DIREITA);             //Faz a leitura do Sensor Reflexivo IR da direita
        sensor_esquerda_estado = !digitalRead(SENSOR_ESQUERDA);           //Faz a leitura do Sensor Reflexivo IR da esquerda
    }
}

//=============================================================================================================================================