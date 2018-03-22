#include "fecha.h"

boolean FechaCompletaFUNC_IsValid(FechaCompleta fecha){
    boolean isValid = FALSE;
    switch (fecha.mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (fecha.dia>=1 && fecha.dia<=31)
                isValid=TRUE;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (fecha.dia>=1 && fecha.dia<=30)
                isValid=TRUE;
            break;
        case 2:
            if (fecha.anio%4 == 0){
                if (fecha.dia>=1 && fecha.dia<=29)
                    isValid=TRUE;
            }else{
                if (fecha.dia>=1 && fecha.dia<=28)
                    isValid=TRUE;
            }
            break;
    }
    return isValid;
}

boolean FechaCompletaFUNC_IsValidRangoAnio(FechaCompleta fecha){
    boolean isValid = FALSE;
    int resultadoComparacion;
    if (fecha.anio >= 1900){
        resultadoComparacion = FechaComparaFechas(fecha, FechaCompletaFUNC_DevolverFechaDelDiaSys() );
        if (resultadoComparacion < 1){ //es menor o igual
             isValid = TRUE;
        }
    }
    return isValid;
}

FechaCompleta FechaCompletaFUNC_DevolverFechaDelDiaSys(){
    time_t tiempo = time(NULL);
    struct tm *tlocal = localtime(&tiempo);
    FechaCompleta fechaDeHOY;
    fechaDeHOY.dia  = tlocal->tm_mday;
    fechaDeHOY.mes  = tlocal->tm_mon+1;
    fechaDeHOY.anio = 1900+tlocal->tm_year;
    return fechaDeHOY;
}

void FechaCompletaPROC_Carga(FechaCompleta &fecha){
    printf("\nIngrese natural mayor a 0 para el d%sa: ", LETRA_i);
    scanf("%d",&fecha.dia);
    printf("\nIngrese natural mayor a 0 para el mes: ");
    scanf("%d",&fecha.mes);
    printf("\nIngrese natural mayor a 0 para el a%so: ", LETRA_n);
    scanf("%d",&fecha.anio);
}

void FechaCompletaPROC_Desplegado(FechaCompleta fecha){
    printf(" d%sa: %d/ mes: %d/ a%so: %d", LETRA_i,fecha.dia,fecha.mes, LETRA_n,fecha.anio);
}

int FechaCompletaFUNC_SelectoraDia(FechaCompleta fecha){
    return fecha.dia;
}

int FechaCompletaFUNC_SelectoraMes(FechaCompleta fecha){
    return fecha.mes;
}

int FechaCompletaFUNC_SelectoraAnio(FechaCompleta fecha){
    return fecha.anio;
}

int FechaComparaFechas(FechaCompleta fecha1, FechaCompleta fecha2){
    int val;
    if ( fecha1.anio < fecha2.anio )
        val = -1;
    else if ( fecha1.anio > fecha2.anio )
        val = 1; // en base a una exhaustiva investigacion en stackoverflow & github y segun material de la FING, la siguiente identacion esta correcta ;)
    else { // año igual
        if ( fecha1.mes < fecha2.mes )
            val = -1;
        else if ( fecha1.mes > fecha2.mes )
            val = 1;
        else { // mes igual
            if ( fecha1.dia < fecha2.dia )
                val = -1;
            else if ( fecha1.dia > fecha2.dia )
                val = 1;
            else // dia igual
                val = 0;
        }
    }
    return val;
}

