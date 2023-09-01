#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNor;
layout(location = 2) in vec2 aTexCoord;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;  

void main()
{
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = aNor;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core

out vec4 FragColor;     

in vec3 Normal;  
in vec3 FragPos;

in vec2 TexCoord;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform sampler2D texture1;

void main()
{   
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

   // vec3 result = (ambient + diffuse) * lightColor;
    //FragColor = vec4(result, 1.0);
    vec3 ambientColor = (ambientStrength + diffuse) * lightColor;
    vec4 result = vec4(ambientColor, 1.0);
	FragColor = texture(texture1, TexCoord) * result;
}