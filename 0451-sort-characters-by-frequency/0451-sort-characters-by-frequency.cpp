class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto  ch:s) freq[ch]++;
        vector<pair<char,int>>freqArr;
        for(auto[ch,fq]:freq) freqArr.push_back({ch,fq});
        auto cmp=[&](pair<char,int>&a,pair<char,int>&b){
            return a.second>b.second;
        };
        sort(freqArr.begin(),freqArr.end(),cmp);
        string ans="";
        for(auto[ch,fq]:freqArr) ans.append(fq,ch);
        return ans;

    }
};