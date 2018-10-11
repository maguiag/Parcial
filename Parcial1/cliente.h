#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[51];
    char apellido[51];
    char cuit[12];
    int idCliente;
    int isEmpty;
}Cliente;
static int proximoId();
//static int buscarLugarLibre(Cliente* array,int limite);
int cliente_init(Cliente* arrayC,int limite);
int cliente_mostrarPorId(Cliente* arrayC,int limite, int idCliente);
int cliente_mostrarDebug(Cliente* arrayC,int limite);
int cliente_alta(Cliente* arrayC,int limite);
int cliente_baja(Cliente* arrayC,int limite, int idCliente);
int cliente_modificacion(Cliente* arrayC,int limite, int idCliente);
int cliente_ordenar(Cliente* arrayC,int limite, int orden);
int cliente_altaForzada(Cliente* arrayC,int limite, char* nombre, char* apellido, char* cuit);
int cliente_buscarPorId(Cliente* arrayC,int limite, int idCliente);

#endif // CLIENTE_H_INCLUDED
