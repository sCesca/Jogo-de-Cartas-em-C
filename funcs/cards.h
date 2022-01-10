#ifndef CARDS_H
#define CARDS_H

#define TAM_DEQUE	52
#define VALOR		0
#define	NAIPE		1
#define MAO		5

typedef enum {OUROS, ESPADAS, COPAS, BASTOS} NAIPES_T;

/* tipo a ser usado para a fila correspondente a mao do usuario */
typedef struct n {
	int valor;
	int naipe;
} CARTA_T;

void imprimeBaralhoVetor(int cartas[][2]);
void criaBaralho(int cartas[][2]);
void embaralha(int cartas[][2]);
void tira_novas_cartas(int cartas[][2], int posicao_no_baralho, CARTA_T mao[]);
int contaPontos(CARTA_T *mao);
void imprime_mao(CARTA_T mao[], int tamanho);
int conta_caracter(CARTA_T mao[]);
int remove_cartas(CARTA_T mao[], int posicao, int tamanho);
int pontos_totais(CARTA_T matriz[][5]);

#endif