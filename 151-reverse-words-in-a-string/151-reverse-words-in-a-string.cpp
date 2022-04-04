class Solution {
public:
    void reversed(int start, int end, string &s){
        while(start<end){
            swap(s[start++], s[end--]);
        }
    }
    
    void removeSpace(string &s){
        int left=0, right=0;
        int n = s.size();
        //Remove the front space
        while(s[right] == ' '){
            right++;
        }
        //Rove the middle extra space
        while(right < n){
            if(right > 0 && s[right] == ' ' && s[right-1] == ' ') right++;
            else{
                s[left] = s[right];
                left++;
                right++;
            }
        }
        
        while(left-1 >0 && s[left-1] == ' ') left--;
        s.resize(left);
        
    }
    
    string reverseWords(string s) 
    {
        removeSpace(s);
        int start = 0, end = s.size()-1;
        reversed(start, end, s);
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                reversed(start, i-1, s);
                start = i+1;
            }
            if(i == s.size()-1){
                reversed(start, i, s);
            }
        }
        return s;
    }
};