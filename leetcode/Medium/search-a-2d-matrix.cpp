class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bottom = rows - 1;
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (target > matrix[mid][cols - 1])
                top = mid + 1;
            else if (target < matrix[mid][0])
                bottom = mid - 1;
            else {
                int left = 0, right = cols - 1;
                while (left <= right) {
                    int mid_c = left + (right - left) / 2;
                    if (matrix[mid][mid_c] == target)
                        return true;
                    else if (matrix[mid][mid_c] < target)
                        left = mid_c + 1;
                    else
                        right = mid_c - 1;
                }
                return false;
            }
        }

        return false;
    }
};
