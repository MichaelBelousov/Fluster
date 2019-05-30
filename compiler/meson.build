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
prog_reflex = find_program('reflex')
src_dir = 'src/'
lexer_cpp_path = join_paths(src_dir, 'lexer.gen.cpp')
lexer_h_path = join_paths(src_dir, 'lexer.gen.h')
lexer_gen_result = run_command(prog_reflex, 'src/lexer.lpp',
    '-o', lexer_cpp_path,
    '--header-file=@0@'.format(lexer_h_path)
)
if lexer_gen_result.returncode() != 0
  error('lexer generation failed\n'
        +lexer_gen_result.stderr())
else
  message('Finished lexer generation')
endif

# generate parser
prog_bison = find_program('bison')
parser_cpp_path = join_paths(src_dir, 'parser.gen.cpp')
parser_h_path = join_paths(src_dir, 'parser.gen.h')
parser_gen_result = run_command(prog_bison, 'src/parser.ypp',
    '-o', parser_cpp_path,
    '--defines=@0@'.format(parser_h_path),
    '-v'
)
if parser_gen_result.returncode() != 0
  error('parser generation failed\n'
       + parser_gen_result.stderr())
else
  # message(open(join_paths(src_dir, 'parser.gen.output')).read())
  message('finished parser generation')
endif


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

exe = executable('flusterc', 'src/main.cpp',
  dependencies : deps,
  cpp_args : [],
  include_directories : includes
)
#install : true

test('basic', exe)
