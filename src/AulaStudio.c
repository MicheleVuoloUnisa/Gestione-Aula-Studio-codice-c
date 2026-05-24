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


//funzione check-in studente prenotato
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

/*
 * Funzione: gestioneIngressoSenzaPrenotazione
 * * Descrizione:
 * Gestisce l'ingresso "last-minute" di uno studente non prenotato.
 * Verifica la disponibilità di un posto libero per la fascia oraria indicata
 * e, in caso positivo, assegna il primo posto disponibile aggiornando lo stato dell'aula.
 *
 * Input:
 * - s: Puntatore all'ADT studente che richiede l'accesso.
 * - inizioOra: Intero che rappresenta l'ora di inizio della fascia oraria.
 * - fineOra: Intero che rappresenta l'ora di fine della fascia oraria.
 *
 * Output:
 * - Intero che rappresenta il numero del Posto assegnato (da 1 a NUMPOSTI).
 * - Ritorna -1 se lo studente è NULL o se la fascia oraria non è valida.
 * - Ritorna 0 se l'aula è completamente piena per quella fascia oraria.
 *
 * Pre-condizione:
 * Lo studente 's' deve essere stato allocato e inizializzato correttamente.
 *
 * Post-condizione:
 * Se c'è posto, la funzione restituisce il numero del posto assegnato.
 * * Effetti Collaterali:
 * Modifica lo stato della matrice globale AulaStudio, impostando a 1 la cella 
 * corrispondente al posto trovato per occuparlo fisicamente.
 */
int gestioneIngressoSenzaPrenotazione(studente s, int inizioOra, int fineOra){
    if(s==NULL){
        return -1;
    }
    if(controlloFasciaOraria(inizioOra,fineOra)==-1){
        return -1;
    }
    int tempFascia=mappaturaFasciaOraria(inizioOra);
    for(int i=0;i<NUMPOSTI;i++){
        if(AulaStudio[i][tempFascia]==0){
            AulaStudio[i][tempFascia]=1; // OCCUPO IL POSTO (Check-in effettivo)
            return i+1;// Restituisco il posto in formato umano (1-50)
        }
    }
    return 0; //l'aula studio per quella fascia oraria è piena
}