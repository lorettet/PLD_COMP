int calculateModulo(int a, int b) {
	return a - (a/b)*b;
}


int main() {
	int a = 14;
	int b = 5;

	return calculateModulo(a,b);
}