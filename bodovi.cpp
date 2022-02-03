
// ******************************************************************************************** //
//                                                                                            
//                                      XML Data Binding                                      
//                                                                                            
//         Generated on: 25-May-21 10:47:05                                                   
//       Generated from: C:\Users\The Popo\Documents\Embarcadero\Studio\Projects\bodovi.xml   
//   Settings stored in: C:\Users\The Popo\Documents\Embarcadero\Studio\Projects\bodovi.xdb   
//                                                                                            
// ******************************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "bodovi.h"


// Global Functions 

_di_IXMLbodoviType __fastcall Getbodovi(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLbodoviType) Doc->GetDocBinding("bodovi", __classid(TXMLbodoviType), TargetNamespace);
};

_di_IXMLbodoviType __fastcall Getbodovi(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getbodovi(DocIntf);
};

_di_IXMLbodoviType __fastcall Loadbodovi(const System::UnicodeString& FileName)
{
  return (_di_IXMLbodoviType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("bodovi", __classid(TXMLbodoviType), TargetNamespace);
};

_di_IXMLbodoviType __fastcall  Newbodovi()
{
  return (_di_IXMLbodoviType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("bodovi", __classid(TXMLbodoviType), TargetNamespace);
};

// TXMLbodoviType 

void __fastcall TXMLbodoviType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("rezultat"), __classid(TXMLrezultatType));
  ItemTag = "rezultat";
  ItemInterface = __uuidof(IXMLrezultatType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLrezultatType __fastcall TXMLbodoviType::Get_rezultat(int Index)
{
  return (_di_IXMLrezultatType) List->Nodes[Index];
};

_di_IXMLrezultatType __fastcall TXMLbodoviType::Add()
{
  return (_di_IXMLrezultatType) AddItem(-1);
};

_di_IXMLrezultatType __fastcall TXMLbodoviType::Insert(const int Index)
{
  return (_di_IXMLrezultatType) AddItem(Index);
};

// TXMLrezultatType 

System::UnicodeString __fastcall TXMLrezultatType::Get_idRezultat()
{
  return GetChildNodes()->Nodes[System::UnicodeString("idRezultat")]->Text;
};

void __fastcall TXMLrezultatType::Set_idRezultat(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("idRezultat")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLrezultatType::Get_ime()
{
  return GetChildNodes()->Nodes[System::UnicodeString("ime")]->Text;
};

void __fastcall TXMLrezultatType::Set_ime(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("ime")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLrezultatType::Get_user()
{
  return GetChildNodes()->Nodes[System::UnicodeString("user")]->Text;
};

void __fastcall TXMLrezultatType::Set_user(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("user")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLrezultatType::Get_email()
{
  return GetChildNodes()->Nodes[System::UnicodeString("email")]->Text;
};

void __fastcall TXMLrezultatType::Set_email(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("email")]->NodeValue = Value;
};

int __fastcall TXMLrezultatType::Get_igraVrsta()
{
  return GetChildNodes()->Nodes[System::UnicodeString("igraVrsta")]->NodeValue.operator int();
};

void __fastcall TXMLrezultatType::Set_igraVrsta(int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("igraVrsta")]->NodeValue = Value;
};

int __fastcall TXMLrezultatType::Get_brojBodova()
{
  return GetChildNodes()->Nodes[System::UnicodeString("brojBodova")]->NodeValue.operator int();
};

void __fastcall TXMLrezultatType::Set_brojBodova(int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("brojBodova")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLrezultatType::Get_sakriven()
{
  return GetChildNodes()->Nodes[System::UnicodeString("sakriven")]->Text;
};

void __fastcall TXMLrezultatType::Set_sakriven(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("sakriven")]->NodeValue = Value;
};

// TXMLrezultatTypeList 

_di_IXMLrezultatType __fastcall TXMLrezultatTypeList::Add()
{
  return (_di_IXMLrezultatType) AddItem(-1);
};

_di_IXMLrezultatType __fastcall TXMLrezultatTypeList::Insert(const int Index)
{
  return (_di_IXMLrezultatType) AddItem(Index);
};

_di_IXMLrezultatType __fastcall TXMLrezultatTypeList::Get_Item(int Index)
{
  return (_di_IXMLrezultatType) List->Nodes[Index];
};
