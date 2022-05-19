CXX = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g
LIBSDIR = -L. -L/usr/lib
INCLUDEDIR = -I. -I/usr/include

LIBCORENAME = mathsup

ifeq ($(OS), Windows_NT)
	EXPORT = export.bat
	LIBTARGET :=$(LIBCORENAME:=.dll)
	CLEANCMD = @del /q *.o *.dll *.exe *.so main.txt
else
	EXPORT = sh export.sh
	LIBTARGET :=lib$(LIBCORENAME:=.so)
	CLEANCMD = rm -rf *.o *.so *.exe *.dll main.txt
endif

LIBSOURCE = matricesquare matrice polynomes complexe arithmetic
LIBSOURCECFILE = $(LIBSOURCE:=.c)
LIBSOURCEOFILE = $(LIBSOURCE:=.o)

EXESOURCE = main
TARGET = $(EXESOURCE:=.exe)
EXESOURCECFILE = $(EXESOURCE:=.c)
EXESOURCEOFILE = $(EXESOURCE:=.o)

all: $(TARGET)

run: $(TARGET)
	$(EXPORT) $(TARGET)

$(TARGET): $(EXESOURCEOFILE) $(LIBTARGET) 
	$(CXX) $(EXESOURCEOFILE) -l$(LIBCORENAME) $(LIBSDIR) -o $(TARGET) -lm

$(LIBTARGET): $(LIBSOURCEOFILE) 
	$(CXX) $(CFLAGS) -shared $(LIBSOURCEOFILE) -o $(LIBTARGET)

.c.o:
	$(CXX) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

clean: 
	$(CLEANCMD)
	@echo CLEAN