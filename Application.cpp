#include "Application.h"
#include "VentanaPrincipal.h"
#include <wx/image.h>

IMPLEMENT_APP(mxApplication)
bool mxApplication::OnInit() {
	wxInitAllImageHandlers();
	new VentanaPrincipal(NULL);
	sistemas=new Mysql();
	sistemas->Conectar();
	sistemas->Conexion_exito(false);
	sistemas->Agregar_si_recargo(false);
	return true;
}

