#ifndef MUSTERIBILGI_H
#define MUSTERIBILGI_H

class MusteriBilgi
{
	private: 
	char tcNo[20],  adSoyad[30], adres[30], tel[20], sifre[20]; 
	float bakiye; 
	
	public:
		MusteriBilgi();
		~MusteriBilgi();
	MusteriBilgi(char *tc, char *ads, char *adr, char * tl, char *sf, float bk );
			
			
	/*void setSubeAd (char *ptr );
	char * getSubeAd (); 
	void setSubeAdres (char *ptr );
	char * getSubeAdres ();	*/			
	void setTcNo (char *ptr );
	char * getTcNo (); 
	void setAdSoyad(char *ptr );
	char * getAdSoyad(); 
	void setAdres(char *ptr );
	char * getAdres (); 
	void setTel (char *ptr );
	char * getTel (); 
	void setSifre (char *ptr );
	char * getSifre(); 
	void setBakiye ( float bk );
	float  getBakiye ();
	 
		
};

#endif
