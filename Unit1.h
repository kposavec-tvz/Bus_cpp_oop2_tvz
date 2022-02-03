//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Unit2.h"              // includane postavke
#include "Unit3.h"              // includani rezultati
#include "Unit4.h"              // includana klasicna igra
#include "Unit5.h"
#include <System.Sensors.Components.hpp>
#include <System.Sensors.hpp>              // includani expanded igra
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonPostavke;
	TButton *ButtonRezultati;
	TLabel *Label1;
	TButton *ButtonClassicGame;
	void __fastcall ButtonPostavkeClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ButtonRezultatiClick(TObject *Sender);
	void __fastcall ButtonClassicGameClick(TObject *Sender);
	void __fastcall ButtonExpandedGameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
