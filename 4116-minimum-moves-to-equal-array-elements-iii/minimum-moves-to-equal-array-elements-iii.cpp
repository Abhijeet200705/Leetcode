class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int max_num = nums[0];
        for(int i =1;i<n;i++){
            if(nums[i]>max_num){
                max_num = nums[i];
            }
        }
        for(int i =0;i<n;i++){
            while(nums[i]<max_num){
                nums[i]+=1;
                ans++;
            }
        }
        return ans;
    }
};