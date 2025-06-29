
parser_src = custom_target(
  'parser_src',
  input: 'src/main.yxx',
  depends: lexer_src[1],

  output: [
    'parser.cc',
    'parser.hh',
    'parser.gv',
    'parser.html',
    'parser.xml',
    'parser.output',
    'location.hh'],
  
  command: [
    bison,
    BISONFLAGS,
    '--output=@OUTPUT0@',
    '--header=@OUTPUT1@',
    '--graph=@OUTPUT2@',
    '--html=@OUTPUT3@',
    '--xml=@OUTPUT4@',
    '@INPUT@'])

libnparse = static_library(
  'nparse',
  [
    parser_src[0],
    'src/handle.cc'],
  dependencies: [llvm],
  include_directories: [
    '../lexer/src',
    lexer_inc,
    'src',
    'test'])

nparse = executable(
  'nparse',
  ['test/main.cc'],
  dependencies: [llvm],
  link_with: [libnparse, libnlex],
  include_directories: [
    lexer_inc,
    'src',
    'test'])

test('nparse_test',
  nparse,
  args: '../parser/test/input.txt')
