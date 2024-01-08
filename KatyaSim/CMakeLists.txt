cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(
        KatyaSim1
        KatyaSim.cpp
        KatyaSim.h
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
)




add_executable(
    Katya
    my_sources/main.cpp
    my_sources/main.h
    my_sources/pch.cpp
    my_sources/pch.h
    my_sources/Application.cpp
    my_sources/Application.h
    
    my_sources/utils/imgui_widgets.h
    my_sources/utils/str_utils.h
    
    my_sources/elems/input.h
    my_sources/elems/light.h
    my_sources/elems/face.cpp
    my_sources/elems/face.h
    my_sources/elems/camera.h
    my_sources/elems/element.cpp
    my_sources/elems/element.h
    my_sources/elems/mesh.cpp
    my_sources/elems/mesh.h
    my_sources/elems/vertex_holder.cpp
    my_sources/elems/vertex_holder.h
    
    my_sources/mesh_import/import_base.h
    my_sources/mesh_import/import_obj.cpp
    my_sources/mesh_import/import_obj.h
    
    my_sources/window/window.h
    my_sources/window/jgl_window.cpp
    my_sources/window/jgl_window.h
    
    my_sources/render/opengl_buffer_manager.cpp
    my_sources/render/opengl_buffer_manager.h
    my_sources/render/opengl_context.cpp
    my_sources/render/render_base.h
    my_sources/render/opengl_context.h
    my_sources/render/ui_context.cpp
    my_sources/render/ui_context.h

    my_sources/ui/property_panel.cpp
    my_sources/ui/property_panel.h
    my_sources/ui/scene_view.cpp
    my_sources/ui/scene_view.h

    my_sources/shader/shader_util.cpp
    my_sources/shader/shader_util.h

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
        #imgui/ImFileBrowser.h
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

target_link_libraries(
        KatyaSim1
        igl::igl_glfw igl::igl_core igl::igl_opengl
        GLEW::GLEW
        OpenGL::GL
        glfw
        glm::glm
        assimp::assimp

)

