class Solution {
public:
    bool canAliceWin(int n) {
        int remove=10;
        bool Awin=true;

        while(n>=remove){
            n-=remove;
            remove--;
            Awin=!Awin;
        }
        return !Awin;
    }
};