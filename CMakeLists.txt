cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
    wxmarkdownexitor
    VERSION 0.0.1
    DESCRIPTION "A wxWidgets based markdown editor"
    LANGUAGES CXX
)


set(WXWIDGETS_PATH "" CACHE PATH "Path to the wxWidgets installation")


if (WXWIDGETS_PATH)
        message(STATUS "Looking for wxWidgets in: ${wxWidgets_DIR}")
        find_package(wxWidgets REQUIRED COMPONENTS core base stc xml xrc webview
        HINTS ${WXWIDGETS_PATH}/lib/cmake/wxWidgets
        )
    else()
        find_package(wxWidgets REQUIRED COMPONENTS core base stc xml xrc webview)
endif()

# Debugging output to check the linked libraries
message(STATUS "wxWidgets libraries: ${wxWidgets_LIBRARIES}")

include(FetchContent)

FetchContent_Declare(
  maddy
  URL https://github.com/progsource/maddy/releases/download/1.3.0/maddy-src.zip
)
FetchContent_MakeAvailable(maddy)

configure_file(res/gui.xrc ${CMAKE_BINARY_DIR} COPYONLY)

if (wxWidgets_FOUND AND wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

# Add the executable
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/gui/wxMarkDownEditorGUI.cpp src/wxMarkDownEditormainFrame.cpp)

# Link wxWidgets libraries explicitly
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} maddy)
