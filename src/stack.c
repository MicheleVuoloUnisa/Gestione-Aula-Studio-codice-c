// Inclusione delle librerie standard necessarie per input/output e allocazione dinamica della memoria.
#include <stdio.h>
#include <stdlib.h>

// Inclusione degli header files per la definizione del tipo 'pren' e delle funzioni relative alla pila.
#include "pren.h" 
#include "stack.h"

// Definizione di una costante che rappresenta la dimensione massima della pila.
#define MAXSTACK 50

// Definizione della struttura 'c_stack' che rappresenta la pila. Contiene un array 'vet' di tipo 'pren' per gli elementi della pila e un intero 'top' che tiene traccia dell'indice dell'ultimo elemento inserito.
struct c_stack {
     pren vet[MAXSTACK];
     int top;
};

// Funzione per creare e inizializzare una nuova pila. Alloca dinamicamente spazio per la struttura 'c_stack' e inizializza 'top' a 0.
stack newStack(void)
{
     stack s;
     s = malloc (sizeof(struct c_stack));
     if (s == NULL) return NULL; // Controlla se l'allocazione è fallita.
     s->top = 0; // Imposta l'indice 'top' a 0, indicando che la pila è vuota.
     return s; // Restituisce un puntatore alla pila creata.
}

// Funzione che verifica se la pila è vuota. Restituisce 1 (vero) se 'top' è 0, altrimenti 0 (falso).
int emptyStack(stack s)
{
     return s->top == 0;
}

// Funzione per aggiungere (push) un nuovo elemento 'val' alla pila. Se la pila non è piena, l'elemento viene aggiunto e 'top' incrementato.
int push(pren val, stack s)
{
     if (s->top == MAXSTACK) // Controlla se la pila è piena.
	return 0; // Restituisce 0 se non c'è spazio per aggiungere un nuovo elemento.
     s->vet[s->top] = val; // Inserisce l'elemento nella posizione corrente di 'top'.
     (s->top)++; // Incrementa 'top'.
      return 1; // Restituisce 1 per indicare che l'elemento è stato aggiunto con successo.
}

// Funzione per rimuovere (pop) l'elemento in cima alla pila. Se la pila non è vuota, 'top' viene decrementato.
int pop(stack s)
{
      if (s->top == 0) // Controlla se la pila è vuota.
	return 0; // Restituisce 0 se non ci sono elementi da rimuovere.
      (s->top)--; // Decrementa 'top'.
      return 1; // Restituisce 1 per indicare che l'elemento è stato rimosso con successo.
}

// Funzione per accedere all'elemento in cima alla pila senza rimuoverlo. Se la pila non è vuota, restituisce l'elemento in cima.
pren top(stack s)
{
      pren e;
      if(s->top > 0) // Controlla se ci sono elementi nella pila.
	e = s->vet[s->top-1]; // Assegna all'elemento 'e' l'elemento in cima alla pila.
      else 
             e = NULLITEM; // Se la pila è vuota, assegna a 'e' un valore predefinito che indica nessun elemento.
      return e; // Restituisce l'elemento in cima alla pila.
}