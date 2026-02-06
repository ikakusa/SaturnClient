#pragma once
class Packet;
template <class payloadTemplate>
class PayloadPacket : public Packet, public payloadTemplate {
};