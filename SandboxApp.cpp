#include "SandboxApp.h"
#include "Shaders/Shader.h"
#include "glad/glad.h"
#include <vector>
#include "Rendering/RenderObject.h"
#include <iostream>
#include "Rendering/RenderingSystem.h"
#include "Window/Public/WindowManager.h"
#include "Window/Public/Viewport.h"
#include "Rendering/Buffers/VBO.h"
#include "Rendering/Buffers/VAO.h"

SandboxApp::SandboxApp() : YorkiEngineApp()
{
}

void SandboxApp::OnCreateApplicationCallback()
{
    Shader triangleShader("res/shaders/Triangle.shader");

    std::vector<float>vertices = {
        // positions       
         0.5f, -0.5f, 0.0f,// bottom right
        -0.5f, -0.5f, 0.0f,// bottom left
         0.0f,  0.5f, 0.0f,// top 
    };

    RenderObject* triangle = new RenderObject;
    triangle->AttachShader(triangleShader);
    
    VBO* vbo = new VBO(vertices, 3, triangle->GetVAO());
    triangle->AddVBOBuffer(*vbo);
    

    Window* window = &WindowManager::GetActiveWindow();
    Viewport* viewport = dynamic_cast<Viewport*>(window);
    viewport->AddRenderObject(*triangle);
    int i = 0; 
    //triangle->buffer.AddBufferData(vertices);

    //triangle->AttachShader(triangleShader);
}

void SandboxApp::OnPreDraw()
{
}

void SandboxApp::OnPostDraw()
{
}
