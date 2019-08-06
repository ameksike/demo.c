------  Estructura del AIS --------------------------------------------------------------

--Trama--

AIS;255802360;9137820;JUMMETOR;21356500;084430800;21/09/2010 19:37:32;0;CQPO;70;1;108;16;23/09 01:00;4;TAMPA;13;0;292;296;5;


--Desglose--

------------------------Nom_Sensor----------------------------------------------------------
posici�n 0=  sensor (AIS)	VARCHAR(60)   			(Nomenclador de sensores y nomenclador de tipo sensores)
INSERT INTO mod_siren.nom_sensor ("nombre", "idtiposensor")
VALUES ('Sensor', 1);
----------------------------------------------------------------------------------------

--------------------------dat_Embarcaci�n---------------------------------------------------
posici�n 1=  MMSI						(TABLA EMBARCACI�N) VARCHAR(100)
posici�n 2=  OMI						(TABLA EMBARCACI�N) VARCHAR(100)
posici�n 3=  nombre del barco			(TABLA EMBARCACI�N) TEXT
posici�n 11= eslora						(TABLA EMBARCACI�N) VARCHAR(20)
posici�n 12= manga						(TABLA EMBARCACI�N) VARCHAR(20)

posici�n 8=  Dispositivo de llamada		(TABLA EMBARCACI�N) VARCHAR(200)
posici�n 9=  Tipo barco					(TABLA EMBARCACI�N) VARCHAR(100)
posici�n 10= Tipo sensor naval			(TABLA EMBARCACI�N) VARCHAR(100)
posici�n 14= calado						(TABLA EMBARCACI�N) TEXT
posici�n 20= estaci�n AIS 				(TABLA EMBARCACI�N) VARCHAR(20)

$idsensor = SELECT s.idsensor from mod_siren.nom_sensor s where s.nombre = 'Tipo sensor naval';
$idtipoembarcacion = SELECT e.idtipoembarcacion from mod_siren.nom_tipoembarcacion e where e.denominacion = 'Tipo barco';
INSERT INTO "mod_siren"."dat_embarcacion" ("nombre", "idtipoembarcacion", "calado", "distllamada", "eslora", "estacionais", "manga", "mmsi", "omi", "idsensor", "imagen")
VALUES ('nombre del barco', $idtipoembarcacion, 'calado', 'Dispositivo de llamada', 'eslora', 'estaci�n AIS ', 'manga', 'MMSI', 'OMI', $idsensor, 'Imagen null');
----------------------------------------------------------------------------------------------------

---------------------Localizaci�n embarcaci�n-------------------------------------------------------

posici�n 16= velocidad			        (TABLA LOCALIZACI�N Embarcacion) DOUBLE PRECISION
posici�n 18= rumbo						(TABLA LOCALIZACI�N Embarcacion) INTEGER
posici�n 19= cabeceo					(TABLA LOCALIZACI�N Embarcacion) VARCHAR(20)
posici�n 17= presici�n de la posici�n 	(TABLA LOCALIZACI�N Embarcacion) INTEGER
posici�n 7=  situaci�n de navegaci�n	(TABLA LOCALIZACI�N Embarcacion) TEXT
posici�n 6=  Fecha y Hora			    (TABLA LOCALIZACI�N Embarcacion) Timestamp(6)

$idembarcacion = SELECT e.idembarcacion from mod_siren.dat_embarcacion e WHERE e.mmsi = 'MMSI';
$idlocalizacion = Select l.idlocalizacion from mod_siren.dat_localizacion l Whre l.the_geom = 'geometria(latitud, longitud)';
$idsituacionnavegacion = Select s.idsituacionnavegacion from mod_siren.nom_situacionnavegacion s Where s.situacion = 'situaci�n de navegaci�n';

INSERT INTO "mod_siren"."dat_localizacionembarcacion" ("idembarcacion", "idlocalizacion", "velocidad", "cabeceo", "rumbo", "precisionnavegacion", "idsituacionnavegacion", "fecha")
VALUES ( $idembarcacion, $idlocalizacion, 'velocidad', 'cabeceo','rumbo', 'presici�n de la posici�n',$idsituacionnavegacion,'Fecha y Hora');
---------------------------------------------------------------------------------------------

-----------------------------------Localizacion----------------------------------------------
posici�n 4=  Longitud				(TABLA LOCALIZACI�N) DOUBLE PRECISION
posici�n 5=  Latitud				(TABLA LOCALIZACI�N) DOUBLE PRECISION

$the_geom = geometryfromtext('POINT('' ||latitud || '' ||longitud');  GEOMETRY

INSERT INTO "mod_siren"."dat_localizacion" ("the_geom")
VALUES ($the_geom);

------------------------------------------------------------------------------------------------

----------------------Tipo de embarcacion-------------------------------------------------------
Codigo = primeros 3 numeros del mmsi que es el 1 VARCHAR(3)
Descripcion = Text
denominacion = posici�n 9=  Tipo barco  (TABLA EMBARCACI�N) VARCHAR(100)
INSERT INTO "mod_siren"."nom_tipoembarcacion" ("codigo","descripcion","denominacion")
VALUES ('codigo','descripcion','denominacion');
------------------------------------------------------------------------------------------------

------------------------Puertos-----------------------------------------------------------------
$idlocalizacion = Select l.idlocalizacion from mod_siren.dat_localizacion l Whre l.the_geom = 'geometryfromtext('POINT('' ||latitud || '' ||longitud')';
INSERT INTO "mod_siren"."dat_puertos" ("denominacion","calado","iddpa", "imagen", "idlocalizacion")
VALUES ('denominacion','calado',$iddpa,'imagen',$idlocalizacion);
------------------------------------------------------------------------------------------------

-----------------------Puerto destino-----------------------------------------------------------
posici�n 13= ETA (momento de llegada)	 (TABLA Puerto Destino)  Timestamp(6)

$idpuertodestino = Select p.idpuerto from mod_siren.dat_puerto p Where p.nombre = 'Puerto';
INSERT INTO "mod_siren"."dat_puertodestino" ("idpuertodestino","eta")
VALUES ($idpuertodestino,'ETA');
------------------------------------------------------------------------------------------------




