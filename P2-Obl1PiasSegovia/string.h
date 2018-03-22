#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"

const int MAX = 80;

typedef char String[MAX];

//Calcula el largo de un arreglo de caracteres String
int StringFUNC_largo(String palabra1);

//Despliega un arreglo de caracteres String
void StringPROC_print(String palabra1);

//Lee y carga un arreglo de caracteres String
void StringPROC_scan(String &palabra1);

//Calcula si los arreglos son iguales
boolean StringFUNC_isSonIguales(String palabra1, String palabra2);

//Copia el segundo arreglo en el primero, de los recibidos como parametros
void StringPROC_CopiaElSegundoEnPrimero(String palabra1, String palabra2);

#endif // STRING_H_INCLUDED
