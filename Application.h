#ifndef MX_APPLICATION_H
#define MX_APPLICATION_H
#include <wx/app.h>
#include "mysql.h"
class mxApplication : public wxApp {
public:
	virtual bool OnInit();
};
#endif
