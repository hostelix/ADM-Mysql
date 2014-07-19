#ifndef VDIALOGOCAMBIARDB_H
#define VDIALOGOCAMBIARDB_H
#include "Ventanas.h"
#include "mysql.h"

class VDialogoCambiarDB : public DialogoCambiarDB {
	
private:
	
protected:
	void evento_cargar_lista_dbs( wxInitDialogEvent& event ) ;
	void evento_dialogo_cambiar_db( wxCommandEvent& event ) ;
	void evento_cancelar( wxCommandEvent& event ) ;
	
public:
	VDialogoCambiarDB(wxWindow *parent=NULL);
	~VDialogoCambiarDB();
};

#endif

