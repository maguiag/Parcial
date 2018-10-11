#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "informes.h"


/** \brief cliente con mas ventas a cobrar
*
* \param arrayCliente Cliente* clientes
* \param limite  para cliente
* \param Afiches* puntero a afiches
* \param limite clientes, limite afiches int limite definido para publicacion
* \return int [-1] ERROR [0] OK
*
*/

int informe_clienteMasACobrar(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches)
{
    int i;
    int j;
    int retorno =-1;
    int contadorVentas=0;
    int masAcobrar=0;
    int idCliente;
    int indiceCliente;

    if(arrayC != NULL && pBuffer !=NULL && limiteClientes>0 &&limiteAfiches>0)
    {
        retorno = 0;
        for(i=0; i<limiteClientes; i++)
        {
            if(!arrayC[i].isEmpty)
            {

                contadorVentas=0;

                for(j=0; j<limiteAfiches; j++)
                {
                    if(!pBuffer[j].isEmpty && pBuffer[j].idCliente == idCliente && pBuffer[j].estado==0)
                    {
                        contadorVentas++;
                    }
                }
                if(contadorVentas>masAcobrar)
                {
                    masAcobrar=contadorVentas;
                    indiceCliente =i;
                }
                // printf("[RELEASE]-IdCliente: %d -Nombre: %s -Apellido: %s -Cuit: %s -Cantidad de Ventas %d\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit,contadorVentas);
            }
            //contadorVentas;
        }
        cliente_mostrarPorId(arrayC,limiteClientes,indiceCliente);
        printf("El cliente con mas avisos a cobrar es: %d",indiceCliente);
    }
    return retorno;
}


/** \brief cliente con mas ventas cobradas
*
* \param arrayCliente Cliente* clientes
* \param limite  para cliente
* \param Afiches* puntero a afiches
* \param limite clientes, limite afiches int limite definido para publicacion
* \return int [-1] ERROR [0] OK
*
*/

int informe_clienteMasCobradas(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches)
{

    int i;
    int j;
    int retorno =-1;
    int contadorPagos;
    int masCobradas=0;
    int idCliente;
    int indiceCliente;

    if(arrayC != NULL && pBuffer !=NULL && limiteClientes>0 &&limiteAfiches>0)
    {
        retorno = 0;
        for(i=0; i<limiteClientes; i++)
        {
            if(!arrayC[i].isEmpty)
            {

                contadorPagos=0;

                for(j=0; j<limiteAfiches; j++)
                {
                    if(!pBuffer[j].isEmpty && pBuffer[j].idCliente == idCliente && pBuffer[j].estado==1)
                    {
                        contadorPagos++;
                    }
                }
                if(contadorPagos>masCobradas)
                {
                    masCobradas=contadorPagos;
                    indiceCliente =i;
                }
                // printf("[RELEASE]-IdCliente: %d -Nombre: %s -Apellido: %s -Cuit: %s -Cantidad de Ventas %d\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit,contadorVentas);
            }
            //contadorVentas;
        }
        cliente_mostrarPorId(arrayC,limiteClientes,indiceCliente);
        printf("El cliente con mas avisos cobrados es: %d",indiceCliente);
    }
    return retorno;


}


/** \brief cliente con la mayor cantidad de ventas
*
* \param arrayCliente Cliente* clientes
* \param limite  para cliente
* \param Afiches* puntero a afiches
* \param limite clientes, limite afiches int limite definido para publicacion
* \return int [-1] ERROR [0] OK
*
*/
int informe_ventasTotales(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches);
{

    int i;
    int j;
    int retorno =-1;
    int indiceCliente;
    int contadorVentasT;
    int conMasVentas=0;

    if(arrayC != NULL && pBUffer !=NULL && limiteClientes>0 &&limiteAfiches>0)
    {
        retorno = 0;
        for(i=0; i<limiteClientes; i++)
        {
            if(!arrayC[i].isEmpty)
            {

                contadorVentasT=0;

                for(j=0; j<limiteAfiches; j++)
                {
                    if(!pBUffer[j].isEmpty && pBuffer[j].idCliente==idCliente)
                    {
                      if(pBuffer[j].estado==1 || pBUffer[j].estado==0)
                      {
                        contadorVentasT++;
                      }

                    }
                }
                if(contadorVentasT>conMasVentas)
                {
                    conMasVentas=contadorVentasT;
                    indiceCliente =i;
                }
                // printf("[RELEASE]-IdCliente: %d -Nombre: %s -Apellido: %s -Cuit: %s -Cantidad de Ventas %d\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit,contadorVentas);
            }
            //contadorVentas;
        }
        cliente_mostrarPorId(arrayC,limiteClientes,indiceCliente);
        printf("El cliente con mas ventas es: %d",indiceCliente);
    }
    return retorno;


}

int informe_clienteMasAfichesCobrar(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches)
{// tine que considedar la cant de afiches

    int i;
    int j;
    int retorno =-1;
    int indiceCliente;
    int totalA=0;
    int contadorAfiches;
    int conMasAfiches=0;


    if(arrayC != NULL && pBUffer !=NULL && limiteClientes>0 &&limiteAfiches>0)
    {
        retorno = 0;
        for(i=0; i<limiteClientes; i++)
        {
            if(!arrayC[i].isEmpty)
            {

                 for(j=0; j<limiteAfiches; j++)
                {
                    if(!pBuffer[j].isEmpty && pBuffer[j].idCliente==idCliente)
                    {
                      if(if pBuffer[j].estado==1 &&  pBuffer[j].cantAfiches>0 )
                      {
                        totalA= &cantAfiches;// no me acuerdooooo
                        // esto es cualquieraaaaaaaaaaa
                      }

                    }
                }
                if(totalA>conMasAfiches)
                {
                    conMasAfiches=totalA;
                    indiceCliente =i;
                }
                // printf("[RELEASE]-IdCliente: %d -Nombre: %s -Apellido: %s -Cuit: %s -Cantidad de Ventas %d\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit,contadorVentas);
            }
            //contadorVentas;
        }
        cliente_mostrarPorId(arrayC,limiteClientes,indiceCliente);
        printf("El cliente con mas afiches a cobrar es: %d",indiceCliente);
    }
    return retorno;


}

/** \brief cliente que compro mas afiches
*
* \param arrayCliente Cliente* clientes
* \param limite  para cliente
* \param Afiches* puntero a afiches
* \param limite clientes, limite afiches int limite definido para publicacion
* \return int [-1] ERROR [0] OK
*
*/

int informe_clienteComproMasAfiches(Cliente* arrayC, int limiteClientes, Afiches* pBuffer, int limiteAfiches);


{// tine que considedar la cant de afiches

    int i;
    int j;
    int retorno =-1;
    int indiceCliente;
    int totalA=0;
    int contadorAfiches;
    int conMasAfiches=0;


    if(arrayC != NULL && pBUffer !=NULL && limiteClientes>0 &&limiteAfiches>0)
    {
        retorno = 0;
        for(i=0; i<limiteClientes; i++)
        {
            if(!arrayC[i].isEmpty)
            {

                 for(j=0; j<limiteAfiches; j++)
                {
                    if(!pBuffer[j].isEmpty && pBuffer[j].idCliente==idCliente && pBuffer[j].cantAfiches>0)
                    {
                      if(if pBuffer[j].estado==1 ||  pBuffer[j].estado==0 )
                      {
                        totalA= &cantAfiches;// no me acuerdooooo
                        // esto es cualquieraaaaaaaaaaa
                      }

                    }
                }
                if(totalA>conMasAfiches)
                {
                    conMasAfiches=totalA;
                    indiceCliente =i;
                }
                // printf("[RELEASE]-IdCliente: %d -Nombre: %s -Apellido: %s -Cuit: %s -Cantidad de Ventas %d\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit,contadorVentas);
            }
            //contadorVentas;
        }
        cliente_mostrarPorId(arrayC,limiteClientes,indiceCliente);
        printf("El cliente que compro mas afiches es: %d",indiceCliente);
    }
    return retorno;


}



