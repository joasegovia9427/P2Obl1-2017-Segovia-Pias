#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
#include <stdio.h>
#include "boolean.h"

typedef enum {COMUN,ESPECIAL,PREMIUM} tipo;

//Carga un enum de tipo de variedad
void tipoPROC_Carga(tipo &t);

//Despliega una op. del enum de tipo de variedad
void tipoPROC_Print(tipo t);

#endif // TIPO_H_INCLUDED
