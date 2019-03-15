#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<limits>
#include<cmath>
 
using namespace std;
double tangh(double x){
	return((exp(x)-exp(-x))/(exp(x)+exp(-x)));
}
double cosh(double x){
	return((exp(x)+exp(-x))/2);
}
double F(double x){
	return 1/sqrt(x);
}
double gs(double a,double b,double s){
	return F((((a+b)/2)+(((b-a)/2)*(tangh(s)))))*(1/pow(cosh(s),2));
}
double ExpSimples(double a, double b,double e){
	double I=0,I1,I2,N;
	double deltax,inf,sup,x1,x2;
	inf = -1;
	sup = 1;
	do{ 
		N = 1;
		I2 = I;
		inf *= 1.1;
		sup *= 1.1;
		do{
			I1 = I;
			I = 0;
			N *= 2;
			deltax = (sup-inf)/N;
			for(int p=0;p<N;p++){
				x1 = inf + p*deltax;
				x2 = x1 + deltax;
				I = I + (deltax*(gs(a,b,x1) + gs(a,b,x2))/2);	
			}
			I *= (b-a)/2;
		}while(abs((I-I1)/I1)>=e);
	}while(abs((I-I2)/I2)>=e);
		return I2;	
}			
int main (int narg , char *argv[]){
double a,b,e;
int n,t=1;
do{
cout<<"Função a ser utilizada: 1/sqrt(x) "<<endl;
cout<<"Entre com o limite inferior do intervalo:"<<endl;
cin>>a;
cout<<"Entre com o limite superior do intervalo:"<<endl;
cin>>b;
cout<<"Entre com a precisao:"<<endl;
cin>>e;
cout<<"Integral: "<<ExpSimples(a,b,e)<<endl;
cout<<"Digite qualquer numero para recomecar ou 0 para sair"<<endl;
cin>>t;
}while(t!=0);
return 0;
  
}


