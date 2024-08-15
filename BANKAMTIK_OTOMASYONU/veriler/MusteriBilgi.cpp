#include "MusteriBilgi.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

 MusteriBilgi:: MusteriBilgi()
{
/*	strcpy( subeAd, "");
	strcpy( subeAdres, "");*/
	strcpy( tcNo, "");
	strcpy( adSoyad, "");
	strcpy( adres, "");
	strcpy( tel, "");
	strcpy( sifre, "");
	bakiye=0.0; 
}

MusteriBilgi::~MusteriBilgi()
{
}
MusteriBilgi:: MusteriBilgi(char *tc, char *ads, char *adr, char * tl, char *sf, float bk )
{
	/*strcpy( subeAd, sbAd);
	strcpy( subeAdres, sbAdres );*/
	strcpy( tcNo, tc);
	strcpy( adSoyad, ads );
	strcpy( adres, adr );
	strcpy( tel, tl );
	strcpy( sifre, sf);
	bakiye=bk ; 
	
}

/*void MusteriBilgi:: setSubeAd (char *ptr ) 
{
	strcpy( subeAd, ptr); 
	
}

char * MusteriBilgi:: getSubeAd ()
{
	return subeAd; 
}

void MusteriBilgi:: setSubeAdres (char *ptr ) 
{
	strcpy( subeAdres, ptr); 
	
}

char * MusteriBilgi:: getSubeAdres ()
{
	return subeAdres; 
}
	*/		
void MusteriBilgi:: setTcNo (char *ptr ) 
{
	strcpy( tcNo, ptr); 
	
}

char * MusteriBilgi:: getTcNo ()
{
	return tcNo; 
}
 
void MusteriBilgi:: setAdSoyad(char *ptr )
{
	strcpy( adSoyad, ptr); 	
}

char * MusteriBilgi:: getAdSoyad()
{
	return adSoyad; 
}

void MusteriBilgi:: setAdres(char *ptr )
{
	strcpy( adres, ptr); 		
}

char * MusteriBilgi:: getAdres ()
{
	return adres; 
}

void MusteriBilgi:: setTel (char *ptr )
{
	strcpy( tel , ptr); 
}

char * MusteriBilgi:: getTel ()
{
	return tel; 
}
void MusteriBilgi:: setSifre (char *ptr )
{
	strcpy( sifre , ptr); 
}

char * MusteriBilgi:: getSifre()
{
	return sifre; 
}
 
void MusteriBilgi:: setBakiye ( float bk )
{
	bakiye = bk; 
}

float  MusteriBilgi:: getBakiye ()
{
	return bakiye; 
}

