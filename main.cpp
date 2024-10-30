#include <iostream>
#include <cstdlib>
using namespace std;

void inserir(int v[], int &n, int e){
	if (40 == n){
		cout << "ERRO: Lista cheia.";
	}else{
		v[n] = e;
		n++;
	}
}

void percorrer(int v[], int n){
	for (int i = 0; i < n; i++)
		cout <<  v[i] << " ";
}

bool troca (int v[], int a, int b){
     int aux;
     aux = v[a];
     v[a] = v[b];
     v[b] = aux;
     return true;
}

int ordenaBolha(int v[], int n){
   	bool trocou = true;
	int i, fim = n-1, aux = 6;
	while (trocou){
		trocou = false;
		aux = aux + 2;
		for (i = 0; i < fim; i++){
            aux = aux + 3;
			if (v[i] > v[i+1]){
				trocou = troca(v,i,(i+1));
				aux = aux + 5;
			}
		}
		fim--;
		aux = aux + 1;
	} // fim while
	return aux;
}// fim da função

int ordenaSelecao(int v[], int n){
	int i, j, menor, aux = 4;
	for (j = 0; j < n-1; j++){
        aux = aux + 2;
		menor = j;
		aux = aux + 1;
		for (i = j+1; i < n; i++){
            aux = aux + 3;
			if (v[i] < v[menor]){
                menor = i;
			    aux = aux + 1;
            }
		}
		troca(v,j,menor);
		aux = aux + 5;
	}
	return aux;
}


int ordenaInsercao(int v[], int n){
	int i, j, aux = 3;
	for (j = 1; j < n; j++){
        aux = aux + 2;
		for (i=j; i > 0 && v[i-1]> v[i]; i--){
                   aux = aux + 4;
                   troca(v,i,(i-1));
                   aux = aux + 5;
		}
    }
    return aux;
}
// algoritmo de quicksort da wikipedia br, só fiz a tramoia de adicionar endereço de passos ali
void quicksort(int values[], int began, int end, int &passos) // mas Phillipe Wolff porque raios você só nao criou
{															// outra aux e retornou ela que nem nos meus codigos?
	int i, j, pivo, aux;									// Rodrigo eu não entendi pq raios vc começa com aux em 3
	i = began;												// ou em 4 ou soma 5, soma 4 literalmente eu nao entendi
	j = end-1;												// dito isso fui pelo meio uga-buga #paz
	pivo = values[(began + end) / 2];

	while(i <= j)
	{
		while(values[i] < pivo && i < end)
		{
			i++;
			passos++;
		}
		while(values[j] > pivo && j > began)
		{
			j--;
			passos++;
		}
		if(i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
			passos++;
		}
	}

	if(j > began)
		quicksort(values, began, j + 1, passos);
	if(i < end)
		quicksort(values, i, end, passos);
}

// Prog. Principal
int main(){
	int v[40], tam = 0, i, temp, temp2=0;
    int v2[40], tam2 = 0;
    int v3[40], tam3 = 0;
	// vetorzinho do merge sort
	int v4[40], tam4 = 0;
	int passos = 0;
    cout << "\nRotina de leitura da colecao:\n\n";
   	for (i = 0; i < 10; i++){
		cout << "Digite um numero: ";
		cin >> temp;
		inserir(v, tam, temp);
		inserir(v2, tam2, temp);
		inserir(v3, tam3, temp);
   		inserir(v4, tam4, temp);
	}
	cout << "\n\n I N S E R T   S O R T";
	cout << "\n Imprimindo antes de ordenar C1: ";
	percorrer(v,tam);
	temp = ordenaInsercao(v,tam);
	cout << "\n Imprimindo depois de ordenar C1: ";
	percorrer(v,tam);
	cout << "\n Precisei de " << temp << " operacoes para ordenar...\n\n"; //nos blocos que tem esse print eu corrigi oredenar por ordenar tbm

	cout << "\n\n S E L E C T   S O R T";
	cout << "\n Imprimindo antes de ordenar C2: ";
	percorrer(v2,tam2);
	temp = ordenaSelecao(v2,tam2);
	cout << "\n Imprimindo depois de ordenar C2: ";
	percorrer(v2,tam2);
	cout << "\n Precisei de " << temp << " operacoes para ordenar...\n\n";

	// rodrigo tu escreveu buble sort em vez de bubBle, dai eu consertei e é isso ai mesmo
	cout << "\n\n B U B B L E   S O R T";
	cout << "\n Imprimindo antes de ordenar C3: ";
	percorrer(v3,tam3);
	temp2 = ordenaBolha(v3,tam3);
	cout << "\n Imprimindo depois de ordenar C3: ";
	percorrer(v3,tam3);
	cout << "\n Precisei de " << temp2 << " operacoes para ordenar...\n\n";

	cout << "\n\n Q U I C K   S O R T";
	cout << "\n Imprimindo antes de ordenar C4: ";
	percorrer(v4,tam4);
	quicksort(v4,0,10,passos);
	cout << "\n Imprimindo depois de ordenar C4: ";
	percorrer(v4,tam4);
	cout << "\n Precisei de " << passos << " operacoes para ordenar...\n\n";

	system("pause");
	return 0;
}