class Solution {
public:
   bool checkString(string s) {
    bool flag = true;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') {
            if(flag == false) return false;
        }
        else {
            flag = false;
        }
    }

    return true;
}
};