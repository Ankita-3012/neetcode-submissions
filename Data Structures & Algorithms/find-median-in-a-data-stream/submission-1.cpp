class MedianFinder {
public:
    priority_queue<int> min_heap;
    priority_queue<int, vector<int>, greater<int>> max_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap.push(num);
        max_heap.push(min_heap.top());
        min_heap.pop();

        if(max_heap.size() > min_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()){
            int a1 = min_heap.top();
            int a2 = max_heap.top();
            return (double)(a1+a2)/2.0;
        }else return min_heap.top();
    }
};
