
#include "lex_handle.hh"
#include "lexer.hh"

/* yytoken_kind_t handle::WHITESPACE(char* text) {
	yylval.cstring = yytext;
	return TOKEN_WHITESPACE;
} */

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
