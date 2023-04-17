#include "minHeap.h"



void minHeap::siftUp(int pos){
    if(pos == 0)
        return;

    int parent = (pos - 1);

    if(heap[parent] > heap[pos]){
        swap(heap[pos], heap[parent]);
        siftUp(parent);
    }
}

void minHeap::siftDown(int pos){
    // if(pos == 0)
    //     return;

    // int child = (pos + 1);

    // if(heap[child] < heap[pos]){
    //     swap(heap[pos], heap[child]);
    //     siftDown(child);
    // }

    int leftChildIndex = 2 * pos + 1;
    int rightChildIndex = 2 * pos + 2;

    if(leftChildIndex >= heap.size())
        return; //index is a leaf

    int minIndex = pos;

    if(heap[pos] > heap[leftChildIndex])
        minIndex = leftChildIndex;
    
    if((rightChildIndex < heap.size()) && (heap[minIndex] > heap[rightChildIndex]))
        minIndex = rightChildIndex;

    if(minIndex != pos){
        //need to swap
        swap(heap[minIndex], heap[pos]);
        siftDown(minIndex);
    }
}

void minHeap::insert(int value){
    heap.push_back(value);
    siftUp(heap.size()-1);
}

int minHeap::removeMin(){
    int min = heap[0];
    swap(heap[heap.size()-1], heap[0]);
    heap.pop_back();
    siftDown(0);
    return min;
}
