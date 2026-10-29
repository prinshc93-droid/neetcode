#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // Step 1: Insert into maxHeap
        maxHeap.push(num);

        // Step 2: Move largest element to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Balance both heaps
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        // Odd number of elements
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // Even number of elements
        return ((double)maxHeap.top() + minHeap.top()) / 2.0;
    }
};