
// ******************************************************************************************** //
//                                                                                            
//                                      XML Data Binding                                      
//                                                                                            
//         Generated on: 25-May-21 10:47:05                                                   
//       Generated from: C:\Users\The Popo\Documents\Embarcadero\Studio\Projects\bodovi.xml   
//   Settings stored in: C:\Users\The Popo\Documents\Embarcadero\Studio\Projects\bodovi.xdb   
//                                                                                            
// ******************************************************************************************** //

#ifndef   bodoviH
#define   bodoviH

#include <System.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLbodoviType;
typedef System::DelphiInterface<IXMLbodoviType> _di_IXMLbodoviType;
__interface IXMLrezultatType;
typedef System::DelphiInterface<IXMLrezultatType> _di_IXMLrezultatType;
__interface IXMLrezultatTypeList;
typedef System::DelphiInterface<IXMLrezultatTypeList> _di_IXMLrezultatTypeList;

// IXMLbodoviType 

__interface INTERFACE_UUID("{67378F0E-504A-434A-A7B3-0CD377AA7C7D}") IXMLbodoviType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLrezultatType __fastcall Get_rezultat(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLrezultatType __fastcall Add() = 0;
  virtual _di_IXMLrezultatType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLrezultatType rezultat[int Index] = { read=Get_rezultat };/* default */
};

// IXMLrezultatType 

__interface INTERFACE_UUID("{9F11CBE6-FAD4-4765-B8D3-EA6FE3D16964}") IXMLrezultatType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_idRezultat() = 0;
  virtual System::UnicodeString __fastcall Get_ime() = 0;
  virtual System::UnicodeString __fastcall Get_user() = 0;
  virtual System::UnicodeString __fastcall Get_email() = 0;
  virtual int __fastcall Get_igraVrsta() = 0;
  virtual int __fastcall Get_brojBodova() = 0;
  virtual System::UnicodeString __fastcall Get_sakriven() = 0;
  virtual void __fastcall Set_idRezultat(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_ime(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_user(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_email(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_igraVrsta(int Value) = 0;
  virtual void __fastcall Set_brojBodova(int Value) = 0;
  virtual void __fastcall Set_sakriven(System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString idRezultat = { read=Get_idRezultat, write=Set_idRezultat };
  __property System::UnicodeString ime = { read=Get_ime, write=Set_ime };
  __property System::UnicodeString user = { read=Get_user, write=Set_user };
  __property System::UnicodeString email = { read=Get_email, write=Set_email };
  __property int igraVrsta = { read=Get_igraVrsta, write=Set_igraVrsta };
  __property int brojBodova = { read=Get_brojBodova, write=Set_brojBodova };
  __property System::UnicodeString sakriven = { read=Get_sakriven, write=Set_sakriven };
};

// IXMLrezultatTypeList 

__interface INTERFACE_UUID("{B1C4BA16-5E77-4323-9C54-AFFA4BCE6FAE}") IXMLrezultatTypeList : public Xml::Xmlintf::IXMLNodeCollection
{
public:
  // Methods & Properties 
  virtual _di_IXMLrezultatType __fastcall Add() = 0;
  virtual _di_IXMLrezultatType __fastcall Insert(const int Index) = 0;

  virtual _di_IXMLrezultatType __fastcall Get_Item(int Index) = 0;
  __property _di_IXMLrezultatType Items[int Index] = { read=Get_Item /* default */ };
};

// Forward Decls 

class TXMLbodoviType;
class TXMLrezultatType;
class TXMLrezultatTypeList;

// TXMLbodoviType 

class TXMLbodoviType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLbodoviType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLbodoviType 
  virtual _di_IXMLrezultatType __fastcall Get_rezultat(int Index);
  virtual _di_IXMLrezultatType __fastcall Add();
  virtual _di_IXMLrezultatType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLrezultatType 

class TXMLrezultatType : public Xml::Xmldoc::TXMLNode, public IXMLrezultatType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLrezultatType 
  virtual System::UnicodeString __fastcall Get_idRezultat();
  virtual System::UnicodeString __fastcall Get_ime();
  virtual System::UnicodeString __fastcall Get_user();
  virtual System::UnicodeString __fastcall Get_email();
  virtual int __fastcall Get_igraVrsta();
  virtual int __fastcall Get_brojBodova();
  virtual System::UnicodeString __fastcall Get_sakriven();
  virtual void __fastcall Set_idRezultat(System::UnicodeString Value);
  virtual void __fastcall Set_ime(System::UnicodeString Value);
  virtual void __fastcall Set_user(System::UnicodeString Value);
  virtual void __fastcall Set_email(System::UnicodeString Value);
  virtual void __fastcall Set_igraVrsta(int Value);
  virtual void __fastcall Set_brojBodova(int Value);
  virtual void __fastcall Set_sakriven(System::UnicodeString Value);
};

// TXMLrezultatTypeList 

class TXMLrezultatTypeList : public Xml::Xmldoc::TXMLNodeCollection, public IXMLrezultatTypeList
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLrezultatTypeList 
  virtual _di_IXMLrezultatType __fastcall Add();
  virtual _di_IXMLrezultatType __fastcall Insert(const int Index);

  virtual _di_IXMLrezultatType __fastcall Get_Item(int Index);
};

// Global Functions 

_di_IXMLbodoviType __fastcall Getbodovi(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLbodoviType __fastcall Getbodovi(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLbodoviType __fastcall Loadbodovi(const System::UnicodeString& FileName);
_di_IXMLbodoviType __fastcall  Newbodovi();

#define TargetNamespace ""

#endif