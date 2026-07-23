class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1;
        int maxArea= 0;
        int h;

        while(left<right){
            h=min(height[left],height[right]);
            int w=right-left;
            int area=h*w;
            maxArea=max(area,maxArea);
            if (height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            

        }
        return maxArea;
    }
    
};