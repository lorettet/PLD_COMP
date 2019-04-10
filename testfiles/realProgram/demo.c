int calculateModulo(int a, int b) {
	return a - (a/b)*b;
}

int countOccurrences(int x, int d) { 
    int count = 0;  
    while (x > 0) 
    { 
        if (calculateModulo(x,10) == d) 
           count = count + 1; 
           
        x = x/10; 
    } 
    return count; 
} 
  

int maxOccurring(int x) { 
  
   int result = 0; 
   int max_count = 1; 
  
	 int d = 0;
	 
	 
   if (x < 0) 
      x = -x; 
      
   while(d <= 9) {
         int count = countOccurrences(x, d); 
  

      if (count >= max_count) 
      { 
         max_count = count; 
         result = d; 
      } 
      
      d = d+1;
   }
   
   return result; 
} 
  
int main() 
{ 
    int x = 1223; 
    return maxOccurring(x);
} 
