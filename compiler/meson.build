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

# generate lexer
reflex_prog = find_program('reflex')
lexer = custom_target(
    'lexer.gen.cpp',
    input : 'src/lexer.lpp',
    output : ['lexer.gen.cpp', 'lexer.gen.h'],
    command : [reflex_prog, '@INPUT@',
               '-o', '@OUTPUT0@',
               '--header-file=@OUTPUT1@']
)
# lexer_h = custom_target(


# generate parser
bison_prog = find_program('bison')
parser = custom_target(
    'parser.gen.cpp',
    input : 'src/parser.ypp',
    output : ['parser.gen.cpp', 'parser.gen.h'],
    command : [bison_prog, '@INPUT@',
               '-v',
               '-o', '@OUTPUT0@',
               '--defines=@OUTPUT1@']
)


llvm_modules = ['all-targets']
llvm_version = '>= 6.0.0'

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


includes = include_directories('src')



main_src = [ lexer
           , 'src/lexer_routines.cpp'
           , parser
           ]

ast_src = [ 'src/ast/block.cpp'
          , 'src/ast/comma_delimited_list.cpp'
          , 'src/ast/identifier.cpp'
          , 'src/ast/if_statement.cpp'
          , 'src/ast/node.cpp'
          ]

data_src = []

atoms_src = [ 'src/atoms/types.cpp' ]

exe = executable('flusterc',
  'src/main.cpp',
  main_src,
  ast_src,
  data_src,
  atoms_src,
  dependencies : deps,
  cpp_args : [],
  include_directories : includes
)
#install : true

test('basic', exe)
