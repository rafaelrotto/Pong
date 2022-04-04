#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


void main()
{
    const int LIN = 20, COL = 55;
    int i, j, posicao1, posicao2, inicio_rqt1, fim_rqt1, inicio_rqt2, fim_rqt2, mov, pts1, pts2, movbola1, movbola2, fim, max;
    char campo[LIN][COL];

    i = 0;
    j = 0;
    inicio_rqt1 = 7;
    fim_rqt1 = LIN-7;
    inicio_rqt2 = 7;
    fim_rqt2 = LIN-7;
    posicao1 = COL/2;
    posicao2 = LIN/2;
    pts1 = 0;
    pts2 = 0;
    movbola1 = 1;
    movbola2 = 1;
    fim = 0;
    srand(time(NULL));

    //DEPOIS DE VÁRIAS TENTATIVAS FRUSTRADAS
    //EIS AQUI MEU CÓDIGO

    //definindo a cor do cenário

    /* CORES DISPONÍVEIS:

    0 = Black ----------- 8 = Gray

    1 = Blue ------------ 9 = Light Blue

    2 = Green ---------- A = Light Green

    3 = Aqua ----------- B = Light Aqua

    4 = Red ------------ C = Light Red

    5 = Purple --------- D = Light Purple

    6 = Yellow --------- E = Light Yellow

    7 = White ---------- F = Bright White
    */

    //fundo preto e interior vermelho
    system("COLOR 0C");

    //apresentação

    printf("\n SEJAM BEM VINDOS AO PONG! made by Rafael Roesler Otto ");
    printf("\n");
    printf("\n Controles jogador 1: W = move para cima");
    printf("\n Controles jogador 1: S = move para baixo");
    printf("\n");
    printf("\n Controles jogador 2: O = move para cima");
    printf("\n Controles jogador 2: L = move para baixo");
    printf("\n");

    //Determinado o número de pontos
    printf ("\nDetermine o número maximo de pontos? ");
    scanf("%d", &max);

	while (fim < max){
        if (pts2 > pts1){
    		fim = pts2;
    	}
    	else{
    		fim = pts1;
    	}
        system ("cls");


        //Configuração do campo
        for (i = 0; i < LIN; i++){
            for (j = 0; j < COL; j++){
                campo[i][j] = ' ';
                if (j == (COL-1))
                    campo[i][j] = '*';
                if (j == 0)
                    campo[i][j] = '*';
                if (i == (LIN-1))
                    campo[i][j] = '*';
                if (i == 0)
                    campo[i][j] = '*';
            }
        }

        //movimentação das raquetes
        if(kbhit() == 1) {
            mov = getch();
            switch(mov){
                case 'w':
                    if(inicio_rqt1 != 1) {
                        fim_rqt1 -= 1;
                        inicio_rqt1 -= 1;
                    }
                break;
                case 's':
                    if(fim_rqt1 != LIN-2){
                        fim_rqt1 += 1;
                        inicio_rqt1 += 1;
                    }
                case 'o':
                    if(inicio_rqt2 != 1) {
                        fim_rqt2 -= 1;
                        inicio_rqt2 -= 1;
                    }
                break;
                case 'l':
                    if(fim_rqt2 != LIN-2){
                        fim_rqt2 += 1;
                        inicio_rqt2 += 1;
                    }
                break;
            }
       }

       //construção da raquete jogador 1
        for (i = inicio_rqt1; i <= fim_rqt1; i++){
            campo[i][2] = '|';
        }

        //constrção da raquete jogador 2
        for (i = inicio_rqt2; i <= fim_rqt2; i++){
            campo[i][COL-3] = '|';
        }

        //configuração da bolinha
        campo[posicao2][posicao1] = 'o';
        posicao1 += movbola1;
        posicao2 += movbola2;
        if (posicao1 == 1){
            movbola1 *= -1;
            pts2++;
            posicao1 = COL / 2;

            posicao2 = ((rand() % 17)+1);
            movbola1 *= -1;
        }
        if (posicao1 == COL-1){
            movbola1 *= -1;
            pts1++;
            posicao1 = COL / 2;
            posicao2 = ((rand() % 17)+1);
            movbola1 *= -1;
        }

        //colisão com as raquetes
        if ((posicao2 == LIN - 2) || (posicao2 == 1)){
            movbola2 *= -1;
        }
        if ((posicao1 == 2) && (posicao2 == inicio_rqt1 || posicao2== inicio_rqt1+1 || posicao2 == inicio_rqt1 +2 || posicao2 == inicio_rqt1 +3 || posicao2 == inicio_rqt1 +4 || posicao2 == inicio_rqt1 +5 || posicao2 == fim_rqt1)){
            movbola1 *= -1;
        }
        if ((posicao1 == COL-3) && (posicao2 == inicio_rqt2 || posicao2 == inicio_rqt2 +1 || posicao2 == inicio_rqt2 +2 || posicao2 == inicio_rqt2 +3 || posicao2 == inicio_rqt2 +4 || posicao2 == inicio_rqt2 +5 || posicao2 == fim_rqt2)){
            movbola1 *= -1;
        }

        //finalização do campo
        for (i=0; i < LIN; i++){
            printf ("\n");
            for (j = 0;j < COL; j++){
                printf ("%c", campo[i][j]);
            }
        }

        //pontuações
        printf("\nPlayer 1 = %d\tPlayer 2 = %d", pts1, pts2);
    }

    //resultados finais
    system("cls");
    printf ("\nRESULTADOS: \n");
    printf ("Player 1: %d\n", pts1);
    printf ("Player 2: %d\n", pts2);
    if (pts2 > pts1){
    	printf("PLAYER 2 GANHOU!\n");
    }
    if (pts1 > pts2){
   		printf("PLAYER 1 GANHOU\n");
    }

    //game over
    printf("\nAperte qualquer tecla para sair\n");
    getch();
}
