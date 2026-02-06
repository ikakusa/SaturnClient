#pragma once
#include <MemUtils.h>

enum class TextPacketType;
struct TextPacketPayload {
public:
    bool mLocalize;
    char pad[0x7];
    std::string mXuid;
    char pad1[0x8];
    std::string mPlatformId;
    char pad2[0x8];
    std::optional<std::string> mFilteredMessage;
    char pad3[0x8];

    struct BodyRaw {
        TextPacketType type;

        union {
            struct {
                char pad[8];
                std::string message;
                char pad2[8];
            } messageOnly;

            struct {
                char pad[8];
                std::string author;
                char pad2[8];
                std::string message;
                char pad3[8];
            } authorAndMessage;

            struct {
                char pad[8];
                std::string message;
                char pad2[0x8];
                std::vector<std::string> params;
                char pad3[0x8];
            } messageAndParams;
        };
    } mBody;
};