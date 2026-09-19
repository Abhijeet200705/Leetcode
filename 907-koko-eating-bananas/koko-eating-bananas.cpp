class Solution {
public:
    long long func(vector<int>& piles, int k){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=(piles[i] + k - 1) / k;
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(), piles.end());

        while(low<=high){
            int k=low+(high-low)/2;
            long long mHpP=func(piles,k);
            if(mHpP<=h) {
                high=k-1;
            }
            else{
                low=k+1;
            }   
        }
        return low;
    }
};