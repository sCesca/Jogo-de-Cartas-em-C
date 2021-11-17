#include "visual.h"
#include <stdio.h>

void cor_normal(void)
{
    printf("%c[0m", 27);

    return;
}

void muda_cor(int rl, int gl, int bl, int rf, int gf, int bf)
{
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);

    return;
}

void cor(int naipe)
{
    if (naipe == 0) {
        muda_cor(COR_OUROS); 
    } else if (naipe == 1) {
        muda_cor(COR_ESPADAS);
    } else if (naipe == 2) {
        muda_cor(COR_COPAS);
    } else if (naipe == 3) {
        muda_cor(COR_PAUS);
    } else if (naipe == -1) {
        muda_cor(COR_MESA);
    }

    return;
}

void indica_naipe(int naipe)
{
    if (naipe == 0) {
        printf("Ouros");
    } else if (naipe == 1) {
        printf("Espadas");
    } else if (naipe == 2) {
        printf("Copas");
    } else if (naipe == 3) {
        printf("Paus");
    }

    return;
}

void boasVindas(void)
{
    printf("|----------------------------------|\n");
    printf("|-----Bem-vindo-ao-PokerSquare-----|\n");
    printf("|----------------------------------|\n");
    printf("Informe a linha, a coluna e a carta desejada para inseri-la na mesa\n");

    return;
}