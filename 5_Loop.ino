//=============================================================================================================================================
//LOOP
//=============================================================================================================================================

void loop() {     
    sensores_reflexivos_loop();                  //Lê os Sensores Reflexivos
    
    //Modo Rede Neural
    if(modo) {
        modo_rede_neural_loop();                 //Executa a rotina do Modo Normal
    }
    
    //Modo Normal
    else {
        modo_normal_loop();                      //Executa a rotina do Modo Rede Neural
    }
    
    motores_stepper_loop();                      //Faz os Motores Stepper executarem o movimento
}

//=============================================================================================================================================