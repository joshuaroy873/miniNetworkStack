#pragma once
#include <cstdint>
#include <stdexcept>
#include <iostream>

struct ByteReader {
    uint8_t* p_data;
    int size;
    int pos;

    ByteReader(uint8_t* data, int len) : p_data(data), size(len), pos(0) {}
};

int bytes_remaining(ByteReader* p_reader);
uint8_t read_u8(ByteReader* p_reader);
uint16_t read_u16(ByteReader* p_reader);