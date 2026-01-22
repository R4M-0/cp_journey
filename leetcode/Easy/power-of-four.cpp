class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0) return false;
        if(n==1) return true;
        float s = (float)n;
        while(s>4.0){
            s=s/4.0;
        }
        return (s==4.0);
    }
};
