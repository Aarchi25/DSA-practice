class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>&nums,int k){
        if(k<0) return 0;
        int l=0,r=0,cnt=0,sum=0;
        while(r<nums.size()){
            sum+=(nums[r]%2);
            while(sum>k){
                sum=sum-(nums[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
};