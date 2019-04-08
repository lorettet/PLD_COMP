#include <string>

class UndefindedVarException : public std::exception
{
  string func;
  string var;

  public:
    UndefindedVarException(string var_, string func_) : std::exception(), var(var_), func(func_)
    {
    }

    string what() throw()
    {
      return "Undefinded variable " + var + " in " + func;
    }
};
