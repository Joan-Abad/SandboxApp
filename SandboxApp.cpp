#include "SandboxApp.h"
#include "Shaders/Shader.h"
#include "glad/glad.h"
#include <vector>
#include "Rendering/RenderObject.h"
#include <iostream>
#include "Rendering/Renderer.h"
#include "Window/Public/WindowManager.h"
#include "Window/Public/Viewport.h"
#include "Rendering/Buffers/VBO.h"
#include "Rendering/Buffers/VAO.h"
#include "Logging/Public/Logger.h"
#include "Components/TransformComponent.h"

SandboxApp::SandboxApp() : YorkiEngineApp()
{
}

void SandboxApp::OnCreateApplicationCallback()
{
    Shader* squareShader = new Shader("res/shaders/Cube.shader");
    Shader* secondSquareShader = new Shader("res/shaders/SecondCube.shader");

    std::vector<Vertex> pyramidVertices = {
        // Base
        {glm::vec3(-0.5f, 0.0f, -0.5f)},
        {glm::vec3(0.5f, 0.0f, -0.5f)},
        {glm::vec3(0.5f, 0.0f, 0.5f)},
        {glm::vec3(-0.5f, 0.0f, 0.5f)},

        // Apex
        {glm::vec3(0.0f, 1.0f, 0.0f)}
    };

    std::vector<unsigned int> pyramidIndices = {
        // Base
        0, 1, 2,
        2, 3, 0,

        // Side faces
        0, 4, 1,
        1, 4, 2,
        2, 4, 3,
        3, 4, 0
    };

    std::vector<Vertex> cubeVertices = {
        // Front face
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f)), // Bottom-left
        Vertex(glm::vec3(0.5f, -0.5f,  0.5f)), // Bottom-right
        Vertex(glm::vec3(0.5f,  0.5f,  0.5f)), // Top-right
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f)), // Top-left

        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f)), // Bottom-left
        Vertex(glm::vec3(0.5f, -0.5f, -0.5f)), // Bottom-right
        Vertex(glm::vec3(0.5f,  0.5f, -0.5f)), // Top-right
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f)), // Top-left
        
        // Right face
        Vertex(glm::vec3(0.5f, -0.5f,  0.5f)), // Bottom-left
        Vertex(glm::vec3(0.5f, -0.5f, -0.5f)), // Bottom-right
        Vertex(glm::vec3(0.5f,  0.5f, -0.5f)), // Top-right
        Vertex(glm::vec3(0.5f,  0.5f,  0.5f)), // Top-left
        
        // Left face
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f)), // Bottom-left
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f)), // Bottom-right
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f)), // Top-right
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f)), // Top-left

        // Top face
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f)), // Bottom-left
        Vertex(glm::vec3(0.5f,  0.5f,  0.5f)), // Bottom-right
        Vertex(glm::vec3(0.5f,  0.5f, -0.5f)), // Top-right
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f)), // Top-left

        // Bottom face
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f)), // Bottom-left
        Vertex(glm::vec3(0.5f, -0.5f, -0.5f)), // Bottom-right
        Vertex(glm::vec3(0.5f, -0.5f,  0.5f)), // Top-right
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f))  // Top-left
    };

    std::vector<unsigned int> cubeIndices = {
        // Front face
        0, 1, 2,
        2, 3, 0,

        // Back face
        4, 5, 6,
        6, 7, 4,

        // Right face
        8, 9, 10,
        10, 11, 8,

        // Left face
        12, 13, 14,
        14, 15, 12,

        // Top face
        16, 17, 18,
        18, 19, 16,

        // Bottom face
        20, 21, 22,
        22, 23, 20
    };

    

    Viewport& vp = WindowManager::GetActiveWindow<Viewport>();
    input = new Controller(vp);

    ro = new RenderObject("Cube", cubeVertices, cubeIndices, *squareShader);
    vp.AddRenderObject(*ro);
    ro->SetPosition(-7,-4, -6);

    secondRo = new RenderObject("Cube2", cubeVertices, cubeIndices);
    vp.AddRenderObject(*secondRo);

    thirdRo = new RenderObject("Pyramid", pyramidVertices, pyramidIndices, *secondSquareShader);
    vp.AddRenderObject(*thirdRo);
    thirdRo->SetPosition(2,7,-2);

    auto &TC = ro->AddComponent<TransformComponent>();
    TC.i = 14;

    thirdRo->GetShader().Bind();
    thirdRo->GetShader().SetUniformVec4("color", { 0.41f, 0.10f, 0.66f, 1.0f });
    thirdRo->GetShader().Unbind();

    ro->GetShader().Bind();
    ro->GetShader().SetUniformVec4("color", { 0.3f, 0.54f, 0.07f, 1.0f });
    ro->GetShader().Unbind();
}

void SandboxApp::OnPreDraw()
{
    
    
    if (input->IsKeyPressed(EKeyboardKeys::KEY_1))
    {
        thirdRo->GetShader().Bind();
        thirdRo->GetShader().SetUniformVec4("color", { 1.0f, 0.0f, 0.0f, 1.0f });
        thirdRo->GetShader().Unbind();
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_2))
    {
        thirdRo->GetShader().Bind();
        thirdRo->GetShader().SetUniformVec4("color", { 0.0f, 1.0f, 0.0f, 1.0f });
        thirdRo->GetShader().Unbind();
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_3))
    {
        thirdRo->GetShader().Bind();
        thirdRo->GetShader().SetUniformVec4("color", {0.0f, 0.0f, 1.0f, 1.0f });
        thirdRo->GetShader().Unbind();
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_4))
    {
        thirdRo->GetShader().Bind();
        thirdRo->GetShader().SetUniformVec4("color", { sin(GetTime()), cos(GetTime()), 0.0f, 1.0f });
        thirdRo->GetShader().Unbind();
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_J))
        Logger::LogError("STOP");



    
}

void SandboxApp::OnPostDraw()
{
}
