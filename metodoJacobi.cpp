#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

double** Identidade(int tam){
	double** id;
	int i,j;
	id = (double**)calloc((tam),sizeof(double));
	for(i=0;i<tam;i++){
		id[i] = (double*)calloc((tam),sizeof(double));
	}
	
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(i==j)
				id[i][j] = 1.0;
			else
				id[i][j] = 0.0;
		}
	}
	return id;
}

double norma(double *v, int tam){
	double norma = 0;
	for(int i =0;i<tam;i++){
		norma = norma + pow(v[i], 2);
	}

	return sqrt(norma);
}

double normaColunas(double **A, int tam){
	double normaC = 0;
	for(int i=0;i<tam;i++){
			normaC = normaC + norma(A[i], tam);
	}

	return normaC;
}

double somaDiagonal(double **A, int tam){
	double soma = 0;
	for(int i=0;i<tam;i++){
		soma = soma + fabs(A[i][i]);
	}
	return soma;
}

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

double** Transposta(double** A, int tam){
	double **T;
	int i, j;
	T = (double**)calloc((tam),sizeof(double));
	for(i=0;i<tam;i++){
		T[i] = (double*)calloc((tam),sizeof(double));
	}
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			T[i][j] = A[j][i];
			//cout<<"o2k"<<endl;			
		}
	}
	
	return T;
}


double Verificar_norma(double **A,int tam){
	double norma = 0;
	for(int i=0;i<tam;i++){
		for (int j = 0; j<tam; ++j){
				if(i != j)
					norma = norma + pow(A[i][j],2);
		}
	}
	norma = sqrt(norma);
	return norma;

}

double** construir_J(double aij, double ajj, double aii, int i, int j, int tam){
  double **J = Identidade(tam);
  double theta;
  if (aij != 0)
    theta = atan(2*aij/(ajj-aii))/2;
  else
    theta = M_PI/4;
  
  J[j][j] = cos(theta);
  J[i][i] = cos(theta);
  J[i][j] = sin(theta);
  J[j][i] = -sin(theta);
      
      
  return J;    
}


  
double** Jacobi(double **A, double e, int tam){
  int i,j;
  double **Jij, **Abarra, **Jijt, **J;
  double E, aux;
 
  Abarra = (double**)calloc((tam),sizeof(double));
	for(i=0;i<tam;i++){
		Abarra[i] = (double*)calloc((tam),sizeof(double));
	}
  Abarra = A;
  J = Identidade(tam);
  do{
  	for(j=1;j<tam-1;j++){
    	for(i=j+1;i<tam;i++){
      		Jij = construir_J(A[i][j],A[j][j], A[i][i], i, j,tam);    
      		Jijt = Transposta(Jij,tam);
      		Abarra = multMatriz(Jijt,Abarra,tam,tam,tam,tam);
      		Abarra = multMatriz(Abarra,Jij,tam,tam,tam,tam);
      		J = multMatriz(Jij,J,tam,tam,tam,tam);
        }
  	}
  	aux = normaColunas(Abarra, tam);
  	cout<<"aux: "<<aux<<endl;
    E = somaDiagonal(Abarra,tam);
    cout<<"E: "<<E<<endl;
    //cout<<E<<endl;
  }while(fabs(aux-E/(aux))>e);
  return Abarra;
} 
      
int main(int narg, char *argv[]){
	
    int tam, i, j;
	double e, elem;
	double **a, **MJacobi;
	
	ifstream readfile, readfile2;
	ofstream file;

	readfile.open("matriz.txt");
	readfile2.open("tolerancefile.txt");
	file.open("resultados.txt");

	readfile>>tam;
    //cout<<"Entre com o tamanho: "<<endl;
    //cin>>tam;
  
    a = (double**)malloc((tam)*sizeof(double*));
	for(i =0; i<tam;i++){
		a[i] = (double*)malloc((tam)*sizeof(double));
		for(j =0;j<tam;j++){
      //      cout<<"Entre com o elemento a["<<i<<"]["<<j<<"]: "<<endl;
        //    cin>>elem;
          //  a[i][j] = elem;
			readfile>> a[i][j];	
		}
	}
    //cout<<"Entre com a tolerância: "<<endl;
    //cin>>e;
	readfile2>>e;
  
    MJacobi = Jacobi(a, e, tam);
    for(i=0;i<tam;i++){
      for(j=0;j<tam;j++){
      	file<< MJacobi[i][j]<<" ";
        cout<<MJacobi[i][j]<<"";
    }
    file<<endl;
    cout<<endl;  
  }
	cout<<"Resultado armazenado no arquivo resultados.txt"<<endl;
	
}      
      
      	 
