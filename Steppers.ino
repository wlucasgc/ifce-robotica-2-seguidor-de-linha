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

byte direcao_indice() {
    if(direcao == "frente") {
        return(3);
    }

    else if(direcao == "direita") {
        return(2);
    }

    else if(direcao == "esquerda") {
        return(1);
    }
    
    else {
        return(0);
    }
}

//=============================================================================================================================================
//PARAR
//=============================================================================================================================================

void steppers_parar() {
    stepper_direita.disableMotor();
    stepper_esquerda.disableMotor();
}

//=============================================================================================================================================
//MOVER PARA FRENTE
//=============================================================================================================================================

void steppers_frente() {
    stepper_direita.moveRelativeInSteps(-STEPPER_PASSOS_POR_VEZ);
    stepper_esquerda.moveRelativeInSteps(-STEPPER_PASSOS_POR_VEZ);
}

//=============================================================================================================================================
//MOVER PARA TRAS
//=============================================================================================================================================

void steppers_tras() {
    stepper_direita.moveRelativeInSteps(STEPPER_PASSOS_POR_VEZ);
    stepper_esquerda.moveRelativeInSteps(STEPPER_PASSOS_POR_VEZ);
}

//=============================================================================================================================================
//MOVER PARA DIREITA
//=============================================================================================================================================

void steppers_direita() {
    stepper_direita.disableMotor();
    stepper_esquerda.moveRelativeInSteps(-STEPPER_PASSOS_POR_VEZ);
}

//=============================================================================================================================================
//MOVER PARA TRAS
//=============================================================================================================================================

void steppers_esquerda() {
    stepper_direita.moveRelativeInSteps(-STEPPER_PASSOS_POR_VEZ);
    stepper_esquerda.disableMotor();
}

//=============================================================================================================================================