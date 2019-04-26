#pragma once

#include "pln.hpp"

namespace Currency {

	namespace Conversion {

		struct ExchangeRate {
			static constexpr double GBP_TO_PLN = 4.97;
			static constexpr double EUR_TO_PLN = 4.29;
		};

		inline auto operator""_GBP(long double value) -> Pln {
			return Pln{ static_cast<double>(value) * ExchangeRate::GBP_TO_PLN };
		}

		inline auto operator""_EUR(long double value) -> Pln {
			return Pln{ static_cast<double>(value) * ExchangeRate::EUR_TO_PLN };
		}

		inline auto operator""_SLOWNIE(const char* value, size_t length) -> Pln {
			std::cout << value << std::endl;
			return Pln{ 1.0 };
		}

	}
}