#include <stdio.h>
#include "Queue.h"

int main()
{

	HQUEUE hQueue;
	DATATYPE i;
	DATATYPE val;

	if ((hQueue = CreateQueue()) == NULL) {
		fprintf(stderr, "cannot create queue!...\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; ++i)
		PutItem(hQueue, i);

	while (!IsEmpty(hQueue)) {
		GetItem(hQueue, &val);
		printf("%d ", val);
	}

	printf("\n");

	CloseQueue(hQueue);
}


/*Notlar
D�ng�sel kutruk sisteminde t�m tahsisat i�in ba��nda bir hamlede yap�l�r.
Dolay�s�yla her eleman eklendi�inde yeniden tahsisat yap�lmaz. Ba�l� liste
kuyruk sistemine g�re bu yu y�zden daha h�zl� olma e�ilimindedir. �te yandan
ba�l� listeli kuyruk sisteminde kuyru�un uzunlu�u ba�tan s�n�rl� de�ildir. 
Heap alan� yettik�e kuyru�a eleman eklenebilir. O halde eleman say�s� belli olan
ve bu say�n�n �ok b�y�k olmad��� sistemlerde d�ng�sel kuyruk sistemi, di�er
sistemlerde ise ba�l� listeli kuyruk sistemi tercih edilebilir. Bellek tahsisat
i�leminin pek �ok durumda O(N) kama��kl�kta oldu�u d���n�l�rse kuyru�a eleman
ekleme i�lemi d�ng�sel kuyruk sisteminde O(1) karma��kl�kta, ba�l� listeli kuyruk
sisteminde ise O(N) karma��kl�ktad�r. Kuyruktan eleman alma i�lemi her iki 
sistemde de O(1) karma��kl�ktad�r.

*/