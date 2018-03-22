#ifndef DATOS_ESPECIAL_H_INCLUDED
#define DATOS_ESPECIAL_H_INCLUDED

#include "string.h"

typedef struct{
    String de_NombreIngredientePrincipal;
    int de_CantidadIngredientes;
}datos_especial;

//Carga un struct datoEspecial
void datos_especialPROC_carga(datos_especial &de);

//Despliega un struct datoEspecial
void datos_especialPROC_print(datos_especial de);

//Selectoras

//Retora el string nombre de ingrediente principal
void datos_especialPROC_SelectNombreIngP(datos_especial de, String &nombreIngP);

//Retora el int cantidad de ingredientes
int datos_especialFUNC_SelectCantIngres(datos_especial de);

#endif // DATOS_ESPECIAL_H_INCLUDED
