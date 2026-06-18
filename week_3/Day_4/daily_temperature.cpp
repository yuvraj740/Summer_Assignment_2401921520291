class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> pending;

        for (int i = 0; i < n; i++) {
            while (!pending.empty() &&
                   temperatures[i] > temperatures[pending.top()]) {
                
                int prevDay = pending.top();
                pending.pop();

                answer[prevDay] = i - prevDay;
            }

            pending.push(i);
        }

        return answer;
    }
};