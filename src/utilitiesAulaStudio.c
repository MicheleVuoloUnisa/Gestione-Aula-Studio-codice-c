#include "utilitiesAulaStudio.h"

int mappaturaFasciaOraria(int inizioOra){
    if(inizioOra==9){
        return 0;
    }
    if(inizioOra==11){
        return 1;
    }
    if(inizioOra==13){
        return 2;
    }
    if(inizioOra==15){
        return 3;
    }
}
