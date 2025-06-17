
#include "parser.hh"

int main(int argc, char** argv, char** environv) {
	yy::parser parse;

	return parse.parse();
}
