class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        num = nums;
        maxN = nums.size();
        used.assign(maxN,0);
        // for (int i = 0;i < maxN;i++) used.emplace_back(0);
        findPer(0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> num;
    vector<int> cur;
    vector<int> used;
    int maxN;
    void findPer(int index){
        if (index == maxN) {
            ans.emplace_back(cur);
            return;
        }
        for (int i = 0;i < maxN ;i++){
            if (used[i] ) continue; 
            if (i && num[i] == num [i-1] && !used[i-1]) continue;
            cur.emplace_back(num[i]);
            used[i] = 1;
            findPer(index + 1);
            cur.pop_back();
            used[i] = 0;
        }
    }
};
