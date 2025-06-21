
#include <cstdlib>
#include "parser.hh"

int main(int argc, char** argv, char** environv) {
	yyparse();

	return EXIT_SUCCESS;
}
