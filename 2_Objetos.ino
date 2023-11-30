//=============================================================================================================================================
//OBJETOS
//=============================================================================================================================================

//Display OLES 128x64
Adafruit_SSD1306 oled(OLED_LARGURA, OLED_ALTURA, &Wire, OLED_RESET);           //Objeto para controle do Display OLED 128x64
Newneotimer oled_timer(100);                                                   //Objeto que faz a temporização do Display OLED 128x64

//Sensor Reflexivo IR
Newneotimer sensor_reflexivo_timer(10);                                        //Objeto que faz a temporização do Sensor Reflexivo IR

//Stepper Direita
TinyStepper_28BYJ_48 stepper_direita;                                          //Objeto para controle do Motor Stepper da direita
TinyStepper_28BYJ_48 stepper_esquerda;                                         //Objeto para controle do Motor Stepper da esquerda

//Rede Neural
NeuralNetwork rede_neural(CAMADAS, NUMERO_DE_CAMADAS, FUNCOES_DE_ATIVACAO);    //Objeto para a utilização da Rede Neural

//Modo Normal
Newneotimer modo_normal_timer(100);                                            //Objeto que faz a temporização do loop do Modo Normal

//=============================================================================================================================================