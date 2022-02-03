object Form5: TForm5
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'GameTypee'
  ClientHeight = 91
  ClientWidth = 269
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
  object RadioGroup1: TRadioGroup
    Left = 32
    Top = 8
    Width = 185
    Height = 77
    TabOrder = 0
  end
  object RadioButton1: TRadioButton
    Left = 72
    Top = 24
    Width = 113
    Height = 17
    Caption = 'Classic'
    TabOrder = 1
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 72
    Top = 48
    Width = 113
    Height = 17
    Caption = 'Expanded'
    TabOrder = 2
    OnClick = RadioButton2Click
  end
end
