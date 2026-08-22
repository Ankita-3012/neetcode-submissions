class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> vec;
        for(int i=0; i<n; i++){
            double tim = (double)(target - position[i])/speed[i];
            vec.push_back({position[i], tim});
        }

        sort(vec.begin(), vec.end(), greater<pair<int, double>>());
        int ans = 0;
        double lasttime = 0;
        for(auto & p : vec){
            double t =  p.second;
            if(t>lasttime){
                ans++;
                lasttime = t;
            }
        }
        return ans;
    }
};
