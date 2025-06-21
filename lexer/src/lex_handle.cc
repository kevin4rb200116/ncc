
#include "lex_handle.hh"
#include "lexer.hh"

yytoken_kind_t handle::LPAR(char* text) {
	yylval.cstring = yytext;
	return TOKEN_LPAR;
}

yytoken_kind_t handle::RPAR(char* text) {
	yylval.cstring = yytext;
	return TOKEN_RPAR;
}

yytoken_kind_t handle::LSQB(char* text) {
	yylval.cstring = yytext;
	return TOKEN_LSQB;
}

yytoken_kind_t handle::RSQB(char* text) {
	yylval.cstring = yytext;
	return TOKEN_RSQB;
}

yytoken_kind_t handle::COLON(char* text) {
	yylval.cstring = yytext;
	return TOKEN_COLON;
}

yytoken_kind_t handle::COMMA(char* text) {
	yylval.cstring = yytext;
	return TOKEN_COMMA;
}

yytoken_kind_t handle::SEMI(char* text) {
	yylval.cstring = yytext;
	return TOKEN_SEMI;
}

yytoken_kind_t handle::PLUS(char* text) {
	yylval.cstring = yytext;
	return TOKEN_PLUS;
}

yytoken_kind_t handle::MINUS(char* text) {
	yylval.cstring = yytext;
	return TOKEN_MINUS;
}

yytoken_kind_t handle::STAR(char* text) {
	yylval.cstring = yytext;
	return TOKEN_STAR;
}

yytoken_kind_t handle::SLASH(char* text) {
	yylval.cstring = yytext;
	return TOKEN_SLASH;
}

yytoken_kind_t handle::VBAR(char* text) {
	yylval.cstring = yytext;
	return TOKEN_VBAR;
}

yytoken_kind_t handle::AMPER(char* text) {
	yylval.cstring = yytext;
	return TOKEN_AMPER;
}

yytoken_kind_t handle::LESS(char* text) {
	yylval.cstring = yytext;
	return TOKEN_LESS;
}

yytoken_kind_t handle::GREATER(char* text) {
	yylval.cstring = yytext;
	return TOKEN_GREATER;
}

yytoken_kind_t handle::EQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_EQUAL;
}

yytoken_kind_t handle::DOT(char* text) {
	yylval.cstring = yytext;
	return TOKEN_DOT;
}

yytoken_kind_t handle::PERCENT(char* text) {
	yylval.cstring = yytext;
	return TOKEN_PERCENT;
}

yytoken_kind_t handle::LBRACE(char* text) {
	yylval.cstring = yytext;
	return TOKEN_LBRACE;
}

yytoken_kind_t handle::RBRACE(char* text) {
	yylval.cstring = yytext;
	return TOKEN_RBRACE;
}

yytoken_kind_t handle::EQEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_EQEQUAL;
}

yytoken_kind_t handle::NOTEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_NOTEQUAL;
}

yytoken_kind_t handle::LESSEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_LESSEQUAL;
}

yytoken_kind_t handle::GREATEREQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_GREATEREQUAL;
}

yytoken_kind_t handle::TILDE(char* text) {
	yylval.cstring = yytext;
	return TOKEN_TILDE;
}

yytoken_kind_t handle::CIRCUMFLEX(char* text) {
	yylval.cstring = yytext;
	return TOKEN_CIRCUMFLEX;
}

yytoken_kind_t handle::LEFTSHIFT(char* text) {
	yylval.cstring = yytext;
	return TOKEN_LEFTSHIFT;
}

yytoken_kind_t handle::RIGHTSHIFT(char* text) {
	yylval.cstring = yytext;
	return TOKEN_RIGHTSHIFT;
}

yytoken_kind_t handle::DOUBLESTAR(char* text) {
	yylval.cstring = yytext;
	return TOKEN_DOUBLESTAR;
}

yytoken_kind_t handle::PLUSEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_PLUSEQUAL;
}

yytoken_kind_t handle::MINEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_MINEQUAL;
}

yytoken_kind_t handle::STAREQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_STAREQUAL;
}

yytoken_kind_t handle::SLASHEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_SLASHEQUAL;
}

yytoken_kind_t handle::PERCENTEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_PERCENTEQUAL;
}

yytoken_kind_t handle::AMPEREQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_AMPEREQUAL;
}

yytoken_kind_t handle::VBAREQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_VBAREQUAL;
}

yytoken_kind_t handle::CIRCUMFLEXEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_CIRCUMFLEXEQUAL;
}

yytoken_kind_t handle::LEFTSHIFTEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_LEFTSHIFTEQUAL;
}

yytoken_kind_t handle::RIGHTSHIFTEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_RIGHTSHIFTEQUAL;
}

yytoken_kind_t handle::DOUBLESTAREQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_DOUBLESTAREQUAL;
}

yytoken_kind_t handle::DOUBLESLASH(char* text) {
	yylval.cstring = yytext;
	return TOKEN_DOUBLESLASH;
}

yytoken_kind_t handle::DOUBLESLASHEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_DOUBLESLASHEQUAL;
}

yytoken_kind_t handle::ELLIPSIS(char* text) {
	yylval.cstring = yytext;
	return TOKEN_ELLIPSIS;
}

yytoken_kind_t handle::RARROW(char* text) {
	yylval.cstring = yytext;
	return TOKEN_RARROW;
}

yytoken_kind_t handle::AT(char* text) {
	yylval.cstring = yytext;
	return TOKEN_AT;
}

yytoken_kind_t handle::ATEQUAL(char* text) {
	yylval.cstring = yytext;
	return TOKEN_ATEQUAL;
}

yytoken_kind_t handle::WHITESPACE(char* text) {
	yylval.cstring = yytext;
	return TOKEN_WHITESPACE;
}

yytoken_kind_t handle::COMMENT(char* text) {
	yylval.cstring = yytext;
	return TOKEN_COMMENT;
}

yytoken_kind_t handle::NAME(char* text) {
	yylval.cstring = yytext;
	return TOKEN_NAME;
}

yytoken_kind_t handle::HEX_NUMBER(char* text) {
	yylval.cstring = yytext;
	return TOKEN_HEX_NUMBER;
}

yytoken_kind_t handle::BIN_NUMBER(char* text) {
	yylval.cstring = yytext;
	return TOKEN_BIN_NUMBER;
}

yytoken_kind_t handle::OCT_NUMBER(char* text) {
	yylval.cstring = yytext;
	return TOKEN_OCT_NUMBER;
}

yytoken_kind_t handle::DEC_NUMBER(char* text) {
	yylval.cstring = yytext;
	return TOKEN_DEC_NUMBER;
}

yytoken_kind_t handle::FLOAT_NUMBER(char* text) {
	yylval.cstring = yytext;
	return TOKEN_FLOAT_NUMBER;
}

yytoken_kind_t handle::STRING(char* text) {
	yylval.cstring = yytext;
	return TOKEN_STRING;
}

yytoken_kind_t handle::YYEOF(char* text) {
	yylval.cstring = yytext;
	return TOKEN_YYEOF;
}
