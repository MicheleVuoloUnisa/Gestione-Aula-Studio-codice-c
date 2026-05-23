
// file stack.h

// Definisce un tipo di dati per la pila come puntatore a struct c_stack. Questo è comune in C per nascondere l'implementazione effettiva della struttura, 
//fornendo un livello di astrazione.
typedef struct c_stack *stack;

// Dichiarazione di funzioni (o prototipi) che saranno implementate altrove. Queste funzioni consentono di manipolare la pila.

// newStack: crea e restituisce una nuova pila. È una funzione senza parametri che restituisce un puntatore a una struttura di tipo 'stack'.
stack newStack(void);

// emptyStack: verifica se la pila è vuota. Prende come parametro un puntatore a una pila e restituisce un intero, tipicamente 0 per falso (non vuota) e 1 per vero (vuota).
int emptyStack(stack s);

// pop: rimuove l'elemento in cima alla pila e restituisce il suo valore. Prende un puntatore a una pila come parametro. La funzione potrebbe restituire un valore che indica l'elemento rimosso o un codice di errore se la pila è vuota.
int pop(stack s);

// push: aggiunge un nuovo elemento (val) in cima alla pila. Prende un valore da aggiungere e un puntatore alla pila come parametri. Restituisce un intero che potrebbe indicare il successo o il fallimento dell'operazione.
int push(pren val, stack s);

// top: restituisce l'elemento in cima alla pila senza rimuoverlo. Prende un puntatore a una pila come parametro. Si presume che 'pren' sia un tipo di dati definito altrove nel codice.
pren top (stack s);