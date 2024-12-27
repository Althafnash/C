#include <stdio.h>
#include <ctype.h>

int main(){
	char unit;
	float temp;

	printf("\n Is the temperature in  celsius (c) or Farhanet (F) : ");
	scanf("%d",&temp);

	unit = toupper(unit);

	if (unit == "C") {
		printf("\n Enter the temperature in celsius : ");
		scanf("%d",&temp);
		temp = ((temp - 32) * 5) + 32;
		printf("\nThe temperature in Frenheit is: %.1f",&temp);
	}else if (unit == "F") {
		printf("\n Enter the temperature in Farenheit : ");
		scanf("%d",&unit);
		temp = ((temp - 32) * 5) / 9;
		printf("\n The temperature in celcius is : %.1f",&temp);
	} else {
		printf("\n %c is not a correct unit", &unit);
	}
}

