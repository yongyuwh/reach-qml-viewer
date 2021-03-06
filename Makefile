package = qml-viewer
version = 1.0.8
tarname = $(package)
distdir = $(tarname)-$(version)

dist: $(distdir).tar.gz

$(distdir).tar.gz: $(distdir)
	tar chof - $(distdir) | gzip -9 -c > $@
	rm -rf $(distdir)

$(distdir): FORCE
	mkdir $(distdir)
	cp Makefile $(distdir)
	cp application.conf.example $(distdir)
	cp connection.cpp $(distdir)
	cp connection.h $(distdir)
	cp main.cpp $(distdir)
	cp mainview.cpp $(distdir)
	cp mainview.h $(distdir)
	cp mainwindow.cpp $(distdir)
	cp mainwindow.h $(distdir)
	cp messagehandler.cpp $(distdir)
	cp messagehandler.h $(distdir)
	cp qml-viewer.pro $(distdir)
	cp screen.cpp $(distdir)
	cp screen.h $(distdir)
	cp settings.conf.example $(distdir)
	cp settings.h $(distdir)
	cp settings.cpp $(distdir)
	cp systemdefs.h $(distdir)

FORCE:
	-rm $(distdir).tar.gz > /dev/null 2>&1
	-rm -rf $(distdir) > /dev/null 2>&1
        
.PHONY: FORCE dist
