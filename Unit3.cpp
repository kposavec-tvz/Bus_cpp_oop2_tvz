//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
#include "Unit6.h"
#include "Unit7.h"
#include <registry.hpp> //ini    stvari
#include "bodovi.h"

#include <memory>
#include <IdHashSHA.hpp>
#include <idhashmessagedigest.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LbCipher"
#pragma link "LbClass"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void ucitajXML(){
  int i;
		int brojskirvenih=0;             //ne koristi se
		UnicodeString hashProvjera;
		_di_IXMLbodoviType bodoviX = Getbodovi(Form4->XMLDocument1);    //ucitava xml
		for(i=0;i<bodoviX->Count;i++){
          //  Form3->ListView1->Columns->
			Form3->ListView1->Items->Add();
			Form3->ListView1->Items->Item[i]->Caption=bodoviX->rezultat[i]->idRezultat;
			Form3->ListView1->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->ime);
			Form3->ListView1->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->user);
			Form3->ListView1->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->email);

			TIdHashMessageDigest5* md5 = new TIdHashMessageDigest5;            //provjera jel prava igra
			hashProvjera=(UnicodeString)bodoviX->rezultat[i]->brojBodova+(UnicodeString)bodoviX->rezultat[i]->idRezultat;
			hashProvjera=md5->HashStringAsHex(hashProvjera);
			if(bodoviX->rezultat[i]->sakriven==hashProvjera){



			if(bodoviX->rezultat[i]->igraVrsta==1)Form3->ListView1->Items->Item[i]->SubItems->Add("Klasična");
				else Form3->ListView1->Items->Item[i]->SubItems->Add("Proširena");
			}else Form3->ListView1->Items->Item[i]->SubItems->Add("VARALICA!");
			delete md5;
			//KRAJ PROVJERE VARANJA

			Form3->ListView1->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->brojBodova);
			Form3->ListView1->Items->Item[i]->SubItems->Add("Lokalno");
            Form3->ListView1->Items->Item[i]->SubItems->Add(i);
		//	ListView1->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->ime);

			/*      kopirano iz 4 cpp da mi je lakše
			zaHashiranje=(UnicodeString)bodovi+vrijemeUserStamp;
			TIdHashMessageDigest5* md5 = new TIdHashMessageDigest5;            //hashiranje rezultata
			hashiranaVrijednost=md5->HashStringAsHex(zaHashiranje);
			ShowMessage(hashiranaVrijednost);
              */



		}

}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	   TIniFile* ini = new TIniFile(GetCurrentDir()+"\\ini1.ini" );              // ini loada pozicije prozora

	   Left=-25+ini->ReadInteger("Main Window","Left",220);
	   Top=-33+ini->ReadInteger("Main Window","Top",220);

	   delete ini;




       //

}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormActivate(TObject *Sender)
{
		//_di_IXMLbodoviType bodovi = Getbodovi(bodovi);
	  //	ucitajXML();
      //ListView1->Columns->


}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{                                                                           //// brisanje
	if(ListView1->Items->Item[0]!=0){
		int i;
		_di_IXMLbodoviType bodoviX = Getbodovi(Form4->XMLDocument1);    //ucitava xml
		bodoviX->Delete(ListView1->ItemIndex);
		Form4->XMLDocument1->SaveToFile(Form4->XMLDocument1->FileName);
		ShowMessage("Izbrisano!");
		ListView1->Items->Clear();
		ucitajXML();
	}else ShowMessage("Nema rezultata učitanih!!");

	//Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormClick(TObject *Sender)
{
//ucitajXML();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
  ucitajXML();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button7Click(TObject *Sender)
{

    	if(ListView1->Items->Item[0]!=0){
		int i;
		_di_IXMLbodoviType bodoviX = Getbodovi(Form4->XMLDocument1);    //ucitava xml
       // Form4->XMLDocument1->SaveToFile(Form4->XMLDocument1->FileName);
		Form6->Label2->Caption="";
		Form6->Edit1->Text=bodoviX->rezultat[ListView1->ItemIndex]->ime;
		Form6->Edit2->Text=bodoviX->rezultat[ListView1->ItemIndex]->user;
		Form6->Edit3->Text=bodoviX->rezultat[ListView1->ItemIndex]->email;
		Form6->Label1->Caption="Rezultat ID: "+bodoviX->rezultat[ListView1->ItemIndex]->idRezultat;
        Form6->ShowModal();

		if(Form6->Label2->Caption=="OK"){
		bodoviX->rezultat[ListView1->ItemIndex]->ime=Form6->Edit1->Text;
		bodoviX->rezultat[ListView1->ItemIndex]->user=Form6->Edit2->Text;
		bodoviX->rezultat[ListView1->ItemIndex]->email=Form6->Edit3->Text;

        Form4->XMLDocument1->SaveToFile(Form4->XMLDocument1->FileName);
		}else ShowMessage("Bez promjene!");

		ListView1->Items->Clear();
	 	ucitajXML();
	}else ShowMessage("Nema rezultata učitanih!!");

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
Form7->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button4Click(TObject *Sender)
{
 //dešifriranje or something
  //	TLb3DES->DecryptFile
  UnicodeString keyValjda;
  UnicodeString imeFajla;
  imeFajla=Edit1->Text;
  keyValjda="123";
  //keyValjda=(UnicodeString)Lb3DES1->GetKey;
 // Lb3DES1->SetKey="4A8A3F328A843E58715B2AEEBBCE3B2D";
  //	Lb3DES1->GenerateRandomKey;
  Lb3DES1->GenerateKey("123");
  //ShowMessage(Lb3DES1->GetKey());
  //key 4A8A3F328A843E58715B2AEEBBCE3B2D
//   keyValjda=Lb3DES1->EncryptString(keyValjda);
//   ShowMessage(keyValjda);

//   keyValjda=Lb3DES1->DecryptString(keyValjda);
//   ShowMessage(keyValjda);
 //	 Lb3DES1->EncryptFile("1bodovi.xml","2bodovi.xml");
	 Lb3DES1->DecryptFile(imeFajla,"_bodovi.xml");





}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
//
int i;
		int brojskirvenih=0;
		UnicodeString hashProvjera;
       // Form4->XMLDocument1->FName
		_di_IXMLbodoviType bodoviX = Getbodovi(Form4->XMLDocument2);    //ucitava xml
		for(i=0;i<bodoviX->Count;i++){
          //  Form3->ListView1->Columns->
			Form3->ListView2->Items->Add();
			Form3->ListView2->Items->Item[i]->Caption=bodoviX->rezultat[i]->idRezultat;
			Form3->ListView2->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->ime);
			Form3->ListView2->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->user);
			Form3->ListView2->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->email);

			TIdHashMessageDigest5* md5 = new TIdHashMessageDigest5;            //provjera jel prava igra
			hashProvjera=(UnicodeString)bodoviX->rezultat[i]->brojBodova+(UnicodeString)bodoviX->rezultat[i]->idRezultat;
			hashProvjera=md5->HashStringAsHex(hashProvjera);
			if(bodoviX->rezultat[i]->sakriven==hashProvjera){



			if(bodoviX->rezultat[i]->igraVrsta==1)Form3->ListView2->Items->Item[i]->SubItems->Add("Klasična");
				else Form3->ListView2->Items->Item[i]->SubItems->Add("Proširena");
			}else Form3->ListView2->Items->Item[i]->SubItems->Add("VARALICA!");
			delete md5;
			//KRAJ PROVJERE VARANJA


			Form3->ListView2->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->brojBodova);
			Form3->ListView2->Items->Item[i]->SubItems->Add("Online");
            Form3->ListView2->Items->Item[i]->SubItems->Add(i);
		//	ListView1->Items->Item[i]->SubItems->Add(bodoviX->rezultat[i]->ime);


		}

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button6Click(TObject *Sender)
{
//
	  Lb3DES1->GenerateKey("123");
      Lb3DES1->EncryptFile("bodovi.xml","kriptirani_bodovi.xml");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	ListView1->Items->Clear();
    ListView2->Items->Clear();
}
//---------------------------------------------------------------------------

