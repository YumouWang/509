main(){
	int lower, upper, step;
	int fahr, celsius;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while(fahr <= upper){
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%f %f\n", fahr, celsius);
		fahr = fahr + step;
	}
}