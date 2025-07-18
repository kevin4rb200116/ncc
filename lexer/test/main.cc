
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

	TOKEN_IF,
	TOKEN_THEN,
	TOKEN_ELSE,
	TOKEN_ENDIF,

	TOKEN_FOR,
	TOKEN_DO,
	TOKEN_ENDFOR,

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
		name,
		yylloc.first_line,
		yylloc.first_column,
		yylloc.last_line,
		yylloc.last_column
	);
}

#define SIMPLE_TOKEN(name)      \
yytoken_kind_t handle::name() { \
	print_simple_token(#name);    \
	return TOKEN_##name;          \
}

void print_value_token(const char *name, const char *value) {
	fprintf(
		stdout,
		"{%s:%s, %d.%d-%d.%d}",
		name,
		value,
		yylloc.first_line,
		yylloc.first_column,
		yylloc.last_line,
		yylloc.last_column
	);
}

#define VALUE_TOKEN(name)                       \
yytoken_kind_t handle::name(const char* text) { \
	print_value_token(#name, text);               \
	return TOKEN_##name;                          \
}

SIMPLE_TOKEN(LPAR)
SIMPLE_TOKEN(RPAR)
SIMPLE_TOKEN(COMMA)
SIMPLE_TOKEN(SEMI)
SIMPLE_TOKEN(PLUS)
SIMPLE_TOKEN(MINUS)
SIMPLE_TOKEN(STAR)
SIMPLE_TOKEN(SLASH)

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

VALUE_TOKEN(NAME)
VALUE_TOKEN(HEX_NUMBER)
VALUE_TOKEN(BIN_NUMBER)
VALUE_TOKEN(OCT_NUMBER)
VALUE_TOKEN(DEC_NUMBER)
VALUE_TOKEN(FLOAT_NUMBER)

SIMPLE_TOKEN(DEF)
SIMPLE_TOKEN(EXTERN)

SIMPLE_TOKEN(IF)
SIMPLE_TOKEN(THEN)
SIMPLE_TOKEN(ELSE)
SIMPLE_TOKEN(ENDIF)

SIMPLE_TOKEN(FOR)
SIMPLE_TOKEN(DO)
SIMPLE_TOKEN(ENDFOR)

SIMPLE_TOKEN(YYEOF)
SIMPLE_TOKEN(YYerror)


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
