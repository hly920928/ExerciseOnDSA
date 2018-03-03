//至少有多少只恼人的大青蛙?
//http://bailian.openjudge.cn/oitraining2016d/B/
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#define MAX 60
using namespace std;
class map;
struct Point {
	int x, y;
	Point() {};
	Point(int _x, int _y) :x(_x), y(_y) {}
	bool operator < (const Point &b) const {
		if (x != b.x) return x<b.x;
		return y<b.y;
	}
	bool operator == (const Point &b) const {
		if (x == b.x&&y == b.y) return true;
		false;
	}
};
struct Frog {
	int x, y, cnt, dx, dy, next;
	Frog() {}
	Frog(int _x, int _y, int _v, int _dx, int _dy, int nx) :x(_x), y(_y), cnt(_v), dx(_dx), dy(_dy), next(nx) {}
	Frog(const Point& p1, const Point& p2) :x(p1.x), y(p1.y), cnt(0), dx(p2.x - p1.x), dy(p2.y - p1.y), next(-1) {}
	bool operator < (const Frog &b) const {
		return cnt>b.cnt;
	}
	int isFeasible(const map& m) const;
	void applyDamage(map& m);
	void removeDamage(map& m);
};
class map {
public:
	int Map[MAX][MAX];
	int n, m, k;
	vector<Point> p;
	vector<Frog> op;
	int sum;
	int tot; int head[MAX][MAX];
	int lit;
	map() {};
	void init() {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				Map[i][j] = 0, head[i][j] = -1;
		tot = 0; sum = 0;
		p.resize(k);
		//op.resize(k*k);
		inputAllPoint();
		produceAllFrog();
	}
	void inline inputAllPoint() {
		for (int i = 0; i < k; i++) {
			int cnt = 0;
			scanf("%d %d %d", &p[i].x, &p[i].y, &cnt);
			sum += cnt;
			Map[p[i].x][p[i].y] = cnt;
		}
		sort(p.begin(), p.begin() + k);

	}
	void produceAllFrog() {
		tot = 0;
		for (int i = 0; i < k - 1; i++) {
			//if (p[i].x >= n / 2 && p[i].x != p[i + 1].x)continue;
			for (int j = i + 1; j <k; j++) {
				Frog now(p[i], p[j]);
				int cnt = now.isFeasible(*this);
				if (cnt == -1)continue;
				now.cnt = cnt;
				op.push_back(now); tot++;
			}
		}
		sort(op.begin(), op.begin() + tot);
	}
	inline bool inrange(int x, int y)const {
		if (x<1 || y<1 || x>n || y>m) return false;
		return true;
	}
	void DFS(int last, int len) {
		//printf("In DFS last is %d len is %d\n", last, len);
		if (len + 1 == lit)return;
		for (int i = last; i < tot; i++) {
			if (op[i].cnt*(lit - len) < sum)return;
			int cnt = op[i].isFeasible(*this);
			if (cnt == -1) continue;
			if (sum == op[i].cnt) {
				lit = (lit > len + 1) ? len + 1 : lit;
				return;
			}
			op[i].applyDamage(*this);
			DFS(i, len + 1);
			//printf("Return DFS last is %d len is %d\n", last, len);
			op[i].removeDamage(*this);
		}
	}
};
int Frog::isFeasible(const map& m)const {
	int now_x, now_y;
	now_x = x - dx, now_y = y - dy;
	if (cnt > 0 && cnt > m.sum)return -1;
	if (m.inrange(now_x, now_y)) return -1;
	now_x = x + 2 * dx, now_y = y + 2 * dy;
	if (!m.inrange(now_x, now_y)) return -1;
	if (m.Map[now_x][now_y] == 0)return -1;
	int count = 0;
	for (now_x = x, now_y = y; m.inrange(now_x, now_y); now_x += dx, now_y += dy)
		if (m.Map[now_x][now_y] != 0) {
			count++;
		}
		else { return -1; }
		return count;
}
void Frog::applyDamage(map& m) {
	int now_x = x; int now_y = y;
	for (; m.inrange(now_x, now_y); now_x += dx, now_y += dy)
		m.Map[now_x][now_y]--;
	m.sum -= cnt;
}
void Frog::removeDamage(map& m) {
	int now_x = x; int now_y = y;
	for (; m.inrange(now_x, now_y); now_x += dx, now_y += dy)
		m.Map[now_x][now_y]++;
	m.sum += cnt;
}
void Solve() {
	map m;
	m.init();
	m.lit = 14;
	m.DFS(0, 0);
	printf("%d\n", m.lit);
}
int main() {
	int cas;
	scanf("%d", &cas);
	while (cas--)Solve();
	return 0;
}
