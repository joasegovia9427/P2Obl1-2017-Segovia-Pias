#include "menus.h"

void menusPROC_menuPrincipal(int &opcion){
    fflush(stdin);
    printf("\n**********Men%s de Opciones Principales**********\n\n", LETRA_u);
    printf("Seleccione un numero como opci%sn del men%s:", LETRA_o, LETRA_u);
    printf("\n1- Registrar una nueva variedad de pancho.");
    printf("\n2- Dar de baja una variedad de pancho que deja de producirse.");
    printf("\n3- Men%s de listados y consultas.", LETRA_u);
    printf("\n4- Salir del programa.\nOpci%sn: ", LETRA_o);
    scanf("%d",&opcion);
}

void menusPROC_menuOpcion3(int &opcion3){
    fflush(stdin);
    printf("\n\n**********Men%s de Opciones para listados y consultas**********\n\n", LETRA_u);
    printf("Seleccione un n%smero como opci%sn del men%s:", LETRA_u, LETRA_o, LETRA_u);
    printf("\n1. Listado reducido (c%sdigo, nombre, fecha y tipo de variedad) de todas las variedades de pancho registrados, ordenado cronol%sgicamente por fecha en que se comenz%s a fabricar.", LETRA_o, LETRA_o, LETRA_o);
    printf("\n2. Listado detallado de una variedad de pancho, dado su c%sdigo identificador.", LETRA_o);
    printf("\n3. Obtener la cantidad de variedades de pancho ingresadas de cada variedad.");
    printf("\n4. Obtener c%sdigo y el nombre de una variedad de pancho con la mayor cantidad de unidades por semana.", LETRA_o);
    printf("\n5. Dado un ingrediente, contar cu%sntas variedades de panchos, de tipo Especial, lo tienen como ingrediente principal.", LETRA_a);
    printf("\n6. Dada una cantidad de premios, buscar una variedad de pancho, de tipo Premium, con al menos esa cantidad de premios.");
    printf("\n7. Dado un c%sdigo de variedad de pancho, incrementar o decrementar su cantidad de unidades por semana.", LETRA_o);
    printf("\n8. Salir del men%s.\nOpci%sn: ", LETRA_u, LETRA_o);
    scanf("%d",&opcion3);
}

void PROC_mensajeErrorCargaVacia(){
    fflush(stdin);
    printf("\n***Error, para esta opci%sn debe tener cargado el listado previamente con la opci%sn 1.***", LETRA_o, LETRA_o);
    PROC_LimpiarYPausa();
}

void PROC_LimpiarYPausa(){
    char limpiar;
    fflush(stdin);
    printf("\n\nPresione enter para continuar ");
    scanf("%c",&limpiar);
    system(LIMPIAR);
}
