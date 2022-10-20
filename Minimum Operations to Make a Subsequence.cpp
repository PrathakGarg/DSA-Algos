class Solution {
public:
        int minOperations(vector<int>& b, vector<int>& c) {
            map<int, int> lks;  
            for (int i=0;i<b.size();i++)  lks[b[i]] = i;
            vector<int> a;
            for (int x : c)  if(lks.count(x))  a.push_back( lks[x] );
			vector<int> d;
            for (int x : a) {
                if(d.size()==0 || x>d.back()) d.push_back(x);
                else *lower_bound(d.begin(), d.end(), x) = x;
        }
        return b.size() - d.size();
    }
};
