#include <vector>
#include <iostream>

#include "minHeap.h"

//using testing::ElementsAreArray;

using namespace std;

int main()
{
    vector<int> input={1,2,3,4,5,6,7,8,9,10};
    vector<int> test={1,2,3,4,5,6,7,8,9,10};
    vector<int> heapTest;
    minHeap h;

    for (int i=9; i>0; i--) swap(input[i], input[rand()%i]);

    for (int i=0; i<10; i++) h.insert(input[i]);

    for (int i=0; i<10; i++) heapTest.push_back(h.removeMin());

    //ASSERT_THAT(heapTest, ElementsAreArray(test));
    for (int i=0; i<10; i++)
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