#include<stdio.h>
#include<math.h>
#define PI 3.14

double circle_area(double radius);
double calc_hypotenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);
double calc_area_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_square(int side1, int side2);
double calc_area_of_largest_square(int side1, int side2);
double calc_area_of_square(int side);
void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square);

int main(void){
	int side1, side2;
	printf("Enter first side for rectangle: ");
	scanf("%d", &side1);
	printf("Enter second side for rectangle: ");
	scanf("%d", &side2);
	
	double largest_circle, largest_square, smallest_circle, smallest_square;
	largest_circle = calc_area_of_largest_circle(side1, side2);
	largest_square = calc_area_of_largest_square(side1, side2);
	smallest_circle = calc_area_of_smallest_circle(side1, side2);
	smallest_square = calc_area_of_smallest_square(side1, side2);
	display_results(largest_circle, largest_square, smallest_circle, smallest_square);
	
	
	return (0);
}

double circle_area(double radius){
	double area = PI * pow(radius,2);													//cember alani = PI * r^2
	return area;
}

double calc_hypotenuse(int side1, int side2){
	double hypotenuse = (sqrt(pow(side1,2)+pow(side2,2)));								//hipotenus^2 = a^2 + b^2 (kok disina cikarmak icin sqrt fonksiyonu kullan)
	return hypotenuse;
}

double calc_radius_of_smallest_circle(int side1, int side2){
	double radius = calc_hypotenuse(side1, side2) / 2;									//cevreleyen en kucuk cemberin yaricapi dikdortgenin hipotenusunun yarisi(r = hipotenus / 2)
	return radius;
}

double calc_radius_of_largest_circle(int side1, int side2){
	double radius;
	if(side1<side2){																	//icine cizilen en buyuk cemberin yaricapi kisa kenarin yarisi
		radius = (double)side1 / 2;														//kenarlar integer ifade oldugu icin casting yap
	}
	else{
		radius = (double)side2 / 2;
	}
	return radius;
}

double calc_area_of_smallest_circle(int side1, int side2){
	double radius = calc_radius_of_smallest_circle(side1, side2);						//yaricapi bul
	double area = circle_area(radius);													//bulunan yaricap ile alani bul
	return area;
}

double calc_area_of_largest_circle(int side1, int side2){
	double radius = calc_radius_of_largest_circle(side1, side2);						//yaricapi bul
	double area = circle_area(radius);													//bulunan yaricap ile alani bul
	return area;
}

double calc_area_of_smallest_square(int side1, int side2){
	double area;
	if(side1<side2){																	//cevreleyen en kucuk kareyi bulmak icin uzun kenar secilir
		area = calc_area_of_square(side2);												//secilen uzun kenar karenin bir kenari olur ve alan islemi yapilir
	}
	else{
		area = calc_area_of_square(side1);
	}
	return area;
}

double calc_area_of_largest_square(int side1, int side2){
	double area;
	if(side1<side2){																	//icine cizilen en buyuk kareyi bulmak icin kisa kenar secilir
		area = calc_area_of_square(side1);												//secilen kisa kenar karenin bir kenari olur ve alan islemi yapilir
	}
	else{
		area = calc_area_of_square(side2);
	}
	return area;
}

double calc_area_of_square(int side){
	double area = pow(side,2);															//karenin alani = a^2
	return area;
}

void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square){										//elde edilen sonuclari ekrana cikti verir
	printf("The area of the largest circle that fits inside a rectangle:			%.2f\n", largest_circle);
	printf("The area of the largest square that fits inside a rectangle:			%.2f\n", largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle:		%.2f\n", smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle:		%.2f\n", smallest_square);
	
}

