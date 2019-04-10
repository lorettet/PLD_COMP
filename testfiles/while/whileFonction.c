int main() {
	int a = 0;
	while(fonctionWhile(a) < 10) {
		a = a+1;
	}
	return a;
}

int fonctionWhile(int a) {
	int i = 0;
	int somme = 0;
	while(i < a){
		somme = somme + i;
		i = i+1;
	}
	return somme;
}