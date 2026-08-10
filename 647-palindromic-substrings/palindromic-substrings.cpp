class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            string sub="";
            for(int j=i;j<n;j++){
                sub+=s[j];
                if(isPalindrome(sub)==true) count++;
            }
        }
        return count;
    }
bool isPalindrome(string &sub){
    int left=0;
    int right=sub.size()-1;

    while(left<right){
        if(sub[left]!=sub[right]){
            return false;
        }
        left++;
        right--;

    }
    return true;
}
};