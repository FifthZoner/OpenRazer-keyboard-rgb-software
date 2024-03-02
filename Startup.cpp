#include <fstream>
#include <chrono>
#include <iostream>
#include "Startup.hpp"
#include "Generator.tpp"
#include "Frame.hpp"

Generator<uint8_t> BrightnessGenerator() {
    for (uint8_t n = 0; n < 255; n++) {
        co_yield n * 1;
    }
    for (uint8_t n = 255; n > 0; n--) {
        co_yield n * 1;
    }
    for (uint8_t n = 0; n < 255; n++) {
        co_yield n * 1;
    }
    co_yield 255;
}

bool DoStartup(const std::string& path) {

    std::string framePath = path + "matrix_custom_frame";
    Frame frame;
    frame.sendFrame(Color(), framePath);

    // brightness check
    {
        auto generator = BrightnessGenerator();
        std::string brightnessPath = path + "matrix_brightness";
        std::ofstream brightnessFile;
        while (generator) {
            brightnessFile.open(brightnessPath);
            if (!brightnessFile.is_open()) {
                std::cout << "Could not open brightness control file!\n";
                return false;
            }

            brightnessFile << generator() * 1;

            brightnessFile.close();
        }
    }

    // custom frame check
    {

        frame.sendFrame(Color(), framePath);
        frame.sendRows({
            {0, Color(0, 0, 255)},
            {1, Color(0, 255, 0)},
            {2, Color(255, 0, 0)},
            {3, Color(0, 0, 128)},
            {4, Color(0, 128, 0)},
            {5, Color(128, 0, 0)}
            }, framePath);

    }

    return true;
}

