class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int count=0;
        int noOfDays=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
                if(count==k){
                    noOfDays++;
                    count=0;
                }
            }
            else{
                
                count=0;
            }
        }
        return noOfDays>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;

        int min = *min_element(bloomDay.begin(),bloomDay.end());
        int max = *max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        

        while(min<=max){
            int mid=min+(max-min)/2;

            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                max=mid-1;
            }
            else{
                min=mid+1;
            }
        }
        return ans;
    }
};