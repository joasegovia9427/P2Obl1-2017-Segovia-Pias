#ifndef DATOS_PREMIUM_H_INCLUDED
#define DATOS_PREMIUM_H_INCLUDED

#include "boolean.h"

typedef struct{
    boolean dp_ExportaAlExterior;
    int dp_CantidadPremiosObtenidos;
}datos_premium;

//Carga un struct de tipo datosPremium
void datos_premiumPROC_carga(datos_premium &dp);

//Despliega un struct de tipo datosPremium
void datos_premiumPROC_print(datos_premium dp);

//Selectoras

//Retorna boolean para saber si exporta o no
boolean datos_premiumFUNC_SelectisExportaExt(datos_premium dp);

//Retorna la cantidad de premios obtenidos en festivales
int datos_premiumFUNC_SelectCantPremios(datos_premium dp);

#endif // DATOS_PREMIUM_H_INCLUDED
