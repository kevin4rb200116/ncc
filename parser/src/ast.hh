
#pragma once

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
	};

	class Number : public Expression {
		public:
			typedef enum Kind {
				HEX_NUMBER,
				BIN_NUMBER,
				OCT_NUMBER,
				DEC_NUMBER,
				FLOAT_NUMBER
			}Kind;

			Number(string value, Kind kind)
				: value(value), kind(kind) {}

		private:
			string value;
			Kind kind;
	};

	class Variable : public Expression {
		string name;

		public:
			Variable(const string name) : name(name) {}
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
	};

	class Call : public Expression {
		string callee;
		vector<Expression*> args;

		public:
			Call(const string callee, vector<Expression*> args)
			  : callee(callee), args(args) {}
		
			~Call() {
				args.clear();
			}
	};
	
	class Prototype {
		string name;
		vector<string> args;

		public:
			Prototype(const string name, vector<string> args)
				: name(name), args(args) {}

			~Prototype() {
				args.clear();
			}

			const string &getName() const { return name; }
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
	};
} // namespace ast
