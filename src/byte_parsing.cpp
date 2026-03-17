#include <iostream>
#include <cstdint> // Required for uint8_t, uint16_t
#include <stdexcept> // std::runtime_error

struct ByteReader {
    uint8_t* p_data;
    int size;
    int pos;

    ByteReader(uint8_t* data, int len) : p_data(data), size(len), pos(0) {}
};

int bytes_remaining(ByteReader* p_reader) {
    return p_reader->size - p_reader->pos;
}

uint8_t read_u8(ByteReader* p_reader) {
    // Read one byte safely from the buffer, advancing position
    int remaining = bytes_remaining(p_reader);

    if (remaining < 1) {
        throw std::runtime_error("ERROR: Beyond end of buffer!");
    }
    else if (remaining == 1) {
        std::cout << "WARNING: Reading last byte of buffer" << std::endl;
    }

    uint8_t byte = p_reader->p_data[p_reader->pos++];
    return byte;
}

uint16_t read_u16(ByteReader* p_reader) {
    // Read two bytes safely from the buffer, advancing position
    int remaining = bytes_remaining(p_reader);

    if (remaining < 2) {
        throw std::runtime_error("ERROR: Not enough bytes for u16!");
    }
    else if (remaining == 2) {
        std::cout << "WARNING: Reading last 2 bytes" << std::endl;
    }

    uint8_t high = p_reader->p_data[p_reader->pos++];
    uint8_t low = p_reader->p_data[p_reader->pos++];
    return static_cast<uint16_t>((high << 8) | low);

}

int main() {

    uint8_t packet[] = {0x09, 0x08, 0x07, 0x06};
    // ByteReader reader;
    // reader.p_data = packet;
    // reader.size = 4;
    // reader.pos = 0;
    ByteReader reader(packet, 4);

    try {
        uint8_t byte1 = read_u8(&reader);
        std::cout << "Byte 1: " << std::hex << (int)byte1 << std::endl;

        uint16_t byte23 = read_u16(&reader);
        std::cout << "Byte 2+3: " << std::hex << (int)byte23 << std::endl;

        uint8_t byte4 = read_u8(&reader);
        std::cout << "Byte 4: " << std::hex << int(byte4) << std::endl;

        uint8_t extra = read_u8(&reader);
    }
    catch (const std::exception& e) {
        std::cout << "CAUGHT ERROR: " << e.what() << std::endl;
    }

    return 0;
}