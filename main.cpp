#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <chrono>
#include <cmath>

// ---
// Stolen from my own C++ snippets:
// http://mrpg.pw/cpp-snippets#now_deltat
// ---
inline std::chrono::time_point<std::chrono::high_resolution_clock> now() {
	return std::chrono::high_resolution_clock::now();
}
 
inline double deltaT(std::chrono::time_point<std::chrono::high_resolution_clock> a, std::chrono::time_point<std::chrono::high_resolution_clock> b) {
	return ((std::chrono::duration_cast<std::chrono::nanoseconds>(b-a).count())/1000000000.0);
}
// ---
// End of stolen code
// ---

int main(void) {
	auto a = now();

	double sum = 0, sqsum = 0, max, min, tmp;
	size_t n = 0;

	while (std::cin >> tmp) {
		sum += tmp;
		sqsum += tmp*tmp;
		n++;

		if (tmp > max || n == 1) max = tmp;
		if (tmp < min || n == 1) min = tmp;
	}

	auto b = now();

	std::cout << std::fixed;

	std::cout << "    N: " << n << '\n';
	std::cout << "  SUM: " << sum << '\n';
	std::cout << "  MIN: " << min << '\n';
	std::cout << "  MAX: " << max << '\n';
	std::cout << "  AVG: " << sum/n << '\n';
	std::cout << "SDDEV: " << sqrt(sqsum/n - (sum/n)*(sum/n)) << '\n';
	std::cout << "-----\n";
	std::cout << round(n/deltaT(a,b)) << " doubles/s (input speed)\n";
}
