//=============================================================================================================================================
//VARIÁVEIS GLOBAIS
//=============================================================================================================================================

bool modo;                                       //Modo de funcionamento (true: Modo Rede Neural | false: Modo Normal)
bool erro = false;
bool sensor_direita_estado;                      //Variável que armazena o estado do sensor da direita
bool sensor_esquerda_estado;                     //Variável que armazena o estado do sensor da esquerda
bool neuronios_ativos[NEORONIOS_CAMADA_SAIDA][NEORONIOS_CAMADA_ESCONDIDA_1 + NEORONIOS_CAMADA_ESCONDIDA_2];

unsigned int epoch = 0;
unsigned long tempo_treino = 0; 

float mse = 0;

String direcao = "parar";
String direcao_anterior = "";

//=============================================================================================================================================