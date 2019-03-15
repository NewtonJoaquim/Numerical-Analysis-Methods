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

double Xi(int i, int n){
	//double pi = 3.1415926535897;
	return cos((i-1.0/2)/n * M_PI);
}

double Wi(int n){
	//double pi = 3.1415926535897;
	return M_PI/n;	 
}

double GChebyshev (double n){
	int i;
	double I = 0;
	for(i=1; i<=n;i++){
		I = I + (F(Xi(i, n))*Wi(n));
	}
	
	return I;

}

int main (int narg, char *argv[]){
	int p;
	cout<<"Função sendo utilizada: -x³ + 2"<<endl;
	
	cout<<"Entre com o número de pontos:"<<endl;
	cin>>p;
	cout<<GChebyshev(p)<<endl;
	return 0;
}
