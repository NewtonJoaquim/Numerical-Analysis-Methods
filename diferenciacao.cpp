#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;

double F(double x){
	return (-(pow(x, 3)) + 2);
}

double forward(int x, vector<double> pontos, int o){
	double deltaX;
	deltaX = pontos.at(x+1)-pontos.at(x);
	if (o > 1){
		return (forward(x+1, pontos, o-1) - forward(x, pontos, o-1))/deltaX; 
	}
	else{
		return (F(pontos.at(x+1)) - F(pontos.at(x)))/deltaX;	
	}
}

double backward(int x, vector<double> pontos, int o){
	double deltaX = pontos.at(x) - pontos.at(x-1); 
	if (o > 1)
		return (backward(x, pontos, o-1) - backward(x-1, pontos, o-1))/deltaX;
	else
		return (F(pontos.at(x)) - F(pontos.at(x-1)))/deltaX; 
}

double central(int x, vector<double> pontos, int o){
	double deltaX = pontos.at(x+1) - pontos.at(x-1);
	if (o>1)
		return (central(x+1, pontos, o-1) - central(x-1, pontos, o-1))/deltaX;
	else 
		return (F(pontos.at(x+1)) - F(pontos.at(x-1)))/deltaX; 
}

/*double derivada(vector<double> pontos, int o) {
	double d = 0;

	for (int i = 0; i < pontos.size();i++){
		if(i = 0)
			d =+ forward(i, pontos, o);
		else if (i = pontos.size()-1)
			d =+ backward(i, pontos,o);
		else
			d =+ central(i, pontos, o);
	}
	return d;
}
*/
double derivada(int x, vector<double> pontos, int o) {
	double d = 0;

		if(x = 0)
			d =+ forward(x, pontos, o);
		else if (x = pontos.size()-1)
			d =+ backward(x, pontos,o);
		else if (x > pontos.size())
			cout<<"valor inválido para a posição"<<endl;
		else
			d =+ central(x, pontos, o);
	return d;
}

int main (int narg , char *argv[]){
	double pontos[] = {1, 3, 5, 7};
	vector<double> pontoss (pontos, pontos + sizeof(pontos) / sizeof(double));
	cout<<derivada(3, pontoss, 1)<<endl;
}
