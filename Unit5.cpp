//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include <registry.hpp> //ini    stvari
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
int vrstaigre=0;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender)
{
	   TIniFile* ini = new TIniFile(GetCurrentDir()+"\\ini1.ini" );              // ini loada pozicije prozora

	   Left=240+ini->ReadInteger("Main Window","Left",220);
	   Top=120+ini->ReadInteger("Main Window","Top",220);

	   delete ini;

       //

}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
//klasicna igra
 vrstaigre=1;
 Close();

}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button2Click(TObject *Sender)
{
//prosirena igra
 vrstaigre=2;
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::RadioButton1Click(TObject *Sender)
{
//klasicna igra
 vrstaigre=1;
Close();

}
//---------------------------------------------------------------------------

void __fastcall TForm5::RadioButton2Click(TObject *Sender)
{
//prosirena igra
 vrstaigre=2;
 Close();

}
//---------------------------------------------------------------------------


