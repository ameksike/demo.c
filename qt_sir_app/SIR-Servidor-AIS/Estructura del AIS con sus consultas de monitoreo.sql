------  Estructura del AIS --------------------------------------------------------------

--Trama--

AIS;255802360;9137820;JUMMETOR;21356500;084430800;21/09/2010 19:37:32;0;CQPO;70;1;108;16;23/09 01:00;4;TAMPA;13;0;292;296;5;


--Desglose--

------------------------Nom_Sensor----------------------------------------------------------
posición 0=  sensor (AIS)	VARCHAR(60)   			(Nomenclador de sensores y nomenclador de tipo sensores)
INSERT INTO mod_siren.nom_sensor ("nombre", "idtiposensor")
VALUES ('Sensor', 1);
----------------------------------------------------------------------------------------

--------------------------dat_Embarcación---------------------------------------------------
posición 1=  MMSI						(TABLA EMBARCACIÓN) VARCHAR(100)
posición 2=  OMI						(TABLA EMBARCACIÓN) VARCHAR(100)
posición 3=  nombre del barco			(TABLA EMBARCACIÓN) TEXT
posición 11= eslora						(TABLA EMBARCACIÓN) VARCHAR(20)
posición 12= manga						(TABLA EMBARCACIÓN) VARCHAR(20)

posición 8=  Dispositivo de llamada		(TABLA EMBARCACIÓN) VARCHAR(200)
posición 9=  Tipo barco					(TABLA EMBARCACIÓN) VARCHAR(100)
posición 10= Tipo sensor naval			(TABLA EMBARCACIÓN) VARCHAR(100)
posición 14= calado						(TABLA EMBARCACIÓN) TEXT
posición 20= estación AIS 				(TABLA EMBARCACIÓN) VARCHAR(20)

$idsensor = SELECT s.idsensor from mod_siren.nom_sensor s where s.nombre = 'Tipo sensor naval';
$idtipoembarcacion = SELECT e.idtipoembarcacion from mod_siren.nom_tipoembarcacion e where e.denominacion = 'Tipo barco';
INSERT INTO "mod_siren"."dat_embarcacion" ("nombre", "idtipoembarcacion", "calado", "distllamada", "eslora", "estacionais", "manga", "mmsi", "omi", "idsensor", "imagen")
VALUES ('nombre del barco', $idtipoembarcacion, 'calado', 'Dispositivo de llamada', 'eslora', 'estación AIS ', 'manga', 'MMSI', 'OMI', $idsensor, 'Imagen null');
----------------------------------------------------------------------------------------------------

---------------------Localización embarcación-------------------------------------------------------

posición 16= velocidad			        (TABLA LOCALIZACIÓN Embarcacion) DOUBLE PRECISION
posición 18= rumbo						(TABLA LOCALIZACIÓN Embarcacion) INTEGER
posición 19= cabeceo					(TABLA LOCALIZACIÓN Embarcacion) VARCHAR(20)
posición 17= presición de la posición 	(TABLA LOCALIZACIÓN Embarcacion) INTEGER
posición 7=  situación de navegación	(TABLA LOCALIZACIÓN Embarcacion) TEXT
posición 6=  Fecha y Hora			    (TABLA LOCALIZACIÓN Embarcacion) Timestamp(6)

$idembarcacion = SELECT e.idembarcacion from mod_siren.dat_embarcacion e WHERE e.mmsi = 'MMSI';
$idlocalizacion = Select l.idlocalizacion from mod_siren.dat_localizacion l Whre l.the_geom = 'geometria(latitud, longitud)';
$idsituacionnavegacion = Select s.idsituacionnavegacion from mod_siren.nom_situacionnavegacion s Where s.situacion = 'situación de navegación';

INSERT INTO "mod_siren"."dat_localizacionembarcacion" ("idembarcacion", "idlocalizacion", "velocidad", "cabeceo", "rumbo", "precisionnavegacion", "idsituacionnavegacion", "fecha")
VALUES ( $idembarcacion, $idlocalizacion, 'velocidad', 'cabeceo','rumbo', 'presición de la posición',$idsituacionnavegacion,'Fecha y Hora');
---------------------------------------------------------------------------------------------

-----------------------------------Localizacion----------------------------------------------
posición 4=  Longitud				(TABLA LOCALIZACIÓN) DOUBLE PRECISION
posición 5=  Latitud				(TABLA LOCALIZACIÓN) DOUBLE PRECISION

$the_geom = geometryfromtext('POINT('' ||latitud || '' ||longitud');  GEOMETRY

INSERT INTO "mod_siren"."dat_localizacion" ("the_geom")
VALUES ($the_geom);

------------------------------------------------------------------------------------------------

----------------------Tipo de embarcacion-------------------------------------------------------
Codigo = primeros 3 numeros del mmsi que es el 1 VARCHAR(3)
Descripcion = Text
denominacion = posición 9=  Tipo barco  (TABLA EMBARCACIÓN) VARCHAR(100)
INSERT INTO "mod_siren"."nom_tipoembarcacion" ("codigo","descripcion","denominacion")
VALUES ('codigo','descripcion','denominacion');
------------------------------------------------------------------------------------------------

------------------------Puertos-----------------------------------------------------------------
$idlocalizacion = Select l.idlocalizacion from mod_siren.dat_localizacion l Whre l.the_geom = 'geometryfromtext('POINT('' ||latitud || '' ||longitud')';
INSERT INTO "mod_siren"."dat_puertos" ("denominacion","calado","iddpa", "imagen", "idlocalizacion")
VALUES ('denominacion','calado',$iddpa,'imagen',$idlocalizacion);
------------------------------------------------------------------------------------------------

-----------------------Puerto destino-----------------------------------------------------------
posición 13= ETA (momento de llegada)	 (TABLA Puerto Destino)  Timestamp(6)

$idpuertodestino = Select p.idpuerto from mod_siren.dat_puerto p Where p.nombre = 'Puerto';
INSERT INTO "mod_siren"."dat_puertodestino" ("idpuertodestino","eta")
VALUES ($idpuertodestino,'ETA');
------------------------------------------------------------------------------------------------




