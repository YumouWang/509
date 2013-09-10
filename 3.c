#define EOF -1

main(){
	
	int c;
	c = getchar();
	while(c != EOF){
		putchar(c);
		c = getchar();
	}
}