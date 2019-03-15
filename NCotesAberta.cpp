#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

//FUNÇÃO A SER UTILIZADA

double F(double x){
	return (-(pow(x, 2)) + 4);
}

//double F(double x){
//	return (-pow(x, 3) + 2);
//}

double NCgrau1A(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = I1;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/3;
		h1 = deltaX1/3;
		
		/*for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + ((3*h0/2) * (F(xp0 + h0) + F(xp0 + (2*h0))));
		}*/		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((3*h1/2) * (F(xp1 + h1) + F(xp1 + (2*h1))));
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	
	return I1;

}

double NCgrau2A(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = I1;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/4;
		h1 = deltaX1/4;
		
		/*for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + ((3*h0/2) * (F(xp0 + h0) + F(xp0 + (2*h0))));
		}*/		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((4*h1/3) * ((2*F(xp1 + h1)) + ((-1)*F(xp1 + (2*h1))) + (2*F(xp1 + (3*h1)))));
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	
	return I1;

}

double NCgrau3A(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = I1;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/5;
		h1 = deltaX1/5;
		
		/*for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + ((3*h0/2) * (F(xp0 + h0) + F(xp0 + (2*h0))));
		}*/		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((5*h1/24) * ((11*F(xp1 + h1)) + F(xp1 + (2*h1)) + F(xp1 + (3*h1)) + (11*F(xp1 + (4*h1)))));
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	
	return I1;

}

double NCgrau4A(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = I1;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/6;
		h1 = deltaX1/6;
		
		/*for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + ((3*h0/2) * (F(xp0 + h0) + F(xp0 + (2*h0))));
		}*/		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((6*h1/20) * ((11*F(xp1 + h1)) + ((-14)*F(xp1 + (2*h1))) + (26*F(xp1 + (3*h1))) + ((-14)*F(xp1 + (4*h1))) + (11*F(xp1 + (5*h1)))));
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	
	return I1;

}

double NCgrau5A(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = I1;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/7;
		h1 = deltaX1/7;
		
		/*for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + ((3*h0/2) * (F(xp0 + h0) + F(xp0 + (2*h0))));
		}*/		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((7*h1/1440) * ((611*F(xp1 + h1)) + ((-453)*F(xp1 + (2*h1))) + (562*F(xp1 + (3*h1))) + (562*F(xp1 + (4*h1))) + ((-453)*F(xp1 + (5*h1))) + (611*F(xp1 + (6*h1)))));
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	
	return I1;

}

int main(int narg, char *argv[]){

	cout<<NCgrau5A(-2, 2, 0.001)<<endl;
}
