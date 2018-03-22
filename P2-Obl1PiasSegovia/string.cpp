#include "string.h"

int StringFUNC_largo(String palabra1){
  int i=0;
  while(i<MAX && palabra1[i]!='\0')
    i++;
  return i;
}

void StringPROC_print(String palabra1){
  int i=0;
  while(palabra1[i]!='\0'){
    printf("%c",palabra1[i]);
    i++;
  }
}

void StringPROC_scan(String &palabra1){
  int i=0;
  fflush(stdin);
  printf("\n(ingrese una palabra y termine con enter): ");
  scanf("%c",&palabra1[i]);
  while(palabra1[i]!='\n' && i<MAX){
    i++;
    scanf("%c",&palabra1[i]);
  }
  palabra1[i]='\0';
  printf("(la palabra es): ");
  i=0;
  while(palabra1[i] != '\0'){
    printf("%c",palabra1[i]);
    i++;
  }
}

boolean StringFUNC_isSonIguales(String palabra1, String palabra2){
  boolean isIgual=TRUE;
  int i=1;
  if(StringFUNC_largo(palabra1)!=StringFUNC_largo(palabra2))
    isIgual=FALSE;
  else
    if(palabra1[0]!=palabra2[0]){
        isIgual=FALSE;
    }
    else{
        while(palabra1[i]!='\0' && palabra2[i]!='\0' && i<MAX && isIgual){
            if(palabra1[i] != palabra2[i])
              isIgual=FALSE;
            i++;
        }
    }
  return isIgual;
}

void StringPROC_CopiaElSegundoEnPrimero(String palabra1, String palabra2){
  int i=1;
  palabra1[0]=palabra2[0];
  while (palabra2[i]!='\0' && i<MAX){
    palabra1[i]=palabra2[i];
    i++;
  }
  palabra1[i]='\0';
}
