#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <limits>
#include <iostream>
using namespace std;


//double F(double x){
//	return (-(pow(x, 2)) + 4);
//}


double F(double x){
	return /*exp(-pow(x, 2))*/(-pow(x, 2) + 4); 
}

double parametrizar(double a, double b, double r){
	return (((a+b)/2) + (r*((b-a)/2)));
}

double GHermite(double a, double b, double t, double wi[], double xi[], int pontos){
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

		deltaX0 = (b-a)/N0;
		deltaX1 = (b-a)/N1;
	
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

double GHermite_2Pontos(double a, double b, double t){
	double wi[] = {0.88622692, 0.88622692};
	double xi[] = {-0.70710678, 0.70710678};
	
	return GHermite(a, b, t, wi, xi, 2);	
}

double GHermite_3Pontos(double a, double b, double t){
	double wi[] = {0.00000000, -1.22474487, 1.22474487};
	double xi[] = {1.18163590, 0.29540897, 0.29540897};
	
	return GHermite(a, b, t, wi, xi, 3);	
}

double GHermite_4Pontos(double a, double b, double t){
	double wi[] = {0.80491409, 0.80491409, 0.08131283, 0.08131283};
	double xi[] = {-0.52464762, -0.52464762, -1.65068012, 1.65068012};
	
	return GHermite(a, b, t, wi, xi, 4);	
}

double GHermite_5Pontos(double a, double b, double t){
	double wi[] = {0.94530872, 0.39361932, 0.39361932, 0.01995324, 0.01995324};
	double xi[] = {0.00000000, -0.95857246, 0.95857246, -2.02018287, 2.02018287};
	
	return GHermite(a, b, t, wi, xi, 5);	
}

double GHermite_6Pontos(double a, double b, double t){
	double wi[] = {0.3607615730481386, 0.3607615730481386, 0.4679139345726910, 0.4679139345726910, 0.1713244923791704, 0.1713244923791704};
	double xi[] = {0.6612093864662645, -0.6612093864662645, -0.2386191860831969, 0.2386191860831969, -0.9324695142031521, 0.9324695142031521};
	
	return GHermite(a, b, t, wi, xi, 6);	
}

int main(int narg, char *argv[]){
	double a = numeric_limits<double>::min();
	double b = numeric_limits<double>::max();

	cout<<GHermite_5Pontos(a, b, 0.0001)<<endl;
	//cout<<numeric_limits<double>::min()<<endl;
}
