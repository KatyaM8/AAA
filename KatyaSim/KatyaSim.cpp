#include <iostream>


#include <GL/glew.h>
#include <igl/readOFF.h>
//#include <igl/opengl/glfw/Viewer.h>
#include <imgui.h>

#include <imgui_impl_glfw.h>

#include <imgui_impl_opengl3.h>

#include "ImFileBrowser.h"

//#include <assimp/Importer.hpp>
#include <assimp/scene.h>
//#include <assimp/postprocess.h>


#include <GLFW/glfw3.h>

//#include <fstream>
//#include <vector>
//#include <string>
//#include <filesystem>
//#include <igl/embree/EmbreeRenderer.h>
//#include <GLFW/glfw3.h>

//#include <imgui.h>
//#include <imgui_impl_glfw.h>
//#include <imgui_impl_opengl3.h>

//#include <igl/opengl/glfw/Viewer.h>
//#include <stdio.h>

//#include "ImFileBrowser.h"
//#include "imGuiColorTextEdit/TextEditor.h"
//#include <igl/readOFF.h>
//#include <Eigen/Core>


#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif



#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif


static void error(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}


int main(int, char**)
{
    glfwSetErrorCallback(error);
    if (!glfwInit())
        return 1;

#if defined(IMGUI_IMPL_OPENGL_ES2)
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(APPLE)
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    GLFWwindow* window = glfwCreateWindow(2520, 1680, "Simur", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);


    // Our state
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    std::vector<std::pair<int, std::string>> data;

    ImGui::FileBrowser FileDialog(ImGuiFileBrowserFlags_ConfirmOnEnter);
    //fileDialog.SetTypeFilters({ ".gitignore" });
    FileDialog.SetTitle("Open mesh");
    FileDialog.SetTypeFilters({ ".off", ".obj" });
    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    std::string workPath = "";
    std::string readPath = "";

    bool open = 0;
    ImFont* previousFont = ImGui::GetFont();

#ifdef EMSCRIPTEN
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!glfwWindowShouldClose(window))
#endif
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        int x, y;
        glfwGetWindowSize(window, &x, &y);

        ImGui::SetNextWindowPos(ImVec2(0, 0), 0, ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2((float)(x) / 2, y), 0);





        ImGui::Begin("Properties");
        ImGui::SetWindowFontScale((float)(x) / 1920);
        if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen))
        {

            if (ImGui::Button("Open..."))
            {
                FileDialog.SetTitle("Выбор 3D-модели");

                FileDialog.SetTypeFilters({".obj", ".off"}); // Поддерживаемые форматы моделей
                FileDialog.Open();

            }
            ImGui::SameLine(0, 5.0f);
            ImGui::Text("< ... >");
        }
        FileDialog.Display();
        ImGui::End();

        //glfwSetFont();

        ImGui::SetNextWindowPos(ImVec2((float)(x) / 2, 0), 0, ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2((float)(x) / 2, y), 0);


        ImGui::Begin("Main");
        ImGui::SetWindowFontScale((float)(x) / 1920);

        ImGui::SameLine();
        bool op = false;

        if (ImGui::Button("Open..."))
        {
            FileDialog.Open();

        }

        FileDialog.Display();


        //auto cpos = editor.GetCursorPosition();

        ImGui::End();
        if (FileDialog.HasSelected())
        {
            std::string file_path = FileDialog.GetSelected().string();
            FileDialog.Close();
            //igl::readOFF(file_path, V, F);
            //igl::opengl::glfw::Viewer viewer;
            //viewer.data().set_mesh(V, F);
            //viewer.launch();

        }




        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
#ifdef EMSCRIPTEN
    EMSCRIPTEN_MAINLOOP_END;
#endif

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}