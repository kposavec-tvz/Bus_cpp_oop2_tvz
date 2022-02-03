//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
#include "Unit6.h"
#include <registry.hpp> //ini    stvari
#include "bodovi.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormCreate(TObject *Sender)
{
	   TIniFile* ini = new TIniFile(GetCurrentDir()+"\\ini1.ini" );              // ini loada pozicije prozora

	   Left=125+ini->ReadInteger("Main Window","Left",220);
	   Top=133+ini->ReadInteger("Main Window","Top",220);

	   delete ini;
       Label2->Caption="";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
	int i=0;
	Label2->Caption="OK";
    Close();
}
//---------------------------------------------------------------------------
