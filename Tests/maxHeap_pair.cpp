//
// Created by User on 04/06/2022.
//

#include <iostream>
#include "maxHeap_pair.h"

// ----------------------------------------------

// Make a value go "up the tree" until it reaches its position
void MaxHeapPair::upHeap(int i) {
    while (i>1 && a[i].value > a[PARENT(i)].value) { // while pos bigger than parent, keep swapping to upper position
        swap(i, PARENT(i));
        i = PARENT(i);
    }
}


// Make a value go "down the tree" until it reaches its position
void MaxHeapPair::downHeap(int i) {
    while (LEFT(i) <= size) { // while within heap limits
        int j = LEFT(i);
        if (RIGHT(i)<=size && a[RIGHT(i)].value > a[j].value) j = RIGHT(i); // choose bigger child
        if (a[i].value > a[j].value) break;   // node already bigger child, stop
        swap(i, j);                    // otherwise, swap with bigger child
        i = j;
    }
}

// Swap two positions of the heap (update their positions)
void MaxHeapPair::swap(int i1, int i2) {
    Node tmp = a[i1]; a[i1] = a[i2]; a[i2] = tmp;
    pos[a[i1].key] = i1;
    pos[a[i2].key] = i2;
}

// ----------------------------------------------

// Create a Max-heap for a max of n pairs (K,V) with notFound returned when empty
MaxHeapPair::MaxHeapPair(int n, const Pair& notFound) : KEY_NOT_FOUND(notFound), size(0), maxSize(n), a(n+1) {
}

// Return number of elements in the heap
int MaxHeapPair::getSize() {
    return size;
}

int MaxHeapPair::getCapacityByKey(const Pair &key) {
    if(hasKey(key)){
        int i = pos[key];
        return a[i].value;
    }
    else{
        return 0;
    }
}

// Heap has key?
bool MaxHeapPair::hasKey(const Pair& key) {
    return pos.find(key) != pos.end();
}

// Insert (key, value) on the heap
void MaxHeapPair::insert(const Pair& key, const int& value) {
    if (size == maxSize) {std::cout << "error"; return;} // heap is full, do nothing
    if (hasKey(key)) return;     // key already exists, do nothing
    a[++size] = {key, value};
    pos[key] = size;
    upHeap(size);
}

// Decrease value of key to the indicated value
//Return false if there is no key to increase
bool MaxHeapPair::increaseKey(const Pair &key, const int &value) {
    if (!hasKey(key)) return false; // key does not exist, do nothing
    int i = pos[key];
    if (value < a[i].value) return true; // value would decrease, do nothing
    a[i].value = value;
    upHeap(i);
    return true;
}

// remove and return key with smaller value
pair<Pair, int> MaxHeapPair::removeMax() {
    if (size == 0) return {KEY_NOT_FOUND, -1};
    pair<Pair, int> ret;
    Pair max = a[1].key;
    int cap = a[1].value;
    ret.first = max; ret.second = cap;
    pos.erase(max);
    a[1] = a[size--];
    downHeap(1);
    return ret;
}