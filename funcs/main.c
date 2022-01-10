#include <stdlib.h>
#include <stdio.h>
#include "cards.h"
#include "desk.h"
#include "visual.h"

int main()
{
	int cartas[TAM_DEQUE][2];
	int posicao_no_baralho = 0, posicao, contador = 0, tamanho;
	CARTA_T mao[5];
	CARTA_T mesa[LINHA_MESA][COLUNA_MESA];
	
	boasVindas();
	
	criaBaralho(cartas);
	
	embaralha(cartas);
	
	inicializa_mesa(mesa);
	
	do {
		if (contador == 0 || contador == 5) {
			tira_novas_cartas(cartas, posicao_no_baralho, mao);

			tamanho = 5;
			contador = 0;
			posicao_no_baralho += 5;
		}
		
		imprime_mesa(mesa);
		
		printf("\n");
		
		imprime_mao(mao, tamanho);
		
		posicao = insere_carta(mesa, mao);
		
		tamanho = remove_cartas(mao, posicao, tamanho);

		contador++;

		
	} while (verifica_mesa(mesa));

	imprime_mesa(mesa);

	printf("Voce possui duas trocas de posicoes\n-Informe  a linha e a coluna, respectivamente, de ambos os pontos: ");

	troca_posicao(mesa);

	printf("\nVoce fez %d pontos\n", pontos_totais(mesa));

	exit(0);
}