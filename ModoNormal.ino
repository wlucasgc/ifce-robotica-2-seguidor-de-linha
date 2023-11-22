//=============================================================================================================================================
//MODO NORMAL
//=============================================================================================================================================

void modo_normal_loop() {
    if(modo_normal_timer.repeat()) {
        if(sensor_direita_estado && sensor_esquerda_estado){
            Serial.println(F("Frente!"));
            direcao = "frente";
        }

        else if(sensor_direita_estado && !sensor_esquerda_estado){
            Serial.println(F("Esquerda!"));
            direcao = "esquerda";
        }

        else if(!sensor_direita_estado && sensor_esquerda_estado){
            Serial.println(F("Direita!"));
            direcao = "direita";
        }

        else {
            Serial.println(F("Parar!"));
            direcao = "parar";
        }

        //Serial.println(F("*********************************************************"));
    }
}

//=============================================================================================================================================