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
set(CMARK_GFM_PATH "" CACHE PATH "Path to the cmark-gfm installation")

if (WXWIDGETS_PATH)
    message(STATUS "Looking for wxWidgets in: ${WXWIDGETS_PATH}")
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

if (CMARK_GFM_PATH)

    message(STATUS "Looking for cmark-gfm in: ${CMARK_GFM_PATH}")
    set(CMARK_GFM_INSTALL_DIR "${CMARK_GFM_PATH}")
    set(CMARK_GFM_LIB_DIR "${CMARK_GFM_INSTALL_DIR}/lib")
    set(CMARK_GFM_INCLUDE_DIR "${CMARK_GFM_INSTALL_DIR}/include")
    set(CMARK_GFM_NAME "${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm${CMAKE_STATIC_LIBRARY_SUFFIX}")
    set(CMARK_GFM_EXT_NAME "${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm-extensions${CMAKE_STATIC_LIBRARY_SUFFIX}")

    # if not unix
    if (WIN32)
        set(CMARK_GFM_NAME "${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm_static${CMAKE_STATIC_LIBRARY_SUFFIX}")
        set(CMARK_GFM_EXT_NAME "${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm-extensions_static${CMAKE_STATIC_LIBRARY_SUFFIX}")
    endif()


    include_directories(${CMARK_GFM_INCLUDE_DIR})

    set(CMARK_GFM_LIB "${CMARK_GFM_LIB_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm${CMAKE_STATIC_LIBRARY_SUFFIX}")
    set(CMARK_GFM_EXT_LIB "${CMARK_GFM_LIB_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm-extensions${CMAKE_STATIC_LIBRARY_SUFFIX}")

    message(STATUS "cmark-gfm libraries: ${CMARK_GFM_LIB}")
    message(STATUS "cmark-gfm-extensions libraries: ${CMARK_GFM_EXT_LIB}")
    if (NOT EXISTS ${CMARK_GFM_LIB})
        message(FATAL_ERROR "Could not find ${CMAKE_STATIC_LIBRARY_PREFIX}cmark-gfm${CMAKE_STATIC_LIBRARY_SUFFIX} in ${CMARK_GFM_LIB}")
    endif()

    if (NOT EXISTS ${CMARK_GFM_EXT_LIB})
        message(FATAL_ERROR "Could not find libcmark-gfm-extensions.a in ${CMARK_GFM_EXT_LIB}")
    endif()

endif()

find_package(PkgConfig QUIET)

    if (PKG_CONFIG_FOUND)
        pkg_check_modules(CMARK_GFM REQUIRED libcmark-gfm)

        string(FIND "${CMARK_GFM_LIBRARIES}" "cmark-gfm-extensions" CMARK_EXT_FOUND)
        if(CMARK_EXT_FOUND EQUAL -1)
            message(FATAL_ERROR "libcmark-gfm-extensions not found!")
        endif()

        include_directories(${CMARK_GFM_INCLUDE_DIRS})
        link_directories(${CMARK_GFM_LIBRARY_DIRS})
        add_definitions(${CMARK_GFM_CFLAGS_OTHER})
    endif()



# Add the executable
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/gui/wxMarkDownEditorGUI.cpp src/wxMarkDownEditormainFrame.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC third_party/cmark-gfm/src third_party/cmark-gfm/extensions ${CMAKE_BINARY_DIR}/third_party/cmark-gfm/src)

# Link wxWidgets and cmark-gfm libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} ${CMARK_GFM_LIBRARIES})
