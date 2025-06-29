
#include <cstdlib>
#include "parser.hh"
#include "lexer.hh"

#include "ast.hh"

llvm::Value *ast::Number::codegen() {
	fprintf(stderr, "%s", value.c_str());
	return nullptr;
}

llvm::Value *ast::Variable::codegen() {
	fprintf(stderr, "%s", name.c_str());
	return nullptr;
}

llvm::Value *ast::Binary::codegen() {
	lhs->codegen();
	fprintf(stderr, " %s ", op.c_str());
	rhs->codegen();

	return nullptr;
}

llvm::Value *ast::Call::codegen() {
	fprintf(stderr, "%s(", callee.c_str());
	
	if (args.size() == 1)
		(*args.begin())->codegen();
	else
		for (auto arg : args) {
			arg->codegen();

			if (arg != args[args.size()-1])
				fprintf(stderr, ", ", arg);
		}

	fprintf(stderr, ")");

	return nullptr;
}

llvm::Function *ast::Prototype::codegen() {
	fprintf(stderr, "def %s(", name.c_str(), args.size());

	if (args.size() == 1)
		fprintf(stderr, args[0].c_str());
	else
		for (auto &arg : args) {
			if (arg != args[args.size()-1])
				fprintf(stderr, "%s, ", arg.c_str());
			else
				fprintf(stderr, "%s", arg.c_str());
		}

	fprintf(stderr, ")");

	return nullptr;
}

llvm::Function *ast::Function::codegen() {
	prototype->codegen();
	fprintf(stderr, " ");
	body->codegen();

	return nullptr;
}

enum {
	YYSTDIN = 1,
	YYFILE = 2,
};

int main(int argc, char **argv) {
	switch (argc) {
		case (YYSTDIN):
			yyrestart(stdin);
			break;
		
		case (YYFILE):
			FILE *input = fopen(argv[1], "rt");
			yyrestart(input);
			break;
	}

	int result = yyparse();
	fprintf(stderr, "\n");

	return result;
}
