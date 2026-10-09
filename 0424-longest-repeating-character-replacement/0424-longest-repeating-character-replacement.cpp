class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxLen=0,maxF=0;
        int hash[26];
        fill(hash,hash+26,0);
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxF=max(maxF,hash[s[r]-'A']);
            while((r-l+1)-maxF>k){
                hash[s[l]-'A']--;
                maxF=0;
                for(int i=0;i<26;i++){
                    maxF=max(maxF,hash[i]);
                }
                l++;
            }
            if((r-l+1)-maxF<=k) maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;

    }
};