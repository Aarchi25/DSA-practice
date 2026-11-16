class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.length()>k){
            string ans="";
             for(int i=0;i<s.length();i=i+k){
                int sum=0;
                string temp=s.substr(i,min(k, (int)s.length()));
                for(int j=0;j<temp.length();j++){
                   sum+=temp[j]-'0';
                }
             ans+=to_string(sum);
            }
            s=ans;
        }
       return s;
    }
};