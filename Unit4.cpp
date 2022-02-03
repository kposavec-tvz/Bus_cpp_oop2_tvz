//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit5.h"
#include "Unit2.h"
#include "bodovi.h"
#include <registry.hpp> //ini    stvari
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <algorithm>    // std::random_shuffle
#include <iostream>     // std::cout

#include <chrono>   // za timestamp xml rezultat id
#include <ctime>

#include <memory>
#include <IdHashSHA.hpp> // hash stvari
#include <idhashmessagedigest.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LbCipher"
#pragma link "LbClass"
#pragma resource "*.dfm"
TForm4 *Form4;
HINSTANCE Karte;
HINSTANCE Karte1;
//---------------------------------------------------------------------------
int vrstaigre=0;
//---------------------------------------------------------------------------
 // odabir igre

int vrstaIgreFunk(){
    int vrstaigre=0;
	if(Form5->ShowModal()){
	if(Form5->RadioButton1->Checked)   vrstaigre=1;
	if(Form5->RadioButton2->Checked)   vrstaigre=2;
	//ShowMessage(vrstaigre);
	}

	return vrstaigre;
}

//------------
//------------
//------------
//------------
//------------

//
//

//Prva karta hit = 2
//Druga = 4
//Boja = 10
//Četvrta = 13
//Pobjeda=preostaleKarte*12
//ista= *2

//------------
//------------
//------------
//------------


// logika igre određuje koja je karta aktivna, updatea slike i čeka inpute
// svaki gumb nju poziva i čeka daljnje upute
// iz nje se poziva bodovanj
/*

	CLUBS = 0              TREF             1 -13
	DIAMONDS = 1       KARA                 14-26
	HEARTS = 2     HERC                     27-39
	SPADES = 3  PIK                         40-52

	Ace = 1
	Two = 
	Three = 
	Four = 
	Five = 
	Six = 
	Seven = 
	Eight = 
	Nine = 
	Ten = 10
	Jack = 11
	Queen = 12
	King = 0

	VRIJEDNOST == broj % 13
	BOJA = int broj/13


 */
int randomiziraniBroj (int i) { return std::rand()%i;}

class LogikaBodovanja{
	public:
	 int bodovi=0;
	 int brojPogodaka;
	 int dosegnutaKarta;
	 int trenutnaPozicija;
	 int vrstaIgreBod;
     int jelIsta;
	 int maxKarteBod;
     int vrstaIgreBodPRAVA=2;
	 UnicodeString igracIme, igracUser, igracEmail;
     UnicodeString vrijemeUserStamp;
	 UnicodeString rezultatRecenica();
		void kojaJeVrsta(int vrstaIgreBod){
			if(vrstaIgreBod==1){
				maxKarteBod=32;
                vrstaIgreBodPRAVA=1;
			}
			else maxKarteBod=52;
			//ShowMessage(maxKarteBod);
		};
		void pozoviBodove(int trenutnaPozicija, int jelIsta){
			switch(trenutnaPozicija){
				case 0:
					bodovi=bodovi+2;
					if (jelIsta) {
                      bodovi=bodovi+2;
					}
					break;
				case 1:
					bodovi=bodovi+4;
					if (jelIsta) {
					  bodovi=bodovi+4;
					}
					break;
				case 2:
					bodovi=bodovi+10;    //boja
					break;
				case 3:
					bodovi=bodovi+13;
					if (jelIsta) {
                      bodovi=bodovi+13;
					}
					break;
               case 4:
					bodovi=bodovi+13;
					if (jelIsta) {
                      bodovi=bodovi+13;
					}
                    break;
			}

			Form4->Label18->Caption=bodovi;
		};
		void GotovaIgra(int trenutnaKartaBod){
			UnicodeString hashiranaVrijednost, zaHashiranje;
			bodovi=bodovi+12*(maxKarteBod-trenutnaKartaBod);


			Form4->Label18->Caption=bodovi;
            //Form4->Label18->Color=(TColor)0x8c8a8a;
			_di_IXMLbodoviType bodoviX = Getbodovi(Form4->XMLDocument1);    //ucitava xml
			std::time_t vrijemeStamp = std::time(0);   // get time now
			ShowMessage(vrijemeStamp);
			vrijemeUserStamp=Form2->EditUsername->Text;
			vrijemeUserStamp=vrijemeUserStamp+(UnicodeString)vrijemeStamp+vrijemeStamp%10;
			igracIme=Form2->EditImePrezime->Text;
			igracUser=Form2->EditUsername->Text;
			igracEmail=Form2->EditEmail->Text;

			zaHashiranje=(UnicodeString)bodovi+vrijemeUserStamp;
			TIdHashMessageDigest5* md5 = new TIdHashMessageDigest5;            //hashiranje rezultata
			hashiranaVrijednost=md5->HashStringAsHex(zaHashiranje);
			//ShowMessage(hashiranaVrijednost);

			//spremanje u xml
			_di_IXMLrezultatType rezultat = bodoviX->Add();
			rezultat->idRezultat=vrijemeUserStamp;
			rezultat->ime=igracIme;
			rezultat->user=igracUser;
			rezultat->email=igracEmail;
			rezultat->igraVrsta=vrstaIgreBodPRAVA;
			rezultat->brojBodova=bodovi;
			rezultat->sakriven=hashiranaVrijednost;              //sprema hash!
            Form4->XMLDocument1->SaveToFile(Form4->XMLDocument1->FileName);
            delete md5;

		};

};

LogikaBodovanja bodujMe;

class LogikaIgre{
	public:
	 int i,j,tempInt;
	 int karta0,karta1,karta2,karta3,karta4;
	 int randomiziraniBroj;
	 std::vector<int> karteObicne{1,7,8,9,10,11,12,13,14,20,21,22,23,24,25,26,27,33,34,35,36,37,38,39,40,46,47,48,49,50,51,52};
	 std::vector<int> karteObicneReset{1,7,8,9,10,11,12,13,14,20,21,22,23,24,25,26,27,33,34,35,36,37,38,39,40,46,47,48,49,50,51,52};
	 std::vector<int> karteProsirene{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};
	 int bodovi;
	 int trenutnaKarta;
	 int pozicija=0;
	 int kojaVrstaIgre;
	 int karteZaKraj=32;
	 int jelDosegunataBoja=0;
	 int vrijednostTrenutneKarte;
     int vrijednostKarteNaStolu;
	 int brojPogodaka;
	 int dosegnutaKarta;
	 UnicodeString testniStringy;
		//int upspjeh(int pozicija, int odabrana);
        //void pokretanjeIgre();
		void randomMijesanje(int kojaVrstaIgre){
		//LogikaBodovanja bodujMe;
		bodujMe.kojaJeVrsta(kojaVrstaIgre);
		//ovo je temp tu, neće se zapravo ovdje koristit bodujMe.pozoviBodove(pozicija, )


			karteObicne=karteObicneReset;         //postavlja klasik igru, a niže ak je proširena promjeni
            karteZaKraj=32;                       // potrebno kad se igra ponovno pokrene bez gašenja programa
            //testiranje vektora
		   /*
			for(i=0;i<karteObicne.size();i++){
				 testniStringy=testniStringy+" "+(UnicodeString)karteObicne[i]+" ";
				 };
			ShowMessage("prije šafla: "+testniStringy);
			testniStringy="";
			 */

			if (kojaVrstaIgre==2) {
				karteObicne=karteProsirene;
                karteZaKraj=52;
			}


			std::srand ( unsigned ( std::time(0) ) );
			std::random_shuffle(karteObicne.begin(),karteObicne.end());
			for(i=0;i<karteObicne.size();i++){
			  testniStringy=testniStringy+" "+(UnicodeString)karteObicne[i]+" ";
               };
		 //	ShowMessage("nakon šafla: "+testniStringy);

				   Karte1 = LoadLibraryA("cards.dll");
				   if (!Karte1) {
				 	ShowMessage("fail!!!");
                 //Close();
	   					}
			//  ShowMessage(karteObicne[0]);
			  Form4->Image1->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[0]);
			  karta0=karteObicne[0];

			//  ShowMessage(karteObicne[1]);
			  Form4->Image2->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[1]);
			  karta1=karteObicne[1];

			//  ShowMessage(karteObicne[2]);

				karta2=karteObicne[4];     //preskacem boju u prvom passu za sliku ali postavljam vrijednost.  [4] jer nisam mislio unaprijed

			  Form4->Image4->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[2]);  //preskacem boju u prvom passu za sliku ali postavljam vrijednost
			  karta3=karteObicne[2];

			//  ShowMessage(karteObicne[3]);
			  Form4->Image5->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[3]);
			  karta4=karteObicne[3];
			  trenutnaKarta=5;
			  Form4->Label1->Caption="    V  ";

              	   if (Form2->EditImePrezime->Text!="Ja Varam"){               //sakriva podatke za varanje ako player name nije   Ja Varam
					Form4->Label6->Visible=0;
                    Form4->Label7->Visible=0;
					Form4->Label12->Visible=0;
					Form4->Label13->Visible=0;
					Form4->Label14->Visible=0;
					Form4->Label15->Visible=0;
					Form4->Label16->Visible=0;

					Form4->Label10->Visible=0;
					Form4->Label11->Visible=0;
				   }else{
                    Form4->Label12->Visible=1;
					Form4->Label13->Visible=1;
					Form4->Label14->Visible=1;
					Form4->Label15->Visible=1;
					Form4->Label16->Visible=1;

					Form4->Label10->Visible=1;
					Form4->Label11->Visible=1;


				   }




		};
		void pozoviMe(int kojiGumbMeZove){      	//tu je vecina posla zapravo  ///////////////////////////////////////////////////////////
		 //	Form4->Label18->Font->Color=(TColor)0x32FF64;
            UnicodeString failMsg="Promašaj, natrag na start";
			UnicodeString hitMsg="Pogodak!";
            UnicodeString krivaKarta="Na krivoj si karti!";
         	if (Form2->RadioButtonENG->Checked) {
			failMsg="Fail, back to start";
			hitMsg="Hit!";
            krivaKarta="Wrong card!";
			}


			if(trenutnaKarta==karteZaKraj){
			krajIgre();
            Form4->Close();
			}
			vrijednostTrenutneKarte=karteObicne[trenutnaKarta]%13;                //as = 1, kralj = 0
			if(vrijednostTrenutneKarte==0)vrijednostTrenutneKarte=13;  //kralj je 13
			if(vrijednostTrenutneKarte==1)vrijednostTrenutneKarte=14;  //as je 14


			

              	if (Form2->RadioButtonENG->Checked) {
			failMsg="Fail, back to start";
			hitMsg="Hit!";
            krivaKarta="Wrong card!";
			}
			/////////////////////// karta 1
			/////////////////////// karta 1
						/////////////////////// karta 1
									/////////////////////// karta 1
		
			if(kojiGumbMeZove==1 ||kojiGumbMeZove==2 || kojiGumbMeZove==3 ){
			if(pozicija==0){     ////////////////
			//ShowMessage(kojiGumbMeZove);

				vrijednostKarteNaStolu=karta0%13;           //as = 1, kralj = 0
				if(vrijednostKarteNaStolu==0)vrijednostKarteNaStolu=13;     //kralj je 13
				if(vrijednostKarteNaStolu==1)vrijednostKarteNaStolu=14;     //kralj je 13

		   //	ShowMessage("karta na stolu "+(UnicodeString)vrijednostKarteNaStolu+"  a dolazi  "+(UnicodeString)vrijednostTrenutneKarte);


        //// manja
			if(kojiGumbMeZove%3==1){
            //ShowMessage("manja");
				if(vrijednostKarteNaStolu>vrijednostTrenutneKarte){
					//ShowMessage("hit!");
					Form4->Label19->Caption=hitMsg;
					karta0=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image1->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					bodujMe.pozoviBodove(pozicija, 0);
					trenutnaKarta++;
					pozicija++;
					}

				else{
					//ShowMessage("fail!");
					Form4->Label19->Caption=failMsg;
                    karta0=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					 Form4->Image1->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
            }

        /// ista
			if(kojiGumbMeZove%3==2){
			//ShowMessage("ista");
				 if(vrijednostKarteNaStolu==vrijednostTrenutneKarte){
				// ShowMessage("hit!");
				Form4->Label19->Caption=hitMsg;
                 karta0=karteObicne[trenutnaKarta];      //updejta vrijednost karte
				 Form4->Image1->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
                 bodujMe.pozoviBodove(pozicija, 1);
				 trenutnaKarta++;
				 pozicija++;
				}else{
					//ShowMessage("fail!");
					Form4->Label19->Caption=failMsg;
                    karta0=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					 Form4->Image1->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}

            // veca
			if(kojiGumbMeZove%3==0){
			//ShowMessage("veca");
			//ShowMessage("veca, karta na stolu "+(UnicodeString)vrijednostKarteNaStolu+" a dolazi "+(UnicodeString)vrijednostTrenutneKarte);
				if(vrijednostKarteNaStolu<vrijednostTrenutneKarte){
					Form4->Label19->Caption=hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta0=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image1->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}
				 else {
			   //	 ShowMessage("fail!");
				 Form4->Label19->Caption=failMsg;
				 karta0=karteObicne[trenutnaKarta];      //updejta vrijednost karte
				 Form4->Image1->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
				 trenutnaKarta++;
				 pozicija=0;
				}


		}  // kraj prvog seta gumbi


	
		}else ShowMessage(krivaKarta);         //krivaKarta
		};
		/// kraj gumbi prve karte

					///////////////////////
			///////////////////////
						///////////////////////
							///////////////////////
							///////////////////////
								///////////////////////
				///////////////////////	///////////////////////

					/////////////////////// karta 2       2222222222222222222222
			/////////////////////// karta 2
						/////////////////////// karta 2
									/////////////////////// karta 2

			if(kojiGumbMeZove==4 ||kojiGumbMeZove==5 || kojiGumbMeZove==6 ){
			if(pozicija==1){     ////////////////
			//ShowMessage(kojiGumbMeZove);

				vrijednostKarteNaStolu=karta1%13;           //as = 1, kralj = 0
				if(vrijednostKarteNaStolu==0)vrijednostKarteNaStolu=13;     //kralj je 13
				if(vrijednostKarteNaStolu==1)vrijednostKarteNaStolu=14;     //kralj je 13

		//	ShowMessage("karta na stolu "+(UnicodeString)vrijednostKarteNaStolu+"  a dolazi  "+(UnicodeString)vrijednostTrenutneKarte);


        //// manja
			if(kojiGumbMeZove%3==1){
		  //  ShowMessage("manja");
				if(vrijednostKarteNaStolu>vrijednostTrenutneKarte){
					Form4->Label19->Caption="      "+hitMsg;
					karta1=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image2->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
                    bodujMe.pozoviBodove(pozicija, 0);
					pozicija++;
                    jelDosegunataBoja++;
					}

				else{
				  //	ShowMessage("fail!");
					Form4->Label19->Caption="     "+failMsg;
					karta1=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					 Form4->Image2->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
            }

        /// ista
			if(kojiGumbMeZove%3==2){
		  //  ShowMessage("ista");
				 if(vrijednostKarteNaStolu==vrijednostTrenutneKarte){
				 Form4->Label19->Caption="     "+hitMsg;
                 bodujMe.pozoviBodove(pozicija, 1);
				 karta1=karteObicne[trenutnaKarta];      //updejta vrijednost karte
				 Form4->Image2->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
				 trenutnaKarta++;
				 pozicija++;
                 jelDosegunataBoja++;
				}else{
				   //	ShowMessage("fail!");
				   Form4->Label19->Caption="     "+failMsg;
					karta1=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					 Form4->Image2->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}

            // veca
			if(kojiGumbMeZove%3==0){
		  //  ShowMessage("veca");
			//ShowMessage("veca, karta na stolu "+(UnicodeString)vrijednostKarteNaStolu+" a dolazi "+(UnicodeString)vrijednostTrenutneKarte);
				if(vrijednostKarteNaStolu<vrijednostTrenutneKarte){
					Form4->Label19->Caption="     "+hitMsg;
                    bodujMe.pozoviBodove(pozicija, 0);
					karta1=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image2->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
                    jelDosegunataBoja++;
					}
				 else {
			 //	 ShowMessage("fail!");
				 Form4->Label19->Caption="     "+failMsg;
				 karta1=karteObicne[trenutnaKarta];      //updejta vrijednost karte
				 Form4->Image2->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
				 trenutnaKarta++;
				 pozicija=0;
				}


		}

		}else ShowMessage(krivaKarta);
		};
		/// kraj gumbi druuuuge karte
					///////////////////////
			///////////////////////
						///////////////////////
							///////////////////////
							///////////////////////
								///////////////////////
				///////////////////////	///////////////////////

			/////////////////////// karta 3                boooooooooooooooooooooooooooooooooooooooooooojaaaaaa
			/////////////////////// karta 3
						/////////////////////// karta 3
									/////////////////////// karta 3

			if(kojiGumbMeZove>99 ){        // tref 100, kara 200, herc 300, pik 400
			if(pozicija==2){     ////////////////
		//// boja
		  // tref 100, kara 200, herc 300, pik 400
		  if(jelDosegunataBoja==1){
			if(kojiGumbMeZove==100){
		 //	ShowMessage("tref 100");
				  if((int)karta2/13==0){
					tempInt=(int)karta2/13;
					Form4->Label19->Caption="        "+hitMsg;
                    bodujMe.pozoviBodove(pozicija, 0);
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[4]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}

				else{
				  //	ShowMessage("fail!");
					Form4->Label19->Caption="        "+failMsg;
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[4]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
		  			}
				}
			else
						if(kojiGumbMeZove==200){
		   //				ShowMessage("200 kara");
				if((int)karta2/13==1){
					Form4->Label19->Caption="        "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[4]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}

				else{
				 //	ShowMessage("fail!");
					Form4->Label19->Caption="        "+failMsg;
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[4]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}
			else
						if(kojiGumbMeZove==300){
		  //				ShowMessage("herc 300");
				if((int)karta2/13==2){
					Form4->Label19->Caption="        "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[4]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}

				else{
				 //	ShowMessage("fail!");
					Form4->Label19->Caption="        "+failMsg;
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[4]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}
			else
			if(kojiGumbMeZove==400){
		 //   ShowMessage("pik 400");
				if((int)karta2/13==3){
					Form4->Label19->Caption="        "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[4]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}

				else{
				 //	ShowMessage("fail!");
					Form4->Label19->Caption="        "+failMsg;
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[4]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}
		  }else if(kojiGumbMeZove==100){                             // ako je druigi+ pokušaj na boji    ///////////
		 //	ShowMessage("tref 100");
				  if((int)karteObicne[trenutnaKarta]/13==0){
					//tempInt=(int)karta2/13;
					Form4->Label19->Caption="        "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}

				else{
				 //	ShowMessage("fail!");
					Form4->Label19->Caption="        "+failMsg;
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
		  			}
				}
			else
						if(kojiGumbMeZove==200){
		  //				ShowMessage("200 kara");
				if((int)karteObicne[trenutnaKarta]/13==1){
					Form4->Label19->Caption="        "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}

				else{
				  //	ShowMessage("fail!");
					Form4->Label19->Caption="        "+failMsg;
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}
			else
						if(kojiGumbMeZove==300){
			 //			ShowMessage("herc 300");
				if((int)karteObicne[trenutnaKarta]/13==2){
					Form4->Label19->Caption="         "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}

				else{
				//	ShowMessage("fail!");
					Form4->Label19->Caption="        "+failMsg;
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}
			else
			if(kojiGumbMeZove==400){
       //     ShowMessage("pik 400");
				if((int)karteObicne[trenutnaKarta]/13==3){
					Form4->Label19->Caption="        "+hitMsg;
                    bodujMe.pozoviBodove(pozicija, 0);
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					}

				else{
				 //	ShowMessage("fail!");
					Form4->Label19->Caption="        "+failMsg;
					karta2=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}






		}else ShowMessage(krivaKarta);
		};
		/// kraj gumbi karte boje
					///////////////////////
			///////////////////////
						///////////////////////
							///////////////////////
							///////////////////////
								///////////////////////
				///////////////////////	///////////////////////

										/////////////////////// karta 4

			if(kojiGumbMeZove==11 ||kojiGumbMeZove==12 || kojiGumbMeZove==10 ){
			if(pozicija==3){     ////////////////
			//ShowMessage(kojiGumbMeZove);

				vrijednostKarteNaStolu=karta3%13;           //as = 1, kralj = 0
				if(vrijednostKarteNaStolu==0)vrijednostKarteNaStolu=13;     //kralj je 13
				if(vrijednostKarteNaStolu==1)vrijednostKarteNaStolu=14;     //kralj je 13

		 //	ShowMessage("karta na stolu "+(UnicodeString)vrijednostKarteNaStolu+"  a dolazi  "+(UnicodeString)vrijednostTrenutneKarte);


        //// manja
			if(kojiGumbMeZove%3==1){
	  //      ShowMessage("manja");
				if(vrijednostKarteNaStolu>vrijednostTrenutneKarte){
					Form4->Label19->Caption="             "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta3=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image4->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					jelDosegunataBoja++;
					}

				else{
				  //	ShowMessage("fail!");
					Form4->Label19->Caption="             "+failMsg;
					karta3=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					 Form4->Image4->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
            }

        /// ista
			if(kojiGumbMeZove%3==2){
	 //       ShowMessage("ista");
				 if(vrijednostKarteNaStolu==vrijednostTrenutneKarte){
				 Form4->Label19->Caption="             "+hitMsg;
                 bodujMe.pozoviBodove(pozicija, 1);
				 karta3=karteObicne[trenutnaKarta];      //updejta vrijednost karte
				 Form4->Image4->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
				 trenutnaKarta++;
				 pozicija++;
                 jelDosegunataBoja++;
				}else{
				 //	ShowMessage("fail!");
					Form4->Label19->Caption="             "+failMsg;
					karta3=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					 Form4->Image4->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}

            // veca
			if(kojiGumbMeZove%3==0){
	  //      ShowMessage("veca");
			//ShowMessage("veca, karta na stolu "+(UnicodeString)vrijednostKarteNaStolu+" a dolazi "+(UnicodeString)vrijednostTrenutneKarte);
				if(vrijednostKarteNaStolu<vrijednostTrenutneKarte){
					Form4->Label19->Caption="              "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta3=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image4->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
                    jelDosegunataBoja++;
					}
				 else {
			 //	 ShowMessage("fail!");
				 Form4->Label19->Caption="             "+failMsg;
				 karta3=karteObicne[trenutnaKarta];      //updejta vrijednost karte
				 Form4->Image4->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
				 trenutnaKarta++;
				 pozicija=0;
				}


		}

		}else ShowMessage(krivaKarta);
		};


	/////////////////////// karta 5 zadnja omg  	/////////////////////// karta 5 zadnja omg	/////////////////////// karta 5 zadnja omg
	// zadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnja
		// zadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnja
			// zadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnjazadnja


		if(kojiGumbMeZove==15 ||kojiGumbMeZove==14 || kojiGumbMeZove==13 ){
			if(pozicija==4){     ////////////////
			//ShowMessage(kojiGumbMeZove);

				vrijednostKarteNaStolu=karta4%13;           //as = 1, kralj = 0
				if(vrijednostKarteNaStolu==0)vrijednostKarteNaStolu=13;     //kralj je 13
				if(vrijednostKarteNaStolu==1)vrijednostKarteNaStolu=14;     //kralj je 13

		  //	ShowMessage("karta na stolu "+(UnicodeString)vrijednostKarteNaStolu+"  a dolazi  "+(UnicodeString)vrijednostTrenutneKarte);


        //// manja
			if(kojiGumbMeZove%3==1){
	 //       ShowMessage("manja");
				if(vrijednostKarteNaStolu>vrijednostTrenutneKarte){
					Form4->Label19->Caption="               "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta4=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image5->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
					jelDosegunataBoja++;
					}

				else{
				 //	ShowMessage("fail!");
					Form4->Label19->Caption="               "+failMsg;
					karta4=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					 Form4->Image5->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
            }

        /// ista
			if(kojiGumbMeZove%3==2){
	 //       ShowMessage("ista");
				 if(vrijednostKarteNaStolu==vrijednostTrenutneKarte){
				 Form4->Label19->Caption="               "+hitMsg;
                 bodujMe.pozoviBodove(pozicija, 1);
				 karta4=karteObicne[trenutnaKarta];      //updejta vrijednost karte
				 Form4->Image5->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
				 trenutnaKarta++;
				 pozicija++;
                 jelDosegunataBoja++;
				}else{
				 //	ShowMessage("fail!");
					Form4->Label19->Caption="               "+failMsg;
					karta4=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					 Form4->Image5->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija=0;
					}
			}

            // veca
			if(kojiGumbMeZove%3==0){
      //      ShowMessage("veca");
			//ShowMessage("veca, karta na stolu "+(UnicodeString)vrijednostKarteNaStolu+" a dolazi "+(UnicodeString)vrijednostTrenutneKarte);
				if(vrijednostKarteNaStolu<vrijednostTrenutneKarte){
					Form4->Label19->Caption="               "+hitMsg;
					bodujMe.pozoviBodove(pozicija, 0);
					karta4=karteObicne[trenutnaKarta];      //updejta vrijednost karte
					Form4->Image5->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
					trenutnaKarta++;
					pozicija++;
                    jelDosegunataBoja++;
					}
				 else {
			 //	 ShowMessage("fail!");
				 Form4->Label19->Caption="               "+failMsg;
				 karta4=karteObicne[trenutnaKarta];      //updejta vrijednost karte
				 Form4->Image5->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, karteObicne[trenutnaKarta]);    //updejta sliku karte
				 trenutnaKarta++;
				 pozicija=0;
				}


		}

		if(pozicija>0){        //ako nakon 5. karte nije vracen na kraj znaci da je pobjeda
                bodujMe.GotovaIgra(trenutnaKarta);
				pobjeda();

		   }
		}else ShowMessage(krivaKarta);

		

		};



	Form4->Label7->Caption=(UnicodeString)pozicija+1;
	Form4->Label9->Caption=(UnicodeString)trenutnaKarta;
	Form4->Label11->Caption=(UnicodeString)karteObicne[trenutnaKarta];

	Form4->Label12->Caption=(UnicodeString)karta0;
	Form4->Label13->Caption=(UnicodeString)karta1;
	Form4->Label14->Caption=(UnicodeString)karta2;
	Form4->Label15->Caption=(UnicodeString)karta3;
	Form4->Label16->Caption=(UnicodeString)karta4;

    // labeliranje na kojoj si karti
			Form4->Label1->Caption="     ";
			Form4->Label2->Caption="     ";
			Form4->Label3->Caption="     ";
			Form4->Label4->Caption="     ";
			Form4->Label5->Caption="     ";
			switch(pozicija){
				case 0:
				  Form4->Label1->Caption="    V  ";
				  break;
				case 1:
					Form4->Label2->Caption="    V  ";
				  break;
				case 2:
					Form4->Label3->Caption="    V  ";
				  break;
				case 3:
					Form4->Label4->Caption="    V  ";
				  break;
				 case 4:
					Form4->Label5->Caption="    V  ";
				  break;

			}

		if(trenutnaKarta==karteZaKraj)krajIgre();
		}
		void pobjeda(){

			if (Form2->RadioButtonENG->Checked){
            ShowMessage("BRAVO! YOU WON!");
			ShowMessage("Final score: "+(UnicodeString)bodujMe.bodovi);
			}else{
			ShowMessage("BRAVO! POBIJEDIO SI!");
			ShowMessage("Tvoj konacni broj bodova je "+(UnicodeString)bodujMe.bodovi);
            }
			pozicija=0;
			jelDosegunataBoja=0;
			//Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, 53);
            FreeLibrary(Karte1);
			Form4->Close();

		};
		void krajIgre(){
			pozicija=0;
            //Form4->Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte1, 53);
			jelDosegunataBoja=0;
			FreeLibrary(Karte1);
			if (Form2->RadioButtonENG->Checked)ShowMessage("Thanks for playing!"); else ShowMessage("Hvala na igranju!");
            Form4->Close();
		};
};



 LogikaIgre igrajmoSe;           ////////////////////----------------aaaaaa
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{

	   TIniFile* ini = new TIniFile(GetCurrentDir()+"\\ini1.ini" );              // ini loada pozicije prozora

	   Left=-20+ini->ReadInteger("Main Window","Left",220);
	   Top=-33+ini->ReadInteger("Main Window","Top",220);


	   delete ini;
	   Label19->Caption="";
	   if (Form2->EditImePrezime->Text!="Ja Varam"){               //sakriva podatke za varanje ako player name nije   Ja Varam
		Label12->Visible=0;
		Label13->Visible=0;
		Label14->Visible=0;
		Label15->Visible=0;
		Label16->Visible=0;

		Label10->Visible=0;
        Label11->Visible=0;
	   }

	   //

	   Karte = LoadLibraryA("cards.dll");
	   if (!Karte) {
				 ShowMessage("fail!!!");
                 Close();
	   }

	   vrstaigre=0;
       bodujMe.bodovi=0;
       // početno stanje karata

	   //Karta 1
       Image1->Picture->Bitmap->LoadFromResourceID((unsigned)Karte, 53);
	   //Karta 2
	   Image2->Picture->Bitmap->LoadFromResourceID((unsigned)Karte, 53);
	   //Karta 3
	   Image3->Picture->Bitmap->LoadFromResourceID((unsigned)Karte, 53);
	   //Karta 4
	   Image4->Picture->Bitmap->LoadFromResourceID((unsigned)Karte, 53);
	   //Karta 5
	   Image5->Picture->Bitmap->LoadFromResourceID((unsigned)Karte, 53);

       FreeLibrary(Karte);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormActivate(TObject *Sender)
{
//zove formu 5 sa selektiranje vrste igre
Form5->RadioButton1->Checked=0;
Form5->RadioButton2->Checked=0;
vrstaigre=vrstaIgreFunk();
Label19->Caption="BUS";
while (vrstaigre==0) {
	if(Form2->RadioButtonENG->Checked)ShowMessage("Select a gametype!");
	else ShowMessage("Pokreni ponovo te daberi vrstu igre!");
    vrstaigre=vrstaIgreFunk();
}

//test za vrijeme stvari
 //	std::time_t vrijemeStamp = std::time(0);   // get time now
  //  ShowMessage(vrijemeStamp);

// pokrene logiku igre
//	LogikaIgre igrajmoSe;

	igrajmoSe.randomMijesanje(vrstaigre);

	// ovo su početne vrijednosti, gore ih ukucam

	Form4->Label7->Caption=(UnicodeString)igrajmoSe.pozicija+1;
	Form4->Label9->Caption=(UnicodeString)igrajmoSe.trenutnaKarta;
	Form4->Label11->Caption=(UnicodeString)igrajmoSe.karteObicne[igrajmoSe.trenutnaKarta];

	Form4->Label12->Caption=(UnicodeString)igrajmoSe.karta0;
	Form4->Label13->Caption=(UnicodeString)igrajmoSe.karta1;
	Form4->Label14->Caption=(UnicodeString)igrajmoSe.karta2;
	Form4->Label15->Caption=(UnicodeString)igrajmoSe.karta3;
	Form4->Label16->Caption=(UnicodeString)igrajmoSe.karta4;

    Form4->Label18->Caption=" 0 ";


//pokreče logiku bodovanja



}

//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	//if jesam li aktivan == 1 onda poziva funkciju else kaže da je kriva karta   --- ovo cu ipak hendlat u objektu
	igrajmoSe.pozoviMe(1);

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(2);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(3);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button4Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(4);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button5Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(5);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(6);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button7Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(7);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button8Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(8);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button9Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(9);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button10Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(10);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button11Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(11);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button12Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(12);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button13Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(13);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button14Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(14);	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button15Click(TObject *Sender)
{
	igrajmoSe.pozoviMe(15);
}
//---------------------------------------------------------------------------




void __fastcall TForm4::ButtonTrefClick(TObject *Sender)
{
  igrajmoSe.pozoviMe(100);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ButtonKaraClick(TObject *Sender)
{
  igrajmoSe.pozoviMe(200);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ButtonHercClick(TObject *Sender)
{
  igrajmoSe.pozoviMe(300);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ButtonPikClick(TObject *Sender)
{
  igrajmoSe.pozoviMe(400);
}
//---------------------------------------------------------------------------
  // tref 100, kara 200, herc 300, pik 400
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
  igrajmoSe.krajIgre();
}
//---------------------------------------------------------------------------


