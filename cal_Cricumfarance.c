#include <stdio.h>

int main(){
	int Radius , Answer ; 
	const int PI = 3.14;
	printf("Enter the Radius : ");
	scanf("%d", &Radius);

	Answer = 2 * Radius * PI;
	printf("The cricumfarance is %d" , Answer);
}
