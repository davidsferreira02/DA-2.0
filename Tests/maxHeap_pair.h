//
// Created by User on 24/05/2022.
//

#ifndef DA_2_0_MAXHEAP_PAIR_H
#define DA_2_0_MAXHEAP_PAIR_H

#include <cstdint>
#include <utility>
#include <unordered_map>
#include <vector>

#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) ((i)/2)

using namespace std;

struct pair_hash {
    size_t operator () (const pair<int, int> &p) const{
        return (size_t) p.first << 32 | (unsigned int) p.second;
    }
};


using Pair = pair<int, int>;
using Unordered_map = unordered_map<Pair, int, pair_hash>;

/*!
 * Costume MaxHeap that is able to accommodate a Pair as its key
 */
class MaxHeapPair {
    struct Node { // An element of the heap: a pair (key, value)
        Pair key;
        int value;
    };

    int size;                  // Number of elements in heap
    int maxSize;               // Maximum number of elements in heap
    vector<Node> a;            // The heap array
    Unordered_map pos; // maps a key into its position on the array a
    const Pair KEY_NOT_FOUND;

    void upHeap(int i);
    void downHeap(int i);
    void swap(int i1, int i2);

public:
    MaxHeapPair(int n, const Pair& notFound); // Create a Max-heap for a max of n pairs (K,V) with notFound returned when empty
    int getSize();              // Return number of elements in the heap
    int getCapacityByKey(const Pair& key);
    bool hasKey(const Pair& key);  // Heap has key?
    void insert(const Pair& key, const int& value);      // Insert (key, value) on the heap
    bool increaseKey(const Pair& key, const int& value); // Increase value of key
    pair<Pair, int> removeMax(); // remove and return key with smaller value
};

#endif //DA_2_0_MAXHEAP_PAIR_H