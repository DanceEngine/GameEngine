//
// Created by DanceEngine on 2024/12/10.
//

#ifndef ENGINE_H
#define ENGINE_H
#include <glm.hpp>



class Engine {

public:
    void Init();

    void Tick(float deltaTime);

    void BeginFrame();

    void EndFrame();

    void InitVertex();

    void InitShaders();

    ~Engine();

private:
    unsigned int shaderProgram;
    unsigned int VAO;
    unsigned int VBO;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
};



#endif //ENGINE_H
