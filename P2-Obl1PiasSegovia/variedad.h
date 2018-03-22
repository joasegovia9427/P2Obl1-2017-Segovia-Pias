#ifndef VARIEDAD_H_INCLUDED
#define VARIEDAD_H_INCLUDED

#include "datos_especial.h"
#include "datos_premium.h"
#include "fecha.h"
#include "tipo.h"
#include "string.h"

typedef struct{
    int CodigoNumID;
    String CodigoNombID;
    FechaCompleta FechaComProd;
    int CantUnidadesProducSemana;
    tipo discriminanteTipo;
    union{
        float pesoEnGramos;
        datos_especial datosEspecial;
        datos_premium datosPremium;
    }etiqUnionVariedad;
}variedad;

//Carga una variedad
void variedadPROC_Carga(variedad &v);

//Despliega una variedad con todos los datos (detalle) del struct
void variedadPROC_Print(variedad v);

//Despliega una variedad con algunos datos (reducido) del struct
void variedadPROC_PrintReducido(variedad v);

//Selectoras

//Retorna el codigo numerico identificador
int variedadFUNC_SelectCodigoNumerico(variedad v);

//Retorna el codigo nombre identificador
void variedadPROC_SelectCodigoNombre(variedad v, String &codigoNombre);

//Retorna la fecha de comienzo de produccion
FechaCompleta variedadFUNC_SelectFechaComProd(variedad v);

//Retorna la cantidad de unidades producidas por semana
int variedadFUNC_SelectCantUnidadesProducSemana(variedad v);

//Retorna retorna el enumerado discriminante tipo para la union
tipo variedadFUNC_SelectdiscriminanteTipo(variedad v);

//Retorna el peso correspondiente al primer tipo de la union
float variedadFUNC_SelectPeso(variedad v);

//Retorna el struct datos especiales correspondiente al segundo tipo de la union
datos_especial variedadFUNC_SelectDatosEspecial(variedad v);

//Retorna el struct datos premium correspondiente al tercer tipo de la union
datos_premium variedadFUNC_SelectDatosPremium(variedad v);

#endif // VARIEDAD_H_INCLUDED
