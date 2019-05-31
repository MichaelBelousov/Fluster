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
               '-d',
               '-o', '@OUTPUT0@',
               '--header-file=@OUTPUT1@']
)


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

# llvm dependency

llvm_modules = ['all-targets']
llvm_version = '>= 6.0.0'

llvm_dep = dependency('llvm',
  version : llvm_version,
  modules : llvm_modules
)
  
if not llvm_dep.found()
  error('LLVM (version @0@) not found'.format(llvm_version))
else
  llvm_version = llvm_dep.version().split('.')
  deps += [llvm_dep]
endif

# reflex dependency

#reflex_version = '>= 1.2.1'
reflex_dep = compiler.find_library(
  'reflex',
  dirs : ['/usr/local/lib']
)

deps += reflex_dep


if get_option('buildtype') == 'debug'
  add_project_arguments('-DDEBUG', language : ['cpp'])
endif


includes = include_directories('src')

parser_src = [ lexer
             , 'src/lexer_routines.cpp'
             , parser
             ]

ast_src = [ 'src/ast/block.cpp'
          , 'src/ast/comma_delimited_list.cpp'
          , 'src/ast/identifier.cpp'
          , 'src/ast/if_statement.cpp'
          , 'src/ast/node.cpp'
          , 'src/ast/expr.cpp'
          ]

ast_src += [ 'src/ast/ops/add.cpp'
           , 'src/ast/ops/assert_type.cpp'
           , 'src/ast/ops/assign.cpp'
           , 'src/ast/ops/divide.cpp'
           , 'src/ast/ops/int_divide.cpp'
           , 'src/ast/ops/multiply.cpp'
           , 'src/ast/ops/negate.cpp'
           , 'src/ast/ops/postdecrement.cpp'
           , 'src/ast/ops/postincrement.cpp'
           , 'src/ast/ops/power.cpp'
           , 'src/ast/ops/predecrement.cpp'
           , 'src/ast/ops/preincrement.cpp'
           , 'src/ast/ops/root.cpp'
           , 'src/ast/ops/square_root.cpp'
           , 'src/ast/ops/subtract.cpp'
           ]

ast_src += [ 'src/ast/lits/float.cpp'
           , 'src/ast/lits/integer.cpp'
           , 'src/ast/lits/string.cpp'
           ]


data_src = []

atoms_src = [ 'src/atoms/types.cpp' ]

srcs = parser_src + ast_src + data_src + atoms_src

exe = executable('flusterc',
  'src/main.cpp', srcs,
  dependencies : deps,
  cpp_args : [],
  include_directories : includes
)

#runlex_exe = executable('runlex',
  #'src/runlex.cpp', srcs,
  #dependencies : deps,
  #cpp_args : [],
  #include_directories : includes
#)
#install : true

test('basic', exe)
