#include <iostream>
#include <iomanip>
#include <cmath>

double closestPair(std::string filename);

int main()
{
    double min = closestPair("points100.txt");

    //ASSERT_NEAR(min, 0.0059037057681839430825, 0.00000000000001e-03);
    if (std::abs(min - 0.0059037057681839430825) > 0.00000000000001e-03)
    {
        std::cout << std::setprecision(23);
        std::cout << "expected/correct value for min is 0.0059037057681839430825, actual value when testing " << min << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}