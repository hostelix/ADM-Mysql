#include "VentanaPrincipal.h"
#include "VDialogoDB.h"
#include "VDialogoCambiarDB.h"
#include "VDialogoCambiarUser.h"
#include "funciones.h"

VentanaPrincipal::VentanaPrincipal(wxWindow *parent):FramePrincipal(parent){
	barra_estado->SetStatusText(wxT("Administrdor MYSQL CreateBy: Hostelix"));
	Show();
}

void VentanaPrincipal::OnBotonCerrar( wxCommandEvent& event ) { 
	delete sistemas;//detruimos los objetos 
	Close();
}

void VentanaPrincipal::evento_cambiar_db( wxCommandEvent& event ) {
	if(sistemas->Verificar_si_existe_conexion()){
		VDialogoCambiarDB *cambiar_db=new VDialogoCambiarDB;
		if(cambiar_db->ShowModal()==wxID_OK){
		}
		else{
			cambiar_db->Destroy();//detruimos los objetos 
		}
	}
	else{
		wxMessageBox(wxT("Error no se ha conectado ha una base de datos"),wxT("Error de conexion"),wxICON_ERROR);
	}
//event.Skip();
}

void VentanaPrincipal::evento_Salir( wxCommandEvent& event )  {
	delete sistemas;//detruimos los objetos 
	Close();
	event.Skip();
}

void VentanaPrincipal::evento_db_dialogo( wxCommandEvent& event )  {
	VDialogoDB *conecta_db=new VDialogoDB;
	if(conecta_db->ShowModal()==wxID_OK){
	}
	else{
		conecta_db->Destroy();//detruimos los objetos 
	}
	event.Skip();
}

void VentanaPrincipal::evento_cargar_tablas( wxCommandEvent& event )  {
	if(sistemas->Verificar_si_existe_conexion()){
		sistemas->Agregar_si_recargo(true);//Agregamos que se recargaron las tablas
		sistemas->Obtener_tablas(db_tablas);
		////Obtenemos el numero de tablas///
		unsigned int num_tab=db_tablas->GetCount();
		wxString num_T;
		num_T << num_tab;
		num_tablas->SetLabel(num_T);
		//////Las ponemos en el label////
	}
	else{
		wxMessageBox(wxT("Error no se ha conectado a una base de datos"),wxT("Error de conexion"),wxICON_ERROR);
	}
	
	event.Skip();
}

void VentanaPrincipal::evento_seleccionar_tabla( wxCommandEvent& event )  {
	Cuadro->DeleteCols(0,Cuadro->wxGrid::GetNumberCols());//Borramos las columnas anteriores para agragar nuevas
	Cuadro->DeleteRows(0,Cuadro->wxGrid::GetNumberRows());//Borramos las columnas anteriores para agragar nuevas
	if(sistemas->Verificar_si_recargo_tablas()){
		wxString consulta=wxT("select * from ")+db_tablas->GetStringSelection();//Hacemos una consulta
		sistemas->Obtener_nombre_campos_y_valores(Cuadro,consulta);
		sistemas->Liberar_consulta();
	}
	else{
		wxMessageBox(wxT("Error! No haz recargado las tablas"),wxT("Atencion"),wxICON_ERROR);
	}
	event.Skip();
}

void VentanaPrincipal::evento_cambiar_campo( wxGridEvent& event )  {
	char *consulta;
	consulta=Patron_actualizar(sistemas->Recuperar_valor_viejo(),Cuadro,db_tablas,consulta);
	if(!sistemas->Consulta(consulta)){
		wxMessageBox(wxT("Error al hacer la consulta"));
	}
	delete consulta;
	event.Skip();
}

void VentanaPrincipal::evento_guardar_valor_viejo( wxGridEvent& event )  {
	sistemas->Guardar_valor_viejo(Cuadro->GetCellValue(Cuadro->wxGrid::GetGridCursorRow(),Cuadro->wxGrid::GetGridCursorCol()));
	event.Skip();
}

void VentanaPrincipal::evento_cargar_lista_dbs( wxInitDialogEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::evento_dialogo_cambiar_db( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::evento_cancelar( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::evento_cambiar_usuario( wxCommandEvent& event )  {
	if(sistemas->Verificar_si_existe_conexion()){
		VDialogoCambiarUser *cambiar_usuario= new VDialogoCambiarUser;
		if(cambiar_usuario->ShowModal()==wxID_OK){
			
		}
		else{
			cambiar_usuario->Destroy();
		}
	}
	else{
		wxMessageBox(wxT("Error, no se ha establecido una conexion con el servidor Mysql"),wxT("Error de conexion"),wxICON_ERROR);
	}
	event.Skip();
}

void VentanaPrincipal::evento_menu_creditos( wxCommandEvent& event )  {
	wxMessageBox(wxT("~Administrador de base de datos Mysql~\n>Programado y modulado por Israel Lugo\n>Contactos: 0426-2075370\n< SOFTelixBM >"),wxT("Creditos"));
}

