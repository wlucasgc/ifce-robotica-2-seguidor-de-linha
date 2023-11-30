//=============================================================================================================================================
//MODO NORMAL
//=============================================================================================================================================

void modo_normal_loop() {
    if(modo_normal_timer.repeat()) {                                      //Verifica se é o momento de executar a rotina...
        if(!sensor_direita_estado && !sensor_esquerda_estado) {           //Se ambos os sensores estiverem detectando a linha...
            direcao = "frente";                                           //Deve se mover para frente
        }

        else if(sensor_direita_estado && !sensor_esquerda_estado) {       //Se o sensor da direita estiver fora da linha...
            direcao = "esquerda";                                         //Deve se mover para a esquerda
        }

        else if(!sensor_direita_estado && sensor_esquerda_estado) {       //Se o sensor da esquerda estiver fora da linha...
            direcao = "direita";                                          //Deve se mover para a direita
        }

        else {                                                            //Se nenhum dos sensores estiverem detectando a linha...
            direcao = "parar";                                            //Deve ficar parado
        }
    }
}

//=============================================================================================================================================