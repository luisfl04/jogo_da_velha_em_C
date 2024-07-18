/* ESCOPOS DOS METODOS(Este arquivo é organizado com base nestes escopos):
MÉTODOS DE EXECUÇÃO -> São os método que serão explicitamente chamados, ou seja, o método 'main' fará a chamada deles;
MÉTODOS DE VERIFICAÇÃO -> Métodos relacionados a verificação de dados que o usuário insere ou oriúndos de outros locais.
MÉTODOS GERAIS -> Implementações gerais que auxiliam na execução do arquivo.
*/

// * BIBLIOTECAS NESCESSÁRIAS * :
    #include <stdio.h>
    #include <stdlib.h>

// * CONSTANTES USADAS * :
    char tabuleiro_do_jogo[3][3]; // -> Esta é a matriz que armazenará os movimentos do jogo.

// * CABEÇALHOS DE FUNÇÕES IMPLEMENTADOS * :

// * ATRIBUTOS GLOBAIS *:

// * MÉTODOS DE VERIFICAÇÃO * :
    char verificar_vencedor(){
        /*Explicação do método -> É verificado todas as posiveis combinações do tabuleiro, e se houver algum ganhador, é retornado o valor.
        Caso não houver um ganhador, é retornado um caractere vazio. 
        */

        // Verificando as linhas do tabuleiro:
        for(int iterador = 0; iterador < 3; iterador++){
            if( (tabuleiro_do_jogo[iterador][0] == tabuleiro_do_jogo[iterador][1]) && 
            (tabuleiro_do_jogo[iterador][0] == tabuleiro_do_jogo[iterador][2]) ){
                return tabuleiro_do_jogo[iterador][0];
            }
        }

        // Verificando as combinações de colunas:
        for(int iterador = 0; iterador < 3; iterador++){
            if( (tabuleiro_do_jogo[0][iterador] == tabuleiro_do_jogo[1][iterador]) &&
            (tabuleiro_do_jogo[0][iterador] == tabuleiro_do_jogo[2][iterador]) ){
                return tabuleiro_do_jogo[0][iterador];
            }
        }

        // Fazendo o teste de combinações de diagonais:
        if( (tabuleiro_do_jogo[0][0] == tabuleiro_do_jogo[1][1]) && 
        (tabuleiro_do_jogo[1][1] == tabuleiro_do_jogo[2][2]) ){
            return tabuleiro_do_jogo[0][0];
        }

        if((tabuleiro_do_jogo[0][2] == tabuleiro_do_jogo[1][1]) && 
        (tabuleiro_do_jogo[1][1] == tabuleiro_do_jogo[2][0]) ){
            return tabuleiro_do_jogo[0][2];
        }

        // Retornando um valor vazio caso nenhuma verificação seja validada:
        return ' '; 
    }


// * MÉTODOS GERAIS * :

// * MÉTODOS DE EXECUÇÃO * :    

    void iniciar_jogo(){
        /* Explicação do método -> Basicamente, esta função preenche os espaços da matriz 'tabuleiro_do_jogo' com valores vazios. */

        // Implementação:
        for(int linha = 0; linha < 3; linha++){
            for(int coluna = 0; coluna < 3; coluna++){
                tabuleiro_do_jogo[linha][coluna] = ' ';
            }
        }
    }

    void mostrar_tabuleiro_na_tela(){
        /*Explicação do método -> Percorre as linhas do tabuleiro e printa os valores. */

        // Implementação:
        for(int linha_do_tabuleiro = 0; linha_do_tabuleiro < 3; linha_do_tabuleiro++){
            printf(" %c | %c | %c ", tabuleiro_do_jogo[linha_do_tabuleiro][0], tabuleiro_do_jogo[linha_do_tabuleiro][1], 
            tabuleiro_do_jogo[linha_do_tabuleiro][2]);

            // Enquanto o loop não chega na última linha, printo esta estilização:
            if(linha_do_tabuleiro != 2){
                printf("\n---|---|---\n");
            }
        }   

        // Ao encerrar a execulção do loop, quebro uma linha:
        printf("\n");
    }

    void obter_jogada_do_usuario(){
        /* Explicação do método -> É pedido para que o usuário digite as cordenadas da matriz onde ele quer posicionar um 'X'. É feita a verificação desse valor e caso
        ele for válido, é posicionado o 'X' na matriz.
        */

        // Criando as variáveis que irão armazenar os valores das coordenadas:
        int linha_da_jogada, coluna_da_jogada;

        // Pedindo o valor da linha:
        printf("\n\nOla usuario, digite a linha do tabuleiro onde voce deseja posicionar a sua jogada. Sao aceitos valores de 1 a 3.\nDigite o valor aqui -> ");
        scanf("%d", &linha_da_jogada);

        // Valor da coluna:
        printf("\nCerto, agora digite o valor da coluna do tabuleiro onde voce deseja posicionar sua jogada. Tambem so sao aceitos valores entre 1 e 3\nDigite sua escolha aqui -> ");
        scanf("%d", &coluna_da_jogada);

        // Ao receber os valores, é decrementado o valor das coordenadas para que seja escrita a marcação no local correto:
        linha_da_jogada--; coluna_da_jogada--;

        // Fazendo a verificação do valor:
        if(tabuleiro_do_jogo[linha_da_jogada][coluna_da_jogada] != ' '){
            // Informando valor inválido e chamando a função novamente:
            printf("\nVoce digitou valores de coordenadas invalidos! Digite novamente. ");
            obter_jogada_do_usuario();
        }   
        else{
            // Se valor válido, escrevo na coordenada.
            tabuleiro_do_jogo[linha_da_jogada][coluna_da_jogada] = 'X';
        }
    }

    void obter_jogada_do_computador(){
        /*Explicação do método -> Toda a matriz do tabuleiro é percorrida tentando encontrar um espaço vazio. Caso seja encontrado, é inserido um 'O' no local, caso não, 
        é declarado que o jogo foi empate. */

        /* Criando as variáveis que irão ser usadas para fazer as comparações das posições do tabuleiro. Elas estão sendo criadas aqui para que
        seja possível acessá-las de qualquer lugar da função.
        */
        int verificador_linha, verificador_coluna;

        // loop´:
        for(verificador_linha = 0; verificador_linha < 3; verificador_linha++){
            for(verificador_coluna = 0; verificador_coluna < 3; verificador_coluna++){  
               // Se for encontrada um espaço vazio no tabuleiro, a execução do loop é encerrada.    
               if(tabuleiro_do_jogo[verificador_linha][verificador_coluna] == ' '){
                break;
               } 
            }
            // Após for feita a comparação em uma linha, é feita a verificação novamente:
            if(tabuleiro_do_jogo[verificador_linha][verificador_coluna] == ' '){
                break;
            }
        }

        // Após a procura, é inserido o 'O' no espaço vazio encontrado ou é declarado que o jogo terminou empatado:
        if((verificador_linha * verificador_coluna) == 9){
            printf("\nO jogo terminou empatado!!!");
            exit(0);
        }
        else{
            tabuleiro_do_jogo[verificador_linha][verificador_coluna] = 'O';
        }

    }   

    int main(){

        // Dando mensagem inicial do jogo ao executar o arquivo:
        printf("Ola, seja bem vindo ao jogo_da_velha!\nVoce jogarah contra o computador.\n");

        // Criando variável que armazenará o valor da jogada:
        char jogada = ' '; // -> Inicialmente a jogada é iniciada com um valor vazio.

        // Chamando função que inicializa o tabuleiro do jogo:
        iniciar_jogo();

        // Enquanto houver espaços vazios no tabuleiro, serão pedidos novos valores:
        do{

            // A cada jogada, a matriz é mostrada na tela:
            mostrar_tabuleiro_na_tela();

            // O usuário é responsável pela primeira movimentação do jogo, essa função se encarrega disso:
            obter_jogada_do_usuario();
            
            // Em toda jogada do usuaria, é verificado se há algum vencedor.
            jogada = verificar_vencedor();

            // Se houver vencedor, a execução do loop e finalizada:
            if(jogada != ' '){
                break;
            }

            // Caso não haja vencedor, é obtida a jogada oriúnda do 'computador':
            obter_jogada_do_computador();

            // Após a jogada do computador, é verificado novamente se há algum vencedor.
            jogada = verificar_vencedor();

        }while(jogada == ' ');
        
        // Printando mensagem de vencedor conforme o resultado:
        if(jogada == 'X'){
            printf("\nParabens usuario!!! Voce ganhou a partida.");
        }
        else{
            printf("\nO computador levou a melhor nessa.");
        }

        return 0;
    }