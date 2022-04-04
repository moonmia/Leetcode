class Solution {
public:
    //反转字符串
    void reverse(string& s,int start,int end){
        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
    //移除多余空格，利用快慢指针
    void removeExtraSpaces(string&s){
        int slow=0,fast=0;
        //移除开始位置的空格
        while(s[fast]==' '){
            fast++;
        }
        //移除中间位置多余的空格
        while(fast<s.size()){
            if(fast>0 && s[fast]==' ' &&s[fast-1]==' '){
                fast++;
            }
            else{
                s[slow]=s[fast];
                slow++;
                fast++;
            }
        }
        //如果末尾仅有一个空格，则上述无法将该空格移除；如果末尾有很多空格，则上述将保留一个空格，也不符合要求；所以最终可能的情况有二：末尾有一个空格/末尾无空格
        
        if(slow-1>0 && s[slow-1]==' '){
            slow--;
        }
        s.resize(slow);
    }
        
    string reverseWords(string s) {
        //step1.移除多余空格
        removeExtraSpaces(s);
        //step2.反转整个字符串
        reverse(s,0,s.size()-1);
        //step3.依次反转每个单词
        int start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s,start,i-1);
                start=i+1;
            }
            if(i==s.size()-1){
                reverse(s,start,i);
            }
        }
        return s;
    }
};