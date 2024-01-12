cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#add_executable(
        #KatyaSim1
        #KatyaSim.cpp
        #KatyaSim.h
        #imgui/imgui.h
        #imgui/imgui.cpp
        #imgui/imconfig.h
        #imgui/imgui_demo.cpp
       # imgui/imgui_draw.cpp
       # imgui/imgui_internal.h
       # imgui/imgui_widgets.cpp
        #imgui/imstb_rectpack.h
       # imgui/imstb_textedit.h
       # imgui/imstb_truetype.h

       # imgui/backends/imgui_impl_glfw.h
      #  imgui/backends/imgui_impl_glfw.cpp

       # imgui/backends/imgui_impl_opengl3.h
       # imgui/backends/imgui_impl_opengl3.cpp
       # imgui/backends/imgui_impl_opengl3_loader.h
      #  ImFileBrowser.h
#)




add_executable(
    Katya
    my_sources/main.cpp
    my_sources/main.h
    imgui/imgui.h
    imgui/imgui.cpp
    imgui/imconfig.h
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_internal.h
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h

    imgui/backends/imgui_impl_glfw.h
    imgui/backends/imgui_impl_glfw.cpp

    imgui/backends/imgui_impl_opengl3.h
    imgui/backends/imgui_impl_opengl3.cpp
    imgui/backends/imgui_impl_opengl3_loader.h
        ImFileBrowser.h
        my_sources/morph.h
        my_sources/morph.cpp
        my_sources/morph.h
)


find_package(OpenGL REQUIRED)

find_package(glfw3 CONFIG REQUIRED)

find_package(glm REQUIRED)

find_package(assimp REQUIRED)

find_package(glew REQUIRED)

find_package(libigl REQUIRED)

target_include_directories(Katya PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/imgui>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/my_sources/>
)


target_link_libraries(
        Katya
        GLEW::GLEW
        OpenGL::GL
        glfw
        glm::glm
        assimp::assimp
        igl::igl_core igl::igl_opengl igl::igl_glfw
)

#target_link_libraries(
       # igl::igl_glfw igl::igl_core igl::igl_opengl
       # GLEW::GLEW
       # OpenGL::GL
       # glfw
      #  glm::glm
      #  assimp::assimp

#)

