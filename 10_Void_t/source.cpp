#include <iostream>

// -------------------------- 0 -----------------------------
struct A
{
	virtual int get_value() = 0;
};

class B: public A
{
private:
	int value;
public:
	B(int value): value {value} {}
	int get_value() override
	{
		return value;
	}
};

// ----------------------------------------------------------

struct Book
{
	int pages;

	int info() const
	{
		return pages;
	}
};

struct Author
{
	std::string name;

	std::string info() const
	{
		return "AUTHOR: " + name;
	}

	friend std::ostream& operator<<(std::ostream& out, const Author& a)
	{
		return out << a.name;
	}
};

struct Library
{
	static void fun(int a, double b)
	{
		std::cout << a << " " << b << std::endl;
	}
};

// std::void_t - mapuje sekwencje dowolnych typow do void
// to samo co:
// template<class...> using void_t = void;
// https://en.cppreference.com/w/cpp/types/void_t

// -------------------------- 1 -----------------------------
template<typename T, typename=void>
struct has_info: std::false_type{};

template<typename T>
struct has_info<T, std::void_t<decltype(std::declval<T&>().info())>>: std::true_type{};

// -------------------------- 2 -----------------------------
template <typename T, typename = void>
struct has_info_and_return_string : std::false_type {};

template <typename T>
struct has_info_and_return_string<T, std::void_t<decltype(std::declval<std::string&>() == std::declval<T>().info())>> : std::true_type {};

// -------------------------- 3 -----------------------------
template <typename T, typename = void>
struct hasfun_with_arguments : std::false_type {};

template <typename T>
struct hasfun_with_arguments<T, std::void_t<decltype(std::declval<T>().fun(std::declval<int>(), std::declval<double>()))>> : std::true_type {};


int main()
{
	// -------------------------- 0 -----------------------------
	// decltype oraz declval
	int x = 11;
	decltype(x) y = 12;

	decltype(B(100).get_value()) a = 1;
	decltype(std::declval<A>().get_value()) b = 2;
	std::cout << a << " " << b << std::endl;

	// ----------------------------------------------------------
	// SFINAE - substitution failure is not an error

	std::cout << std::endl;
	std::cout << "1.1. Author  --> " << has_info<Author>::value << std::endl;
	std::cout << "1.2. Book    --> " << has_info<Book>::value << std::endl;
	std::cout << "1.3. Library --> " << has_info<Library>::value << std::endl;

	std::cout << std::endl;
	std::cout << "2.1. Author  --> " << has_info_and_return_string<Author>::value << std::endl;
	std::cout << "2.2. Book    --> " << has_info_and_return_string<Book>::value << std::endl;
	std::cout << "2.3. Library --> " << has_info_and_return_string<Library>::value << std::endl;

	std::cout << std::endl;
	std::cout << "3.1. Author  --> " << hasfun_with_arguments<Author>::value << std::endl;
	std::cout << "3.2. Book    --> " << hasfun_with_arguments<Book>::value << std::endl;
	std::cout << "3.3. Library --> " << hasfun_with_arguments<Library>::value << std::endl;

	return 0;
}