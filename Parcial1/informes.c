#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "informes.h"

/** \brief imprime listado a cobrar
 *
 * \param cliente y su limite
 * \param afiches y su limite
 * \return [-1] si mal, [0] si ok
 *
 */

int informe_clientesAcobrar(Cliente* array, int limiteClientes, Afiches* pBuffer, int limiteAfiches)
{

    int i;
    int retorno=-1;

    int afichesAcobrar=0;;
    if(array!=NULL && limiteClientes>0 && pBuffer!=NULL && limiteAfiches>0)
        {
        for(i=0;i<limiteClientes;i++)
            {
            if(!pBuffer[i].isEmpty)
            {
                printf("\nIdCLIENTE: %d",pBuffer[i].idCliente);
                printf("\nNombre: %s",pBuffer[i].nombre);
                printf("\nApellido: %s",pBuffer[i].apellido);
                printf("\nCuit: %s",pBuffer[i].cuit);
                afichesAcobrar = afiches_aCobrarByIdCliente(Afiches,VENTAS,pBuffer[i].idCliente);
                printf("\nVentas a cobrar: %d",aCobrar);
                retorno=0;
            }
        }
    }
return retorno;
}
