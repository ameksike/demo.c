object Form5: TForm5
  Left = 299
  Top = 321
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = '  Sistema de Gesti'#243'n de Proyectos'
  ClientHeight = 163
  ClientWidth = 437
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ListaProblemasComponentes: TGroupBox
    Left = 0
    Top = -5
    Width = 439
    Height = 168
    TabOrder = 0
    Visible = False
    object Label4: TLabel
      Left = 64
      Top = 8
      Width = 293
      Height = 19
      Caption = 'Listado de Problemas por cada Componente'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GroupBox5: TGroupBox
      Left = 5
      Top = 26
      Width = 256
      Height = 138
      TabOrder = 0
      object DBGrid2: TDBGrid
        Left = 4
        Top = 9
        Width = 246
        Height = 123
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object GroupBox6: TGroupBox
      Left = 263
      Top = 26
      Width = 172
      Height = 138
      TabOrder = 1
      object Label5: TLabel
        Left = 7
        Top = 24
        Width = 136
        Height = 13
        Caption = 'Seleccione  el  Componente '
      end
      object DBLookupComboBox1: TDBLookupComboBox
        Left = 7
        Top = 42
        Width = 158
        Height = 21
        KeyField = 'IdComponente'
        ListField = 'IdComponente'
        ListSource = DataModuleTablas.DataSComponente
        TabOrder = 0
        OnClick = DBLookupComboBox1Click
      end
    end
  end
  object IstadoTrabajadoresComponentes: TGroupBox
    Left = -3
    Top = -5
    Width = 442
    Height = 168
    TabOrder = 1
    Visible = False
    object Label7: TLabel
      Left = 64
      Top = 8
      Width = 312
      Height = 19
      Caption = 'Listado de Trabajadores por cada Componente'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GroupBox4: TGroupBox
      Left = 261
      Top = 27
      Width = 177
      Height = 137
      TabOrder = 0
      object Label6: TLabel
        Left = 7
        Top = 24
        Width = 133
        Height = 13
        Caption = 'Seleccione  el  Componente'
      end
      object DBLookupComboBox3: TDBLookupComboBox
        Left = 6
        Top = 41
        Width = 163
        Height = 21
        KeyField = 'IdComponente'
        ListField = 'IdComponente'
        ListSource = DataModuleTablas.DataSComponente
        TabOrder = 0
        OnClick = DBLookupComboBox3Click
      end
    end
    object GroupBox1: TGroupBox
      Left = 5
      Top = 27
      Width = 256
      Height = 137
      TabOrder = 1
      object DBGrid3: TDBGrid
        Left = 4
        Top = 9
        Width = 246
        Height = 123
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
  end
  object IncumplimientosComponentes: TGroupBox
    Left = 0
    Top = -6
    Width = 438
    Height = 170
    TabOrder = 2
    Visible = False
    object Label8: TLabel
      Left = 43
      Top = 8
      Width = 356
      Height = 19
      Caption = 'Listado de Tareas incumplidas  por cada Componente'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GroupBox8: TGroupBox
      Left = 3
      Top = 25
      Width = 255
      Height = 141
      TabOrder = 0
      object StringGrid1: TStringGrid
        Left = 4
        Top = 9
        Width = 244
        Height = 127
        ColCount = 2
        RowCount = 3
        TabOrder = 0
        ColWidths = (
          8
          231)
      end
    end
    object GroupBox9: TGroupBox
      Left = 259
      Top = 25
      Width = 175
      Height = 141
      TabOrder = 1
      object Label9: TLabel
        Left = 7
        Top = 24
        Width = 133
        Height = 13
        Caption = 'Seleccione  el  Componente'
      end
      object DBLookupComboBox4: TDBLookupComboBox
        Left = 7
        Top = 41
        Width = 160
        Height = 21
        KeyField = 'IdComponente'
        ListField = 'IdComponente'
        ListSource = DataModuleTablas.DataS_Listado_de_ComponentesT
        TabOrder = 0
        OnClick = DBLookupComboBox4Click
      end
    end
  end
  object ListadoTareas: TGroupBox
    Left = -1
    Top = -5
    Width = 438
    Height = 169
    TabOrder = 3
    Visible = False
    object Label3: TLabel
      Left = 80
      Top = 7
      Width = 266
      Height = 19
      Caption = 'Listado de Trareas por cada Trabajador'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GroupBox2: TGroupBox
      Left = 5
      Top = 25
      Width = 255
      Height = 140
      TabOrder = 0
      object DBGrid1: TDBGrid
        Left = 4
        Top = 9
        Width = 245
        Height = 125
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object GroupBox3: TGroupBox
      Left = 262
      Top = 25
      Width = 171
      Height = 140
      TabOrder = 1
      object Label2: TLabel
        Left = 6
        Top = 60
        Width = 118
        Height = 13
        Caption = 'Seleccione el Trabajador'
      end
      object Label1: TLabel
        Left = 5
        Top = 12
        Width = 157
        Height = 13
        Caption = 'Seleccione el Estado de la Traea'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object GroupBox7: TGroupBox
        Left = 2
        Top = 104
        Width = 165
        Height = 33
        TabOrder = 0
        object Button1: TButton
          Left = 40
          Top = 10
          Width = 75
          Height = 18
          Caption = 'Mostrar'
          TabOrder = 0
          OnClick = Button1Click
        end
      end
      object DBLookupComboBox2: TDBLookupComboBox
        Left = 6
        Top = 76
        Width = 159
        Height = 21
        KeyField = 'Apellidos'
        ListField = '#Credencial'
        ListSource = DataModuleTablas.DataSPersona
        TabOrder = 1
      end
      object ComboBox1: TComboBox
        Left = 6
        Top = 28
        Width = 158
        Height = 21
        ItemHeight = 13
        TabOrder = 2
        OnChange = ComboBox1Change
        Items.Strings = (
          'Pendiente'
          'Terminada')
      end
    end
  end
end
