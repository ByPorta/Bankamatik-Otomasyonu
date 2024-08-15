#include "AnaMenu.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "YetkiliIslem.h"
#include "MusteriIslem.h" 
#include "fstream"
using namespace std; 

 AnaMenu:: AnaMenu()
{
}

AnaMenu::~AnaMenu()
{
}

void  AnaMenu:: yetkiliKontrol()
{
	system("cls") ; 
	char kullaniciAdi[20], sifre[20]; 
	cout<<"\nYetkili giris icin... "<< endl<< endl; 
	cout<<"\nKullanici adi : "; scanf(" %[^\n]s", kullaniciAdi ) ; 
	cout<<"Parola        : "; scanf(" %[^\n]s", sifre ) ;
	if( strcmp ( kullaniciAdi ,"admin" ) ==0 && strcmp ( sifre ,"12" ) ==0   ) 
	 {
	 	YetkiliIslem y1; 
	 	y1.yetkiliGiris() ; 
	 }
	 else 
	 {
	 	cout<<"\nHatali kullanici adi/parola !!! "<< endl << endl ; 
	 	system("pause") ; 
	 }
	
	
}
void  AnaMenu:: musteriKontrol()
{
	system("cls") ; 
	char kullaniciAdi[20], sifre[20]; 
	cout<<"\nMusteri girisi icin... "<< endl<< endl; 
	cout<<"\n\nMusteri No/TcNo : "; scanf(" %[^\n]s", kullaniciAdi ) ; 
	cout<<"Parola          : "; scanf(" %[^\n]s", sifre ) ;
	
	
	char dosyaAdi[30]; 
	strcpy(dosyaAdi, kullaniciAdi ) ; 
	strcat(dosyaAdi, ".txt") ; 
	ifstream file(dosyaAdi) ; 
	if( ! file.is_open() )
		cout<<"\nHatali MusteriNo/TcNo !!! "<< endl<< endl ; 
	else 
	{
		
		file.read ((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		
		if(  strcmp ( sifre , m1.getSifre() ) ==0   )  
			 {
			 	MusteriIslem mi;  
			 	mi.musteriGiris( m1 );    
			 }
		 else 
		 	 	cout<<"\nHatali kullanici adi/parola !!! "<< endl<< endl ; 	 		
		
	} 
	file.close(); 
	system("pause"); 
		
}
	
int AnaMenu:: menu ()
{
	system("cls"); 
	int secim; 
	cout<<"\n\tB A N K A M A T I K   O T O M A S Y O N U "<< endl<< endl; 
	cout<<"\t[1]- Yetkili Giris  "<< endl; 
	cout<<"\t[2]- Musteri Giris  "<< endl; 
	cout<<"\t[0]- Programi Kapat  "<< endl; 
	cout<<"\n\tSeciminiz    :   ";  cin>>secim; 
	return secim; 
 } 
void AnaMenu:: giris()
{
	int secim= menu(); 
	while( secim != 0 ) 
	{
		switch(secim )
		{
			case 1: yetkiliKontrol() ; break; 
			case 2: musteriKontrol(); break; 
			case 0: break; 
			default: cout<<"Hatali secim "<< endl; 
		}
		secim= menu(); 
	} 
	
	
}
		
