#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>
 
using namespace std;
 
int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    int n, m, K;
    scanf("%d%d%d", &n, &m, &K);
    vector<int> h(n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
      int target = max(0, h[i + 1] - K);
      if (target < h[i]) {
        m += h[i] - target;
      } else if (target - h[i] > m){
        ans = false;
        break;
      } else {
        m -= (target - h[i]);
      }
    }
    if (ans) puts("YES");
    else puts("NO");
  }
  return 0;
}