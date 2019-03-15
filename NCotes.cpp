#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;


//FUNÇÃO A SER UTILIZADA
double F(double x){
	return (-(pow(x, 2)) + 4);
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
			I0 = I0 + (deltaX0/2 * (F(xp0)+ F(xp0 + deltaX0)));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + (deltaX1/2 * (F(xp1)+ F(xp1 + deltaX1)));
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
			I0 = I0 + (h0/3 * (F(xp0) + (4*F(xp0 + h0)) + F(xp0 + deltaX0)));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + (h1/3 * (F(xp1) + (4*F(xp1 + h1)) + F(xp1 + deltaX1)));
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
			I0 = I0 + ((3*h0/8) * (F(xp0) + (3*F(xp0 + h0)) + (3*F(xp0 + (2*h0))) + F(xp0 + deltaX0)));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((3*h1/8) * (F(xp1) + (3*F(xp1 + h1)) + (3*F(xp1 + (2*h1))) + F(xp1 + deltaX1)));
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
			I0 = I0 + ((2*h0/45) * ((7*F(xp0)) + (32*F(xp0 + h0)) + (12*F(xp0 + (2*h0))) + (32*F(xp0 + (3*h0))) + (7*F(xp0 + deltaX0))));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((2*h1/45) * ((7*F(xp1)) + (32*F(xp1 + h1)) + (12*F(xp1 + (2*h1))) + (32*F(xp1 + (3*h1))) + (7*F(xp1 + deltaX1))));
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
			I0 = I0 + ((5*h0/288) * ((19*F(xp0)) + (75*F(xp0 + h0)) + (50*F((xp0 + 2*h0))) + (50*F((xp0 + 3*h0))) + (75*F(xp0 + (4*h0))) + (19*F(xp0 + deltaX0))));
		}		
		
		for (p = 0; p<N1; p++){
			xp1 = a + (0.5 + p)*deltaX1;
			I1 = I1 + ((5*h1/288) * ((19*F(xp1)) + (75*F(xp1 + h1)) + (50*F(xp1 + (2*h1))) + (50*F(xp1 + (3*h1))) + (75*F(xp1 + (4*h1))) + (19*F(xp1 + deltaX1))));
		}
	
	
	}while (fabs((I1 - I0)/I0) > e); /*|| (I1 == 0 && I2 == 0)*/
	

	return I1;
}

int main(int narg, char *argv[]){

	int grau;
	double a, b, n, t;
	
	do{
	
	cout<<"Entre com o limite inferior do intervalo:"<<endl;
	cin>>a;
	
	cout<<"Entre com o limite superior do intervalo:"<<endl;
	cin>>b;
	
	if (a>b)
		cout<<"Intervalo inválido"<<endl;
	else{
		cout<<"Entre com a tolerânica (Ex: 0.1 , 0.001)"<<endl;
		cin>>t;
	
		cout<<"Entre com o grau:"<<endl;

	
		cin>>grau;
		
		if ((grau<0)||(grau>5))
			cout<<"Grau inválido"<<endl;
		else{
			if (grau == 1)
				cout<<"Integral : " << NCgrau1(a, b, t)<<endl;
			else if (grau == 2)
				cout<<"Integral : " <<NCgrau2(a, b, t)<<endl;
			else if (grau == 3)
				cout<<"Integral : " <<NCgrau3(a, b, t)<<endl;
			else if (grau == 4)
				cout<<"Integral : " <<NCgrau4(a, b, t)<<endl;
			else if (grau == 5)
				cout<<"Integral : " <<NCgrau5(a, b, t)<<endl;
			else
				cout<<"grau invalido"<<endl;
		}
	cout<<"Entre qualquer numero para recomecar, ou 0 para sair"<<endl;
	cin>>n;
	}
	}while (n!=0);
	//cout<<NCgrau5(-2, 2, 0.001)<<endl;
	return 0;
}

