#ifndef VentanaPrincipal_H
#define VentanaPrincipal_H
#include "mysql.h"
#include "Ventanas.h"
class VentanaPrincipal:public FramePrincipal{
protected:
	void evento_menu_creditos( wxCommandEvent& event ) ;
	void evento_cambiar_usuario( wxCommandEvent& event ) ;
	void evento_cargar_lista_dbs( wxInitDialogEvent& event ) ;
	void evento_dialogo_cambiar_db( wxCommandEvent& event ) ;
	void evento_cancelar( wxCommandEvent& event ) ;
	void evento_guardar_valor_viejo( wxGridEvent& event ) ;
	void evento_cambiar_campo( wxGridEvent& event ) ;
	void evento_cambiar_db( wxCommandEvent& event ) ;
	void evento_Salir( wxCommandEvent& event ) ;
	void evento_db_dialogo( wxCommandEvent& event ) ;
	void evento_cargar_tablas( wxCommandEvent& event ) ;
	void evento_seleccionar_tabla( wxCommandEvent& event ) ;

public:
	VentanaPrincipal(wxWindow *parent=NULL);
	void OnBotonCerrar(wxCommandEvent &evt);
};
#endif
