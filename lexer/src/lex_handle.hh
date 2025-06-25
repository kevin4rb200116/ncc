
#pragma once

#include "parser.hh"
#include <cstdio>

namespace handle {
	// yytoken_kind_t WHITESPACE      (char* text);
	yytoken_kind_t COMMENT         (char* text);
	yytoken_kind_t NAME            (char* text);
	yytoken_kind_t HEX_NUMBER      (char* text);
	yytoken_kind_t BIN_NUMBER      (char* text);
	yytoken_kind_t OCT_NUMBER      (char* text);
	yytoken_kind_t DEC_NUMBER      (char* text);
	yytoken_kind_t FLOAT_NUMBER    (char* text);
	yytoken_kind_t STRING          (char* text);
} // namespace handle
