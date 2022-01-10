#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cards.h"
#include "visual.h"

/* funcao simples para impressão do vetor de baralho */
void imprimeBaralhoVetor(int cartas[][2])
{
	int i;

	for (i = 0; i < TAM_DEQUE; i++) {
		printf("[%i %i]", cartas[i][0], cartas[i][1]);
	}
			
	return;
}

/* funcao simples que preenche o vetor de baralho com as 52 cartas padrao */
void criaBaralho(int cartas[][2])
{	
	long int i, j = 0;
	NAIPES_T n;

	/* geracao do baralho ordenado */
	for (n = OUROS; n <= BASTOS; n++) {
		for (i = 1; i <= 13; i++) {
			cartas[j][VALOR] = i;
			cartas[j][NAIPE] = n;
			j++;
		}
	}
	
	return;
}

/* funcao que embaralha as cartas de acordo com uma semente para a funcao srand */
/* OBS: o uso da mesma semente irá gerar embaralhamento igual */
void embaralha(int cartas[][2])
{
	int i, j, aux_v, aux_n;
	/* EMBARALHAMENTO */
	srand(time(NULL));

	for (i = 0; i < TAM_DEQUE; i++) {
		j = (unsigned long int) rand() % TAM_DEQUE;
		aux_v = cartas[i][VALOR];
		aux_n = cartas[i][NAIPE];
		cartas[i][VALOR] = cartas[j][VALOR];
		cartas[i][NAIPE] = cartas[j][NAIPE];
		cartas[j][VALOR] = aux_v;
		cartas[j][NAIPE] = aux_n;
	}

	return;
}

int remove_cartas(CARTA_T mao[], int posicao, int tamanho)
{	
	if (posicao < 4) {
		for (int i = posicao; i < tamanho; i++) {
			mao[i] = mao[i + 1];
		}
	}
	
	return tamanho - 1;
}

void tira_novas_cartas(int cartas[][2], int posicao_no_baralho, CARTA_T mao[]) 
{
	int j = 0;
	
	for (int i = posicao_no_baralho; i < (posicao_no_baralho + 5); i++) {
		mao[j].valor = cartas[i][VALOR];
		mao[j].naipe = cartas[i][NAIPE];
		j++;  
	}

	return;
}

int conta_caracter(CARTA_T mao[])
{
	int cont = 0;

	for (int i = 0; i < 5; i++) {
		if (mao[i].valor > 9) {
			cont = 2;
		} else {
			cont = 1;
		}
	}

	return cont;
}

void imprime_mao(CARTA_T mao[], int tamanho) 
{	
	for (int i = 0; i < tamanho; i++) {
		printf("%d-", i);
		
		cor(mao[i].naipe);

		if (mao[i].valor > 9) {
			printf("%d ", mao[i].valor);

			cor_normal();

			printf(" - ");
			
			indica_naipe(mao[i].naipe);

		} else {
			printf(" %d ", mao[i].valor);

			cor_normal();

			printf(" - ");
			
			indica_naipe(mao[i].naipe);
		}

		cor_normal();
		
		printf("\n");
	}

	return;
}

int pontos_totais(CARTA_T matriz[][5])
{
	CARTA_T mao[5];
	int pontos = 0;
	
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			mao[i].valor = matriz[i][j].valor;
		}

		pontos += contaPontos(mao);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			mao[i].valor = matriz[i][j].valor;
		}

		pontos += contaPontos(mao);
	}

	for (int i = 0; i < 5; i++) {
		mao[i].valor = matriz[i][i].valor;

		pontos += contaPontos(mao);
	}

	mao[0].valor = matriz[0][4].valor;
	mao[1].valor = matriz[1][3].valor;
	mao[2].valor = matriz[2][2].valor;
	mao[3].valor = matriz[3][1].valor;
	mao[4].valor = matriz[4][0].valor;

	pontos += contaPontos(mao);
	
	return pontos;
}

/* funcao que conta os pontos de uma mao (5 cartas) passada para ela. */
/* OBS: a mao deve estar ordenada por valor ascendente. Naipes não precisam estar ordenados */
int contaPontos(CARTA_T *mao)
{
	int cont = 0, flush = 0, straight = 0, royalStraight = 0;
	int cont2 = 0, i;

	/* verifica Flush */
	for (i = 0; i < MAO-1; i++) {
		if (mao[i].naipe == mao[i+1].naipe) {
			cont ++;
		}		
	}

	if (cont == 4) {
		flush = 1; /* é um flush */
	}
		
	/* verifica Royal Straight */
	if (mao[0].valor == 1 && mao[1].valor == 10 && mao[2].valor == 11 && mao[3].valor == 12 && mao[4].valor == 13) {
		royalStraight = 1; /* é um royal straight */
	}

	if (flush && royalStraight) {
		return 100; /* mão é um royal straight flush */
	}
		
	/* verifica Straight simples */
	for (i = 0, cont = 0; i < MAO-1; i++) {
		if (mao[i].valor == (mao[i+1].valor - 1)) {
			cont ++;
		}		
	}

	if (cont == 4) {
		straight = 1; /* é um straight simples */
	}

	if (flush && straight) {
		return 75; /* mão é um straight flush */
	} 
		
	if (royalStraight || straight) {
		return 15;/* mão é um straight */
	}	

	if (flush) {
		return 20;/* mão é flush */
	}

	/* verifica pares, trincas e quadras */
	i = cont = cont2 = 0;
	while ((i < MAO-1) && (mao[i].valor != mao[i+1].valor)) {
		i++;
	}
		
	while ((i < MAO-1) && (mao[i].valor == mao[i+1].valor)) {
		cont++;
		i++;
	}

	while ((i < MAO-1) && (mao[i].valor != mao[i+1].valor)) {
		i++;
	}
		
	while ((i < MAO-1) && (mao[i].valor == mao[i+1].valor)) {
		cont2++;
		i++;
	}

	/* se foi encontrada algum par, trinca, four ou full house, é necessário */
	/* fazer cont e cont2 conter numero correto de cartas iguais encontradas */
	if (cont > 0) {
		cont++; /* normalizando valor do primeiro contador */
	} 
		
	if (cont2 > 0) {
		cont2++; /* normalizando valor do segundo contador */
	}
		
	/* após normalizaçao, cont e cont2 podem ser usados para verificacao */
	switch (cont+cont2) {
		case 5: /* mão é um full house */
			return 25;
		case 4: /* four ou dois pares */
			if(cont == 4 || cont2 == 4)
				return 50;
			else
				return 5;
		case 3: /* trinca */
			return 10;
		case 2: /* par simples */
			return 2;
	}

	return 0;
}