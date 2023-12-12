//=============================================================================================================================================
//MOTORES STEPPER
//=============================================================================================================================================

//=============================================================================================================================================
//SETUP
//=============================================================================================================================================

void motores_stepper_setup() {
    stepper_direita.connectToPins(
        STEPPER_DIREITA_IN1,
        STEPPER_DIREITA_IN2,
        STEPPER_DIREITA_IN3,
        STEPPER_DIREITA_IN4
    );

    stepper_direita.setSpeedInStepsPerSecond(STEPPER_VELOCIDADE);
    stepper_direita.setAccelerationInStepsPerSecondPerSecond(STEPPER_ACELERACAO);
    Serial.println(F("> Motor de passo (Direita)                             OK"));

    stepper_esquerda.connectToPins(
        STEPPER_ESQUERDA_IN1,
        STEPPER_ESQUERDA_IN2,
        STEPPER_ESQUERDA_IN3,
        STEPPER_ESQUERDA_IN4
    );
    
    stepper_esquerda.setSpeedInStepsPerSecond(STEPPER_VELOCIDADE);
    stepper_esquerda.setAccelerationInStepsPerSecondPerSecond(STEPPER_ACELERACAO);
    Serial.println(F("> Motor de passo (Esquerda)                            OK"));
}

//=============================================================================================================================================
//LOOP
//=============================================================================================================================================

void motores_stepper_loop() {
    //Verifica a direção do movimento e faz os Motores Stepper se moverem (ou não) na direção desejada
    if(direcao == "frente") { 
        steppers_frente();
    }

    else if(direcao == "esquerda"){
        steppers_esquerda();
    }

    else if(direcao == "direita"){
        steppers_direita();
    }

    else {
        steppers_parar();
    }
}

//=============================================================================================================================================
//RETORNA A DIREÇÃO COMO UM VALOR NUMÉRICO
//=============================================================================================================================================

byte direcao_indice(String direcao) {
    String direcoes[] = {"parar", "esquerda", "direita", "frente"};       //Cria um vetor com as direções possíveis
    
    for(int i = 0 ; i < 4 ; i++) {                                        //Percorre todo o vetor em busca da direção desejada
        if(direcao == direcoes[i]) {                                      //Se encontrar a direção...
            return(i);                                                    //Retorna o índice da direção no vetor
        }
    }
}

//=============================================================================================================================================
//PARAR
//=============================================================================================================================================

void steppers_parar() {
    stepper_direita.disableMotor();                                       //Desliga o Motor Stepper da direita (economiza energia)
    stepper_esquerda.disableMotor();                                      //Desliga o Motor Stepper da esquerda (economiza energia)
}

//=============================================================================================================================================
//MOVER PARA FRENTE
//=============================================================================================================================================

void steppers_frente() {
    stepper_direita.moveRelativeInSteps(-STEPPER_PASSOS_POR_VEZ);         //Executa a quantidade de passos desejada no Motor Stepper da direita 
    stepper_esquerda.moveRelativeInSteps(-STEPPER_PASSOS_POR_VEZ);        //Executa a quantidade de passos desejada no Motor Stepper da esquerda
}

//=============================================================================================================================================
//MOVER PARA TRAS
//=============================================================================================================================================

void steppers_tras() {
    stepper_direita.moveRelativeInSteps(STEPPER_PASSOS_POR_VEZ);          //Executa a quantidade de passos desejada no Motor Stepper da direita
    stepper_esquerda.moveRelativeInSteps(STEPPER_PASSOS_POR_VEZ);         //Executa a quantidade de passos desejada no Motor Stepper da esquerda
}

//=============================================================================================================================================
//MOVER PARA DIREITA
//=============================================================================================================================================

void steppers_direita() {
    //stepper_direita.disableMotor();                                       //Desliga o Motor Stepper da direita (economiza energia)
    stepper_direita.moveRelativeInSteps(STEPPER_PASSOS_POR_VEZ);          //Executa a quantidade de passos desejada no Motor Stepper da direita
    stepper_esquerda.moveRelativeInSteps(-STEPPER_PASSOS_POR_VEZ);        //Executa a quantidade de passos desejada no Motor Stepper da esquerda
}

//=============================================================================================================================================
//MOVER PARA TRAS
//=============================================================================================================================================

void steppers_esquerda() {
    stepper_direita.moveRelativeInSteps(-STEPPER_PASSOS_POR_VEZ);         //Executa a quantidade de passos desejada no Motor Stepper da direita
    //stepper_esquerda.disableMotor();                                      //Desliga o Motor Stepper da esquerda (economiza energia)
    stepper_esquerda.moveRelativeInSteps(STEPPER_PASSOS_POR_VEZ);         //Executa a quantidade de passos desejada no Motor Stepper da esquerda
}

//=============================================================================================================================================