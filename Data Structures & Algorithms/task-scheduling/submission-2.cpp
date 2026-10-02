class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char c : tasks){
            freq[c - 'A']++;
        }

        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            if(freq[i]>0) pq.push(freq[i]);
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> left;
            int cycle = n+1;
            int used = 0;

            while(cycle>0 && !pq.empty()){
                int cnt = pq.top();
                pq.pop();
                cnt--;
                used++;
                cycle--;
                if(cnt>0) left.push_back(cnt);
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
