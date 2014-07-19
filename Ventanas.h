///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __VENTANAS_H__
#define __VENTANAS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/toolbar.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/msgdlg.h>
///////////////////////////////////////////////////////////////////////////

#define id_menu_cambiar_db 1000
#define id_salir 1001
#define id_cargar_db 1002
#define id_cambiar_usuario 1003
#define id_agregar 1004
#define id_conectar_db 1005
#define id_cancelar 1006

///////////////////////////////////////////////////////////////////////////////
/// Class FramePrincipal
///////////////////////////////////////////////////////////////////////////////
class FramePrincipal : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* Menu;
		wxMenu* Opciones;
		wxMenu* ayuda;
		wxStatusBar* barra_estado;
		wxToolBar* m_toolBar2;
		wxStaticText* m_staticText6;
		wxStaticText* num_tablas;
		wxChoice* db_tablas;
		wxGrid* Cuadro;
		
		// Virtual event handlers, overide them in your derived class
		virtual void evento_cambiar_db( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_Salir( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_menu_creditos( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_db_dialogo( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_cambiar_usuario( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_cargar_tablas( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_seleccionar_tabla( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_cambiar_campo( wxGridEvent& event ) { event.Skip(); }
		virtual void evento_guardar_valor_viejo( wxGridEvent& event ) { event.Skip(); }
		
	
	public:
		
		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Administrador MYSQL"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,350 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FramePrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogoDB
///////////////////////////////////////////////////////////////////////////////
class DialogoDB : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* campo_servidor;
		wxStaticBitmap* m_bitmap1;
		wxStaticText* m_staticText11;
		wxTextCtrl* campo_usuario;
		wxStaticBitmap* m_bitmap2;
		wxStaticText* m_staticText12;
		wxTextCtrl* campo_password;
		wxStaticBitmap* m_bitmap3;
		wxStaticText* m_staticText13;
		wxTextCtrl* campo_db;
		wxStaticBitmap* m_bitmap4;
		wxStaticText* m_staticText14;
		wxTextCtrl* campo_puerto;
		wxStaticBitmap* m_bitmap5;
		wxStaticLine* m_staticline1;
		wxButton* btn_conectar_db;
		wxButton* btn_cancelar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void evento_conectar_db( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_SalirModal( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogoDB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Conexion con la DB"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogoDB();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogoCambiarDB
///////////////////////////////////////////////////////////////////////////////
class DialogoCambiarDB : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText7;
		wxChoice* lista_db;
		wxButton* btn_cambiar_db;
		wxButton* btn_cancelar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void evento_cargar_lista_dbs( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void evento_dialogo_cambiar_db( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_cancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogoCambiarDB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cambiar DB"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 265,106 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogoCambiarDB();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogoCambiarUser
///////////////////////////////////////////////////////////////////////////////
class DialogoCambiarUser : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText9;
		wxTextCtrl* campo_cambiar_usuario;
		wxStaticText* m_staticText11;
		wxTextCtrl* campo_cambiar_password;
		wxStaticText* m_staticText111;
		wxChoice* cambiar_user_dbs;
		wxStaticLine* m_staticline4;
		wxButton* btn_cambiar_user_aceptar;
		wxButton* btn_cambiar_user_cancelar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void evento_cambiar_user_cargar_dbs( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void evento_cambiar_usuario( wxCommandEvent& event ) { event.Skip(); }
		virtual void evento_cambiar_user_cancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogoCambiarUser( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cambiar Usuario"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogoCambiarUser();
	
};

#endif //__VENTANAS_H__
