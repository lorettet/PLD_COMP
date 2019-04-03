int f(int a, int b, int c, int d, int e, int f){
	return a+b+c+d+e+f;
}

int main(){
	return f(1,2,3,4,5,6) + (-f(1,2,3,4,5,6));
}
