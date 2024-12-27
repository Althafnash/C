#include <stdio.h>
#include <math.h>

int main(){
	int ASide , OSide , Answer;

	printf("Enter the value for the Adjecent side : ");
	scanf("%d", &ASide);
	printf("Enter the value for the Opposite Side : ");
	scanf("%d",&OSide);

	OSide = sqrt(OSide);
	ASide = sqrt(ASide);
	Answer = OSide + ASide ;
	printf("The Hypotenus is %d",Answer);
}
