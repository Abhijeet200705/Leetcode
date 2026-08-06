class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> totalgain(gain.size()+1);
        int highest=0;
        totalgain[0]=0;
        for(int i=1;i<totalgain.size();i++){
            totalgain[i]=totalgain[i-1]+gain[i-1];
            highest=max(highest,totalgain[i]);
        }
        return highest;

    }
};