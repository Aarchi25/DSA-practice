class Solution {
public:
    int maxVowels(string s, int k) {
        int maxV = 0,count=0,n=s.length(),i=0,j=0;

        while(j<n){
            char ch=s[j];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
                count++;
            if(j-i+1==k){
                maxV=max(maxV,count);
                char ch=s[i];
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count--;
                i++;
            }
            j++;
        }

        return maxV;
    }
};