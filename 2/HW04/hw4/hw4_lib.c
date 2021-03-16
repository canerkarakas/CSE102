/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/
#include <stdio.h>
#include "hw4_lib.h"
/*	Simpson kurali ile cozumleme yaptim.
**	kural : (delta/3) * [f(x0) + f(x0+delta)*4 + f(x1)*2 + f(x2)*4 + f(x3)*2 ... + f(xend)]
*/
double integral(double f(double x), double xs, double xe, double delta){
	double sum = f(xs);
	double intgrl;
	int n = (xe-xs)/delta;
	xs = xs + delta;
	for(int i=1; i<=n; ++i){
		if(i%2==0 && i!=n){
			sum = sum + (2 * f(xs));
			xs = xs + delta;
		}
		if(i%2==1 && i!=n){
			sum = sum + (4 * f(xs));
			xs = xs + delta;
		}
		if(i==n){
			sum = sum + f(xs);
		}
	}
	intgrl = (delta / 3) * sum;
	return intgrl;
}

int derivatives(double f(double a), double x, double eps, double * d1, double * d2){
	int result;
	if((2*eps!=0) && (eps*eps!=0)){
		*d1 = (f(x+eps) - f(x-eps)) / (2 * eps);
		*d2 = (f(x+eps) - (2*f(x)) + f(x+eps)) / (eps * eps);
		result = 1;
	}
	else{
		result = -1;
	}
	return result;
}


/*	Olabildigince fazla sayiyi fonksiyona gondererek sifir yapan degerleri tuttum
**	ne kadar kok varsa dondurup kalan kokleri sifirladim
*/
int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4){
	double min_num = 9999.90 * -1;
	double max_num = 9999.90;
	double up = 0.10;
	int result=0;
	while(min_num<max_num){
		//printf("\nmin_num = %.2f\n", min_num);
		if(f(min_num)==0){
			printf("\n1\n");
			//printf("\nroot_min_num = %.2f\n", min_num);
			result++;
			switch(result){
				case 1: *x1=min_num;/*printf("\n%.2f = x1\n", *x1);*/break;
				case 2: *x2=min_num;/*printf("\n%.2f = x2\n", *x2);*/break;
				case 3: *x3=min_num;/*printf("\n%.2f = x3\n", *x3);*/break;
				case 4: *x4=min_num;/*printf("\n%.2f = x4\n", *x4);*/break;
				default: break;
			}
			min_num = min_num + up;
		}
		else{
			min_num = min_num + up;
		}
	}
	if(result==1){
		*x2=0.0;
		*x3=0.0;
		*x4=0,0;
	}
	if(result==2){
		*x3=0,0;
		*x4=0,0;
	}
	if(result==3){
		*x4=0.0;
	}
	return result;
}

int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
	double e11, e22;
	double num_cal_of_deri = derivatives(f, x, eps, &e11, &e22);
	double actual_deri = derivatives(f, x, eps, e1, e2);
	*e1 = *e1 - e11;
	*e2 = *e2 - e22;
	return 1;
}
