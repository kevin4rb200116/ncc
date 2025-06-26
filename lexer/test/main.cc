
#include <cstdio>

#include "lex_handle.hh"
#include "lexer.hh"

/* yytoken_kind_t handle::WHITESPACE(char* text) {
	fprintf(stdout,"{ WHITESPACE: '%s' }\n", text);
	return TOKEN_WHITESPACE;
} */

yytoken_kind_t handle::COMMENT(char* text) {
	fprintf(stdout,"{ COMMENT: '%s' }\n", text);
	return TOKEN_COMMENT;
}

yytoken_kind_t handle::NAME(char* text) {
	fprintf(stdout,"{ NAME: '%s' }\n", text);
	return TOKEN_NAME;
}

yytoken_kind_t handle::HEX_NUMBER(char* text) {
	fprintf(stdout,"{ HEX_NUMBER: '%s' }\n", text);
	return TOKEN_HEX_NUMBER;
}

yytoken_kind_t handle::BIN_NUMBER(char* text) {
	fprintf(stdout,"{ BIN_NUMBER: '%s' }\n", text);
	return TOKEN_BIN_NUMBER;
}

yytoken_kind_t handle::OCT_NUMBER(char* text) {
	fprintf(stdout,"{ OCT_NUMBER: '%s' }\n", text);
	return TOKEN_OCT_NUMBER;
}

yytoken_kind_t handle::DEC_NUMBER(char* text) {
	fprintf(stdout,"{ DEC_NUMBER: '%s' }\n", text);
	return TOKEN_DEC_NUMBER;
}

yytoken_kind_t handle::FLOAT_NUMBER(char* text) {
	fprintf(stdout,"{ FLOAT_NUMBER: '%s' }\n", text);
	return TOKEN_FLOAT_NUMBER;
}

yytoken_kind_t handle::STRING(char* text) {
	fprintf(stdout,"{ STRING: '%s' }\n", text);
	return TOKEN_STRING;
}

int main(int argc, char **argv, char **environv) {
	yytoken_kind_t token =(yytoken_kind_t) yylex();

	while (token != TOKEN_YYEOF) {
		switch (token) {
			case (TOKEN_LPAR):
				fprintf(stdout, "{ LPAR }\n");
				break;

			case (TOKEN_RPAR):
				fprintf(stdout, "{ RPAR }\n");
				break;

			case (TOKEN_LSQB):
				fprintf(stdout, "{ LSQB }\n");
				break;

			case (TOKEN_RSQB):
				fprintf(stdout, "{ RSQB }\n");
				break;

			case (TOKEN_COLON):
				fprintf(stdout, "{ COLON }\n");
				break;

			case (TOKEN_COMMA):
				fprintf(stdout, "{ COMMA }\n");
				break;

			case (TOKEN_SEMI):
				fprintf(stdout, "{ SEMI }\n");
				break;

			case (TOKEN_PLUS):
				fprintf(stdout, "{ PLUS }\n");
				break;

			case (TOKEN_MINUS):
				fprintf(stdout, "{ MINUS }\n");
				break;

			case (TOKEN_STAR):
				fprintf(stdout, "{ STAR }\n");
				break;

			case (TOKEN_SLASH):
				fprintf(stdout, "{ SLASH }\n");
				break;

			case (TOKEN_VBAR):
				fprintf(stdout, "{ VBAR }\n");
				break;

			case (TOKEN_AMPER):
				fprintf(stdout, "{ AMPER }\n");
				break;

			case (TOKEN_LESS):
				fprintf(stdout, "{ LESS }\n");
				break;

			case (TOKEN_GREATER):
				fprintf(stdout, "{ GREATER }\n");
				break;

			case (TOKEN_EQUAL):
				fprintf(stdout, "{ EQUAL }\n");
				break;

			case (TOKEN_DOT):
				fprintf(stdout, "{ DOT }\n");
				break;

			case (TOKEN_PERCENT):
				fprintf(stdout, "{ PERCENT }\n");
				break;

			case (TOKEN_LBRACE):
				fprintf(stdout, "{ LBRACE }\n");
				break;

			case (TOKEN_RBRACE):
				fprintf(stdout, "{ RBRACE }\n");
				break;

			case (TOKEN_EQEQUAL):
				fprintf(stdout, "{ EQEQUAL }\n");
				break;

			case (TOKEN_NOTEQUAL):
				fprintf(stdout, "{ NOTEQUAL }\n");
				break;

			case (TOKEN_LESSEQUAL):
				fprintf(stdout, "{ LESSEQUAL }\n");
				break;

			case (TOKEN_GREATEREQUAL):
				fprintf(stdout, "{ GREATEREQUAL }\n");
				break;

			case (TOKEN_TILDE):
				fprintf(stdout, "{ TILDE }\n");
				break;

			case (TOKEN_CIRCUMFLEX):
				fprintf(stdout, "{ CIRCUMFLEX }\n");
				break;

			case (TOKEN_LEFTSHIFT):
				fprintf(stdout, "{ LEFTSHIFT }\n");
				break;

			case (TOKEN_RIGHTSHIFT):
				fprintf(stdout, "{ RIGHTSHIFT }\n");
				break;

			case (TOKEN_DOUBLESTAR):
				fprintf(stdout, "{ DOUBLESTAR }\n");
				break;

			case (TOKEN_PLUSEQUAL):
				fprintf(stdout, "{ PLUSEQUAL }\n");
				break;

			case (TOKEN_MINEQUAL):
				fprintf(stdout, "{ MINEQUAL }\n");
				break;

			case (TOKEN_STAREQUAL):
				fprintf(stdout, "{ STAREQUAL }\n");
				break;

			case (TOKEN_SLASHEQUAL):
				fprintf(stdout, "{ SLASHEQUAL }\n");
				break;

			case (TOKEN_PERCENTEQUAL):
				fprintf(stdout, "{ PERCENTEQUAL }\n");
				break;

			case (TOKEN_AMPEREQUAL):
				fprintf(stdout, "{ AMPEREQUAL }\n");
				break;

			case (TOKEN_VBAREQUAL):
				fprintf(stdout, "{ VBAREQUAL }\n");
				break;

			case (TOKEN_CIRCUMFLEXEQUAL):
				fprintf(stdout, "{ CIRCUMFLEXEQUAL }\n");
				break;

			case (TOKEN_LEFTSHIFTEQUAL):
				fprintf(stdout, "{ LEFTSHIFTEQUAL }\n");
				break;

			case (TOKEN_RIGHTSHIFTEQUAL):
				fprintf(stdout, "{ RIGHTSHIFTEQUAL }\n");
				break;

			case (TOKEN_DOUBLESTAREQUAL):
				fprintf(stdout, "{ DOUBLESTAREQUAL }\n");
				break;

			case (TOKEN_DOUBLESLASH):
				fprintf(stdout, "{ DOUBLESLASH }\n");
				break;

			case (TOKEN_DOUBLESLASHEQUAL):
				fprintf(stdout, "{ DOUBLESLASHEQUAL }\n");
				break;

			case (TOKEN_ELLIPSIS):
				fprintf(stdout, "{ ELLIPSIS }\n");
				break;

			case (TOKEN_RARROW):
				fprintf(stdout, "{ RARROW }\n");
				break;

			case (TOKEN_AT):
				fprintf(stdout, "{ AT }\n");
				break;

			case (TOKEN_ATEQUAL):
				fprintf(stdout, "{ ATEQUAL }\n");
				break;

			case (TOKEN_DEF):
				fprintf(stdout, "{ DEF }\n");
				break;

			case (TOKEN_EXTERN):
				fprintf(stdout, "{ EXTERN }\n");
				break;

			case (TOKEN_YYEOF):
				fprintf(stdout, "{ YYEOF }\n");
				break;

			default:
				break;
		}

		token =(yytoken_kind_t) yylex();
	}

	return EXIT_SUCCESS;
}
