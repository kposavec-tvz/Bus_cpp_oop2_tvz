//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <registry.hpp> //ini    stvari
#include <fstream>
#include<iostream>


#include "Unit3.h"              // includani rezultati
#include "Unit4.h"              // includana klasicna igra
#include "Unit5.h"              // includani expanded igra
#include "reinit.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
   //int jezik2;
   UnicodeString welcomeMessage;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonPostavkeClick(TObject *Sender)
{
        int kojiJezik;
		//ShowMessage("Test!");

	  //	ShowMessage(JezikString);
	  TIniFile* ini3 = new TIniFile(GetCurrentDir()+"\\ini_2.ini" );              // ini loada postavke
     /* kojiJezik=ini3->ReadInteger("Postavke","Jezik",1);
	  if (kojiJezik==2) {
		   ShowMessage(kojiJezik);

       const int ENGLISH = (SUBLANG_ENGLISH_US << 10) | LANG_ENGLISH;
		if(LoadNewResourceModule(ENGLISH))
		ReinitializeForms();
		}
		/*else{
		const int CROATIAN = SUBLANG_CROATIAN_CROATIA << 10 | (LANG_CROATIAN);
		if(LoadNewResourceModule(CROATIAN))
		ReinitializeForms();

		}   */


			// tu budem upunio postavke !!

		   Form2->EditImePrezime->Text=ini3->ReadString("Postavke","PlayerIme","Ime i prezime");
	   Form2->EditUsername->Text=ini3->ReadString("Postavke","PlayerUsername","Korisnicko ime");
	   Form2->EditEmail->Text=ini3->ReadString("Postavke","PlayerMail","Email Adresa");
       	delete ini3;
		Form2->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	   TIniFile* ini = new TIniFile(GetCurrentDir()+"\\ini1.ini" );                 // ini sprema

	   ini->WriteInteger("Main Window","Left",Left);
	   ini->WriteInteger("Main Window","Top",Top);

	   delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	   TIniFile* ini = new TIniFile(GetCurrentDir()+"\\ini1.ini" );              // ini loada

	   Left=ini->ReadInteger("Main Window","Left",220);
	   Top=ini->ReadInteger("Main Window","Top",220);

	   delete ini;

        int kojiJezik;
	   TIniFile* ini3 = new TIniFile(GetCurrentDir()+"\\ini_2.ini" );
	   UnicodeString welcomeStr="Dobrodošao ";
	   if (ini3->ReadInteger("Postavke","Jezik",1)==2) {
            welcomeStr="Welcome ";
	   }
	   Label1->Caption=welcomeStr+ini3->ReadString("Postavke","PlayerIme"," novi igrač!");

	  

		delete ini3;


}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
    	   // provjera postoji li ini2

       int kojiJezik;
	   TIniFile* ini3 = new TIniFile(GetCurrentDir()+"\\ini_2.ini" );              // ini loada postavke

	   int postojimli;
	   postojimli=ini3->ReadInteger("Postavke","Postojim",0);
	   kojiJezik=ini3->ReadInteger("Postavke","Jezik",1);               //default HRV

	   // if eng reinit
        /*
		   if (kojiJezik==2) {
		   ShowMessage(kojiJezik);

       const int ENGLISH = (SUBLANG_ENGLISH_US << 10) | LANG_ENGLISH;
		if(LoadNewResourceModule(ENGLISH))
		ReinitializeForms();
		}
		else{
		const int CROATIAN = SUBLANG_CROATIAN_CROATIA << 10 | (LANG_CROATIAN);
		if(LoadNewResourceModule(CROATIAN))
		ReinitializeForms();

		}        */

       UnicodeString welcomeStr="Dobrodošao ";
	   Label1->Caption=welcomeStr+ini3->ReadString("Postavke","PlayerIme"," novi igrač!");

	   if(postojimli==0){
		  ShowMessage("Novi igrac!");
		 Form2->ShowModal();
	   }

		delete ini3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonRezultatiClick(TObject *Sender)
{
     Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonClassicGameClick(TObject *Sender)
{
	Form4->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonExpandedGameClick(TObject *Sender)
{
    Form5->ShowModal();
}
//---------------------------------------------------------------------------

