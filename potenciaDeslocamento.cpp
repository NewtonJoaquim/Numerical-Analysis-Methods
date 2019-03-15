#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<iostream>
using namespace std;

double autovalor2 = 0;
double *autovetor;

double* autovalores;
double** autovetores;

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

double** multMatrizEscalar(double **m1, double esc, int tam1i, int tam1j){

	int i, j, w;
    double **m2;

    m2 = (double**)calloc((tam1j),sizeof(double));

	for(i=0;i<tam1j;i++)
        m2[i] = (double*)calloc((tam1j),sizeof(double));

	for(w=0;w<tam1j;w++){
		for(i=0;i<tam1j;i++){
				m2[w][i] = m1[w][i]*esc;
		}
	}
	

	return m2;
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

	int i, j, w;
    double **m3;

    m3 = (double**)malloc((tam)*sizeof(double*));


	for(i=0;i<tam;i++)
        m3[i] = (double*)calloc((tam),sizeof(double));


		for(w=0;w<tam;w++){
			for(i=0;i<tam;i++) {
				m3[w][i] = (m1[w][i])-(m2[w][i]);
				//cout<<m3[w][i]<<" ";
			}
			//cout<<endl;
		}
	return m3;
}


double* gerschgorin(double **a, int tam){
	double *discos;
	double soma = 0;
	
	discos = (double*)calloc((tam),sizeof(double));
	
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			if(i != j){
				soma = soma + fabs(a[i][j]);
			}
		}
		discos[i] = soma;
		soma = 0;
	}
	
	return discos;
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

double** calcular_inversa(double **matrizG,int n){
    double **inversa, matriz[n][n];
    int i, j, w;
    double pivo, op;
  
    inversa = (double**)malloc(n*sizeof(double*));
  
  	for(i=0;i<n;i++){
  		for(j=0;j<n;j++){
  			matriz[i][j] = matrizG[i][j];
  		}
  	}
  
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

double* metodoPotenciaInversa(double **a, double *v, double e, int tam){
	int i;
	double *v1, *v2/*, *autovetor*/;
	double **inversa;
	double *auto_vetor;
	//double autovalor2 = 0;
	double autovalor;
	
	v1 = (double*)calloc((tam),sizeof(double));	
	v2 = (double*)calloc((tam),sizeof(double));
	auto_vetor = (double*)calloc((tam),sizeof(double));
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
			auto_vetor[i] = v1[i]/raizEuclidiana(v1, tam);
		}
		for(i=0;i<tam;i++){
			v2[i] = multMatrizVetor(inversa, auto_vetor, tam, tam, tam)[i];
		}
		autovalor2 = produtoEscalar(auto_vetor, v2, tam);

	}while(fabs((autovalor2 - autovalor)/autovalor2) > e);
	
	return auto_vetor;
/*	cout<<"A matriz é: "<<endl;
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
	cout<<"|"<<endl; */
}

/*void metodoPotenciaDeslocamento(double **a, double *v, double e, int tam){
	double menor_raio, maior_raio, deltaX;
	double *discos, *mi;
	int intervalos = 1000;
	int i, j;

	discos = gerschgorin(a, tam);
	
	menor_raio = discos[0];
	maior_raio = discos[0];

	mi = (double*)calloc((tam),sizeof(double));
	autovalores = (double*)calloc((tam),sizeof(double));
	autovetores = (double**)calloc((tam),sizeof(double));	

	for(i=1;i<tam;i++){
		if (discos[i]<menor_raio)
			menor_raio = discos[i];
		else if(discos[i]>maior_raio)
			maior_raio = discos[i];
	}
	cout<<"maior raio: "<<maior_raio<<endl;
	cout<<"menor raio: "<<menor_raio<<endl;

	deltaX = (maior_raio-menor_raio)/intervalos;
	
	for (i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			mi[j] = v[j]+(250*deltaX);
		}
		autovetores[i] = metodoPotenciaInversa(a, mi, e, tam);
		autovalores[i] = autovalor2;
	}	

}
*/
void potenciaDeslocamento(double **a, double *v, double e, int tam){
	double h, chute;
	double *mi;
	double **a2;
	double **mult;
	double maior_mi, menor_mi;
	int i;
	mi = (double*)calloc((tam),sizeof(double));
	//a2 = (double**)calloc((tam),sizeof(double));
	
	autovalores = (double*)calloc((2*tam),sizeof(double));
	autovetores = (double**)calloc((2*tam),sizeof(double));	
	
	/*for(i=0;i<tam;i++){
		a2[i] =( double*)calloc((tam),sizeof(double));
	}*/
	
	mi = gerschgorin(a, tam);

	maior_mi = menor_mi = mi[0];
	
	for(i=1;i<tam;i++){
		if(mi[i] > maior_mi)
			maior_mi = mi[i];
		else if(mi[i]<menor_mi)
			menor_mi = mi[i];
	}
		//cout<<maior_mi<<"---"<<menor_mi<<endl;
	
	h = fabs(maior_mi-menor_mi)/(2*tam);
	
///////////////////////////////////////////////////////////	
	mult = (double**)calloc((tam),sizeof(double));
	for(i=0;i<tam;i++){
		mult[i]= (double*)calloc((tam),sizeof(double));
	}
	mult = multMatrizEscalar(Identidade(tam), mi[0], tam, tam);
	/*for(i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			cout<<mult[i][j]<<" ";
		}
		cout<<endl;
	}*/
/////////////////////////////////////////////////////////////////////////////	
	//a2 = subMatriz(a, multMatrizEscalar(Identidade(tam), 8, tam ,tam), tam);
	
	
	for(i=0;i<2*tam;i++){
		chute = menor_mi + (i*h);
		mult = multMatrizEscalar(Identidade(tam), chute+0.67, tam, tam);
		
		a2 = subMatriz(a, mult, tam);
	
		autovetores[i] = metodoPotenciaInversa(a2, mi, e, tam);
		autovalores[i] = autovalor2 + chute;
	}
	
	/*for(i=0;i<tam;i++){
		for(int j = 0;j<tam;j++){
			cout<<a2[i][j]<< " ";
		}
		cout<<endl;
	}*/
}

int main(int narg, char *argv[]){
	int tam,i,j;
	double elem, e;
	double **a;
	//vector<vector<double> > a;
	double *v;
	ifstream readfile, readfile2, readfile3;
	ofstream file;
	
	readfile.open("matrixfile.txt");
	readfile2.open("vectorfile.txt");
	readfile3.open("tolerancefile.txt");
	file.open("resultados.txt");
	
	readfile >> tam;
	//cout<<tam<<endl;
	//cout<<tam<<endl;
	autovetor = (double*)calloc((tam),sizeof(double));
	v = (double*)calloc((tam),sizeof(double));
	a = (double**)malloc((tam)*sizeof(double*));
	for(i=0; i< tam;i++){
		readfile2 >> v[i];
		a[i] = (double*)malloc((tam)*sizeof(double));
		for(j=0; j<tam; j++){
			readfile >> a[i][j];
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}
	readfile3 >> e;
	/*cout<<"Entre com um tamanho para a matriz e o vetor:"<<endl;
	cin>>tam;
	
	v = (double*)calloc((tam),sizeof(double));
	a = (double**)calloc((tam),sizeof(double*));
	for(i=0; i<tam; i++){
		a[i] = (double*)calloc((tam),sizeof(double));
	}*/
	/*cout<<"Entre com os elementos do vetor:"<<endl;
	
	for(i=0;i<tam;i++){
		cout<<"Entre com o elemento v["<<i<<"]"<<endl;
		cin>>elem;
		v[i] = elem;
	}*/
	
	file<<"O vetor é [";
	cout<<"O vetor é [";
	for(i=0;i<tam;i++){
		cout<<v[i]<<" ";
		file<<v[i]<<" ";
	}
	cout<<"]"<<endl;
	file<<"]"<<endl;
	/*
	cout<<"Entre com os elementos da matriz"<<endl;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			cout<<"Entre com o elemento a["<<i<<","<<j<<"]"<<endl;
			cin>>elem;
			a[i][j] = elem;
		}
	}*/
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
	
	/*cout<<"Entre com a tolerancia"<<endl;
	cin>>e;*/
	file<<"A tolerância é "<<e<<endl;
	//metodoPotenciaDeslocamento(a, v, e, tam);
	potenciaDeslocamento(a, v, e, tam);
	
	file<<"Autovalores: "<<endl;
	for(i=0;i<2*tam;i++){
		file<<autovalores[i]<<endl;	
	}
	file<<"Autovetores: "<<endl;
	for(i=0;i<2*tam;i++){
		file<<"|";
		for(j=0;j<tam;j++){
			file<<autovetores[i][j]<<" ";
		}
		file<<"|"<<endl;
	}
	
	file.close();
	
	cout<<"Resultado armazenado no arquivo 'resultados.txt'"<<endl;
	
	return 0;
}

