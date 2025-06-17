
lexer_src = custom_target(
  'lexer_src',
  input: 'src/main.lxx',

  output: [
    'lexer.cc',
    'flex_lexer.hh'],
  depends: parser_src[0],
  command: [flex,
    '--outfile=@OUTPUT0@',
    '--header-file=@OUTPUT1@',    
    '@INPUT@'])

lexer_obj = custom_target(
  'lexer_obj',
  output: 'lexer.cc.o',
  input: lexer_src[0],
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
