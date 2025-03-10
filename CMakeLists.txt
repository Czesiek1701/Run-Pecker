cmake_minimum_required(VERSION 3.5)

project(pecker_vt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Test Gui Widgets REQUIRED)

enable_testing()

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(pecker_vt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        game.h game.cpp
        resources.qrc
        gameboard.h gameboard.cpp

        creature.h creature.cpp

        gamepage.h gamepage.cpp gamepage.ui
        gamepause.h gamepause.cpp gamepause.ui
        player.h player.cpp
        bot.h bot.cpp
        background.h background.cpp
        mapentity.h mapentity.cpp
        nonpenetratingwall.h nonpenetratingwall.cpp
        nonpenetrationmanager.h nonpenetrationmanager.cpp
        ibehaviourmanager.h ibehaviourmanager.cpp
        playerfightmanager.h playerfightmanager.cpp
        entityregistry.h entityregistry.cpp
        gameboardbuilder.h gameboardbuilder.cpp
        gameboarddirector.h gameboarddirector.cpp


    )


# Define target properties for Android with Qt 6 as:
#    set_property(TARGET pecker_vt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(pecker_vt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(pecker_vt
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_link_libraries(pecker_vt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.pecker_vt)
endif()
set_target_properties(pecker_vt PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS pecker_vt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(pecker_vt)
endif()


# ===========================  TESTS  =========================================================

enable_testing()

qt_add_executable(mytest

    tst_GameBoard.cpp

    mainwindow.cpp mainwindow.h mainwindow.ui
    game.h game.cpp
    resources.qrc
    gameboard.h gameboard.cpp
    creature.h creature.cpp
    gamepage.h gamepage.cpp gamepage.ui
    gamepause.h gamepause.cpp gamepause.ui
    player.h player.cpp
    bot.h bot.cpp
    background.h background.cpp
    mapentity.h mapentity.cpp
    nonpenetratingwall.h nonpenetratingwall.cpp
    nonpenetrationmanager.h nonpenetrationmanager.cpp
    ibehaviourmanager.h ibehaviourmanager.cpp
    playerfightmanager.h playerfightmanager.cpp
    entityregistry.h
    entityregistry.cpp
    gameboardbuilder.h gameboardbuilder.cpp
    gameboarddirector.h gameboarddirector.cpp


)
set_source_files_properties(tst_GameBoard.cpp PROPERTIES SKIP_AUTOMOC OFF)

target_link_libraries(mytest PRIVATE Qt6::Widgets)
target_link_libraries(mytest PRIVATE Qt6::Test)

add_test(NAME mytest COMMAND mytest)
