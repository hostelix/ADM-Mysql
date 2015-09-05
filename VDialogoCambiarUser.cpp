#include "VDialogoCambiarUser.h"
#include "mysql.h"

VDialogoCambiarUser::VDialogoCambiarUser(wxWindow *parent) : DialogoCambiarUser(parent) {
	
}

VDialogoCambiarUser::~VDialogoCambiarUser() {
	
}
void VDialogoCambiarUser::evento_cambiar_usuario( wxCommandEvent& event )  {
	if(campo_cambiar_usuario->IsEmpty()||campo_cambiar_password->IsEmpty()){
		wxMessageBox(wxT("Los campos Usuario y Password son obligatorios"),wxT("Error"),wxICON_ERROR);
	}
	else{
		wxString usuario=campo_cambiar_usuario->GetValue();
		wxString password=campo_cambiar_password->GetValue();
		wxString db=cambiar_user_dbs->GetStringSelection();
		if(!db.IsEmpty()){
			int respuesta=wxMessageBox(wxT("Realmente desea cambiar de usuario?"),wxT("Atencion"),wxYES_NO);
			if(respuesta==wxYES){
				if(sistemas->Cambiar_usuario(usuario,password,db)){
					wxMessageBox(wxT("El usuario se ha cambiado con exito"),wxT("Felicidades"));
					sistemas->Agregar_si_recargo(false);//Agregamos que no se recargaron las tablas
					Close();
				}
				else{
					wxMessageBox(wxT("Error inesperado al cambiar el usuario"),wxT("Error"));
				}
			}
		}
		else{
			wxMessageBox(wxT("Por favor, Seleccione una base de datos"),wxT("Atencion"));
		}
	}
	event.Skip();
}

void VDialogoCambiarUser::evento_cambiar_user_cancelar( wxCommandEvent& event )  {
	Close();
	event.Skip();
}

void VDialogoCambiarUser::evento_cambiar_user_cargar_dbs( wxInitDialogEvent& event )  {
	sistemas->Obtener_dbs(cambiar_user_dbs);
	event.Skip();
}

