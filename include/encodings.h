#ifndef encodings_H
#define encodings_H

// TOKENS
enum TokenType { UNDEF_TOKEN = 0, OPCODE_TOKEN, MODE_TOKEN, REGISTER_TOKEN };
typedef struct {
        char token[16];
        enum TokenType type;
} token_t;

// REGISTERS

static const token_t REGISTER_TOKENS[16] = {
    [0b0000] = {"al", REGISTER_TOKEN},
    [0b0001] = {"cl", REGISTER_TOKEN},
    [0b0010] = {"dl", REGISTER_TOKEN},
    [0b0011] = {"bl", REGISTER_TOKEN},
    [0b0100] = {"ah", REGISTER_TOKEN},
    [0b0101] = {"ch", REGISTER_TOKEN},
    [0b0110] = {"dh", REGISTER_TOKEN},
    [0b0111] = {"bh", REGISTER_TOKEN},
    [0b1000] = {"ax", REGISTER_TOKEN},
    [0b1001] = {"cx", REGISTER_TOKEN},
    [0b1010] = {"dx", REGISTER_TOKEN},
    [0b1011] = {"bx", REGISTER_TOKEN},
    [0b1100] = {"sp", REGISTER_TOKEN},
    [0b1101] = {"bp", REGISTER_TOKEN},
    [0b1110] = {"si", REGISTER_TOKEN},
    [0b1111] = {"di", REGISTER_TOKEN}};



#endif // encodings_H
