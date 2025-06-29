
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
} yytoken_kind_t;

#include "handle.hh"

yytoken_kind_t handle::LPAR() {
	fprintf(stdout, "{LPAR}");
	return TOKEN_LPAR;
}

yytoken_kind_t handle::RPAR() {
	fprintf(stdout, "{RPAR}");
	return TOKEN_RPAR;
}

yytoken_kind_t handle::COMMA() {
	fprintf(stdout, "{COMMA}");
	return TOKEN_COMMA;
}

yytoken_kind_t handle::SEMI() {
	fprintf(stdout, "{SEMI}");
	return TOKEN_SEMI;
}

yytoken_kind_t handle::PLUS() {
	fprintf(stdout, "{PLUS}");
	return TOKEN_PLUS;
}

yytoken_kind_t handle::MINUS() {
	fprintf(stdout, "{MINUS}");
	return TOKEN_MINUS;
}

yytoken_kind_t handle::STAR() {
	fprintf(stdout, "{STAR}");
	return TOKEN_STAR;
}

yytoken_kind_t handle::SLASH() {
	fprintf(stdout, "{SLASH}");
	return TOKEN_SLASH;
}

yytoken_kind_t handle::NAME(const char* text) {
	fprintf(stdout, "{NAME:%s}", text);
	return TOKEN_NAME;
}

yytoken_kind_t handle::HEX_NUMBER(const char* text) {
	fprintf(stdout, "{HEX_NUMBER:%s}", text);
	return TOKEN_HEX_NUMBER;
}

yytoken_kind_t handle::BIN_NUMBER(const char* text) {
	fprintf(stdout, "{BIN_NUMBER:%s}", text);
	return TOKEN_BIN_NUMBER;
}

yytoken_kind_t handle::OCT_NUMBER(const char* text) {
	fprintf(stdout, "{OCT_NUMBER:%s}", text);
	return TOKEN_OCT_NUMBER;
}

yytoken_kind_t handle::DEC_NUMBER(const char* text) {
	fprintf(stdout, "{DEC_NUMBER:%s}", text);
	return TOKEN_DEC_NUMBER;
}

yytoken_kind_t handle::FLOAT_NUMBER(const char* text) {
	fprintf(stdout, "{FLOAT_NUMBER:%s}", text);
	return TOKEN_FLOAT_NUMBER;
}

yytoken_kind_t handle::DEF() {
	fprintf(stdout, "{DEF}");
	return TOKEN_DEF;
}

yytoken_kind_t handle::EXTERN() {
	fprintf(stdout, "{EXTERN}");
	return TOKEN_EXTERN;
}

yytoken_kind_t handle::YYEOF() {
	fprintf(stdout, "{YYEOF}\n");
	return TOKEN_YYEOF;
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
