bindir = @libdir@/games/psemu/
libdir = @libdir@/games/psemu/

lib_LTLIBRARIES = libBladeSio1.la

libBladeSio1_la_SOURCES = sio1.c settings.c
libBladeSio1_la_LDFLAGS = -module -avoid-version

AM_CPPFLAGS = -DLOCALE_DIR=\"${datadir}/locale/\" \
	-DDATADIR=\"${datadir}/psemu/\" \
	$(GTK2_CFLAGS) $(GLADE2_CFLAGS) \
	-I../../libpcsxcore -I../../include

bin_PROGRAMS = cfgBladeSio1
cfgBladeSio1_SOURCES = gui.c
cfgBladeSio1_LDADD = $(GTK2_LIBS) $(GLADE2_LIBS)

glade_DATA = sio1.glade2
gladedir = $(datadir)/psemu/
EXTRA_DIST = $(glade_DATA)
