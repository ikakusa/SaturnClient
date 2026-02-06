#pragma once
#include "PayloadPacket.h"
class RequestPermissionPayload;
class RequestPermission : public PayloadPacket<RequestPermissionPayload>
{
public:
    RequestPermission() = delete;
};