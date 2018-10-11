#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "utn.h"
#include "cliente.h"
#include "afiches.h"
#define VENTAS 1000
#define QTY 100

int informe_clienteMasACobrar(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches);
int informe_clienteMasCobradas(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches);
int informe_ventasTotales(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches);
int informe_clienteMasAfichesCobrar(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches);
int informe_clienteComproMasAfiches(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches);
int informe_clienteMasMil(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches);
#endif // INFORMES_H_INCLUDED
