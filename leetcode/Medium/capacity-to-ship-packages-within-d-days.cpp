class Solution {
public:
    int neededDays(vector<int>& weights, int cap) {
        int days = 1;
        int current = 0;
        for (int w : weights) {
            if (current + w > cap) {
                days++;
                current = 0;
            }
            current += w;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (neededDays(weights, mid) <= days)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
