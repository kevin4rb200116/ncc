
#pragma once

#include <cstdio>

#ifndef YYTOKENTYPE
typedef int yytoken_kind_t;
#endif

namespace handle {
	yytoken_kind_t LPAR();
	yytoken_kind_t RPAR();
	yytoken_kind_t COMMA();
	yytoken_kind_t SEMI();
	yytoken_kind_t PLUS();
	yytoken_kind_t MINUS();
	yytoken_kind_t STAR();
	yytoken_kind_t SLASH();

	yytoken_kind_t DEF();
	yytoken_kind_t EXTERN();

	yytoken_kind_t IF();
	yytoken_kind_t THEN();
	yytoken_kind_t ELSE();
	yytoken_kind_t ENDIF();

	yytoken_kind_t NAME(const char *);
	yytoken_kind_t BIN_NUMBER(const char *);
	yytoken_kind_t OCT_NUMBER(const char *);
	yytoken_kind_t DEC_NUMBER(const char *);
	yytoken_kind_t HEX_NUMBER(const char *);
	yytoken_kind_t FLOAT_NUMBER(const char *);

	yytoken_kind_t YYEOF();
	yytoken_kind_t YYerror();
} // namespace handle
