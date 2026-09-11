class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int count=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='('){
                count++;
                ans=max(ans,count);
            }
            else if(s[i] == ')') {
                count--;
            }


            i++;
        }
        return ans;
    }
};