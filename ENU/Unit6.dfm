object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Edit'
  ClientHeight = 177
  ClientWidth = 386
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 304
    Top = 152
    Width = 3
    Height = 13
  end
  object Button1: TButton
    Left = 152
    Top = 144
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 24
    Top = 40
    Width = 321
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 24
    Top = 80
    Width = 321
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 24
    Top = 117
    Width = 321
    Height = 21
    TabOrder = 3
    Text = 'Edit3'
  end
end
