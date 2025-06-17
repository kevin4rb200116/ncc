
#pragma once

#include "parser.hh"

#define SYM_TYPE yy::parser::symbol_type

namespace handle {
	SYM_TYPE LPAR            (char*);
	SYM_TYPE RPAR            (char*);
	SYM_TYPE LSQB            (char*);
	SYM_TYPE RSQB            (char*);
	SYM_TYPE COLON           (char*);
	SYM_TYPE COMMA           (char*);
	SYM_TYPE SEMI            (char*);
	SYM_TYPE PLUS            (char*);
	SYM_TYPE MINUS           (char*);
	SYM_TYPE STAR            (char*);
	SYM_TYPE SLASH           (char*);
	SYM_TYPE VBAR            (char*);
	SYM_TYPE AMPER           (char*);
	SYM_TYPE LESS            (char*);
	SYM_TYPE GREATER         (char*);
	SYM_TYPE EQUAL           (char*);
	SYM_TYPE DOT             (char*);
	SYM_TYPE PERCENT         (char*);
	SYM_TYPE LBRACE          (char*);
	SYM_TYPE RBRACE          (char*);
	SYM_TYPE EQEQUAL         (char*);
	SYM_TYPE NOTEQUAL        (char*);
	SYM_TYPE LESSEQUAL       (char*);
	SYM_TYPE GREATEREQUAL    (char*);
	SYM_TYPE TILDE           (char*);
	SYM_TYPE CIRCUMFLEX      (char*);
	SYM_TYPE LEFTSHIFT       (char*);
	SYM_TYPE RIGHTSHIFT      (char*);
	SYM_TYPE DOUBLESTAR      (char*);
	SYM_TYPE PLUSEQUAL       (char*);
	SYM_TYPE MINEQUAL        (char*);
	SYM_TYPE STAREQUAL       (char*);
	SYM_TYPE SLASHEQUAL      (char*);
	SYM_TYPE PERCENTEQUAL    (char*);
	SYM_TYPE AMPEREQUAL      (char*);
	SYM_TYPE VBAREQUAL       (char*);
	SYM_TYPE CIRCUMFLEXEQUAL (char*);
	SYM_TYPE LEFTSHIFTEQUAL  (char*);
	SYM_TYPE RIGHTSHIFTEQUAL (char*);
	SYM_TYPE DOUBLESTAREQUAL (char*);
	SYM_TYPE DOUBLESLASH     (char*);
	SYM_TYPE DOUBLESLASHEQUAL(char*);
	SYM_TYPE ELLIPSIS        (char*);
	SYM_TYPE RARROW          (char*);
	SYM_TYPE AT              (char*);
	SYM_TYPE ATEQUAL         (char*);
	SYM_TYPE WHITESPACE      (char*);
	SYM_TYPE COMMENT         (char*);
	SYM_TYPE NAME            (char*);
	SYM_TYPE HEX_NUMBER      (char*);
	SYM_TYPE BIN_NUMBER      (char*);
	SYM_TYPE OCT_NUMBER      (char*);
	SYM_TYPE DEC_NUMBER      (char*);
	SYM_TYPE FLOAT_NUMBER    (char*);
	SYM_TYPE STRING          (char*);
	SYM_TYPE EOF_TOK         (char*);
} // namespace lexer::handle
