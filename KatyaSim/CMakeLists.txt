set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(KatyaSim KatyaSim.cpp KatyaSim.h)

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
)


SET(CMAKE_TOOLCHAIN_FILE "C:/Users/Katya/vcpkg/scripts/buildsystems/vcpkg.cmake")
include(C:/Users/Katya/vcpkg/scripts/buildsystems/vcpkg.cmake)

#find_package(ImGui CONFIG REQUIRED)

find_package(OpenGL REQUIRED)

find_package(glfw3 CONFIG REQUIRED)

find_package(glm REQUIRED)

find_package(assimp REQUIRED)

find_package(glew REQUIRED)

include(FetchContent)

FetchContent_Declare(
imgui
GIT_REPOSITORY https://github.com/ocornut/imgui.git
GIT_TAG v1.90
SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imguilib
)

FetchContent_MakeAvailable(imgui)

add_library(imgui STATIC
${imgui_SOURCE_DIR}/imgui.cpp
${imgui_SOURCE_DIR}/imgui_demo.cpp
${imgui_SOURCE_DIR}/imgui_draw.cpp
${imgui_SOURCE_DIR}/imgui_widgets.cpp
)
target_include_directories(imgui PUBLIC
$<BUILD_INTERFACE:${imgui_SOURCE_DIR}>
$<INSTALL_INTERFACE:include>
)


target_link_libraries(
    Katya
    GLEW::GLEW
    OpenGL::GL 
    imgui
    glfw 
    glm::glm 
    assimp::assimp  
)


#set(ImGui_DIR "C:/tit/cmake-imgui/build/dist/lib/cmake")
#list(APPEND CMAKE_PREFIX_PATH ${ImGui_DIR})



#add_library(KatyaSetup INTERFACE) # удобная хрень. можешь почитать, вкратце - просто передает настройки

#target_link_libraries(
  #  KatyaSetup INTERFACE
 #   OpenGL::GL 
 #   ImGui::imgui 
 #   glfw 
#    glm::glm 
#    assimp::assimp
#    GLEW::GLEW
#)


#target_link_libraries(KatyaSim KatyaSetup)
#target_include_directories(KatyaSim PUBLIC .)

#target_link_libraries(Katya KatyaSetup)
#target_include_directories(Katya PUBLIC my_sources)





