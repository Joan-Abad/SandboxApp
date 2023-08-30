#include "SandboxApp.h"
#include "Graphics/Shaders/Shader.h"
#include "glad/glad.h"
#include <vector>
#include "Game/GameEntity.h"
#include <iostream>
#include "Window/WindowManager.h"
#include "Window/Viewport.h"
#include "Graphics/Buffers/VBO.h"
#include "Graphics/Buffers/VAO.h"
#include "Logging/Logger.h"
#include "Components/TransformComponent.h"
#include "Components/MeshComponent.h"
#include "Input/Input.h"

SandboxApp::SandboxApp() : YorkieEngineApp()
{
}

void SandboxApp::OnCreateApplicationCallback()
{
    Shader* uniformColorShader = new Shader("res/shaders/Cube.shader");
    Shader* secondCubeColorShader = new Shader("res/shaders/Cube.shader");
    Shader* secondSquareShader = new Shader("res/shaders/SecondCube.shader");
    Shader* defaultShader = new Shader("res/shaders/default.shader");
    Shader* secondDefaultShader = new Shader("res/shaders/secondTexture.shader");
    Shader* thirdDefaultShader = new Shader("res/shaders/ThirdTexture.shader");

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
    input = new Input(vp);

    TextureComponent* textureComponent = new TextureComponent(std::string("res/textures/Jolie.jpg"));
    textureComponent->AttachShader(*defaultShader);

    TextureComponent* secondTextureComponent = new TextureComponent(std::string("res/textures/mario64.jpg"));
    secondTextureComponent->AttachShader(*secondDefaultShader);
    
    TextureComponent* thirdTextureComponent = new TextureComponent(std::string("res/textures/eevee.jpg"));
    thirdTextureComponent->AttachShader(*thirdDefaultShader);

    GameEntity& entity = *vp.CreateEntity();
    entity.SetEntityLocation(3,4,-8);
    entity.AttachShader(defaultShader);
    entity.AddComponent<MeshComponent>(cubeVertices, cubeIndices, textureComponent);
    entity.entityName = "Cube default 1";

    GameEntity& secondDefaultEntity = *vp.CreateEntity();
    secondDefaultEntity.SetEntityLocation(-5, 3, -4);
    secondDefaultEntity.AttachShader(secondDefaultShader);
    secondDefaultEntity.AddComponent<MeshComponent>(cubeVertices, cubeIndices, secondTextureComponent);
    secondDefaultEntity.entityName = "Cube default 2";

    GameEntity& thirdDefaultEntity = *vp.CreateEntity();
    thirdDefaultEntity.SetEntityLocation(2, 10, 3);
    thirdDefaultEntity.AddComponent<MeshComponent>(cubeVertices, cubeIndices, thirdTextureComponent);
    thirdDefaultEntity.AttachShader(thirdDefaultShader);
    thirdDefaultEntity.entityName = "Cube default 3";
}

void SandboxApp::OnUpdate()
{
    YorkieEngineApp::OnUpdate();
    if (input->IsKeyPressed(EKeyboardKeys::KEY_1))
    {
        thirdRE->GetShader().Bind();
        thirdRE->GetShader().SetUniformVec4("color", { 1.0f, 0.0f, 0.0f, 1.0f });
        thirdRE->GetShader().Unbind();
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_2))
    {
        thirdRE->GetShader().Bind();
        thirdRE->GetShader().SetUniformVec4("color", { 0.0f, 1.0f, 0.0f, 1.0f });
        thirdRE->GetShader().Unbind();
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_3))
    {
        thirdRE->GetShader().Bind();
        thirdRE->GetShader().SetUniformVec4("color", {0.0f, 0.0f, 1.0f, 1.0f });
        thirdRE->GetShader().Unbind();
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_4))
    {
        thirdRE->GetShader().Bind();
        thirdRE->GetShader().SetUniformVec4("color", { sin(GetGameTime()), cos(GetGameTime()), 0.0f, 1.0f });
        thirdRE->GetShader().Unbind();
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_J))
        Logger::LogError("STOP");    
}

void SandboxApp::OnPostUpdate()
{
}
