
int main()
{
  int a=12;
  int b = 6;
  int c=0;
  if(a <= b*3) {
    if(a != 12) {
      c = 9;
      c = somme(c,a);
    } else {
      c = 10;
      c = somme(c,15);
    }
    a = 100;
  }
  return c;
}

int somme(int a, int b){
  return a+b;
}
