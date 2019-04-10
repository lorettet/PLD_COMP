int main() {
	return factorial(5);
}

int factorial(int x) {
	int i = 1;
	int resultat =  1;
	while(i <= x) {
		resultat = i*resultat;
		i = i+1;
	}
	return resultat;
}
