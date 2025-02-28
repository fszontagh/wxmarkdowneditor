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
    find_package(wxWidgets REQUIRED COMPONENTS core base stc xml xrc webview
    HINTS ${WXWIDGETS_PATH}/lib/cmake/wxWidgets)
else()
    find_package(wxWidgets REQUIRED COMPONENTS core base stc xml xrc webview)
endif()

# Debugging output to check the linked libraries
message(STATUS "wxWidgets libraries: ${wxWidgets_LIBRARIES}")

set(CMARK_TESTS  OFF)
set(CMARK_SHARED  OFF)
set(CMARK_STATIC  ON)
add_subdirectory(third_party/cmark-gfm)

# Include cmark-gfm headers


# Configure file for wxWidgets
configure_file(res/gui.xrc ${CMAKE_BINARY_DIR} COPYONLY)

if (wxWidgets_FOUND AND wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

find_library(CMARK_GFM_LIB
    NAMES ${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm${CMAKE_STATIC_LIBRARY_SUFFIX}
    PATHS ${CMAKE_BINARY_DIR}/third_party/cmark-gfm/src)

    find_library(CMARK_GFM_LIB_EXTENSIONS
    NAMES ${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm-extensions${CMAKE_STATIC_LIBRARY_SUFFIX}
    PATHS ${CMAKE_BINARY_DIR}/third_party/cmark-gfm/extensions)

# Add the executable
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/gui/wxMarkDownEditorGUI.cpp src/wxMarkDownEditormainFrame.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC third_party/cmark-gfm/src third_party/cmark-gfm/extensions ${CMAKE_BINARY_DIR}/third_party/cmark-gfm/src)

# Link wxWidgets and cmark-gfm libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} ${CMARK_GFM_LIB} ${CMARK_GFM_LIB_EXTENSIONS})
