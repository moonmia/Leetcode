class Solution {
public:
    int consecutiveNumbersSum(int n) 
    {
        int result =1;
        for(int i=2; i<sqrt(2*n); i++)
        {
            if((n- i*(i-1)/2) % i == 0)
            {
                result++;
            }
        }
        return result;
    }
};

/*
N=(x+1)+(x+2)+⋯+(x+k) = kx+k*(k+1)/2;
2N=k(2x+k+1);
K<sqrt(2N);
*/