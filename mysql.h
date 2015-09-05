#ifndef __MYSQL_H_
#define __MYSQL_H_
#include "Ventanas.h"
#ifdef __WIN32__
	#include <windows.h>	
#endif

#include <mysql/mysql.h>

/*
#include <wx/msgdlg.h>
/*/
class Mysql{
public:
	int Conectar();//Iniciar mysql
	void Desconectar();//Cerrar mysql
	int ReConectar();//Reconectar mysql
	int Conexion_db();//Conectar a una db
	void Configurar_conexion(wxString host,wxString user, wxString pass, wxString db,unsigned port);//cambiar datos db
	int Seleccionar_db(wxString db);//Selecionar una nueva db
	int Obtener_tablas(wxChoice tablas[]);//Obtener las tablas de la db
	int Consulta(char *consulta);//Hacer una consulta
	int Agragar_valor_fila_columnas(wxGrid *cuadro);//Procesar la consulta
	void Conexion_exito(bool YESoNO);//Si o no la conexion con la db
	bool Verificar_si_existe_conexion();//Comprobar si se ha conectado con una db
	wxString Errores();//Mostrar errores producidos por las consultas
	int Obtener_nombre_campos_y_valores(wxGrid *cuadro,wxString consulta);
	int Liberar_consulta();//Liberamos consultas
	void Agregar_si_recargo(bool YESoNO);//Agramos a una varible bool si se recargo las tablas
	int Verificar_si_recargo_tablas();//Verificamos si las tablas se recargaron
	void Guardar_valor_viejo(wxString valor);
	wxString Recuperar_valor_viejo();
	int Obtener_dbs(wxChoice db[]);//Obtener las todas las db's
	bool Cambiar_usuario(wxString new_usuario,wxString new_password,wxString new_db);
private:
	wxString servidor;
	wxString usuario;
	wxString password;
	wxString base_de_datos;
	unsigned puerto;
	MYSQL *sock;
	MYSQL_RES *resultado;
	MYSQL_ROW fila;
	MYSQL_FIELD *columna;
	int f, c;
	bool existe_db_conectada;
	bool recargo_tablas;
	wxString valor_viejo;
	
};
extern Mysql *sistemas;//Varible externa para usar en todos los documentos
#endif
