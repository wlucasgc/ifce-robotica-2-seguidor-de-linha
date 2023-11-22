//=============================================================================================================================================
//OBJETOS
//=============================================================================================================================================

//Sensor Reflexivo IR
Newneotimer sensor_reflexivo_timer(10);

//Stepper Direita
TinyStepper_28BYJ_48 stepper_direita;
TinyStepper_28BYJ_48 stepper_esquerda;

//Modo Normal
Newneotimer modo_normal_timer(100);

//Rede Neural
NeuralNetwork rede_neural(
    CAMADAS,
    NUMERO_DE_CAMADAS,
    FUNCOES_DE_ATIVACAO
);

//=============================================================================================================================================