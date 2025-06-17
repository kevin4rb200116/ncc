
#include <cstdio>

#include "lexer.hh"
#include "lexer/flex_lexer.hh"

typedef SYM_TYPE symbol;

void just_print(char *type, char *yytext) {
	fprintf(stdout, "{ %s:'%s' }\n", type, yytext);
}

symbol handle::STRING(char *yytext) {
	just_print((char *)"STRING", yytext);
	return symbol();
}

symbol handle::COMMENT(char *yytext) {
	just_print((char *)"COMMENT", yytext);
	return symbol();
}

symbol handle::WHITESPACE(char *yytext) {
	just_print((char *)"WHITESPACE", yytext);
	return symbol();
}

symbol handle::NAME(char *yytext) {
	just_print((char *)"NAME", yytext);
	return symbol();
}

symbol handle::HEX_NUMBER(char *yytext) {
	just_print((char *)"HEX_NUMBER", yytext);
	return symbol();
}

symbol handle::BIN_NUMBER(char *yytext) {
	just_print((char *)"BIN_NUMBER", yytext);
	return symbol();
}

symbol handle::OCT_NUMBER(char *yytext) {
	just_print((char *)"OCT_NUMBER", yytext);
	return symbol();
}

symbol handle::DEC_NUMBER(char *yytext) {
	just_print((char *)"DEC_NUMBER", yytext);
	return symbol();
}

symbol handle::FLOAT_NUMBER(char *yytext) {
	just_print((char *)"FLOAT_NUMBER", yytext);
	return symbol();
}

symbol handle::LPAR(char *yytext) {
	just_print((char *)"LPAR", yytext);
	return symbol();
}

symbol handle::RPAR(char *yytext) {
	just_print((char *)"RPAR", yytext);
	return symbol();
}

symbol handle::LSQB(char *yytext) {
	just_print((char *)"LSQB", yytext);
	return symbol();
}

symbol handle::RSQB(char *yytext) {
	just_print((char *)"RSQB", yytext);
	return symbol();
}

symbol handle::COLON(char *yytext) {
	just_print((char *)"COLON", yytext);
	return symbol();
}

symbol handle::COMMA(char *yytext) {
	just_print((char *)"COMMA", yytext);
	return symbol();
}

symbol handle::SEMI(char *yytext) {
	just_print((char *)"SEMI", yytext);
	return symbol();
}

symbol handle::PLUS(char *yytext) {
	just_print((char *)"PLUS", yytext);
	return symbol();
}

symbol handle::MINUS(char *yytext) {
	just_print((char *)"MINUS", yytext);
	return symbol();
}

symbol handle::STAR(char *yytext) {
	just_print((char *)"STAR", yytext);
	return symbol();
}

symbol handle::SLASH(char *yytext) {
	just_print((char *)"SLASH", yytext);
	return symbol();
}

symbol handle::VBAR(char *yytext) {
	just_print((char *)"VBAR", yytext);
	return symbol();
}

symbol handle::AMPER(char *yytext) {
	just_print((char *)"AMPER", yytext);
	return symbol();
}

symbol handle::LESS(char *yytext) {
	just_print((char *)"LESS", yytext);
	return symbol();
}

symbol handle::GREATER(char *yytext) {
	just_print((char *)"GREATER", yytext);
	return symbol();
}

symbol handle::EQUAL(char *yytext) {
	just_print((char *)"EQUAL", yytext);
	return symbol();
}

symbol handle::DOT(char *yytext) {
	just_print((char *)"DOT", yytext);
	return symbol();
}

symbol handle::PERCENT(char *yytext) {
	just_print((char *)"PERCENT", yytext);
	return symbol();
}

symbol handle::LBRACE(char *yytext) {
	just_print((char *)"LBRACE", yytext);
	return symbol();
}

symbol handle::RBRACE(char *yytext) {
	just_print((char *)"RBRACE", yytext);
	return symbol();
}

symbol handle::EQEQUAL(char *yytext) {
	just_print((char *)"EQEQUAL", yytext);
	return symbol();
}

symbol handle::NOTEQUAL(char *yytext) {
	just_print((char *)"NOTEQUAL", yytext);
	return symbol();
}

symbol handle::LESSEQUAL(char *yytext) {
	just_print((char *)"LESSEQUAL", yytext);
	return symbol();
}

symbol handle::GREATEREQUAL(char *yytext) {
	just_print((char *)"GREATEREQUAL", yytext);
	return symbol();
}

symbol handle::TILDE(char *yytext) {
	just_print((char *)"TILDE", yytext);
	return symbol();
}

symbol handle::CIRCUMFLEX(char *yytext) {
	just_print((char *)"CIRCUMFLEX", yytext);
	return symbol();
}

symbol handle::LEFTSHIFT(char *yytext) {
	just_print((char *)"LEFTSHIFT", yytext);
	return symbol();
}

symbol handle::RIGHTSHIFT(char *yytext) {
	just_print((char *)"RIGHTSHIFT", yytext);
	return symbol();
}

symbol handle::DOUBLESTAR(char *yytext) {
	just_print((char *)"DOUBLESTAR", yytext);
	return symbol();
}

symbol handle::PLUSEQUAL(char *yytext) {
	just_print((char *)"PLUSEQUAL", yytext);
	return symbol();
}

symbol handle::MINEQUAL(char *yytext) {
	just_print((char *)"MINEQUAL", yytext);
	return symbol();
}

symbol handle::STAREQUAL(char *yytext) {
	just_print((char *)"STAREQUAL", yytext);
	return symbol();
}

symbol handle::SLASHEQUAL(char *yytext) {
	just_print((char *)"SLASHEQUAL", yytext);
	return symbol();
}

symbol handle::PERCENTEQUAL(char *yytext) {
	just_print((char *)"PERCENTEQUAL", yytext);
	return symbol();
}

symbol handle::AMPEREQUAL(char *yytext) {
	just_print((char *)"AMPEREQUAL", yytext);
	return symbol();
}

symbol handle::VBAREQUAL(char *yytext) {
	just_print((char *)"VBAREQUAL", yytext);
	return symbol();
}

symbol handle::CIRCUMFLEXEQUAL(char *yytext) {
	just_print((char *)"CIRCUMFLEXEQUAL", yytext);
	return symbol();
}

symbol handle::LEFTSHIFTEQUAL(char *yytext) {
	just_print((char *)"LEFTSHIFTEQUAL", yytext);
	return symbol();
}

symbol handle::RIGHTSHIFTEQUAL(char *yytext) {
	just_print((char *)"RIGHTSHIFTEQUAL", yytext);
	return symbol();
}

symbol handle::DOUBLESTAREQUAL(char *yytext) {
	just_print((char *)"DOUBLESTAREQUAL", yytext);
	return symbol();
}

symbol handle::DOUBLESLASH(char *yytext) {
	just_print((char *)"DOUBLESLASH", yytext);
	return symbol();
}

symbol handle::DOUBLESLASHEQUAL(char *yytext) {
	just_print((char *)"DOUBLESLASHEQUAL", yytext);
	return symbol();
}

symbol handle::ELLIPSIS(char *yytext) {
	just_print((char *)"ELLIPSIS", yytext);
	return symbol();
}

symbol handle::RARROW(char *yytext) {
	just_print((char *)"RARROW", yytext);
	return symbol();
}

symbol handle::AT(char *yytext) {
	just_print((char *)"AT", yytext);
	return symbol();
}

symbol handle::ATEQUAL(char *yytext) {
	just_print((char *)"ATEQUAL", yytext);
	return symbol();
}

symbol handle::EOF_TOK(char *yytext) {
	exit(EXIT_SUCCESS);
	return symbol();
}

int main(int argc, char **argv, char **environv) {
	while (true)
		yylex();

	return EXIT_SUCCESS;
}
