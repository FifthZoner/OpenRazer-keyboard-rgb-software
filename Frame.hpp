#ifndef OPENRAZERKEYBOARDSCREENCAPTURE_FRAME_HPP
#define OPENRAZERKEYBOARDSCREENCAPTURE_FRAME_HPP

#include <cstdint>
#include <array>
#include <string>
#include <fstream>
#include <vector>

struct Color {
    uint8_t r = 255;
    uint8_t g = 255;
    uint8_t b = 255;
    Color() = default;
    Color(uint8_t r, uint8_t g, uint8_t b);
};

struct Frame {
    std::ofstream file;
    Frame() = default;
    bool sendFrame(Color color, const std::string& path);
    bool sendRows(std::vector <std::pair<uint8_t, Color>> rows, const std::string& path);
};

#endif //OPENRAZERKEYBOARDSCREENCAPTURE_FRAME_HPP
