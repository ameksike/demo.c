object Form2: TForm2
  Left = 300
  Top = 321
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = '  Sistema de Gesti'#243'n de Proyectos'
  ClientHeight = 255
  ClientWidth = 385
  Color = clBtnFace
  DefaultMonitor = dmDesktop
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ComponenteModulo: TGroupBox
    Left = 0
    Top = -5
    Width = 373
    Height = 262
    TabOrder = 0
    Visible = False
    object GRUP: TGroupBox
      Left = 4
      Top = 140
      Width = 364
      Height = 118
      TabOrder = 0
      object Label4: TLabel
        Left = 13
        Top = 14
        Width = 325
        Height = 19
        Caption = 'Eliminar | Asignale  un Componente a un Modulo'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object GroupBox1: TGroupBox
        Left = 4
        Top = 82
        Width = 355
        Height = 31
        TabOrder = 0
        object Button1: TButton
          Left = 5
          Top = 8
          Width = 75
          Height = 18
          Caption = 'Asignar'
          TabOrder = 0
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 272
          Top = 9
          Width = 75
          Height = 17
          Caption = 'Eliminar'
          TabOrder = 1
          OnClick = Button2Click
        end
      end
      object GroupBox2: TGroupBox
        Left = 4
        Top = 30
        Width = 355
        Height = 55
        TabOrder = 1
        object Label1: TLabel
          Left = 5
          Top = 11
          Width = 89
          Height = 13
          Caption = 'Id del Componente'
        end
        object Label2: TLabel
          Left = 121
          Top = 12
          Width = 71
          Height = 13
          Caption = 'Id del Proyecto'
        end
        object Label3: TLabel
          Left = 238
          Top = 11
          Width = 64
          Height = 13
          Caption = 'Id del Modulo'
        end
        object DBLCBIdComponente: TDBLookupComboBox
          Left = 5
          Top = 26
          Width = 108
          Height = 21
          KeyField = 'IdComponente'
          ListField = 'IdComponente'
          ListSource = DataModuleTablas.DataSComponente
          TabOrder = 0
        end
        object DBLCBIdProyecto: TDBLookupComboBox
          Left = 121
          Top = 26
          Width = 108
          Height = 21
          KeyField = 'IDdeProyecto'
          ListField = 'IDdeProyecto'
          ListSource = DataModuleTablas.DataSProyecto
          TabOrder = 1
        end
        object DBLCBIdModulo: TDBLookupComboBox
          Left = 237
          Top = 26
          Width = 109
          Height = 21
          KeyField = 'IDdeM'#243'dulo'
          ListField = 'IDdeM'#243'dulo'
          ListSource = DataModuleTablas.DataSModulo
          TabOrder = 2
        end
      end
    end
    object GroupBox3: TGroupBox
      Left = 5
      Top = 6
      Width = 363
      Height = 137
      TabOrder = 1
      object DBGrid1: TDBGrid
        Left = 5
        Top = 10
        Width = 351
        Height = 121
        DataSource = DataModuleTablas.DataS_ModuloComponente
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
  end
  object TareaTrabajador: TGroupBox
    Left = 1
    Top = -5
    Width = 384
    Height = 262
    TabOrder = 1
    Visible = False
    object GroupBox5: TGroupBox
      Left = 5
      Top = 139
      Width = 374
      Height = 119
      TabOrder = 0
      object Label11: TLabel
        Left = 18
        Top = 14
        Width = 317
        Height = 19
        Caption = 'Eliminar |  Asignarle una Tarea a un Trabajador'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object GroupBox4: TGroupBox
        Left = 5
        Top = 82
        Width = 364
        Height = 33
        TabOrder = 0
        object Button3: TButton
          Left = 7
          Top = 9
          Width = 75
          Height = 19
          Caption = 'Asignar'
          TabOrder = 0
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 283
          Top = 9
          Width = 75
          Height = 20
          Caption = 'Eliminar'
          TabOrder = 1
          OnClick = Button4Click
        end
      end
      object TGroupBox
        Left = 5
        Top = 30
        Width = 364
        Height = 55
        TabOrder = 1
        object Label8: TLabel
          Left = 6
          Top = 10
          Width = 103
          Height = 13
          Caption = '# de Credencia del T.'
        end
        object Label9: TLabel
          Left = 126
          Top = 10
          Width = 66
          Height = 13
          Caption = 'Id de la Tarea'
        end
        object Label10: TLabel
          Left = 245
          Top = 11
          Width = 89
          Height = 13
          Caption = 'Id del Componente'
        end
        object DBLCBIdTarea: TDBLookupComboBox
          Left = 125
          Top = 26
          Width = 109
          Height = 21
          KeyField = 'IDdeTarea'
          ListField = 'IDdeTarea'
          ListSource = DataModuleTablas.DataSTarea
          TabOrder = 0
        end
        object DBLCBIdComponenteTrabaja: TDBLookupComboBox
          Left = 245
          Top = 26
          Width = 108
          Height = 21
          KeyField = 'IdComponente'
          ListField = 'IdComponente'
          ListSource = DataModuleTablas.DataSComponente
          TabOrder = 1
        end
        object DBLCBCredencial: TDBLookupComboBox
          Left = 8
          Top = 26
          Width = 105
          Height = 21
          KeyField = 'Apellidos'
          ListField = '#Credencial'
          ListSource = DataModuleTablas.DataSPersona
          TabOrder = 2
        end
      end
    end
    object TGroupBox
      Left = 5
      Top = 6
      Width = 373
      Height = 136
      TabOrder = 1
      object DBGrid2: TDBGrid
        Left = 4
        Top = 9
        Width = 362
        Height = 121
        DataSource = DataModuleTablas.DataS_TareaPersona
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
  end
  object ProblemaComponente: TGroupBox
    Left = 1
    Top = -5
    Width = 384
    Height = 262
    TabOrder = 2
    Visible = False
    object GroupBox8: TGroupBox
      Left = 5
      Top = 138
      Width = 374
      Height = 119
      TabOrder = 0
      object Label7: TLabel
        Left = 15
        Top = 15
        Width = 342
        Height = 19
        Caption = 'Eliminar |  Asignarle un Problema a un Componente'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object GroupBox9: TGroupBox
        Left = 5
        Top = 81
        Width = 365
        Height = 33
        TabOrder = 0
        object Button5: TButton
          Left = 7
          Top = 10
          Width = 75
          Height = 19
          Caption = 'Asignar'
          TabOrder = 0
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 282
          Top = 9
          Width = 75
          Height = 19
          Caption = 'Eliminar'
          TabOrder = 1
          OnClick = Button6Click
        end
      end
      object GroupBox7: TGroupBox
        Left = 5
        Top = 32
        Width = 365
        Height = 52
        TabOrder = 1
        object Label5: TLabel
          Left = 5
          Top = 9
          Width = 92
          Height = 13
          Caption = 'Id del Componente '
        end
        object Label6: TLabel
          Left = 214
          Top = 10
          Width = 73
          Height = 13
          Caption = 'Id del Problema'
        end
        object DBLCBIdComponenteProble: TDBLookupComboBox
          Left = 5
          Top = 24
          Width = 144
          Height = 21
          KeyField = 'IdComponente'
          ListField = 'IdComponente'
          ListSource = DataModuleTablas.DataSComponente
          TabOrder = 0
        end
        object DBLCBIdProblema: TDBLookupComboBox
          Left = 212
          Top = 25
          Width = 142
          Height = 21
          KeyField = 'IDdelProblema'
          ListField = 'IDdelProblema'
          ListSource = DataModuleTablas.DataSProblema
          TabOrder = 1
        end
      end
    end
    object GroupBox6: TGroupBox
      Left = 5
      Top = 6
      Width = 372
      Height = 134
      TabOrder = 1
      object DBGrid3: TDBGrid
        Left = 3
        Top = 10
        Width = 363
        Height = 118
        DataSource = DataModuleTablas.DataS_ComponenteProblema
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
  end
end
