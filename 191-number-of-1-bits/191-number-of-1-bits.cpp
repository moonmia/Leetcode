class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count =0;
        
        while (n)
        {
            n &= (n-1);
            count++;
        }
        return count;
    }
};
// x &= (x-1) every time remove the last binary number '1'.
//o(logn), o(1)