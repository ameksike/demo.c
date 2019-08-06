object FormRegistro: TFormRegistro
  Left = 406
  Top = 317
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = ' Registro'
  ClientHeight = 83
  ClientWidth = 187
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = -5
    Width = 188
    Height = 89
    TabOrder = 0
    object GroupBox2: TGroupBox
      Left = 2
      Top = 1
      Width = 183
      Height = 85
      TabOrder = 0
      object Label1: TLabel
        Left = 8
        Top = 8
        Width = 36
        Height = 13
        Caption = 'Usuario'
      end
      object Label2: TLabel
        Left = 8
        Top = 44
        Width = 54
        Height = 13
        Caption = 'Contrase'#241'a'
      end
      object EditUsuario: TEdit
        Left = 8
        Top = 22
        Width = 163
        Height = 21
        TabOrder = 0
        OnKeyDown = EditUsuarioKeyDown
      end
      object MaskEditPass: TMaskEdit
        Left = 7
        Top = 58
        Width = 162
        Height = 21
        PasswordChar = '*'
        TabOrder = 1
        OnKeyDown = MaskEditPassKeyDown
      end
    end
  end
end
