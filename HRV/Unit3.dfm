object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Upravljanje rezultatima'
  ClientHeight = 503
  ClientWidth = 943
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClick = FormClick
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 784
    Top = 16
    Width = 98
    Height = 24
    Caption = '       Opcije'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ListView1: TListView
    Left = 16
    Top = 16
    Width = 753
    Height = 237
    Color = clMoneyGreen
    Columns = <
      item
        Caption = 'ID'
        Width = 150
      end
      item
        Caption = 'Ime Prezime'
        Width = 120
      end
      item
        Caption = 'Username'
        Width = 100
      end
      item
        Caption = 'email'
        Width = 150
      end
      item
        Caption = 'Vrsta igre'
        Width = 60
      end
      item
        Caption = 'Broj bodova'
        Width = 70
      end
      item
        Caption = 'Izvor'
        Width = 53
      end
      item
        Caption = 'Br.'
        Width = 30
      end>
    TabOrder = 0
    ViewStyle = vsReport
  end
  object Button1: TButton
    Left = 775
    Top = 77
    Width = 160
    Height = 25
    Caption = 'Izbri'#353'i odabrani'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 775
    Top = 46
    Width = 160
    Height = 25
    Caption = 'U'#269'itaj rezultate'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 775
    Top = 259
    Width = 160
    Height = 25
    Caption = 'Skini rezultate'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 775
    Top = 322
    Width = 160
    Height = 25
    Caption = 'De'#353'ifriraj online rezultate'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 775
    Top = 290
    Width = 160
    Height = 26
    Caption = 'U'#269'itaj online rezultate'
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 775
    Top = 139
    Width = 160
    Height = 25
    Caption = #352'ifriraj lokalne rezultate'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 775
    Top = 108
    Width = 160
    Height = 25
    Caption = 'Izmjeni rezultat'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Edit1: TEdit
    Left = 775
    Top = 353
    Width = 160
    Height = 21
    TabOrder = 8
    Text = 'Ime datoteke za dekripciju'
  end
  object ListView2: TListView
    Left = 16
    Top = 259
    Width = 753
    Height = 237
    Color = clMoneyGreen
    Columns = <
      item
        Caption = 'ID'
        Width = 150
      end
      item
        Caption = 'Ime Prezime'
        Width = 120
      end
      item
        Caption = 'Username'
        Width = 100
      end
      item
        Caption = 'email'
        Width = 150
      end
      item
        Caption = 'Vrsta igre'
        Width = 60
      end
      item
        Caption = 'Broj bodova'
        Width = 70
      end
      item
        Caption = 'Izvor'
        Width = 53
      end
      item
        Caption = 'Br.'
        Width = 30
      end>
    TabOrder = 9
    ViewStyle = vsReport
  end
  object Lb3DES1: TLb3DES
    CipherMode = cmECB
    Left = 880
    Top = 448
  end
end
