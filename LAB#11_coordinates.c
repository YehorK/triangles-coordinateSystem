#include <stdio.h>
#include <math.h>

float funcPer(float*);
void output(float, float, int, int y, float(*)[y]);
float farea(float, float*);
float flength(int, int y, float(*)[y]);
void fperimeter(float*, int, int y, float(*)[y]);
void inputPoints(int, int y, float(*)[y]);
float inputNumber(float);
int main (void)
{
	int i, x, y;
	float num = 0.0f;
	y = 2;
	
	num = inputNumber(num);
	
	for (i = 0; i < num; i++){
		x = 3;
		float matrix[x][y];
		float perimeter, area;
		
		inputPoints(x, y, matrix);
		
		float arraySides[3];
		
		fperimeter(arraySides, x, y,matrix);
		
		perimeter = funcPer(arraySides);
		
		area = farea(perimeter, arraySides);
		
		output(perimeter, area, x, y, matrix);
		}
		
	return 0;	
}
////////////////////////////////////////////////////////////////////////
float inputNumber(float t)
{
	do{
		printf("Input how many triangles you want create? \n");
		scanf("%f", &t);
	}while(t < 1 || t > 3);
	return t;
}
////////////////////////////////////////////////////////////////////////
void inputPoints(int x, int y, float(*mat)[y])
{
	int m, j;
	
	float a, b;
	
	for(m = 0; m < x; m++){
		for(j = 0; j < y; j++){
			if (j == 0){
				printf("Enter the value for x of point: ");
				scanf("%f", &a);
				mat[m][j] = a;}
			else{
				printf("Enter the value for y of point: ");
				scanf("%f", &b);
				mat[m][j] = b;}	
			}
			printf("\n\n");
		}
}
////////////////////////////////////////////////////////////////////////
void fperimeter(float* arr, int x, int y, float (*mat)[y]){
	float a, b, c, d, e, f;
	float side1, side2, side3;
	
	
		a = mat[0][0];
		b = mat[0][1];
		
		c = mat[1][0];
		d = mat[1][1];
		
		e = mat[2][0];
		f = mat[2][1];
	
	
	side1 = sqrt(pow((c - a), 2) + pow((d - b), 2));
	side2 = sqrt(pow((e - a), 2) + pow((f - b), 2));
	side3 = sqrt(pow((e - c), 2) + pow((f - d), 2));
	
	arr[0] = side1;
	arr[1] = side2;
	arr[2] = side3;
}
////////////////////////////////////////////////////////////////////////
float funcPer(float* arr){
	float p;
	p = arr[0] + arr[1] + arr[2];
	return p;
}
////////////////////////////////////////////////////////////////////////
float farea(float perim, float* arr){
	
	float part, A;
	part = perim / 2;
	A = sqrt(part*(part - arr[0])*(part - arr[1])*(part - arr[2]));
	return A;
	
}
///////////////////////////////////////////////////////////////////////
void output(float perim, float A, int x, int y, float(*mat)[y]){
	int i, j;
	float a, b;
	
	printf("\nThe perimeter of your triangle is: %0.1f!\n", perim);
	printf("The area of your triangle is: %0.1f!\n", A);
	
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
		if (j == 0){a = mat[i][j];}
		else{b = mat[i][j];}
		}
		printf("\nThe length from origin to point%d is: %0.1f!\n", i+1, sqrt(pow(a, 2) + pow(b, 2)));
	}
	printf("\n\n\n");
}

