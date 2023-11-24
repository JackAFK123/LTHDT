#include <iostream>
#include <cmath>

using namespace std;

class gtri {
public:
    gtri(int a) : value(a) {}

    gtri operator+(const gtri& other) const {
        return gtri(value + other.value);
    }

    gtri operator-(const gtri& other) const {
        return gtri(value - other.value);
    }

    gtri operator*(const gtri& other) const {
        return gtri(value * other.value);
    }

    gtri abs() const {
        return gtri(std::abs(value));
    }

    int getValue() const {
        return value;
    }

private:
    int value;
};

int main() {
    gtri result = gtri(3) + (gtri(4) - gtri(-5).abs()) * gtri(6);
    
    cout << result.getValue();
    cout << std::noboolalpha << endl;

    return 0;
}

