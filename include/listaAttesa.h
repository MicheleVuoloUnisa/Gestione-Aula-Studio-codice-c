// file queue.h
#include "prenotazione.h"
typedef struct c_queue *queue;
// prototipi delle funzioni
queue nuovaCoda(void);
int codaVuota(queue q);
prenotazione dequeue(queue q); 
int inserisciInCoda(prenotazione val, queue q);