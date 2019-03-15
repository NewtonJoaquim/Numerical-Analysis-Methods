

// FUNÇÃO A SER UTILIZADA: -(x ^ 2) + 4


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;


//UTILIZANDO RETANGULOS
double riemannRetangulos(double a, double b, int n){
	double I = 0;
	double xp, deltaX;

	deltaX = (b - a)/n;

	int p;
	for(p=0; p<n; p++){
		xp = a + (0.5 + p)*deltaX;
		I = I + (deltaX	* (-(pow(xp, 2)) + 4));
	}

	return I;
}

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


//UTILIZANDO TRAPÉZIOS
double riemannTrapezio(double a, double b, int n){
	double I = 0;
	double xp, deltaX;

	deltaX = (b - a)/n;

	int p;
	for(p=0; p<n; p++){
		xp = a + (0.5 + p)*deltaX;
		I = I + (deltaX	* 0.5 *((-(pow(xp, 2)) + 4)+ (-pow(xp + deltaX, 2) + 4)));
	}

	return I;
}


//UTILIZANDO CURVATURAS E INTERPOLAÇÃO
double riemannCurvatura(double a, double b, int n){
	double xp1, xp2, xp3;
	double deltaX; 
	double I = 0;

	deltaX = (b - a)/n;

	//cout<< deltaX<<endl;

	int p;
	for(p = 0; p<n; p++){
		xp1 = a + p*deltaX;
		xp3 = (a+deltaX) + p*deltaX;
		xp2 = (xp1 + xp3)/2;

		I = I + ((deltaX/6) * ((-(pow(xp1, 2)) + 4) + (4 * (-(pow(xp2, 2)) + 4)) + (-(pow(xp3, 2)) + 4))); 

		//cout<<xp1<<" "<< xp2<< " "<< xp3<< endl;
	}

	return I;
}


int main(int narg, char *argv[]){
	cout<<riemannCurvatura(-2, 2, 20)<<endl;;
	return 0;
}





