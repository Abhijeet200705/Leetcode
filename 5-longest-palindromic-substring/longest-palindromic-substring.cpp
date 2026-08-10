class Solution {
public:
    string longestPalindrome(string s) {
        string resultant="";
        for(int i=0; i<s.size();i++){
            for(int j=i; j<s.size();j++){
                if(isPalindrome(s,i,j)==true){
                    if((j-i+1)>resultant.size()){
                        resultant=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return resultant;
    }

private:
    bool isPalindrome(string &s, int left, int right){

        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
            
        }
        return true;
    }
};