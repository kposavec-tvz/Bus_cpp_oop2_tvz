//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
UnicodeString ExtractUrlFileName(UnicodeString url) {
	int i = LastDelimiter('/', url);
	return url.SubString(i + 1, url.Length() - i);
}


 class prebaciMaks{
	public:
        int a;
 };
 prebaciMaks maksimalac;


void __fastcall TForm7::Button1Click(TObject *Sender)
{

   TFileStream* fs = new TFileStream("downloaded.xml",fmCreate);
	IdHTTP1->Get(Edit1->Text, fs);
	delete fs;

}
//---------------------------------------------------------------------------
  //https://i.imgur.com/x54tMdz.jpg
void __fastcall TForm7::IdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax)

{
 //
 int maksBrz=0;
	if(RadioButton1->Checked)maksBrz=512*8;
	if(RadioButton2->Checked)maksBrz=1024*8;
	if(RadioButton3->Checked)maksBrz=1024*2*8;
	if(CheckBox1->Checked)IdInterceptThrottler1->BitsPerSec=maksBrz;
		else maksBrz=0;
maksimalac.a=AWorkCountMax;



}
//---------------------------------------------------------------------------

void __fastcall TForm7::IdHTTP1Work(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)

{



	int postotak=0;
	postotak=100-(int)maksimalac.a/AWorkCount;
	if(postotak>0)Label2->Caption=(UnicodeString)postotak+"%";
		else
			if(Form2->RadioButtonHRV->Checked==1)Label2->Caption="Priprema...";
				else Label2->Caption="Preparing...";
  // Label2->Caption=AWorkCount;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::IdHTTP1WorkEnd(TObject *ASender, TWorkMode AWorkMode)
{
   if(Form2->RadioButtonHRV->Checked==1)Label2->Caption="Gotovo!";
   	else Label2->Caption="Done!";
}
//---------------------------------------------------------------------------

void __fastcall TForm7::CheckBox1Click(TObject *Sender)
{
	//IdInterceptThrottler1
	/*
	int maksBrz=0;
	if(RadioButton1->Checked)maksBrz=512*8;
	if(RadioButton1->Checked)maksBrz=1024*8;
	if(RadioButton1->Checked)maksBrz=1024*2*8;
	if(CheckBox1->Checked)IdInterceptThrottler1->BitsPerSec=maksBrz;
		else maksBrz=0;   */

        	int maksBrz=0;
	if(RadioButton1->Checked)maksBrz=512*8;
	if(RadioButton2->Checked)maksBrz=1024*8;
	if(RadioButton3->Checked)maksBrz=1024*2*8;
	if(CheckBox1->Checked)IdInterceptThrottler1->BitsPerSec=maksBrz;
		else maksBrz=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormClose(TObject *Sender, TCloseAction &Action)
{
//
	IdHTTP1->Disconnect();
    Label2->Caption="Prekinuto!";
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button2Click(TObject *Sender)
{
   IdHTTP1->Disconnect();
   Label2->Caption="Prekinuto!";
}
//---------------------------------------------------------------------------

void __fastcall TForm7::RadioButton1Click(TObject *Sender)
{
	int maksBrz=0;
	if(RadioButton1->Checked)maksBrz=512*8;
	if(RadioButton2->Checked)maksBrz=1024*8;
	if(RadioButton3->Checked)maksBrz=1024*2*8;
	if(CheckBox1->Checked)IdInterceptThrottler1->BitsPerSec=maksBrz;
		else maksBrz=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::RadioButton2Click(TObject *Sender)
{
	int maksBrz=0;
	if(RadioButton1->Checked)maksBrz=512*8;
	if(RadioButton2->Checked)maksBrz=1024*8;
	if(RadioButton3->Checked)maksBrz=1024*2*8;
	if(CheckBox1->Checked)IdInterceptThrottler1->BitsPerSec=maksBrz;
		else maksBrz=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::RadioButton3Click(TObject *Sender)
{
	int maksBrz=0;
	if(RadioButton1->Checked)maksBrz=512*8;
	if(RadioButton2->Checked)maksBrz=1024*8;
	if(RadioButton3->Checked)maksBrz=1024*2*8;
	if(CheckBox1->Checked)IdInterceptThrottler1->BitsPerSec=maksBrz;
		else maksBrz=0;
}
//---------------------------------------------------------------------------

