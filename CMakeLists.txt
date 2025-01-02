cmake_minimum_required( VERSION 3.5 )

project( QStyleIconLister VERSION 1.0 LANGUAGES CXX )

set( CMAKE_AUTOUIC ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( QT NAMES Qt6 REQUIRED COMPONENTS Widgets )
find_package( Qt6 REQUIRED COMPONENTS Widgets )
qt_standard_project_setup()

set( CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}" )
set( PROJECT_SOURCES
        QStyleIconLister.cpp
		QStyleStandardIcon.h
		QStyleStandardIcon.cpp
		FlowLayout.h
		FlowLayout.cpp
)

if ( 6 LESS_EQUAL ${QT_VERSION_MAJOR} )
    qt_add_executable( QStyleIconLister
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QStyleIconLister APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if( ANDROID )
        add_library( QStyleIconLister SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable( QStyleIconLister
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions( QStyleIconLister PUBLIC PROJECT_NAME="${CMAKE_PROJECT_NAME}" )
target_link_libraries( QStyleIconLister  PRIVATE Qt${QT_VERSION_MAJOR}::Widgets )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set( BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER tom.examples.QStyleIconLister )
endif()
set_target_properties( QStyleIconLister PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS QStyleIconLister
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if( QT_VERSION_MAJOR EQUAL 6 )
    qt_finalize_executable( QStyleIconLister )
endif()

qt_generate_deploy_app_script(
    TARGET QStyleIconLister
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install( SCRIPT ${deploy_script} )

include( CPack )
if ( MSVC AND CMAKE_MAKE_PROGRAM MATCHES "ninja" )
	message( NOTICE "Ninjabuild in MSVC! => adding custom packaging targets..." )
	add_custom_target( Ninja_package COMMAND ${CMAKE_MAKE_PROGRAM} "package"
		#COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}-${PROJECT_VERSION}-${CPACK_SYSTEM_NAME}.exe"
		DEPENDS QStyleIconLister USES_TERMINAL
		COMMENT "Create installer package ..."
	)
endif()