#include "ClientSettings.hh"

#include <iterator>

namespace SP::ClientSettings {

const char name[] = "MKW-SP Settings";

const u32 categoryMessageIds[] = { 10118, 10126, 10119, 10120 };

const Entry entries[] = {
    [static_cast<u32>(Setting::DriftMode)] = {
        .category = Category::Race,
        .name = magic_enum::enum_name(Setting::DriftMode),
        .messageId = 0,
        .defaultValue = static_cast<u32>(DriftMode::Manual),
        .valueCount = magic_enum::enum_count<DriftMode>(),
        .valueNames = magic_enum::enum_names<DriftMode>().data(),
        .valueMessageIds = nullptr,
        .valueExplanationMessageIds = nullptr,
        .hidden = true,
    },
    [static_cast<u32>(Setting::VanillaMode)] = {
        .category = Category::Race,
        .name = magic_enum::enum_name(Setting::VanillaMode),
        .messageId = 10166,
        .defaultValue = static_cast<u32>(VanillaMode::Disable),
        .valueCount = magic_enum::enum_count<VanillaMode>(),
        .valueNames = magic_enum::enum_names<VanillaMode>().data(),
        .valueMessageIds = (u32[]) { 10167, 10168 },
        .valueExplanationMessageIds = (u32[]) { 10169, 10170 },
    },
    [static_cast<u32>(Setting::FOV169)] = {
        .category = Category::Race,
        .name = magic_enum::enum_name(Setting::FOV169),
        .messageId = 10009,
        .defaultValue = static_cast<u32>(FOV169::FOV169),
        .valueCount = magic_enum::enum_count<FOV169>(),
        .valueNames = magic_enum::enum_names<FOV169>().data(),
        .valueMessageIds = (u32[]) { 10010, 10011 },
        .valueExplanationMessageIds = (u32[]) { 10012, 10013 },
        .vanillaValue = static_cast<u32>(FOV169::FOV169),
    },
    [static_cast<u32>(Setting::PlayerTags)] = {
        .category = Category::Race,
        .name = magic_enum::enum_name(Setting::PlayerTags),
        .messageId = 10183,
        .defaultValue = 8,
        .valueCount = 13,
        .valueNames = nullptr,
        .valueMessageIds = (u32[]) { 10184 },
        .valueExplanationMessageIds = (u32[]) { 10185 },
        .vanillaValue = 3,
    },
    [static_cast<u32>(Setting::HUDLabels)] = {
        .category = Category::Race,
        .name = magic_enum::enum_name(Setting::HUDLabels),
        .messageId = 10004,
        .defaultValue = static_cast<u32>(HUDLabels::Show),
        .valueCount = magic_enum::enum_count<HUDLabels>(),
        .valueNames = magic_enum::enum_names<HUDLabels>().data(),
        .valueMessageIds = (u32[]) { 10005, 10006 },
        .valueExplanationMessageIds = (u32[]) { 10007, 10008 },
        .vanillaValue = static_cast<u32>(HUDLabels::Show),
    },
    [static_cast<u32>(Setting::MapIcons)] = {
        .category = Category::Race,
        .name = magic_enum::enum_name(Setting::MapIcons),
        .messageId = 10014,
        .defaultValue = static_cast<u32>(MapIcons::Miis),
        .valueCount = magic_enum::enum_count<MapIcons>(),
        .valueNames = magic_enum::enum_names<MapIcons>().data(),
        .valueMessageIds = (u32[]) { 10015, 10016 },
        .valueExplanationMessageIds = (u32[]) { 10017, 10018 },
        .vanillaValue = static_cast<u32>(MapIcons::Characters),
    },
    [static_cast<u32>(Setting::InputDisplay)] = {
        .category = Category::Race,
        .name = magic_enum::enum_name(Setting::InputDisplay),
        .messageId = 10061,
        .defaultValue = static_cast<u32>(InputDisplay::Simple),
        .valueCount = magic_enum::enum_count<InputDisplay>(),
        .valueNames = magic_enum::enum_names<InputDisplay>().data(),
        .valueMessageIds = (u32[]) { 10062, 10063 },
        .valueExplanationMessageIds = (u32[]) { 10064, 10065 },
        .vanillaValue = static_cast<u32>(InputDisplay::Disable),
    },
    [static_cast<u32>(Setting::RankControl)] = {
        .category = Category::Race,
        .name = magic_enum::enum_name(Setting::RankControl),
        .messageId = 10121,
        .defaultValue = static_cast<u32>(RankControl::GPVS),
        .valueCount = magic_enum::enum_count<RankControl>(),
        .valueNames = magic_enum::enum_names<RankControl>().data(),
        .valueMessageIds = (u32[]) { 10122, 10123 },
        .valueExplanationMessageIds = (u32[]) { 10124, 10125 },
        .vanillaValue = static_cast<u32>(RankControl::GPVS),
    },
    [static_cast<u32>(Setting::ItemMusic)] = {
        .category = Category::Sound,
        .name = magic_enum::enum_name(Setting::ItemMusic),
        .messageId = 10127,
        .defaultValue = static_cast<u32>(ItemMusic::All),
        .valueCount = magic_enum::enum_count<ItemMusic>(),
        .valueNames = magic_enum::enum_names<ItemMusic>().data(),
        .valueMessageIds = (u32[]) { 10128, 10129, 10130 },
        .valueExplanationMessageIds = (u32[]) { 10131, 10132, 10133 },
        .vanillaValue = static_cast<u32>(ItemMusic::All),
    },
    [static_cast<u32>(Setting::LastLapJingle)] = {
        .category = Category::Sound,
        .name = magic_enum::enum_name(Setting::LastLapJingle),
        .messageId = 10134,
        .defaultValue = static_cast<u32>(LastLapJingle::GameplayOnly),
        .valueCount = magic_enum::enum_count<LastLapJingle>(),
        .valueNames = magic_enum::enum_names<LastLapJingle>().data(),
        .valueMessageIds = (u32[]) { 10135, 10136 },
        .valueExplanationMessageIds = (u32[]) { 10137, 10138 },
        .vanillaValue = static_cast<u32>(LastLapJingle::GameplayOnly),
    },
    [static_cast<u32>(Setting::LastLapSpeedup)] = {
        .category = Category::Sound,
        .name = magic_enum::enum_name(Setting::LastLapSpeedup),
        .messageId = 10139,
        .defaultValue = static_cast<u32>(LastLapSpeedup::Static),
        .valueCount = magic_enum::enum_count<LastLapSpeedup>(),
        .valueNames = magic_enum::enum_names<LastLapSpeedup>().data(),
        .valueMessageIds = (u32[]) { 10140, 10141, 10142 },
        .valueExplanationMessageIds = (u32[]) { 10143, 10144, 10145 },
        .vanillaValue = static_cast<u32>(LastLapSpeedup::Static),
    },
    [static_cast<u32>(Setting::TAClass)] = {
        .category = Category::TA,
        .name = magic_enum::enum_name(Setting::TAClass),
        .messageId = 3410,
        .defaultValue = static_cast<u32>(TAClass::CC150),
        .valueCount = magic_enum::enum_count<TAClass>(),
        .valueNames = magic_enum::enum_names<TAClass>().data(),
        .valueMessageIds = (u32[]) { 3413, 10072 },
        .valueExplanationMessageIds = (u32[]) { 10079, 10081 },
    },
    [static_cast<u32>(Setting::TAGhostSorting)] = {
        .category = Category::TA,
        .name = magic_enum::enum_name(Setting::TAGhostSorting),
        .messageId = 10019,
        .defaultValue = static_cast<u32>(TAGhostSorting::Time),
        .valueCount = magic_enum::enum_count<TAGhostSorting>(),
        .valueNames = magic_enum::enum_names<TAGhostSorting>().data(),
        .valueMessageIds = (u32[]) { 10171, 10172, 10173, 10174, 10175 },
        .valueExplanationMessageIds = (u32[]) { 10176, 10177, 10178, 10179, 10180 },
    },
    [static_cast<u32>(Setting::TAGhostTagVisibility)] = {
        .category = Category::TA,
        .name = magic_enum::enum_name(Setting::TAGhostTagVisibility),
        .messageId = 10028,
        .defaultValue = static_cast<u32>(TAGhostTagVisibility::All),
        .valueCount = magic_enum::enum_count<TAGhostTagVisibility>(),
        .valueNames = magic_enum::enum_names<TAGhostTagVisibility>().data(),
        .valueMessageIds = (u32[]) { 10029, 10030, 10031 },
        .valueExplanationMessageIds = (u32[]) { 10032, 10033, 10034 },
        .vanillaValue = static_cast<u32>(TAGhostTagVisibility::Watched),
    },
    [static_cast<u32>(Setting::TAGhostTagContent)] = {
        .category = Category::TA,
        .name = magic_enum::enum_name(Setting::TAGhostTagContent),
        .messageId = 10035,
        .defaultValue = static_cast<u32>(TAGhostTagContent::Name),
        .valueCount = magic_enum::enum_count<TAGhostTagContent>(),
        .valueNames = magic_enum::enum_names<TAGhostTagContent>().data(),
        .valueMessageIds = (u32[]) { 10036, 10037, 10053, 10038 },
        .valueExplanationMessageIds = (u32[]) { 10039, 10040, 10054, 10041 },
        .vanillaValue = static_cast<u32>(TAGhostTagContent::Name),
    },
    [static_cast<u32>(Setting::TASolidGhosts)] = {
        .category = Category::TA,
        .name = magic_enum::enum_name(Setting::TASolidGhosts),
        .messageId = 10042,
        .defaultValue = static_cast<u32>(TASolidGhosts::None),
        .valueCount = magic_enum::enum_count<TASolidGhosts>(),
        .valueNames = magic_enum::enum_names<TASolidGhosts>().data(),
        .valueMessageIds = (u32[]) { 10029, 10030, 10031 },
        .valueExplanationMessageIds = (u32[]) { 10043, 10044, 10045 },
        .vanillaValue = static_cast<u32>(TASolidGhosts::None),
    },
    [static_cast<u32>(Setting::TAGhostSound)] = {
        .category = Category::TA,
        .name = magic_enum::enum_name(Setting::TAGhostSound),
        .messageId = 10066,
        .defaultValue = static_cast<u32>(TAGhostSound::Watched),
        .valueCount = magic_enum::enum_count<TAGhostSound>(),
        .valueNames = magic_enum::enum_names<TAGhostSound>().data(),
        .valueMessageIds = (u32[]) { 10029, 10030, 10031 },
        .valueExplanationMessageIds = (u32[]) { 10067, 10068, 10069 },
        .vanillaValue = static_cast<u32>(TAGhostSound::Watched),
    },
    [static_cast<u32>(Setting::MiiAvatar)] = {
        .category = Category::License,
        .name = magic_enum::enum_name(Setting::MiiAvatar),
        .messageId = 0,
        .defaultValue = 0x80000001,
        .valueCount = 0,
        .valueNames = nullptr,
        .valueMessageIds = nullptr,
        .valueExplanationMessageIds = nullptr,
    },
    [static_cast<u32>(Setting::MiiClient)] = {
        .category = Category::License,
        .name = magic_enum::enum_name(Setting::MiiClient),
        .messageId = 0,
        .defaultValue = 0xECFF82D2,
        .valueCount = 0,
        .valueNames = nullptr,
        .valueMessageIds = nullptr,
        .valueExplanationMessageIds = nullptr,
    },
    [static_cast<u32>(Setting::LoadingScreenColor)] = {
        .category = Category::License,
        .name = magic_enum::enum_name(Setting::LoadingScreenColor),
        .messageId = 0,
        .defaultValue = 0xFF,
        .valueCount = 0,
        .valueNames = nullptr,
        .valueMessageIds = nullptr,
        .valueExplanationMessageIds = nullptr,
    },
    [static_cast<u32>(Setting::PageTransitions)] = {
        .category = Category::License,
        .name = magic_enum::enum_name(Setting::PageTransitions),
        .messageId = 10056,
        .defaultValue = static_cast<u32>(PageTransitions::Enable),
        .valueCount = magic_enum::enum_count<PageTransitions>(),
        .valueNames = magic_enum::enum_names<PageTransitions>().data(),
        .valueMessageIds = (u32[]) { 10057, 10058 },
        .valueExplanationMessageIds = (u32[]) { 10059, 10060 },
    },
};

} // namespace SP::ClientSettings
