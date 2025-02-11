#include "RaceConfig.hh"

#include "game/system/InputManager.hh"
extern "C" {
#include "game/system/SaveManager.h"
}
#include "game/system/SaveManager.hh"

extern "C" {
#include <vendor/libhydrogen/hydrogen.h>
}

namespace System {

RaceConfig::Scenario &RaceConfig::raceScenario() {
    return m_raceScenario;
}

RaceConfig::Scenario &RaceConfig::menuScenario() {
    return m_menuScenario;
}

RaceConfig::Scenario &RaceConfig::awardsScenario() {
    return m_awardsScenario;
}

u8 (&RaceConfig::ghostBuffers())[2][11][0x2800] {
    return m_ghostBuffers;
}

void RaceConfig::applyVSEngineClass() {
    m_menuScenario.engineClass = EngineClass::CC150;
    m_menuScenario.mirror = false;
    m_menuScenario.mirrorRng = false;
    vsSpeedModIsEnabled = false;

    auto *saveManager = SaveManager::Instance();
    auto setting = saveManager->getSetting<SP::ClientSettings::Setting::VSClass>();
    switch (setting) {
    case SP::ClientSettings::VSClass::Mixed:
        m_menuScenario.mirror = hydro_random_uniform(20) >= 17;
        m_menuScenario.mirrorRng = true;
        break;
    case SP::ClientSettings::VSClass::CC150:
        break;
    case SP::ClientSettings::VSClass::Mirror:
        m_menuScenario.mirror = true;
        break;
    case SP::ClientSettings::VSClass::CC200:
        vsSpeedModIsEnabled = true;
        break;
    }
}

RaceConfig *RaceConfig::Instance() {
    return s_instance;
}

void RaceConfig::ConfigurePlayers(Scenario &scenario, u32 screenCount) {
    auto *inputManager = InputManager::Instance();

    u8 screenId = 0, ghostProxyId = 0;

    for (u32 i = 0; i < 12; i++) {
        if (scenario.players[i].type == Player::Type::Local) {
            assert(screenId < screenCount);
            assert(ghostProxyId < 4);

            s32 controllerId = inputManager->ghostProxy(ghostProxyId)->pad()->getControllerId();
            scenario.players[i].screenId = screenId;
            scenario.players[i].ghostProxyId = ghostProxyId;
            scenario.players[i].controllerId = controllerId;
            scenario.screenPlayerIds[screenId] = i;

            screenId++;
            ghostProxyId++;
        } else if (scenario.players[i].type == Player::Type::Ghost) {
            u32 ghostId = scenario.players[0].type == Player::Type::Ghost ? i : i - 1;
            const u8 *rawGhostFile = (*scenario.ghostBuffer)[ghostId];

            if (RawGhostFile::IsValid(rawGhostFile)) {
                auto *rawGhostHeader = reinterpret_cast<const RawGhostHeader *>(rawGhostFile);
                bool driftIsAuto = rawGhostHeader->driftIsAuto;
                inputManager->setGhostPad(i, rawGhostFile + 0x88, driftIsAuto);
                scenario.players[i].characterId = rawGhostHeader->characterId;
                scenario.players[i].vehicleId = rawGhostHeader->vehicleId;
                scenario.players[i].controllerId = rawGhostHeader->controllerId;
            } else {
                inputManager->setGhostPad(i, rawGhostFile + 0x88, false);
                scenario.players[i].characterId = 0; // Mario
                scenario.players[i].vehicleId = 1; // Standard Kart M
                scenario.players[i].controllerId = 0; // Wii Wheel
            }
        } else {
            scenario.players[i].controllerId = -1;
        }
    }

    for (u32 i = 0; i < 12 && screenId < screenCount; i++) {
        if (scenario.players[i].type == Player::Type::None) {
            continue;
        }

        if (scenario.players[i].screenId != -1) {
            continue;
        }

        scenario.players[i].screenId = screenId;
        scenario.screenPlayerIds[screenId] = i;

        screenId++;
    }
}

} // namespace System

extern "C" {

bool RaceConfig_IsSameTeam(u32 p0, u32 p1) {
    auto &raceScenario = System::RaceConfig::Instance()->raceScenario();
    if (raceScenario.spMaxTeamSize < 2) {
        return p0 == p1;
    }

    return raceScenario.players[p0].spTeam == raceScenario.players[p1].spTeam;
}

}
