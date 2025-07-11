
#include <cstdlib>
#include "parser.hh"
#include "lexer.hh"

#include "ast.hh"

llvm::Value *ast::Number::irgen() {
	fprintf(stderr, "%s", value.c_str());
	return nullptr;
}

llvm::Value *ast::Variable::irgen() {
	fprintf(stderr, "%s", name.c_str());
	return nullptr;
}

llvm::Value *ast::Binary::irgen() {
	lhs->irgen();
	fprintf(stderr, " %s ", op.c_str());
	rhs->irgen();

	return nullptr;
}

llvm::Value *ast::Call::irgen() {
	fprintf(stderr, "%s(", callee.c_str());
	
	if (args.size() == 1)
		(*args.begin())->irgen();
	else
		for (auto arg : args) {
			arg->irgen();

			if (arg != args[args.size()-1])
				fprintf(stderr, ", ", arg);
		}

	fprintf(stderr, ")");

	return nullptr;
}

llvm::Value *ast::If::irgen() {
	fprintf(stderr, "if ");
	condition->irgen();

	fprintf(stderr, " then ");
	then_body->irgen();

	fprintf(stderr, " else ");
	else_body->irgen();
	fprintf(stderr, " endif");

	return nullptr;
}

llvm::Function *ast::Prototype::irgen() {
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

	fprintf(stderr, ")\n    ");

	return nullptr;
}

llvm::Function *ast::Function::irgen() {
	prototype->irgen();
	fprintf(stderr, " ");
	body->irgen();

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
