
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

            vector<int> freq(26, 0);

                    // Step 1: Count frequencies
                            for (char task : tasks) {
                                        freq[task - 'A']++;
                                                }

                                                        // Step 2: Find maximum frequency
                                                                int maxFreq = 0;

                                                                        for (int f : freq) {
                                                                                    maxFreq = max(maxFreq, f);
                                                                                            }

                                                                                                    // Step 3: Count tasks with maximum frequency
                                                                                                            int countMax = 0;

                                                                                                                    for (int f : freq) {
                                                                                                                                if (f == maxFreq) {
                                                                                                                                                countMax++;
                                                                                                                                                            }
                                                                                                                                                                    }

                                                                                                                                                                            // Step 4: Calculate minimum intervals
                                                                                                                                                                                    int result = max(
                                                                                                                                                                                                (int)tasks.size(),
                                                                                                                                                                                                            (maxFreq - 1) * (n + 1) + countMax
                                                                                                                                                                                                                    );

                                                                                                                                                                                                                            return result;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                };
                                                                                                                                                                                                                                
