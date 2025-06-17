
#include "driver.hh"

namespace driver {
	int Driver::parse(const string &f) {
		file = f;
		location.initialize(&file);
		scan_begin();
		yy::parser parse(*this);
		int res = parse();
		scan_end();
		return res;
	}
} // driver
