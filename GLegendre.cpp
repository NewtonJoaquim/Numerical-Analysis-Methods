#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;


//double F(double x){
//	return (-(pow(x, 2)) + 4);
//}


double F(double x){
	return (-pow(x, 3) + 2);
}

double parametrizar(double a, double b, double r){
	return (((a+b)/2) + (r*((b-a)/2)));
}

double GLegendre(double a, double b, double t, double wi[], double xi[], int pontos){
	double I, I1 = 0;
	double a0, b0, a1, b1, aux0, aux1;
	double xp0, xp1, deltaX0, deltaX1;
	double N0, N1 = 1;
	
	int p, i;
	
	//a1 = a;
	//b1 = b;
	do{

		I = 0;
		I1 = 0;		

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b-a)/N0;
		deltaX1 = (b-a)/N1;
	
		for(i = 0; i < N0; i++){
			a0 = a + i*deltaX0;
			b0 = a0 + deltaX0;
			for(p = 0; p < pontos; p++){
				xp0 = parametrizar(a0, b0, xi[p]);
				//aux0 = (wi[p]*F(xp0))*(deltaX0/2);
				I = I + (wi[p]*F(xp0)) /*aux0*/;
			}
		}
		I = (deltaX0/2) * I;

		for(i = 0; i < N1; i++){
			a1 = a + i*deltaX1;
			b1 = a1 + deltaX1;		
			for(p = 0; p < pontos; p++){
				xp1 = parametrizar(a1, b1, xi[p]);
				//aux1 = (wi[p]*F(xp1))*(deltaX1/2);
				I1 = I1 +(wi[p]*F(xp1))/*aux1*/;
			}
		}
		I1 = (deltaX1/2) * I1;
		
		cout<<I<<endl;
		cout<<I1<<endl;
		//cout<<(fabs((I1 - I)/I))<<endl;
			
	}while (fabs((I1 - I)/I) > t);
	
	//I1 = (deltaX1/2) * I1;

	return I1;
}

double GLegendre_2Pontos(double a, double b, double t){
	double wi[] = {1.0, 1.0};
	double xi[] = {-0.57735, 0.57735};
	
	return GLegendre(a, b, t, wi, xi, 2);	
}

double GLegendre_3Pontos(double a, double b, double t){
	double wi[] = {0.888889, 0.555556, 0.555556 };
	double xi[] = {0.0, -0.7745966692414834, 0.7745966692414834};
	
	return GLegendre(a, b, t, wi, xi, 3);	
}

double GLegendre_4Pontos(double a, double b, double t){
	double wi[] = {0.6521451548625461, 0.6521451548625461, 0.3478548451374538, 0.3478548451374538};
	double xi[] = {-0.3399810435848563, 0.3399810435848563, -0.8611363115940526, 0.8611363115940526};
	
	return GLegendre(a, b, t, wi, xi, 4);	
}

double GLegendre_5Pontos(double a, double b, double t){
	double wi[] = {0.5688888888888889, 0.4786286704993665, 0.4786286704993665, 0.2369268850561891, 0.2369268850561891};
	double xi[] = {0.0, -0.5384693101056831, 0.5384693101056831, -0.9061798459386640, 0.9061798459386640};
	
	return GLegendre(a, b, t, wi, xi, 5);	
}

double GLegendre_6Pontos(double a, double b, double t){
	double wi[] = {0.3607615730481386, 0.3607615730481386, 0.4679139345726910, 0.4679139345726910, 0.1713244923791704, 0.1713244923791704};
	double xi[] = {0.6612093864662645, -0.6612093864662645, -0.2386191860831969, 0.2386191860831969, -0.9324695142031521, 0.9324695142031521};
	
	return GLegendre(a, b, t, wi, xi, 6);	
}

int main(int narg, char *argv[]){

	cout<<GLegendre_2Pontos(-2, 2, 0.0001)<<endl;
}
