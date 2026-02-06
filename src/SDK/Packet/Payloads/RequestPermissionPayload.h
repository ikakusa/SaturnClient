#pragma once
enum class PlayerPermissionLevel : uint8_t {
    Visitor = 0,
    Member = 1,
    Operator = 2,
    Custom = 3,
};
struct RequestPermissionPayload {
public:
    enum class CustomPermissions : unsigned short {
        // bitfield representation
        Build = 1 << 0,
        Mine = 1 << 1,
        DoorsAndSwitches = 1 << 2,
        OpenContainers = 1 << 3,
        AttackPlayers = 1 << 4,
        AttackMobs = 1 << 5,
        OperatorCommands = 1 << 6,
        Teleport = 1 << 7,
    };
public:
    SAFE_ACCESS(__int64, actorUniqueID, 0x0);
    SAFE_ACCESS(PlayerPermissionLevel, permissionLevel, 0x8);
    SAFE_ACCESS(CustomPermissions, permissionFlags, 0x10);
};