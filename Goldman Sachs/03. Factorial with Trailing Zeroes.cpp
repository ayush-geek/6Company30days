
class Solution {
public:
    int trailingZeroes(int n) {
        

        //Punch fact(25) has 5(1)  +1 (1) 
        //Perfect square of 5,25,625,...
        int c=0;
        int s=5;

        while(s<=n)
        {
            c+=n/s;
            s*=5;
        
        
        }
        return c;
    }   
};