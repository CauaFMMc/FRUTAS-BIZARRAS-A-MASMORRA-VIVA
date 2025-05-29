#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define parede '*'
#define vazio ' '
#define personagem '&'
#define INIMIGO_ALEATORIO 'X'
#define INIMIGO_SEGUIDOR 'V'
#define chave '@'
#define espinho '#'
#define portao '='
#define portac 'D'
#define teletransporte '>'
#define botao 'O'
#define npc 'P'

	int menu(){
    printf("***********************************************************************\n");
    printf("*                                                                     *\n");
    printf("*  *-------* *_ *________ *-------* *_______ * _______  *-------*     *\n");
    printf("*  |  ---  | | ||______  ||  ---  | | ____  | | ____  | |  -----|     *\n");
    printf("*  | |___| | | | ______| || |___| | | |___| | | |___| | | |_____      *\n");
    printf("*  |  ___ |  | ||  ______||  ___  | |  _____| |  _____| |  _____|     *\n");
    printf("*  | |   | | | || |       | |   | | | |  | |  | |  | |  | |           *\n");
    printf("*  | |___| | | || |______ | |   | | | |  | |  | |  | |  | |_____      *\n");
    printf("*  |_______| |_||________||_|   |_| |_|   |_| |_|   |_| |_______|     *\n");
    printf("*                                                                     *\n");
    printf("*  *-------*  *_______ *_     _ *_    ________  *________             *\n");
    printf("*  |  -----| |  ____ | | |   | | | | |___  ___| |  _____|             *\n");
    printf("*  | |_____  |  |__| | | |   | | | |    | |     | |_____              *\n");
    printf("*  |  _____| |  _____| | |   | | | |    | |     |_____  |             *\n");
    printf("*  | |       | | | |   | |   | | | |    | |           | |             *\n");
    printf("*  | |       | |  | |  | |___| | | |    | |     ______| |             *\n");
    printf("*  |_|       |_|  |_|  *_______* |_|    |_|     |_______|             *\n");
    printf("*                                                                     *\n");
	printf("*                                                                     *\n");
    printf("*      [1] Jogar                                                      *\n");
    printf("*      [2] Creditos                                                   *\n");
    printf("*      [3] Sair                                                       *\n");
    printf("*                                                                     *\n");
    printf("***********************************************************************\n");
    printf(": ");
}

	int creditos() {
    system("cls");
    printf("***********************************************************************\n");
    printf("*                                                                     *\n");
    printf("*                          === CREDITOS ===                           *\n");
    printf("*                                                                     *\n");
    printf("*    Jogo desenvolvido por:                                           *\n");
    printf("*                                                                     *\n");
    printf("*                                                                     *\n");
    printf("*                                                                     *\n");
    printf("*                                                                     *\n");
    printf("*                                                                     *\n");
    printf("*                                                                     *\n");
    printf("*                                                                     *\n");
    printf("*                                                                     *\n");
    printf("*      - Brenno Yasuhei                                               *\n");
    printf("*      - Guilherme Mergulhao                                          *\n");
    printf("*      - Caua Felipe                                                  *\n");
    printf("*                                                                     *\n");
    printf("*      Obrigado por jogar!                                            *\n");
    printf("*                                                                     *\n");
    printf("*      Pressione qualquer tecla para voltar ao menu...                *\n");
    printf("*                                                                     *\n");
    printf("***********************************************************************\n");
    _getch();
    return 4;
	}

	int vila() {
    int i;
    int temChave = 0;
    int ganhou = 0;
    char mapa[10][11]={
	    "**********",
        "****DD****",
        "*        *",
        "* P      *",
        "*        *",
        "*        *",
        "*     @  *",
        "*        *",
        "*        *",
        "**********"
	};
	
 	int x=4, y=8;
 	int novoX = x;
	int novoY = y;
    int chaveX = 4, chaveY = 3;
 	mapa[y][x] = personagem;

 	char comando;
    do {
        system("cls");
        // Exibe o mapa
        for(i = 0; i < 10; i++) {
            printf("%s\n", mapa[i]);
        }
        
        if (temChave)
            printf("Chave: SIM\n");
        else
            printf("Chave: NAO\n");
        
	// Captura o comando
        comando = _getch();

        // Apaga o personagem na posicao atual
        mapa[y][x] = vazio;
    
        // Movimenta o personagem
        if (comando == 'w') novoY--;
		else if (comando == 's') novoY++;
		else if (comando == 'a') novoX--;
		else if (comando == 'd') novoX++;
		
		if (mapa[novoY][novoX] == parede) {
    		novoX = x;
			novoY = y;
		}

        if (mapa[novoY][novoX] == npc) {
    		novoX = x;
			novoY = y;
		}
		
		if (mapa[novoY][novoX] == chave) {
            temChave = 1;
        }
        
        // Porta trancada
        if (mapa[novoY][novoX] == portac) {
            if (temChave) {
                mapa[novoY][novoX] = portao; // Abre a porta
            } else {
                novoX = x;
                novoY = y; // Nao deixa passar
            }
        }

        if (comando == 'i' && y > 0 && mapa[y - 1][x] == npc) {
                    printf("  ------------------------------------------------------------\n");
        printf(" | Ola, Elon. Imagino que esteja com medo de sua jornada,     |\n");
        printf(" | porem as frutas bizarras sao extremamente valiosas, feitas |\n");
        printf(" | por povos antigos, se dominarmos elas, teremos o poder dos |\n");
        printf(" | GRANDES.                                                   |\n");
        printf(" | Na sua jornada cuidado com espinhos e inimigos,            |\n");
        printf(" | se necessario, use as frutas ao seu favor.                 |\n");
        printf("  ------------------------------------------------------------\n");
        printf("           \\\n");
        printf("            \\\n");
        printf("             O\n");     // cabeça
        printf("            /|\\\n");    // braços e corpo
        printf("            / \\\n");    // pernas

                system("pause");
            }

        // Porta aberta, finaliza o jogo
        if (mapa[novoY][novoX] == portao) {
            ganhou = 1;
            break;
        } 
		
        x = novoX;
        y = novoY;
              
		// Atualiza o personagem na nova posicao
        mapa[y][x] = personagem;
       
    }while (comando != 'q');
    
    if (ganhou) {
        system("cls");
        for(i = 0; i < 10; i++) {
            printf("%s\n", mapa[i]);
        }
        printf("\nParabens, voce venceu o jogo!\n");
        return 1;
    } else {
        printf("FIM DE JOGO\n");
        return 0;
	}
}

	int fase1() {
    int i;
    int temChave = 0;
    int ganhou = 0;
    char mapa[10][11]={
	    "**********",
        "*        *",
        "******** *",
        "*      * *",
        "* ****   *",
        "*   ******",
        "* * *    *",
        "* * * *  *",
        "*@*   *  D",
        "**********"
	};
	
 	int x=1, y=1;
 	int novoX = x;
	int novoY = y;
 	mapa[y][x] = personagem;
 	
 	char comando;
    do {
        system("cls");

        // Exibe o mapa
        for(i = 0; i < 10; i++) {
            printf("%s\n", mapa[i]);
        }
        
        if (temChave)
            printf("Chave: SIM\n");
        else
            printf("Chave: NAO\n");
        
	// Captura o comando
        comando = _getch();

        // Apaga o personagem na posicao atual
        mapa[y][x] = vazio;

        // Movimenta o personagem
        if (comando == 'w') novoY--;
		else if (comando == 's') novoY++;
		else if (comando == 'a') novoX--;
		else if (comando == 'd') novoX++;
		
		if (mapa[novoY][novoX] == parede) {
    		novoX = x;
			novoY = y;
		}
		
		if (mapa[novoY][novoX] == chave) {
            temChave = 1;
        }
        
        // Porta trancada
        if (mapa[novoY][novoX] == portac) {
            if (temChave) {
                mapa[novoY][novoX] = portao; // Abre a porta
            } else {
                novoX = x;
                novoY = y; // Nao deixa passar
            }
        }

        // Porta aberta, finaliza o jogo
        if (mapa[novoY][novoX] == portao) {
            ganhou = 1;
            break;
        }

        // Teletransporte
        if (mapa[novoY][novoX] == teletransporte) {
            int tx = -1, ty = -1;
            int linha;
            int col;
            for (linha = 0; linha < 10; linha++) {
                for (col = 0; col < 10; col++) {
                    if (mapa[linha][col] == teletransporte && (linha != novoY || col != novoX)) {
                        tx = col;
                        ty = linha;
                        break;
                    }
                }
                if (tx != -1) break;
            }
            if (tx != -1) {
                novoX = tx;
                novoY = ty;
            }
        }
        
		
        x = novoX;
        y = novoY;
		      
	// Atualiza o personagem na nova posicao
        mapa[y][x] = personagem;
        
    }while (comando != 'q');
    
    if (ganhou) {
        system("cls");
        for(i = 0; i < 10; i++) {
            printf("%s\n", mapa[i]);
        }
        return 2;
    }
}


	int fase2(){
	int i;
	int temchave = 0;
	int ganhou = 0;
    char mapa[20][21]={
		
		"********************",
		"*                  *",
		"*                  *",
		"*##########        *",
		"*                  *",
		"*                  *",
		"*                  *",
		"*                  *",
		"*                  *",
		"*        ##########*",
		"*                  *",
		"*                  *",
		"*                  *",
		"*                  *",
		"*                D *",
		"*                  *",
		"*#####             *",
		"*    #             *",
		"*@   #    O        *",
		"********************"
	};
	
 	int x=1, y=1;
 	int novoX = x;
	int novoY = y;
 	int inimigoX = 8, inimigoY = 8;
 	mapa[y][x] = personagem;
 	mapa[inimigoY][inimigoX] = INIMIGO_ALEATORIO;
 	
 	char comando;
    do {
        system("cls");

        // Exibe o mapa
        for(i = 0; i < 20; i++) {
            printf("%s\n", mapa[i]);
        }
        
        if (temchave)
            printf("Chave: SIM\n");
        else
            printf("Chave: NAO\n");
        
        comando = _getch();

        mapa[y][x] = vazio;
        mapa[inimigoY][inimigoX] = vazio;

        // Movimentacao o personagem
        if (comando == 'w') novoY--;
		else if (comando == 's') novoY++;
		else if (comando == 'a') novoX--;
		else if (comando == 'd') novoX++;
		
		if (mapa[novoY][novoX] == parede) {
    		novoX = x;
			novoY = y;
		}
        
        // Movimentacao do inimigo aleatorio
        int direcao = rand() % 4;
        if (direcao == 0 && mapa[inimigoY - 1][inimigoX] == vazio) inimigoY--;
        else if (direcao == 1 && mapa[inimigoY + 1][inimigoX] == vazio) inimigoY++;
        else if (direcao == 2 && mapa[inimigoY][inimigoX - 1] == vazio) inimigoX--;
        else if (direcao == 3 && mapa[inimigoY][inimigoX + 1] == vazio) inimigoX++;
       
		//morte do personagem
        if (mapa[novoY][novoX] == espinho || (x == inimigoX && y == inimigoY)){
            system("cls");
            for(i = 0; i < 20; i++) {
                printf("%s\n", mapa[i]);
            }
            printf("\nVoce morreu!\n");
            break;
        }
        
        if (mapa[novoY][novoX] == chave) {
            temchave = 1;
        }
        
        
        if(mapa[novoY][novoX] == portac){
			if(temchave){
				mapa[novoY][novoX] = portao;
			}else {
                novoX = x;
                novoY = y;
            }
		}
		
		if (mapa[novoY][novoX] == portao) {
            ganhou = 1;
            break;
        }
        
        int linha, col;
        if (mapa[novoY][novoX] == botao) {
            for (linha = 0; linha < 20; linha++) {
                for ( col = 0; col < 20; col++) {
                    if (mapa[linha][col] == espinho) {
                        mapa[linha][col] = vazio;
                    }
                }
            }
        }
        x = novoX;
		y = novoY;
		mapa[y][x] = personagem;
        mapa[inimigoY][inimigoX] = INIMIGO_ALEATORIO;	
		
    }while (comando != 'q');
    
    if (ganhou) {
        system("cls");
        for(i = 0; i < 20; i++) {
            printf("%s\n", mapa[i]);
        }
        return 3;    
    }
}
	int fase3(){
	int i;
    int temChave = 0;
    int ganhou = 0;
    char mapa[40][41]={
		
		"****************************************",
		"*           #     # #  #         #   O *",
		"*           # #   # #  #     #         *",
		"*           # #   #    #   #######   > *",
		"*   #####     #   # #  #   #     #     *",
		"*    #        #   # #  #      #  #     *",
		"*###########  #   # ###########  ######*",
		"*                                      *",
		"*###  ##############   ################*",
		"*              #                       *",
		"*###########  ######################  #*",
		"*                            #         *",
		"* ##  ###############        #         *",
		"*        #                #############*",
		"*        #                             *",
		"* #  #############     ################*",
		"*        #                #            *",
		"* ###############################      *",
		"*                                      *",
		"*      ################################*",
		"*      #                               *",
		"*     ##                               *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*############                          *",
		"*@   >                                 *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*                         #############*",
		"*                                      *",
		"*                                      *",
		"*                                      *",
		"*######                                *",
		"*     #                                *",
		"*D    #                                *",
		"****************************************"
	};
	
 	int x=1, y=1;
 	int novoX = x;
	int novoY = y;
 	int inimigoX = 8, inimigoY = 8;
 	int seguidorX = 20, seguidorY = 20;
 	mapa[y][x] = personagem;
 	mapa[inimigoY][inimigoX] = INIMIGO_ALEATORIO;
 	mapa[seguidorY][seguidorX] = INIMIGO_SEGUIDOR;
 	
 	char comando;
    do {
        system("cls");

        // Exibe o mapa
        for(i = 0; i < 40; i++) {
            printf("%s\n", mapa[i]);
        }
        
        if (temChave)
            printf("Chave: SIM\n");
        else
            printf("Chave: NAO\n");
        
	// Captura o comando
        comando = _getch();

        // Apaga o personagem na posicao atual
        mapa[y][x] = vazio;
        mapa[inimigoY][inimigoX] = vazio;
        mapa[seguidorY][seguidorX] = vazio;

        // Movimenta o personagem
        if (comando == 'w') novoY--;
		else if (comando == 's') novoY++;
		else if (comando == 'a') novoX--;
		else if (comando == 'd') novoX++;
		
		if (mapa[novoY][novoX] == parede) {
    		novoX = x;
			novoY = y;
		}
		
		if (mapa[novoY][novoX] == chave) {
            temChave = 1;
        }
        
        // Porta trancada
        if (mapa[novoY][novoX] == portac) {
            if (temChave) {
                mapa[novoY][novoX] = portao; // Abre a porta
            } else {
                novoX = x;
                novoY = y; // Nao deixa passar
            }
        }

        // Porta aberta, finaliza o jogo
        if (mapa[novoY][novoX] == portao) {
            ganhou = 1;
            break;
        }

        // Pisa no botao -> remove todos os espinhos
        int linha, col;
        if (mapa[novoY][novoX] == botao) {
            for (linha = 0; linha < 40; linha++) {
                for ( col = 0; col < 40; col++) {
                    if (mapa[linha][col] == espinho) {
                        mapa[linha][col] = vazio;
                    }
                }
            }
        }

        // Teletransporte
        if (mapa[novoY][novoX] == teletransporte) {
            int tx = -1, ty = -1;
            for (linha = 0; linha < 40; linha++) {
                for (col = 0; col < 40; col++) {
                    if (mapa[linha][col] == teletransporte && (linha != novoY || col != novoX)) {
                        tx = col;
                        ty = linha;
                        break;
                    }
                }
                if (tx != -1) break;
            }
            if (tx != -1) {
                novoX = tx;
                novoY = ty;
            }
        }
        
        x = novoX;
        y = novoY;
        
        // Movimentacao do inimigo aleatorio
        int direcao = rand() % 4;
        if (direcao == 0 && mapa[inimigoY - 1][inimigoX] == vazio) inimigoY--;
        else if (direcao == 1 && mapa[inimigoY + 1][inimigoX] == vazio) inimigoY++;
        else if (direcao == 2 && mapa[inimigoY][inimigoX - 1] == vazio) inimigoX--;
        else if (direcao == 3 && mapa[inimigoY][inimigoX + 1] == vazio) inimigoX++;
        
        // Movimentacao do inimigo seguidor
        if (seguidorY < y && mapa[seguidorY + 1][seguidorX] == vazio) seguidorY++;
        else if (seguidorY > y && mapa[seguidorY - 1][seguidorX] == vazio) seguidorY--;

        if (seguidorX < x && mapa[seguidorY][seguidorX + 1] == vazio) seguidorX++;
        else if (seguidorX > x && mapa[seguidorY][seguidorX - 1] == vazio) seguidorX--;
        
		      
        //morte do personagem
        if (mapa[novoY][novoX] == espinho || (x == inimigoX && y == inimigoY) || (x == seguidorX && y == seguidorY)) {
            system("cls");
            for(i = 0; i < 40; i++) {
                printf("%s\n", mapa[i]);
            }
            printf("\nVoce morreu!\n");
            break;
        }
        
		// Atualiza o personagem na nova posicao
        mapa[y][x] = personagem;
        mapa[inimigoY][inimigoX] = INIMIGO_ALEATORIO;
        mapa[seguidorY][seguidorX] = INIMIGO_SEGUIDOR;
        
    }while (comando != 'q');
    
    if (ganhou) {
        system("cls");
        for(i = 0; i < 40; i++) {
            printf("%s\n", mapa[i]);
        }
        system("cls");
    printf("\n");
    printf("  [=============================================]\n");
    printf("  [                                             ]\n");
    printf("  [       Obrigado por jogar nosso jogo!        ]\n");
    printf("  [                                             ]\n");
    printf("  [     Esperamos te ver novamente em breve!    ]\n");
    printf("  [                                             ]\n");
    printf("  [      - Brenno Yasuhei                       ]\n");
    printf("  [      - Guilherme Mergulhao                  ]\n");
    printf("  [      - Caua Felipe                          ]\n");
    printf("  [                                             ]\n");
    printf("  [      Encerrando...                          ]\n");
    printf("  [=============================================]\n");
    printf("\n");
        _getch();
    } else {
        printf("FIM DE JOGO\n");
        return 0;
	}
}

int main()
{
	int executarFaseComTentativas(int (*fase)(), int tentativasMax) {
    int tentativas = 0;
    int resultado = 0;

    while (tentativas < tentativasMax) {
        resultado = fase();
        if (resultado > 0) {
            return resultado; // fase vencida, retorna codigo
        } else {
            tentativas++;
            printf("\nTentativa %d/%d\n", tentativas, tentativasMax);
            _getch();
        }
    }
    system("cls");
    printf("\n");
    printf("[=====================================]\n");
    printf("[           VOCE FOI DERROTADO        ]\n");
    printf("[=====================================]\n");
    printf("[ Nao desanime, ate os maiores herois ]\n");
    printf("[ ja cairam em batalha alguma vez...  ]\n");
    printf("[                                     ]\n");
    printf("[ Use esta derrota como aprendizado.  ]\n");
    printf("[ A jornada continua, e voce esta     ]\n");
    printf("[ ficando mais forte a cada passo.    ]\n");
    printf("[                                     ]\n");
    printf("[      Pressione qualquer tecla       ]\n");
    printf("[         para tentar de novo.        ]\n");
    printf("[=====================================]\n");
    _getch();
    return 0;
	}
	
	while (1) {
        system("cls");
	menu();
	int z;
	scanf("%d", &z);
    
    if(z == 1){
    	int resultado = executarFaseComTentativas(vila, 3);
		if(resultado == 1){
			resultado = executarFaseComTentativas(fase1, 3);
			if(resultado == 2){
				resultado = executarFaseComTentativas(fase2, 3);
				if(resultado == 3){
					resultado = executarFaseComTentativas(fase3, 3);
				}
			}
			
		}
			
	}
	else if(z == 2){
		creditos();
		
	}
	else if(z == 3){
		printf("\ndesligando...\n");
		return 0;
	}
	else {
            printf("\nOpcao invalida! Pressione uma tecla para tentar novamente.\n");
            _getch();
        }
	}
    return 0;
}