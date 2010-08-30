#############################################################################
# Makefile for building: qneur
# Generated by qmake (2.01a) (Qt 4.6.2) on: ?? ???? 25 19:47:11 2010
# Project:  qneur.pro
# Template: subdirs
# Command: /usr/bin/qmake-qt4 -unix -o Makefile qneur.pro
#############################################################################

first: make_default
MAKEFILE      = Makefile
QMAKE         = /usr/bin/qmake-qt4
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		sub-qgraph \
		sub-qgraph-test \
		sub-qneurnet

qgraph//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) qgraph/ || $(MKDIR) qgraph/ 
	cd qgraph/ && $(QMAKE) /home/sphinx/cpp/qneur/qgraph/qgraph.pro -unix -o $(MAKEFILE)
sub-qgraph-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) qgraph/ || $(MKDIR) qgraph/ 
	cd qgraph/ && $(QMAKE) /home/sphinx/cpp/qneur/qgraph/qgraph.pro -unix -o $(MAKEFILE)
sub-qgraph: qgraph//$(MAKEFILE) FORCE
	cd qgraph/ && $(MAKE) -f $(MAKEFILE)
sub-qgraph-make_default: qgraph//$(MAKEFILE) FORCE
	cd qgraph/ && $(MAKE) -f $(MAKEFILE) 
sub-qgraph-make_first: qgraph//$(MAKEFILE) FORCE
	cd qgraph/ && $(MAKE) -f $(MAKEFILE) first
sub-qgraph-all: qgraph//$(MAKEFILE) FORCE
	cd qgraph/ && $(MAKE) -f $(MAKEFILE) all
sub-qgraph-clean: qgraph//$(MAKEFILE) FORCE
	cd qgraph/ && $(MAKE) -f $(MAKEFILE) clean
sub-qgraph-distclean: qgraph//$(MAKEFILE) FORCE
	cd qgraph/ && $(MAKE) -f $(MAKEFILE) distclean
sub-qgraph-install_subtargets: qgraph//$(MAKEFILE) FORCE
	cd qgraph/ && $(MAKE) -f $(MAKEFILE) install
sub-qgraph-uninstall_subtargets: qgraph//$(MAKEFILE) FORCE
	cd qgraph/ && $(MAKE) -f $(MAKEFILE) uninstall
qgraph-test//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) qgraph-test/ || $(MKDIR) qgraph-test/ 
	cd qgraph-test/ && $(QMAKE) /home/sphinx/cpp/qneur/qgraph-test/qgraph-test.pro -unix -o $(MAKEFILE)
sub-qgraph-test-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) qgraph-test/ || $(MKDIR) qgraph-test/ 
	cd qgraph-test/ && $(QMAKE) /home/sphinx/cpp/qneur/qgraph-test/qgraph-test.pro -unix -o $(MAKEFILE)
sub-qgraph-test: qgraph-test//$(MAKEFILE) FORCE
	cd qgraph-test/ && $(MAKE) -f $(MAKEFILE)
sub-qgraph-test-make_default: qgraph-test//$(MAKEFILE) FORCE
	cd qgraph-test/ && $(MAKE) -f $(MAKEFILE) 
sub-qgraph-test-make_first: qgraph-test//$(MAKEFILE) FORCE
	cd qgraph-test/ && $(MAKE) -f $(MAKEFILE) first
sub-qgraph-test-all: qgraph-test//$(MAKEFILE) FORCE
	cd qgraph-test/ && $(MAKE) -f $(MAKEFILE) all
sub-qgraph-test-clean: qgraph-test//$(MAKEFILE) FORCE
	cd qgraph-test/ && $(MAKE) -f $(MAKEFILE) clean
sub-qgraph-test-distclean: qgraph-test//$(MAKEFILE) FORCE
	cd qgraph-test/ && $(MAKE) -f $(MAKEFILE) distclean
sub-qgraph-test-install_subtargets: qgraph-test//$(MAKEFILE) FORCE
	cd qgraph-test/ && $(MAKE) -f $(MAKEFILE) install
sub-qgraph-test-uninstall_subtargets: qgraph-test//$(MAKEFILE) FORCE
	cd qgraph-test/ && $(MAKE) -f $(MAKEFILE) uninstall
qneurnet//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) qneurnet/ || $(MKDIR) qneurnet/ 
	cd qneurnet/ && $(QMAKE) /home/sphinx/cpp/qneur/qneurnet/qneurnet.pro -unix -o $(MAKEFILE)
sub-qneurnet-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) qneurnet/ || $(MKDIR) qneurnet/ 
	cd qneurnet/ && $(QMAKE) /home/sphinx/cpp/qneur/qneurnet/qneurnet.pro -unix -o $(MAKEFILE)
sub-qneurnet: qneurnet//$(MAKEFILE) FORCE
	cd qneurnet/ && $(MAKE) -f $(MAKEFILE)
sub-qneurnet-make_default: qneurnet//$(MAKEFILE) FORCE
	cd qneurnet/ && $(MAKE) -f $(MAKEFILE) 
sub-qneurnet-make_first: qneurnet//$(MAKEFILE) FORCE
	cd qneurnet/ && $(MAKE) -f $(MAKEFILE) first
sub-qneurnet-all: qneurnet//$(MAKEFILE) FORCE
	cd qneurnet/ && $(MAKE) -f $(MAKEFILE) all
sub-qneurnet-clean: qneurnet//$(MAKEFILE) FORCE
	cd qneurnet/ && $(MAKE) -f $(MAKEFILE) clean
sub-qneurnet-distclean: qneurnet//$(MAKEFILE) FORCE
	cd qneurnet/ && $(MAKE) -f $(MAKEFILE) distclean
sub-qneurnet-install_subtargets: qneurnet//$(MAKEFILE) FORCE
	cd qneurnet/ && $(MAKE) -f $(MAKEFILE) install
sub-qneurnet-uninstall_subtargets: qneurnet//$(MAKEFILE) FORCE
	cd qneurnet/ && $(MAKE) -f $(MAKEFILE) uninstall

Makefile: qneur.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -unix -o Makefile qneur.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake: qmake_all FORCE
	@$(QMAKE) -unix -o Makefile qneur.pro

qmake_all: sub-qgraph-qmake_all sub-qgraph-test-qmake_all sub-qneurnet-qmake_all FORCE

make_default: sub-qgraph-make_default sub-qgraph-test-make_default sub-qneurnet-make_default FORCE
make_first: sub-qgraph-make_first sub-qgraph-test-make_first sub-qneurnet-make_first FORCE
all: sub-qgraph-all sub-qgraph-test-all sub-qneurnet-all FORCE
clean: sub-qgraph-clean sub-qgraph-test-clean sub-qneurnet-clean FORCE
distclean: sub-qgraph-distclean sub-qgraph-test-distclean sub-qneurnet-distclean FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-qgraph-install_subtargets sub-qgraph-test-install_subtargets sub-qneurnet-install_subtargets FORCE
uninstall_subtargets: sub-qgraph-uninstall_subtargets sub-qgraph-test-uninstall_subtargets sub-qneurnet-uninstall_subtargets FORCE

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:

