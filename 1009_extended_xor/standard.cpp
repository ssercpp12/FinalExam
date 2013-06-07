#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp(x,y) make_pair(x,y)
#define RESET(a,b) memset(a, b, sizeof(a))

int x[100010], y[100010];
int ans[100010];

int main(int argc, char* argv[]) {
  int n, m;
  while(~scanf("%d%d", &n, &m)) {
    RESET(x, 0);
    RESET(y, 0);
    int tmp;
    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      x[m - tmp - 1]++;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      y[tmp]++;
    }
    int now = 0;
    stack<pii> down;
    deque<pii> up;
    for (int i = 0; i < m; i++) {
      if (x[i] && y[i]) {
        int tmp = min(x[i], y[i]);
        for (int j = 0; j < tmp; j++)
          ans[now++] = m - 1;
        x[i] -= tmp;
        y[i] -= tmp;
      }
      if (y[i])
        down.push(mp(i, y[i]));
      while (!down.empty() && x[i]) {
        pair<int, int> dd = down.top();
        int tmp = min(x[i], dd.second);
        for (int j = 0; j < tmp; j++)
          ans[now++] = m - 1 - (i - dd.first);
        x[i] -= tmp;
        dd.second -= tmp;
        down.pop();
        if (dd.second > 0)
          down.push(dd);
      }
      if (x[i])
        up.push_back(mp(i, x[i]));
    }
    while (!up.empty()) {
      pair<int, int> uu = up.front();
      pair<int, int> dd = down.top();
      int tmp = min(uu.second, dd.second);
      for (int j = 0; j < tmp; j++)
        ans[now++] = m - 1 - (uu.first + m - dd.first);
      dd.second -= tmp;
      uu.second -= tmp;
      down.pop();
      if (dd.second > 0)
        down.push(dd);
      up.pop_front();
      if (uu.second > 0)
        up.push_front(uu);
    }
    sort(ans, ans + now);
    for (int i = now-1; i >= 0; i--) {
      if (i != now-1)
        printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
