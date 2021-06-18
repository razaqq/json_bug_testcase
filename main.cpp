#include <iostream>
#include <nlohmann/json.hpp>


using nlohmann::json;

class sax_no_exception : public nlohmann::detail::json_sax_dom_parser<json>
{
public:
	explicit sax_no_exception(json& j) : nlohmann::detail::json_sax_dom_parser<json>(j, false) {}

	static bool parse_error(std::size_t position, const std::string& last_token, const json::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return false;
	}
};

int main()
{
	json j;
	sax_no_exception sax(j);
	if (!json::sax_parse("xyz", &sax))
	{
		std::cout << "Error while parsing JSON" << std::endl;
		return 1;
	}
	return 0;
}
