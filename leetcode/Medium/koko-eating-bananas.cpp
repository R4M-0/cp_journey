class Solution {
public:
    long long hoursNeeded(vector<int>& piles, int k) {
        long long hours = 0;

        for (int p : piles)
            hours += (p + k - 1) / k;

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (hoursNeeded(piles, mid) <= h)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
