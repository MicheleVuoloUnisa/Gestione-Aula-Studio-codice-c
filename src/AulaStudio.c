#include <stdio.h>
#include <stdlib.h>
#include "AulaStudio.h"
#define NUMPOSTI 50
#define FASCIAORARIA 4
//altre eventuali inclusioni

/*matrice che ci definisce l'aula studio vera e propria
l'indice 50 indica il numero di posti dell'aula studio (0-49)
l'indice 4 indica le fasce orarie (9-11;11-13;13-15;15-17)
*/
static int AulaStudio[NUMPOSTI][FASCIAORARIA];

int occupazionePosto(prenotazione p){
    if(p==NULL){
        printf("prenotazione inesistente oppure errore di memoria");
        return -1;
    }
    /*finché l'utente non inserisce una fascia oraria valida,
    non può andare avanti */
        // Verifichiamo che l'orario sia valido prima di fare calcoli
    controlloFasciaOraria(getInizioOra(p), getFineOra(p));
    

    
    if(getInizioOra(p)==9){
        setStato(p);
        AulaStudio[getPostoAssegnato(p)-1][0]=1;
        printf("lo studente è entrato in aula");
        //inserimento nello storico accessi
        return 0;
    }

    if(getInizioOra(p)==11){
        setStato(p);
        AulaStudio[getPostoAssegnato(p)-1][1]=1;
        printf("lo studente è entrato in aula");
        //inserimento nello storico accessi
        return 0;
    }
    if(getInizioOra(p)==13){
        setStato(p);
        AulaStudio[getPostoAssegnato(p)-1][2]=1;
        printf("lo studente è entrato in aula");
        //inserimento nello storico accessi
        return 0;
    }
    if(getInizioOra(p)==15){
        setStato(p);
        AulaStudio[getPostoAssegnato(p)-1][3]=1;
        printf("lo studente è entrato in aula");
        //inserimento nello storico accessi
        return 0;
    }
}

int visualizzaStudentiPresenti(int inizioOra){
    int cont=0;
    for(int i=0;i<NUMPOSTI;i++){
        if(AulaStudio[i][mappaturaFasciaOraria(inizioOra)]==1){
            cont++;
        }
    }
    return cont;
}

int postiDisponibiliFasciaOraria(int inizioOra, int fineOra){
    printf("I POSTI DISPONIBILI SONO: \n");
    for(int i=0;i<NUMPOSTI;i++){
        if(AulaStudio[i][mappaturaFasciaOraria(inizioOra)]==0){
            printf("%d ", i+1);
        }
    }
    return 0;
}