#include "datos_premium.h"

void datos_premiumPROC_carga(datos_premium &dp){
    printf("\nIngrese si esta variedad es exportada al exterior: ");
    booleanPROC_carga(dp.dp_ExportaAlExterior);
    printf("\nIngrese cantidad de premios obtenidos: ");
    scanf("%d", &dp.dp_CantidadPremiosObtenidos);
}

void datos_premiumPROC_print(datos_premium dp){
    printf("\nVariedad exportada al exterior: ");
    booleanPROC_mostrar(dp.dp_ExportaAlExterior);
    printf("\nCantidad de premios obtenidos: %d", dp.dp_CantidadPremiosObtenidos);
}

boolean datos_premiumFUNC_SelectisExportaExt(datos_premium dp){
    return dp.dp_ExportaAlExterior;
}

int datos_premiumFUNC_SelectCantPremios(datos_premium dp){
    return dp.dp_CantidadPremiosObtenidos;
}

