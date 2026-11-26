class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        if(n==10) return true;
        int num=10;
        int diff=n-num;

        int chance=1;
        while(diff>=(num-1)){
            num=num-1;
            if(chance==1) chance=0;
            else chance=1;
            diff=diff-(num);


        }
        if(chance==1) return true;
        return false;
    }
};