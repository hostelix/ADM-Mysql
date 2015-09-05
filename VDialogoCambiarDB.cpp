#include "VDialogoCambiarDB.h"

VDialogoCambiarDB::VDialogoCambiarDB(wxWindow *parent) : DialogoCambiarDB(parent) {
	
}

VDialogoCambiarDB::~VDialogoCambiarDB() {
	
}


void VDialogoCambiarDB::evento_cancelar( wxCommandEvent& event )  {
	EndModal(1);//cerramos la ventana
	event.Skip();
}

void VDialogoCambiarDB::evento_dialogo_cambiar_db( wxCommandEvent& event )  {
	int respuesta=wxMessageBox(wxT("Estas seguro que quieres cambiar la DB?"),wxT("Atencion!"),wxYES_NO);
	
	if(respuesta==wxYES){
		wxString db=lista_db->GetStringSelection();//Nombre de la nueva base de datos
		
		if(sistemas->Seleccionar_db(db)){
			
			wxMessageBox(wxT("Se ha cambiado la base de datos con exito"),wxT("Felicidades!"));
			wxMessageBox(wxT("No olvides recargar las tablas! ya que se ha cambiado la DB"),wxT("Atencion!"),wxICON_EXCLAMATION);
			sistemas->Agregar_si_recargo(false);//Agragamos false para que presione nuevamente el boton de recargar
			EndModal(1);//cerramos la ventana
		}
		else{
			wxMessageBox(wxT("Lo sentimos, hubo un error al cambiar la base de datos"),wxT("Error!"));
		}
	}
	else{
		EndModal(1);//cerramos la ventana
	}
	event.Skip();
}

void VDialogoCambiarDB::evento_cargar_lista_dbs( wxInitDialogEvent& event )  {
	sistemas->Obtener_dbs(lista_db);
	event.Skip();
}

