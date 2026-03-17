`buildCpp.sh` can build all files in project folder
- One Cpp file is passed during function call, whose `main()` output is displayed
- So, all `main()` in `src/*.cpp` needs to be commented out

- [x] Phase 1: Byte parsing: `src/byte_parsing.cpp`
- [x] Phase 2: Ethernet framing: `src/ethernet.cpp`

- [ ] Phase 3: Error handling + vectors
    - introduce safe bounds checking
    - use vectors instead of raw arrays
    - catch exceptions in main

- [ ] Phase 4: Introduce ByteBuffer class
    - now that you understand why, build the encapsulation
    - understand move semantics from context

- [ ] Phase 5: IPv4, UDP, etc.