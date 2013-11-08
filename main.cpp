#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <chrono>

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

inline double square(double a) {
	return a*a;
}

double avg(const std::vector<double>& nums) {
	double a = 0;

	for (auto& c: nums) {
		a += c;
	}

	return a/nums.size();
}

double sddev(const std::vector<double>& nums, double mean) {
	const double co = 1.0/nums.size();
	double s = 0;

	for (auto& c: nums) {
		s += square(c-mean)*co;
	}

	return sqrt(s);
}

int main(void) {
	std::vector<double> nums;
	double tmp;

	while (std::cin >> tmp) {
		nums.push_back(tmp);
	}

	double mean, sd, p1;

	auto a = now();
	mean = avg(nums);
	sd = sddev(nums,mean);
	auto b = now();

	p1 = ((sqrt((1.0-(4.0*(sd*sd)/nums.size()))))+1.0)/2.0;

	std::cout << std::setprecision(20);

	std::cout << "    N: " << nums.size() << '\n';
	std::cout << "  SUM: " << mean*nums.size() << '\n';
	std::cout << "  MIN: " << *std::min_element(nums.begin(),nums.end()) << '\n';
	std::cout << "  MAX: " << *std::max_element(nums.begin(),nums.end()) << '\n';
	std::cout << "  AVG: " << mean << '\n';
	std::cout << "SDDEV: " << sd << '\n';
	if (p1 == p1) std::cout << "    P: " << p1 << '\n';
	std::cout << "-----\n";
	std::cout << round(nums.size()/deltaT(a,b)) << " doubles/s\n";
}
