
class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size();
        int n = num2.size();

        vector<int> ans(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b + ans[i + j + 1];

                ans[i + j + 1] = product % 10;

                ans[i + j] += product / 10;
            }
        }

        string result;

        for (int digit : ans) {

            if (result.empty() && digit == 0)
                continue;

            result += char(digit + '0');
        }

        return result;
    }
};
