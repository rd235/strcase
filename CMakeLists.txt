cmake_minimum_required(VERSION 3.12)
include(GNUInstallDirs)
project(strcase
    VERSION 0.0.1
    DESCRIPTION "Multiway branch (switch) for short strings in C (in one header file)"
    HOMEPAGE_URL "https://github.com/rd235/strcase")

install(FILES strcase.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES strcase.3
		DESTINATION ${CMAKE_INSTALL_MANDIR}/man3)

