object FormConectar: TFormConectar
  Left = 405
  Top = 317
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = ' Conectar a ...'
  ClientHeight = 86
  ClientWidth = 228
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = -5
    Width = 229
    Height = 93
    TabOrder = 0
    object GroupBox2: TGroupBox
      Left = 2
      Top = 1
      Width = 224
      Height = 89
      TabOrder = 0
      object Label1: TLabel
        Left = 7
        Top = 8
        Width = 39
        Height = 13
        Caption = 'Servidor'
      end
      object Label2: TLabel
        Left = 8
        Top = 47
        Width = 65
        Height = 13
        Caption = 'Base de Dato'
      end
      object EditServidor: TEdit
        Left = 8
        Top = 23
        Width = 208
        Height = 21
        TabOrder = 0
        OnKeyDown = EditServidorKeyDown
      end
      object EditDB: TEdit
        Left = 8
        Top = 62
        Width = 208
        Height = 21
        TabOrder = 1
        OnKeyDown = EditDBKeyDown
      end
    end
  end
end
