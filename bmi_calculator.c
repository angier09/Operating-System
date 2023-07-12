#include <stdio.h>
#include<stdlib.h>

void bmi_calculator()
{
   float weight, height, bmi;

	printf("Enter your weight (in kg): ");
	scanf("%f", &weight);

	printf("Enter your height (in meters): ");
	scanf("%f", &height);

	bmi = weight / (height * height);

	printf("Your BMI is %.2f\n", bmi);

	if (bmi < 18.5)
	{
    	printf("You are underweight\n");
	}
	else if (bmi >= 18.5 && bmi <= 24.9)
	{
    	printf("Your weight is normal\n");
	}
	else if (bmi >= 25 && bmi <= 29.9)
	{
    	printf("You are overweight\n");
	}
	else
	{
    	printf("You are obese\n");
	}
}
int main()
{
	bmi_calculator();

}






