object DataModuleTablas: TDataModuleTablas
  OldCreateOrder = False
  Left = 240
  Top = 102
  Height = 632
  Width = 762
  object ADOConnection1: TADOConnection
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 326
    Top = 1
  end
  object DataSProyecto: TDataSource
    DataSet = ADOTProyecto
    Left = 41
    Top = 94
  end
  object DataSPersona: TDataSource
    DataSet = ADOTPersona
    Left = 137
    Top = 94
  end
  object DataSModulo: TDataSource
    DataSet = ADOTModulo
    Left = 235
    Top = 94
  end
  object DataSTarea: TDataSource
    DataSet = ADOTTarea
    Left = 326
    Top = 94
  end
  object DataSComponente: TDataSource
    DataSet = ADOTComponente
    Left = 437
    Top = 94
  end
  object DataSProblema: TDataSource
    DataSet = ADOTProblema
    Left = 550
    Top = 94
  end
  object ADOTProyecto: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'PROYECTO'
    Left = 41
    Top = 46
  end
  object ADOTPersona: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'PERSONA'
    Left = 136
    Top = 46
  end
  object ADOTModulo: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'MODULO'
    Left = 233
    Top = 46
  end
  object ADOTTarea: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'TAREA'
    Left = 326
    Top = 46
  end
  object ADOTComponente: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Componente'
    Left = 435
    Top = 48
  end
  object ADOTProblema: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Problema'
    Left = 549
    Top = 49
  end
  object ADOTSeguridad: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Seguridad'
    Left = 654
    Top = 48
  end
  object DataSSeguridad: TDataSource
    DataSet = ADOTSeguridad
    Left = 656
    Top = 96
  end
  object ADOSP_Proyecto: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_PROYECTO_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeProyecto_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@Nombre_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@PersonaResponsable_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@Facultad_4'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = 0
      end
      item
        Name = '@FechadeInicio_5'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@Objetivo_6'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end>
    Left = 40
    Top = 140
  end
  object ADOSP_Persona: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_PERSONA_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@#Credencial_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@Nombre_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@Apellidos_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 20
        Value = '0'
      end
      item
        Name = '@Sexo_4'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@CI_5'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@CorreoElectronico_6'
        Attributes = [paNullable]
        DataType = ftString
        Size = 30
        Value = '0'
      end
      item
        Name = '@Categoria_7'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@IDdeProyecto_8'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@FechadeInicioenProyecto_9'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 134
    Top = 140
  end
  object ADOSP_Modulo: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_MODULO_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeM'#243'dulo_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@IDdeProyecto_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@PersonaResponsable_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@Nombre_4'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@Objetivo_5'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@FechadeInicio_6'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end>
    Left = 236
    Top = 141
  end
  object ADOSP_Tarea: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_TAREA_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeTarea_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@IdComponente_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@Objetivo_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@Estado_4'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@FechadeInicio_5'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@FechadeTerminada_6'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@FechadeEntrega_7'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 326
    Top = 142
  end
  object ADOSP_Componente: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_Componente_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IdComponente_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@PersonaResponsable_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@Nombre_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 20
        Value = '0'
      end
      item
        Name = '@Version_4'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@FechadeInicio_5'
        Attributes = [paNullable]
        DataType = ftString
        Size = 20
        Value = '0'
      end>
    Left = 437
    Top = 142
  end
  object ADOSP_Problema: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_Problema_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdelProblema_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@DescripciondelP_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end>
    Left = 553
    Top = 142
  end
  object ADOSP_Seguridad: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_Seguridad_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@Usuario_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 20
        Value = '0'
      end
      item
        Name = '@Contrase'#241'a_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 20
        Value = '0'
      end>
    Left = 658
    Top = 143
  end
  object ADOSP_EProyecto: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_PROYECTO_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeProyecto_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 40
    Top = 193
  end
  object ADOSP_EPersona: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_PERSONA_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@#Credencial_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 136
    Top = 194
  end
  object ADOSP_EModulo: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_MODULO_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeM'#243'dulo_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@IDdeProyecto_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 238
    Top = 193
  end
  object ADOSP_ETarea: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_TAREA_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeTarea_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@IdComponente_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 330
    Top = 193
  end
  object ADOSP_EComponente: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_Componente_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IdComponente_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 438
    Top = 193
  end
  object ADOSP_EProblema: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_Problema_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdelProblema_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 554
    Top = 193
  end
  object ADOSP_ESeguridad: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_Seguridad_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@Usuario_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 661
    Top = 193
  end
  object ADOSPExisteUsuario: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'Existe_Usuario;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@User'
        Attributes = [paNullable]
        DataType = ftString
        Size = 20
        Value = '0'
      end>
    Left = 96
    Top = 260
  end
  object ADOSP_ITareaPersona: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_TAREAPERSONA_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeTarea_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@#Credencial_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@IdComponente_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end>
    Left = 317
    Top = 259
  end
  object ADOSP_ETareaPersona: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_TAREAPERSONA_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeTarea_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@#Credencial_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@IdComponente_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 317
    Top = 307
  end
  object ADOSP_IModuloComponente: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_MODULOComponente_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeM'#243'dulo_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@IDdeProyecto_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@IdComponente_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end>
    Left = 473
    Top = 258
  end
  object ADOSP_EModuloComponente: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_MODULOComponente_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IDdeM'#243'dulo_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@IDdeProyecto_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@IdComponente_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 473
    Top = 306
  end
  object ADOSP_IComponenteProblema: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'insert_ComponenteProblema_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IdComponente_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end
      item
        Name = '@IDdelProblema_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end>
    Left = 645
    Top = 256
  end
  object ADOSP_EComponenteProblema: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'delete_ComponenteProblema_1;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IdComponente_1'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end
      item
        Name = '@IDdelProblema_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 645
    Top = 307
  end
  object ADOT_TareaPersona: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'TAREAPERSONA'
    Left = 316
    Top = 357
  end
  object ADOT_ModuloComponente: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'MODULOComponente'
    Left = 476
    Top = 357
  end
  object ADOT_ComponenteProblema: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'ComponenteProblema'
    Left = 648
    Top = 357
  end
  object DataS_TareaPersona: TDataSource
    DataSet = ADOT_TareaPersona
    Left = 316
    Top = 408
  end
  object DataS_ModuloComponente: TDataSource
    DataSet = ADOT_ModuloComponente
    Left = 476
    Top = 408
  end
  object DataS_ComponenteProblema: TDataSource
    DataSet = ADOT_ComponenteProblema
    Left = 649
    Top = 407
  end
  object ADOSP_TareasPTrabajador: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'Tareas_Pendientes_por_Persona;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@nombre'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = '0'
      end>
    Left = 96
    Top = 308
  end
  object ADOSP_TareasTTrabajador: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'Tareas_Terminadas_por_Persona;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@nombre'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 97
    Top = 357
  end
  object ADOSP_ErroresComponente: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'Listado_de_Problemas_por_Componente;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IdComponente'
        Attributes = [paNullable]
        DataType = ftString
        Size = 10
        Value = Null
      end>
    Left = 95
    Top = 428
  end
  object ADOSP_PersonasComponente: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'Listado_de_Trabajadores_por_Componente;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IdComponente'
        Attributes = [paNullable]
        DataType = ftString
        Size = 16
        Value = '0'
      end>
    Left = 96
    Top = 477
  end
  object ADOSP_IncumplimientoComponente: TADOStoredProc
    Connection = ADOConnection1
    ProcedureName = 'Listado_Fechas_and_IdTareas_por_cada_IdComponente;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@IdComponente'
        Attributes = [paNullable]
        DataType = ftString
        Size = 10
        Value = Null
      end>
    Left = 96
    Top = 525
  end
  object ADOT_Listado_de_ComponentesT: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Listado_de_IdComponentes_con_Tareas'
    Left = 312
    Top = 483
  end
  object DataS_Listado_de_ComponentesT: TDataSource
    DataSet = ADOT_Listado_de_ComponentesT
    Left = 312
    Top = 539
  end
end
