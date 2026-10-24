class Solution {
public:
    
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int convert(string &s){
        string m,d;
        m+=s[0];
        m+=s[1];

        d+=s[3];
        d+=s[4];
        int cnt=0,mm,dd;
        mm=stoi(m);
        dd=stoi(d);
        for(int i=0;i<mm;i++){
            cnt+=month[i];
        }
        cnt+=dd;
        return cnt;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arr1=convert(arriveAlice);
        int arr2=convert(arriveBob);
        int lev1=convert(leaveAlice);
        int lev2=convert(leaveBob);
        int start=max(arr1,arr2);
        int end=min(lev1,lev2);
        if(start>end) return 0;
        return end-start+1;
    }
};