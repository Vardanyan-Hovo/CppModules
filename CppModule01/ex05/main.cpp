#include "Harl.hpp"

int main()
{
	Harl h;
	std::string levl;
	levl = "debug";
	h.complain(levl);
	levl = "info";
	h.complain(levl);
	levl = "warning";
	h.complain(levl);
	levl = "error";
	h.complain(levl);
	return 0;
}
