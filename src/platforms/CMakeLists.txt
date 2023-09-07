project(platforms_utils)
if(WIN32)
    file(GLOB platform_srcs win/*)
    message("----- Library platform is WIN32 add include files: \n${platform_srcs}")
endif()
add_library(platforms_utils ${platform_srcs})
target_include_directories(platforms_utils PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(platforms_utils PRIVATE "..")
target_precompile_headers(platforms_utils PRIVATE "../pch.hpp")
target_link_libraries(platforms_utils PRIVATE toy::generic toy::cpperclip lib::gui_utils Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Core)


