#include <stdio.h>

/// @brief Returns the X coordinate of the centre of an ANSI keycap. Based on a
/// PNG pulled from Wikipedia.
int getX(char c) {
    switch (c) {
    case 'q':
        return 119;
    case 'w':
        return 175;
    case 'e':
        return 231;
    case 'r':
        return 285;
    case 't':
        return 341;
    case 'y':
        return 397;
    case 'u':
        return 453;
    case 'i':
        return 508;
    case 'o':
        return 562;
    case 'p':
        return 619;
    case 'a':
        return 145;
    case 's':
        return 201;
    case 'd':
        return 257;
    case 'f':
        return 315;
    case 'g':
        return 368;
    case 'h':
        return 424;
    case 'j':
        return 480;
    case 'k':
        return 538;
    case 'l':
        return 592;
    case 'z':
        return 168;
    case 'x':
        return 224;
    case 'c':
        return 278;
    case 'v':
        return 332;
    case 'b':
        return 385;
    case 'n':
        return 439;
    case 'm':
        return 493;
    default:
        fprintf(stderr, "Error in getX(). Could not find %d\n", c);
        return 0;
    }
}

///@brief Returns the Y coordinate of the centre of an ANSI keycap. Based on a
/// PNG pulled from Wikipedia.
int getY(char c) {
    switch (c) {
    case 'q':
    case 'w':
    case 'e':
    case 'r':
    case 't':
    case 'y':
    case 'u':
    case 'i':
    case 'o':
    case 'p':
        return 91;
    case 'a':
    case 's':
    case 'd':
    case 'f':
    case 'g':
    case 'h':
    case 'j':
    case 'k':
    case 'l':
        return 147;
    case 'z':
    case 'x':
    case 'c':
    case 'v':
    case 'b':
    case 'n':
    case 'm':
        return 203;
    default:
        fprintf(stderr, "Error in getY(). Could not find %d\n", c);
        return 0;
    }
}