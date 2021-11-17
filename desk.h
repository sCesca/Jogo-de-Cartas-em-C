#ifndef DESK_H
#define DESK_H
#include <stdbool.h>
#include "cards.h"

#define LINHA_MESA  5
#define COLUNA_MESA 5

void inicializa_mesa(CARTA_T matriz[][5]);
bool verifica_mesa(CARTA_T matriz[][5]);
void imprime_mesa(CARTA_T matriz[][5]);
int insere_carta(CARTA_T matriz[][5], CARTA_T mao[]);
int digitos_da_carta(int carta);
void troca_posicao(CARTA_T matriz[][COLUNA_MESA]);

#endif