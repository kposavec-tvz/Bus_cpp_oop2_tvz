object Form7: TForm7
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = 'Online'
  ClientHeight = 219
  ClientWidth = 351
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 34
    Height = 13
    Caption = 'Adress'
  end
  object Label2: TLabel
    Left = 144
    Top = 182
    Width = 9
    Height = 19
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 8
    Top = 27
    Width = 313
    Height = 21
    TabOrder = 0
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 54
    Width = 185
    Height = 115
    Caption = 'Speed limiter'
    TabOrder = 1
  end
  object RadioButton1: TRadioButton
    Left = 40
    Top = 72
    Width = 113
    Height = 17
    Caption = '0,5 KB/s'
    TabOrder = 2
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 40
    Top = 95
    Width = 113
    Height = 17
    Caption = '1 KB/s'
    TabOrder = 3
    OnClick = RadioButton2Click
  end
  object RadioButton3: TRadioButton
    Left = 40
    Top = 118
    Width = 113
    Height = 17
    Caption = '2 KB/s'
    TabOrder = 4
    OnClick = RadioButton3Click
  end
  object CheckBox1: TCheckBox
    Left = 40
    Top = 141
    Width = 97
    Height = 17
    Caption = 'Limit speed'
    TabOrder = 5
    OnClick = CheckBox1Click
  end
  object Button1: TButton
    Left = 208
    Top = 54
    Width = 113
    Height = 115
    Caption = 'Begin download'
    TabOrder = 6
    OnClick = Button1Click
  end
  object IdHTTP1: TIdHTTP
    Intercept = IdInterceptThrottler1
    OnWork = IdHTTP1Work
    OnWorkBegin = IdHTTP1WorkBegin
    OnWorkEnd = IdHTTP1WorkEnd
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 240
    Top = 176
  end
  object IdInterceptThrottler1: TIdInterceptThrottler
    BitsPerSec = 0
    RecvBitsPerSec = 0
    SendBitsPerSec = 0
    Left = 280
    Top = 176
  end
end
