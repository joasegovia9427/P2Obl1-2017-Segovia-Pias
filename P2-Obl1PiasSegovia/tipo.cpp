#include "tipo.h"

void tipoPROC_Carga(tipo &t){
    char ingreso;
    boolean ok = FALSE;
    do{
        fflush(stdin);
        printf("\nIngrese Tipo de Variedad: COM%sN(C),ESPECIAL(E),PREMIUM(P): ", LETRA_U);
        scanf("%c", &ingreso);
        switch (ingreso){
            case 'C':
            case 'c':
                t = COMUN;
                ok = TRUE;
                break;
            case 'E':
            case 'e':
                t = ESPECIAL;
                 ok = TRUE;
                break;
            case 'P':
            case 'p':
                t = PREMIUM;
                 ok = TRUE;
                break;
            default:
                printf("\nOpci%sn Incorrecta, reintente.", LETRA_o);
                break;
        }
    }while(ok == FALSE);
}
void tipoPROC_Print(tipo t){
    switch(t){
        case COMUN:
            printf("\nCOM%sN", LETRA_U);
            break;
        case ESPECIAL:
            printf("\nESPECIAL");
            break;
        case PREMIUM:
            printf("\nPREMIUM");
            break;
    }
}

