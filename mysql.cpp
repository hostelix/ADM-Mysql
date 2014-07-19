#include "mysql.h"
Mysql *sistemas;//Declaramos la varible global sistemas

int Mysql::Conectar(){
	if((sock=mysql_init(0))){
		return 1;
	}
	else{
		return 0;
	}
}

void Mysql::Desconectar(){
	mysql_close(sock);
}

int Mysql::ReConectar(){
	if(!mysql_ping(sock)){
		return 1;
	}
	else{
		mysql_close(sock);
		return 0;
	}
}

int Mysql::Conexion_db(){
	if(mysql_real_connect(sock,servidor,usuario, password, base_de_datos, puerto=MYSQL_PORT, NULL, 0)){
		return 1;
	}
	else{
		mysql_close(sock);
		return 0;
	}
}

void Mysql::Configurar_conexion(wxString host,wxString user, wxString pass, wxString db,unsigned puerto){
	servidor=host;
	usuario=user;
	password=pass;
	base_de_datos=db;
	puerto=puerto;
}

int Mysql::Seleccionar_db(wxString db){
	if(mysql_select_db(sock, db)){
		//Error al seleccionar la DB
		return 0;
	}
	else{
		return 1;
	}
}

int Mysql::Obtener_tablas(wxChoice tablas[]){
	if((resultado = mysql_list_tables(sock,NULL))){
		tablas->Clear();//Limpiamos todos los item del choice para agrgar nuevos
		c = (int) mysql_num_fields(resultado);
		while((fila = mysql_fetch_row(resultado))){
			for(int j = 0 ; j < c ; j++){
				(fila[j]==NULL) ? tablas->Append("NULL") : tablas->Append(fila[j]);
			}
		}
		mysql_free_result(resultado); // Liberar el resultado de la consulta
		return 1;
	}
	else{
		return 0;
	}
} 


int Mysql::Consulta(char *consulta){
	if(!mysql_query(sock,consulta)){
		return 1;
	}
	else{
		mysql_close(sock);
		return 0;
	}
}

int Mysql::Agragar_valor_fila_columnas(wxGrid *cuadro){
	if((resultado = mysql_store_result(sock))){
		c = (int) mysql_num_fields(resultado);
		f = (int) mysql_num_rows(resultado);
		for(int k=0; k<f;k++){
			fila = mysql_fetch_row(resultado);
			for(int j = 0 ; j < c ; j++){
				cuadro->SetCellValue(k,j,fila[j]);
			}
		}
		return 1;
	}
	else{
		mysql_close(sock);
		return 0;
	}
	
}
void Mysql::Conexion_exito(bool YESoNO){
	existe_db_conectada=YESoNO; //agragamos true si se conecto una db  o false si no se conecto 
}

bool Mysql::Verificar_si_existe_conexion(){
	//Comprueba si se ha conectado con la db
	if(existe_db_conectada){
		return 1;
	}
	else{
		return 0;
	}
}

wxString Mysql::Errores(){
	return mysql_error(sock);
}

int Mysql::Obtener_nombre_campos_y_valores(wxGrid *cuadro,wxString consulta){
	if(!mysql_query(sock,consulta)){
		if((resultado =  mysql_store_result(sock))) {
			// Obtener el número de registros seleccionados:
			f = (int) mysql_num_rows(resultado);
			// Obtener el número de columnsa por fila:
			c = (int) mysql_num_fields(resultado);
			// Información sobre columnas usando mysql_fetch_field:
			if(c!=cuadro->GetNumberCols()){
				cuadro->AppendCols(c);//agregamos el numero de columnas x resultado
				cuadro->AppendRows(f);//agregamos el numero de filas x resultado
				for(int l = 0; l < c; l++) {
					columna = mysql_fetch_field(resultado);
					cuadro->SetColLabelValue( l,columna->name);
					cuadro->SetRowLabelValue(l,wxString::Format(wxT("%i"),l+1));
				}
				for(int k=0; k<f;k++){
					fila = mysql_fetch_row(resultado);
					for(int j = 0 ; j < c ; j++){
						cuadro->SetCellValue(k,j,fila[j]);
					}
				}
			}
		}
		else{
			return 0;
		}
		return 1;
	}
	else{
		mysql_close(sock);
		return 0;
	}
	
}

int Mysql::Liberar_consulta(){
	mysql_free_result(resultado); // Liberar el resultado de la consulta
	return 1;
}

void Mysql::Agregar_si_recargo(bool YESoNO){
	recargo_tablas=YESoNO;
}

int Mysql::Verificar_si_recargo_tablas(){
	if(recargo_tablas){
		return 1;
	}
	else{
		return 0;
	}
}


void Mysql::Guardar_valor_viejo(wxString valor){
	valor_viejo=valor;
}

wxString Mysql::Recuperar_valor_viejo(){
	return valor_viejo;
}

int Mysql::Obtener_dbs(wxChoice db[]){
	if((resultado = mysql_list_dbs(sock,NULL))){
		db->Clear();//Limpiamos todos los item del choice para agrgar nuevos
		c = (int) mysql_num_fields(resultado);
		while((fila = mysql_fetch_row(resultado))){
			for(int j = 0 ; j < c ; j++){
				(fila[j]==NULL) ? db->Append("NULL") : db->Append(fila[j]);
			}
		}
		mysql_free_result(resultado); // Liberar el resultado de la consulta
		return 1;
	}
	else{
		return 0;
	}
} 


bool Mysql::Cambiar_usuario(wxString new_usuario,wxString new_password,wxString new_db){
	if(mysql_change_user(sock,new_usuario,new_password,new_db)){
		return false;//No tuvo exito
	}
	else{
		return true;//Tuvo exito la consulta
	}
}
