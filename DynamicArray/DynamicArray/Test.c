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
C'de diziler açýlýrken boyutu sabit ifadesi olarak belirtilir.
Dinamik dizilerde, dinamik bellek alaný kullanýlarak dizi boyutu
gerektiði zamanlarda sürekli büyütülür.
Dinamik dizi uygulamasýnda öncelikle dizi için küçük bir alan tahsis
edilir. Bu alan dolduðunda yeniden tahsisat yapýlýr. Tabi eski alandaki
bilgiler yeni alana kopyalanýr ve eski alan serbest býrakýlýr. Dizi için
tahsis edilmiþ olan toplam alana capacity, dolu olan eleman sayýsýna ise
size veya count denir.
Dinamik diziye eleman eklenirken eleman "size" ile belirtilen indekse 
eklenir size arttýrýlýr. size deðeri capacity deðerine geldiðinde yeniden
tahsisat yapýlýr. Capacity ne kadar arttýrýlýr ?
Capacity deðeri eskisinin katý olarak arttýrýlýrsa(yani geometrik olarak
arttýrýlýrsa) sona eleman ekleme iþlemi sabit karmaþýklýða yaklaþýr. Eðer
capacity deðeri eskisinden N fazla olacak biçimde arttýrýlýrsa bu durumda 
sona eleman ekleme iþlemi doðrusal karmaþýklýða yaklaþýr. Geometrik arttýrýmdaki
sona eleman ekleme karmaþýlýðýna "ek maliyetli sabit zamanlý karmaþýklýk" denir
(amortized constant time complexity), bu iþlemin çoðu kez sabit karmaþýklýkta ancak
üstel aralýklarla doðrusal karmaþýklýkta yapýlmasý demektir.
Örneðin arttýrýmýn hep beþer beþer yapýldýðý düþünülsün. Bu durumda dinamik 
dizinin sonuna eleman ekleme sýrasýnda her 5 eklemede bir yeniden tahsisat
yapýlacaktýr. Bu yeniden tahsisat iþlemi sýrasýnda doðrusal karmaþýklýkta bir
kopyalama iþlemi devreye girer. Bu durumda sona eleman ekleme iþlemi aslýnda
doðrusal karmaþýklýktadýr. Yani biz her eklemeyi 1/5 kadar dönen bir döngü ile
yaptýðýmýzý düþünebiliriz. Halbuki büyütme eskisinin iki katý kadar yapýlýrsa sona 
eleman ekleme iþlemi her beþte bir deðil logaritmik bir karmaþýklýða çekilir.
Yani arada sýrada nadiren tahsisat yapacaktýr, iþte buna amortized constant time
denilir.

Dinamik dizilerde elemana eriþim normal dizilerde olduðu gibi sabit karmaþýklýkta
yani O(1) karmaþýklýktadýr. Araya eleman ekleme ve aradan eleman silme iþlemi ise 
doðrusal yani O(N) karmaþýklýkta.




*/