class Solution {
public:
    bool isPerfectSquare(int num) {
        return(floor(sqrt(num)) == sqrt(num));
    }
};
