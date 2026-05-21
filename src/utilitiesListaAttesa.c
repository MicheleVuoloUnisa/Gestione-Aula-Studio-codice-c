#include<stdio.h>
#include<stdlib.h>
#include "utilitiesListaAttesa.h"
/*
 * Funzione: visualizzaStudentiInAttesa
 * Conta il numero di studenti in lista di attesa per una specifica data e fascia oraria.
 * * Parametri:
 * q: la coda (lista di attesa) da ispezionare
 * giorno: il giorno della prenotazione da cercare
 * mese: il mese della prenotazione da cercare
 * anno: l'anno della prenotazione da cercare
 * inizioOra: l'ora di inizio della fascia oraria
 * fineOra: l'ora di fine della fascia oraria
 * * Pre-condizione:
 * La coda 'q' deve essere stata inizializzata.
 * * Post-condizione:
 * La coda 'q' viene riportata esattamente al suo stato e ordine originale.
 * Non avvengono modifiche permanenti ai dati.
 * * Ritorna:
 * Il numero di studenti in attesa che corrispondono ai criteri.
 * Ritorna 0 se la coda è vuota o inesistente.
 */
int visualizzaStudentiInAttesa(queue q,int giorno,int mese,int anno, int inizioOra,int fineOra){
    if(q==NULL){
        printf("non ci sono studenti in attesa");
        return 0;
    }
    int cont=0;
    queue temp=nuovaCoda();
    while(codaVuota(q)==0){
        prenotazione tempItem=dequeue(q);
        //controllo se la prenotazione corrisponde alla data e alla fascia oraria
        //che l'utente ha selezionato
        if((getGiornoPrenotazione(tempItem)==giorno)&&(getMesePrenotazione(tempItem)==mese)
            &&(getAnnoprenotazione(tempItem)==anno)&&(getInizioOra(tempItem)==inizioOra)
        &&(getFineOra(tempItem)==fineOra)){
        cont++;
        }
        inserisciInCoda(tempItem,temp);
    }
    //Ripristina l'ordine originale trasferendo di nuovo i dati nella coda di partenza
    while(codaVuota(temp)==0){
        prenotazione tempItem=dequeue(temp);
        inserisciInCoda(tempItem,q);
    }
    //libero la memoria occupata per la lista temporanea
    free(temp);
    temp=NULL;
    return cont;
}