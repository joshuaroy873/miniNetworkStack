#include "../include/byte_reader.hpp"

#include <iostream>
#include <cstdint> // Required for uint8_t, uint16_t
#include <iomanip> // Required for setfill, setw

struct EthernetFrame {
    uint8_t dst_mac[6];
    uint8_t src_mac[6];
    uint16_t ether_type;
    int payload_size;
    uint8_t* p_payload;
};

EthernetFrame parse_ethernet_frame(ByteReader* p_reader) {
    EthernetFrame frame;
    
    // dst_mac
    for (int i=0; i<6; i++) {frame.dst_mac[i] = read_u8(p_reader);}
    // src_mac
    for (int i=0; i<6; i++) {frame.src_mac[i] = read_u8(p_reader);}
    // ether_type
    frame.ether_type = read_u16(p_reader);
    // payload_size
    frame.payload_size = bytes_remaining(p_reader);
    // payload
    frame.p_payload = &p_reader->p_data[p_reader->pos]; // [] operator dereferences!

    return frame;
}

void print_mac(uint8_t mac[6]) {
    for (int i = 0; i < 6; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)mac[i];
        if (i < 5) std::cout << ":";
    }
    std::cout << std::endl;
}

int main() {
    uint8_t packet[] = {
        0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF,    // dst_mac (6 bytes)
        0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA,    // src_mac (6 bytes)
        0x08, 0x00,                            // ether_type (2 bytes)
        0x45, 0x00, 0x00, 0x54, 0x12, 0x34     // payload
    };
    ByteReader reader(packet, sizeof(packet));
    EthernetFrame frame = parse_ethernet_frame(&reader);

    std::cout << "DST MAC: ";
    print_mac(frame.dst_mac);

    std::cout << "SRC MAC: ";
    print_mac(frame.src_mac);

    std::cout << "ETHER TYPE: 0x" << std::hex << frame.ether_type << std::endl;

    std::cout << "PAYLOAD SIZE (bytes): " << frame.payload_size << std::endl;

    std::cout << "PAYLOAD: [";
    for (int i = 0; i < frame.payload_size; i++) {
        std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)frame.p_payload[i];
        if (i < frame.payload_size-1) std::cout << " ";
    }
    std::cout << "]";

    return 0;
}