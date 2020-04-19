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
Döngüsel kutruk sisteminde tüm tahsisat iþin baþýnda bir hamlede yapýlýr.
Dolayýsýyla her eleman eklendiðinde yeniden tahsisat yapýlmaz. Baðlý liste
kuyruk sistemine göre bu yu yüzden daha hýzlý olma eðilimindedir. Öte yandan
baðlý listeli kuyruk sisteminde kuyruðun uzunluðu baþtan sýnýrlý deðildir. 
Heap alaný yettikçe kuyruða eleman eklenebilir. O halde eleman sayýsý belli olan
ve bu sayýnýn çok büyük olmadýðý sistemlerde döngüsel kuyruk sistemi, diðer
sistemlerde ise baðlý listeli kuyruk sistemi tercih edilebilir. Bellek tahsisat
iþleminin pek çok durumda O(N) kamaþýklýkta olduðu düþünülürse kuyruða eleman
ekleme iþlemi döngüsel kuyruk sisteminde O(1) karmaþýklýkta, baðlý listeli kuyruk
sisteminde ise O(N) karmaþýklýktadýr. Kuyruktan eleman alma iþlemi her iki 
sistemde de O(1) karmaþýklýktadýr.

*/