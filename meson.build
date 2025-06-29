project('ncc', ['cpp'],
  version : '0.1',
  meson_version: '>=1.5.0',
  default_options : [
    'warning_level=0',
    'cpp_std=c++17'
    ])

fs = import('fs')

llvm = dependency(
  'llvm',
  version: '>= 19.0.0',
  modules: ['core', 'orcjit', 'native'])

flex = find_program(
  'flex',
  version: '>= 2.6.0')

bison = find_program(
  'bison',
  version: '>= 3.8.0')

BISONFLAGS = [
  '--defines',
  '-Werror',
  '-Wall,dangling-alias',
  '--report=all',
  '--no-lines',
  '-Wcounterexamples',
  '--verbose']

subdir('lexer')

lexer_inc = include_directories(
  fs.relative_to(
    fs.parent(lexer_src[1].full_path()),
    '.',
  ))

subdir('parser')

parser_inc = include_directories(
  fs.relative_to(
    fs.parent(parser_src[1].full_path()),
    '.',
  ))

subdir('codegen')
