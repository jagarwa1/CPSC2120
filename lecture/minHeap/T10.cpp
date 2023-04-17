#include <vector>
#include <iostream>

#include "minHeap.h"

using namespace std;

int main()
{
    vector<int> input;
    vector<int> test;
    vector<int> heapTest;

    for (int i=10000000; i>0; i--) input.push_back(i);

    minHeap h(input);

    test = h.getHeap();

    //ASSERT_EQ(test.size(), 10000000);
    if (test.size() != 10000000)
    {
        std::cout << "expected/correct value for test.size() is 10000000, actual value when testing " << test.size() << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}