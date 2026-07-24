class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        
        int closest=nums[0]+nums[1]+nums[2];
        
        int currentClosest;
        

        for(int i=0;i<n-2;i++){
            
            int l=i+1;
            int r=n-1;
            while(l<r){

                currentClosest=nums[i]+nums[l]+nums[r];
                
                if ((abs(currentClosest-target))<(abs(closest-target))){
                    closest=currentClosest;
                }
                
                if (currentClosest==target){
                    return closest;
                }
                else if(currentClosest<target){
                    l++;
                }
                else{
                    r--;
                }
            }

        }
        return closest;
    }
};