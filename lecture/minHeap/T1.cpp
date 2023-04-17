#include <vector>
#include <iostream>

#include "minHeap.h"

//using testing::ElementsAreArray;

using namespace std;

int main()
{
  vector<int> test={1,2,3,4,5,6,7,8,9,10};
  vector<int> heapTest;
  minHeap h;

  h.insert(1);
  h.insert(2);
  h.insert(3);
  h.insert(4);
  h.insert(5);
  h.insert(6);
  h.insert(7);
  h.insert(8);
  h.insert(9);
  h.insert(10);



  vector<int> newVector = h.getHeap();

  for (int i=0; i<10; i++)
  {
    cout << newVector[i] << endl;
    heapTest.push_back(h.removeMin());
  }

  // //ASSERT_THAT(heapTest, ElementsAreArray(test));
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