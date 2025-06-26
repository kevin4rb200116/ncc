
#include <cstdlib>
#include "parser.hh"


#include "ast.hh"

llvm::Value *ast::Number::codegen() {
	fprintf(stderr, "TODO: ast::Number::codegen()\n");
	return nullptr;
}

llvm::Value *ast::Variable::codegen() {
	fprintf(stderr, "TODO: ast::Variable::codegen()\n");
	return nullptr;
}

llvm::Value *ast::Binary::codegen() {
	fprintf(stderr, "TODO: ast::Binary::codegen()\n");
	return nullptr;
}

llvm::Value *ast::Call::codegen() {
	fprintf(stderr, "TODO: ast::Call::codegen()\n");
	return nullptr;
}

llvm::Function *ast::Prototype::codegen() {
	fprintf(stderr, "TODO: ast::Prototype::codegen()\n");
	return nullptr;
}

llvm::Function *ast::Function::codegen() {
	fprintf(stderr, "TODO: ast::Function::codegen()\n");
	return nullptr;
}

int main() {
	yyparse();

	return EXIT_SUCCESS;
}
