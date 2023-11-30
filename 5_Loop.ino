//=============================================================================================================================================
//LOOP
//=============================================================================================================================================

void loop() {     
    sensores_reflexivos_loop();                  //Lê os Sensores Reflexivos
    
    //Modo Rede Neural
    if(modo) {
        modo_rede_neural_loop();                 //Executa a rotina do Modo Normal
        oled_loop_rede_neural();
    }
    
    //Modo Normal
    else {
        modo_normal_loop();                      //Executa a rotina do Modo Rede Neural
        oled_loop_normal(); 
    }
    
    motores_stepper_loop();                      //Faz os Motores Stepper executarem o movimento
}

//=============================================================================================================================================