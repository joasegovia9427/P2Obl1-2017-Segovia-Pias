#include "datos_especial.h"

void datos_especialPROC_carga(datos_especial &de){
    printf("\nIngrese nombre del ingrediente principal: ");
    StringPROC_scan(de.de_NombreIngredientePrincipal);
    printf("\nIngrese cantidad de ingredientes: ");
    scanf("%d",&de.de_CantidadIngredientes);
}

void datos_especialPROC_print(datos_especial de){
    printf("\nNombre deliIngrediente principal: ");
    StringPROC_print(de.de_NombreIngredientePrincipal);
    printf("\nCantidad de ingredientes: %d",de.de_CantidadIngredientes);
}

void datos_especialPROC_SelectNombreIngP(datos_especial de, String &nombreIngP){
    StringPROC_CopiaElSegundoEnPrimero(nombreIngP, de.de_NombreIngredientePrincipal);
}

int datos_especialFUNC_SelectCantIngres(datos_especial de){
    return de.de_CantidadIngredientes;
}
