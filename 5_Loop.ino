//=============================================================================================================================================
//LOOP
//=============================================================================================================================================

void loop() {     
    sensores_reflexivos_loop();                  //Lê os Sensores Reflexivos
    
    //Modo Rede Neural
    if(modo) {
        modo_rede_neural_loop();                 //Executa a rotina do Modo Rede Neural
        oled_loop_rede_neural();                 //Executa a rotina do Display OLED 128x64 para o Modo Rede Neural
    }
    
    //Modo Normal
    else {
        modo_normal_loop();                      //Executa a rotina do Modo Normal
        oled_loop_normal();                      //Executa a rotina do Display OLED 128x64 para o Modo Normal
    }
    
    motores_stepper_loop();                      //Faz os Motores Stepper executarem o movimento
}

//=============================================================================================================================================