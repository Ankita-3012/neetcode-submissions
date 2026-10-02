class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int siz = tasks.size();
        vector<int> freq(26, 0);

        for(char c : tasks){
            freq[c - 'A']++;
        }

        priority_queue<int> pq;
        for(int num : freq){
            if(num>0) pq.push(num);
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> left;
            int cycle = n+1;
            int used = 0;
            while(cycle>0 && !pq.empty()){
                int f = pq.top();
                pq.pop();
                f--;
                used++;
                cycle--;

                if(f>0){
                    left.push_back(f);
                }
            }

            for(int num : left){
                pq.push(num);
            }

            if(pq.empty()) time += used;
            else time += n+1;
        }

        return time;
    }
};
