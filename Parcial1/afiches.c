#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "afiches.h"
#include "cliente.h"
#include "utn.h"

static int proximoId();
static int buscarLugarLibre(Afiches* array,int limite);


/** \brief Inicializa la estructura afiches
 * \param array Afiches* puntero a array
 * \param limite int limite definido para la estructura afiches
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_init(Afiches* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Muestra el debug de la estructura Afiches
 *
 * \param array Afiches* puntero a array
 * \param limite int limite definido para afiches
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_mostrarDebug(Afiches* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",array[i].idAfiche, array[i].nombreArchivo, array[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief Muestra afiches a partir del Idafiches que recibe
 *
 * \param array Afiches* puntero al array
 * \param limite int limite definido para afiches
 * \param idAfiches int ID de afiche que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_mostrarPorId(Afiches* array,int limite, int idAfiche)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==idCliente)
                printf("[RELEASE] -IdCliente: %d -Cant.archivos: %d -Nombre Archivo: %s -zona: %s -idArchivo: %d\n",array[i].idCliente, array[i].cantAfiches, array[i].nombreArchivo, array[i].zona, array[i].idAfiche);
        }
    }
    return retorno;
}

/** \brief Da de alta afiches
 *
 * \param array Afiches* puntero al array y limite de afiches
 * \param puntero a clientes y limite clientes
 * \return int [0] OK [1] ERROR
 *
 */
 int afiches_alta(Afiches* array,int limiteAfiches, Cliente* pBuffer, int limiteCliente)

{
    int retorno = -1;
    int i;
    char idCliente;
    int auxCant;
    char auxArchivo[51];
    char auxZona[51];

    if((limite > 0 && array != NULL) && (limiteCliente>0 && pBuffer !=NULL))
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nIngrese IdCliente: ","\nSolo numeros","El maximo es 11",pBuffer,100,2))
                do
                {
                    if(!getValidInt("\ncantidad de afiches ","\nDebe tener solo numeros","El maximo es de 999",auxCant,12,2) )
                    {
                        if(!getValidString("\nIngrese Nombre Archivo: ","\nError","El maximo es 50",auxArchivo,100,2))
                        {
                            if(!getValidString("\nIngrese la zona ","\nError","El maximo es 50",auxZona,100,2))
                            {
                                retorno = 0;
                                strcpy(array[i].cantAfiches,auxCant);
                                strcpy(array[i].nombreArchivo,auxArchivo);
                                strcpy(array[i].zona,auxZona);
                                array[i].idAfiche = proximoId();
                                array[i].isEmpty = 0;

                            }

                        }
                    }
                }
                while( array[i].idCliente==pBuffer[i].idCliente && pBuffer !=NULL && limiteC>0)

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


/** \brief Da de baja al fiche por el ID
 *
 * \param array Afichee* puntero al array
 * \param limite int limite definido para afiche
 * \param idCliente int Id del cliente que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int afiches_baja(Afiches* array,int limite, int idAfiche)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idAfiche==idAfiche)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica al afiche a partir de su Id
 *
 * \param array Afiche* puntero al array
 * \param limite int limite definido para el afiche
 * \param idafiche
 * \return int [0] OK [1] ERROR
 *
 */
 /*
int cliente_modificacion(Cliente* array,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==idCliente)
            {
                if(!getValidString("\nIngrese nombre? ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
                {
                    if(!getValidString("\nIngrese apellido? ","\nNo es un apellido","El maximo es de 50",auxApellido,50,2))
                    {
                        if(!getValidInt("\nIngrese CUIT ","\nDebe tener solo numeros","El maximo es de 11",auxCuit,12,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,auxNombre);
                            strcpy(array[i].apellido,auxApellido);
                            strcpy(array[i].cuit,auxCuit);
                            array[i].idCliente = proximoId();
                            array[i].estado=1;//estado  a cobrar
                            array[i].isEmpty = 0;
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
*/
/** \brief Ordena a los clientes de menor a mayo o de mayor a menor segun el "orden"
 *
 * \param array Cliente* puntero al array
 * \param limite int limite definido para el cliente
 * \param orden int [1] de menor a mayor, [0] de mayor a menor
 * \return int [0] OK [1] ERROR
 *
 */

/*int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
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

static int buscarLugarLibre(Afiches* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


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
int afiches_altaForzada(Afiches* array,int limite, char* cantidad, char* nombreArch, char* auxZona)
{

    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].cantAfiches,cantidad);
            strcpy(array[i].nombreArchivo,nombreArch);
            strcpy(array[i].zona,auxZona);
            array[i].idCliente = proximoId();
            array[i].isEmpty = 0;
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
int afiches_buscarPorIdAfiche(Afiches* array,int limite, int idAfiche)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idAfiche==idAfiche)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief listado de afiches a cobrar
 *
 * \param afiches y su limite, cliente y su limite
 * \param id e indice
 * \return [-1] si mal, [0] si ok
 *
 */

int afiches_cobrar(Afiches* arrayAfiches, int limiteAfiche, Cliente* pBuffer, int limiteCliente, int id, int *indice)
{
    int i,j;
    int retorno=-1;
    if(arrayAfi!=NULL&&limiteAfiche>0&& pBuffer!= NULL && limiteCliente>0)
        {
        for(i=0;i<limiteAfiche;i++)
        {
            if(arrayAfi[i].id==id)
            {
                for(j=0;j<limiteCli;j++)
                {
                    if(arrayAfi[i].idCliente==pBuffer[i].idCliente&& !arrayAfi[i].isEmpty)
                    {
                        printf("\nIdCliente: %d",pBuffer[i].idCliente);
                        printf("\nNombre: %s",pBuffer[i].nombre);
                        printf("\nApellido: %s",pBuffer[i].apellido);
                        printf("\nCuit: %s",pBuffer[i].cuit);
                        retorno=0;
                        *indice=i;
                        break;
                    }
                }
            }
        }
    }
return retorno;
}

/** \brief contador fiches cobrar segun IDCLIENTE
 *
 * \param afiches y su limite
 * \param id cliente
 * \return retorno
 *
 */


int afiches_aCobrarByIdCliente(Afiches* array,int limite,int idCliente)
{
    int i;
    int retorno=0;
    for(i=0;i<limite;i++){
        if(array[i].idCliente==idCliente&& array[i].estado==1 && !array[i].isEmpty)
            {
            retorno++;
        }
    }
return retorno:
}

/** \brief lista afiches
 *
 * \param afiches
 * \param limite afiches
 * \return [-1] si mal, [0]si ok
 *
 */

int afiches_listado(Afiches* array,int limite)
{
    int i;
    int retorno=-1;
    if(array!=NULL&&limite>0)
        {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0)
                {
                retorno=0;
                printf("\nIdCliente: %d",array[i].idCliente);
                printf("\nIdAfiche: %d",array[i].idAfiche);
                printf("\nCantidad Afiches: %d",array[i].cantAfiches);
                printf("\nNombreArchivo: %s",array[i].nombreArchivo);
                printf("\nEStado (0  cobrada, 1 por cobrar): %s",array[i].estado);
                switch (array[i].zona)
                {
                    case 1:
                        printf("\nCABA");
                        break;
                    case 2:
                        printf("\nZona oeste");
                        break;
                    case 3:
                        printf("\nZona sur");
                    break;
                }
                           }
        }
    }
    return retorno;
}

int afiches_cambiarEstado(Afiches* array, int limite)
{
    int i;
    int retorno =-1;
    if(array!=NULL && limite>0)
    {
        if(array[i].estado==1)
        {
           array[i].estado=0;
           printf("EStado de la venta: Cobrada");
        }
    }
}


/** \brief editar afiches
 *
 * \param afiche y su limite
 * \param id, cantidad de afiches y las zona
 * \return [-1] si mal, [0] is ok
 *
 */

int afiches_editar(Afiches* array,int id,int limite,int cantAfiches,int zona)
{
    int i;
    int retorno=-1;
    if(array!=NULL && limite>0 )
        {
        for (i=0;i<limite;i++)
        {
            if(array[i].id==id)
            {
                array[i].cantAfiches=cantAfiches;
                array[i].zona=zona;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
