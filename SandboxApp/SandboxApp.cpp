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
#include "Lighting/BasicLight.h"
#include "Graphics/Primitives/Cube.h"

SandboxApp::SandboxApp() : YorkieEngineApp()
{
}

void SandboxApp::OnCreateApplicationCallback()
{
    Shader* defaultShader = new Shader("res/shaders/default.shader");

    //Shader* firstTextureShader = new Shader("res/shaders/CubeTexture.shader");
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
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 1.0f)), // Bottom-left
        Vertex(glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 1.0f)), // Bottom-right
        Vertex(glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 1.0f)), // Top-right
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 1.0f)), // Top-left

        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f)), // Bottom-left
        Vertex(glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f)), // Bottom-right
        Vertex(glm::vec3(0.5f,  0.5f, -0.5f),   glm::vec3(0.0f, 0.0f, -1.0f)), // Top-right
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f)), // Top-left

        // Right face                          
        Vertex(glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec3(1.0f, 0.0f, 0.0f)), // Bottom-left
        Vertex(glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(1.0f, 0.0f, 0.0f)), // Bottom-right
        Vertex(glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(1.0f, 0.0f, 0.0f)), // Top-right
        Vertex(glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(1.0f, 0.0f, 0.0f)), // Top-left

        // Left face                            
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f)), // Bottom-left
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f)), // Bottom-right
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f)), // Top-right
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f)), // Top-left

        // Top face                             
        Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 1.0f, 0.0f)), // Bottom-left
        Vertex(glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 1.0f, 0.0f)), // Bottom-right
        Vertex(glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 1.0f, 0.0f)), // Top-right
        Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f)), // Top-left

        // Bottom face                          
        Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(0.0f, -1.0f, 0.0f)),  // Bottom-left
        Vertex(glm::vec3(0.5f, -0.5f, -0.5f),    glm::vec3(0.0f, -1.0f, 0.0f)),  // Bottom-right
        Vertex(glm::vec3(0.5f, -0.5f,  0.5f),    glm::vec3(0.0f, -1.0f, 0.0f)),   // Top-right
        Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),   glm::vec3(0.0f, -1.0f, 0.0f))   // Top-left
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

    //First Texture

    TextureComponent* jolieTexture = new TextureComponent(std::string("res/textures/Jolie.jpg"));
    jolieTexture->AttachShader(*secondDefaultShader);

    TextureComponent* floorTexture = new TextureComponent(std::string("res/textures/floor.jpg"));
    floorTexture->AttachShader(*secondDefaultShader);

    //Second Texture

    TextureComponent* secondTextureComponent = new TextureComponent(std::string("res/textures/mario64.jpg"));
    secondTextureComponent->AttachShader(*secondDefaultShader);
    
    //Third Texture

    //TextureComponent* thirdTextureComponent = new TextureComponent(std::string("res/textures/eevee.jpg"));
    //thirdTextureComponent->AttachShader(*thirdDefaultShader);

    //First Game Entity

    jolieCubeEntity = vp.CreateEntity<>();
    jolieCubeEntity->SetLocation(3,4,-8);
    jolieCubeEntity->AttachShader(secondDefaultShader);
    jolieCubeEntity->AddComponent<MeshComponent>(cubeVertices, cubeIndices, jolieTexture);
    jolieCubeEntity->entityName = "Jolie cube";
    jolieCubeEntity->SetScale(3,3,3);


    //Third Game Entity
    /*
   thirdTexturedEntity = vp.CreateEntity();
   thirdTexturedEntity->SetLocation(2, 10, 3);
   thirdTexturedEntity->AddComponent<MeshComponent>(cubeVertices, cubeIndices, thirdTextureComponent);
   thirdTexturedEntity->AttachShader(thirdDefaultShader);
   thirdTexturedEntity->entityName = "Eevee cube";
   */

    m_floor = vp.CreateEntity();
    m_floor->SetScale(50, 1, 50);
    m_floor->AttachShader(secondDefaultShader);
    m_floor->AddComponent<MeshComponent>(cubeVertices, cubeIndices, floorTexture);
    m_floor->entityName = "Floor";


    //Second Game Entity
   secondTexturedEntity = vp.CreateEntity();
   secondTexturedEntity->SetLocation(-5, 3, -4);
   secondTexturedEntity->AttachShader(secondDefaultShader);
   secondTexturedEntity->AddComponent<MeshComponent>(cubeVertices, cubeIndices, secondTextureComponent);
   secondTexturedEntity->entityName = "Mario64 cube";
   

   m_BasicLight = vp.CreateEntity<BasicLight>();
   m_BasicLight->SetLocation(-10, 2, -2);
   secondTexturedEntity->m_basicLight = dynamic_cast<BasicLight*>(m_BasicLight);
   /*
    //Fourth Entity
    gE = vp.CreateEntity();
    gE->SetLocation(0, 0, 0);
    gE->AddComponent<MeshComponent>(cubeVertices, cubeIndices);
    gE->AttachShader(defaultShader);
    gE->entityName = "Default cube";
    */
}

void SandboxApp::OnUpdate(float deltaTime)
{
    YorkieEngineApp::OnUpdate(deltaTime);
    glm::vec3 moveSpeed = glm::vec3(5.0f, 0.0f, 0.0f) * deltaTime;
    glm::vec3 scale = glm::vec3(3.0f, 1.0f, 1.0f);

    double getTimeX = cos(GetGameTime()) * 360;
    double getTimeY = sin(GetGameTime()) * 360;

    if(input->IsKeyPressed(EKeyboardKeys::KEY_1))
        secondTexturedEntity->m_basicLight->m_lightColor = glm::vec3(0.36, 0.76, 0.92);
    else if (input->IsKeyPressed(EKeyboardKeys::KEY_2))
        secondTexturedEntity->m_basicLight->m_lightColor = glm::vec3(0.83, 0.26, 0.26);
    else if (input->IsKeyPressed(EKeyboardKeys::KEY_3))
        secondTexturedEntity->m_basicLight->m_lightColor = glm::vec3(0.43, 0.86, 0.40);
    else if (input->IsKeyPressed(EKeyboardKeys::KEY_4))
        secondTexturedEntity->m_basicLight->m_lightColor = glm::vec3(0.96, 0.93, 0.34);
    else
        secondTexturedEntity->m_basicLight->m_lightColor = glm::vec3(1.0, 1.0, 1.0);

    

    if (m_BasicLight->GetPosition().x > 15)
        lightSpeed = -15;
    if(m_BasicLight->GetPosition().x < -15)
        lightSpeed = 15;

    m_BasicLight->AddOffstet(lightSpeed*deltaTime, 0, 0);

    jolieCubeEntity->SetRotation(getTimeX, getTimeY, 1);

    /*
    if (input->IsKeyPressed(EKeyboardKeys::KEY_1))
    {
        texturedEntity->SetLocation(moveSpeed);
    }
    if (input->IsKeyPressed(EKeyboardKeys::KEY_2))
    {
        texturedEntity->SetScale(scale);
    }

    texturedEntity->AddOffstet(getTimeX * deltaTime, getTimeY * deltaTime, 0);
    texturedEntity->SetScale(2, 2, 2);

    //Second textured entity 

    float rot = 90 * deltaTime;
    secondTexturedEntity->AddRotation(rot, rot, rot);
    secondTexturedEntity->SetScale(2, 2, 2);

    //Third textured entity

    float scaleX = cos(GetGameTime()) * 2;
    float scaleY = sin(GetGameTime()) * 3;
    thirdTexturedEntity->SetScale(scaleX, scaleY, 1.5);
        */

}

void SandboxApp::OnPostUpdate()
{
}
