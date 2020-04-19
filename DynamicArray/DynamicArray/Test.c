#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

int main() {

	HDARRAY hDArray;
	size_t i;
	DATATYPE val;
	DATATYPE vals[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	if ((hDArray = CreateDArrayWithArray(vals, 10)) == NULL) {
		fprintf(stderr, "Can not create Dynamic Array!\n");
		exit(EXIT_FAILURE);
	}

	Remove(hDArray, 40);
	DeleteItem(hDArray, 2);

	for (i = 0; i < GetSize(hDArray); ++i) {
		val = GetItem(hDArray, i);
		printf("%d ", val);
	}

	printf("\n");
	
	CloseDArray(hDArray);

	return 0;
}



/*Notlar
C'de diziler a��l�rken boyutu sabit ifadesi olarak belirtilir.
Dinamik dizilerde, dinamik bellek alan� kullan�larak dizi boyutu
gerekti�i zamanlarda s�rekli b�y�t�l�r.
Dinamik dizi uygulamas�nda �ncelikle dizi i�in k���k bir alan tahsis
edilir. Bu alan doldu�unda yeniden tahsisat yap�l�r. Tabi eski alandaki
bilgiler yeni alana kopyalan�r ve eski alan serbest b�rak�l�r. Dizi i�in
tahsis edilmi� olan toplam alana capacity, dolu olan eleman say�s�na ise
size veya count denir.
Dinamik diziye eleman eklenirken eleman "size" ile belirtilen indekse 
eklenir size artt�r�l�r. size de�eri capacity de�erine geldi�inde yeniden
tahsisat yap�l�r. Capacity ne kadar artt�r�l�r ?
Capacity de�eri eskisinin kat� olarak artt�r�l�rsa(yani geometrik olarak
artt�r�l�rsa) sona eleman ekleme i�lemi sabit karma��kl��a yakla��r. E�er
capacity de�eri eskisinden N fazla olacak bi�imde artt�r�l�rsa bu durumda 
sona eleman ekleme i�lemi do�rusal karma��kl��a yakla��r. Geometrik artt�r�mdaki
sona eleman ekleme karma��l���na "ek maliyetli sabit zamanl� karma��kl�k" denir
(amortized constant time complexity), bu i�lemin �o�u kez sabit karma��kl�kta ancak
�stel aral�klarla do�rusal karma��kl�kta yap�lmas� demektir.
�rne�in artt�r�m�n hep be�er be�er yap�ld��� d���n�ls�n. Bu durumda dinamik 
dizinin sonuna eleman ekleme s�ras�nda her 5 eklemede bir yeniden tahsisat
yap�lacakt�r. Bu yeniden tahsisat i�lemi s�ras�nda do�rusal karma��kl�kta bir
kopyalama i�lemi devreye girer. Bu durumda sona eleman ekleme i�lemi asl�nda
do�rusal karma��kl�ktad�r. Yani biz her eklemeyi 1/5 kadar d�nen bir d�ng� ile
yapt���m�z� d���nebiliriz. Halbuki b�y�tme eskisinin iki kat� kadar yap�l�rsa sona 
eleman ekleme i�lemi her be�te bir de�il logaritmik bir karma��kl��a �ekilir.
Yani arada s�rada nadiren tahsisat yapacakt�r, i�te buna amortized constant time
denilir.

Dinamik dizilerde elemana eri�im normal dizilerde oldu�u gibi sabit karma��kl�kta
yani O(1) karma��kl�ktad�r. Araya eleman ekleme ve aradan eleman silme i�lemi ise 
do�rusal yani O(N) karma��kl�kta.




*/