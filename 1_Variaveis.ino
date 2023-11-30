//=============================================================================================================================================
//VARIÁVEIS GLOBAIS
//=============================================================================================================================================

bool modo = false;                               //Modo de funcionamento (true: Modo Rede Neural | false: Modo Normal)
bool erro = false;                               //Indica se ocorreu um erro durante a inicialização
bool sensor_direita_estado;                      //Estado do sensor da direita
bool sensor_esquerda_estado;                     //Estado do sensor da esquerda

bool neuronios_ativos[NEORONIOS_CAMADA_SAIDA][NEORONIOS_CAMADA_ESCONDIDA_1 + NEORONIOS_CAMADA_ESCONDIDA_2];

unsigned int epoch = 0;                          //Contador de épocas do treinamento da Rede Neural
unsigned long tempo_treino = 0;                  //Tempo de treinamento da Rede Neural em milissegundos

float mse = 0;                                   //Erro Médio Quadrático da Rede Neural

String direcao = "parar";                        //Direção atual
String direcao_anterior = "";                    //Direção anterior

//=============================================================================================================================================