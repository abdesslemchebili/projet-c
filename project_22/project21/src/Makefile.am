## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project_2

project_2_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	reclam.c reclam.h \
	tree.c tree.h \
	crud.c crud.h \
	foyer.c foyer.h \
	fonction.c fonction.h \
	fonction1.c fonction1.h \
	fonction2.c fonction2.h \
	stock.c stock.h
	

project_2_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

