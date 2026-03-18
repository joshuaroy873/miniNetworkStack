#pragma once
#include <cstdint>

#define MAC_ADDRESS_SIZE 6

struct EthernetFrame {
    uint8_t dst_mac[MAC_ADDRESS_SIZE];
    uint8_t src_mac[MAC_ADDRESS_SIZE];
    uint16_t ether_type;
    int payload_size;
    uint8_t* p_payload;
};