
#include <cstdlib>
#include <cstdio>

#include "lexer.hh"

#define YYTOKENTYPE 1
typedef enum : int {
	TOKEN_LPAR,
	TOKEN_RPAR,
	TOKEN_COMMA,
	TOKEN_SEMI,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_STAR,
	TOKEN_SLASH,

	TOKEN_DEF,
	TOKEN_EXTERN,

	TOKEN_NAME,
	TOKEN_BIN_NUMBER,
	TOKEN_OCT_NUMBER,
	TOKEN_DEC_NUMBER,
	TOKEN_HEX_NUMBER,
	TOKEN_FLOAT_NUMBER,

	TOKEN_YYEOF,
	TOKEN_YYerror,
} yytoken_kind_t;

#include "handle.hh"

struct YYLTYPE {
	int first_line;
	int first_column;
	int last_line;
	int last_column;
} yylloc;

void print_simple_token(const char *name) {
	fprintf(
		stdout,
		"{%s, %d.%d-%d.%d}",
		yylloc.first_line,
		yylloc.first_column,
		yylloc.last_line,
		yylloc.last_column,
		name
	);
}

void print_value_token(const char *name, const char *value) {
	fprintf(
		stdout,
		"{%s:%s, %d.%d-%d.%d}",
		yylloc.first_line,
		yylloc.first_column,
		yylloc.last_line,
		yylloc.last_column,
		name,
		value
	);
}

yytoken_kind_t handle::LPAR() {
	print_simple_token("LPAR");
	return TOKEN_LPAR;
}

yytoken_kind_t handle::RPAR() {
	print_simple_token("RPAR");
	return TOKEN_RPAR;
}

yytoken_kind_t handle::COMMA() {
	print_simple_token("COMMA");
	return TOKEN_COMMA;
}

yytoken_kind_t handle::SEMI() {
	print_simple_token("SEMI");
	return TOKEN_SEMI;
}

yytoken_kind_t handle::PLUS() {
	print_simple_token("PLUS");
	return TOKEN_PLUS;
}

yytoken_kind_t handle::MINUS() {
	print_simple_token("MINUS");
	return TOKEN_MINUS;
}

yytoken_kind_t handle::STAR() {
	print_simple_token("STAR");
	return TOKEN_STAR;
}

yytoken_kind_t handle::SLASH() {
	print_simple_token("SLASH");
	return TOKEN_SLASH;
}

yytoken_kind_t handle::NAME(const char* text) {
	print_value_token("NAME", text);
	return TOKEN_NAME;
}

yytoken_kind_t handle::HEX_NUMBER(const char* text) {
	print_value_token("HEX_NUMBER", text);
	return TOKEN_HEX_NUMBER;
}

yytoken_kind_t handle::BIN_NUMBER(const char* text) {
	print_value_token("BIN_NUMBER", text);
	return TOKEN_BIN_NUMBER;
}

yytoken_kind_t handle::OCT_NUMBER(const char* text) {
	print_value_token("OCT_NUMBER", text);
	return TOKEN_OCT_NUMBER;
}

yytoken_kind_t handle::DEC_NUMBER(const char* text) {
	print_value_token("DEC_NUMBER", text);
	return TOKEN_DEC_NUMBER;
}

yytoken_kind_t handle::FLOAT_NUMBER(const char* text) {
	print_value_token("FLOAT_NUMBER", text);
	return TOKEN_FLOAT_NUMBER;
}

yytoken_kind_t handle::DEF() {
	print_simple_token("DEF");
	return TOKEN_DEF;
}

yytoken_kind_t handle::EXTERN() {
	print_simple_token("EXTERN");
	return TOKEN_EXTERN;
}

yytoken_kind_t handle::YYEOF() {
	print_simple_token("YYEOF");
	printf("\n");
	return TOKEN_YYEOF;
}

yytoken_kind_t handle::YYerror() {
	print_simple_token("YYerror");
	printf("\n");
	return TOKEN_YYerror;
}

enum {
	YYSTDIN = 1,
	YYFILE = 2,
};

int main(int argc, char **argv) {
	switch (argc) {
		case (YYSTDIN):
			yyrestart(stdin);
			break;
		
		case (YYFILE):
			FILE *input = fopen(argv[1], "rt");
			yyrestart(input);
			break;
	}

	while (yylex() != TOKEN_YYEOF)
		continue;

	return EXIT_SUCCESS;
}
