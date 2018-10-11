#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "afiches.h"
#include "informes.h"
#define QTY 100
#define VENTAS 1000

int main()
{
    Cliente clientes[QTY];
    Afiches afiches[VENTAS];


    int auxId;
    int menu;
    int auxVentas;
    int auxZona;
    int auxIndice;


    cliente_init(clientes,QTY);
    afiches_init(afiches,VENTAS);

    cliente_altaForzada(clientes,QTY,"maria","Gomez",27356258);
    cliente_altaForzada(clientes,QTY, "sol","rhy",13569578);
    cliente_altaForzada(clientes,QTY, "paz","miro",56753102);
    afiches_altaForzada(afiches,VENTAS, 10,"red","1");
    afiches_altaForzada(afiches,VENTAS,600,"blue",3);
    afiches_altaForzada(afiches,VENTAS,50,"pink",1000);

    do
    {
        getValidInt("1.Alta\n2.Modificar cliente\n3.Baja cliente\n4.Vender\n5.Editar\n6.Cobrar\n7.Imprimir clientes\n8.Informar\n9.Salir\n","\nError\n",&menu,1,9,1);
        switch(menu)
        {
        case 1:
            cliente_alta(clientes,QTY);
            break;
        case 2:
            getValidInt("\nIngrese IdCliente\n","Error",&auxId,0,999,2);
            cliente_modificacion(clientes,QTY,auxId);
            break;
        case 3:
            getValidInt("\nIngrese IdCliente\n","Error",&auxId,0,999,2);
            cliente_baja(clientes,QTY,auxId);
            break;
        case 4:
            getValidInt("\nIngrese IdCliente\n","Error",&auxId,0,999,2);
            afiches_alta(afiches,VENTAS,clientes,QTY);
            break;
        case 5:
            afiches_listado(afiches,VENTAS);
            getValidInt("\nIngrese IdCliente\n","Error",&auxId,0,999,2);
            afiches_editar(afiches,auxId,VENTAS,auxVentas,auxZona);
            break;
        case 6:
            afiches_listado(afiches,VENTAS):
            getValidInt("\nIngrese IdCliente\n","Error",&auxId,0,999,2);
            afiches_cobrar(afiches,VENTAS,clientes,QTY, auxId, auxIndice);
            afiches_cambiarEstado(afiches,VENTAS);
            break;
        case 7:
            informe_clientesAcobrar(clientes, QTY,afiches,VENTAS);
            break;
            case 8:
            getValidInt("1.Cl + ventas a cobrar\n2.Cl + ventas cobradas\n3.Cl + ventas\n4.Cl + afiches cobrar\n5.Cl + afiches\n6.zona - afiches\n7.cl-1000af\n8.af xzona\n9.venta x zona\n10.af prom Cl",)
            switch
            {

            }
            break;
        }
    }while(menu !=9);
    return 0;
}
