#pragma once

#include "libs.hpp"

namespace Currency {

	class Pln
	{
	private:
		double value;
	public:
		explicit Pln(double value = 0);

		// czy ten operator jest tutaj potrzebny?
		Pln& operator=(const Pln& currency_pln);

		friend std::ostream& operator<<(std::ostream& out, const Pln& currency);

		virtual ~Pln() = default;
	};

}