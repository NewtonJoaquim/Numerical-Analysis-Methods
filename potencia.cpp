#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<iostream>
using namespace std;

double autovalor2 = 0;
double *autovetor;

double** multMatriz(double **m1, double **m2, int tam1i, int tam1j, int tam2i, int tam2j){

	int i, j, w;
    double **m3;

    m3 = (double**)malloc((tam1i)*sizeof(double*));

	for(i=0;i<tam1i;i++)
        m3[i] = (double*)calloc((tam2j),sizeof(double));

	if(tam1j==tam2i){

		for(w=0;w<tam1i;w++){
			for(i=0;i<tam1j;i++) {
				for(j=0;j<tam2j;j++){
					m3[w][j] += (m1[w][i])*(m2[i][j]);
				}
			}
		}
	}
	return m3;
}

double* multMatrizVetor(double **m1, double *v, int tam1i, int tam1j, int tam2i){

	int i, w;
    double *v2;

    v2 = (double*)calloc((tam1i),sizeof(double*));

	if(tam1j==tam2i){
		for(w=0;w<tam1i;w++){
			for(i=0;i<tam2i;i++) {
				v2[w] += (m1[w][i])*(v[i]);
			}
		}
	}
	//v2[tam2i-1] = 1;
	return v2;
}

double produtoEscalar(double *v1, double *v2, int tam){
    double v;
	int i;
	v = 0;
	for(i=0;i<tam;i++)
		v += v1[i]*v2[i];
	return v;
}

double raizEuclidiana(double *v, int tam){
	double s = 0;
	for(int i=0;i<tam;i++){
		s = s + pow(v[i], 2);
	}
	
	return sqrt(s);
}

void metodoPotencia(double **a, double *v, double e, int tam){
	int i;
	double *v1, *v2/*, *autovetor*/;
	//double autovalor2 = 0;
	double autovalor;
	
	v1 = (double*)calloc((tam),sizeof(double));	
	v2 = (double*)calloc((tam),sizeof(double));
	autovetor = (double*)calloc((tam),sizeof(double));

	for(i=0;i<tam;i++){
		v2[i] = v[i];
	}

	do{
		autovalor = autovalor2;
		for(i=0;i<tam;i++){
			v1[i] = v2[i];
		}
		for(i=0;i<tam;i++){
			autovetor[i] = v1[i]/raizEuclidiana(v1, tam);
		}
		for(i=0;i<tam;i++){
			v2[i] = multMatrizVetor(a, autovetor, tam, tam, tam)[i];
		}
		autovalor2 = produtoEscalar(autovetor, v2, tam);

	}while(fabs((autovalor2 - autovalor)/autovalor2) > e);
	
	cout<<"Autovalor: "<<autovalor2<<endl;
	cout<<"Autovetor: |";
	for(i=0;i<tam;i++){
		cout<<autovetor[i]<<" ";
	}
	cout<<"|"<<endl;
}

int main(int narg, char *argv[]){
	int tam,i,j;
	double elem, e;
	double **a;
	double *v;
	ofstream file;
	
	file.open("resultados.txt");
	
	cout<<"Entre com um tamanho para a matriz e o vetor:"<<endl;
	cin>>tam;
	
	v = (double*)calloc((tam),sizeof(double));
	a = (double**)calloc((tam),sizeof(double*));
	for(i=0; i<tam; i++){
		a[i] = (double*)calloc((tam),sizeof(double));
	}
	cout<<"Entre com os elementos do vetor:"<<endl;
	
	for(i=0;i<tam;i++){
		cout<<"Entre com o elemento v["<<i<<"]"<<endl;
		cin>>elem;
		v[i] = elem;
	}
	
	file<<"O vetor é [";
	cout<<"O vetor é [";
	for(i=0;i<tam;i++){
		cout<<v[i]<<" ";
		file<<v[i]<<" ";
	}
	cout<<"]"<<endl;
	file<<"]"<<endl;
	
	cout<<"Entre com os elementos da matriz"<<endl;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			cout<<"Entre com o elemento a["<<i<<","<<j<<"]"<<endl;
			cin>>elem;
			a[i][j] = elem;
		}
	}
	cout<<"A matriz é: "<<endl;
	file<<"A matriz é: "<<endl;
	for(i=0;i<tam;i++){
		cout<<"|";
		file<<"|";
		for(j=0;j<tam;j++){
			cout<<a[i][j]<<" ";
			file<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
		file<<"|"<<endl;
	}
	
	cout<<"Entre com a tolerancia"<<endl;
	cin>>e;
	file<<"A tolerância é "<<e<<endl;
	metodoPotencia(a, v, e, tam);
	
	file<<"Autovalor: "<<autovalor2<<endl;
	file<<"Autovetor: |";
	for(i=0;i<tam;i++){
		file<<autovetor[i]<<" ";
	}
	file<<"|"<<endl;
	
	file.close();
	
	cout<<"Resultado armazenado no arquivo 'resultados.txt'"<<endl;
	
	return 0;
}

