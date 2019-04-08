int f(int a)
{
  if(a == 0)
  {
    return 1;
  }
  else
  {
    return a*f(a-1);
  }
}

int main()
{
  return f(5);
}
