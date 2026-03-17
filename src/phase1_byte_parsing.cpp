#include <iostream>
#include <cstdint> // Required for uint8_t

struct ByteReader {
    uint8_t* p_data;
    int size;
    int pos;
};

int bytes_remaining(ByteReader* p_ByteReader) {
    return p_ByteReader->size - p_ByteReader->pos - 1;
}

// unsigned char read_byte() {
//     // Input: ByteReader pointer
//     // Safety: check if at least 1 byte remains
//     // If not enough: print error and return 0
//     // If enough: read the byte, move position forward, return it
// }

// unsigned short read_u16_big_endian() {
//     // Input: ByteReader pointer
//     // Safety: check if at least 2 bytes remain
//     // Read two bytes in order: first byte is "high", second is "low"
//     // Combine as: (high << 8) | low
//     // Return the uint16 value
// }

int main() {
    // Create array: {0x01, 0x02, 0x03, 0x04}
    // Create ByteReader pointing to it
    // Read: one byte (expect 1), one u16 (expect 0x0203), one byte (expect 4)
    // Print each result
    // Try to read one more (expect error message)

    uint8_t tempArray[] = {0x01, 0x02, 0x03, 0x04};
    ByteReader tempReader;
    
    tempReader.p_data = tempArray;
    tempReader.size = 4;
    tempReader.pos = 0;

    while (tempReader.pos < tempReader.size) {
        uint8_t tempByte = tempReader.p_data[tempReader.pos];
        std::cout << (int)tempByte << ":  " << bytes_remaining(&tempReader) << std::endl;
        tempReader.pos++;
    }
}