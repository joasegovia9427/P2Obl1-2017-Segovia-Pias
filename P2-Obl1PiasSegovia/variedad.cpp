#include "variedad.h"

void variedadPROC_Carga(variedad &v){
    boolean isValid;
    printf("***Ingreso de una variedad de pancho***");
    printf("\nIngrese c%sdigo variedad\n(solo ingrese n%smero natural, de lo contrario, autom%sticamente se ingresara un 0): ", LETRA_o, LETRA_u, LETRA_a);
    scanf("%d", &v.CodigoNumID);
    fflush(stdin);
    printf("\nIngrese nombre variedad : ");
    StringPROC_scan(v.CodigoNombID);
    fflush(stdin);
    do{
        isValid=FALSE;
        fflush(stdin);
        printf("\nIngrese la fecha de cuando se empez%s a fabricar : ", LETRA_o);
        FechaCompletaPROC_Carga(v.FechaComProd);
        isValid = FechaCompletaFUNC_IsValidRangoAnio(v.FechaComProd);
        if (isValid){
            isValid = FechaCompletaFUNC_IsValid(v.FechaComProd);
            if (!isValid){
                printf("\nError, fecha no valida, reingrese fecha.");
            }
        }
        else{
            printf("\nError, fecha no valida, reingrese fecha con un a%so posterior o igual a 1900\n y una fecha posterior o igual a la de la fecha de hoy.", LETRA_n);
        }
        fflush(stdin);
    } while (isValid == FALSE);
    printf("\nIngrese cantidad de unidades producidas por semana: ");
    scanf("%d", &v.CantUnidadesProducSemana);
    fflush(stdin);
    printf("\nIngrese tipo de variedad: ");
    tipoPROC_Carga(v.discriminanteTipo);
    switch(v.discriminanteTipo){
        case COMUN:
            printf("\nIngrese peso en gramos: ");
            scanf("%f", &v.etiqUnionVariedad.pesoEnGramos);
            break;
        case ESPECIAL:
            datos_especialPROC_carga(v.etiqUnionVariedad.datosEspecial);
            break;
        case PREMIUM:
            datos_premiumPROC_carga(v.etiqUnionVariedad.datosPremium);
            break;
    }
}

void variedadPROC_Print(variedad v){
    printf("\n\nC%sdigo: %d \nNombre:", LETRA_o, v.CodigoNumID);
    StringPROC_print(v.CodigoNombID);
    printf("\nFecha de comenzo de la producci%sn : %d/%d/%d", LETRA_o, v.FechaComProd.dia, v.FechaComProd.mes, v.FechaComProd.anio);
    printf("\nCantidad de unidades por semana: %d", v.CantUnidadesProducSemana);
    printf("\nTipo de variedad: ");
    tipoPROC_Print(v.discriminanteTipo);
    switch(v.discriminanteTipo){
        case COMUN:
            printf("\nPeso en gramos: %f", v.etiqUnionVariedad.pesoEnGramos);
            break;
        case ESPECIAL:
            datos_especialPROC_print(v.etiqUnionVariedad.datosEspecial);
            break;
        case PREMIUM:
            datos_premiumPROC_print(v.etiqUnionVariedad.datosPremium);
            break;
    }
}

void variedadPROC_PrintReducido(variedad v){
    printf("\n\nC%sdigo: %d \nNombre: ", LETRA_o, v.CodigoNumID);
    StringPROC_print(v.CodigoNombID);
    printf("\nFecha de comenzo de la producci%sn: %d/%d/%d", LETRA_o, v.FechaComProd.dia, v.FechaComProd.mes, v.FechaComProd.anio);
    printf("\nTipo de variedad: ");
    tipoPROC_Print(v.discriminanteTipo);
}

int variedadFUNC_SelectCodigoNumerico(variedad v){
    return v.CodigoNumID;
}

void variedadPROC_SelectCodigoNombre(variedad v, String &codigoNombre){
    StringPROC_CopiaElSegundoEnPrimero(codigoNombre, v.CodigoNombID);
}

FechaCompleta variedadFUNC_SelectFechaComProd(variedad v){
    return v.FechaComProd;
}

int variedadFUNC_SelectCantUnidadesProducSemana(variedad v){
    return v.CantUnidadesProducSemana;
}

tipo variedadFUNC_SelectdiscriminanteTipo(variedad v){
    return v.discriminanteTipo;
}

float variedadFUNC_SelectPeso(variedad v){
    return v.etiqUnionVariedad.pesoEnGramos;
}

datos_especial variedadFUNC_SelectDatosEspecial(variedad v){
    return v.etiqUnionVariedad.datosEspecial;
}

datos_premium variedadFUNC_SelectDatosPremium(variedad v){
    return v.etiqUnionVariedad.datosPremium;
}
