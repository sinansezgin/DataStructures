#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

BOOL display(DATATYPE *val)
{
	printf("%d ", *val);

	return TRUE;
}

int main() 
{
	HSTACK hStack;
	int i;

	if ((hStack = CreateStack(10)) == NULL) {
		fprintf(stderr, "cannot create stack!\n");
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < 10; ++i)
		Push(hStack, i);

	Walk(hStack, display);
	printf("\n");

	for (i = 0; i < 5; ++i)
		Pop(hStack);

	Walk(hStack, display);
	printf("\n");
}

/*Notlar
Stack, LIFO �al��an bir kuyruk sistemi. Last in First Out.
K�sacas� bir kuyruk sistemi ancak kuyruktan eleman al�nd���nda
ilk eklenen de�il son eklenen al�n�r.
�rnek olarak 10-20-30 kuyru�a eklendi, al�rken son eklenen olan
30 al�n�r. Tekrar al�nacak olsa 20 al�n�r.
Do�ada da stack sistemi ile kar��la��l�r. Bir asans�re insanlar 
binerken, her binen ileri gider, ��karken ise en son ��kar.
Tabaklar �st �ste konuldu�unda bir y���n olu�ur, y�kanaca�� zaman
en son eklenen �nce y�kan�r.
Son yerle�tirilen bilgi ilk olarak al�n�r.
Stack'e eleman ekleyen fonksiyonlara push, stackden eleman almaya
yarayan fonksiyonlar ise pop diye isimlendirilir.
Push ve Pop i�lemleri O(1) karma��kll�kta ger�ekle�tirilmektedir.
Undo mekanizmas� bir stack sistemini kullan�r.(son yap�lan de�i�ikli�i
ilk geri al�r�z)
Stack sistemleri de iki bi�imde ger�ekle�tirilirler, dizilerle ve ba�l�
listelerle. Dizi y�teminde stack bir dizi olarak olu�turulur. Bir stack
pointer denen bir g�sterici veya indeks sona �ekilir. Stack'e bi�ey 
at�ld���nda, stack pointer bir geriye al�n�p eleman yerle�tirilir. Pop 
yap�laca�� zaman ise stack pointer'�n oldu�u yerden eleman al�n�p, stack
pointer bir ileri g�t�r�l�r. �ok fazla push yap�ld���nda dizi yukar�dan
ta�ar, buna stack overflow denir. �ok fazla pop yap�ld���nda ise dizi
a�a��dan ta�ar buna da stack underflow denir.
��in ba��nda stack g�stericisi dizinin sonundad�r.
Stack pointer sona al�n�p, her push yap�ld���nda yukar� ��kart�l�r.
Ba�l� liste tekni�inde push i�lemi s�ras�nda ba�l� listenin �n�ne
eleman eklenir, pop i�leminde de ba�l� listenin �n�ndeki eleman al�n�r.
*/