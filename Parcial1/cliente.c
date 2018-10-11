#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"


//static int buscarLugarLibre(Cliente* array,int limite);


/** \brief Inicializa la estructura clientes
 * \param array Cliente* puntero a array
 * \param limite int limite definido para la estructura cliente
 * \return int [0] OK [1] ERROR
 *
 */

int cliente_init(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayC[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Muestra el debug de la estructura Cliente
 *
 * \param array Cliente* puntero a array
 * \param limite int limite definido para cliente
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_mostrarDebug(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",arrayC[i].idCliente, arrayC[i].nombre, arrayC[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief Muestra cliente a partir del IdCliente que recibe
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para cliente
 * \param idCliente int ID del cliente que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_mostrarPorId(Cliente* arrayC,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente==idCliente)
                printf("[RELEASE] -ID: %d -NOMBRE: %s -APELLIDO: %s -CUIT: %s\n",arrayC[i].idCliente, arrayC[i].nombre, arrayC[i].apellido, arrayC[i].cuit);
        }
    }
    return retorno;
}

/** \brief Da de alta al cliente
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para Cliente
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_alta(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];

    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            if(!getValidString("\nIngrese nombre: ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
            {
                if(!getValidString("\nIngrese el apellido: ","\nNo es un apellido","El maximo es de 50",auxApellido,50,2))
                {
                    if(!getValidInt("\nIngrese CUIT: ","\nDebe tener solo numeros","El maximo es de 11",auxCuit,12,2))
                    {
                        retorno = 0;
                        strcpy(arrayC[i].nombre,auxNombre);
                        strcpy(arrayC[i].apellido,auxApellido);
                        strcpy(arrayC[i].cuit,auxCuit);
                        arrayC[i].idCliente = proximoId();
                        arrayC[i].isEmpty = 0;
                        printf("El IdCliente es: %d\n",arrayC[i].idCliente);
                    }
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


/** \brief Da de baja al cliente por el ID
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para cliente
 * \param idCliente int Id del cliente que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_baja(Cliente* arrayC,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente==idCliente)
            {
                arrayC[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica al cliente a partir de su Id
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \param idCliente int Id del cliente buscado
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_modificacion(Cliente* arrayC,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];
    if(limite > 0 && arrayC != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente==idCliente)
            {
                if(!getValidString("\nIngrese nombre: ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
                {
                    if(!getValidString("\nIngrese apellido: ","\nNo es un apellido","El maximo es de 50",auxApellido,50,2))
                    {
                        if(!getValidInt("\nIngrese CUIT: ","\nDebe tener solo numeros","El maximo es de 11",auxCuit,12,2))
                        {
                            retorno = 0;
                            strcpy(arrayC[i].nombre,auxNombre);
                            strcpy(arrayC[i].apellido,auxApellido);
                            strcpy(arrayC[i].cuit,auxCuit);
                            arrayC[i].idCliente = proximoId();
                            arrayC[i].isEmpty = 0;
                        }
                    }
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Ordena a los clientes de menor a mayo o de mayor a menor segun el "orden"
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \param orden int [1] de menor a mayor, [0] de mayor a menor
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_ordenar(Cliente* arrayC,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && arrayC != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayC[i].isEmpty && !arrayC[i+1].isEmpty)
                {
                    if((strcmp(arrayC[i].nombre,arrayC[i+1].nombre) > 0 && orden) || (strcmp(arrayC[i].nombre,arrayC[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayC[i];
                        arrayC[i] = arrayC[i+1];
                        arrayC[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief Busca el lugar libre en el array de clientes
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \return int [0] OK [1] ERROR
 *
 */
/*static int buscarLugarLibre(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayC[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

*/
/** \brief Incremente el Id al ser llamada
 *
 * \return int retorna el valor correspondiente al proximoId
 *
 */
static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief Fuerza el alta de cliente
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el array
 * \param nombre char* fuerza el nombre
 * \param apellido char* fuerza el apellido
 * \param cuit char* fuerza el cuit
 * \return int [0] OK [1] ERROR
 *
 */
int cliente_altaForzada(Cliente* arrayC,int limite, char* nombre, char* apellido, char* cuit)
{

    int retorno = -1;
    int i;

    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayC[i].nombre,nombre);
            strcpy(arrayC[i].apellido,apellido);
            strcpy(arrayC[i].cuit,cuit);
            arrayC[i].idCliente = proximoId();
            arrayC[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief retorna un entero que corresponde a la posicion del Id
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para cliente
 * \param idCliente int id del cliente buscado
 * \return int retorna un entero que corresponde a la posicion en la que se encuentra ese Id
 *
 */
int cliente_buscarPorId(Cliente* arrayC,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente==idCliente)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


