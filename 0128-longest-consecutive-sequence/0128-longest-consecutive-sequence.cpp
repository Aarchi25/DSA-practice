class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
         return 0;
          }
        sort(nums.begin(),nums.end());
        int longest=1,currCnt=0,lastSmaller=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==lastSmaller){
                currCnt++;
                lastSmaller=nums[i];
            }
            else if(nums[i]!=lastSmaller){
                currCnt=1;
                lastSmaller=nums[i];
            }
            longest=max(longest,currCnt);
        }
        return longest;
    }
};