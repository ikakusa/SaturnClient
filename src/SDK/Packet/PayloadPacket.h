#pragma once
#include "Payloads/TextPacketPayload.h"
#include "Payloads/RequestPermissionPayload.h"
class Packet;
template <class payloadTemplate>
class PayloadPacket : public Packet, public payloadTemplate {
};