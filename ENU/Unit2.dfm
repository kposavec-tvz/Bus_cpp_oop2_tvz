object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = 'Settings'
  ClientHeight = 151
  ClientWidth = 489
  Color = clBtnFace
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
  object ButtonSpremiPostavke: TButton
    Left = 208
    Top = 112
    Width = 81
    Height = 31
    Caption = 'Save'
    TabOrder = 0
    OnClick = ButtonSpremiPostavkeClick
  end
  object EditImePrezime: TEdit
    Left = 32
    Top = 16
    Width = 185
    Height = 21
    TabOrder = 1
    Text = 'Name Surname'
  end
  object EditUsername: TEdit
    Left = 32
    Top = 43
    Width = 185
    Height = 21
    TabOrder = 2
    Text = 'Username'
  end
  object EditEmail: TEdit
    Left = 32
    Top = 70
    Width = 185
    Height = 21
    TabOrder = 3
    Text = 'EMail'
  end
  object RadioGroupJezik: TRadioGroup
    Left = 285
    Top = 8
    Width = 185
    Height = 83
    Caption = 'Language'
    TabOrder = 4
  end
  object RadioButtonHRV: TRadioButton
    Left = 312
    Top = 32
    Width = 113
    Height = 17
    Caption = 'CROATIAN'
    TabOrder = 5
  end
  object RadioButtonENG: TRadioButton
    Left = 312
    Top = 55
    Width = 113
    Height = 17
    Caption = 'ENGLISH'
    TabOrder = 6
  end
end
