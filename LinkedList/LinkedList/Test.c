#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


BOOL DispItem(DATATYPE *pVal)
{
	printf("%d ", *pVal);

	return TRUE;
}

BOOL MyComparer(const DATATYPE *pVal)
{
	if (*pVal == 5)
		return TRUE;

	return FALSE;
}

int main()
{
	HLLIST hLList;
	int i = 0;
	NODE *pNode, *pDelNode;
	DATATYPE *pVal;

	if ((hLList = CreateLList()) == NULL) {
		fprintf(stderr, "cannot create linked list!\n");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < 10; ++i){
		if ((pNode = AddItemTail(hLList, i)) == NULL) {
			fprintf(stderr, "cannot add node!.\n");
			exit(EXIT_FAILURE);
		}
		if (i == 5)
			pDelNode = pNode;
	}

	WalkList(hLList, DispItem);
	printf("\n");

	DeleteItemIndex(hLList, 7);

	WalkList(hLList, DispItem);
	printf("\n");

	
	pVal = FindItem(hLList, MyComparer);

	printf("Found: %d\n", *pVal);

	printf("Total Item: %u\n", GetCount(hLList));

	CloseList(hLList);

}


/* Notlar */
/*
Elemanlar� bellekte ard���l olmayan, farkl� yerlerde olan veri yap�s�.
�nceki eleman, sonraki eleman� pointer kullanarak g�sterir.
Bu durumda ilk eleman�n yerinin bilinmesi yeterli.
Bir d���m(Node) tutaca�� veri d���nda bir sonraki d���m�n adresini de tutar.
Bu sebeple d���mler yap�lar ile temsil edilir.
Baz� durumlarda dizilere g�re avantaj� mevcut. 
Son eleman�n g�stericisinde NULL olabilir.
Yap�n�n bir eleman� ger�ekten dizi eleman� gibi tutulacak bilgiyi i�erir di�er 
eleman ise bir sonraki node'un adresini tutar.
Genellikle ba�l� listenin ilk d���m�n�n adresine head son d���m�n adresine ise
tail denir.
Bir ba�l� listede her d���m yaln�zca kendinden sonraki d���m�n adresini tutuyorsa
buna tek ba�l� liste denir.(single linked list)
Her d���m ayn� zamanda kendisinden bir �ncekinin de adresini tutuyorsa buna �ift
ba�l� liste denir.(doubly linked list). Burada ise Node'da datatype'a ilaveten
iki tane pointer olur: struct Node *pNext ve struct Node *pPrev.
�o�u zaman ba�l� listenin ilk d���m�n�n ve son d���m�n�n yeri de tutulur.

struct NODE{
	DATATYPE val;
	struct NODE *pNext;
	struct NODE *pPrev;

}

Ba�l� listelerde belirli indeksteki elemana eri�mek do�rusal kama��kl�ktad�r. Yani be�inci
elemana eri�mek istendi�inde gezerek eri�ilir, d�ng� kullan�l�r. Bir algoritmada d�ng� varsa
onun karma��kl��� O(N).
Fakat ba�l� listelerde bir d���m�n yeri biliniyorsa oraya eleman eklemek sabit karma��kl�ktad�r.
Benzer bi�imde de e�er d���m�n yerini biliyorsak eleman silme i�lemi de sabit karma��kl�ktad�r.
Ba�l� listelerin ba��na ve sonuna eleman ekleme de yine sabit karma��kl�kta bir i�lemdir.

�ift ba�l� listelerde sadece ileri de�il geri de gidilebilir. Tek ba�l� liste etkin bi�imde tersten
dola��lamaz. �ift ba�l� listlelerin en �nemli kullan�m sebebi eleman silme i�lemleri i�indir. �ift
ba�l� listelerde bir eleman�n adresi biliniyorsa, eleman sabit karma��kl�kta silinebilir. Tek ba�l�
listelerde ise adresi bilinen eleman sabit yani O(1) karma��kl�kta silinemez, ancak onun �n�ndeki
eleman silinebilir.

Neden Diziler yerine Ba�l� Listeler Kullan�ls�n ?
1)Elemanlar bellekte ard���l olarak bulunmak zorunda de�il. Ard���l bellek sorununun oldu�u durumlarda
ba�l� listeler tercih edilirler. Ard���ll�k b�l�nmeye(fragmentation) neden olur. �zellikle �ok say�da
ayn� b�lgeyi(�rne�in heap'i) kullanan dinamik diziler s�z konusu oldu�u durumlarda ba�l� listeler belle�in
daha verimli kullan�lmas�n� sa�lamaktad�r.
2)�ok say�da insert delete i�lemlerinin yap�ld��� durumlarda ba�l� listeler tercih edilir. 

Ba�l� Lisleter ile Dizilerin Kar��la�t�r�lmas�:
1)Belirli bir indeksteli eri�im dizilerde sabit zamanl�d�r fakat ba�l� listelerde do�rusal karma��kl�kta.
Elemana dizilerde daha h�zl� eri�ilir.
2)D���m� bilinen bir eleman�n �n�ne veya gerisine insert i�lemi ba�l� listelerde sabit zamanl�d�r ancak 
dizilerde do�rusal karma��kl�kta.
3)D���m adresi bilinen bir eleman�n silinmesi ba�l� listelerde sabit karma��kl�ktad�r ancak dizilerde
do�ursal karma��kl�ktad�r. 
4)Ba�a eleman ekleme dizilerde do�rusal karma��kl�ktad�r, ba�l� listelerde ise sabit karma��kl�kta. Sona
eleman ekleme i�lemi her ikisinde de sabiy karma��kl�ktad�r.
*/