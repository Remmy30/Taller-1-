#include <stdio.h>

int main (){

    int ID, stock=0, unidadesVentas,opcion, cantidad_Reabastecer,total_nuevo;
    char nombre[50], continuar;
    float precioUnitario=0,ganancias=0,descuento,precioFinal,Valortotal;

    do{  
        printf("\n---MENU---\n");
        printf("1. Registrar datos del producto\n");
        printf("2. Venta de unidades\n");
        printf("3. Reabastecer producto\n");
        printf("4. Consultar informacion\n");
        printf("5. Finalizar el programa\n");
        printf ("\nIngrese la opcion que desea:");
        scanf ("\n%d",&opcion);
        switch (opcion)
        {
        case 1: //registrar los productos
            do{
                printf ("\nIngrese el ID:");
                scanf ("%d",&ID);
                if(ID<=0){
                    printf("No es un ID valido");
                }
            } while (ID<=0);
            printf ("\nIngrese el nombre del producto:");
            scanf ("\n%s",&nombre);
            do{ //stock
                printf("\nIngrese la cantidad del producto:");
                scanf ("\n%d",&stock);
                if (stock<=0)
                {
                    printf("La cantidad a ingresar debe ser mayor a 0");
                }
            } while (stock<=0);
            do{ //precio 
                printf ("\nIngrese precio unitario:");
                scanf ("\n%f",&precioUnitario);
                if (precioUnitario<=0)
                {
                    printf("No es un precio valido");
                }
            }while(precioUnitario<=0);
            break;
        
        case 2: //venta de unidades-stock
            printf ("\n Ingresar las unidades que desea vender:");
            scanf ("\n%d",&unidadesVentas);
            if (unidadesVentas<=0)
            {
                printf("La cantidad de unidades debe ser mayor a 0");
            }else{
                if (stock>=unidadesVentas)
                {
                    printf("\nSi hay stock ");
                    stock-=unidadesVentas;
                    printf("\nIngrese el descuento: ");
                    scanf("%f",&descuento);
                    if (descuento >= 0 && descuento < 100)
                    {
                        Valortotal = (precioUnitario * unidadesVentas);
                        // Precio con descuento aplicado
                        precioFinal = Valortotal - (Valortotal * descuento / 100);
                        ganancias += precioFinal;
                        printf("\nEl Precio total a pagar es: %.2f", precioFinal);
                        printf("\nEl total de ganancias obtenidas es: %.2f", ganancias);
                    }
                    else
                    {
                        printf("\nDescuento Invalido");
                    }
                }else{
                    printf("Necesita reabastecer el stock ");
                } 
            }
            break;
        case 3: //Reabastecer producto
            printf("Ingrese la cantidad de unidades: ");
            scanf("%d",&cantidad_Reabastecer);
            if (cantidad_Reabastecer>0)
            {
                stock+=cantidad_Reabastecer;
                printf("\nSe añadieron %d unidades", cantidad_Reabastecer);
                printf("\nstock actual es de: %d", stock);
            }else
            {
                printf("\n Se debe ingresar cantidades mayores a 0");
            }
            break;
        case 4: //Consultar informacion actualizada del producto  
            printf("\n--- INFORMACION DEL PRODUCTO ---\n");
            printf("ID: %d\n", ID);
            printf("Nombre: %s\n", nombre);
            printf("Stock: %d\n", stock);
            printf("Precio: %.2f\n", precioUnitario);
            printf("Ganancias: %.2f\n", ganancias);
            break; 
        case 5: //salir
            printf("\nfin del programa");
            break;
        default:
        printf("\nEscoja una opcion:  ");
        scanf("%d",&opcion);
        }
    }while(opcion<6 && opcion>0);
    return 0;
}

