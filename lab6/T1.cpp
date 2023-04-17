#include <iostream>
#include <iomanip>
#include <cmath>

double closestPair(std::string filename);

int main()
{
    double min = closestPair("points10.txt");

    //ASSERT_NEAR(min, 0.068553744951327016954, 0.00000000000001e-02);
    if (std::abs(min - 0.068553744951327016954) > 0.00000000000001e-02)
    {
        std::cout << std::setprecision(22);
        std::cout << "expected/correct value for min is 0.068553744951327016954, actual value when testing " << min << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}