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

#include <GL/glut.h>

namespace BlackCodex {
namespace BCGlEngine {

class BCGlCamera
{
    GLfloat mPosition[3];
    GLfloat mCenter[3];

public:
    BCGlCamera()
        {}

    void set(GLfloat pos[3], GLfloat cen[3]) {
        copyArray3(mPosition, pos);
        copyArray3(mCenter, cen);
        _update();
    }

protected:
    void copyArray3(GLfloat* tgt, const GLfloat* src) {
        tgt[0] = src[0];
        tgt[1] = src[1];
        tgt[2] = src[2];
    }
    void _update() {
        glLoadIdentity();
        gluLookAt(
            mPosition[0],   mPosition[1],   mPosition[2],   /* eye is at (0,0,5) */
            mCenter[0],     mCenter[1],     mCenter[2],     /* center is at (0,0,0) */
            0.0, 1.0, 0.0);                                 /* up is in positive Y direction */
    }
};

} // BCGlEngine
} // BlackCodex

