
#pragma once

#include <cstdio>

#ifndef YYTOKENTYPE
typedef int yytoken_kind_t;
#endif

#define SIMPLE_TOKEN(name) yytoken_kind_t name()
#define VALUE_TOKEN(name) yytoken_kind_t name(const char *)

namespace handle {
	SIMPLE_TOKEN(LPAR);
	SIMPLE_TOKEN(RPAR);
	SIMPLE_TOKEN(COMMA);
	SIMPLE_TOKEN(SEMI);
	SIMPLE_TOKEN(PLUS);
	SIMPLE_TOKEN(MINUS);
	SIMPLE_TOKEN(STAR);
	SIMPLE_TOKEN(SLASH);

	SIMPLE_TOKEN(LSQB);
	SIMPLE_TOKEN(RSQB);
	SIMPLE_TOKEN(COLON);
	SIMPLE_TOKEN(VBAR);
	SIMPLE_TOKEN(AMPER);
	SIMPLE_TOKEN(LESS);
	SIMPLE_TOKEN(GREATER);
	SIMPLE_TOKEN(EQUAL);
	SIMPLE_TOKEN(DOT);
	SIMPLE_TOKEN(PERCENT);
	SIMPLE_TOKEN(LBRACE);
	SIMPLE_TOKEN(RBRACE);
	SIMPLE_TOKEN(EQEQUAL);
	SIMPLE_TOKEN(NOTEQUAL);
	SIMPLE_TOKEN(LESSEQUAL);
	SIMPLE_TOKEN(GREATEREQUAL);
	SIMPLE_TOKEN(TILDE);
	SIMPLE_TOKEN(CIRCUMFLEX);
	SIMPLE_TOKEN(LEFTSHIFT);
	SIMPLE_TOKEN(RIGHTSHIFT);
	SIMPLE_TOKEN(DOUBLESTAR);
	SIMPLE_TOKEN(PLUSEQUAL);
	SIMPLE_TOKEN(MINEQUAL);
	SIMPLE_TOKEN(STAREQUAL);
	SIMPLE_TOKEN(SLASHEQUAL);
	SIMPLE_TOKEN(PERCENTEQUAL);
	SIMPLE_TOKEN(AMPEREQUAL);
	SIMPLE_TOKEN(VBAREQUAL);
	SIMPLE_TOKEN(CIRCUMFLEXEQUAL);
	SIMPLE_TOKEN(LEFTSHIFTEQUAL);
	SIMPLE_TOKEN(RIGHTSHIFTEQUAL);
	SIMPLE_TOKEN(DOUBLESTAREQUAL);
	SIMPLE_TOKEN(DOUBLESLASH);
	SIMPLE_TOKEN(DOUBLESLASHEQUAL);
	SIMPLE_TOKEN(ELLIPSIS);
	SIMPLE_TOKEN(RARROW);
	SIMPLE_TOKEN(AT);
	SIMPLE_TOKEN(ATEQUAL);
	SIMPLE_TOKEN(HASHTAG);

	SIMPLE_TOKEN(DEF);
	SIMPLE_TOKEN(EXTERN);

	SIMPLE_TOKEN(IF);
	SIMPLE_TOKEN(THEN);
	SIMPLE_TOKEN(ELSE);
	SIMPLE_TOKEN(ENDIF);

	SIMPLE_TOKEN(FOR);
	SIMPLE_TOKEN(DO);
	SIMPLE_TOKEN(ENDFOR);

	VALUE_TOKEN(NAME);
	VALUE_TOKEN(BIN_NUMBER);
	VALUE_TOKEN(OCT_NUMBER);
	VALUE_TOKEN(DEC_NUMBER);
	VALUE_TOKEN(HEX_NUMBER);
	VALUE_TOKEN(FLOAT_NUMBER);

	SIMPLE_TOKEN(YYEOF);
	SIMPLE_TOKEN(YYerror);
} // namespace handle

#undef SIMPLE_TOKEN
#undef VALUE_TOKEN
