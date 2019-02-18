#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <vector>

using std::vector;
const int MAX_N = 100 + 10;
const double Pi = acos(-1);

int n;

struct P {
	double x, y; 
} p[MAX_N], t;

inline double Rand() {
	return rand() / (double)(RAND_MAX + 1);
}

inline double Rand(double l, double r) {
	return Rand() * (r - l) + l;
}

inline double dis(P a, P b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline void node(double &x, double &y, double tx, double ty, double r) {
	double a = Rand() * 2.0 * Pi;
	
	x = tx + r * std::cos(a), y = ty + r * std::sin(a);
}

int main() {
	// std::srand(time(NULL));

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	
	double r = 5000.0, eps = 0.95;	
	double tx = 5000.0, ty = 5000.0;

	double Min = 0.0, sx = 5000.0, sy = 5000.0;
	
	for (int i = 1; i <= n; i++) {
		Min += dis(p[i], (P){ tx, ty });
	}
	
	while (r >= 0.001) {
		for (int i = 1; i <= 100; i++) {
			node(t.x, t.y, tx, ty, r);
			
			if (t.x > 10000.0 || t.x < 0.0 || t.y > 10000.0 || t.y < 0.0) continue;
			
			double Dis = 0.0;
			for (int j = 1; j <= n; j++) {
				Dis += dis(t, p[j]);
			}
			if (Dis < Min) {
				Min = Dis;
				sx = t.x, sy = t.y;
			}
		}
		r *= eps;
		tx = sx, ty = sy;
	}
	
	printf("%.0f\n", round(Min));

	return 0;
}
