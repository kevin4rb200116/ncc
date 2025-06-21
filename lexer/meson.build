
lexer_obj = custom_target(
  'lexer_obj',
  output: 'lexer.cc.o',
  input: lexer_src[0],
  depends: parser_src[1],
  command: compile)

lex_handle_obj = custom_target(
  'lex_handle_obj',
  output: 'lex_handle.cc.o',
  input: 'src/lex_handle.cc',
  depends: parser_src[1],
  command: compile)

lexer_bin = custom_target(
  'lexer',
  output: 'lexer',
  input: [
    lexer_obj,
    custom_target(
      'lexer_main',
      output: 'main.cc.o',
      input: 'test/main.cc',
      command: compile)],
  command: link)
