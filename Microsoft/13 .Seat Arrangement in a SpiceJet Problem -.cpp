class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        
        
        //Solution:->https://leetcode.com/problems/airplane-seat-assignment-probability/submissions/870969554/
        //Intution what I eventually Understood

        //If p1 occupies its seat last one will be in its seat

        //if p1 occupies some other seat
        // lst person can occupy only 1 or lst whichever remains empty till last

        //so have a prob of 0.5

        if(n==1)
            return 1/(double) 1;
        else
            return 1/(double) 2;

    }
};