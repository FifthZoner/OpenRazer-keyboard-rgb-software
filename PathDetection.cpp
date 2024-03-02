#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

#include "PathDetection.hpp"

std::string GetKeyboardPath() {
    for (auto& n : fs::directory_iterator("/sys/bus/hid/devices/")) {
        std::string current = n.path().string() + "/";
        // not the best way to check but it finds what it needs to find
        if (fs::exists(current + "matrix_brightness") and fs::exists(current + "matrix_custom_frame")) {
            std::cout << "Found a device with expected files at: " << current << "\n";
            return current;
        }
    }
    std::cout << "No compatible device was found!\n";
    return "";
}