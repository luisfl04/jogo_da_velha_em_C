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
            printf(" %c  | %c  | %c ", tabuleiro_do_jogo[linha_do_tabuleiro][0], tabuleiro_do_jogo[linha_do_tabuleiro][1], 
            tabuleiro_do_jogo[linha_do_tabuleiro][2]);

            // Enquanto o loop não chega na última linha, printo esta estilização:
            if(linha_do_tabuleiro != 2){
                printf("\n---|---|---\n");
            }
        }   

        // Ao encerrar a execulção do loop, quebro uma linha:
        printf("\n");
    }



    int main(){

        mostrar_tabuleiro_na_tela();

        // // Dando mensagem inicial do jogo ao executar o arquivo:
        // printf("Ola, seja bem vindo ao jogo_da_velha!\nVoce jogarah contra o computador.");

        // // Criando variável que armazenará o valor da jogada:
        // char jogada = ' '; // -> Inicialmente a jogada é iniciada com um valor vazio.

        // // Chamando função que inicializa o tabuleiro do jogo:
        // iniciar_jogo();

        // // Enquanto houver espaços vazios no tabuleiro, serão pedidos novos valores:
        // do{

        //     // A cada jogada, a matriz é mostrada na tela:




        // }while(jogada == ' ');





        return 0;
    }