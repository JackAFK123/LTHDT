#include <iostream>

using namespace std;

class Sum {
public:
    Sum(int a, int b) : num1(a), num2(b) {}

    int TinhSum() {
        return num1 + num2;
    }

private:
    int num1;
    int num2;
};

int main() {
    int a, b;
    cin >> a >> b;

    Sum calculator(a, b);
    int kqua = calculator.TinhSum();

    cout << kqua << endl;

    return 0;
}

