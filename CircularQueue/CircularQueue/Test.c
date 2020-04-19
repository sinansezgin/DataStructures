#include <stdio.h>
#include "Queue.h"

int main()
{

	HQUEUE hQueue;
	DATATYPE i;
	DATATYPE val;

	if ((hQueue = CreateQueue(10)) == NULL) {
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
Kuyruk Veri Yapýsý(Queue):
FIFO prensibi ile çalýþan veri yapýsý. First in First out. Kuyruk veri yapýsýnda eleman
insert etme, dolaþma yok. 
Ýki temel eleman var: kuyruða eleman eklemek ve kuyruktan eleman almak. 10, 20, 30 sýrasý ile 
eklendi, eleman alýnacaksa da önce 10 sonra 20 alýnýr. Kuyruða önce Ali sonra Veli sonra Selahattin 
eklendi, eleman alýnacakken önce Ali sonra Veli alýnýr.
Genellikle kuyruða eleman ekleme için ingilizce put sözcüðü veya inqueue kullanýlýr.
Kuyruktan eleman almak içinse get veya dequeue sözcükleri kullanýlýr.
Bir taraf iþliyor bir taraf tedarik ediyor ancak ayný hýzda deðiller doðal olarak bir birikme olur.
Sýranýn bozulmamasý isteniyorsa daha önce tedarik edilenler daha önce iþlenir.
Bilgilerin sýrasý bozulmadan geçici bir süre bekletmek için kullanýlýr, buffer sistemleri için.
Klavyeden tuþlara basýldýðýnda aslýnda her tuþa basýlan bilgi kuyruða yerleþtirilir ve sýrasý ile
kuyruktan alýnýr, kaybedilmez.
Elemanlar sona eklenir, baþtan alýnýr. Kuyruktan alýnan eleman ayn zamanda silinmektedir.
Yemek kuyruðu bilgisayarda simule edilmek istense kuyruk veri yapýsý kullanýlýr.
Yazýcýya birden fazla iþ gönderilirse yazýcý bunlarý kuyruk sisteminde saklar ve yazdýrma iþlemini
bu sýrada gerçekleþtirir.

Kuyruk Veri Yapýsýnýn Gerçekleþtirilmesi:
Kuyruklar üç biçimde gerçekleþtirilebilirler. 
En basit yöntem dizi yöntemidir ancak iyi bir sistem deðildir. Bir dizi açýlýr. Kuyruðun sonu bir
indeks veya pointerda tutulur. Eleman eklendikçe indis bir sonrayý gösterecek hale getirilir.
Eleman alýrken de baþtan alýnýr, tüm diðer elemanlar bir geri kaydýrýlýr indis de bir geri çekilir.
Dizi kaydýrmaya yol açtýðý için iyi bir yöntem deðil.

Onun yerine kaydýrmaya gerek olmayan döngüsel sistem kullanýlýr.
Bir gösterici veya indekse head göstericisi denir. Diðerine ise tail göstericisi denir. Kuyruðun baþýný
gösterirler. Bir de kuyruktaki eleman sayýsý tutulur. Eleman tailin gösterdiði yere eklenir ve tail bir
arttýrýlýr. Eleman alýrken ise eleman head'in gösterdiði yerden alýnýr ve head bir arttýrýlýr.
Dizinin sonuna gelindiyse ve eleman eklenecekse, tail tekrar baþa çekilir kontrol yapýlýp. 
Ayný þekilde eleman alýrken sona gelindiyse head yine kontrol yapýlýp baþa çekilir.
head ve tail birbirine eþit olduðunda kuyruk tam dolu da olabilir boþ da olabilir orada count'a bakmak
gerekir. Döngüsel yöntemde kuyruk için gereken alan iþin baþýnda tahsis edilmek zorunda. 

Son yöntem ise baðlý liste yöntemi. Baðlý listenin sonuna eleman eklenir, baþýndan eleman alýnýr.
Ýþletim sistemleri baðlý liste yöntemini de sýk kullanýr.
Bu yöntemde kuyruk dinamik olarak büyütüp küçültülebilir.
Dinamik tahsisat sistemleri genel olarak O(N) karmaþýklýkta ama avantajý alanýn büyütülebilmesi.


*/