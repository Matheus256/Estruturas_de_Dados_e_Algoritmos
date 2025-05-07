#include <stdio.h>

int main(){
	int res = 0b1001101110001000;
	printf("Valor inicial: %b\n", res); 
	printf("Valo para termos o ou bit a bit: %b\n", 0b11 << 6);
	res &= ~(0b11 << 6);
	printf("Resultado binário: %b\n", res);
	return 0;
}
