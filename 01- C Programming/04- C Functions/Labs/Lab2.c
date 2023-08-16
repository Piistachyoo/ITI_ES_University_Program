#include <stdio.h>

int g_n1 = 10;
int g_n2 = 20;

void swap_globals(void);

int main(){
	printf("Number 1 before swap: %d\n", g_n1);
	printf("Number 2 before swap: %d\n\n", g_n2);
	swap_globals();
	printf("Number 1 after swap: %d\n", g_n1);
	printf("Number 2 after swap: %d\n", g_n2);
	return 0;
}

void swap_globals(void){
	int temp_var = g_n1;
	g_n1 = g_n2;
	g_n2 = temp_var;
	printf("Swap done!!\n\n");
}
