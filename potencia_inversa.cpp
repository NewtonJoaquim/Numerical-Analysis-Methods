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

double** calcular_inversa(double **matriz,int n){
    double **inversa;
    int i, j, w;
    double pivo, op;
 
    inversa = (double**)malloc(n*sizeof(double*));
 
    for(i=0;i<n;i++)
        inversa[i] = (double*)calloc(n,sizeof(double));
 
    for(i=0;i<n;i++)
        inversa[i][i] = 1;
 
    for (i=0;i<n;i++){//i linha atual, j coluna
        pivo = matriz[i][i];
        if(pivo != 1){
            for(j=0;j<n;j++){
                matriz[i][j] = matriz[i][j]/pivo;
                inversa[i][j] = inversa[i][j]/pivo;
            }
        }
         
        //w irá percorrer as linhas
        for(w=0;w<n;w++){
            if(w != i){
                op = matriz[w][i]; //i como linha
                for(j=0;j<n;j++){
                     
                    matriz[w][j] = matriz[w][j]-(op*(matriz[i][j]));
                    inversa[w][j] = inversa[w][j]-(op*(inversa[i][j]));
                     
                }
            }
        }
    }
                     
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout << "Elemento " << i << " " << j << " " << inversa[i][j] << endl;
    }*/
    return inversa;
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

void metodoPotenciaInversa(double **a, double *v, double e, int tam){
	int i;
	double *v1, *v2/*, *autovetor*/;
	double **inversa;
	//double autovalor2 = 0;
	double autovalor;
	
	v1 = (double*)calloc((tam),sizeof(double));	
	v2 = (double*)calloc((tam),sizeof(double));
	autovetor = (double*)calloc((tam),sizeof(double));
	inversa = (double**)calloc((tam),sizeof(double));
	for(i=0;i<tam;i++){
		inversa[i] =( double*)calloc((tam),sizeof(double));
	}
	inversa = calcular_inversa(a, tam);

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
			v2[i] = multMatrizVetor(inversa, autovetor, tam, tam, tam)[i];
		}
		autovalor2 = produtoEscalar(autovetor, v2, tam);

	}while(fabs((autovalor2 - autovalor)/autovalor2) > e);
	
	cout<<"A matriz é: "<<endl;
    for(i=0;i<tam;i++){
        cout<<"|";
        for(int j=0;j<tam;j++){
            cout<<inversa[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }

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
	//vector<vector<double> > a;
	double *v;
	ifstream readfile;
	ofstream file;
	
	readfile.open("matrixfile.txt");
	file.open("resultados.txt");
	
	readfile >> tam;
	//cout<<tam<<endl;
	v = (double*)calloc((tam),sizeof(double));
	a = (double**)malloc((tam)*sizeof(double*));
	for(i=0; i< tam;i++){
		a[i] = (double*)malloc((tam)*sizeof(double));
		for(j=0; j<tam; j++){
			readfile >> a[i][j];
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
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
	cout<<"Entre com a tolerancia"<<endl;
	cin>>e;
	file<<"A tolerância é "<<e<<endl;
	metodoPotenciaInversa(a, v, e, tam);
	
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

