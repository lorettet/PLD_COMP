int puissance(int a, int n) {
	if(n>0) {
		return a*puissance(a, n-1);
	} else {
		return 1;
	}
}

int main() {
	return puissance (6,3);
}
