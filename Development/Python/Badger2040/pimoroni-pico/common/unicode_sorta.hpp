#pragma once

#include <cstdint>

/*
This file exists to allow space-efficient rendering of accented characters.

It permits rudimentary support for unicode characters by providing a lookup
table to map anything prefixed with 0xc3 to its non-accented equivilent.
*/

namespace unicode_sorta {

const char PAGE_194_START = 194;
const char PAGE_195_START = 195;

// Codepage is probably completely the wrong terminology here
// but character pairs come in the form 0xc2 0x00 and 0xc3 0x00.
enum codepage_t : uint8_t {
    PAGE_194,
    PAGE_195
};

const uint8_t UNICODE_PREFIX = 0xc3;

enum accents : uint8_t {
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_TILDE,
    ACCENT_DIAERESIS,
    ACCENT_RING_ABOVE,
    ACCENT_STROKE,
    ACCENT_CEDILLA,
    ACCENT_NONE,
};

static const accents char_accent[] = {
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_TILDE,
    ACCENT_DIAERESIS,
    ACCENT_RING_ABOVE,
    ACCENT_NONE,
    ACCENT_CEDILLA,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_DIAERESIS,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_DIAERESIS,
    ACCENT_NONE,
    ACCENT_TILDE,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_TILDE,
    ACCENT_DIAERESIS,
    ACCENT_NONE,
    ACCENT_STROKE,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_DIAERESIS,
    ACCENT_ACUTE,
    ACCENT_NONE,
    ACCENT_NONE,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_TILDE,
    ACCENT_DIAERESIS,
    ACCENT_RING_ABOVE,
    ACCENT_NONE,
    ACCENT_CEDILLA,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_DIAERESIS,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_DIAERESIS,
    ACCENT_NONE,
    ACCENT_TILDE,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_TILDE,
    ACCENT_DIAERESIS,
    ACCENT_NONE,
    ACCENT_STROKE,
    ACCENT_GRAVE,
    ACCENT_ACUTE,
    ACCENT_CIRCUMFLEX,
    ACCENT_DIAERESIS,
    ACCENT_ACUTE,
    ACCENT_NONE,
    ACCENT_DIAERESIS
};

// Codepage 194. Starts at 0x80 but the first 32 are non-printable
// Since we're already implementing LUTs for various accented characters,
// it makes sense for us poor brits to grab a usable ??, too!
static const char char_base_194[] = {
    ' ', //   - c2 a0 - NO-BREAK SPACE
    'i', // ?? - c2 a1 - INVERTED EXCLAMATION MARK
    ' ', // ?? - c2 a2 - CENT SIGN
    '\x85', // ?? - c2 a3 - POUND SIGN
    ' ', // ?? - c2 a4 - CURRENCY SIGN
    '\x86', // ?? - c2 a5 - YEN SIGN
    ' ', // ?? - c2 a6 - BROKEN BAR
    'S', // ?? - c2 a7 - SECTION SIGN
    ' ', // ?? - c2 a8 - DIAERESIS
    '\x87', // ?? - c2 a9 - COPYRIGHT SIGN
    'a', // ?? - c2 aa - FEMININE ORDINAL INDICATOR
    '<', // ?? - c2 ab - LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
    ' ', // ?? - c2 ac - NOT SIGN
    ' ', // ?? - c2 ad - SOFT HYPHEN
    'R', // ?? - c2 ae - REGISTERED SIGN
    ' ', // ?? - c2 af - MACRON
    '\x88', // ?? - c2 b0 - DEGREE SIGN
    ' ', // ?? - c2 b1 - PLUS-MINUS SIGN
    '2', // ?? - c2 b2 - SUPERSCRIPT TWO
    '3', // ?? - c2 b3 - SUPERSCRIPT THREE
    ' ', // ?? - c2 b4 - ACUTE ACCENT
    ' ', // ?? - c2 b5 - MICRO SIGN
    ' ', // ?? - c2 b6 - PILCROW SIGN
    ' ', // ?? - c2 b7 - MIDDLE DOT
    ' ', // ?? - c2 b8 - CEDILLA
    ' ', // ?? - c2 b9 - SUPERSCRIPT ONE
    ' ', // ?? - c2 ba - MASCULINE ORDINAL INDICATOR
    ' ', // ?? - c2 bb - RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
    ' ', // ?? - c2 bc - VULGAR FRACTION ONE QUARTER
    ' ', // ?? - c2 bd - VULGAR FRACTION ONE HALF
    ' ', // ?? - c2 be - VULGAR FRACTION THREE QUARTERS
    ' ', // ?? - c2 bf - INVERTED QUESTION MARK
};

// Codepage 195. Starts at 0x80
static const char char_base_195[] = {
    'A', // ?? - c3 80 - A + GRAVE
    'A', // ?? - c3 81 - A + ACUTE
    'A', // ?? - c3 82 - A + CIRCUMFLEX
    'A', // ?? - c3 83 - A + TILDE
    'A', // ?? - c3 84 - A + DIAERESIS
    'A', // ?? - c3 85 - A + RING ABOVE
    '\x80', // ?? - c3 86 - AE
    'C', // ?? - c3 87 - C + CEDILLA
    'E', // ?? - c3 88 - E + GRAVE
    'E', // ?? - c3 89 - E + ACUTE
    'E', // ?? - c3 8a - E + CIRCUMFLEX
    'E', // ?? - c3 8b - E + DIAERESIS
    'I', // ?? - c3 8c - I + GRAVE
    'I', // ?? - c3 8d - I + ACUTE
    'I', // ?? - c3 8e - I + CIRCUMFLEX
    'I', // ?? - c3 8f - I + DIAERESIS
    'D', // ?? - c3 90 - ETH
    'N', // ?? - c3 91 - N + TILDE
    'O', // ?? - c3 92 - O + GRAVE
    'O', // ?? - c3 93 - O + ACUTE
    'O', // ?? - c3 94 - O + CIRCUMFLEX
    'O', // ?? - c3 95 - O + TILDE
    'O', // ?? - c3 96 - O + DIAERESIS
    'x', // ?? - c3 97 - MULTIPLICATION SIGN
    'O', // ?? - c3 98 - O + STROKE
    'U', // ?? - c3 99 - U + GRAVE
    'U', // ?? - c3 9a - U + ACUTE
    'U', // ?? - c3 9b - U + CIRCUMFLEX
    'U', // ?? - c3 9c - U + DIAERESIS
    'Y', // ?? - c3 9d - Y + ACUTE
    '\x81', // ?? - c3 9e - THORN
    '\x82', // ?? - c3 9f - SHARP S
    'a', // ?? - c3 a0 - A + GRAVE
    'a', // ?? - c3 a1 - A + ACUTE
    'a', // ?? - c3 a2 - A + CIRCUMFLEX
    'a', // ?? - c3 a3 - A + TILDE
    'a', // ?? - c3 a4 - A + DIAERESIS
    'a', // ?? - c3 a5 - A + RING ABOVE
    '\x83', // ?? - c3 a6 - AE
    'c', // ?? - c3 a7 - C + CEDILLA
    'e', // ?? - c3 a8 - E + GRAVE
    'e', // ?? - c3 a9 - E + ACUTE
    'e', // ?? - c3 aa - E + CIRCUMFLEX
    'e', // ?? - c3 ab - E + DIAERESIS
    'i', // ?? - c3 ac - I + GRAVE
    'i', // ?? - c3 ad - I + ACUTE
    'i', // ?? - c3 ae - I + CIRCUMFLEX
    'i', // ?? - c3 af - I + DIAERESIS
    'o', // ?? - c3 b0 - ETH
    'n', // ?? - c3 b1 - N + TILDE
    'o', // ?? - c3 b2 - O + GRAVE
    'o', // ?? - c3 b3 - O + ACUTE
    'o', // ?? - c3 b4 - O + CIRCUMFLEX
    'o', // ?? - c3 b5 - O + TILDE
    'o', // ?? - c3 b6 - O + DIAERESIS
    '/', // ?? - c3 b7 - DIVISION SIGN
    'o', // ?? - c3 b8 - O + STROKE
    'u', // ?? - c3 b9 - U + GRAVE
    'u', // ?? - c3 ba - U + ACUTE
    'u', // ?? - c3 bb - U + CIRCUMFLEX
    'u', // ?? - c3 bc - U + DIAERESIS
    'y', // ?? - c3 bd - Y + ACUTE
    '\x84', // ?? - c3 be - THORN
    'y', // ?? - c3 bf - Y + DIAERESIS
};

}