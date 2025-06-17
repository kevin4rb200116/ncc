
#pragma once

#include <map>
#include <string>

#include "parser.hh"

namespace driver {
	using std::map;
	using std::string;

	// Conducting the whole scanning and parsing
	class Driver {
		public:
			map<string, int> variables;

			// The token's location used by the lexer.
			yy::location location;

			// The name of the file being parsed.
			string file;

			// Run the parser on file F.  Return 0 on success.
			int parse(const string &f);

			// Handling the lexer.
			void lexerBegin();
			void lexerEnd();
	};
} // namespace driver
