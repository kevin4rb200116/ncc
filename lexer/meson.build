
lexer_src = custom_target(
  'lexer_src',
  input: 'src/main.lxx',

  output: [
    'lexer.cc',
    'lexer.hh'],

  command: [flex,
    '--outfile=@OUTPUT0@',
    '--header-file=@OUTPUT1@',    
    '@INPUT@'])

libnlex = static_library(
  'nlex',
  [lexer_src[0]],
  include_directories: ['src','test'])

executable(
  'nlex',
  ['test/main.cc'],
  link_with: libnlex,
  include_directories: ['src','test'])
