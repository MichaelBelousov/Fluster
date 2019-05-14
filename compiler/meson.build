project('Fluster', 'cpp',
  version: '0.1',
  default_options : ['warning_level=3']
)

lexer = command('reflex', 'src/lexer.l')
parser = command('bison', 'src/parser.y')

exe = executable('flusterc', 'src/main.cpp')
#install : true

test('basic', exe)
