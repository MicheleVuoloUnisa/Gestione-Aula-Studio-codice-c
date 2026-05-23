#include <stdio.h>
#include <stdlib.h>
#include "prenotazione.h"
#include "stack.h"

int nuovoAccesso(prenotazione prenotazione, stack *storico, int accessi){
    push(prenotazione, *storico);
    accessi++;
    return accessi;
}

int visualizzazioneAccessi(stack *storico, int accessi){
    stack stack =  newStack();
    for(int i=0; i<accessi; i++){
        push(top(*storico), stack);
    }
    for(int i=0; i<accessi; i++){
        printf("\nMatricola: %s\n", getMatricolaPreno(top(*storico)));
        printf("Posto: %d\n", getPostoAssegnato(top(*storico)));
        printf("Orario: %d-%d\n", getInizioOra(top(*storico)), getFineOra(top(*storico)));
        printf("Data: %d/%d/%d\n", getGiornoPrenotazione(top(*storico)), getMesePrenotazione(top(*storico)), getAnnoprenotazione(top(*storico)));
        pop(*storico);
    }
    for(int i=0; i<accessi; i++){
        push(top(stack), *storico);
    }
    return 0;
}

