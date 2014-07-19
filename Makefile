GPP=mingw32-g++
GCC=mingw32-gcc
FLAGS= -fshow-column  -g2 -Wall -O0 "-IC:\Archivos de programa\ZinjaI\mingw\include" "-IC:\Archivos de programa\ZinjaI\mingw\wx\include"  -DDEBUG 
LIBS= -static-libstdc++ -static-libgcc -mwindows "-LC:\Archivos de programa\ZinjaI\mingw\lib" "-LC:\Archivos de programa\ZinjaI\mingw\wx\lib" -lmysql -lwxmsw28_html -lwxmsw28_core -lwxbase28_net -lwxbase28 -lwxmsw28_adv -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lwxregex -lwxexpat -lwinmm -lshell32 -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lwsock32 -lodbc32 -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lwinspool  
OBJS=debug.w32\zpr_resource.o debug.w32\Application.o debug.w32\VentanaPrincipal.o debug.w32\Ventanas.o debug.w32\VDialogoDB.o debug.w32\mysql.o debug.w32\VDialogoCambiarDB.o debug.w32\VDialogoCambiarUser.o 

all: debug.w32 debug.w32\interfaz-sistemas.exe

clean:
	del ${OBJS} debug.w32\interfaz-sistemas.exe

debug.w32\interfaz-sistemas.exe: ${OBJS}
	${GPP} ${OBJS} ${LIBS} -o $@

debug.w32:
	mkdir debug.w32

debug.w32\Application.o: Application.cpp Application.h mysql.h Ventanas.h VentanaPrincipal.h
	${GPP} ${FLAGS} -c Application.cpp -o $@

debug.w32\VentanaPrincipal.o: VentanaPrincipal.cpp VentanaPrincipal.h mysql.h Ventanas.h VDialogoDB.h VDialogoCambiarDB.h VDialogoCambiarUser.h funciones.h
	${GPP} ${FLAGS} -c VentanaPrincipal.cpp -o $@

debug.w32\Ventanas.o: Ventanas.cpp Ventanas.h
	${GPP} ${FLAGS} -c Ventanas.cpp -o $@

debug.w32\VDialogoDB.o: VDialogoDB.cpp VDialogoDB.h Ventanas.h mysql.h VentanaPrincipal.h
	${GPP} ${FLAGS} -c VDialogoDB.cpp -o $@

debug.w32\mysql.o: mysql.cpp mysql.h Ventanas.h
	${GPP} ${FLAGS} -c mysql.cpp -o $@

debug.w32\VDialogoCambiarDB.o: VDialogoCambiarDB.cpp VDialogoCambiarDB.h Ventanas.h mysql.h
	${GPP} ${FLAGS} -c VDialogoCambiarDB.cpp -o $@

debug.w32\VDialogoCambiarUser.o: VDialogoCambiarUser.cpp VDialogoCambiarUser.h Ventanas.h mysql.h
	${GPP} ${FLAGS} -c VDialogoCambiarUser.cpp -o $@

