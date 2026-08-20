class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=INT_MIN;
        int st=0;
        int ansStart=-1;
        int ansEnd=-1;

        for(int i=0 ; i<n ;i++){
            sum+=nums[i];
            st=i;

            maxi=max(sum,maxi);
            ansStart=st,ansEnd=i;
            if(sum<0){
                sum=0;
                st=i+1;
            }
        }
        return maxi;
    }
};