#include "PathDetection.hpp"
#include "Startup.hpp"

int main() {
    std::string path = GetKeyboardPath();
    if (path.length() == 0) {
        return 1;
    }

    if (!DoStartup(path)) {
        return 1;
    }


    return 0;
}
