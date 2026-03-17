#pragma once
#include <cstdint>

struct EthernetFrame {
    uint8_t dst_mac[6];
    uint8_t src_mac[6];
    uint16_t ether_type;
    int payload_size;
    uint8_t* p_payload;
};