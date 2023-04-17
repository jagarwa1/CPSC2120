#include <vector>
#include <iostream>

#include "minHeap.h"

//using testing::ElementsAreArray;

using namespace std;

int main()
{
    vector<int> input={1,2,3,4,5,11,12,13,14,15};
    vector<int> test={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> heapTest;

    for (int i=9; i>0; i--) swap(input[i], input[rand()%i]);

    minHeap h(input);

    h.insert(6);
    h.insert(10);
    h.insert(7);
    h.insert(9);
    h.insert(8);

    for (int i=0; i<15; i++) heapTest.push_back(h.removeMin());

    //ASSERT_THAT(heapTest, ElementsAreArray(test));
    for (int i=0; i<15; i++)
    {
        if (heapTest[i] != test[i])
        {
            std::cout << "Mismatch in heapTest at position " << i << ": expected/correct value " << test[i] << ", actual value when testing " << heapTest[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}