#include <iostream>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstdint>

using namespace std;

bitset<32> floatBits(float value) {
    uint32_t raw;
    memcpy(&raw, &value, sizeof(float));
    return bitset<32>(raw);
}

string formatIEEE(float value) {
    bitset<32> bits = floatBits(value);
    string s = bits.to_string();

    // sign exponent fraction
    return s.substr(0, 1) + " " + s.substr(1, 8) + " " + s.substr(9, 23);
}

int unbiasedExponent(float value) {
    bitset<32> bits = floatBits(value);
    uint32_t raw = static_cast<uint32_t>(bits.to_ulong());

    int exponentBits = (raw >> 23) & 0xFF;

    // inputs are positive floats, and we assume
    // regular normalized values as in class examples.
    return exponentBits - 127;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Error: Incorrect number of arguments!" << endl;
        return 1;
    }

    float bound = strtof(argv[1], nullptr);
    float inc   = strtof(argv[2], nullptr);

    cout << "First value:  " << bound << endl;
    cout << formatIEEE(bound) << endl;

    cout << "Second value: " << inc << endl;
    cout << formatIEEE(inc) << endl;

    int boundExp = unbiasedExponent(bound);
    int incExp = unbiasedExponent(inc);

    const int PRECISION_BITS = 24;

    if ((boundExp - incExp) >= PRECISION_BITS) {
        int thresholdExp = incExp + PRECISION_BITS;
        float threshold = ldexp(1.0f, thresholdExp);  // 2^(thresholdExp)

        cout << "Warning: Possible overflow!" << endl;
        cout << "Overflow threshold:" << endl;
        cout << threshold << endl;
        cout << formatIEEE(threshold) << endl;
    } else {
        cout << "No overflow!" << endl;
    }

    return 0;
}
