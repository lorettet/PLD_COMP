#include "symboles.h"

string TestExprLogique::buildIR(CFG & cfg)
{
  cout << "-= Building IR TestExpr =-" << endl;
  string var1 = expression1->buildIR(cfg);
  string var2 = expression2->buildIR(cfg);

}
