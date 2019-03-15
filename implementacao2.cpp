#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

double riemannTolerancia(double a, double b, double e){
	double I0, I1 = 0;
	double N0 = 1;
	double N1 = 1;
	double xp0, xp1 , deltaX0, deltaX1;
	
	int p;

	do{
		
		I0 = 0;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + deltaX1 * (-pow(xp1, 2) + 4);
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	
	return I1; 
}

double NCgrau1(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1;
	
	int p;
	
	do{
		
		I0 = 0;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + (deltaX0/2 * ((-(pow(xp0, 2)) + 4)+ (-pow(xp0 + deltaX0, 2) + 4)));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + (deltaX1/2 * ((-(pow(xp1, 2)) + 4)+ (-pow(xp1 + deltaX1, 2) + 4)));
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	
	return I1;

}

double NCgrau2(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = 0;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/2;
		h1 = deltaX1/2;
		
		for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + (h0/3 * ((-(pow(xp0, 2)) + 4) + (4*(-pow(xp0 + h0, 2) + 4)) + (-pow(xp0 + deltaX0, 2) + 4)));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + (h1/3 * ((-(pow(xp1, 2)) + 4) + (4*(-pow(xp1 + h1, 2) + 4)) + (-pow(xp1 + deltaX1, 2) + 4)));
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	
	return I1;

}

double NCgrau3(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = 0;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/3;
		h1 = deltaX1/3;
		
		for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + ((3*h0/8) * ((-(pow(xp0, 2)) + 4) + (3*(-pow(xp0 + h0, 2) + 4)) + (3*(-pow(xp0 + (2*h0), 2) + 4)) + (-pow(xp0 + deltaX0, 2) + 4)));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((3*h1/8) * ((-(pow(xp1, 2)) + 4) + (3*(-pow(xp1 + h1, 2) + 4)) + (3*(-pow(xp1 + (2*h1), 2) + 4)) + (-pow(xp1 + deltaX1, 2) + 4)));
		}

	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	

	return I1;
}

double NCgrau4(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = 0;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/4;
		h1 = deltaX1/4;
		
		for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + ((2*h0/45) * ((7*(-(pow(xp0, 2)) + 4)) + (32*(-pow(xp0 + h0, 2) + 4)) + (12*(-pow(xp0 + (2*h0), 2) + 4)) + (32*(-pow(xp0 + (3*h0), 2) + 4)) + (7*(-pow(xp0 + deltaX0, 2) + 4))));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((2*h1/45) * ((7*(-(pow(xp1, 2)) + 4)) + (32*(-pow(xp1 + h1, 2) + 4)) + (12*(-pow(xp1 + (2*h1), 2) + 4)) + (32*(-pow(xp1 + (3*h1), 2) + 4)) + (7*(-pow(xp1 + deltaX1, 2) + 4))));
		}
	
	
	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	

	return I1;
}

double NCgrau5(double a, double b, double e){
	double I0, I1 =0;
	double N0, N1 =1;
	double xp0, xp1, deltaX0, deltaX1, h0, h1;
	
	int p;
	
	do{
		
		I0 = 0;
		I1 = 0;

		N0 = N1;
		N1 = 2*N1;

		deltaX0 = (b - a)/N0;
		deltaX1 = (b - a)/N1;
		
		h0 = deltaX0/5;
		h1 = deltaX1/5;
		
		for (p = 0; p<N0; p++){
			xp0 = a + (0.5 + p)*deltaX0;
			//I0 = I0 + deltaX0 * (-pow(xp0, 2) + 4);
			I0 = I0 + ((5*h0/288) * ((19*(-(pow(xp0, 2)) + 4)) + (75*(-pow(xp0 + h0, 2) + 4)) + (50*(-pow(xp0 + (2*h0), 2) + 4)) + (50*(-pow(xp0 + (3*h0), 2) + 4)) + (75*(-pow(xp0 + deltaX0, 2) + 4)) + (19*(-pow(xp0 + deltaX0, 2) + 4))));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((5*h1/288) * ((19*(-(pow(xp1, 2)) + 4)) + (75*(-pow(xp1 + h1, 2) + 4)) + (50*(-pow(xp1 + (2*h1), 2) + 4)) + (50*(-pow(xp1 + (3*h1), 2) + 4)) + (75*(-pow(xp1 + deltaX1, 2) + 4)) + (19*(-pow(xp1 + deltaX1, 2) + 4))));
		}
	
	
	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	

	return I1;
}

int main(int narg, char *argv[]){
	cout<<NCgrau5(-2, 2, 0.01)<<endl;;
	return 0;
}

