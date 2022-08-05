// 第二周作业——子域名访问计数
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int>counts;
        unordered_map<int, int[2]>dis;
        int degree=0;
        vector<int> maxNum;
        for (int i=0 ; i<nums.size() ; i++){
            counts[nums[i]]++;
            if(degree < counts[nums[i]]){
                degree = counts[nums[i]];
                maxNum=vector<int>{nums[i]};
            }else if(degree == counts[nums[i]]) maxNum.emplace_back(nums[i]);
            if (dis.find(nums[i]) == dis.end()) dis[nums[i]][0]=dis[nums[i]][1]=i;
            else dis[nums[i]][1]=i;
        }
        int ans=nums.size();
        for (int num : maxNum) ans = min(ans,dis[num][1]-dis[num][0]+1);
        return ans;
    }
};
