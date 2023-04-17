#include <iostream>
#include <iomanip>
#include <cmath>

double closestPair(std::string filename);

int main()
{
    double min = closestPair("points250k.txt");

    //ASSERT_NEAR(min, 3.3634146364707639731e-06, 0.00000000000001e-06);
    if (std::abs(min - 3.3634146364707639731e-06) > 0.00000000000001e-06)
    {
        std::cout << std::scientific << std::setprecision(20);
        std::cout << "expected/correct value for min is 3.3634146364707639731e-06, actual value when testing " << min << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}