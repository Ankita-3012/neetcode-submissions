class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    vector<int> arr;
    int kth;

    KthLargest(int k, vector<int>& nums) {
        
        kth = k;
        for(int num : nums){
            pq.push(num);
            if(pq.size()>kth){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        arr.push_back(val);
        pq.push(val);
        if(pq.size()>kth){
            pq.pop();
        }
        return pq.top();
    }
};
