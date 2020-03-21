#include <assert.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int64_t CYCLES_PER_SEC = 2400000000;
const double TIMELIMIT = 2.8;
struct Timer {
	int64_t start;
	Timer() { reset(); }
	void reset() { start = getCycle(); }
	void plus(double a) { start -= (a * CYCLES_PER_SEC); }
	inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
	inline int64_t getCycle() {
		uint32_t low, high;
		__asm__ volatile("rdtsc"
						 : "=a"(low), "=d"(high));
		return ((int64_t)low) | ((int64_t)high << 32);
	}
};
class XorShift {
   public:
	unsigned int x, y, z, w;
	double nL[65536];

	XorShift() {
		init();
	}

	void init() {
		x = 314159265;
		y = 358979323;
		z = 846264338;
		w = 327950288;
		double n = 1 / (double)(2 * 65536);
		for (int i = 0; i < 65536; i++) {
			nL[i] = log(((double)i / 65536) + n);
		}
	}

	inline unsigned int next() {
		unsigned int t = x ^ x << 11;
		x = y;
		y = z;
		z = w;
		return w = w ^ w >> 19 ^ t ^ t >> 8;
	}

	inline double nextLog() {
		return nL[next() & 0xFFFF];
	}

	inline int nextInt(int m) {
		return (int)(next() % m);
	}

	int nextInt(int min, int max) {
		return min + nextInt(max - min + 1);
	}

	inline double nextDouble() {
		return (double)next() / ((long long)1 << 32);
	}
};
XorShift rnd;
int ask(int a) {
	cout << a << '\n'
		 << flush;
	cin >> a;
	return a;
}
int main(int argc, char *argv[]) {
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < T; i++) {
		ask(rnd.nextInt(N));
	}
	return 0;
}