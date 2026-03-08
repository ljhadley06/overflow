#include <iostream>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdint>

using namespace std;

bitset<32> floatBits(float value) {
    uint32_t raw;
    memcpy(&raw, &value, sizeof(float));
    return bitset<32>(raw);
}

string formatIEEE(float value) {
    string s = floatBits(value).to_string();
    return s.substr(0, 1) + " " + s.substr(1, 8) + " " + s.substr(9, 23);
}

int unbiasedExponent(float value) {
    uint32_t raw;
    memcpy(&raw, &value, sizeof(float));
    int exponentBits = (raw >> 23) & 0xFF;
    return exponentBits - 127;
}

void printUsage(const char* programName) {
    cout << "usage: " << programName << " loop_bound loop_counter" << endl;
    cout << endl;
    cout << "    loop_bound is a positive floating-point value" << endl;
    cout << "    loop_counter is a positive floating-point value" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return 1;
    }

    float loopBound = strtof(argv[1], nullptr);
    float loopCounter = strtof(argv[2], nullptr);

    cout << "loop bound:   " << formatIEEE(loopBound) << endl;
    cout << "loop counter: " << formatIEEE(loopCounter) << endl;
    cout << endl;

    int boundExp = unbiasedExponent(loopBound);
    int counterExp = unbiasedExponent(loopCounter);

    const int PRECISION_BITS = 24;

    if ((boundExp - counterExp) >= PRECISION_BITS) {
        int thresholdExp = counterExp + PRECISION_BITS;

        uint32_t thresholdRaw = static_cast<uint32_t>(thresholdExp + 127) << 23;
        float threshold;
        memcpy(&threshold, &thresholdRaw, sizeof(float));

        cout << "Warning: Possible overflow!" << endl;
        cout << "Overflow threshold:" << endl;
        cout << threshold << endl;
        cout << formatIEEE(threshold) << endl;
    } else {
        cout << "There is no overflow!" << endl;
    }

    return 0;
}
