#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<limits>
#include<cmath>
#include<fstream>
using namespace std;
double norma (double *vk,int t){
        double norma=0;
        double *fik = new double[t];
                for(int i=0;i<t;i++){
                        norma = norma + pow(vk[i],2);
                }
                norma = sqrt(norma);
       return norma;         
}
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

double* normalizarVetor(double *v, int tam){
	double *v_normalizado;
	double n_v;
	
	n_v = norma(v, tam);
	
	v_normalizado = (double*)calloc((tam),sizeof(double));
	
	for(int i =0; i<tam;i++){
		v_normalizado[i] = (v[i]/n_v);
	}
	
	return v_normalizado;

}

double** multVetorT(double *m1, int tam){

    int j, w;
    double **m3;

    m3 = (double**)malloc((tam)*sizeof(double*));

    for(int i=0;i<tam;i++)
        m3[i] = (double*)calloc((tam),sizeof(double));


    for(w=0;w<tam;w++){
        for(j=0;j<tam;j++){
            m3[w][j] += (m1[w])*(m1[j]);
        }
    }

    return m3;
}

double** multMatrizEscalar(double **m1, double esc, int tam1i, int tam1j){

    double **m2;

    m2 = (double**)calloc((tam1j),sizeof(double));

	for(int i=0;i<tam1j;i++)
        m2[i] = (double*)calloc((tam1j),sizeof(double));

    for(int w=0;w<tam1i;w++){
		for(int i=0;i<tam1j;i++){
				m2[w][i] = m1[w][i]*esc;
		}
	}
	

	return m2;
}
				
double* MMatrizVetor(double **A,double *v,int t){
        double *R = new double[t];
        int i,j;
                for(i=0;i<t;i++){
                        for(j=0;j<t;j++){
                                R[i] = R[i]+A[i][j]*v[i];
                        }
                }
        return R;
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

double** subMatriz(double **m1, double **m2, int tam){

    double **m3;

    m3 = (double**)malloc((tam)*sizeof(double*));

	for(int i=0;i<tam;i++)
        m3[i] = (double*)calloc((tam),sizeof(double));

	for(int w=0;w<tam;w++){
		for(int i=0;i<tam;i++) {
			m3[w][i] = (m1[w][i])-(m2[w][i]);
		}
	}
	return m3;
}

double MVetores(double *v,double *v1,int t){
        double R=0;
        int i;
        for(i=0;i<=t;i++){
                R = R + v[i]*v1[i];
        }
        return R;
}
double* multVetorEscalar(double *m1, double esc, int tam){
	int w;
    double *m2;
    m2 = (double*)calloc((tam),sizeof(double));
	for(w=0;w<tam;w++){
				m2[w]= m1[w]*esc;
		}
		return m2;	
	}
/*double* calc_colh(double **A,int h,int tam){
	double *colh;
	colh = (double*)calloc((tam-h),sizeof(double*));
	for(int i=0;i<tam-h;i++){
		colh[i] = A[h+1][h-1];
	}	
	return colh;
}*/

double* calc_colh(double **A, int h, int tam){
	double* colh;
	colh = (double*)calloc((tam),sizeof(double*));
	for(int i=0;i<tam;i++){
		colh[i] = A[i][h];
	}
	return colh;
}				
double** HouseHolder(double **A,int h,int tam){
	int i;
	double cv, cn;
	double *v,*N,*n_chapeu,*n, *auxv;
	double **Q, **I, **aux;
	auxv = calc_colh(A, h, tam);
	v = (double*)calloc((tam),sizeof(double*));
	for(i = h+1;i<tam;i++){
		v[i] = auxv[i];
	}
	cv = norma(v,tam);
	N = v;
	if(N[h+1]>0)
		N[h+1] = N[h+1] + cv;
	else
		N[h+1] = N[h+1] - cv;
	cn = norma(N,tam);
	n_chapeu = normalizarVetor(N,tam);
	n = (double*)calloc((tam),sizeof(double*));
	for(i=h+1;i<tam;i++){
		n[i] = n_chapeu[i];
	}
	
	I = Identidade(tam);
    aux = multMatrizEscalar(multVetorT(n, tam), 2, tam, tam);

    Q = subMatriz(I, aux, tam);

	return Q;
}				
	
		
double** Calc_Householder(double **A,int tam){
	double** H;
	double** Abarra;
	double** Qh;
	double** Aux;
	H = Identidade(tam);
	Abarra = A;
	for(int i=0;i<=tam-2;i++){
		Qh = HouseHolder(Abarra,i,tam);
		H = multMatriz(H,Qh,tam,tam,tam,tam);
		Aux = multMatriz(Qh,Abarra,tam,tam,tam,tam);
		Abarra = multMatriz(Aux,Qh,tam,tam,tam,tam);
	}
	return Abarra;
}
int main(int argc, char *argv[])
{
	int tam,i,j;
	double elem, e;
	double **a,**O;
	double *v;
	ifstream readfile;
	ofstream file;
	
	readfile.open("matrixfile.txt");
	file.open("resultados.txt");
	readfile >> tam;
	v = (double*)calloc((tam),sizeof(double));
	a = (double**)malloc((tam)*sizeof(double*));
	for(i=0; i< tam;i++){
		a[i] = (double*)malloc((tam)*sizeof(double));
		for(j=0; j<tam; j++){
			readfile >> a[i][j];
		}
	}
	O = Calc_Householder(a,tam);

	for (int i = 0; i < tam; ++i)
	{
		for (int j = 0; j < tam ; j++)
		{
			if(fabs(O[i][j])<pow(10,-15)){
				file<<"0"<<" ";
			}
			else{
				file<<O[i][j]<< " ";
			}		
		}
		file<<endl;
		
	}
	file.close();
	
	cout<<"Resultado armazenado no arquivo 'resultados.txt'"<<endl;
	
	return 0;
}
