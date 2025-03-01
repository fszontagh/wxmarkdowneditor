cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

project(
    wxmarkdowneditor
    VERSION 0.0.1
    DESCRIPTION "A wxWidgets based markdown editor"
    LANGUAGES CXX
)

set(WXWIDGETS_PATH "" CACHE PATH "Path to the wxWidgets installation")

if (WXWIDGETS_PATH)
    message(STATUS "Looking for wxWidgets in: ${wxWidgets_DIR}")
    find_package(wxWidgets REQUIRED core base stc xml xrc webview
    HINTS ${WXWIDGETS_PATH}/lib/cmake/wxWidgets)
else()
    find_package(wxWidgets REQUIRED gl core base stc webview OPTIONAL_COMPONENTS net)
    include(${wxWidgets_USE_FILE})
endif()

# Debugging output to check the linked libraries
message(STATUS "wxWidgets libraries: ${wxWidgets_LIBRARIES}")

if (wxWidgets_FOUND AND wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

find_package(PkgConfig REQUIRED)


pkg_check_modules(CMARK_GFM REQUIRED libcmark-gfm)

string(FIND "${CMARK_GFM_LIBRARIES}" "cmark-gfm-extensions" CMARK_EXT_FOUND)
if(CMARK_EXT_FOUND EQUAL -1)
    message(FATAL_ERROR "libcmark-gfm-extensions not found!")
endif()

include_directories(${CMARK_GFM_INCLUDE_DIRS})
link_directories(${CMARK_GFM_LIBRARY_DIRS})
add_definitions(${CMARK_GFM_CFLAGS_OTHER})

# Add the executable
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/gui/wxMarkDownEditorGUI.cpp src/wxMarkDownEditormainFrame.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC third_party/cmark-gfm/src third_party/cmark-gfm/extensions ${CMAKE_BINARY_DIR}/third_party/cmark-gfm/src)

# Link wxWidgets and cmark-gfm libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} ${CMARK_GFM_LIBRARIES})
