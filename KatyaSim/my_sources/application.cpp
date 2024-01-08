#include "pch.h"

#include "application.h"

#include "window/jgl_window.h"

Application::Application(const std::string& app_name)
{
  mWindow = std::make_unique<nwindow::GLWindow>();
  mWindow->init(1920, 1080, app_name);

}

//вызывается метод render(), в котором запускается основной цикл программы
void Application::loop()
{
  while (mWindow->is_running())
  {
      mWindow->render();
  }
}