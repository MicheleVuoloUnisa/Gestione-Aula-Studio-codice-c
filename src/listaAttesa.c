
/*
 * File: listaAttesa.c
 * Descrizione: Implementazione dell'ADT Coda (Queue) tramite lista concatenata.
 * Gestisce la logica FIFO (First In, First Out) per la lista di attesa degli 
 * studenti. Questo file nasconde i dettagli implementativi (nodi e puntatori)
 * al resto del programma per garantire l'Information Hiding.
 */

#include <stdio.h>
#include <stdlib.h>
#include "listaAttesa.h"

/* Struttura privata che rappresenta 
il singolo elemento (nodo) della lista d'attesa*/
struct node
{
    prenotazione value;
    struct node *next;
};

struct c_queue
{
    struct node *testa, *coda;
    int numel;
};

/*
 * Funzione: nuovaCoda
 * Alloca dinamicamente e inizializza una nuova struttura coda vuota.
 * * Parametri:
 * Nessuno
 * * Pre-condizione:
 * Nessuno
 * * Post-condizione:
 * Viene creata una coda vuota, i puntatori sono a NULL e il contatore a 0.
 * * Ritorna:
 * Il puntatore alla nuova coda, oppure NULL se l'allocazione fallisce.
 */
queue nuovaCoda(void)
{
    struct c_queue *q;
    q = malloc(sizeof(struct c_queue));
    if (q == NULL)
        return NULL;
    q->numel = 0;
    q->testa = NULL;
    q->coda = NULL;
    return q;
}

/*
 * Funzione: codaVuota
 * Verifica lo stato di riempimento della coda.
 * * Parametri:
 * q: la coda da ispezionare.
 * * Pre-condizione:
 * Nessuno
 * * Post-condizione:
 * Nessuna modifica alla struttura dati.
 * * Ritorna:
 * 1 (Vero) se la coda è vuota, 0 (Falso) se contiene elementi. 
 * Ritorna -1 in caso di coda inesistente (NULL).
 */
int codaVuota(queue q)
{
    if (q == NULL)
        return -1;
    return q->numel == 0;
}

/*
 * Funzione: inserisciInCoda
 * Inserisce un nuovo elemento alla fine della lista (logica FIFO).
 * * Parametri:
 * val: la prenotazione dello studente da mettere in attesa.
 * q: la coda in cui inserire l'elemento.
 * * Pre-condizione:
 * La coda 'q' deve esistere e 'val' deve essere valido.
 * * Post-condizione:
 * L'elemento viene aggiunto in ultima posizione e il contatore incrementato.
 * * Ritorna:
 * 1 in caso di successo, 0 in caso di fallimento allocazione, -1 se coda non valida.
 */
int inserisciInCoda(prenotazione val, queue q)
{
    if (q == NULL)
        return -1;
    /*se la coda esiste, creamo un nuovo nodo che conterrà
    l'elemento da inserire */
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo == NULL){
        return 0;
    }
    nuovo->value = val;
    nuovo->next = NULL;
    if (q->testa == NULL)
        q->testa = nuovo; // caso coda vuota
    else
        q->coda->next = nuovo; // caso coda non vuota
    q->coda = nuovo;           // coda punta al nuovo nodo
    (q->numel)++;              // incrementare il numero di elementi
    return 1;
}

/*
 * Funzione: dequeue
 * Estrae e restituisce la prenotazione che si trova in cima alla lista d'attesa.
 * * Parametri:
 * q: la coda da cui estrarre.
 * * Pre-condizione:
 * La coda 'q' deve esistere , non essere vuota e il numero di elementi deve essere >0
 * * Post-condizione:
 * L'elemento in testa viene rimosso, la memoria liberata e la nuova testa aggiornata.
 * * Ritorna:
 * L'elemento (prenotazione) in cima alla coda, o NULLITEM se la coda è vuota/nulla.
 */
prenotazione dequeue(queue q)
{
    if (q == NULL)
        return NULLITEM;
    if (q->numel == 0)
        return NULLITEM;                  // coda vuota
    prenotazione result = q->testa->value; // item da restituire
    struct node *temp = q->testa;          // nodo da rimuovere

    q->testa = q->testa->next; // q->head avanza
    free(temp);              // liberiamo memoria nodo da rimuovere
    if (q->testa == NULL)     // se la coda conteneva un solo elemento
        q->coda = NULL;

    (q->numel)--;
    return result;
}