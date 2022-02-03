//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>

#include "Unit2.h"
#include <registry.hpp> //ini    stvari
#include "reinit.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
    //deklariram stvari za postavke

int jezik;
int jezikPocetni;
//std::string PlayerIme,PlayerUsername,PlayerMail;
 UnicodeString PlayerIme,PlayerUsername,PlayerMail,JezikString;


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonSpremiPostavkeClick(TObject *Sender)
{
	//ShowMessage("Spremi!");
	if (RadioButtonENG->Checked==true) {
		jezik=2;
		JezikString="ENG";
	}           else {
		jezik=1;
        RadioButtonHRV->Checked=true;
          JezikString="HRV";
	}
	PlayerIme=EditImePrezime->Text;
	PlayerUsername=EditUsername->Text;
	PlayerMail=EditEmail->Text;

	//Application->MessageBox( PlayerMail,
	 //						L"Postavke");

   //	 ShowMessage(PlayerIme+" "+PlayerUsername+" "+PlayerMail+" "+JezikString);     //testunesenihpodataka

     //spremanje postavka u ini


	   TIniFile* ini = new TIniFile(GetCurrentDir()+"\\ini_2.ini" );                 // ini sprema

	   ini->WriteString("Postavke","Jezik",jezik);
	   ini->WriteString("Postavke","PlayerIme",PlayerIme);
	   ini->WriteString("Postavke","PlayerUsername",PlayerUsername);
	   ini->WriteString("Postavke","PlayerMail",PlayerMail);
	   ini->WriteInteger("Postavke","Postojim",1);

	   delete ini;

		if(jezikPocetni==jezik){
		 if(jezik==2) {

       const int ENGLISH = LANG_ENGLISH | (SUBLANG_ENGLISH_US << 10);
		if(LoadNewResourceModule(ENGLISH))
		ReinitializeForms();
		}
		else{
		const int CROATIAN = LANG_CROATIAN | (SUBLANG_CROATIAN_CROATIA << 10);
		if(LoadNewResourceModule(CROATIAN))
		ReinitializeForms();

		}
        }//ovo je od if(jezikPocetni==jezik

     Close();                                                                                            //zatvara formu za postavke
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
   	   TIniFile* ini = new TIniFile(GetCurrentDir()+"\\ini1.ini" );              // ini loada pozicije prozora

	   Left=25+ini->ReadInteger("Main Window","Left",220);
	   Top=33+ini->ReadInteger("Main Window","Top",220);

	   delete ini;

       //

	   TIniFile* ini2 = new TIniFile(GetCurrentDir()+"\\ini_2.ini" );              // ini loada postavke

	   if(ini2->ReadInteger("Postavke","Jezik",1)==2){
			RadioButtonENG->Checked=True;
            jezikPocetni=2;
			}else  {
			RadioButtonENG->Checked=False;
			RadioButtonHRV->Checked=1;
            jezikPocetni=1;
			};       // jeeezik
	 //  Left=ini->ReadInteger("Main Window","Left",220);
	//   Top=ini->ReadInteger("Main Window","Top",220);


	   EditImePrezime->Text=ini2->ReadString("Postavke","PlayerIme","Ime i prezime");
	   EditUsername->Text=ini2->ReadString("Postavke","PlayerUsername","Korisnicko ime");
	   EditEmail->Text=ini2->ReadString("Postavke","PlayerMail","Email Adresa");


		delete ini2;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TForm2::FormActivate(TObject *Sender)
{
 TIniFile* ini2 = new TIniFile(GetCurrentDir()+"\\ini_2.ini" );              // ini loada postavke
EditImePrezime->Text=ini2->ReadString("Postavke","PlayerIme","Ime i prezime");
	   EditUsername->Text=ini2->ReadString("Postavke","PlayerUsername","Korisnicko ime");
	   EditEmail->Text=ini2->ReadString("Postavke","PlayerMail","Email Adresa");

       if(jezikPocetni==jezik){
		 if(jezik==2) {

       const int ENGLISH = LANG_ENGLISH | (SUBLANG_ENGLISH_US << 10);
		if(LoadNewResourceModule(ENGLISH))
		ReinitializeForms();
		}
		else{
		const int CROATIAN = LANG_CROATIAN | (SUBLANG_CROATIAN_CROATIA << 10);
		if(LoadNewResourceModule(CROATIAN))
		ReinitializeForms();

		}
        }


       	delete ini2;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
//
 int jezik123;
 TIniFile* ini2 = new TIniFile(GetCurrentDir()+"\\ini_2.ini" );              // ini loada postavke
EditImePrezime->Text=ini2->ReadString("Postavke","PlayerIme","Ime i prezime");
	   EditUsername->Text=ini2->ReadString("Postavke","PlayerUsername","Korisnicko ime");
	   EditEmail->Text=ini2->ReadString("Postavke","PlayerMail","Email Adresa");
		jezik=ini2->ReadInteger("Postavke","Jezik",1);
	   if(jezik==1)
	   RadioButtonHRV->Checked=1;
	   else RadioButtonENG->Checked=1;
       	delete ini2;

}
//---------------------------------------------------------------------------

