
libncc = static_library(
  'ncc',
  ['src/codegen.cc'],
  dependencies: [llvm],
  include_directories: [
    '../parser/src',
    'src','test'])

ncc = executable(
  'ncc',
  ['test/main.cc'],
  link_with: [libnparse, libnlex, libncc],
  dependencies: [llvm],
  include_directories: [
    lexer_inc,
    '../lexer/src',
    parser_inc,
    '../parser/src',
    'src','test'])

test('ncc_test',
  ncc,
  args: '../codegen/test/input.txt')
