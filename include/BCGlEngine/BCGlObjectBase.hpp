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

#include <bcpptools/math/bcvector3.h>

#include <string>
#include <vector>

namespace BlackCodex {
namespace BCGlEngine {

template <typename T>
class BCGlObjectBase
{
private:
    typedef bcpptools::math::bcvector3_t<T> TVec3;

    std::string mName;
    int mType;
    TVec3 mPos;
    TVec3 mRot;
    TVec3 mSca;
    std::vector<TVec3> mPts;
    std::vector<TVec3> mNrms;
    std::vector<BCGlObjectBase<T>> mSubtree;

public:
    BCGlObjectBase(int type)
    : mType(type)
    , mSca(1.0, 1.0, 1.0)
    {}

    int getType() const {
        return mType;
    }
    const TVec3& getPosition() const {
        return mPos;
    }
    const TVec3& getRotation() const {
        return mRot;
    }
    const TVec3& getScale() const {
        return mSca;
    }
    void setPosition(const TVec3& pos) {
        mPos = pos;
    }
    void setRotation(const TVec3& rot) {
        mRot = rot;
    }
    void setScale(const TVec3& sca) {
        mSca = sca;
    }

    template <size_t VC, size_t NC>
    void set(const T (&v)[VC], const T (&n)[NC]){
        mPts.clear();
        mNrms.clear();
        for (size_t x = 0; x < VC; x+=3){
            mPts.emplace_back(v[x], v[x+1], v[x+2]);
        }
        for (size_t x = 0; x < NC; x+=3){
            mNrms.emplace_back(n[x], n[x+1], n[x+2]);
        }
    }

    void set(
      std::vector<TVec3>&& pts,
      std::vector<TVec3>&& nrms = std::vector<TVec3>())
    {
      mPts = pts;
      mNrms = nrms;
    }

    const std::vector<TVec3>& pts() const {
        return mPts;
    }

    const std::vector<TVec3>& nrms() const {
        return mNrms;
    }
};

} // BCGlEngine
} // BlackCodex
