#ifndef CONVERT_CHIFFRE_H_INCLUDED
#define CONVERT_CHIFFRE_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXIMUM 900
#define minimum 50

char *main_convert(char *nombre);
char * Discrete_convert(char *nombre,char *resultat);

char *million(unsigned long long nbr);
char *milliard(unsigned long long nbr);
char *million(unsigned long long nbr);
char *mille(unsigned long long  nbr);
char *cent(unsigned long long nbr);
char *mot(unsigned long long nbr);

#endif // CONVERT_CHIFFRE_H_INCLUDED
char unite[10][20]={"","un ","deux ","trois ","quatre ","cinq ","six ","sept ","huit ","neuf "};
char onze_a_dix_neuf[10][20]={"dix ", "onze ", "douze ", "treize ", "quatorze ", "quinze ", "seize ", "dix-sept ", "dix-huit ", "dix-neuf "};
char dizaines[10][20] = {"", "dix ", "vingt ", "trente ", "quarante ", "cinquante ", "soixante ", "soixante-", "quatre-vingt ", "quatre-vingt-"};

char *main_convert(char *nombre)
{
    char *resultat=(char*)calloc(MAXIMUM,sizeof(char));
    Discrete_convert(nombre,resultat);
    return resultat;

}
char* Discrete_convert(char *nombre,char *resultat)
{
    double nbr=atof(nombre);
    unsigned long long p_entier=(unsigned long long)nbr;
   unsigned long long p_decimale=(unsigned long long )((nbr-p_entier)*100+0.5);
    if(p_entier==0 &&p_decimale==0){  resultat ="zero"; return resultat;}
   unsigned long long rest=p_entier;
    char *tompo;

    //partie milliard
    tompo=milliard(rest/1000000000);
    strcpy(resultat,tompo);
    rest%=1000000000;
    free(tompo);


    //partie million
    tompo=million(rest/1000000);
    strcat(resultat,tompo);
    rest%=1000000;
    free(tompo);

    //partie mille
    tompo=mille(rest/1000);
    strcat(resultat,tompo);
    rest%=1000;
    free(tompo);


    //partie cent
    tompo=cent(rest/100);
    strcat(resultat,tompo);
    rest%=100;
    free(tompo);


    // partie unite
    tompo=mot(rest);
    strcat(resultat,tompo);
    free(tompo);

    //partie decimale
    if(p_decimale>0)
    {
        if(p_entier==0) strcpy(resultat ,"zero ");
        strcat(resultat," virgule ");
         tompo=mot(p_decimale);
        strcat(resultat,tompo);
        free(tompo);
    }
    return resultat;
}
char *milliard(unsigned long long nbr)
{
    if(!nbr) return strdup("");
    char *p_milliard=(char*)calloc(MAXIMUM,sizeof(char));
    char *tompo=cent(nbr/100);
    strcat(p_milliard,tompo);
    if(nbr!=1)strcat(p_milliard,mot(nbr%100));
    strcat(p_milliard," milliard ");
    free(tompo);
    return p_milliard;
}
char *million(unsigned long long  nbr)
{
    if(!nbr) return strdup("");
    char *p_million=(char*)calloc(MAXIMUM,sizeof(char));
    char *tompo=cent(nbr/100);
    strcpy(p_million,tompo);
     if(nbr!=1)strcat(p_million,mot(nbr%100));
    strcat(p_million," million ");
    free(tompo);
    return p_million;
}
char *mille(unsigned long long  nbr)
{
    if(!nbr) return strdup("");
    char *p_mille=(char*)calloc(MAXIMUM,sizeof(char));
    char *tompo=cent(nbr/100);
    strcpy(p_mille,tompo);
     if(nbr!=1)strcat(p_mille,mot(nbr%100));
    strcat(p_mille," mille ");
    free(tompo);
    return p_mille;
}
char *cent(unsigned long long  nbr)
{
    if(!nbr) return strdup("");
    char *p_mille=(char*)calloc(MAXIMUM,sizeof(char));
     if(nbr!=1)strcpy(p_mille,mot(nbr));
    strcat(p_mille," cent ");
    return p_mille;
}
char *mot(unsigned long long nbr)
{
        char *Mot=(char*)calloc(minimum,sizeof(char));
    if(nbr<10) strcpy(Mot,unite[nbr]);
    else if(nbr<20)strcpy(Mot,onze_a_dix_neuf[nbr%10]);
    else{
            int p_unit=nbr%10,p_u_dizaine=nbr/10;
            strcpy(Mot,dizaines[p_u_dizaine]);
            if(p_u_dizaine==7||p_u_dizaine==9)
                strcat(Mot,onze_a_dix_neuf[p_unit]);
                else
                    strcat(Mot,unite[p_unit]);
    }
        return Mot;
}
