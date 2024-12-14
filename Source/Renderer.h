//
// Created by DanceEngine on 2024/12/10.
//

#ifndef RENDERER_H
#define RENDERER_H


class Window;

class Renderer {

public:
    static Renderer& Get();

    void Init(Window* window);

    void BeginFrame();

    void EndFrame();

private:
    Window* window;
};



#endif //RENDERER_H
