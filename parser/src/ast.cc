
#include "ast.hh"

namespace ast {
	Value *Number::codegen() {
		fprintf(stderr, "TODO: ast::Number::codegen()\n");
		return nullptr;
	}

	Value *Variable::codegen() {
		fprintf(stderr, "TODO: ast::Variable::codegen()\n");
		return nullptr;
	}

	Value *Binary::codegen() {
		fprintf(stderr, "TODO: ast::Binary::codegen()\n");
		return nullptr;
	}

	Value *Call::codegen() {
		fprintf(stderr, "TODO: ast::Call::codegen()\n");
		return nullptr;
	}

	llvm::Function *Prototype::codegen() {
		fprintf(stderr, "TODO: ast::Prototype::codegen()\n");
		return nullptr;
	}

	llvm::Function *Function::codegen() {
		fprintf(stderr, "TODO: ast::Function::codegen()\n");
		return nullptr;
	}
} // namespace ast
