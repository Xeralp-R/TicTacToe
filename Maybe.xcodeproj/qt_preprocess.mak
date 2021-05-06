#############################################################################
# Makefile for building: Maybe.app/Contents/MacOS/Maybe
# Generated by qmake (3.1) (Qt 5.15.2)
# Project:  Maybe.pro
# Template: app
# Command: /Users/mariquitreventar/Qt/5.15.2/clang_64/bin/qmake -o Maybe.xcodeproj/project.pbxproj Maybe.pro -spec macx-xcode
#############################################################################

MAKEFILE      = project.pbxproj

EQ            = =

MOC       = /Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
UIC       = /Users/mariquitreventar/Qt/5.15.2/clang_64/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_NO_DEBUG -DQT_MULTIMEDIA_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
INCPATH       = -I. -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/AGL.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compilers: qrc_overarching.cpp moc_predefs.h moc_helpscreen.cpp moc_titular.cpp moc_gamesettings.cpp\
	 moc_playersettings.cpp moc_aboutus.cpp moc_tttgame.cpp\
	 moc_victory.cpp moc_draw.cpp moc_tourneygame.cpp
compiler_rcc_make_all: qrc_overarching.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_overarching.cpp
qrc_overarching.cpp: overarching.qrc \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/rcc \
		images/RexImage.png \
		images/BrentImage.jpg \
		styles/gamesettings.qss \
		styles/lorescreen.qss \
		styles/victory.qss \
		styles/tourneygame.qss \
		styles/draw.qss \
		styles/aboutus.qss \
		styles/titular.qss \
		styles/playersettings.qss \
		styles/tttgame.qss \
		styles/helpscreen.qss \
		music/Elephant.wav \
		music/Elephant.mp3 \
		fonts/SIFONN.otf
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/rcc -name overarching overarching.qrc -o qrc_overarching.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/features/data/dummy.cpp
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -pipe -stdlib=libc++ -O2 -std=gnu++11 -Wall -Wextra -dM -E -o moc_predefs.h /Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_helpscreen.cpp moc_titular.cpp moc_gamesettings.cpp moc_playersettings.cpp moc_aboutus.cpp moc_tttgame.cpp moc_victory.cpp moc_draw.cpp moc_tourneygame.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_helpscreen.cpp moc_titular.cpp moc_gamesettings.cpp moc_playersettings.cpp moc_aboutus.cpp moc_tttgame.cpp moc_victory.cpp moc_draw.cpp moc_tourneygame.cpp
moc_helpscreen.cpp: helpscreen.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib helpscreen.h -o moc_helpscreen.cpp

moc_titular.cpp: titular.h \
		helpscreen.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		gamesettings.h \
		gameoptions.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers/QMediaPlayer \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QSlider \
		playersettings.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QString \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QChar \
		aboutus.hpp \
		tttgame.hpp \
		victory.hpp \
		draw.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QPushButton \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib titular.h -o moc_titular.cpp

moc_gamesettings.cpp: gamesettings.h \
		gameoptions.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers/QMediaPlayer \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QSlider \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib gamesettings.h -o moc_gamesettings.cpp

moc_playersettings.cpp: playersettings.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QString \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QChar \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib playersettings.hpp -o moc_playersettings.cpp

moc_aboutus.cpp: aboutus.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib aboutus.hpp -o moc_aboutus.cpp

moc_tttgame.cpp: tttgame.hpp \
		victory.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QString \
		draw.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QPushButton \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QChar \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib tttgame.hpp -o moc_tttgame.cpp

moc_victory.cpp: victory.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QString \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib victory.hpp -o moc_victory.cpp

moc_draw.cpp: draw.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QString \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib draw.hpp -o moc_draw.cpp

moc_tourneygame.cpp: tourneygame.hpp \
		tttgame.hpp \
		victory.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QString \
		draw.hpp \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers/QPushButton \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers/QChar \
		moc_predefs.h \
		/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc
	/Users/mariquitreventar/Qt/5.15.2/clang_64/bin/moc $(DEFINES) --include /Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe/moc_predefs.h -I/Users/mariquitreventar/Qt/5.15.2/clang_64/mkspecs/macx-clang -I/Users/mariquitreventar/Desktop/ACodes/CPP_Files/QT_Work/Maybe -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtMultimedia.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtWidgets.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtGui.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtNetwork.framework/Headers -I/Users/mariquitreventar/Qt/5.15.2/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/10.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include -F/Users/mariquitreventar/Qt/5.15.2/clang_64/lib tourneygame.hpp -o moc_tourneygame.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean 

