
libnirgen = static_library(
  'nirgen',
  ['src/irgen.cc'],
  dependencies: [llvm],
  include_directories: [
    '../parser/src',
    'src','test'])

nirgen = executable(
  'nirgen',
  ['test/main.cc'],
  link_with: [libnparse, libnlex, libnirgen],
  dependencies: [llvm],
  include_directories: [
    lexer_inc,
    '../lexer/src',
    parser_inc,
    '../parser/src',
    'src','test'])

test('ncc_test',
  nirgen,
  args: '../nirgen/test/input.txt')
