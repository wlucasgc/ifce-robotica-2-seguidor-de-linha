//=============================================================================================================================================
//MODO REDE NEURAL
//=============================================================================================================================================

//=============================================================================================================================================
//SETUP
//=============================================================================================================================================

void modo_rede_neural_setup() {
    unsigned long tempo_inicio = millis();
    
    //Dados de treinamento
    //Entrada: {SENSOR_DIREITA, SENSOR_ESQUERDA}
    const float entradas_treino[QUANTIDADE_DE_DADOS][NEORONIOS_CAMADA_ENTRADA] = {
        {1, 1},
        {1, 0},
        {0, 1},
        {0, 0}
    };

    //Saída: {PARAR, ESQUERDA, DIREITA, FRENTE}
    const float saidas_treino[QUANTIDADE_DE_DADOS][NEORONIOS_CAMADA_SAIDA] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    //Treinamento da Rede Neural
    Serial.println(F("Treinamento da Rede Neural"));
    Serial.println(F("*********************************************************"));

    do { 
        for (int j = 0 ; j < QUANTIDADE_DE_DADOS ; j++) {
            rede_neural.FeedForward(entradas_treino[j]);                                      //FeedForwards the input arrays through the NN | stores the output array internally
            rede_neural.BackProp(saidas_treino[j]);                                           //"Tells" to the NN if the output was the-expected-correct one | then, "teaches" it
        }
        
        epoch += 1;
        mse = rede_neural.MeanSqrdError;

        Serial.printf("EPOCH: %5d | ", epoch);                       //Prints the Error.
        Serial.printf("MSE: %10.6f\n", mse);                         //Prints the Error.
        
        tempo_treino = millis() - tempo_inicio;
        
        if(epoch % 10 == 0) {
            oled_setup_treinamento();
        }
        
        //Pisca o LED durante o treinamento
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

    } while(rede_neural.getMeanSqrdError(QUANTIDADE_DE_DADOS) > ERRO_MEDIO_QUADRATICO && epoch < EPOCHS);       //Loops through each epoch Until MSE goes < 0.003

    Serial.println(F("*********************************************************"));

    /*
    Serial.print(F("Pesos:"));
    rede_neural.print();                           // Prints the weights and biases of each layer
    
    Serial.println(F("*********************************************************"));
    */

    oled_setup_treinamento();

    //Calcula e imprime o tempo de duração do treinamento
    Serial.println("Duração do treinamento: " + String(tempo_treino / 1000.0, 2) + " segundos");
    delay(3000);
    
    Serial.println(F("*********************************************************"));
}

//=============================================================================================================================================
//LOOP
//=============================================================================================================================================

void modo_rede_neural_loop() {
    float soma = 0;
    float porcentagem = 0;
    float entradas[2];
    float* saidas;
    float pontos[] = {0.125, 0.375, 0.625, 0.875};
    unsigned long duracao = millis();

    entradas[0] = sensor_direita_estado;
    entradas[1] = sensor_esquerda_estado;
    
    saidas = rede_neural.FeedForward(entradas);

    for(int i = 0 ; i < NEORONIOS_CAMADA_SAIDA ; i++) {
        soma += saidas[i]; 
    }
    
    if((saidas[0] > saidas[1]) && (saidas[0] > saidas[2]) && (saidas[0] > saidas[3])) {
        //Serial.println(F("Parar!"));
        //steppers_parar();        
        direcao = "parar";
        porcentagem = (saidas[0] * 100) / soma;
    }

    else if((saidas[1] > saidas[0]) && (saidas[1] > saidas[2]) && (saidas[1] > saidas[3])) {
        //Serial.println(F("Esquerda!"));
        //steppers_esquerda();
        direcao = "esquerda";
        porcentagem = (saidas[1] * 100) / soma;
    }

    else if((saidas[2] > saidas[0]) && (saidas[2] > saidas[1]) && (saidas[2] > saidas[3])) {
        //Serial.println(F("Direita!"));
        //steppers_direita();
        direcao = "direita";
        porcentagem = (saidas[2] * 100) / soma;
    }
    
    else if((saidas[3] > saidas[0]) && (saidas[3] > saidas[1]) && (saidas[3] > saidas[2])) {
        //Serial.println(F("Frente!"));
        //steppers_frente();
        direcao = "frente";
        porcentagem = (saidas[3] * 100) / soma;
    }

    if(DEBUG) {
        printf("ENTRADAS: [%.0f, %.0f]\n\n", entradas[0], entradas[1]);
        
        printf("SAÍDAS:   [%.4f, %.4f, %.4f, %.4f]\n", saidas[0], saidas[1], saidas[2], saidas[3]);
        
        Serial.println();
        Serial.println("PORCENTAGENS:");
        printf("- Parar:    %.2f %%\n", (saidas[0] * 100) / soma);
        printf("- Esquerda: %.2f %%\n", (saidas[1] * 100) / soma);
        printf("- Direita:  %.2f %%\n", (saidas[2] * 100) / soma);
        printf("- Frente:   %.2f %%\n", (saidas[3] * 100) / soma);
    
        Serial.println();
        printf("Duração: %d ms\n", millis() - duracao);
        Serial.println(F("*********************************************************"));
    }
    
    /*
    Serial.println();
    Serial.println(F("*************************************************************************************"));
    Serial.println(F("*      ENTRADAS       *                   SAÍDAS                  *     MOVIMENTO   *")); 
    Serial.println(F("*************************************************************************************"));
    Serial.println(F("* DIREITA  * ESQUERDA *  PARAR   * ESQUERDA * DIREITA  *  FRENTE  * DIREÇÃO  *  %   *"));
    Serial.println(F("*************************************************************************************"));
    printf("*    %d     *    %d     * %8.6f * %8.6f * %8.6f * %8.6f * %8s * %6.2 *\n", entradas[0], entradas[1], saidas[0], saidas[1], saidas[2], saidas[3], direcao.c_str(), porcentagem);
    Serial.println(F("*************************************************************************************"));
    */
}

//=============================================================================================================================================