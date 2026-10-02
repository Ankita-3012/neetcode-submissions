class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int rem = tasks.size();
        vector<int> freq(26, 0);
        vector<int> avail(26, 0);

        for(char c : tasks){
            freq[c - 'A']++;
        }

        int time=0;
        while(rem>0){
            int chosen = -1;
            for(int i=0; i<26; i++){
                if(freq[i]>0 && avail[i]<=time){
                    if(chosen == -1 || freq[i]>freq[chosen]) chosen = i;
                }
            }

            if(chosen == -1){
                time++;
                continue;
            }

            freq[chosen]--;
            rem--;
            avail[chosen] = time + n + 1;
            time++;
        }
        return time;
    }
};
