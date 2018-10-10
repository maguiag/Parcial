#ifndef AFICHES_H_INCLUDED
#define AFICHES_H_INCLUDED

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

int afiches_init(Afiches* array,int limite);
int afiches_mostrarPorId(Afiches* array,int limite, int idAfiches);
int afiches_mostrarDebug(Afiches* array,int limite);

int afiches_alta(Afiches* array,int limiteAfiches, Cliente* pBuffer, int limiteCliente);
int afiches_baja(Afiches* array,int limite, int idAfiche);
//int afiches_modificacion(Afiches* array,int limite, int idAfiche);
int afiches_ordenar(Afiches* array,int limite, int orden);
int afiches_altaForzada(Afiches* array,int limite, char* cantidad, char* nombreArch, char* auxZona);
int afiches_buscarPorIdAfiche(Afiches* array,int limite, int idAfiche);
int afiches_cobrar(Afiches* arrayAfiches, int limiteAfiche, Cliente* pBuffer, int limiteCliente, int id, int *indice)
int afiches_aCobrarByIdCliente(Afiches* array,int limite,int idCliente);
int afiches_listado(Afiches* array,int limite);
int afiches_cambiarEstado(Afiches* array, int limite);
int afiches_editar(Afiches* array,int id,int limite,int cantAfiches,int zona);

#endif // AFICHES_H_INCLUDED
