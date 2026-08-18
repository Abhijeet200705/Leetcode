class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                right++;
            }
            else{
                swap(nums[left],nums[right]);
                left++;
                right++;
            }
        }
        
    }
};