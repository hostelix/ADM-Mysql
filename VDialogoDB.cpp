#include "VDialogoDB.h"
#include "VentanaPrincipal.h"

VDialogoDB::VDialogoDB(wxWindow *parent) : DialogoDB(parent) {
	
}

VDialogoDB::~VDialogoDB() {
}

void VDialogoDB::evento_conectar_db( wxCommandEvent& event )  {
	
	if(campo_db->IsEmpty() || campo_password->IsEmpty() || campo_servidor->IsEmpty() || campo_usuario->IsEmpty()){
		wxMessageBox(wxT("Por favor rellena todos los campos"),wxT("Error"),wxOK);
	}
	else{
		wxString servidor= campo_servidor->GetValue();
		wxString usuario= campo_usuario->GetValue();
		wxString password= campo_password->GetValue();
		wxString puerto= campo_puerto->GetValue();
		wxString db= campo_db->GetValue();
		int port;
		port = wxAtoi(puerto);
		
		sistemas->Configurar_conexion(servidor,usuario,password,db,port);
		int pase=sistemas->Conexion_db();
		
		if(pase){
			int exito=wxMessageBox(wxT("Se a establecido la conexion con exito"),wxT("Excelente"),wxOK);
			if(exito){
				sistemas->Conexion_exito(true);//Agramos true para ver que si se conecto!
				sistemas->Agregar_si_recargo(false);//Agragamos false para que presione nuevamente el boton de recargar
				Close();
			}
		}
		else{
			wxMessageBox(wxT("Error al conectar con la base de datos"),wxT("Error"),wxICON_ERROR);
			sistemas->Conectar();
		}
	}
	event.Skip();
}

void VDialogoDB::evento_SalirModal( wxCommandEvent& event ) {
	Close();
	event.Skip();
}

