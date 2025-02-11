#pragma once

#include <Common.hh>
#include <revolution/gx.h>

/*
Helpful asserts:

v10 = nw4r::g3d::ResMdl::GetResMat(&v14, j);
if ( !v10 )
    nw4r::db::Panic("g3d_resmat_ac.h", 621, "%s::%s: Object not valid.", "ResMat", "ref");
if ( ((v10 + 20) & 3) != 0 )
    nw4r::db::Panic("g3d_resmat_ac.h", 175, "NW4R:Failed assertion !((u32)p & 0x3)");
v12 = v10 + 20;
if ( v10 == -20 )
    nw4r::db::Panic("g3d_resmat_ac.h", 223, "NW4R:Failed assertion IsValid()");
*/

namespace nw4r::g3d {

template <typename T>
class ResCommon {
public:
    ResCommon(T *data) : m_data(data) {}

    T &ref() {
        assert(m_data != nullptr);
        return *m_data;
    }
    const T &ref() const {
        assert(m_data != nullptr);
        return *m_data;
    }

private:
    T *m_data = nullptr;
};

struct ResMdlData {
    u8 _00[0x44];
    u32 ofsUserData;
    // ...
};

struct ResMatData {
    char _00[0x14 - 0x00];
    char _14;
    // ...
};

class ResGenMode : public ResCommon<char> {
public:
    using ResCommon::ResCommon;

    void GXSetCullMode(GXCullMode cullMode);
    GXCullMode GXGetCullMode() const {
        return *reinterpret_cast<const GXCullMode *>(&ref() + 4);
    }
};

class ResMat : public ResCommon<ResMatData> {
public:
    ResGenMode GetResGenMode() {
        return ResGenMode(&ref()._14);
    }
};
static_assert_32bit(sizeof(ResMat) == 4);

class ResMdl : public ResCommon<ResMdlData> {
public:
    ResMat GetResMat(u32 idx) const;
    u32 GetResMatNumEntries() const;
};
static_assert_32bit(sizeof(ResMdl) == 4);

class ResFile : public ResCommon<char> {
public:
    ResMdl GetResMdl(u32 idx) const;
    u32 GetResMdlNumEntries() const;
};
static_assert_32bit(sizeof(ResFile) == 4);

} // namespace nw4r::g3d
