
#pragma once

#include <cstdio>

#ifndef YYTOKENTYPE
typedef int yytoken_kind_t;
#endif

namespace handle {
	yytoken_kind_t LPAR();
	yytoken_kind_t RPAR();
	yytoken_kind_t LSQB();
	yytoken_kind_t RSQB();
	yytoken_kind_t COLON();
	yytoken_kind_t COMMA();
	yytoken_kind_t SEMI();
	yytoken_kind_t PLUS();
	yytoken_kind_t MINUS();
	yytoken_kind_t STAR();
	yytoken_kind_t SLASH();
	yytoken_kind_t VBAR();
	yytoken_kind_t AMPER();
	yytoken_kind_t LESS();
	yytoken_kind_t GREATER();
	yytoken_kind_t EQUAL();
	yytoken_kind_t DOT();
	yytoken_kind_t PERCENT();
	yytoken_kind_t LBRACE();
	yytoken_kind_t RBRACE();
	yytoken_kind_t EQEQUAL();
	yytoken_kind_t NOTEQUAL();
	yytoken_kind_t LESSEQUAL();
	yytoken_kind_t GREATEREQUAL();
	yytoken_kind_t TILDE();
	yytoken_kind_t CIRCUMFLEX();
	yytoken_kind_t LEFTSHIFT();
	yytoken_kind_t RIGHTSHIFT();
	yytoken_kind_t DOUBLESTAR();
	yytoken_kind_t PLUSEQUAL();
	yytoken_kind_t MINEQUAL();
	yytoken_kind_t STAREQUAL();
	yytoken_kind_t SLASHEQUAL();
	yytoken_kind_t PERCENTEQUAL();
	yytoken_kind_t AMPEREQUAL();
	yytoken_kind_t VBAREQUAL();
	yytoken_kind_t CIRCUMFLEXEQUAL();
	yytoken_kind_t LEFTSHIFTEQUAL();
	yytoken_kind_t RIGHTSHIFTEQUAL();
	yytoken_kind_t DOUBLESTAREQUAL();
	yytoken_kind_t DOUBLESLASH();
	yytoken_kind_t DOUBLESLASHEQUAL();
	yytoken_kind_t ELLIPSIS();
	yytoken_kind_t RARROW();
	yytoken_kind_t AT();
	yytoken_kind_t ATEQUAL();

	yytoken_kind_t DEF();
	yytoken_kind_t EXTERN();

	yytoken_kind_t WHITESPACE(const char *);
	yytoken_kind_t COMMENT(const char *);
	yytoken_kind_t NAME(const char *);
	yytoken_kind_t BIN_NUMBER(const char *);
	yytoken_kind_t OCT_NUMBER(const char *);
	yytoken_kind_t DEC_NUMBER(const char *);
	yytoken_kind_t HEX_NUMBER(const char *);
	yytoken_kind_t FLOAT_NUMBER(const char *);
	yytoken_kind_t STRING(const char *);

	yytoken_kind_t YYEOF();
} // namespace handle
