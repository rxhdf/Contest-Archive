#ifndef KAREL_H
#define KAREL_H

void jugar(int n);
void recibir_muro(int &f, int &c, int &d);
void mover(int d);
void poner_muro(int f, int c, int d);
int recibir_movimiento();

#endif
