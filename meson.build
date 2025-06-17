project('ncc', ['c', 'cpp'],
  version : '0.1',
  meson_version: '>=1.5.0',
  default_options : [
    'warning_level=0',
    'cpp_std=c++14'
    ])

dependency(
  'llvm',
  version: '>= 19.0.0',
  modules: ['core'])

flex = find_program(
  'flex',
  version: '>= 2.6.0')

bison = find_program(
  'bison',
  version: '>= 3.8.0')

CXXFLAGS = run_command('sh','-c',
  'llvm-config-19 --cxxflags',
  capture: true,
  check: true).stdout().strip().split()

CXXFLAGS += [
  '-I../parser/src',
  '-I../lexer/src',
  '-I../driver/src',
  '-Wall',
  '-I@BUILD_ROOT@']

LDFLAGS = run_command('sh', '-c',
  'llvm-config-19 --cxxflags --ldflags --system-libs --libs core orcjit native',
  capture: true,
  check: true).stdout().strip().split()

BISONFLAGS = [
  # '--defines',
  # '-Werror',
  # '-Wall,dangling-alias',
  # '--report=all',
  # '--no-lines',
  # '-Wcounterexamples',
  '--verbose']

compile = ['c++', CXXFLAGS, '-c', '-o', '@OUTPUT@', '@INPUT@']

link = ['c++', LDFLAGS, '-ly', '-o', '@OUTPUT@', '@INPUT@']

parser_src = custom_target(
  'parser_src',
  input: 'parser/src/main.yxx',
  output: [
    'parser.cc',
    'parser.hh',
    'parser.gv',
    'parser.html',
    'parser.xml',
    'parser.output',
    'location.hh'],
  command: [bison, BISONFLAGS,
    '--output=@OUTPUT0@',
    '--header=@OUTPUT1@',
    '--graph=@OUTPUT2@',
    '--html=@OUTPUT3@',
    '--xml=@OUTPUT4@',
    '@INPUT@'])

subdir('lexer')
subdir('parser')
