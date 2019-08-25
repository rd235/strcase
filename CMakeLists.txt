cmake_minimum_required(VERSION 2.6)
include(GNUInstallDirs)

install(FILES strcase.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES strcase.3
		DESTINATION ${CMAKE_INSTALL_MANDIR}/man3)

