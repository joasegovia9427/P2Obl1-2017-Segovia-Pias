#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include "boolean.h"

typedef struct{
    int dia;
    int mes;
    int anio;
}FechaCompleta;

//Validar fecha
boolean FechaCompletaFUNC_IsValid(FechaCompleta fecha);

//Validar año acotamiento inferior, y acotamiento no mayor a la fecha actual, se hace en una fucnion aparte ya que este es una funcionalidad complementaria a la validacion normal
boolean FechaCompletaFUNC_IsValidRangoAnio(FechaCompleta fecha);

//Obtener Fecha del dia del sistema
FechaCompleta FechaCompletaFUNC_DevolverFechaDelDiaSys();

//Carga fecha por teclado
void FechaCompletaPROC_Carga(FechaCompleta &fecha);

//Despliega fecha
void FechaCompletaPROC_Desplegado(FechaCompleta fecha);

//Compara fechas
int FechaComparaFechas(FechaCompleta fecha1, FechaCompleta fecha2);
/**
    Función comparaFecha, devuelve:
     -1 si fecha1 < fecha2
      0 si fecha1 = fecha2
      1 si fecha1 > fecha2
**/

//Selectoras

//Retorna el dia de la fecha
int FechaCompletaFUNC_SelectoraDia(FechaCompleta fecha);

//Retorna el mes de la fecha
int FechaCompletaFUNC_SelectoraMes(FechaCompleta fecha);

//Retorna el año de la fecha
int FechaCompletaFUNC_SelectoraAnio(FechaCompleta fecha);

#endif // FECHA_H_INCLUDED
