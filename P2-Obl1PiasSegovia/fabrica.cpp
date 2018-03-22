#include "fabrica.h"

void arregloVariedadesPROC_inicializacion(arregloVariedades &v){//a
    v.tope = 0;
}

void arregloVariedadesPROC_topeMasUno(arregloVariedades &v){//b
    v.tope = v.tope + 1;
}

void arregloVariedadesPROC_topeMenosUno(arregloVariedades &v){//c
    v.tope = v.tope - 1;
}

void arregloVariedadesPROC_printTodoDetallado(arregloVariedades v){//d
    if (v.tope > 0){
        for(int i=0; i<v.tope;i++){
            variedadPROC_Print(v.arreVariedades[i]);
        }
    }
    else{
        printf("\nNo hay variedades para mostrar");
    }
}

boolean arregloVariedadesFUNC_isExisteVariedadIDnumero(arregloVariedades v, int codigoNumID){//e
    int i=0;
    boolean existe = FALSE;
    do{
        if( variedadFUNC_SelectCodigoNumerico(v.arreVariedades[i]) == codigoNumID){
            existe = TRUE;
        }
        i++;
    }while(i<v.tope && existe != TRUE);
    return existe;
}

boolean arregloVariedadesFUNC_isExisteVariedadIDnombre(arregloVariedades v, String codigoNombID){//f
    int i=0;
    boolean existe=FALSE;
    String valor_obtenido;
    do{
        variedadPROC_SelectCodigoNombre(v.arreVariedades[i], valor_obtenido);
        if(StringFUNC_isSonIguales(valor_obtenido,codigoNombID)){
            existe = TRUE;
        }
        i++;
    }while(i<v.tope && existe != TRUE);
    return existe;
}

void arregloVariedadesPROC_carga(arregloVariedades &arr_v, variedad v, boolean &isCargadoCorrecto){//1.1
    if(arr_v.tope < MAXvariedad){
        arr_v.arreVariedades[arr_v.tope] = v;
        arregloVariedadesPROC_topeMasUno(arr_v);
        isCargadoCorrecto = TRUE;
    }else{
        isCargadoCorrecto = FALSE;
    }
}

void arregloVariedadesPROC_ordenarPorFechasBB(arregloVariedades &v){
    int resultadoDeComparacion;
    FechaCompleta f1, f2;
    variedad temp;
    for(int i=0; i<v.tope;i++){
        for (int j=0;j<v.tope-1;j++){
            f1 = variedadFUNC_SelectFechaComProd(v.arreVariedades[j]);
            f2 = variedadFUNC_SelectFechaComProd(v.arreVariedades[j+1]);
            resultadoDeComparacion = FechaComparaFechas(f1,f2);
            if (resultadoDeComparacion == 1){
                temp = v.arreVariedades[j];
                v.arreVariedades[j] = v.arreVariedades[j+1];
                v.arreVariedades[j+1] = temp;
            }

        }
    }

}

void arregloVariedadesPROC_bajaIDcodigo(arregloVariedades &v, int codigoNumID){//1.2
    int i=0;
    do{
        if(variedadFUNC_SelectCodigoNumerico(v.arreVariedades[i]) == codigoNumID){
            for(int k=i;k<v.tope;k++){
                    v.arreVariedades[k] = v.arreVariedades[k+1];
            }
            arregloVariedadesPROC_topeMenosUno(v);
        }
        i++;
    }while(i<v.tope);
}

void arregloVariedadesPROC_listadoTodoSimple(arregloVariedades v){//3.1
    if (v.tope > 0){
        for(int i = 0; i<v.tope;i++){
            variedadPROC_PrintReducido(v.arreVariedades[i]);
        }
    }
    else{
        printf("\nNo hay variedades para mostrar");
    }
}
void arregloVariedadesPROC_listadoUnidadDetallado(arregloVariedades v, int codigoNumID){//3.2
    int i=0;
    boolean existe = FALSE;
    if (v.tope > 0){
        do{
            if(variedadFUNC_SelectCodigoNumerico(v.arreVariedades[i]) == codigoNumID){
                existe = TRUE;
                variedadPROC_Print(v.arreVariedades[i]);
            }
            i++;
        }while(i<v.tope && existe == FALSE);
    }
    else{
        printf("\nNo hay variedades para mostrar");
    }
}

void  arregloVariedadesPROC_cantidadesVporTipos(arregloVariedades v, int &cantComun, int &cantEspecial, int &cantPremium){//3.3
    cantComun = 0;
    cantEspecial = 0;
    cantPremium = 0;
    for(int i=0;i<v.tope;i++){
        switch(v.arreVariedades[i].discriminanteTipo){
            case COMUN:
                cantComun++;
            break;
            case ESPECIAL:
                cantEspecial++;
            break;
            case PREMIUM:
                cantPremium++;
            break;
        }
    }
}

void arregloVariedadesPROC_devolverDatosVarMayorProd(arregloVariedades arreVar, int &codigoNumID, String &codigoNombID, int &mayorCantProd){//3.4
    codigoNumID = 0;
    mayorCantProd = 0;
    for(int i = 0; i<arreVar.tope;i++){
        if(variedadFUNC_SelectCantUnidadesProducSemana(arreVar.arreVariedades[i]) > mayorCantProd){
            mayorCantProd = variedadFUNC_SelectCantUnidadesProducSemana(arreVar.arreVariedades[i]);
            codigoNumID = variedadFUNC_SelectCodigoNumerico(arreVar.arreVariedades[i]);
            variedadPROC_SelectCodigoNombre(arreVar.arreVariedades[i],codigoNombID);
        }
    }
}

int arregloVariedadesFUNC_cantidadesVespConIngrediente(arregloVariedades v, String ingredientePrin){//3.5
    int cantidad = 0;
    for(int i=0; i<v.tope;i++){
        if(StringFUNC_isSonIguales(v.arreVariedades[i].etiqUnionVariedad.datosEspecial.de_NombreIngredientePrincipal , ingredientePrin)){
            cantidad++;
        }
    }
    return cantidad;
}

void arregloVariedadesPROC_devolverVariedadSegunPremios(arregloVariedades v, int cantidadPremios, int &codigoNumID, String &codigoNombID, int &cantidadEfectiva){//3.6
    codigoNumID = 0;
    int i = 0;
    boolean existe = FALSE;
    do{
        if(v.arreVariedades[i].etiqUnionVariedad.datosPremium.dp_CantidadPremiosObtenidos >= cantidadPremios){
            existe = TRUE;
            codigoNumID = variedadFUNC_SelectCodigoNumerico(v.arreVariedades[i]);
            variedadPROC_SelectCodigoNombre(v.arreVariedades[i],codigoNombID);
            cantidadEfectiva = datos_premiumFUNC_SelectCantPremios(variedadFUNC_SelectDatosPremium(v.arreVariedades[i]));
        }
        i++;
    }while(existe == FALSE && i<v.tope);
}

void arregloVariedadesPROC_incORdecCantidadProdc(arregloVariedades &v, int codigoNumID, int enteroMayorAcero, boolean incORdec){//3.7
    boolean existe = FALSE;
    int i=0;
    do{
        if(variedadFUNC_SelectCodigoNumerico(v.arreVariedades[i]) == codigoNumID){
            existe = TRUE;
            if(incORdec == TRUE){
                v.arreVariedades[i].CantUnidadesProducSemana =  v.arreVariedades[i].CantUnidadesProducSemana + enteroMayorAcero;
            }else{
                if(v.arreVariedades[i].CantUnidadesProducSemana >= enteroMayorAcero){
                    v.arreVariedades[i].CantUnidadesProducSemana =  v.arreVariedades[i].CantUnidadesProducSemana - enteroMayorAcero;
                }else{
                    v.arreVariedades[i].CantUnidadesProducSemana = 0;
                }
            }
        }
        i++;
    }while(i<v.tope && existe != TRUE);
}

variedad arregloVariedadesFUNC_SelectArregloVariedadesItem(arregloVariedades v, int codigoNumID){
    int i=0;
    variedad vItem;
    boolean encontrado = FALSE;
    do{
        if (variedadFUNC_SelectCodigoNumerico(v.arreVariedades[i]) == codigoNumID){
            vItem = v.arreVariedades[i];
            encontrado = TRUE;
        }
        i++;
    }while(i<v.tope && encontrado != TRUE);
    return vItem;
}

int arregloVariedadesFUNC_SelectTope(arregloVariedades v){
    return v.tope;
}
