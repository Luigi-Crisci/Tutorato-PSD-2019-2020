#include<stdlib.h>
#include<stdio.h>
#include"list_0.1.h"
#include"item.h"

void printList(list l){
	list tmp;
	tmp = l; //Questo è necessario per poter mantenere un riferimento alla testa della lista, in quanto
			 //tailList() su l vi farebbe perdere il riferimento all'elemento precedente
	for (int i = 0; !emptyList(tmp); i++, tmp = tailList(tmp))
	{
		printf("Item numero %i: ",i);
		fflush(stdout);
		output_item(getFirst(tmp));	
	}
	printf("\n");
}

/**
 * Prende in input 10 elementi, li stampa e poi cancella l'ultimo elemento
 */
int main(){
    list l = newList();
	item e;
	
	//Prendo i 10 elementi in input
	for (int i = 0; i < 10; i++)
	{
		input_item(&e);
		l = consList(e,l);
	}

	//Stampo gli elementi
	printList(l);

	//Arrivo all'ultimo elemento
	list tmp = l; //resetto la posizione del puntatore
	list prec,prec_2;
	//Mando avanti la mia lista fino all'ultimo elemento, salvandomi sempre il precedente
	//In questo modo, quando tmp == NULL, prec punterà all'ultimo elemento e prec_2 a quello precedente a prec
	while (!emptyList(tmp))
	{
		prec_2 = prec;
		prec = tmp;
		tmp = tailList(tmp);
	}

	free(prec); //Elimino il nodo dalla memoria
	truncate(prec_2); //Setto il campo next dell'elemento precedente di prec a NULL, così da mantenere la struttura della lista
	
	//Controllo il risultato
	printList(l);
	
	return 1;
}
 