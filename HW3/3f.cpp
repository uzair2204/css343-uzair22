class MedianFinder {
    //Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //Max Heap
    priority_queue<int, vector<int>, less<int>> maxHeap;
    
public:
    MedianFinder() {
        
    }
    
    //Adds an integer to one of the queues based on its priority value.
    void addNum(int num) {
        maxHeap.push(num);
        num = maxHeap.top();
        maxHeap.pop();
        minHeap.push(num);
        while (minHeap.size() > maxHeap.size()) 
        {
            num = minHeap.top();
            minHeap.pop();
            maxHeap.push(num);
        }
    }
    
    //Returns either the top item from maxHeap, minHeap or (minHeap + maxHeap) / 2.
    double findMedian() {
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : double(minHeap.top() + maxHeap.top()) / 2;
    }
};
