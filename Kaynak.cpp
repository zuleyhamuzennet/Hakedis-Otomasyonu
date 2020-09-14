

#include <iostream>
#include <fstream>
#include <windows.h>
//2020
using namespace std;
void DosyayaUrunYazdir(string dosyayolu, int urunNo, string urunAdi, string Birim, string birimFiyati, string Markasi) {
	ofstream DosyaYaz;//Dosya çýkýþý yapabilmek için gerekli kod.
	DosyaYaz.open(dosyayolu, ios::app); //Urunler.txt dosyasýný dosya ekleme modunda açtým
	DosyaYaz << endl << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi; // urunler.txtye yazdýrdýk
}
int main() {

	//Urunler.txt için
	int urunNo;
	string urunAdi;
	string Birim;
	int birimFiyati;
	string Markasi;
	//Projeler.txt için
	int projeNo; // Her proje için ayrý deðer
	string projeAdi;
	string yurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;
	//Hakedis.txt için
	int hakedisDönemi;
	int kullanilanUrun;
	int kullanilanUrunAdetleri;
	int kullanilanUrunFiyatlari;


	char genelcvp = 'e';
	int secim;
	do // genel yapmak istediði varmi diye soruyoruz
	{
		do // secimi doðru girmesini saðlýyoruz
		{
			cout << " Ne yapmak istiyorsunuz ?" << endl;
			cout << " 1) Urun Ekleme" << endl;
			cout << " 2) Urun Silme" << endl;
			cout << " 3) Urun Arama" << endl;
			cout << " 4) Raporlama(Urun)" << endl;
			cout << " 5) Proje Ekleme" << endl;
			cout << " 6) Proje Silme(hakedis verilmisler silinemez)" << endl;
			cout << " 7) Proje Arama" << endl;
			cout << " 8) Raporlama(Proje)" << endl;
			cout << " 9) Kullanilan Urun Ekleme(Hakedise)" << endl;
			cout << " 10) Kullanilan Urun Silme(Hakedisten)" << endl;
			cout << " 11) Kullanilan urun guncelleme(hakedisten)" << endl;
			cout << " 12) Kullanilan urunleri listele(hakediste)" << endl;
			cout << " 13) Kullanilan urunlerde arama(Hakedisten)" << endl;
			cout << " 14) Raporlama" << endl; // GENEL RAPOR ÝÇÝN LÜTFEN BURAYI KULLANIN ÝÇERÝDE TEKRAR RAPOR DETAYI SORULACAKTIR // eksiiiik
			cin >> secim;
		} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9 && secim != 10 && secim != 11 && secim != 12 && secim != 13 && secim != 14);


		if (secim == 1) // Urun Ekleme
		{
			int temp;
			string temp1, temp2;
			int temp3;
			string temp4;
			bool yokmu = true;
			system("cls"); // ekraný temizliyoruz

			cout << "-------YENI URUN-------" << endl;

			ofstream DosyaYaz;//Dosya çýkýþý yapabilmek için gerekli kod.
			DosyaYaz.open("Urunler.txt", ios::app); //Urunler.txt dosyasýný dosya ekleme modunda açtým
			ifstream DosyaOku;//Dosya çýkýþý yapabilmek için gerekli kod.
			DosyaOku.open("Urunler.txt", ios::app); //Urunler.txt dosyasýný dosya ekleme modunda açtým

			cout << "-----------URUN KAYDI--------------" << endl;
			cout << " Urun NO                           :"; cin >> urunNo; //bilgileri aldýk
			cout << " Urun Adi                          :"; cin >> urunAdi;
			cout << " Birim                             :"; cin >> Birim;
			cout << " Birim Fiyati                      :"; cin >> birimFiyati;
			cout << " Markasi                           :"; cin >> Markasi;
			while (!DosyaOku.eof()) {
				DosyaOku >> temp >> temp1 >> temp2 >> temp3 >> temp4;
				if (temp == urunNo) {
					cout << " bu urunu eklemissiniz" << endl;
					yokmu = false;
				}
			}
			if (yokmu)
				DosyaYaz << endl << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi; // urunler.txtye yazdýrdýk

			cout << "Urun Kayidi Tamamlandi" << endl; //Kayýt bittiðinde ekrana olumlu bir sonuç yazýsý yazdýrdým.

			DosyaYaz.close(); // Dosyayý kapatýyoruz
		}
		if (secim == 2) //Urun silme
		{
			system("cls"); //ekrani temizledik

			cout << "-------URUN SILME-------" << endl;

			int NO;
			int i = 1;
			ofstream DosyaYaz("geciciurunler.tmp", ios::app); //Gecici bir dosya açýlýr
			ifstream DosyaOku("Urunler.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.

			cout << "Silmek istediginiz urun'un NOsunu girin...:"; cin >> NO;

			while (!DosyaOku.eof()) //Urunler.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> urunNo >> urunAdi >> Birim >> birimFiyati >> Markasi; // urunler.txt içindeki bilgileri okuyor.
				if (NO == urunNo)
				{
					cout << "---------- Urun Bilgileri ----------" << endl << endl;

					cout << " Urun NO                       :" << NO << endl; // bilgileri tek tek yazdýrýyor.
					cout << " Urun Adi                      :" << urunAdi << endl;
					cout << " Birim                         :" << Birim << endl;
					cout << " Birim Fiyati                  :" << birimFiyati << endl;
					cout << " Markasi                       :" << Markasi << endl;
					cout << " -------Silme islemi tamamlandi-------" << endl;
				}
				else//urunler.txt içinde noyu bulamaz ise urunlergecici.tmp ye yazdýrýyor
				{
					DosyaYaz << endl << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
				}
			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
			DosyaYaz.close();

			remove("Urunler.txt");// Urunler.txt dosyasý silinirken
			rename("geciciurunler.tmp", "Urunler.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.
		}
		if (secim == 3) //Urun arama
		{
			system("cls"); //ekrani temizledik

			cout << "-------URUN ARAMA-------" << endl;

			int NO;
			int i = 1;
			ofstream DosyaYaz("geciciurunler.tmp", ios::app); //Gecici bir dosya açýlýr
			ifstream DosyaOku("Urunler.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.

			cout << "Aramak istediginiz urun'un NOsunu girin...:"; cin >> NO;

			while (!DosyaOku.eof()) //Urunler.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> urunNo >> urunAdi >> Birim >> birimFiyati >> Markasi; // urunler.txt içindeki bilgileri okuyor.
				if (NO == urunNo)
				{
					cout << "---------- Urun Bilgileri ----------" << endl << endl;

					cout << " Urun NO                       :" << NO << endl; // bilgileri tek tek yazdýrýyor.
					cout << " Urun Adi                      :" << urunAdi << endl;
					cout << " Birim                         :" << Birim << endl;
					cout << " Birim Fiyati                  :" << birimFiyati << endl;
					cout << " Markasi                       :" << Markasi << endl;
					cout << " -------Urun Bulundu-------" << endl;

					DosyaYaz << "\n" << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
				}
				else//urunler.txt içinde noyu bulamaz ise urunlergecici.tmp ye yazdýrýyor
				{
					DosyaYaz << "\n" << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
				}
			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
			DosyaYaz.close();


			remove("Urunler.txt");// Urunler.txt dosyasý silinirken
			rename("geciciurunler.tmp", "Urunler.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.
		}
		if (secim == 4) {
			system("cls"); //ekrani temizledik

			cout << "-------URUNLERI LISTELE-------" << endl;

			int i = 1;
			ifstream DosyaOku("Urunler.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.

			while (!DosyaOku.eof()) //Urunler.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> urunNo >> urunAdi >> Birim >> birimFiyati >> Markasi; // urunler.txt içindeki bilgileri okuyor.

				cout << "---------- Urun Bilgileri ----------" << endl << endl;

				cout << " Urun NO                       :" << urunNo << endl; // bilgileri tek tek yazdýrýyor.
				cout << " Urun Adi                      :" << urunAdi << endl;
				cout << " Birim                         :" << Birim << endl;
				cout << " Birim Fiyati                  :" << birimFiyati << endl;
				cout << " Markasi                       :" << Markasi << endl;


			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
		}
		if (secim == 5) {
			bool yokmu = true;
			int temp;
			string temp1, temp2, temp3, temp4;
			system("cls"); // ekraný temizliyoruz

			cout << "-------YENI PROJE-------" << endl;

			ofstream DosyaYaz;//Dosya çýkýþý yapabilmek için gerekli kod.
			ifstream DosyaOku;

			DosyaYaz.open("Projeler.txt", ios::app); //Projeler.txt dosyasýný dosya ekleme modunda açtým
			DosyaOku.open("Projeler.txt");

			cout << "-----------PROJE KAYDI--------------" << endl;
			cout << " Proje NO                                 :"; cin >> projeNo; //bilgileri aldýk
			cout << " Proje Adi                                :"; cin >> projeAdi;
			cout << " Yurutucu Firma                           :"; cin >> yurutucuFirma;
			cout << " Proje Sorumlusu                          :"; cin >> projeSorumlusu;
			cout << " Proje Kontroloru                         :"; cin >> projeKontroloru;

			while (!DosyaOku.eof()) {
				DosyaOku >> temp >> temp1 >> temp2 >> temp3 >> temp4;
				if (temp == projeNo) {
					cout << " bu proje zaten mevcut" << endl;
					yokmu = false;
				}
			}
			DosyaOku.close();
			if (yokmu)
				DosyaYaz << endl << projeNo << " " << projeAdi << " " << yurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru; // projeler.txtye yazdýrdýk

			cout << "Proje Kayidi Tamamlandi" << endl; //Kayýt bittiðinde ekrana olumlu bir sonuç yazýsý yazdýrdým.

			DosyaYaz.close(); // Dosyayý kapatýyoruz
		}
		if (secim == 6) {
			system("cls"); //ekrani temizledik

			cout << "-------PROJE SILME-------" << endl;

			int NO;
			int i = 0;
			ofstream DosyaYaz("geciciprojeler.tmp", ios::app); //Gecici bir dosya açýlýr
			ifstream DosyaOku("Projeler.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
			ifstream DosyaOku1("Hakedis.txt"); // Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
			ofstream DosyaYaz1("gecicihakedis.tmp", ios::app);//Gecici bir dosya açýlýr

			cout << "Silmek istediginiz proje'nin NOsunu girin...:"; cin >> NO;

			while (!DosyaOku.eof()) //Projeler.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> projeNo >> projeAdi >> yurutucuFirma >> projeSorumlusu >> projeKontroloru; // Projeler.txt içindeki bilgileri okuyor.
				if (NO == projeNo)
				{
					while (!DosyaOku1.eof()) //hakedis.txt nin sonuna kadar dönen döngü
					{
						int temp;
						DosyaOku1 >> temp >> hakedisDönemi >> kullanilanUrun >> kullanilanUrunAdetleri >> kullanilanUrunFiyatlari;
						DosyaYaz1 << "\n" << temp << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
						if (temp == projeNo) {
							i++;
						}
					}
					if (i == 0) {
						cout << "---------- Proje Bilgileri ----------" << endl << endl;

						cout << " Proje NO                              :" << projeNo << endl; // bilgileri tek tek yazdýrýyor.
						cout << " Proje Adi                             :" << projeAdi << endl;
						cout << " Yurutucu Firma                        :" << yurutucuFirma << endl;
						cout << " Proje sorumlusu                       :" << projeSorumlusu << endl;
						cout << " Proje Kontroloru                      :" << projeKontroloru << endl;
						cout << " -------Silme islemi tamamlandi-------" << endl;
					}
					else
						DosyaYaz << endl << projeNo << " " << projeAdi << " " << yurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru;

				}
				else {
					DosyaYaz << endl << projeNo << " " << projeAdi << " " << yurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru;
				}
			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
			DosyaYaz.close();
			DosyaOku1.close();
			DosyaYaz1.close();

			remove("Projeler.txt");// Urunler.txt dosyasý silinirken
			rename("geciciprojeler.tmp", "Projeler.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.
			remove("Hakedis.txt");// Okuyucu.txt dosyasý silinirken
			rename("gecicihakedis.tmp", "Hakedis.txt");//gecici.tmp dosyasý Okuyucu.txt dosyasý olarak deðiþtirirlir.
		}
		if (secim == 7) //Proje arama
		{
			system("cls"); //ekrani temizledik

			cout << "-------PROJE ARAMA-------" << endl;

			int NO;
			int i = 1;
			ofstream DosyaYaz("geciciprojeler.tmp", ios::app); //Gecici bir dosya açýlýr
			ifstream DosyaOku("Projeler.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.

			cout << "Silmek istediginiz Proje'nin NOsunu girin...:"; cin >> NO;

			while (!DosyaOku.eof()) //Projeler.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> projeNo >> projeAdi >> yurutucuFirma >> projeSorumlusu >> projeKontroloru; // Projeler.txt içindeki bilgileri okuyor.
				if (NO == projeNo)
				{
					cout << "---------- Urun Bilgileri ----------" << endl << endl;

					cout << " Proje NO                             :" << projeNo << endl; // bilgileri tek tek yazdýrýyor.
					cout << " Proje Adi                            :" << projeAdi << endl;
					cout << " Yurutucu Firma                       :" << yurutucuFirma << endl;
					cout << " Proje Sorumlusu                      :" << projeSorumlusu << endl;
					cout << " Proje Kontroloru                     :" << projeKontroloru << endl;
					cout << " -------Urun Bulundu-------" << endl;

					DosyaYaz << "\n" << projeNo << " " << projeAdi << " " << yurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru;
				}
				else//urunler.txt içinde noyu bulamaz ise urunlergecici.tmp ye yazdýrýyor
				{
					DosyaYaz << "\n" << projeNo << " " << projeAdi << " " << yurutucuFirma << " " << projeSorumlusu << " " << projeKontroloru;
				}
			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
			DosyaYaz.close();

			remove("Projeler.txt");// Urunler.txt dosyasý silinirken
			rename("geciciprojeler.tmp", "Projeler.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.
		}
		if (secim == 8) {
			system("cls"); //ekrani temizledik

			cout << "-------PROJELERI LISTELE-------" << endl;

			int i = 1;
			ifstream DosyaOku("Projeler.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.

			while (!DosyaOku.eof()) //Projeler.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> projeNo >> projeAdi >> yurutucuFirma >> projeSorumlusu >> projeKontroloru; // Projeler.txt içindeki bilgileri okuyor.

				cout << "---------- Proje Bilgileri ----------" << endl << endl;

				cout << " Proje NO                            :" << projeNo << endl; // bilgileri tek tek yazdýrýyor.
				cout << " Proje Adi                           :" << projeAdi << endl;
				cout << " Yurutucu Firma                      :" << yurutucuFirma << endl;
				cout << " Proje Sorumlusu                     :" << projeSorumlusu << endl;
				cout << " Proje Kontroloru                    :" << projeKontroloru << endl;


			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
		}
		if (secim == 9) {
			system("cls"); // ekraný temizliyoruz

			cout << "-------YENI HAKEDIS-------" << endl;

			ofstream DosyaYaz1("geciciurunler.tmp", ios::app); //Gecici bir dosya açýlýr
			ifstream DosyaOku1("Urunler.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.

			ofstream DosyaYaz;//Dosya çýkýþý yapabilmek için gerekli kod.
			DosyaYaz.open("Hakedis.txt", ios::app); //hakedis.txt dosyasýný dosya ekleme modunda açtým
			int temp = 0;

			cout << "-----------HAKEDIS KAYDI--------------" << endl;
			cout << " Proje NO                                    :"; cin >> projeNo; //bilgileri aldýk
			cout << " Hakkedis Donemi                             :"; cin >> hakedisDönemi;
			cout << " Kullanilan Urunun No su                     :"; cin >> kullanilanUrun;
			cout << " Kullanilan Adet                             :"; cin >> kullanilanUrunAdetleri;
			cout << " Fiyati                                      :"; cin >> kullanilanUrunFiyatlari;

			while (!DosyaOku1.eof()) //Urunler.txt nin sonuna kadar dönen döngü
			{
				DosyaOku1 >> urunNo >> urunAdi >> Birim >> birimFiyati >> Markasi; // urunler.txt içindeki bilgileri okuyor.

				if (kullanilanUrun == urunNo)
				{
					DosyaYaz1 << "\n" << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
					temp++;
				}
				else//urunler.txt içinde noyu bulamaz ise urunlergecici.tmp ye yazdýrýyor
				{
					DosyaYaz1 << "\n" << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
				}
			}

			if (temp) {
				DosyaYaz << endl << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari; // hakedis.txtye yazdýrdýk
				cout << "Urun Kayidi Tamamlandi" << endl; //Kayýt bittiðinde ekrana olumlu bir sonuç yazýsý yazdýrdým.
			}
			else
				cout << "Girdiginiz urun mevcut degildir..." << endl;




			DosyaYaz.close(); // Dosyayý kapatýyoruz

			DosyaYaz1.close();
			DosyaOku1.close();
			remove("Urunler.txt");// Urunler.txt dosyasý silinirken
			rename("geciciurunler.tmp", "Urunler.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.
		}
		if (secim == 10) //Urun silme
		{
			system("cls"); //ekrani temizledik

			cout << "-------URUN SILME-------" << endl;

			int NO;
			int i = 1;
			ofstream DosyaYaz("gecicihakedis.tmp", ios::app); //Gecici bir dosya açýlýr
			ifstream DosyaOku("Hakedis.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.

			cout << "Silmek istediginiz urun'nun no sunu girin...:"; cin >> NO;

			while (!DosyaOku.eof()) //Urunler.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> projeNo >> hakedisDönemi >> kullanilanUrun >> kullanilanUrunAdetleri >> kullanilanUrunFiyatlari; // urunler.txt içindeki bilgileri okuyor.
				if (NO == kullanilanUrun && i)
				{
					cout << "---------- Urun Bilgileri ----------" << endl << endl;

					cout << " Proje NO                                    :" << projeNo << endl; //bilgileri aldýk
					cout << " Hakkedis Donemi                             :" << hakedisDönemi << endl;
					cout << " Kullanilan Urun                             :" << kullanilanUrun << endl;
					cout << " Kullanilan Adet                             :" << kullanilanUrunAdetleri << endl;
					cout << " Fiyati                                      :" << kullanilanUrunFiyatlari << endl;
					cout << " -------Silme islemi tamamlandi-------" << endl;
					i = 0;

				}
				else//urunler.txt içinde noyu bulamaz ise urunlergecici.tmp ye yazdýrýyor
				{
					DosyaYaz << endl << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
				}
			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
			DosyaYaz.close();

			remove("Hakedis.txt");// Urunler.txt dosyasý silinirken
			rename("gecicihakedis.tmp", "Hakedis.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.
		}
		if (secim == 11) // Hakedis urun guncelleme
		{
			system("cls"); //ekrani temizledik

			cout << "-------URUN GUNCELLEME-------" << endl;
			int NO;
			int i = 1;
			ofstream DosyaYaz("gecicihakedis.tmp", ios::app); //Gecici bir dosya açýlýr
			ifstream DosyaOku("Hakedis.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým


			cout << "Guncellemek istediginiz urunun nosunu girin...:"; cin >> NO;

			while (!DosyaOku.eof()) //hakedis.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> projeNo >> hakedisDönemi >> kullanilanUrun >> kullanilanUrunAdetleri >> kullanilanUrunFiyatlari; // hakedis.txt içindeki bilgileri okuyor.
				if (NO == kullanilanUrun && i)
				{
					cout << "---------- Hakedis Bilgileri ----------" << endl << endl;

					cout << " Proje NO                                    :"; cin >> projeNo; //bilgileri aldýk
					cout << " Hakkedis Donemi                             :"; cin >> hakedisDönemi;
					cout << " Kullanilan Urun                             :"; cin >> kullanilanUrun;
					cout << " Kullanilan Adet                             :"; cin >> kullanilanUrunAdetleri;
					cout << " Fiyati                                      :"; cin >> kullanilanUrunFiyatlari;
					cout << " -------Guncelleme islemi tamamlandi-------" << endl;
					i = 0;
					DosyaYaz << endl << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
				}
				else//hakedis.txt içinde tcyi bulamaz ise okuyucugecici.tmp ye yazdýrýyor
				{
					DosyaYaz << endl << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
				}
			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
			DosyaYaz.close();

			remove("Hakedis.txt");// hakedis.txt dosyasý silinirken
			rename("gecicihakedis.tmp", "Hakedis.txt");//gecici.tmp dosyasý hakedis.txt dosyasý olarak deðiþtirirlir.
		}
		if (secim == 12) {
			system("cls"); // ekraný temizledik

			cout << "-------KULLANILAN URUNLERIN LISTESI-------" << endl;

			ifstream DosyaOku("Hakedis.txt"); //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.


			while (!DosyaOku.eof()) // hakedis.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> projeNo >> hakedisDönemi >> kullanilanUrun >> kullanilanUrunAdetleri >> kullanilanUrunFiyatlari;//hakedis.txt yi okuyor satir satir

				cout << kullanilanUrun << endl;

			}

			DosyaOku.close();// açtýðýmýz dosyayý kapatýyoruz
		}
		if (secim == 13) //Urun arama
		{
			system("cls"); //ekrani temizledik

			cout << "-------KULLANILAN URUN ARAMA-------" << endl;

			int NO;
			int i = 1;
			ofstream DosyaYaz("gecicihakedis.tmp", ios::app); //Gecici bir dosya açýlýr
			ifstream DosyaOku("Hakedis.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.

			cout << "Aramak istediginiz urun'un nosunu girin...:"; cin >> NO;

			while (!DosyaOku.eof()) //Hakedis.txt nin sonuna kadar dönen döngü
			{
				DosyaOku >> projeNo >> hakedisDönemi >> kullanilanUrun >> kullanilanUrunAdetleri >> kullanilanUrunFiyatlari;//hakedis.txt yi okuyor satir satir
				if (NO == kullanilanUrun)
				{
					cout << "---------- Urun Bilgileri ----------" << endl << endl;

					cout << " Proje NO                                    :" << projeNo << endl; //bilgileri aldýk
					cout << " Hakkedis Donemi                             :" << hakedisDönemi << endl;
					cout << " Kullanilan Urun                             :" << kullanilanUrun << endl;
					cout << " Kullanilan Adet                             :" << kullanilanUrunAdetleri << endl;
					cout << " Fiyati                                      :" << kullanilanUrunFiyatlari << endl;
					cout << " -------Urun Bulundu-------" << endl;

					DosyaYaz << "\n" << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
				}
				else//hakedis.txt içinde noyu bulamaz ise hakedisgecici.tmp ye yazdýrýyor
				{
					DosyaYaz << "\n" << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
				}
			}
			DosyaOku.close(); //açtýðýmýz dosyalarý kapatýyoruz
			DosyaYaz.close();

			remove("Hakedis.txt");// hakedis.txt dosyasý silinirken
			rename("gecicihakedis.tmp", "Hakedis.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.

		}
		if (secim == 14) {
			cout << "-------RAPORLAMA-------" << endl;
			int secim1;
			do
			{
				cout << " Nasýl Rapor Istiyorsunuz ?" << endl;
				cout << " 1) Secilen proje icin hakedis'in cikarilmasi" << endl;
				cout << " 2) Belirtilen doneme gore tum hakedis tablosunun raporlanmasi" << endl;
				cin >> secim1;
			} while (secim1 != 1 && secim1 != 2);
			int NO, Donem;

			if (secim1 == 1) {
				ofstream DosyaYaz("gecicihakedis.tmp", ios::app); //Gecici bir dosya açýlýr
				ifstream DosyaOku("Hakedis.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
				ifstream DosyaOku1("Urunler.txt"); // Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
				ofstream DosyaYaz1("geciciurunler.tmp", ios::app);//Gecici bir dosya açýlýr

				cout << "Aramak istediginiz proje'nin NOsunu girin...:"; cin >> NO;

				while (!DosyaOku.eof()) //hakedis.txt nin sonuna kadar dönen döngü
				{
					DosyaOku >> projeNo >> hakedisDönemi >> kullanilanUrun >> kullanilanUrunAdetleri >> kullanilanUrunFiyatlari; // hakedis.txt içindeki bilgileri okuyor.
					DosyaOku1 >> urunNo >> urunAdi >> Birim >> birimFiyati >> Markasi;
					if (NO == projeNo)
					{
						cout << "---------- Rapor ----------" << endl << endl;

						cout << " Proje NO                                    :" << projeNo << endl;
						cout << " Hakkedis Donemi                             :" << hakedisDönemi << endl;
						cout << " Kullanilan Urunun Nosu                      :" << kullanilanUrun << endl;
						cout << " Genel Toplam Fiyati                         :" << kullanilanUrunFiyatlari * kullanilanUrunAdetleri * birimFiyati << endl;

						DosyaYaz1 << "\n" << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
						DosyaYaz << "\n" << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
					}
					else//urunler.txt içinde noyu bulamaz ise urunlergecici.tmp ye yazdýrýyor
					{
						DosyaYaz1 << "\n" << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
						DosyaYaz << "\n" << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
					}
				}
				DosyaOku.close();
				DosyaOku1.close();
				DosyaYaz.close();
				DosyaYaz1.close();


				remove("Urunler.txt");// Urunler.txt dosyasý silinirken
				rename("geciciurunler.tmp", "Urunler.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.

				remove("Hakedis.txt");// Urunler.txt dosyasý silinirken
				rename("gecicihakedis.tmp", "Hakedis.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.
			}
			if (secim1 == 2) {
				ofstream DosyaYaz("gecicihakedis.tmp", ios::app); //Gecici bir dosya açýlýr
				ifstream DosyaOku("Hakedis.txt");  //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
				ifstream DosyaOku1("Urunler.txt"); // Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
				ofstream DosyaYaz1("geciciurunler.tmp", ios::app);//Gecici bir dosya açýlýr
				cout << "Raporlamak istediginiz hakedis donemini giriniz...:"; cin >> Donem;
				while (!DosyaOku.eof()) //hakedis.txt nin sonuna kadar dönen döngü
				{
					DosyaOku >> projeNo >> hakedisDönemi >> kullanilanUrun >> kullanilanUrunAdetleri >> kullanilanUrunFiyatlari; // hakedis.txt içindeki bilgileri okuyor.
					DosyaOku1 >> urunNo >> urunAdi >> Birim >> birimFiyati >> Markasi;
					if (Donem == hakedisDönemi)
					{
						cout << "---------- Rapor ----------" << endl << endl;

						cout << " Proje NO                                    :" << projeNo << endl;
						cout << " Hakkedis Donemi                             :" << hakedisDönemi << endl;
						cout << " Kullanilan Urun                             :" << kullanilanUrun << endl;
						cout << " Genel Toplam Fiyati                         :" << kullanilanUrunFiyatlari * kullanilanUrunAdetleri * birimFiyati << endl;


						DosyaYaz1 << "\n" << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
						DosyaYaz << "\n" << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
					}
					else//urunler.txt içinde noyu bulamaz ise urunlergecici.tmp ye yazdýrýyor
					{
						DosyaYaz1 << "\n" << urunNo << " " << urunAdi << " " << Birim << " " << birimFiyati << " " << Markasi;
						DosyaYaz << "\n" << projeNo << " " << hakedisDönemi << " " << kullanilanUrun << " " << kullanilanUrunAdetleri << " " << kullanilanUrunFiyatlari;
					}

				}

				DosyaOku.close();
				DosyaOku1.close();
				DosyaYaz.close();
				DosyaYaz1.close();


				remove("Urunler.txt");// Urunler.txt dosyasý silinirken
				rename("geciciurunler.tmp", "Urunler.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.

				remove("Hakedis.txt");// Urunler.txt dosyasý silinirken
				rename("gecicihakedis.tmp", "Hakedis.txt");//gecici.tmp dosyasý Urunler.txt dosyasý olarak deðiþtirirlir.
			}

		}









		cout << "--------------------------------------------------------------------------------------------------------" << endl;
		cout << endl << "Baska yapmak istediginiz bir islem var mi? e/h" << endl;
		cin >> genelcvp;
	} while (!(genelcvp == 'h'));

	return 0;
}