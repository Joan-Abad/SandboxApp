#include "SandboxApp.h"
#include "Shaders/Shader.h"
#include "glad/glad.h"
#include <vector>
#include "Rendering/RenderObject.h"
#include <iostream>
#include "Rendering/RenderingSystem.h"
#include "Window/Public/WindowManager.h"

SandboxApp::SandboxApp() : YorkiEngineApp()
{
}

void SandboxApp::OnCreateApplicationCallback()
{
 /*
    Shader squareShader("res/shaders/Square.shader");
    Shader secondSquareShader("res/shaders/SecondSquare.shader");
    Shader triangleShader("res/shaders/Triangle.shader");

    // Vertices of the left square
    std::vector<float> leftSquareVertices = {
        -0.75f, -0.5f, 0.0f, // Bottom-left vertex
        -0.25f, -0.5f, 0.0f, // Bottom-right vertex
        -0.75f, 0.5f, 0.0f,  // Top-left vertex
        -0.25f, 0.5f, 0.0f    // Top-right vertex
    };

    // Vertices of the right square
    std::vector<float> rightSquareVertices = {
        0.25f, -0.5f, 0.0f,  // Bottom-left vertex
        0.75f, -0.5f, 0.0f,  // Bottom-right vertex
        0.25f, 0.5f, 0.0f,   // Top-left vertex
        0.75f, 0.5f, 0.0f    // Top-right vertex
    };

    // Indices of both squares to be drawn with GL_TRIANGLES
    std::vector<unsigned int> indices = {
        0, 1, 2, // First triangle (left square)
        1, 3, 2, // Second triangle (left square)
        4, 5, 6, // First triangle (right square)
        5, 7, 6  // Second triangle (right square)
    };

    std::vector<float>vertices = {
        // positions       
         0.5f, -0.5f, 0.0f,// bottom right
        -0.5f, -0.5f, 0.0f,// bottom left
         0.0f,  0.5f, 0.0f,// top 
    };

    //RenderObject* firstSquare = new RenderObject(leftSquareVertices, indices, squareShader);
    //RenderObject* secondSquare = new RenderObject(rightSquareVertices, indices, secondSquareShader);
    RenderObject* triangle = new RenderObject(vertices, triangleShader);
    //triangle->buffer.AddBufferData(vertices);

    //triangle->AttachShader(triangleShader);
        */
}

void SandboxApp::OnPreDraw()
{
}

void SandboxApp::OnPostDraw()
{
}
