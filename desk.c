#include "desk.h"
#include "cards.h"
#include "visual.h"
#include <stdio.h>

void inicializa_mesa(CARTA_T matriz[][COLUNA_MESA]) 
{
    for (int i = 0; i < LINHA_MESA; i++) {
        for (int j = 0; j < COLUNA_MESA; j++) {
            matriz[i][j].valor = -1;
            matriz[i][j].naipe = -1;
        }
    }

    return;
}

bool verifica_mesa(CARTA_T matriz[][COLUNA_MESA])
{
    int contador = 0;

    for (int i = 0; i < LINHA_MESA; i++) {
        for (int j = 0; j < COLUNA_MESA; j++) {
            if (matriz[i][j].valor == -1) {
                contador++;
            }
        }
    }

    if (contador == 0) {
        return false;
    } else {
        return true;
    }
}

int digitos_da_carta(int carta)
{
    int cont = 0;
    
    do {
        cont++;
        carta = carta / 10;
    } while (carta != 0);
    
    return cont;
}

void imprime_mesa(CARTA_T matriz[][COLUNA_MESA]) 
{
    printf("\n");
    printf("     0    1    2    3    4\n");
    for (int i = 0; i < 5; i++) {
        for (int l = 0 ; l < 3; l++) {
            if (l == 1) printf(" %d-", i);
            else printf("   ");
            for (int j = 0; j < 5; j++) {
                cor(matriz[i][j].naipe);
                if (l == 1) {
                    if (digitos_da_carta(matriz[i][j].valor) == 1 && matriz[i][j].valor != -1) {
                        printf("  %d  ", matriz[i][j].valor);
                    } else if(matriz[i][j].valor == -1) {
                            printf("     ");
                    } else {
                        printf("  %d ", matriz[i][j].valor);
                    }
                } else {
                    printf("     ");
                }
            }
            
            cor_normal();
            
            printf("\n");
        }
    }
    
    return;
}

void troca_posicao(CARTA_T matriz[][COLUNA_MESA])
{
    int contador = 0, linha1, linha2, coluna1, coluna2, aux_valor, aux_naipe;
    
    while (contador < 2) {
        scanf("%d", &linha1);
        if (linha1 > 4) break;

        scanf("%d", &coluna1);
        if (coluna1 > 4) break;
        
        scanf("%d", &linha2);
        if (linha2 > 4) break;
        
        scanf("%d", &coluna2);
        if (coluna2 > 4) break;
       
        aux_valor = matriz[linha1][coluna1].valor;

        aux_naipe = matriz[linha1][coluna1].naipe;

        matriz[linha1][coluna1].valor = matriz[linha2][coluna2].valor;

        matriz[linha1][coluna1].naipe = matriz[linha2][coluna2].naipe;

        matriz[linha2][coluna2].valor = aux_valor;

        matriz[linha2][coluna2].naipe = aux_naipe;
        
        imprime_mesa(matriz);
        
        contador++;
    }

    return;
}

int insere_carta(CARTA_T matriz[][COLUNA_MESA], CARTA_T mao[])
{
    int linha, coluna, posica_na_mao;

    while(true) {
        scanf("%d %d %d", &linha, &coluna, &posica_na_mao);
        if (matriz[linha][coluna].valor == -1) {
            matriz[linha][coluna].valor = mao[posica_na_mao].valor;
            matriz[linha][coluna].naipe = mao[posica_na_mao].naipe;

            return posica_na_mao;
        } else {
            continue;
        }
    } 
    
}