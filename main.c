#include "Convert_chiffre.h"
int main()
{
    char nombre[minimum],*chiffre;
    int i;
    do{printf("donner un nombre :");
    scanf("%s",nombre);
    chiffre=main_convert(nombre);
    printf("le chiffre est : %s\n",chiffre);
    scanf("%d",&i);
    free(chiffre);
    }while(i);

    return 0;
}
