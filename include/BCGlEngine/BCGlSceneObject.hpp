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

#include <BCGlEngine/BCGlObjectBase.hpp>

#include <GL/gl.h>

#include <stdexcept>

namespace BlackCodex {
namespace BCGlEngine {

template<typename T>
class BCGlSceneObject : public BCGlObjectBase<T>
{
public:
    BCGlSceneObject(int type)
        : BCGlObjectBase<T>(type)
    {}

    void process() const
    {
        const auto& lpts = BCGlObjectBase<T>::pts();
        const auto& lnrm = BCGlObjectBase<T>::nrms();
        size_t dsp = 0;

        if (!lnrm.empty()) {
            if (0 != lpts.size() % lnrm.size()) {
                throw std::runtime_error("Invalid normals / points");
                return;
            }

            dsp = lpts.size() / lnrm.size();
        }

        const auto& pos = BCGlObjectBase<T>::getPosition();
        glTranslated(pos.getX(), pos.getY(), pos.getZ());
        glBegin(BCGlObjectBase<T>::getType());
        for (size_t px=0, nx=0; px < lpts.size(); ++px, --nx)
        {
            if (nx == 0 & dsp != 0) {
                const auto& n = lnrm[nx];
                glNormal3d(n.getX(), n.getY(), n.getZ());
                nx=dsp;
            }
            const auto& p = lpts[px];
            glVertex3d(p.getX(), p.getY(), p.getZ());
        }
        glEnd();
    }
};

} // BCGlEngine
} // BlackCodex
