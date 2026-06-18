class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!indices.empty() &&
                   heights[indices.top()] >= currentHeight) {

                int h = heights[indices.top()];
                indices.pop();

                int leftBoundary =
                    indices.empty() ? -1 : indices.top();

                int width = i - leftBoundary - 1;

                maxArea = max(maxArea, h * width);
            }

            indices.push(i);
        }

        return maxArea;
    }
};