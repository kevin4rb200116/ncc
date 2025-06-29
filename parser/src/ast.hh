
#pragma once

#include <llvm/IR/Function.h>
#include <llvm/IR/Value.h>

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

	class Expression {
		public:
			virtual ~Expression() = default;

			virtual llvm::Value *codegen() = 0;
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

			llvm::Value *codegen() override;

		private:
			string value;
			Kind kind;
	};

	class Variable : public Expression {
		string name;

		public:
			Variable(const string name) : name(name) {}

			llvm::Value *codegen() override;
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

			llvm::Value *codegen() override;
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

			llvm::Value *codegen() override;
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
