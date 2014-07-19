#ifndef VDIALOGOCAMBIARUSER_H
#define VDIALOGOCAMBIARUSER_H
#include "Ventanas.h"

class VDialogoCambiarUser : public DialogoCambiarUser {
	
private:
	
protected:
	void evento_cambiar_user_cargar_dbs( wxInitDialogEvent& event ) ;
	void evento_cambiar_usuario( wxCommandEvent& event ) ;
	void evento_cambiar_user_cancelar( wxCommandEvent& event ) ;
	
public:
	VDialogoCambiarUser(wxWindow *parent=NULL);
	~VDialogoCambiarUser();
};

#endif

