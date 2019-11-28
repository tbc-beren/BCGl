/**
*
* The Black Codex Library: Chapter: BCGlEngine

* https://github.com/tbc-beren/BCGlEngine
*
* Mozilla Public License Version 2.0
* https://github.com/tbc-beren/BCGlEngine/blob/master/LICENSE
*
*/
#pragma once

#include <BCGlEngine/BCGlSceneObject.hpp>

#include <GL/glut.h>

#include <memory>
#include <vector>

namespace BlackCodex {
namespace BCGlEngine {

template <typename T>
class BCGlScene
{
    std::vector<std::shared_ptr<BCGlSceneObject<T>>> mObjects;

    BCGlScene()
    {}

public:
    static BCGlScene& instance() {
        static BCGlScene gInstance;
        return gInstance;
    }

    void add(std::shared_ptr<BCGlSceneObject<T>>& obj) {
        mObjects.push_back(obj);
    }

    int init()
    {
        int argc = 0;
        char** argv = nullptr;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutCreateWindow("sample");
        glutDisplayFunc(_sprocess);
        return 0;
    }

    int run()
    {
        glutMainLoop();
        return 0;
    }

private:
    void _process() {
        for (const auto& obj : mObjects) {
            obj->process();
        }
    }

    static void _sprocess(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        instance()._process();
        glutSwapBuffers();
    }

};

} // BCGlEngine
} // BlackCodex
