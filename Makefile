CXX = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -fpic
LIBSDIR = -L. 
INCLUDEDIR = -I.

LIBCORENAME = mathsup

DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -ggdb -DDEBUG
endif

ifeq ($(OS), Windows_NT)
	EXPORT = export.bat
	LIBTARGET :=$(LIBCORENAME:=.dll)
	CLEANCMD = @del /q *.o *.dll *.exe *.so main.txt
else
	EXPORT = sh export.sh
	LIBTARGET :=lib$(LIBCORENAME:=.so)
	LIBSDIR += -L/usr/lib
	INCLUDEDIR += -I/usr/include
	CLEANCMD = rm -rf *.o *.so *.exe *.dll main.txt
endif

LIBSOURCE = matricesquare matrice complexe polynomes arithmetic
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