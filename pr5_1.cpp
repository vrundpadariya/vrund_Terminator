#include <iostream>
using namespace std;

class ExceptionDemo {
public:
	int runtime_error;
    void divideNumbers(int numerator, int denominator) {
        try {
            if (denominator == 0) {
                throw runtime_error ;0;
            }

            double result = static_cast<double>(numerator) / denominator;
            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cout << "An exception occurred: " << e.what() << endl;
        }
    }
};

int main() {
    ExceptionDemo demo;

    try {
        demo.divideNumbers(10, 2);
        demo.divideNumbers(5, 0);  // Division by zero
        demo.divideNumbers(8, 4);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

