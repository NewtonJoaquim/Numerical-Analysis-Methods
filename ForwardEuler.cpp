#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;

double F(double un, double tn){
	return -(3*un) - (10*tn);
}

double ForwardEuler(double estadoInicial, double deltaT, double tempoInicial){
	return estadoInicial + (deltaT*F(estadoInicial, tempoInicial));
}


double iteracaoFW(int n, double estadoInicial, double deltaT, double tempoInicial){
	double estadoAtual = estadoInicial;
	double tempoAtual = tempoInicial;

	for(int i = 0; i<n; i++){
		estadoAtual = ForwardEuler(estadoAtual, deltaT, tempoAtual);
		tempoAtual = tempoAtual + deltaT;
	}
	
	return estadoAtual;

}

int main(){
	double u0, t0, deltaT;
	int n;

	cout<<"A fórmula é -3u - 10t"<<endl<<endl;

	cout<<"Entre com o valor para o estado inicial u0"<<endl;
	cin>>u0;

	cout<<"Entre com o valor para o deltaT"<<endl;
	cin>>deltaT;

	cout<<"Entre com o valor do tempo inicial"<<endl;
	cin>>t0;

	cout<<"Entre com o o numero do estado que deseja calcular (Ex: u2, u3)"<<endl;
	cin>>n;

	cout<<iteracaoFW(n, u0, deltaT, t0)<<endl;
	//cout<<ForwardEuler(u0, deltaT, t0)<<endl;
	return 0;
}
