#include <iostream>
#include "Frame.hpp"

Color::Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

bool Frame::sendFrame(const Color color, const std::string& path) {

    file.open(path, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Could not open custom frame file!\n";
        return false;
    }

    // drawing the colors into the frame
    for (uint8_t y = 0; y < 6; y++) {
        file << y << uint8_t(0) << uint8_t(21);
        for (uint8_t n = 0; n < 22; n++) {
            file << color.r << color.g << color.b;
        }
    }


    file.close();
    return true;
}

bool Frame::sendRows(const std::vector <std::pair<uint8_t, Color>> rows, const std::string& path) {
    file.open(path, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Could not open custom frame file!\n";
        return false;
    }

    // drawing the colors into the frame
    for (const auto& n : rows) {
        file << uint8_t(n.first) << uint8_t(0) << uint8_t(21);
        for (uint8_t m = 0; m < 22; m++) {
            file << n.second.r << n.second.g << n.second.b;
        }
    }


    file.close();
    return true;
}