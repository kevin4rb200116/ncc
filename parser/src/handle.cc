
#include "lexer.hh"
#include "parser.hh"
#include "handle.hh"

yytoken_kind_t handle::LPAR() {
	return TOKEN_LPAR;
}

yytoken_kind_t handle::RPAR() {
	return TOKEN_RPAR;
}

yytoken_kind_t handle::LSQB() {
	return TOKEN_LSQB;
}

yytoken_kind_t handle::RSQB() {
	return TOKEN_RSQB;
}

yytoken_kind_t handle::COLON() {
	return TOKEN_COLON;
}

yytoken_kind_t handle::COMMA() {
	return TOKEN_COMMA;
}

yytoken_kind_t handle::SEMI() {
	return TOKEN_SEMI;
}

yytoken_kind_t handle::PLUS() {
	return TOKEN_PLUS;
}

yytoken_kind_t handle::MINUS() {
	return TOKEN_MINUS;
}

yytoken_kind_t handle::STAR() {
	return TOKEN_STAR;
}

yytoken_kind_t handle::SLASH() {
	return TOKEN_SLASH;
}

yytoken_kind_t handle::VBAR() {
	return TOKEN_VBAR;
}

yytoken_kind_t handle::AMPER() {
	return TOKEN_AMPER;
}

yytoken_kind_t handle::LESS() {
	return TOKEN_LESS;
}

yytoken_kind_t handle::GREATER() {
	return TOKEN_GREATER;
}

yytoken_kind_t handle::EQUAL() {
	return TOKEN_EQUAL;
}

yytoken_kind_t handle::DOT() {
	return TOKEN_DOT;
}

yytoken_kind_t handle::PERCENT() {
	return TOKEN_PERCENT;
}

yytoken_kind_t handle::LBRACE() {
	return TOKEN_LBRACE;
}

yytoken_kind_t handle::RBRACE() {
	return TOKEN_RBRACE;
}

yytoken_kind_t handle::EQEQUAL() {
	return TOKEN_EQEQUAL;
}

yytoken_kind_t handle::NOTEQUAL() {
	return TOKEN_NOTEQUAL;
}

yytoken_kind_t handle::LESSEQUAL() {
	return TOKEN_LESSEQUAL;
}

yytoken_kind_t handle::GREATEREQUAL() {
	return TOKEN_GREATEREQUAL;
}

yytoken_kind_t handle::TILDE() {
	return TOKEN_TILDE;
}

yytoken_kind_t handle::CIRCUMFLEX() {
	return TOKEN_CIRCUMFLEX;
}

yytoken_kind_t handle::LEFTSHIFT() {
	return TOKEN_LEFTSHIFT;
}

yytoken_kind_t handle::RIGHTSHIFT() {
	return TOKEN_RIGHTSHIFT;
}

yytoken_kind_t handle::DOUBLESTAR() {
	return TOKEN_DOUBLESTAR;
}

yytoken_kind_t handle::PLUSEQUAL() {
	return TOKEN_PLUSEQUAL;
}

yytoken_kind_t handle::MINEQUAL() {
	return TOKEN_MINEQUAL;
}

yytoken_kind_t handle::STAREQUAL() {
	return TOKEN_STAREQUAL;
}

yytoken_kind_t handle::SLASHEQUAL() {
	return TOKEN_SLASHEQUAL;
}

yytoken_kind_t handle::PERCENTEQUAL() {
	return TOKEN_PERCENTEQUAL;
}

yytoken_kind_t handle::AMPEREQUAL() {
	return TOKEN_AMPEREQUAL;
}

yytoken_kind_t handle::VBAREQUAL() {
	return TOKEN_VBAREQUAL;
}

yytoken_kind_t handle::CIRCUMFLEXEQUAL() {
	return TOKEN_CIRCUMFLEXEQUAL;
}

yytoken_kind_t handle::LEFTSHIFTEQUAL() {
	return TOKEN_LEFTSHIFTEQUAL;
}

yytoken_kind_t handle::RIGHTSHIFTEQUAL() {
	return TOKEN_RIGHTSHIFTEQUAL;
}

yytoken_kind_t handle::DOUBLESTAREQUAL() {
	return TOKEN_DOUBLESTAREQUAL;
}

yytoken_kind_t handle::DOUBLESLASH() {
	return TOKEN_DOUBLESLASH;
}

yytoken_kind_t handle::DOUBLESLASHEQUAL() {
	return TOKEN_DOUBLESLASHEQUAL;
}

yytoken_kind_t handle::ELLIPSIS() {
	return TOKEN_ELLIPSIS;
}

yytoken_kind_t handle::RARROW() {
	return TOKEN_RARROW;
}

yytoken_kind_t handle::AT() {
	return TOKEN_AT;
}

yytoken_kind_t handle::ATEQUAL() {
	return TOKEN_ATEQUAL;
}

yytoken_kind_t handle::WHITESPACE(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_WHITESPACE;
}

yytoken_kind_t handle::COMMENT(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_COMMENT;
}

yytoken_kind_t handle::NAME(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_NAME;
}

yytoken_kind_t handle::HEX_NUMBER(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_HEX_NUMBER;
}

yytoken_kind_t handle::BIN_NUMBER(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_BIN_NUMBER;
}

yytoken_kind_t handle::OCT_NUMBER(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_OCT_NUMBER;
}

yytoken_kind_t handle::DEC_NUMBER(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_DEC_NUMBER;
}

yytoken_kind_t handle::FLOAT_NUMBER(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_FLOAT_NUMBER;
}

yytoken_kind_t handle::STRING(const char* text) {
	yylval.cstring = yytext;
	return TOKEN_STRING;
}

yytoken_kind_t handle::DEF() {
	return TOKEN_DEF;
}

yytoken_kind_t handle::EXTERN() {
	return TOKEN_EXTERN;
}

yytoken_kind_t handle::YYEOF() {
	return TOKEN_YYEOF;
}
