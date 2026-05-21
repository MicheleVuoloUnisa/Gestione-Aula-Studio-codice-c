//file header di prenotazione

#define NULLITEM 0
//definizione del puntatore opaco
typedef struct pre* prenotazione;
//definizione dei prototipi
prenotazione creaPrenotazione(char mat[11], int giorno,int mese,int anno,int posto,int inizioOra,int fineOra);
char* getMatricola(prenotazione p);
int getPostoAssegnato(prenotazione p);
int getGiornoPrenotazione(prenotazione p);
int getMesePrenotazione(prenotazione p);
int getAnnoprenotazione(prenotazione p);
int getInizioOra(prenotazione p);
int getFineOra(prenotazione p);
int getStato(prenotazione p);
int setStato(prenotazione p);
int annullaPrenotazione(prenotazione p);