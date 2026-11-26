class Solution {
public:
    bool canAliceWin(int n) {
        int remove =10;
        int steps=0;
        while(n>=remove){
            n-=remove;
            remove--;
            steps++;
        }
        if(steps%2==0) return false;
        return true;
    }
};