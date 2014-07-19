#ifndef VDIALOGODB_H
#define VDIALOGODB_H
#include "Ventanas.h"
#include "mysql.h"

class VDialogoDB : public DialogoDB{
	
private:
	
protected:
	void evento_cerrar_ventana_y_cargar_tablas( wxCloseEvent& event ) ;
	void evento_conectar_db( wxCommandEvent& event ) ;
	void evento_SalirModal( wxCommandEvent& event ) ;
public:
	VDialogoDB(wxWindow *parent=NULL);
	~VDialogoDB();
};

#endif

