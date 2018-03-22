#ifndef FABRICA_H_INCLUDED
#define FABRICA_H_INCLUDED

#include "variedad.h"

const int MAXvariedad=30;

typedef struct{
    variedad arreVariedades[MAXvariedad];
    int tope;
}arregloVariedades;

//a•Procedimiento que inicialice el tope del struc en 0 y devuelva para poder ejecutar las funciones futuras
void arregloVariedadesPROC_inicializacion(arregloVariedades &v);

//b•Procedimeinto que ingemente el tope
void arregloVariedadesPROC_topeMasUno(arregloVariedades &v);

//c•Procedimeinto que decremente el tope
void arregloVariedadesPROC_topeMenosUno(arregloVariedades &v);

//d•Listado de todo el arreglo detalladamente
void arregloVariedadesPROC_printTodoDetallado(arregloVariedades v);

//e•Dado un código identificador número, determinar si existe alguna variedad de pancho ya registrada con ese código.
boolean arregloVariedadesFUNC_isExisteVariedadIDnumero(arregloVariedades v, int codigoNumID);

//f•Dado un código identificador nombre de variedad de pancho, determinar si existe alguna variedad de pancho ya registrada con ese nombre.
boolean arregloVariedadesFUNC_isExisteVariedadIDnombre(arregloVariedades v, String codigoNombID);

//1.1 Ingresar un nueva variedad de pancho no registrada previamente. Las variedades de panchos deben quedar ordenadas cronológicamente por fecha en que se comenzó a fabricar.
void arregloVariedadesPROC_carga(arregloVariedades &arr_v, variedad v, boolean &isCargadoCorrecto); //se validara con los metodos anteriores

//Ordenar por fechas - Auxilia a la opcion anterior
void arregloVariedadesPROC_ordenarPorFechasBB(arregloVariedades &v);

//1.2 Dado un código identificador numérico, dar de baja la variedad de pancho correspondiente, eliminándola del sistema. Las restantes variedades de panchos deben permanecer almacenadas en el orden que están.
void arregloVariedadesPROC_bajaIDcodigo(arregloVariedades &v, int codigoNumID);

//3.1 Listar por pantalla código, nombre, fecha y tipo de variedad, de todas las variedades de panchos registrados.
void arregloVariedadesPROC_listadoTodoSimple(arregloVariedades v);

//3.2 Dado un código identificador numérico de variedad de pancho, listar detalladamente todos los datos de la variedad de pancho correspondiente.
void arregloVariedadesPROC_listadoUnidadDetallado(arregloVariedades v, int codigoNumID);

//3.3 Devolver la cantidad de variedades de panchos de cada tipo de variedad registrados actualmente.
void  arregloVariedadesPROC_cantidadesVporTipos(arregloVariedades v, int &cantComun, int &cantEspecial, int &cantPremium);//validar si efectivametne es un proc

//3.4 Obtener código y el nombre de una variedad de pancho con la mayor cantidad de unidades por semana.
void arregloVariedadesPROC_devolverDatosVarMayorProd(arregloVariedades arreVar, int &codigoNumID, String &codigoNombID, int &mayorCantProd);

//3.5 Dado un ingrediente, contar cuántas variedades de panchos, de tipo especial, lo tienen como ingrediente principal.
int arregloVariedadesFUNC_cantidadesVespConIngrediente(arregloVariedades v, String ingredientePrin);

//3.6 Dada una cantidad, buscar la primer variedad de pancho, de tipo Premium, que tenga al menos esa cantidad de premios. En caso de que exista, devolver código y nombre de la variedad de pancho correspondiente.
void arregloVariedadesPROC_devolverVariedadSegunPremios(arregloVariedades v, int cantidadPremios, int &codigoNumID, String &codigoNombID, int &cantidadEfectiva);

//3.7 Dados un código identificador numérico de variedad de pancho, un entero n > 0 y un valor booleano que indica si es incremento o decremento, incrementar o decrementar (según corresponda) en n unidades la cantidad de unidades de panchos, que esa variedad de pancho, produce semanalmente. En caso de que sea decremento y que n supere la cantidad de unidades actualmente vendidas, se pondrá cero (0) como resultado.
void arregloVariedadesPROC_incORdecCantidadProdc(arregloVariedades &v, int codigoNumID, int enteroMayorAcero, boolean incORdec);

//Selectoras

//Retorna un item del struct
variedad arregloVariedadesFUNC_SelectArregloVariedadesItem(arregloVariedades v, int codigoNumID);

//Retorna el tope del struct
int arregloVariedadesFUNC_SelectTope(arregloVariedades v);

#endif // FABRICA_H_INCLUDED
