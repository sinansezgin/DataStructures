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
Kuyruk Veri Yap�s�(Queue):
FIFO prensibi ile �al��an veri yap�s�. First in First out. Kuyruk veri yap�s�nda eleman
insert etme, dola�ma yok. 
�ki temel eleman var: kuyru�a eleman eklemek ve kuyruktan eleman almak. 10, 20, 30 s�ras� ile 
eklendi, eleman al�nacaksa da �nce 10 sonra 20 al�n�r. Kuyru�a �nce Ali sonra Veli sonra Selahattin 
eklendi, eleman al�nacakken �nce Ali sonra Veli al�n�r.
Genellikle kuyru�a eleman ekleme i�in ingilizce put s�zc��� veya inqueue kullan�l�r.
Kuyruktan eleman almak i�inse get veya dequeue s�zc�kleri kullan�l�r.
Bir taraf i�liyor bir taraf tedarik ediyor ancak ayn� h�zda de�iller do�al olarak bir birikme olur.
S�ran�n bozulmamas� isteniyorsa daha �nce tedarik edilenler daha �nce i�lenir.
Bilgilerin s�ras� bozulmadan ge�ici bir s�re bekletmek i�in kullan�l�r, buffer sistemleri i�in.
Klavyeden tu�lara bas�ld���nda asl�nda her tu�a bas�lan bilgi kuyru�a yerle�tirilir ve s�ras� ile
kuyruktan al�n�r, kaybedilmez.
Elemanlar sona eklenir, ba�tan al�n�r. Kuyruktan al�nan eleman ayn zamanda silinmektedir.
Yemek kuyru�u bilgisayarda simule edilmek istense kuyruk veri yap�s� kullan�l�r.
Yaz�c�ya birden fazla i� g�nderilirse yaz�c� bunlar� kuyruk sisteminde saklar ve yazd�rma i�lemini
bu s�rada ger�ekle�tirir.

Kuyruk Veri Yap�s�n�n Ger�ekle�tirilmesi:
Kuyruklar �� bi�imde ger�ekle�tirilebilirler. 
En basit y�ntem dizi y�ntemidir ancak iyi bir sistem de�ildir. Bir dizi a��l�r. Kuyru�un sonu bir
indeks veya pointerda tutulur. Eleman eklendik�e indis bir sonray� g�sterecek hale getirilir.
Eleman al�rken de ba�tan al�n�r, t�m di�er elemanlar bir geri kayd�r�l�r indis de bir geri �ekilir.
Dizi kayd�rmaya yol a�t��� i�in iyi bir y�ntem de�il.

Onun yerine kayd�rmaya gerek olmayan d�ng�sel sistem kullan�l�r.
Bir g�sterici veya indekse head g�stericisi denir. Di�erine ise tail g�stericisi denir. Kuyru�un ba��n�
g�sterirler. Bir de kuyruktaki eleman say�s� tutulur. Eleman tailin g�sterdi�i yere eklenir ve tail bir
artt�r�l�r. Eleman al�rken ise eleman head'in g�sterdi�i yerden al�n�r ve head bir artt�r�l�r.
Dizinin sonuna gelindiyse ve eleman eklenecekse, tail tekrar ba�a �ekilir kontrol yap�l�p. 
Ayn� �ekilde eleman al�rken sona gelindiyse head yine kontrol yap�l�p ba�a �ekilir.
head ve tail birbirine e�it oldu�unda kuyruk tam dolu da olabilir bo� da olabilir orada count'a bakmak
gerekir. D�ng�sel y�ntemde kuyruk i�in gereken alan i�in ba��nda tahsis edilmek zorunda. 

Son y�ntem ise ba�l� liste y�ntemi. Ba�l� listenin sonuna eleman eklenir, ba��ndan eleman al�n�r.
��letim sistemleri ba�l� liste y�ntemini de s�k kullan�r.
Bu y�ntemde kuyruk dinamik olarak b�y�t�p k���lt�lebilir.
Dinamik tahsisat sistemleri genel olarak O(N) karma��kl�kta ama avantaj� alan�n b�y�t�lebilmesi.


*/