
parser_obj = custom_target(
  'parser_obj',
  output: 'parser.cc.o',
  input: parser_src[0],
  depends: lexer_obj[0],
  command: compile)

parser_bin = custom_target(
  'parser',
  output: 'parser',
  input: [
    lexer_obj[0],
    lex_handle_obj,
    parser_obj[0], 
    custom_target(
      'parser_main',
      output: 'main.cc.o',
      input: 'test/main.cc',
      depends: parser_obj,
      command: compile)],
  command: link)
