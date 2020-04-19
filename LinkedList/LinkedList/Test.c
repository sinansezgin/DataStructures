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
Elemanlarý bellekte ardýþýl olmayan, farklý yerlerde olan veri yapýsý.
Önceki eleman, sonraki elemaný pointer kullanarak gösterir.
Bu durumda ilk elemanýn yerinin bilinmesi yeterli.
Bir düðüm(Node) tutacaðý veri dýþýnda bir sonraki düðümün adresini de tutar.
Bu sebeple düðümler yapýlar ile temsil edilir.
Bazý durumlarda dizilere göre avantajý mevcut. 
Son elemanýn göstericisinde NULL olabilir.
Yapýnýn bir elemaný gerçekten dizi elemaný gibi tutulacak bilgiyi içerir diðer 
eleman ise bir sonraki node'un adresini tutar.
Genellikle baðlý listenin ilk düðümünün adresine head son düðümün adresine ise
tail denir.
Bir baðlý listede her düðüm yalnýzca kendinden sonraki düðümün adresini tutuyorsa
buna tek baðlý liste denir.(single linked list)
Her düðüm ayný zamanda kendisinden bir öncekinin de adresini tutuyorsa buna çift
baðlý liste denir.(doubly linked list). Burada ise Node'da datatype'a ilaveten
iki tane pointer olur: struct Node *pNext ve struct Node *pPrev.
Çoðu zaman baðlý listenin ilk düðümünün ve son düðümünün yeri de tutulur.

struct NODE{
	DATATYPE val;
	struct NODE *pNext;
	struct NODE *pPrev;

}

Baðlý listelerde belirli indeksteki elemana eriþmek doðrusal kamaþýklýktadýr. Yani beþinci
elemana eriþmek istendiðinde gezerek eriþilir, döngü kullanýlýr. Bir algoritmada döngü varsa
onun karmaþýklýðý O(N).
Fakat baðlý listelerde bir düðümün yeri biliniyorsa oraya eleman eklemek sabit karmaþýklýktadýr.
Benzer biçimde de eðer düðümün yerini biliyorsak eleman silme iþlemi de sabit karmaþýklýktadýr.
Baðlý listelerin baþýna ve sonuna eleman ekleme de yine sabit karmaþýklýkta bir iþlemdir.

Çift baðlý listelerde sadece ileri deðil geri de gidilebilir. Tek baðlý liste etkin biçimde tersten
dolaþýlamaz. Çift baðlý listlelerin en önemli kullaným sebebi eleman silme iþlemleri içindir. Çift
baðlý listelerde bir elemanýn adresi biliniyorsa, eleman sabit karmaþýklýkta silinebilir. Tek baðlý
listelerde ise adresi bilinen eleman sabit yani O(1) karmaþýklýkta silinemez, ancak onun önündeki
eleman silinebilir.

Neden Diziler yerine Baðlý Listeler Kullanýlsýn ?
1)Elemanlar bellekte ardýþýl olarak bulunmak zorunda deðil. Ardýþýl bellek sorununun olduðu durumlarda
baðlý listeler tercih edilirler. Ardýþýllýk bölünmeye(fragmentation) neden olur. Özellikle çok sayýda
ayný bölgeyi(örneðin heap'i) kullanan dinamik diziler söz konusu olduðu durumlarda baðlý listeler belleðin
daha verimli kullanýlmasýný saðlamaktadýr.
2)Çok sayýda insert delete iþlemlerinin yapýldýðý durumlarda baðlý listeler tercih edilir. 

Baðlý Lisleter ile Dizilerin Karþýlaþtýrýlmasý:
1)Belirli bir indeksteli eriþim dizilerde sabit zamanlýdýr fakat baðlý listelerde doðrusal karmaþýklýkta.
Elemana dizilerde daha hýzlý eriþilir.
2)Düðümü bilinen bir elemanýn önüne veya gerisine insert iþlemi baðlý listelerde sabit zamanlýdýr ancak 
dizilerde doðrusal karmaþýklýkta.
3)Düðüm adresi bilinen bir elemanýn silinmesi baðlý listelerde sabit karmaþýklýktadýr ancak dizilerde
doðursal karmaþýklýktadýr. 
4)Baþa eleman ekleme dizilerde doðrusal karmaþýklýktadýr, baðlý listelerde ise sabit karmaþýklýkta. Sona
eleman ekleme iþlemi her ikisinde de sabiy karmaþýklýktadýr.
*/