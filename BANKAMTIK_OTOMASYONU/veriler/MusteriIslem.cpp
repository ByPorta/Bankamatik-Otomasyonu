#include "MusteriIslem.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>


#include <fstream>
 
using namespace std; 


MusteriIslem:: MusteriIslem()
{
	
}
MusteriIslem:: MusteriIslem( MusteriBilgi mPtr )
{
	m1= mPtr; 
}

MusteriIslem::~MusteriIslem()
{
}

void  MusteriIslem:: paraCek() 
{
	system("cls") ; 
	
	float sayi; 
	cout<<"\nPara cekme ekrani : "<< endl<< endl ; 
	cout<<"Bakiye : "<< m1.getBakiye()<< " TL"<< endl<< endl; 
	cout<<"Cekmek istediginiz miktar (TL) : "; cin>>sayi; 
	if( sayi >m1.getBakiye())
	cout<<"Yetersiz bakiye !"<< endl; 
	else
	{	
		m1.setBakiye( m1.getBakiye() - sayi ) ; 
		
		char dosyaAdi[30]; 
		strcpy(dosyaAdi, m1.getTcNo() ) ; 
		strcat(dosyaAdi, ".txt") ; 
	
		ofstream file(dosyaAdi) ; 
		file.write((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		file.close(); 
		cout<<"Para cekme islemi basarili  "<< endl<< endl ; 
		
		char msj[]= "Para Cekildi "; 
		HareketKaydet( m1.getTcNo(), msj  )  ; 
	  
	} 
	system("pause"); 
	
 } 
 
void MusteriIslem::  paraYatir()
{
	system("cls") ; 	
	float sayi; 
	cout<<"\nPara Yatirma ekrani : "<< endl << endl ; 
	cout<<"Bakiye : "<< m1.getBakiye()<< " TL"<< endl<< endl; 
	cout<<"Yatirmak istediginiz miktar (TL) : "; cin>>sayi; 

		m1.setBakiye( m1.getBakiye() + sayi ) ; 
		
		char dosyaAdi[30]; 
		strcpy(dosyaAdi, m1.getTcNo() ) ; 
		strcat(dosyaAdi, ".txt") ; 
	
		ofstream file(dosyaAdi) ; 
		file.write((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		file.close(); 
		cout<<"Para yatirma islemi basarili  "<< endl<< endl ; 
		
		char msj[]="Para yatirildi" ; 
		HareketKaydet( m1.getTcNo(), msj   )  ; 
	 	system("pause"); 		
	
	
} 
 
void  MusteriIslem:: bakiye()
{
	system("cls") ; 
	
	float sayi; 
	cout<<"\nBakiye sorgulama ekrani : "<< endl; 
	cout<<"Bakiyeniz  : "<< m1.getBakiye()<< " TL"<< endl<< endl; 
	 	
	char msj[]= "Bakiye Sorgulandi "; 
	HareketKaydet( m1.getTcNo(), msj )  ; 
	system("pause"); 	
	
} 
  
void  MusteriIslem:: havale()
{
	system("cls") ; 
	float sayi; 
	char aliciNo[20]; 
	cout<<"\nHavale ekrani... : "<< endl; 
	cout<<"Bakiye : "<< m1.getBakiye()<< " TL"<< endl<< endl; 
	cout<<"Havale edeceginiz miktar (TL) : "; cin>>sayi; 
	if( sayi >m1.getBakiye())
	cout<<"Yetersiz bakiye !"<< endl; 
	else
	{	
		cout<<"Alici HesapNo/TcNo : "; scanf(" %[^\n]s", aliciNo ); 
		char dosyaAdi[30]; 
		strcpy(dosyaAdi, aliciNo ) ; 
		strcat(dosyaAdi, ".txt") ; 
		
		ifstream file(dosyaAdi) ; 
		MusteriBilgi m2; 
		file.read ((char*)&m2, sizeof(MusteriBilgi ) ) ; 
		if( !file.is_open() ) 
		cout<<"Alici HesapNo/TcNo hatali !!!"<< endl; 
		else 
		{
			m2.setBakiye(m2.getBakiye() + sayi) ; 
			m1.setBakiye(m1.getBakiye() - sayi ); 
			
			file.close(); 
			
		ofstream file2(dosyaAdi) ; 
		
		file2.write ((char*)&m2, sizeof(MusteriBilgi ) ) ;
		file2.close(); 
		
		strcpy(dosyaAdi, m1.getTcNo() ) ; 
		strcat(dosyaAdi, ".txt") ; 
		
		ofstream file(dosyaAdi) ; 
		
		file.write ((char*)&m1, sizeof(MusteriBilgi ) ) ;
		file.close(); 
		cout<<"Havale islemi gerceklestirildi. "<< endl; 
		
		char msj[] = "Havale gonderildi "; 
		char msj2[] = "Havale alindi "; 
		HareketKaydet( m1.getTcNo(), msj )  ;
		 
		HareketKaydet( m2.getTcNo(), msj2 )  ; 
		
	  
		}
		file.close(); 
		
	} 
	system("pause");  
	
} 


  
void  MusteriIslem:: HareketKaydet ( char *tcNo,  char * msj   )
{	
		char dosyaAdi[30]; 
		strcpy(dosyaAdi, tcNo ) ; 
		strcat(dosyaAdi, "rapor.txt") ; 
	
		ofstream file(dosyaAdi, ios::app  )  ; 
		file<< msj<< endl; 
		file.close(); 
	//	cout<<"Hareket kaydedildi "<< endl; 
	
} 


  
void  MusteriIslem:: hesapHareketleri()
{
	system("cls") ; 
	
	float sayi; 
	cout<<"\nHesap hareket ekrani ... "<< endl<< endl; 
	
		char dosyaAdi[30]; 
		strcpy(dosyaAdi, m1.getTcNo() ) ; 
		strcat(dosyaAdi, "rapor.txt") ; 
	
		ifstream file(dosyaAdi) ; 
		char harf  ; 
		
		while(  file.get(harf )  ) 
		{
			cout<<harf; 
		}
		file.close(); 
		
		cout<<endl<<endl; 
		
		system("pause"); 		
	
} 

void MusteriIslem ::  sifreDegistir() 
{
	char eSifre [20], ySifre[20];
	
	 
	system("cls") ; 
	cout<<"\nSifre Degistirme Islemleri... "<< endl<< endl; 
	cout<<"Eski Sifre : "; scanf(" %[^\n]s", eSifre ); 
	cout<<"Yeni Sifre : "; scanf(" %[^\n]s", ySifre ); 
	
	
	char dosyaAdi[30]; 
	strcpy(dosyaAdi, m1.getTcNo() ) ; 
	strcat(dosyaAdi, ".txt") ; 
	ifstream file(dosyaAdi) ; 
	if(  file.is_open() )
	{
		
		file.read ((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		if(  strcmp( m1.getSifre() , eSifre   ) != 0 ) 
		cout<<"Eski sifreyi hatali girdiniz !!! "<< endl; 
		else 
		{
			file.close();
			ofstream file(dosyaAdi) ;
			m1.setSifre(ySifre) ; 
			file.write ((char*)&m1, sizeof(MusteriBilgi ) ) ; 
			cout<<"Sifre degistirildi "<< endl<< endl ;
			char msj[]="Sifre degistirildi "; 
			HareketKaydet(m1.getTcNo(), msj ) ;  
		}   
	} 
	file.close(); 
	system("pause"); 
	
}  

void  MusteriIslem:: paraDonustur()
{
	system("cls") ; 
	float dolarMiktar;
	float tlMiktar;
	
    cout << "Cevrilecek miktari girin (Dolar): ";
    cin >> dolarMiktar;
    
    tlMiktar = dolarMiktar * 28.95;
    
    cout << "Dolar miktari: " << dolarMiktar << " $, TL miktari: " << tlMiktar << " TL\n";
    
    if( tlMiktar >m1.getBakiye())
	cout<<"Yetersiz bakiye !"<< endl; 
	else
	{	
		m1.setBakiye( m1.getBakiye() - tlMiktar ) ; 
		//cout<<"Para donusumu islemi basarili  "<< endl<< endl ; 
		char dosyaAdi[30]; 
		strcpy(dosyaAdi, m1.getTcNo() ) ; 
		strcat(dosyaAdi, ".txt") ; 
	
		ofstream file(dosyaAdi) ; 
		file.write((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		file.close(); 
		cout<<"Para donusumu islemi basarili  "<< endl<< endl ; 
		
		char msj[]="Para donusumu yapildi." ; 
		HareketKaydet( m1.getTcNo(), msj   )  ; 
	 	system("pause");
	} 
	system("pause"); 

} 


void  MusteriIslem:: faturaOdeme()
{
	system("cls") ; 
	float fatura;
	float odemeMiktari;
	bool faturaOdendi;

	cout << "Odenecek fatura miktarini giriniz: " ; cin>>odemeMiktari;
	 if (!faturaOdendi) {
       // cout << "Odenecek fatura miktari: " << fatura << " TL\n";
        cout << "Hesap bakiyesi: " << m1.getBakiye() << " TL\n";
		if (odemeMiktari <= m1.getBakiye()) {
            faturaOdendi = true;
            m1.setBakiye(m1.getBakiye() - odemeMiktari) ; 
        
            fatura = 0.0;
            cout << "Fatura odendi. Odenen miktar: " << odemeMiktari << " TL\n";
            cout << "Guncel bakiye: " << fixed << setprecision(2) << m1.getBakiye() << " TL\n";
            char dosyaAdi[30]; 
			strcpy(dosyaAdi, m1.getTcNo() ) ; 
			strcat(dosyaAdi, ".txt") ; 
		
			ofstream file(dosyaAdi) ; 
			file.write((char*)&m1, sizeof(MusteriBilgi ) ) ; 
			file.close(); 
			cout<<"Fatura odeme islemi islemi basarili  "<< endl<< endl ; 
			
			char msj[]="Fatura islemi Yapildi." ; 
			HareketKaydet( m1.getTcNo(), msj   )  ; 
        } else {
            cout << "Yetersiz bakiye. Odeme islemi basarisiz.\n";
        }
      
    } else {
        cout << "Bu fatura zaten odendi.\n";
    }
    
   
    
    
    system("pause"); 

} 


void  MusteriIslem:: krediHesaplama()
{
	system("cls") ;
	double miktar; 
	int vade;
	double faizOrani;
	double krediMiktari;
	char tercih;
	
	cout << "Kredi miktarini girin: ";
    cin >> krediMiktari;
    cout << "Vadeyi girin (ay): ";
    cin >> vade;
    cout << "Yillik faiz oranini girin: ";
    cin >> faizOrani;
    
	double faiz = (krediMiktari * faizOrani * vade) / 100.0;
    double toplamTutar = krediMiktari + faiz;
    
    cout << "Kredi miktari: " << krediMiktari << " TL\n";
	cout << "Vade: " << vade << " ay\n";
	cout << "Faiz orani: " << faizOrani << "%\n";
	cout << "Odenecek toplam miktar: " << fixed << setprecision(2) << toplamTutar << " TL\n";
    
    cout<<"Kredi cekmek istediginize emin misiniz ? [E/H] : "; cin>>tercih; 
	if( tercih =='e' || tercih == 'E'){
		double yeniTutar = toplamTutar*2; 
		if(yeniTutar <= m1.getBakiye()){
			cout << "Kredi cekme islemi basarili bir sekilde yapildi.\n"; 
		    char msj[]= "Kredi cekme islemi basarili bir sekilde yapildi. "; 
			HareketKaydet( m1.getTcNo(), msj )  ; 
		}else{
			cout << "Toplam tutar bakiyenizin yarisindan fazla oldugu icin kredi islemi basarisiz oldu.\n" ;
		}
		
	}else{
		cout << "Kredi hesaplama islemi sonlandirildi. \n" ;
	}

    system("pause");
} 

  
int  MusteriIslem:: musteriMenu()
{
	system("cls") ; 
	int secim; 
	cout<<"\n\nHosgeldiniz sayin "<< m1.getAdSoyad() << endl<<endl; 
	cout<<"Musteri No : "<< m1.getTcNo()<< endl<< endl; 
	
	cout<<"[1]- Para Cek "<< endl; 
	cout<<"[2]- Para Yatir  "<< endl; 
	cout<<"[3]- Bakiye Sorgula "<< endl; 
	cout<<"[4]- Havale  "<< endl;
	cout<<"[5]- Hesap Hareketleri  "<< endl;
	cout<<"[6]- Sifre Degistir  "<< endl;
	cout<<"[7]- Para Donustur  "<< endl;
	cout<<"[8]- Fatura Odeme  "<< endl;
	cout<<"[9]- Kredi Hesaplama  "<< endl;
	cout<<"[0]- CIKIS YAP  "<< endl; 
	cout<<"Seciminiz    :  "; cin>>secim;  
	return secim; 	
} 
 
void MusteriIslem ::  musteriGiris( MusteriBilgi mb  )
{
	m1= mb; 
 
	int secim= musteriMenu() ; 
	while( secim != 0 )
	{
		switch (secim )
		{
			case 1: paraCek (); break; 
			case 2: paraYatir  (); break; 
			case 3: bakiye  (); break; 
			case 4: havale  (); break;
			case 5: hesapHareketleri  (); break;
			case 6: sifreDegistir()  ;  break;
			case 7: paraDonustur(); break;
			case 8: faturaOdeme(); break;
			case 9: krediHesaplama(); break;
			
			case 0:  break;
			default : cout<<"Hatali secim yaptiniz !!! "<< endl;  			
		}
		secim = musteriMenu();
	}	
} 
 

