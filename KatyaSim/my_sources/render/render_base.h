#pragma once

#include "../elems/vertex_holder.h"

#include "../window/window.h"
#pragma once

// Std includes
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

// GL includes
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
namespace nrender
{
  class VertexIndexBuffer
  {
  public:
    VertexIndexBuffer() : mVBO{ 0 }, mVAO{ 0 }, mIBO{ 0 }
    {}

    virtual void create_buffers(const std::vector<nelems::VertexHolder>& vertices, const std::vector<unsigned int>& indices) = 0;

    virtual void delete_buffers() = 0;

    virtual void bind() = 0;

    virtual void unbind() = 0;

    virtual void draw(int index_count) = 0;

  protected:
    GLuint mVBO;
    GLuint mVAO;
    GLuint mIBO;
  };

  class FrameBuffer
  {
  public:
    FrameBuffer() : mFBO { 0 }, mDepthId {0}
    {}

    virtual void create_buffers(int32_t width, int32_t height) = 0;

    virtual void delete_buffers() = 0;

    virtual void bind() = 0;

    virtual void unbind() = 0;

    virtual uint32_t get_texture() = 0;

  protected:
    uint32_t mFBO = 0;
    uint32_t mTexId = 0;
    uint32_t mDepthId = 0;
    int32_t mWidth = 0;
    int32_t mHeight = 0;
  };

  class RenderContext
  {

  public:

    RenderContext() : mWindow(nullptr) {}

    virtual bool init(nwindow::IWindow* window)
    {
      mWindow = window;
      return true;
    }

    virtual void pre_render() = 0;

    virtual void post_render() = 0;

    virtual void end() = 0;

  protected:
    nwindow::IWindow* mWindow;
  };
}
