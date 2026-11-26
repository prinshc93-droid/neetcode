

class CountSquares {
private:
    unordered_map<int, unordered_map<int, int>> points;

    public:
        CountSquares() {
                
                    }

                        void add(vector<int> point) {
                                int x = point[0];
                                        int y = point[1];

                                                points[x][y]++;
                                                    }

                                                        int count(vector<int> point) {
                                                                int x = point[0];
                                                                        int y = point[1];

                                                                                int ans = 0;

                                                                                        for (auto& [x2, ys] : points) {
                                                                                                    for (auto& [y2, freq] : ys) {

                                                                                                                    if (abs(x2 - x) != abs(y2 - y) ||
                                                                                                                                        x2 == x || y2 == y) {
                                                                                                                                                            continue;
                                                                                                                                                                            }

                                                                                                                                                                                            ans += freq *
                                                                                                                                                                                                                   points[x][y2] *
                                                                                                                                                                                                                                          points[x2][y];
                                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                              }

                                                                                                                                                                                                                                                                      return ans;
                                                                                                                                                                                                                                                                          }
                                                                                                                                                                                                                                                                          };
                                                                                                                                                                                                                                                                          