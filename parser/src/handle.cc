
#include <string>

#include "lexer.hh"
#include "parser.hh"
#include "handle.hh"

yytoken_kind_t handle::LPAR() {
	return TOKEN_LPAR;
}

yytoken_kind_t handle::RPAR() {
	return TOKEN_RPAR;
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

yytoken_kind_t handle::NAME(const char* text) {
	yylval.pointer = (void*) new std::string(yytext);
	((std::string*) yylval.pointer)
		-> resize(yyleng);

	return TOKEN_NAME;
}

yytoken_kind_t handle::HEX_NUMBER(const char* text) {
	yylval.pointer = (void*) new std::string(yytext);
	((std::string*) yylval.pointer)
		-> resize(yyleng);

	return TOKEN_HEX_NUMBER;
}

yytoken_kind_t handle::BIN_NUMBER(const char* text) {
	yylval.pointer = (void*) new std::string(yytext);
	((std::string*) yylval.pointer)
		-> resize(yyleng);

	return TOKEN_BIN_NUMBER;
}

yytoken_kind_t handle::OCT_NUMBER(const char* text) {
	yylval.pointer = (void*) new std::string(yytext);
	((std::string*) yylval.pointer)
		-> resize(yyleng);

	return TOKEN_OCT_NUMBER;
}

yytoken_kind_t handle::DEC_NUMBER(const char* text) {
	yylval.pointer = (void*) new std::string(yytext);
	((std::string*) yylval.pointer)
		-> resize(yyleng);

	return TOKEN_DEC_NUMBER;
}

yytoken_kind_t handle::FLOAT_NUMBER(const char* text) {
	yylval.pointer = (void*) new std::string(yytext);
	((std::string*) yylval.pointer)
		-> resize(yyleng);

	return TOKEN_FLOAT_NUMBER;
}

yytoken_kind_t handle::DEF() {
	return TOKEN_DEF;
}

yytoken_kind_t handle::EXTERN() {
	return TOKEN_EXTERN;
}

yytoken_kind_t handle::IF() {
	return TOKEN_IF;
}

yytoken_kind_t handle::THEN() {
	return TOKEN_THEN;
}

yytoken_kind_t handle::ELSE() {
	return TOKEN_ELSE;
}

yytoken_kind_t handle::ENDIF() {
	return TOKEN_ENDIF;
}


yytoken_kind_t handle::YYEOF() {
	return TOKEN_YYEOF;
}

yytoken_kind_t handle::YYerror() {
	return TOKEN_YYerror;
}
