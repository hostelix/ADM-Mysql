///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Ventanas.h"

///////////////////////////////////////////////////////////////////////////

FramePrincipal::FramePrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	Menu = new wxMenuBar( 0 );
	Opciones = new wxMenu();
	wxMenuItem* menu_cambiar_db;
	menu_cambiar_db = new wxMenuItem( Opciones, id_menu_cambiar_db, wxString( wxT("Cambiar DB") ) , wxEmptyString, wxITEM_NORMAL );
	Opciones->Append( menu_cambiar_db );
	
	wxMenuItem* m_separator2;
	m_separator2 = Opciones->AppendSeparator();
	
	wxMenuItem* menu_salir;
	menu_salir = new wxMenuItem( Opciones, id_salir, wxString( wxT("Salir") ) , wxEmptyString, wxITEM_NORMAL );
	Opciones->Append( menu_salir );
	
	Menu->Append( Opciones, wxT("Opciones") ); 
	
	ayuda = new wxMenu();
	wxMenuItem* menu_creditos;
	menu_creditos = new wxMenuItem( ayuda, wxID_ANY, wxString( wxT("Creditos") ) , wxEmptyString, wxITEM_NORMAL );
	ayuda->Append( menu_creditos );
	
	Menu->Append( ayuda, wxT("Ayuda") ); 
	
	this->SetMenuBar( Menu );
	
	barra_estado = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_toolBar2 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar2->AddTool( id_cargar_db, wxT("tool"), wxBitmap( wxT("img/cargar_db.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Conectar a base de datos"), wxEmptyString, NULL ); 
	
	m_toolBar2->AddSeparator(); 
	
	m_toolBar2->AddTool( id_cambiar_usuario, wxT("tool"), wxBitmap( wxT("img/usuario.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Cambiar de usuario"), wxEmptyString, NULL ); 
	
	m_toolBar2->AddSeparator(); 
	
	m_toolBar2->AddSeparator(); 
	
	m_toolBar2->AddTool( id_agregar, wxT("tool"), wxBitmap( wxT("img/reaload_tablas.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Recargar tablas"), wxEmptyString, NULL ); 
	
	m_toolBar2->AddSeparator(); 
	
	m_toolBar2->AddSeparator(); 
	
	m_toolBar2->AddSeparator(); 
	
	m_staticText6 = new wxStaticText( m_toolBar2, wxID_ANY, wxT("Tablas >>"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_toolBar2->AddControl( m_staticText6 );
	num_tablas = new wxStaticText( m_toolBar2, wxID_ANY, wxT(" 0"), wxDefaultPosition, wxDefaultSize, 0 );
	num_tablas->Wrap( -1 );
	m_toolBar2->AddControl( num_tablas );
	m_toolBar2->AddSeparator(); 
	
	wxArrayString db_tablasChoices;
	db_tablas = new wxChoice( m_toolBar2, wxID_ANY, wxDefaultPosition, wxDefaultSize, db_tablasChoices, 0 );
	db_tablas->SetSelection( 0 );
	m_toolBar2->AddControl( db_tablas );
	m_toolBar2->Realize(); 
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	Cuadro = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	Cuadro->CreateGrid( 0, 0 );
	Cuadro->EnableEditing( true );
	Cuadro->EnableGridLines( true );
	Cuadro->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );
	Cuadro->EnableDragGridSize( false );
	Cuadro->SetMargins( 0, 0 );
	
	// Columns
	Cuadro->AutoSizeColumns();
	Cuadro->EnableDragColMove( false );
	Cuadro->EnableDragColSize( false );
	Cuadro->SetColLabelSize( 30 );
	Cuadro->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	Cuadro->AutoSizeRows();
	Cuadro->EnableDragRowSize( false );
	Cuadro->SetRowLabelSize( 80 );
	Cuadro->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	Cuadro->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer10->Add( Cuadro, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( menu_cambiar_db->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::evento_cambiar_db ) );
	this->Connect( menu_salir->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::evento_Salir ) );
	this->Connect( menu_creditos->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::evento_menu_creditos ) );
	this->Connect( id_cargar_db, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FramePrincipal::evento_db_dialogo ) );
	this->Connect( id_cambiar_usuario, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FramePrincipal::evento_cambiar_usuario ) );
	this->Connect( id_agregar, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FramePrincipal::evento_cargar_tablas ) );
	db_tablas->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( FramePrincipal::evento_seleccionar_tabla ), NULL, this );
	Cuadro->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( FramePrincipal::evento_cambiar_campo ), NULL, this );
	Cuadro->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( FramePrincipal::evento_guardar_valor_viejo ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
	// Disconnect Events
	this->Disconnect( id_menu_cambiar_db, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::evento_cambiar_db ) );
	this->Disconnect( id_salir, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::evento_Salir ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FramePrincipal::evento_menu_creditos ) );
	this->Disconnect( id_cargar_db, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FramePrincipal::evento_db_dialogo ) );
	this->Disconnect( id_cambiar_usuario, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FramePrincipal::evento_cambiar_usuario ) );
	this->Disconnect( id_agregar, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FramePrincipal::evento_cargar_tablas ) );
	db_tablas->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( FramePrincipal::evento_seleccionar_tabla ), NULL, this );
	Cuadro->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( FramePrincipal::evento_cambiar_campo ), NULL, this );
	Cuadro->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( FramePrincipal::evento_guardar_valor_viejo ), NULL, this );
	
}

DialogoDB::DialogoDB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Servidor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer9->Add( m_staticText2, 0, wxALL, 5 );
	
	campo_servidor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer9->Add( campo_servidor, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("img/servidor.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_bitmap1, 0, wxALL, 5 );
	
	bSizer18->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer20->Add( m_staticText11, 0, wxALL, 5 );
	
	campo_usuario = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer20->Add( campo_usuario, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("img/usuario.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_bitmap2, 0, wxALL, 5 );
	
	bSizer18->Add( bSizer20, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer22->Add( m_staticText12, 0, wxALL, 5 );
	
	campo_password = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD|wxTE_RIGHT );
	bSizer22->Add( campo_password, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_bitmap3 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("img/clave.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_bitmap3, 0, wxALL, 5 );
	
	bSizer18->Add( bSizer22, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Base de datos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer23->Add( m_staticText13, 0, wxALL, 5 );
	
	campo_db = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer23->Add( campo_db, 1, wxALL, 5 );
	
	m_bitmap4 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("img/db.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_bitmap4, 0, wxALL, 5 );
	
	bSizer18->Add( bSizer23, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Puerto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer24->Add( m_staticText14, 0, wxALL, 5 );
	
	campo_puerto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer24->Add( campo_puerto, 1, wxALL, 5 );
	
	m_bitmap5 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("img/puerto.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_bitmap5, 0, wxALL, 5 );
	
	bSizer18->Add( bSizer24, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer18->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	btn_conectar_db = new wxButton( this, id_conectar_db, wxT("Conectar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( btn_conectar_db, 1, wxALL|wxALIGN_BOTTOM, 5 );
	
	btn_cancelar = new wxButton( this, id_cancelar, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( btn_cancelar, 1, wxALL, 5 );
	
	bSizer18->Add( bSizer25, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer18 );
	this->Layout();
	bSizer18->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btn_conectar_db->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoDB::evento_conectar_db ), NULL, this );
	btn_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoDB::evento_SalirModal ), NULL, this );
}

DialogoDB::~DialogoDB()
{
	// Disconnect Events
	btn_conectar_db->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoDB::evento_conectar_db ), NULL, this );
	btn_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoDB::evento_SalirModal ), NULL, this );
	
}

DialogoCambiarDB::DialogoCambiarDB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Base de datos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer11->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString lista_dbChoices;
	lista_db = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, lista_dbChoices, 0 );
	lista_db->SetSelection( -1 );
	bSizer11->Add( lista_db, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer10->Add( bSizer11, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	btn_cambiar_db = new wxButton( this, wxID_ANY, wxT("Cambiar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( btn_cambiar_db, 1, wxALL, 5 );
	
	btn_cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( btn_cancelar, 1, wxALL, 5 );
	
	bSizer10->Add( bSizer15, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogoCambiarDB::evento_cargar_lista_dbs ) );
	btn_cambiar_db->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoCambiarDB::evento_dialogo_cambiar_db ), NULL, this );
	btn_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoCambiarDB::evento_cancelar ), NULL, this );
}

DialogoCambiarDB::~DialogoCambiarDB()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogoCambiarDB::evento_cargar_lista_dbs ) );
	btn_cambiar_db->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoCambiarDB::evento_dialogo_cambiar_db ), NULL, this );
	btn_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoCambiarDB::evento_cancelar ), NULL, this );
	
}

DialogoCambiarUser::DialogoCambiarUser( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer13->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	campo_cambiar_usuario = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( campo_cambiar_usuario, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer12->Add( bSizer13, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer14->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	campo_cambiar_password = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	bSizer14->Add( campo_cambiar_password, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer12->Add( bSizer14, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText111 = new wxStaticText( this, wxID_ANY, wxT("Bases de datos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	bSizer161->Add( m_staticText111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString cambiar_user_dbsChoices;
	cambiar_user_dbs = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, cambiar_user_dbsChoices, 0 );
	cambiar_user_dbs->SetSelection( -1 );
	bSizer161->Add( cambiar_user_dbs, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer12->Add( bSizer161, 1, wxEXPAND, 5 );
	
	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer12->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	btn_cambiar_user_aceptar = new wxButton( this, wxID_ANY, wxT("Cambiar Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( btn_cambiar_user_aceptar, 1, wxALL, 5 );
	
	btn_cambiar_user_cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( btn_cambiar_user_cancelar, 1, wxALL, 5 );
	
	bSizer12->Add( bSizer16, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer12 );
	this->Layout();
	bSizer12->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogoCambiarUser::evento_cambiar_user_cargar_dbs ) );
	btn_cambiar_user_aceptar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoCambiarUser::evento_cambiar_usuario ), NULL, this );
	btn_cambiar_user_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoCambiarUser::evento_cambiar_user_cancelar ), NULL, this );
}

DialogoCambiarUser::~DialogoCambiarUser()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogoCambiarUser::evento_cambiar_user_cargar_dbs ) );
	btn_cambiar_user_aceptar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoCambiarUser::evento_cambiar_usuario ), NULL, this );
	btn_cambiar_user_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogoCambiarUser::evento_cambiar_user_cancelar ), NULL, this );
	
}
