#ifndef VISUAL_H
#define VISUAL_H

#define COR_PAUS 255, 255, 255, 0, 0, 0  /* preto */
#define COR_COPAS 255, 255, 255, 255, 0, 0  /* vermelho escuro */
#define COR_ESPADAS 255, 255, 255, 77, 77, 77  /* cinza */
#define COR_OUROS 255, 255, 255, 255, 102, 102  /* vermelho claro */
#define COR_MESA 255, 255, 255, 255, 255, 255  /* branco */

void cor_normal(void);
void muda_cor(int rl, int gl, int bl, int rf, int gf, int bf);
void cor(int naipe);
void boasVindas(void);
void indica_naipe(int naipe);

#endif