#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Ventanas.h"

char *Patron_actualizar(wxString sistema,wxGrid *cuadro,wxChoice *tablas,char *&CONSULTA){
	wxString nomTabla=tablas->GetStringSelection();
	wxString nomCampo=cuadro->GetColLabelValue(cuadro->wxGrid::GetGridCursorCol());//nombre de la tabla
	wxString valorV=sistema;//Valor viejo de la celda
	wxString valorN=cuadro->GetCellValue(cuadro->wxGrid::GetGridCursorRow(),cuadro->wxGrid::GetGridCursorCol());//Valor nuevo de la celda
	char patron[]="UPDATE %s SET %s ='%s' Where (%s LIKE '%s')";//Patron de la consulta
	CONSULTA=new char[nomTabla.Len()+nomCampo.Len()+valorN.Len()+nomCampo.Len()+valorV.Len()+strlen(patron)];
	sprintf(CONSULTA,patron,nomTabla.mb_str(),nomCampo.mb_str(),valorN.mb_str(),nomCampo.mb_str(),valorV.mb_str());
	return CONSULTA;
}

#endif
