#include <iostream> 
#include <cstdlib>
#include <fstream>  // Dosya iþlemleri
#include <locale.h> // Türkçe karakter için
#include <string>   
#include <windows.h>
#include <conio.h>  
#include <stdio.h>
#include <iomanip>  // setw kullanmak için

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;


void gotoxy(int,int);
void menu1();
void anamenu();
void menu();

void menu()
{	
	 
 
	int b,c;
	int menu_Secim;
	int kyt_Secim;
	int rnd_Secim;
	string k_No;
	int i ;
	k_No = "";
	
	system("cls");
	anamenu();
	
	gotoxy(60,16);
	cout<<"\t\tHASTANE OTOMASYONU\n";
	gotoxy(30,19);
	cout<<"\t\t\t\t [1] HASTA ISLEMLERI \n";
	gotoxy(30,20);
	cout<<"\t\t\t\t [2] RANDEVU ISLEMLERI \n";
	gotoxy(30,21);
	cout<<"\t\t\t\t [3] MUAYENE KAYDI \n";
	gotoxy(30,22);
	cout<<"\t\t\t\t [4] CIKIS \n";
		
		gotoxy(60,26);   
		cout << "Seciminiz (1, 2, 3, 4):  ";
				
		gotoxy(84,26); 
		
	 menu_Secim=getch();
	system ("cls");

	switch (menu_Secim)
	{
	case '1':
		anamenu();
		menu1();
		break;
	case '2':  
	anamenu();
	gotoxy(60,16);
	cout<<"\t\t RANDEVU ISLEMLERI \n"; 
	gotoxy(30,19);
	cout<<"\t\t\t\t [1] RANDEVU ALMA \n";
	gotoxy(30,20);
	cout<<"\t\t\t\t [2] RANDEVU SILME \n";
	gotoxy(30,21);
	cout<<"\t\t\t\t [3] RANDEVU GUNCELLEME \n";
	gotoxy(30,22);
	cout<<"\t\t\t\t [4] CIKIS \n"; 
		gotoxy(60,26);   
	cout << "Seciminiz (1, 2, 3, 4 ):  ";
	b=getch();
			system("cls"); 
		switch(b){
			case '1': 
			case '2': 
			case '3': 
			case '4': menu();	
			
		}
	
	break;
	case '3':  
	anamenu();
	gotoxy(60,16);
	cout<<"\t\t MUAYENE KAYDI  "; 
	gotoxy(60,18);
	cout<<"\t\t HASTA BILGILERI "; 
	gotoxy(30,19);
 	cout<<"\t\t\t\t TC NO      :";
 	gotoxy(30,20);
 	cout<<"\t\t\t\t ADI SOYADI :";
	gotoxy(30,21);
 	cout<<"\t\t\t\t YASI       :"<<endl;
 	gotoxy(30,22);
 	cout<<"\t\t\t\t TELEFONU   :" <<endl;
 	gotoxy(30,23);
 	cout<<"\t\t\t\t CINSIYETI  :"<<endl;
 	gotoxy(60,26);   
	cout << "CIKMAK ICIN '0'  BASINIZ :  ";
	c=getch();
			system("cls"); 
		switch(c){
			case '1': 
			case '0': menu();	
			}
	 break;
	case '4': 
	exit(1);
	break;
	
	default:
		anamenu();
			gotoxy(60,16);
		cout<<"\t\t HATA  "; 
		gotoxy(52,19);
		cout << "MENUDE HATALI SECIM YAPTINIZ !!"<<endl; 
		break;
	}
}

	void fullscreen()
	{
		keybd_event(VK_MENU,0x38,0,0);
		keybd_event(VK_RETURN,0x1c,0,0);
		keybd_event(VK_MENU,0x1c,KEYEVENTF_KEYUP,0);
		keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);		
	}
int main()
{	fullscreen();
    int x;
	char selection;
	while (true)
	{
		system("COLOR 07");
		system("cls"); 
		menu(); 
		system("pause"); 
	}
	return 0;
}
void gotoxy(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}
void hastaKayit(){
	anamenu();
	string HastaAdi; //Deðiþkenleri tanýmladýk
 string HastaSoyadi; 
 
 long long int Telefon;
 int KayitNo;
 int HastaYas; 
 char d;
 string HastaCinsiyet; 
 char islem;
 char cevap;
 long long int TC;
	ofstream DosyaYaz; 
 DosyaYaz.open("Hasta.txt",ios::app);{ 
 gotoxy(60,16);
	cout<<"\t\t KAYIT EKLE  ";
	gotoxy(30,19);
 cout<<"\t\t\t\t Hasta TC     : "; cin>>TC; 
 gotoxy(30,20);
 cout<<"\t\t\t\t Hasta Adi    : "; cin>>HastaAdi; 
 gotoxy(30,21);
 cout<<"\t\t\t\t Hasta Soyadi : "; cin>>HastaSoyadi; 
 gotoxy(30,22);
 cout<<"\t\t\t\t Hasta Yasi   : "; cin>>HastaYas; 
 gotoxy(30,23);
 cout<<"\t\t\t\t Telefonu     : "; cin>>Telefon; 
 gotoxy(30,24);
 cout<<"\t\t\t\t Cinsiyeti    : " ; cin>>HastaCinsiyet; 
 
 DosyaYaz<<TC<<" "<<HastaAdi<<' '<<HastaSoyadi<<' ' <<HastaYas<<' '<<Telefon<<' ' <<HastaCinsiyet<<endl; 
 		gotoxy(60,26);   
 cout<<" Baska kayit yapacak misiniz?(e/E) (h/H) ";cin>>cevap; 
 system("cls");
 
 }
 if(cevap=='h' || cevap=='H'){ 

 system("cls");
 anamenu();
 gotoxy(60,16);
	cout<<"\t\t BASARILI  ";
  gotoxy(30,22);
 cout<< "\t\t\t\t  Kayit basariyla eklendi."<<endl;
gotoxy(60,26);   
  cout<<" Anamenuye Donmek Icin '1'e Basiniz. ";d=getch();
 DosyaYaz.close();
 	
			system("cls"); 
		switch(d){
			 
			case '1': menu();	
			default : menu();
			}
			
}

 if(cevap=='e' || cevap=='E'){
 	system("cls");
 	hastaKayit();
 }
 
 
 
}


void menu1(){
	int a;
	gotoxy(60,16);
	cout<<"\t\t HASTA ISLEMLERI "; 
	gotoxy(30,19);
	cout<<"\t\t\t\t [1] KAYIT EKLE ";
	gotoxy(30,20);
	cout<<"\t\t\t\t [2] KAYIT GUNCELLE ";
	gotoxy(30,21);
	cout<<"\t\t\t\t [3] KAYIT SILME ";
	gotoxy(30,22);
	cout<<"\t\t\t\t [4] KAYIT SORGULAMA ";
	gotoxy(30,23);
	cout<<"\t\t\t\t [5] KAYIT LISTESI ";
	gotoxy(30,24);
	cout<<"\t\t\t\t [6] CIKIS ";
	gotoxy(60,26);   
	cout << "Seciminiz (1, 2, 3, 4, 5, 6):  ";
		a=getch();
			system("cls"); 
		switch(a){
			case '1':hastaKayit(); 
			case '2': 
			case '3': 
			case '4': 
			case '5': 
			case '6': menu();	
			
		}
	
}
void anamenu(){   

	int x=0;
	int b=0;
	gotoxy(50,15);
	cout<<char(201);
		for(int i=0;i<=58;i++){
			cout<< char(205);
		}
		cout<<char(187);
		gotoxy(50,16);
	cout<<char(186);
		gotoxy(50,17);
	cout<<char(204);
		for(int i=0;i<=58;i++){
			cout<< char(205);
		}
			cout<<char(185);
			
			gotoxy(110,16);
			cout<<char(186);
			
		gotoxy(110,18);
		while(b<10){
			cout<<char(186);
			gotoxy(110,x+18);
			x++;
			b++;
		}
		gotoxy(50,18);
		for(int i=0;i<10;i++){
			cout<<char(186);
			gotoxy(50,i+18);
		}
	gotoxy(50,27);
			cout<<char(200);
	gotoxy(110,27);
	cout<<char(188);
		gotoxy(50,25);
			cout<<char(204);
			gotoxy(110,25);
			cout<<char(185);
		gotoxy(51,25);	
		for(int i=0;i<=58;i++){
		cout<< char(205);}
			gotoxy(51,27);
		for(int i=0;i<=58;i++){
			cout<< char(205);
}
}

