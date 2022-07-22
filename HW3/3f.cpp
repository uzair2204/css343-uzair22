class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    
public:
    MedianFinder() {
        
    }

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

    double findMedian() {
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : double(minHeap.top() + maxHeap.top()) / 2;
    }
};
