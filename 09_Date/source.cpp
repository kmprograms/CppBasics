#include <string>
#include <iostream>

#include "date.h"

using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;


struct Date
{
	int y;
	unsigned int m;
	unsigned int d;

	auto operator()() const {
		return year_month_day{ year{ y }, month{ m }, day{ d } };
	}
};

int number_of_days(const Date& d1, const Date& d2)
{
	return (sys_days{ d1() } - sys_days{ d2() }).count();
}

int main()
{
	std::cout << "----------------------------- D1 --------------------------------" << std::endl;
	const auto d1 = year_month_day{ year{2019}, month{8}, day{1} };
	std::cout << d1 << std::endl;
	std::cout << d1.year() << std::endl;
	std::cout << d1.month() << std::endl;
	std::cout << d1.day() << std::endl;

	std::cout << "----------------------------- D2 --------------------------------" << std::endl;
	const auto d2 = year_month_day{ August / Friday[last] / 2019 };
	std::cout << d2 << std::endl;
	const auto d2_1 = year_month_day{ August / Friday[2] / 2019 };
	std::cout << d2_1 << std::endl;

	std::cout << "----------------------------- D3 --------------------------------" << std::endl;
	// today
	const auto d3 = year_month_day{ ceil<days>(system_clock::now()) };
	std::cout << d3 << std::endl;

	std::cout << "----------------------------- D4 --------------------------------" << std::endl;
	const auto d4 = year{ 2019 } / 1 / 22;
	const auto d5 = d4 + years{ 12 };
	const auto d6 = d4 - months{ 12 };
	std::cout << d4 << std::endl;
	std::cout << d5 << std::endl;
	std::cout << d6 << std::endl;

	std::cout << "----------------------------- D5 --------------------------------" << std::endl;
	// subtraction of days
	const auto d7 = year{ 2019 } / 1 / 22;
	const auto days_d7 = sys_days(d7);
	const auto days_d7_diff = days_d7 - days{ 22 };
	const auto d8 = year_month_day{ days_d7_diff };
	std::cout << d8 << std::endl;

	std::cout << "----------------------------- D6 --------------------------------" << std::endl;
	day_point dp = sep / 25 / 2019;
	std::cout << dp.time_since_epoch().count() << std::endl;
	dp += days{ 10 };
	std::cout << dp.time_since_epoch().count() << std::endl;
	const auto d9 = year_month_day{ dp };
	std::cout << d9 << std::endl;

	std::cout << "----------------------------- D7 --------------------------------" << std::endl;
	const auto d10 = Date{2019, 11, 20};
	const auto d11 = Date{2019, 11, 15};
	std::cout << number_of_days(d10, d11) << std::endl;

	return 0;
}