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
Stack, LIFO çalýþan bir kuyruk sistemi. Last in First Out.
Kýsacasý bir kuyruk sistemi ancak kuyruktan eleman alýndýðýnda
ilk eklenen deðil son eklenen alýnýr.
Örnek olarak 10-20-30 kuyruða eklendi, alýrken son eklenen olan
30 alýnýr. Tekrar alýnacak olsa 20 alýnýr.
Doðada da stack sistemi ile karþýlaþýlýr. Bir asansöre insanlar 
binerken, her binen ileri gider, çýkarken ise en son çýkar.
Tabaklar üst üste konulduðunda bir yýðýn oluþur, yýkanacaðý zaman
en son eklenen önce yýkanýr.
Son yerleþtirilen bilgi ilk olarak alýnýr.
Stack'e eleman ekleyen fonksiyonlara push, stackden eleman almaya
yarayan fonksiyonlar ise pop diye isimlendirilir.
Push ve Pop iþlemleri O(1) karmaþýkllýkta gerçekleþtirilmektedir.
Undo mekanizmasý bir stack sistemini kullanýr.(son yapýlan deðiþikliði
ilk geri alýrýz)
Stack sistemleri de iki biçimde gerçekleþtirilirler, dizilerle ve baðlý
listelerle. Dizi yöteminde stack bir dizi olarak oluþturulur. Bir stack
pointer denen bir gösterici veya indeks sona çekilir. Stack'e biþey 
atýldýðýnda, stack pointer bir geriye alýnýp eleman yerleþtirilir. Pop 
yapýlacaðý zaman ise stack pointer'ýn olduðu yerden eleman alýnýp, stack
pointer bir ileri götürülür. Çok fazla push yapýldýðýnda dizi yukarýdan
taþar, buna stack overflow denir. Çok fazla pop yapýldýðýnda ise dizi
aþaðýdan taþar buna da stack underflow denir.
Ýþin baþýnda stack göstericisi dizinin sonundadýr.
Stack pointer sona alýnýp, her push yapýldýðýnda yukarý çýkartýlýr.
Baðlý liste tekniðinde push iþlemi sýrasýnda baðlý listenin önüne
eleman eklenir, pop iþleminde de baðlý listenin önündeki eleman alýnýr.
*/