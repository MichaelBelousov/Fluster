#
# Build configuration for flusterc
#

project('Fluster', 'cpp',
  version : '0.1',
  license : 'MIT',
  meson_version : '>= 0.50',
  default_options : [
    'warning_level=3',
    'cpp_std=c++17'
  ]
)

compiler = meson.get_compiler('cpp')

# dependencies
deps = []

# generate lexer and parser source
prog_reflex = find_program('reflex', 'reflex.exe')
prog_bison = find_program('bison', 'bison.exe')
run_command(prog_reflex, 'src/lexer.lpp')
run_command(prog_bison, 'src/parser.ypp')

on_linux = host_machine.system() == 'linux'
on_windows = ['windows', 'cygwin'].contains(host_machine.system())
on_macos = host_machine.system() == 'darwin'

llvm_modules = ['all-targets']
llvm_version = '>= 6.0.0'

# required by llvm
zlib_dep = dependency('zlib')

llvm_dep = dependency('llvm',
  version : llvm_version,
  modules : llvm_modules
)

  
if not llvm_dep.found()
  error('LLVM (version at least 8.0.0) not found')
else
  llvm_version = llvm_dep.version().split('.')
  deps += [llvm_dep]
endif



if get_option('buildtype') == 'debug'
  add_project_arguments('-DDEBUG', language : ['cpp'])
endif

inc_include = include_directories('include')

exe = executable('flusterc', 'src/main.cpp',
  dependencies : deps,
  cpp_args : []
)
#install : true

test('basic', exe)
