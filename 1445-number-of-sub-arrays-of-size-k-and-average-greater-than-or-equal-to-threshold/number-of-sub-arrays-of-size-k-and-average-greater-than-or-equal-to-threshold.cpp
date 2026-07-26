class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int count=0;
        int avgSum=(double)sum/k;
        if(avgSum>=threshold){
            count++;
        }
        for(int i=k;i<n;i++){
            sum+=arr[i];
            sum-=arr[i-k];
            avgSum=(double)sum/k;
            if(avgSum>=threshold){
                count++;
            }
        }
        return count;
    }
};