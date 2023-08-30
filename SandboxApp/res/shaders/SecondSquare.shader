#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
out vec3 FragPos;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    FragPos = aPos;
}

#shader fragment
#version 330 core

in vec3 FragPos; // Declare the input variable for the position
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0, 0.0, 0.66, 1.0);
}