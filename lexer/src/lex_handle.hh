
#pragma once

#include "parser.hh"
#include <cstdio>

namespace handle {
		yytoken_kind_t LPAR            (char* text);
		yytoken_kind_t RPAR            (char* text);
		yytoken_kind_t LSQB            (char* text);
		yytoken_kind_t RSQB            (char* text);
		yytoken_kind_t COLON           (char* text);
		yytoken_kind_t COMMA           (char* text);
		yytoken_kind_t SEMI            (char* text);
		yytoken_kind_t PLUS            (char* text);
		yytoken_kind_t MINUS           (char* text);
		yytoken_kind_t STAR            (char* text);
		yytoken_kind_t SLASH           (char* text);
		yytoken_kind_t VBAR            (char* text);
		yytoken_kind_t AMPER           (char* text);
		yytoken_kind_t LESS            (char* text);
		yytoken_kind_t GREATER         (char* text);
		yytoken_kind_t EQUAL           (char* text);
		yytoken_kind_t DOT             (char* text);
		yytoken_kind_t PERCENT         (char* text);
		yytoken_kind_t LBRACE          (char* text);
		yytoken_kind_t RBRACE          (char* text);
		yytoken_kind_t EQEQUAL         (char* text);
		yytoken_kind_t NOTEQUAL        (char* text);
		yytoken_kind_t LESSEQUAL       (char* text);
		yytoken_kind_t GREATEREQUAL    (char* text);
		yytoken_kind_t TILDE           (char* text);
		yytoken_kind_t CIRCUMFLEX      (char* text);
		yytoken_kind_t LEFTSHIFT       (char* text);
		yytoken_kind_t RIGHTSHIFT      (char* text);
		yytoken_kind_t DOUBLESTAR      (char* text);
		yytoken_kind_t PLUSEQUAL       (char* text);
		yytoken_kind_t MINEQUAL        (char* text);
		yytoken_kind_t STAREQUAL       (char* text);
		yytoken_kind_t SLASHEQUAL      (char* text);
		yytoken_kind_t PERCENTEQUAL    (char* text);
		yytoken_kind_t AMPEREQUAL      (char* text);
		yytoken_kind_t VBAREQUAL       (char* text);
		yytoken_kind_t CIRCUMFLEXEQUAL (char* text);
		yytoken_kind_t LEFTSHIFTEQUAL  (char* text);
		yytoken_kind_t RIGHTSHIFTEQUAL (char* text);
		yytoken_kind_t DOUBLESTAREQUAL (char* text);
		yytoken_kind_t DOUBLESLASH     (char* text);
		yytoken_kind_t DOUBLESLASHEQUAL(char* text);
		yytoken_kind_t ELLIPSIS        (char* text);
		yytoken_kind_t RARROW          (char* text);
		yytoken_kind_t AT              (char* text);
		yytoken_kind_t ATEQUAL         (char* text);
		yytoken_kind_t WHITESPACE      (char* text);
		yytoken_kind_t COMMENT         (char* text);
		yytoken_kind_t NAME            (char* text);
		yytoken_kind_t HEX_NUMBER      (char* text);
		yytoken_kind_t BIN_NUMBER      (char* text);
		yytoken_kind_t OCT_NUMBER      (char* text);
		yytoken_kind_t DEC_NUMBER      (char* text);
		yytoken_kind_t FLOAT_NUMBER    (char* text);
		yytoken_kind_t STRING          (char* text);
		yytoken_kind_t YYEOF           (char* text);
} // namespace handle
