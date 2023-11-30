//=============================================================================================================================================
//ROBÔ SEGUIDOR DE LINHA COM REDES NEURAIS
//=============================================================================================================================================

//IFCE Campus Limoeiro do Norte
//Tecnologia em Mecatrônica Industrial
//Robótica II (S6) - 2023.2
//Robô seguidor de linha
//Equipe: Newton Rogério de Freitas Raulino
//        Weber Lucas Guimarães Chaves

//=============================================================================================================================================
//BIBLIOTECAS
//=============================================================================================================================================

#define ACTIVATION__PER_LAYER                    //Habilita a Rede Neural a utilizar diferentes Funções de Ativação por cadada
#define Sigmoid                                  //Habilita a Função de Ativação Sigmoid (0)
#define Tanh                                     //Habilita a Função de Ativação Tangente Hiperbólica (1)
#define ReLU                                     //Habilita a Função de Ativação ReLU (2)

#include <NeuralNetwork.h>                       //Biblioteca para Redes Neurais
#include <Adafruit_SSD1306.h>
#include <TinyStepper_28BYJ_48.h>                //Biblioteca para os Motores Stepper
#include <Newneotimer.h>                         //Biblioteca para temporização de processos     

//=============================================================================================================================================
//DEFINIÇÕES DE PINOS
//=============================================================================================================================================

//LED da placa
const byte LED_BUILTIN = 2;

//Modo de execução
const byte PINO_MODO = 23;

//Stepper Direita
const byte STEPPER_DIREITA_IN1 = 4;
const byte STEPPER_DIREITA_IN2 = 5;
const byte STEPPER_DIREITA_IN3 = 18;
const byte STEPPER_DIREITA_IN4 = 19;

//Stepper Esquerda
const byte STEPPER_ESQUERDA_IN1 = 13;
const byte STEPPER_ESQUERDA_IN2 = 12;
const byte STEPPER_ESQUERDA_IN3 = 14;
const byte STEPPER_ESQUERDA_IN4 = 27;

//Sensores reflexivos
const byte SENSOR_DIREITA = 26;
const byte SENSOR_ESQUERDA = 25;

//=============================================================================================================================================
//CONFIGURAÇÕES
//=============================================================================================================================================

//Modo debug
const bool DEBUG = false;

//Configurações do Display OLED 128x64
const int OLED_LARGURA = 128; // OLED display width, in pixels
const int OLED_ALTURA = 64; // OLED display height, in pixels
const int OLED_RESET = -1; // Reset pin # (or -1 if sharing Arduino reset pin)
const int OLED_ENDERECO = 0x3C; ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

//Configuração dos Steppers
const int STEPPER_PASSOS_POR_REVOLUCAO = 2048;
const int STEPPER_PASSOS_POR_VEZ = 5;
const int STEPPER_VELOCIDADE = 1000;
const int STEPPER_ACELERACAO = 10000;

//Configurações da Rede Neural
const byte NUMERO_DE_CAMADAS = 4;                //Número de camadas da Rede Neural

const byte NEORONIOS_CAMADA_ENTRADA = 2;         //Número de neurônios na camada de entrada da Rede Neural
const byte NEORONIOS_CAMADA_ESCONDIDA_1 = 3;     //Número de neurônios na primeira camada escondida da Rede Neural
const byte NEORONIOS_CAMADA_ESCONDIDA_2 = 3;     //Número de neurônios na segunda camada escondida da Rede Neural
const byte NEORONIOS_CAMADA_SAIDA = 4;           //Número de neurônios na camada de saída da Rede Neural

const unsigned int CAMADAS[] = {                 //Arquitetura da Rede Neural
    NEORONIOS_CAMADA_ENTRADA,
    NEORONIOS_CAMADA_ESCONDIDA_1,
    NEORONIOS_CAMADA_ESCONDIDA_2,
    NEORONIOS_CAMADA_SAIDA
};

byte FUNCOES_DE_ATIVACAO[] = {1, 0, 2};    //Funções de Ativação em cada camada (0: Sigmoid | 1: Tanh | 2: ReLU)

const unsigned int EPOCHS = 1000;

const float ERRO_MEDIO_QUADRATICO = 0.001;       //Valor de Erro Médio Quadrático (MSE) desejado

const byte QUANTIDADE_DE_DADOS = 4;              //Quantidade de dados para treino da Rede Neural

//=============================================================================================================================================