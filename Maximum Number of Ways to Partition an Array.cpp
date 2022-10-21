class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        vector<long> prefix(1); 
        unordered_map<long, vector<int>> mp; 
        for (int i = 0; i < nums.size(); ++i) {
            prefix.push_back(prefix[i] + nums[i]); 
            if (i < nums.size()-1) mp[prefix[i+1]].push_back(i); 
        }
        
        int ans = 0; 
        long total = prefix.back(); 
        if (total % 2 == 0) ans = mp[total/2].size(); 
        
        for (int i = 0; i < nums.size(); ++i) {
            int diff = k - nums[i], val = 0; 
            long target = total + diff; 
            if (target % 2 == 0) {
                target /= 2; 
                val += lower_bound(mp[target].begin(), mp[target].end(), i) - mp[target].begin(); 
                val += mp[target-diff].size() - (lower_bound(mp[target-diff].begin(), mp[target-diff].end(), i) - mp[target-diff].begin()); 
            }
            ans = max(ans, val); 
        }
        return ans; 
    }
};
