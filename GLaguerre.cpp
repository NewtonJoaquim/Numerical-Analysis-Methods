#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <limits>
#include <iostream>
using namespace std;

double F(double x){
	return /*exp(-pow(x, 2))*/(-pow(x, 3) + 2); 
}

double GLaguerre(double a, double b, double t, double wi[], double xi[], int pontos){
	double I, I1 = 0;
	double a0, b0, a1, b1, aux0, aux1;
	double xp0, xp1, deltaX0, deltaX1;
	double N0, N1 = 1;
	
	int p, i;
	
	//a1 = a;
	//b1 = b;
	//do{

		I = 0;
		I1 = 0;		

		N0 = N1;
		N1 = 2*N1;

		//deltaX0 = (b-a)/N0;
		//deltaX1 = (b-a)/N1;
	
		/*for(i = 0; i < N0; i++){
			a0 = a + i*deltaX0;
			b0 = a0 + deltaX0;
			for(p = 0; p < 2; p++){
				xp0 = parametrizar(a0, b0, xi[p]);
				//aux0 = (wi[p]*F(xp0))*(deltaX0/2);
				I = I + (wi[p]*F(xp0)) /*aux0*/;
	/*		}
		}
		I = (deltaX0/2) * I;
		*/
		//for(i = 0; i < N1; i++){
		//	a1 = a + i*deltaX1;
		//	b1 = a1 + deltaX1;		
			for(p = 0; p < pontos; p++){
				//xp1 = parametrizar(a1, b1, xi[p]);
				//xp1 = F(xi[p]);
				//aux1 = (wi[p]*F(xp1))*(deltaX1/2);
				I1 = I1 +(wi[p]*F(xi[p]))/*aux1*/;
			}
		//}
		//I1 = (deltaX1/2) * I1;
		
		//cout<<I<<endl;
		//cout<<I1<<endl;
		//cout<<(fabs((I1 - I)/I))<<endl;
			
	//}while (fabs((I1 - I)/I) > t);
	
	//I1 = (deltaX1/2) * I1;

	return I1;
}

double GLaguerre_2Pontos(double a, double b, double t){
	double wi[] = {0.85355339, 0.14644660};
	double xi[] = {0.58578643, 3.41421356};
	
	return GLaguerre(a, b, t, wi, xi, 2);	
}

double GLaguerre_3Pontos(double a, double b, double t){
	double wi[] = {0.71109300, 0.27851973, 0.01038926};
	double xi[] = {0.41577455, 2.24428036, 6.28994508};
	
	return GLaguerre(a, b, t, wi, xi, 3);	
}

double GLaguerre_4Pontos(double a, double b, double t){
	double wi[] = {0.60315410, 0.35741869, 0.03888791, 0.00053929};
	double xi[] = {0.32254768, 1.74576110, 4.53662029, 9.39507091};
	
	return GLaguerre(a, b, t, wi, xi, 4);	
}

double GLaguerre_5Pontos(double a, double b, double t){
	double wi[] = {0.521756, 0.398667, 0.0759424, 0.00361176, 0.00002337};
	double xi[] = {0.26356, 1.4134, 3.59643, 7.08581, 12.6408};
	
	return GLaguerre(a, b, t, wi, xi, 5);	
}

double GLaguerre_6Pontos(double a, double b, double t){
	double wi[] = {0.45896467, 0.41700083, 0.11337338, 0.010399197, 0.0002610172, 0.0000089854791};
	double xi[] = {0.2228466042, 1.188932102, 2.992736326, 5.775143569, 9.837467418, 15.98287398};
	
	return GLaguerre(a, b, t, wi, xi, 6);	
}

int main(int narg, char *argv[]){
	double b = numeric_limits<double>::max();
	cout<<GLaguerre_6Pontos(0, b, 0.0001)<<endl;
	return 0;
}
