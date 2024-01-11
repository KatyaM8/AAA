#include <iostream>
//#include <GL/glew.h>

//#include <GLFW/glfw3.h>

//#include <igl/readOFF.h>
#include <igl/readOBJ.h>
#include <igl/opengl/glfw/Viewer.h>
#include <imgui.h>

#include <imgui_impl_glfw.h>

#include <imgui_impl_opengl3.h>

#include "ImFileBrowser.h"


static void error(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main(int, char**)
{

    igl::opengl::glfw::Viewer viewer;

    //viewer.data().set_mesh(V, F);
    viewer.launch_init();
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int width = mode->width;
    int height = mode->height;
    glfwSetWindowSize(viewer.window, width / 2, height);
    glfwSetWindowPos(viewer.window, width * 0.5f, 0);


    // glfwSetErrorCallback(error);
    //if (!glfwInit())
      //  return 1;

//#if defined(IMGUI_IMPL_OPENGL_ES2)
    //const char* glsl_version = "#version 100";
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
//#elif defined(APPLE)
   // const char* glsl_version = "#version 150";
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
//#else
  //  const char* glsl_version = "#version 130";
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//#endif

    GLFWwindow* window = glfwCreateWindow(mode->width*0.5f, mode->height, "Simur", nullptr, nullptr);
    glfwSetWindowPos(window, 0, 0);
    if (window == nullptr)
        return 1;
    //glfwMakeContextCurrent(window);
    //glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (io, window, true);

    // Инициализация ImGui для работы с OpenGL и GLFW
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    //ImGui_ImplGlfw_InitForOpenGL(viewer.window(), true);
    ImGui_ImplOpenGL3_Init("#version 410");

    // Our state
    //bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    std::vector<std::pair<int, std::string>> data;

    ImGui::FileBrowser FileDialog(ImGuiFileBrowserFlags_ConfirmOnEnter);
    //fileDialog.SetTypeFilters({ ".gitignore" });
    FileDialog.SetTitle("Open mesh");
    //FileDialog.SetTypeFilters({ ".off", ".obj" });

    //std::string workPath = "";
    //std::string readPath = "";

    bool open = 0;
    ImFont* previousFont = ImGui::GetFont();


    while (!glfwWindowShouldClose(window) && !glfwWindowShouldClose(viewer.window))
    {
        glfwMakeContextCurrent(viewer.window);
        processInput(viewer.window);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        viewer.draw();
        glfwSwapBuffers(viewer.window);
        glfwPollEvents();



        glfwMakeContextCurrent(window);
        processInput(window);
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        //int x, y;
        glfwGetWindowSize(window, &width, &height);

        ImVec2 window_size = ImVec2(static_cast<float>(width), static_cast<float>(height));
        ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);



        ImGui::Begin("Properties");
        ImGui::SetWindowFontScale(5);
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
        if (ImGui::CollapsingHeader("Texture"))
        {
            //ImGui::ColorPicker3("Color", (float*)&mesh->mColor, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_DisplayRGB);
            //ImGui::SliderFloat("Roughness", &mesh->mRoughness, 0.0f, 1.0f);
            //ImGui::SliderFloat("Metallic", &mesh->mMetallic, 0.0f, 1.0f);
        }
        ImGui::End();
        if (FileDialog.HasSelected()) {
            Eigen::MatrixXd V;
            Eigen::MatrixXi F;
            //flagopen = 0;



            //glfwMakeContextCurrent(viewer.window);
            std::string file_path = FileDialog.GetSelected().string();
            FileDialog.Close();

            viewer.data().clear();
            igl::readOBJ(file_path, V, F);


            viewer.data().set_mesh(V, F);
            //glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
            //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            FileDialog.ClearSelected();

        }
        //glfwSetFont();

        //ImGui::SetNextWindowPos(ImVec2((float)(x) / 2, 0), 0, ImVec2(0, 0));
        //ImGui::SetNextWindowSize(ImVec2((float)(x) / 2, y), 0);


        //ImGui::Begin("Main");
        //ImGui::SetWindowFontScale((float)(x) / 1920);

        //ImGui::SameLine();
        // bool op = false;

        //if (ImGui::Button("Open..."))
        //{
        //    FileDialog.Open();

        //}

        //FileDialog.Display();




        //ImGui::End();





        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}