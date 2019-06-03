namespace fluster { namespace diagnostic {


// parser, analyzer, compiler should throw errors to be caught by
// the program and redirected to the log

// TODO: pick a dependency for coloring compiler terminal output e.g. ncurses

struct CompilationLog
{
    //verbosity
    //ignore_list;

    void error() ;

    void warning() ;

    void message() ;
};



} }  //namespace fluster::diagnostic
