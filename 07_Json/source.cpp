#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <array>
#include <list>

#include "json.hpp"

using json = nlohmann::json;

enum class Color { BLACK, SILVER, WHITE };

// specjalne makro, ktore pozwoli na automatyczna konwersje wartosci enum do 
// wybranego string-a
NLOHMANN_JSON_SERIALIZE_ENUM(Color, {
	{Color::BLACK, "BLACK"},
	{Color::SILVER, "SILVER"},
	{Color::WHITE, "WHITE"}
});

std::string json_example_1()
{
	json j;
	j["speed"] = 210;
	j["diesel"] = true;
	j["model"] = "BMW";
	j["nothing"] = nullptr;
	j["comments"]["John Smith"] = "Best car ever!"; // zagniezdzanie
	j["colors"] = { Color::BLACK, Color::SILVER }; // kolekcja
	j["owner"] = { {"name", "John"}, {"surname", "Smith"} };

	return j.dump(); // domyslna postac najbardziej kompaktowa
}

std::string json_example_2()
{
	// mozna tez zapisac krocej
	json j = {
		{ "speed", 210 },
		{ "diesel", true },
		{ "model", "BMW" },
		{ "nothing", nullptr },
		{ "comments", {
			{"John Smith", "Best car ever!"}
		} },
		{ "colors", {Color::BLACK, Color::SILVER} },
		{ "owner", {
			{ "name", "John"},
			{ "surname", "Smith" }
		} }
	};
	return j.dump(4); // mowi nam ile spacji ma zostac przeznaczone na wciecie
}

std::string json_example_3()
{
	// jeszcze inna postac 

	json array;
	array.push_back(10);
	array.push_back(20);
	array.push_back(30);

	json object;
	object["name"] = "John";
	object["surname"] = "Smith";

	const json array_with_object = json::array({ {"currency", "USD"}, {"value", 42.99} });

	json final_object = json::object();
	final_object["a"] = array;
	final_object["o"] = object;
	final_object["ao"] = array_with_object;

	return final_object.dump(4);
}

std::string json_example_4()
{
	// mozliwosc zwracania albo jako string albo jako json

	json j = "this is string";

	// zwracasz jako normalny string
	// return j.get<std::string>();

	// zwracasz jako json
	return j.dump();
}

std::string json_example_5()
{
	// odczyt z pliku json
	const std::string filename = "file1.json";
	std::ifstream reader(filename);
	json j;
	reader >> j;
	reader.close();
	return j.dump(4);
}

std::string json_example_6()
{
	// zapis do pliku json
	json j;
	j.push_back("name");
	j.push_back(10);
	j.push_back(true);
	j.emplace_back("poland");

	json jj;
	jj["a"] = j;

	std::ofstream writer;
	writer.open("file2.json");
	writer << jj.dump(4);

	return jj.dump(4);
}

void json_example_7()
{
	json o1;
	o1["name"] = "John";
	o1["surname"] = "Smith";

	json o2;
	o2["name"] = "Andy";
	o2["surname"] = "Black";

	json a;
	a.push_back(o1);
	a.push_back(o2);

	std::cout << "********************* iteracja 1 ******************" << std::endl;
	for (const auto& person : a)
	{
		std::cout << person["name"] << " " << person["surname"] << std::endl;
	}

	std::cout << "********************* iteracja 2 ******************" << std::endl;
	for (const auto& item : a.items())
	{
		std::cout << item.key() << " " << item.value()["name"] << std::endl;
	}

	std::cout << "********************* iteracja 3 ******************" << std::endl;
	for (const auto& [key, value] : a.items())
	{
		std::cout << key << " " << value["name"] << std::endl;
	}

	// wyszukiwanie encji
	if (a[0].find("name") != a[0].end())
	{
		std::cout << "FOUND! " << a[0]["name"] << std::endl;
	}

	// zliczanie
	std::cout << a[0].count("name") << std::endl;
	a[0].erase("name"); // usuwanie
	std::cout << a << std::endl;
}

void json_example_8()
{
	// konwersje z roznych kolekcji - biblioteka jest przygotowana do pracy
	// z kazdym rodzajem kolekcji

	// ---------------------------------------------------
	std::vector<int> c_vector = { 1, 2, 3, 4 };
	json j_vec(c_vector);
	// [1, 2, 3, 4]
	std::cout << j_vec << std::endl;

	// ---------------------------------------------------
	std::deque<double> c_deque = { 1.2, 2.3, 3.4, 5.6 };
	json j_deque(c_deque);
	// [1.2, 2.3, 3.4, 5.6]
	std::cout << j_deque << std::endl;

	// ---------------------------------------------------
	std::list<bool> c_list = { true, true, false, true };
	json j_list(c_list);
	// [true, true, false, true]
	std::cout << j_list << std::endl;

	// ---------------------------------------------------
	std::array<unsigned long, 4> c_array = { {1, 2, 3, 4} };
	json j_array(c_array);
	// [1, 2, 3, 4]
	std::cout << j_array << std::endl;

	// ---------------------------------------------------
	std::map<std::string, int> c_map = { {"one", 1}, {"two", 2}, {"three", 3} };
	json j_map(c_map);
	// {"one": 1, "three": 3, "two": 2 }
	std::cout << j_map.dump(4) << std::endl;
}

int main()
{

	std::cout << "--------------------- example 1 ------------------- " << std::endl;
	std::cout << json_example_1() << std::endl;

	std::cout << "--------------------- example 2 ------------------- " << std::endl;
	std::cout << json_example_2() << std::endl;

	std::cout << "--------------------- example 3 ------------------- " << std::endl;
	std::cout << json_example_3() << std::endl;

	std::cout << "--------------------- example 4 ------------------- " << std::endl;
	std::cout << json_example_4() << std::endl;

	std::cout << "--------------------- example 5 ------------------- " << std::endl;
	std::cout << json_example_5() << std::endl;

	std::cout << "--------------------- example 6 ------------------- " << std::endl;
	std::cout << json_example_6() << std::endl;

	std::cout << "--------------------- example 7 ------------------- " << std::endl;
	json_example_7();

	std::cout << "--------------------- example 8 ------------------- " << std::endl;
	json_example_8();

	std::cin.get();
	return 0;
}