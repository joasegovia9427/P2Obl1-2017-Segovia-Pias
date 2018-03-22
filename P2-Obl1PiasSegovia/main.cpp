////UDE - LicEnInformatica, Curso 2017 - Nocturno - Programacion 2 - Primer Obligatorio - Docente: Tavidian, Sirely
////Integrantes: Pías, Richard - 1.924.591-2 ; Segovia, Joaquín - 4.739.544-4
#include "fabrica.h"
#include "menus.h"
void PROC_logicaMenuOp3(arregloVariedades &arreVarBasePrincipal){
    int opcionMenuOp3,codigoNumID,mayorCantProd,cantidadPremiosAbuscar=0,cantidadEfectiva=0,cantidadesCOMUN, cantidadesESPECIAL, cantidadesPREMIUM,cantidadVars,cantidadAModificarle;
    String codigoNombID, ingredienteAContar;
    boolean isSVolver,isExisteNUM,isIncrementarODec;
    do{
        fflush(stdin);
        isExisteNUM = FALSE;
        menusPROC_menuOpcion3(opcionMenuOp3);
        switch (opcionMenuOp3){
        case 1://3.1
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            arregloVariedadesPROC_listadoTodoSimple(arreVarBasePrincipal);
            PROC_LimpiarYPausa();
            break;
        case 2://3.2
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            printf("\nIngrese n%smero identificador para listar una variedad detallademente: ", LETRA_u);
            scanf("%d",&codigoNumID);
            isExisteNUM = arregloVariedadesFUNC_isExisteVariedadIDnumero(arreVarBasePrincipal, codigoNumID);
            if (isExisteNUM){
                arregloVariedadesPROC_listadoUnidadDetallado(arreVarBasePrincipal, codigoNumID);
            }
            else{
                printf("\nError, no existe la variedad con tal identificador");
            }
            PROC_LimpiarYPausa();
            break;
        case 3://3.3
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            arregloVariedadesPROC_cantidadesVporTipos(arreVarBasePrincipal,cantidadesCOMUN, cantidadesESPECIAL, cantidadesPREMIUM);
            printf("\nLa cantidad de variedades de pancho, de tipo     COM%sN es: %d", LETRA_U,cantidadesCOMUN);
            printf("\nLa cantidad de variedades de pancho, de tipo  ESPECIAL es: %d",cantidadesESPECIAL);
            printf("\nLa cantidad de variedades de pancho, de tipo   PREMIUM es: %d\n",cantidadesPREMIUM);
            PROC_LimpiarYPausa();
            break;
        case 4://3.4
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            arregloVariedadesPROC_devolverDatosVarMayorProd(arreVarBasePrincipal, codigoNumID, codigoNombID, mayorCantProd);
            printf("\nDatos de la variedad con la mayor cantidad de unidades producidas \nC%sdigo: %d \nNombre: ", LETRA_o,codigoNumID);
            StringPROC_print(codigoNombID);
            printf("\nCantidad producidas: %d",mayorCantProd);
            PROC_LimpiarYPausa();
            break;
        case 5://3.5
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            arregloVariedadesPROC_cantidadesVporTipos(arreVarBasePrincipal,cantidadesCOMUN, cantidadesESPECIAL, cantidadesPREMIUM);
            if (cantidadesESPECIAL == 0){
                printf("\n***No hay variedades de pancho de tipo ESPECIAL para procesar.");
            }
            else{
                printf("\nIngrese un ingrediente para contar la cantidad de variedades de tipo especial que lo tienen como principal: ");
                StringPROC_scan(ingredienteAContar);
                cantidadVars = arregloVariedadesFUNC_cantidadesVespConIngrediente(arreVarBasePrincipal, ingredienteAContar);
                printf("\nCantidad variedades con ese ingredeiente es: %d",cantidadVars);
            }
            PROC_LimpiarYPausa();
            break;
        case 6://3.6
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            arregloVariedadesPROC_cantidadesVporTipos(arreVarBasePrincipal,cantidadesCOMUN, cantidadesESPECIAL, cantidadesPREMIUM);
            if (cantidadesPREMIUM == 0){
                printf("\n***No hay variedades de pancho de tipo PREMIUM para procesar.");
            }
            else{
                do{
                    cantidadPremiosAbuscar = 0;
                    fflush(stdin);
                    printf("\nIngrese cantidad de premios para buscar alguna variedad que al menos haya ganado esa cantidad: ");
                    scanf("%d",&cantidadPremiosAbuscar);
                    if (cantidadPremiosAbuscar <= 0){
                       printf("\nError, la cantidad no puede ser menor a 0, reintente");
                       PROC_LimpiarYPausa();
                    }
                } while (cantidadPremiosAbuscar < 1);
                arregloVariedadesPROC_devolverVariedadSegunPremios(arreVarBasePrincipal, cantidadPremiosAbuscar, codigoNumID, codigoNombID, cantidadEfectiva);
                if (codigoNumID > 0){
                    printf("\n\nC%sdigo: %d \nNombre:", LETRA_o, codigoNumID);
                    StringPROC_print(codigoNombID);
                    printf("\nCantidad de premios: %d", cantidadEfectiva);
                }else{
                    printf("\nNo existe una variedad con al menos la cantidad ingresada");
                }
            }
            PROC_LimpiarYPausa();
            break;
        case 7://3.7
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            printf("\nIngrese n%smero identificado para modificar su cantidad de unidades por semana: ", LETRA_u);
            scanf("%d",&codigoNumID);
            arregloVariedadesPROC_listadoUnidadDetallado(arreVarBasePrincipal,codigoNumID);
            isExisteNUM = arregloVariedadesFUNC_isExisteVariedadIDnumero(arreVarBasePrincipal, codigoNumID);
            if (isExisteNUM){
                printf("\nUsted desea incrementar la cantidad de producci%sn por semana de la variedad?\n('SI' para incrementar, o 'NO' para decrementar: ", LETRA_o);
                booleanPROC_carga(isIncrementarODec);
                do{
                    cantidadAModificarle = 0;
                    fflush(stdin);
                    printf("\nIngrese cantidad para modificar: ");
                    scanf("%d",&cantidadAModificarle);
                    if (cantidadAModificarle < 1){
                       printf("\nError, la cantidad no puede ser menor a 1, reintente");
                       PROC_LimpiarYPausa();
                    }
                } while (cantidadAModificarle < 1);
                arregloVariedadesPROC_incORdecCantidadProdc(arreVarBasePrincipal,codigoNumID,cantidadAModificarle,isIncrementarODec);
            }
            else{
                printf("\nError, no existe la variedad con tal identificador");
            }
            PROC_LimpiarYPausa();
            break;
        case 8://3.8
            printf("\n***Opci%sn %d - Esta seguro que desea volver al men%s principal?***", LETRA_o,opcionMenuOp3, LETRA_u);
            booleanPROC_carga(isSVolver);

            if (!isSVolver){
                opcionMenuOp3=0;
            }
            else{
                printf("\n   volver%s al men%s principal   ", LETRA_a, LETRA_u);
            }
            system(LIMPIAR);
            break;
        default:
            system(LIMPIAR);
            printf("\n***Error, reintente con un caracter valido.***\n");
            PROC_LimpiarYPausa();
            break;
        }
    } while (opcionMenuOp3 != 8);
}
int main(){
    arregloVariedades arreVarBasePrincipal;
    arregloVariedadesPROC_inicializacion(arreVarBasePrincipal);
    int opcion,i,j,IDnumParaBorrar;
    String codigoNombID;
    boolean isArregloCargado = FALSE, isSalir = FALSE, isConfirmarEjecucion,isExisteNUM = FALSE,isExisteNOMB,idCargadoCorrecto;
    variedad var;
    printf("\n\n**********BIENVENIDO A PROGRAMA DE F%sBRICA - El pancho sabros%sn**********\n", LETRA_A, LETRA_o);
    do{
        fflush(stdin);
        menusPROC_menuPrincipal(opcion);
        switch (opcion){
        case 1://1.1
            printf("\nIngreso a la opci%sn %d\n", LETRA_o,opcion);
            do{
                variedadPROC_Carga(var);
                int codigoNumID = variedadFUNC_SelectCodigoNumerico(var);
                isExisteNUM = arregloVariedadesFUNC_isExisteVariedadIDnumero(arreVarBasePrincipal, codigoNumID);
                variedadPROC_SelectCodigoNombre(var, codigoNombID);
                isExisteNOMB = arregloVariedadesFUNC_isExisteVariedadIDnombre(arreVarBasePrincipal, codigoNombID);
                if (isExisteNUM || isExisteNOMB){
                    printf("\nError, ya hay una variedad cargada con el mismo identificadores.\nReintente.");
                    PROC_LimpiarYPausa();
                }
            } while (isExisteNUM || isExisteNOMB);
            printf("\nUsted ingresara la siguiente variedad de pancho:");
            variedadPROC_Print(var);
            printf("\nEsta seguro que desea confirmar el guardado de esta variedad?");
            booleanPROC_carga(isConfirmarEjecucion);
            if (isConfirmarEjecucion){
                arregloVariedadesPROC_carga(arreVarBasePrincipal, var, idCargadoCorrecto);
                if (idCargadoCorrecto){
                    isArregloCargado = TRUE;
                    arregloVariedadesPROC_ordenarPorFechasBB(arreVarBasePrincipal);
                    printf("\n***Se ingreso correctamente la variedad");
                }
                else{
                    printf("\nNo se pueden ingresar mas variedades");
                }
            }
            else{
                printf("\n***No se guardo variedad, usted volvera al menu principal");
            }
            PROC_LimpiarYPausa();
            break;
        case 2://1.2
            if (isArregloCargado == FALSE){
                PROC_mensajeErrorCargaVacia();
            }
            else{
                printf("\nIngreso a la opci%sn %d\n", LETRA_o,opcion);
                isExisteNUM = FALSE;
                printf("\n***Opci%sn para Borrar Variedad", LETRA_o);
                printf("\nIngrese n%smero identificado para borrar: ", LETRA_u);
                scanf("%d",&IDnumParaBorrar);
                isExisteNUM = arregloVariedadesFUNC_isExisteVariedadIDnumero(arreVarBasePrincipal, IDnumParaBorrar);
                if (isExisteNUM){
                    printf("\nUsted eliminara la siguiente variedad de pancho:");
                    arregloVariedadesPROC_listadoUnidadDetallado(arreVarBasePrincipal, IDnumParaBorrar);
                    printf("\nEsta seguro que desea confirmar la eliminaci%sn de esta variedad?", LETRA_o);
                    booleanPROC_carga(isConfirmarEjecucion);
                    if (isConfirmarEjecucion){
                        arregloVariedadesPROC_bajaIDcodigo(arreVarBasePrincipal, IDnumParaBorrar);
                        printf("\n***Se elimin%s la variedad", LETRA_o);
                        fflush(stdin);
                        if (arregloVariedadesFUNC_SelectTope(arreVarBasePrincipal) == 0){
                            isArregloCargado = FALSE;
                        }
                        PROC_LimpiarYPausa();
                    }
                    else{
                        printf("\n***No se elimin%s variedad, usted volver%s al men%s principal", LETRA_o, LETRA_a, LETRA_u);
                        PROC_LimpiarYPausa();
                        fflush(stdin);
                    }
                }
                else{
                    system(LIMPIAR);
                    printf("\nError, no hay variedad con este identificador para borrar.\nReintente.");
                    PROC_LimpiarYPausa();
                    fflush(stdin);
                }
            }
            break;
        case 3://3
            if (isArregloCargado == FALSE){
                PROC_mensajeErrorCargaVacia();
            }
            else{
                printf("\nIngreso a la opci%sn %d\n", LETRA_o,opcion);
                PROC_logicaMenuOp3(arreVarBasePrincipal);
            }
            break;
        case 4://4
            printf("\n***Opci%sn %d - Est%s seguro que desea salir?***", LETRA_o,opcion, LETRA_a);
            booleanPROC_carga(isSalir);
            if (!isSalir){
                opcion=1;
                system(LIMPIAR);
            }
            else{
                system(LIMPIAR);
                printf("\n\n*******<<<________FIN DEL PROGRAMA F%sBRICA________>>>*******\n\n", LETRA_A);
                printf("\n*******<<<****************************************>>>*******\n");
                for (j=176;j<179;j++)
                {
                    printf("\n");
                    for (i=0;i<85 ;i++ )
                    {
                        printf("%c",j);
                    }
                }
                printf("\n%c",201);
                for (i=0;i<84 ;i++ ){
                    printf("%c",205);
                }
            }
            break;
        default:
            system(LIMPIAR);
            printf("\n***Error, reintente con un car%scter valido.***", LETRA_a);
            PROC_LimpiarYPausa();
            break;
        }
    } while (opcion != 4);
    printf("\n%c<<<*****************<<<______About this software______>>>***********************>>>%c",186,186);
    printf("\n%c<<<UDE-TRABAJO OBLIGATORIO PROG2 LIC.INFO.Nocturno2017-Docente: Tavidian, Sirely>>>%c",186,186);
    printf("\n%c<<<#proudlyDevelopedBy: Pias, Richard-1.924.591-2 & Segovia, Joaquin-4.739.544-4>>>%c",186,186);
    printf("\n%c<<<*****************************************************************************>>>%c",186,186);
    printf("\n%c",200);
    for (i=0;i<84 ;i++ ){
        printf("%c",205);
    }
    for (j=176;j<179;j++)
    {
        printf("\n");
        for (i=0;i<85 ;i++ )
        {
            printf("%c",j);
        }
    }
    PROC_LimpiarYPausa();
}
//UDE - LicEnInformatica, Curso 2017 - Nocturno - Programacion 2 - Primer Obligatorio - Docente: Tavidian, Sirely
//Integrantes: Pias, Richard - 1.924.591-2; Segovia, Joaquin - 47395444
