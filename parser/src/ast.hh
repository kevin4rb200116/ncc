
#pragma once

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/PassManager.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/StandardInstrumentations.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Transforms/Scalar/Reassociate.h>
#include <llvm/Transforms/Scalar/SimplifyCFG.h>

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include <vector>
#include <map>

namespace ast {
	using std::string;
	using std::unique_ptr;
	using std::make_unique;
	using std::move;
	using std::vector;
	using std::map;

	using llvm::Value;
	using llvm::LLVMContext;
	using llvm::Module;
	using llvm::IRBuilder;
	using llvm::ConstantFP;
	using llvm::APFloat;
	using llvm::Type;
	using llvm::FunctionType;
	using llvm::BasicBlock;
	using llvm::FunctionPassManager;
	using llvm::LoopAnalysisManager;
	using llvm::FunctionAnalysisManager;
	using llvm::CGSCCAnalysisManager;
	using llvm::ModuleAnalysisManager;
	using llvm::PassInstrumentationCallbacks;
	using llvm::StandardInstrumentations;
	using llvm::PassBuilder;

	class Expression {
		public:
			virtual ~Expression() = default;

			virtual Value *codegen() = 0;
	};

	class Number : public Expression {
		public:
			typedef enum Kind {
				BIN_NUMBER,
				OCT_NUMBER,
				DEC_NUMBER,
				HEX_NUMBER,
				FLOAT_NUMBER
			}Kind;

			Number(string value, Kind kind)
				: value(value), kind(kind) {}

			string &getValue() {
				return value;
			}

			Value *codegen() override;

		private:
			string value;
			Kind kind;
	};

	class Variable : public Expression {
		string name;

		public:
			Variable(const string name) : name(name) {}

			Value *codegen() override;
	};

	class Binary : public Expression {
		string op;
		Expression *lhs, *rhs;

		public:
			Binary(string op,
						 Expression* lhs,
						 Expression* rhs)
			  : op(op), lhs(lhs), rhs(rhs) {}

			~Binary() {
				delete lhs;
				delete rhs;
			}

			Value *codegen() override;
	};

	class Call : public Expression {
		string callee;
		vector<Expression*> args;

		public:
			Call(const string callee, vector<Expression*>* args)
			  : callee(callee), args(*args) {}

			~Call() {
				args.clear();
			}

			Value *codegen() override;
	};

	class Prototype {
		string name;
		vector<string> args;

		public:
			Prototype(const string name, vector<string>* args)
				: name(name), args(*args) {}

			~Prototype() {
				args.clear();
			}

			const string &getName() const { return name; }

			llvm::Function *codegen();
	};

	class Function {
		Prototype *prototype;
		Expression *body;

		public:
			Function(Prototype *prototype,
				       Expression *body)
				: prototype(prototype), body(body) {}

			~Function() {
				delete prototype;
				delete body;
			}

			llvm::Function *codegen();
	};
} // namespace ast
