
#include <cstdio>
#include "lexer.hh"
#include "parser.hh"
#include "codegen.hh"

namespace codegen {
	extern State *state;
} // namespace codegen

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

	codegen::state = new codegen::State(mname);
	int result = yyparse();
	codegen::state->module->print(llvm::errs(), nullptr);

	return result;
}
