#include "utilitiesPrenotazione.h"
int controlloData(int giorno,int mese,int anno){
    if((mese < 1)||(mese >12)){
        return -1;
    }
    if((mese != 1)&&(mese != 2)&&(mese != 8)&&(mese != 10)&&
    (mese != 12) &&(mese !=3)&&(mese != 5)&&(mese != 7)){
        if((giorno < 1)||(giorno>30)){
            return -1;
        }
    }
    else if((giorno <1)||(giorno >31)){
        return -1;
    }
    if(mese == 2){
        if((giorno < 1)||(giorno >29)){
            return -1;
        }
    }
    if((anno <=2025)||(anno >2026)){
        return -1;
    }
    return 0;
}

int controlloFasciaOraria(int inizioOra,int fineOra){
        if((inizioOra <=8)||(inizioOra ==10)||(inizioOra==12)||
    (inizioOra==14)||(inizioOra >=16)){
            return -1;
        }
        if((fineOra <=10)|| (fineOra==12)||(fineOra==14)||(fineOra==16)
    ||(fineOra>17)){
            return -1;
    }
    return 0;
}