//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

    //deklariram stvari za postavke

extern int jezik;
//std::string PlayerIme,PlayerUsername,PlayerMail;
extern UnicodeString PlayerIme,PlayerUsername,PlayerMail,JezikString;

class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonSpremiPostavke;
	TEdit *EditImePrezime;
	TEdit *EditUsername;
	TEdit *EditEmail;
	TRadioGroup *RadioGroupJezik;
	TRadioButton *RadioButtonHRV;
	TRadioButton *RadioButtonENG;
	void __fastcall ButtonSpremiPostavkeClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	//void __fastcall EditImePrezimeChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
