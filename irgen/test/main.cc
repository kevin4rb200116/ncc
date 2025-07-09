
#include <cstdio>
#include "lexer.hh"
#include "parser.hh"
#include "irgen.hh"

namespace irgen {
	extern State *state;
} // namespace irgen

enum {
	YYSTDIN = 1,
	YYFILE = 2,
};

int main(int argc, char **argv) {
	std::string mname;

	switch (argc) {
		case (YYSTDIN):
			yyrestart(stdin);
			mname.clear();
			mname.append("<stdin>");
			break;
		
		case (YYFILE):
			FILE *input = fopen(argv[1], "rt");
			yyrestart(input);
			mname.clear();
			mname.append(argv[1]);
			break;
	}

	irgen::state = new irgen::State(mname);
	int result = yyparse();
	irgen::state->module->print(llvm::errs(), nullptr);

	return result;
}
