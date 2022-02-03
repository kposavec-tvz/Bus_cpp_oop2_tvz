object Form4: TForm4
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  BorderWidth = 1
  Caption = 'BUS'
  ClientHeight = 372
  ClientWidth = 847
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 72
    Top = 104
    Width = 81
    Height = 105
  end
  object Image2: TImage
    Left = 224
    Top = 104
    Width = 81
    Height = 105
  end
  object Image3: TImage
    Left = 368
    Top = 104
    Width = 81
    Height = 105
  end
  object Image4: TImage
    Left = 504
    Top = 104
    Width = 89
    Height = 105
  end
  object Image5: TImage
    Left = 648
    Top = 104
    Width = 81
    Height = 105
  end
  object Label1: TLabel
    Left = 72
    Top = 74
    Width = 6
    Height = 24
    Caption = ' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 224
    Top = 74
    Width = 6
    Height = 24
    Caption = ' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 368
    Top = 74
    Width = 6
    Height = 24
    Caption = ' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 504
    Top = 74
    Width = 6
    Height = 24
    Caption = ' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 648
    Top = 74
    Width = 6
    Height = 24
    Caption = ' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 192
    Top = 272
    Width = 35
    Height = 13
    Caption = 'position'
    Visible = False
  end
  object Label7: TLabel
    Left = 240
    Top = 272
    Width = 3
    Height = 13
    Caption = ' '
    Visible = False
  end
  object Label8: TLabel
    Left = 191
    Top = 291
    Width = 36
    Height = 13
    Caption = 'Card#'
  end
  object Label9: TLabel
    Left = 240
    Top = 291
    Width = 3
    Height = 13
    Caption = ' '
  end
  object Label10: TLabel
    Left = 162
    Top = 310
    Width = 65
    Height = 13
    Caption = 'upcoming cards'
  end
  object Label11: TLabel
    Left = 240
    Top = 310
    Width = 3
    Height = 13
    Caption = ' '
  end
  object Label12: TLabel
    Left = 84
    Top = 55
    Width = 3
    Height = 13
    Caption = ' '
  end
  object Label13: TLabel
    Left = 234
    Top = 55
    Width = 3
    Height = 13
    Caption = ' '
  end
  object Label14: TLabel
    Left = 380
    Top = 55
    Width = 3
    Height = 13
    Caption = ' '
  end
  object Label15: TLabel
    Left = 528
    Top = 55
    Width = 3
    Height = 13
    Caption = ' '
  end
  object Label16: TLabel
    Left = 660
    Top = 55
    Width = 3
    Height = 13
    Caption = ' '
  end
  object Label17: TLabel
    Left = 525
    Top = 320
    Width = 48
    Height = 19
    Caption = 'Score'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label18: TLabel
    Left = 602
    Top = 315
    Width = 61
    Height = 25
    Caption = 'Score'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label19: TLabel
    AlignWithMargins = True
    Left = 72
    Top = 16
    Width = 92
    Height = 33
    Alignment = taCenter
    Caption = ' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 72
    Top = 215
    Width = 25
    Height = 25
    Caption = 'v'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 96
    Top = 215
    Width = 25
    Height = 25
    Caption = '='
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 120
    Top = 215
    Width = 25
    Height = 25
    Caption = '^'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 224
    Top = 215
    Width = 25
    Height = 25
    Caption = 'v'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 248
    Top = 215
    Width = 25
    Height = 25
    Caption = '='
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 272
    Top = 215
    Width = 25
    Height = 25
    Caption = '^'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button10: TButton
    Left = 504
    Top = 215
    Width = 25
    Height = 25
    Caption = 'v'
    TabOrder = 6
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 528
    Top = 215
    Width = 25
    Height = 25
    Caption = '='
    TabOrder = 7
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 552
    Top = 215
    Width = 25
    Height = 25
    Caption = '^'
    TabOrder = 8
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 648
    Top = 215
    Width = 25
    Height = 25
    Caption = 'v'
    TabOrder = 9
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 672
    Top = 215
    Width = 25
    Height = 25
    Caption = '='
    TabOrder = 10
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 696
    Top = 215
    Width = 25
    Height = 25
    Caption = '^'
    TabOrder = 11
    OnClick = Button15Click
  end
  object ButtonTref: TButton
    Left = 360
    Top = 215
    Width = 50
    Height = 33
    Caption = 'Clubs'
    TabOrder = 12
    OnClick = ButtonTrefClick
  end
  object ButtonKara: TButton
    Left = 408
    Top = 215
    Width = 49
    Height = 33
    Caption = 'Diamond'
    TabOrder = 13
    OnClick = ButtonKaraClick
  end
  object ButtonPik: TButton
    Left = 408
    Top = 254
    Width = 49
    Height = 33
    Caption = 'Spades'
    TabOrder = 14
    OnClick = ButtonPikClick
  end
  object ButtonHerc: TButton
    Left = 360
    Top = 254
    Width = 50
    Height = 33
    Caption = 'Hearts'
    TabOrder = 15
    OnClick = ButtonHercClick
  end
  object XMLDocument1: TXMLDocument
    Active = True
    FileName = 
      'C:\Users\The Popo\Documents\Embarcadero\Studio\Projects\bodovi.x' +
      'ml'
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl]
    Left = 776
    Top = 304
  end
  object XMLDocument2: TXMLDocument
    FileName = 
      'C:\Users\The Popo\Documents\Embarcadero\Studio\Projects\Win32\De' +
      'bug\_bodovi.xml'
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl]
    Left = 704
    Top = 304
  end
end
