cmake_minimum_required(VERSION 3.5)

project(TinyCopyQ VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Gui Core)
function(fetch_content_check content_name)
    FetchContent_MakeAvailable(${content_name})
    message("---- ${content_name}_SOURCE_DIR is found in ${${content_name}_SOURCE_DIR}")
endfunction()
include(FetchContent)
FetchContent_Declare(
    toy
    GIT_REPOSITORY https://github.com/Michaelzhouisnotwhite/My-CXX-Small-Toys
    GIT_TAG main
)

FetchContent_Declare(
    myguiutils
    GIT_REPOSITORY https://github.com/Michaelzhouisnotwhite/MyGuiUtils.git
    GIT_TAG main
)

fetch_content_check(myguiutils)
fetch_content_check(toy)
file(GLOB_RECURSE  srcs "src/*")
message("project files in src/: ${srcs}" )
set(PROJECT_SOURCES
        ${srcs}
        ./ui/clipboardmainwindow.ui

)
#at_add_resources()
qt_add_resources(TinyCopyQ "image" PREFIX "/icon" FILES ui/icon.png)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TinyCopyQ
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TinyCopyQ APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TinyCopyQ SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TinyCopyQ
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(TinyCopyQ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Core)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TinyCopyQ)
endif()
set_target_properties(TinyCopyQ PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

include(GNUInstallDirs)
install(TARGETS TinyCopyQ
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TinyCopyQ)
endif()

target_include_directories(TinyCopyQ PRIVATE ${PROJECT_SOURCE_DIR} src ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_autogen/include)
target_link_libraries(TinyCopyQ PRIVATE toy::generic toy::cpperclip lib::gui_utils)
target_precompile_headers(TinyCopyQ PRIVATE src/pch.hpp)
