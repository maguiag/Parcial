#ifndef AFICHES_H_INCLUDED
#define AFICHES_H_INCLUDED
#include "cliente.h"

typedef struct
{
    int idCliente;
    int cantAfiches;
    char nombreArchivo[51];
    char zona[51];
    int idAfiche;
    int estado;
    int isEmpty;
}Afiches;

static int proximoId();
//static int buscarLugarLibre(Afiches* arrayA,int limite);
int afiches_init(Afiches* arrayA,int limite);
int afiches_mostrarPorId(Afiches* arrayA,int limite, int idAfiches);
int afiches_mostrarDebug(Afiches* arrayA,int limite);

int afiches_alta(Afiches* arrayA,int limiteAfiches, Cliente* pBuffer, int limiteCliente);
int afiches_baja(Afiches* arrayA,int limite, int idAfiche);
//int afiches_modificacion(Afiches* array,int limite, int idAfiche);
int afiches_ordenar(Afiches* arrayA,int limite, int orden);
int afiches_altaForzada(Afiches* arrayA,int limite, char* cantidad, char* nombreArch, char* auxZona);
int afiches_buscarPorIdAfiche(Afiches* arrayA,int limite, int idAfiche);
int afiches_cobrar(Afiches* arrayAfiches, int limiteAfiche, Cliente* pBuffer, int limiteCliente, int id, int *indice);
int afiches_aCobrarByIdCliente(Afiches* arrayA,int limite,int idCliente);
int afiches_listado(Afiches* arrayA,int limite);
int afiches_cambiarEstado(Afiches* arrayA, int limite);
int afiches_editar(Afiches* arrayA,int id,int limite,int cantAfiches,int zona);
int informe_clientesAcobrar(Cliente* arrayA, int limiteClientes, Afiches* pBuffer, int limiteAfiches);

#endif // AFICHES_H_INCLUDED
