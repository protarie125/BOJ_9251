#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string a, b;
	cin >> a >> b;

	const auto& l1 = a.length();
	const auto& l2 = b.length();

	auto dp = vvi(l2 + 1, vi(l1 + 1, 0));
	for (auto i = 1; i <= l2; ++i) {
		const auto& nc = b[i - 1];
		for (auto j = 1; j <= l1; ++j) {
			if (nc == a[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				const auto& u = dp[i - 1][j];
				const auto& l = dp[i][j - 1];
				dp[i][j] = max(u, l);
			}
		}
	}

	cout << dp[l2][l1];

	return 0;
}