#
# Build configuration for flusterc
#

project('Fluster', ['cpp'],
  version : '0.1',
  license : 'MIT',
  meson_version : '>= 0.49',
  default_options : ['warning_level=3', 'cpp_std=c++17']
)

prog_reflex = find_program('reflex', required : true)
prog_bison = find_program('bison', required : true)

on_linux = host_machine.system() == 'linux'
on_windows = ['windows', 'cygwin'].contains(host_machine.system())
on_macos = host_machine.system() == 'darwin'

llvm_modules = ['engine']
llvm_version = '>= 8.0.0'

llvm_dep = dependency('llvm',
  version : llvm_version,
  modules : llvm_modules,
  required : true
)
  
if not llvm_dep.found()
  error('LLVM (version at least 8.0.0) not found')
else
  llvm_version = llvm_dep.version().split('.')
endif


lexer = run_command([prog_reflex, 'src/lexer.l']).stdout()
parser = run_command([prog_bison, 'src/parser.y']).stdout()

if get_option('buildtype') == 'debug'
  add_project_arguments('-DDEBUG', language : ['cpp'])
endif

inc_include = include_directories('include')

exe = executable('flusterc', 'src/main.cpp')
#install : true

test('basic', exe)
