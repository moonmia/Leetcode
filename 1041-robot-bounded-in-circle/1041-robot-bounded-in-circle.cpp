class Solution {
public:
    bool isRobotBounded(string instructions) 
    {
        int dirs[4][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};
        int di =0; // UP
        int circle=0, start=0;
        for(char ins : instructions)
        {
            if(ins == 'G')
            {
                circle += dirs[di][0];
                start += dirs[di][1];
            }
            else if(ins == 'L')
            {
                di = (di-1+4)%4;
            }
            else
            {
                di = (di+1)%4;
            }
        }
        return ( (circle ==0 && start ==0) || (di != 0) );
    }
};