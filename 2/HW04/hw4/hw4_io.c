/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include <stdio.h>
#include "hw4_io.h"

int read_polynomial3(double *a0, double *a1, double *a2, double *a3){
	double a00, a11, a22, a33;
	scanf("%lf%lf%lf%lf", &a00, &a11, &a22, &a33);
	*a0 = a00;
	*a1 = a11;
	*a2 = a22;
	*a3 = a33;
	int result = 1;
	return result;
}

int read_polynomial4(double *a0, double *a1, double *a2, double *a3, double *a4){
	double a00, a11, a22, a33, a44;
	scanf("%lf%lf%lf%lf%lf", &a00, &a11, &a22, &a33, &a44);
	*a0 = a00;
	*a1 = a11;
	*a2 = a22;
	*a3 = a33;
	*a4 = a44;
	int result = 1;
	return result;
}

void write_polynomial3(double a0, double a1, double a2, double a3){
	scanf("%lf%lf%lf%lf", &a0, &a1, &a2, &a3);
	char sem1, sem2, sem3, sem4;
	if(a0<0){
		sem1 = '-';
		if(a0==-1){
			printf("%cx^3", sem1);
		}
		else{
			printf("%c%.fx^3", sem1, a0* -1);
		}
	}
	if(a0==0){
		sem1 = ' ';
	}
	if(a0>0){
		sem1 = ' ';
		if(a0==1){
			printf("x^3");
		}
		else{
			printf("%.0fx^3", a0);
		}
	}
	if(a1<0){
		sem2 = '-';
		if(a1==-1){
			printf("%cx^2", sem2);
		}
		else{
			printf("%c%.0fx^2", sem2, a1 * -1);
		}
	}
	if(a1==0){
		sem2 = ' ';
	}
	if(a1>0){
		sem2 = '+';
		if(a1==1){
			printf("%cx^2", sem2);
		}
		else{
			printf("%c%.0fx^2", sem2, a1);
		}
	}
	if(a2<0){
		sem3 = '-';
		if(a2==-1){
			printf("%cx", sem3);
		}
		else{
			printf("%c%.0fx", sem3, a2 * -1);
		}
	}
	if(a2==0){
		sem3 = ' ';
	}
	if(a2>0){
		sem3 = '+';
		if(a2==1){
			printf("%cx", sem3);
		}
		else{
			printf("%c%.0fx", sem3, a2);
		}
	}
	if(a3<0){
		sem4 = '-';
		printf("%c%.0f", sem4, a3 * -1);
	}
	if(a3==0){
		sem4 = ' ';
	}
	if(a3>0){
		sem4 = '+';
		printf("%c%.0f", sem4, a3);
	}
}

void write_polynomial4(double a0, double a1, double a2, double a3, double a4){
	scanf("%lf%lf%lf%lf%lf", &a0, &a1, &a2, &a3, &a4);
	char sem1, sem2, sem3, sem4, sem5;
	if(a0<0){
		sem1 = '-';
		if(a0==-1){
			printf("%cx^4", sem1);
		}
		else{
			printf("%c%.fx^4", sem1, a0* -1);
		}
	}
	if(a0==0){
		sem1 = ' ';
	}
	if(a0>0){
		sem1 = ' ';
		if(a0==1){
			printf("x^4");
		}
		else{
			printf("%.0fx^4", a0);
		}
	}
	if(a1<0){
		sem2 = '-';
		if(a1==-1){
			printf("%cx^3", sem2);
		}
		else{
			printf("%c%.0fx^3", sem2, a1 * -1);
		}
	}
	if(a1==0){
		sem2 = ' ';
	}
	if(a1>0){
		sem2 = '+';
		if(a1==1){
			printf("%cx^3", sem2);
		}
		else{
			printf("%c%.0fx^3", sem2, a1);
		}
	}
	if(a2<0){
		sem3 = '-';
		if(a2==-1){
			printf("%cx^2", sem3);
		}
		else{
			printf("%c%.0fx^2", sem3, a2 * -1);
		}
	}
	if(a2==0){
		sem3 = ' ';
	}
	if(a2>0){
		sem3 = '+';
		if(a2==1){
			printf("%cx^2", sem3);
		}
		else{
			printf("%c%.0fx^2", sem3, a2);
		}
	}
	if(a3<0){
		sem4 = '-';
		if(a3==-1){
			printf("%c", sem4);
		}
		else{
			printf("%c%.0fx", sem4, a3 * -1);
		}
	}
	if(a3==0){
		sem4 = ' ';
	}
	if(a3>0){
		sem4 = '+';
		if(a3==1){
			printf("%c", sem4);
		}
		else{
			printf("%c%.0f", sem4, a3);
		}
	}
	if(a4<0){
		sem5 = '-';
		printf("%c%.0f", sem5, a4 * -1);
	}
	if(a4==0){
		sem5 = ' ';
	}
	if(a4>0){
		sem5 = '+';
		printf("%c%.0f", sem5, a4);
	}
}
