#pragma once
#include "PayloadPacket.h"
class TextPacketPayload;
class TextPacket : public PayloadPacket<TextPacketPayload>
{
public:
    TextPacket() = delete;
};