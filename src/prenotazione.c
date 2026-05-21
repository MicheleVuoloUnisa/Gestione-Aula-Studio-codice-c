/*
 * File: prenotazione.c
 * Descrizione: Implementazione dell'ADT Prenotazione. 
 * Gestisce la creazione, la manipolazione e l'annullamento delle prenotazioni
 * per l'aula studio. Le strutture interne sono nascoste per garantire l'Information Hiding.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "prenotazione.h"
//definizione della struttura "DATA"
 struct data{
    int giorno;
    int mese;
    int anno;
};

 struct fasciaOraria{
    int inizioOra;
    int fineOra;
};

//Definizione della struttura: "PRENOTAZIONE"
 struct pre{
    char matricola[11];
    struct data DataPrenotazione;
    int postoAssegnato;
    struct fasciaOraria fascia;
    int stato; //stato=0 se lo studente è prenotato ma non è in aula, stato = 1 se lo studente prenotato è presente in aula
};

//funzioni di base per l'item: costruttore,getter

/*
 * Funzione: creaPrenotazione
 * Costruttore dell'ADT. Alloca e inizializza una nuova prenotazione.
 * * Parametri: matricola, giorno, mese, anno, posto, inizioOra, fineOra.
 * * Pre-condizione: I dati passati devono essere validi e la stringa 'mat' max 10 char.
 * * Post-condizione: Viene allocato un nuovo blocco di memoria per la prenotazione.
 * * Ritorna: Il puntatore alla nuova prenotazione, o NULL se l'allocazione fallisce.
 */
prenotazione creaPrenotazione(char mat[11], int giorno,int mese,int anno,int posto,int inizioOra,int fineOra){
    prenotazione p=malloc(sizeof(struct pre));
    if(p==NULL){
        printf("errore durante l'allocazione di memoria");
        return NULL;}
    // Si usa strncpy invece di strcpy per evitare buffer overflow se la stringa 'mat' è troppo lunga
    strncpy(p->matricola,mat,10);
    //aggiungiamo il terminatore nullo alla stringa in modo da essere tale
    p->matricola[10]='\0';


    //inizializziamo i valori di giorno,mese,anno
    p->DataPrenotazione.giorno=giorno;
    p->DataPrenotazione.mese=mese;
    p->DataPrenotazione.anno=anno;
    //inizializziamo il valore del posto assegnato
    p->postoAssegnato = posto;
    //inizializziamo i valori della fascia oraria della prenotazione
    p->fascia.inizioOra = inizioOra;
    p->fascia.fineOra=fineOra;
    p->stato=0;
    return p;
}

//funzioni getter, con esse garantiamo information hiding

/*
 * Funzione: getMatricola
 * Pre-condizione: p != NULL
 * Post-condizione: restituisce la matricola associata alla prenotazione.
 * * Ritorna: Puntatore alla stringa matricola, o NULL in caso di errore.
 */
char* getMatricola(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return NULL;}
    return p->matricola;
}

/* Tutte le funzioni getter seguenti restituiscono -1 in caso di prenotazione NULL 
 * Funzione: getPostoAssegnato
 * Pre-condizioni: p != NULL
 * Post-condizioni: restituisce il valore del puntatore
*/
int getPostoAssegnato(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return -1;}
    return p->postoAssegnato;
}

/* Funzione: getGiornoPrenotazione
 * Pre-condizioni: p != NULL
 * Post-condizioni: restituisce il valore del puntatore
*/
int getGiornoPrenotazione(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return -1;}
    return p->DataPrenotazione.giorno;
}

/* Funzione: getMesePrenotazione
 * Pre-condizioni: p != NULL
 * Post-condizioni: restituisce il valore del puntatore
*/
int getMesePrenotazione(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return -1;}
    return p->DataPrenotazione.mese;
}

/* Funzione: getAnnoPrenotazione
 * Pre-condizioni: p != NULL
 * Post-condizioni: restituisce il valore del puntatore
*/
int getAnnoprenotazione(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return -1;}
    return p->DataPrenotazione.anno;
}

/* Funzione: getInizioOra
 * Pre-condizioni: p != NULL
 * Post-condizioni: restituisce il valore del puntatore
*/
int getInizioOra(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return -1;}
    return p->fascia.inizioOra;
}

/* Funzione: getFineOra
 * Pre-condizioni: p != NULL
 * Post-condizioni: restituisce il valore del puntatore
*/
int getFineOra(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return -1;}
    return p->fascia.fineOra;
}

/*
 * Funzione: getStato
 * Pre-condizioni: p != NULL
 * Post-condizioni: lo stato attuale della prenotazione (utile per il check-in).
 * * Ritorna: 0 se solo prenotato, 1 se presente in aula, -1 in caso di errore.
 */
int getStato(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return -1;}
    return p->stato;
}

/* Funzione: setStato
 * Pre-condizioni: p != NULL
 * Post-condizioni: restituisce l'operazione di check-in, impostando lo stato dello studente a 1 (presente).
 * * Ritorna: il valore del puntatore se l'aggiornamento ha successo, -1 se fallisce (es. puntatore NULL).
 */
int setStato(prenotazione p){
    if(p==NULL){
        printf("errore,la prenotazione è stata deallocata oppure non è mai stata allocata");
        return -1;}
    p->stato=1;
    return p->stato;
}

/*
 * Funzione: annullaPrenotazione (Distruttore)
 * Libera la memoria allocata per la prenotazione.
 * * Parametri: p (la prenotazione da eliminare).
 * * Post-condizione: La memoria puntata da p viene restituita al sistema.
 * * Ritorna: 0 in caso di successo.
 */
int annullaPrenotazione(prenotazione p){
    if(p!=NULL){
        free(p);
    }
    return 0;
}

