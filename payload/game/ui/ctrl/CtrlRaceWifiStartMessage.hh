#pragma once

#include "game/ui/ctrl/CtrlRaceBase.hh"

namespace UI {

class CtrlRaceWifiStartMessage : public CtrlRaceBase {
public:
    CtrlRaceWifiStartMessage();
    ~CtrlRaceWifiStartMessage() override;
    void calcSelf() override;
    void vf_28() override;
    void vf_2c() override;
    void vf_40() override;
    void vf_44() override;
    bool vf_48() override;
    void vf_4c() override;

    void load(u32 localPlayerCount, u32 localPlayerId);

private:
    u8 _198[0x19c - 0x198];
};
static_assert(sizeof(CtrlRaceWifiStartMessage) == 0x19c);

} // namespace UI
