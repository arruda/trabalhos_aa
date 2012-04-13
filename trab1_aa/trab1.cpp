// Trabalho 1 de AA 2012.1
// Alunos: Felipe Arruda Pontes e Hiran Tassinari
// 
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>

using namespace std;

//verifica se é negativo
bool is_negativo(string *str){
	return (*str)[0] == '-';
}

//regula o tamanho da string para ser almentado em incremento,
//se for negativo preserva o sinal no lugar de um incremento
void regular_string(string *str, int incremento){
	bool negativo = is_negativo(str);
	if(negativo){
		(*str)[0] = '0';
		incremento--;
	}
	for (int i=0;i< incremento;i++){
		*str = "0"+ (*str);
	}
	if(negativo){
		(*str)[0] = '-';
	}

}

// Voce deve escrever essa funcao!
string soma(string a, string b) {
	bool negativo = false;

	int regulador = 0;
	regulador = a.length() - b.length();
	//se a ou b são negativos
	bool a_negativo = is_negativo(&a);
	bool b_negativo = is_negativo(&b);

	//regula o tamanho das strings a e b
	if(regulador < 0){
		regular_string(&a,regulador*-1);
	}
	else if(regulador > 0){
		regular_string(&b,regulador);
	}

	bool vaium=false;

	cout << "soma:>>> " << a << " + " << b << endl;
	string res = "";
	int i=a.length();
	for(i=a.length();i!=0;i--){
		int pos = i-1;
		int res_a=0;
		int res_b=0;

		//se um dos dois for '-' não faz o passo normal, pois é o ultimo passo
		if(a[pos]!='-' || b[pos]!='-'){
			res_a=(a[pos]-'0');
			if(a_negativo && b_negativo)
				res = "0"+res;
			else
				res= "-"+res;
			break;
		}

		int res_int = res_a+res_b;
//		cout << "a[i-1]:" << a[i-1] << " b[i-1] :" << b[i-1] <<endl;
//		cout << "resint-" << i << ">>> " << res_int <<endl;
		//verifica vai um anterior
		if(vaium){
			if(negativo && ){
				res_int--;
			}
			res_int+=1;
		}
		vaium=false;

		//verifica se vai um para o proximo
		if(res_int > 9){
			res_int = res_int - 10;
			vaium=true;
		}
		stringstream ss;
		ss << res_int;
		res=ss.str()+res;
//		cout << "res-" << i << ">>> " << res <<endl;
	}
	if(vaium){
		res="1"+res;
	}
	cout << ">>> " << res<<endl;
    return res;
}

// Voce deve escrever essa funcao!
string mul_lento(string a, string b) {
    return string("4");
}

// Voce deve escrever essa funcao!
string mul_rapido(string a, string b) {
    return string("4");
}


// Nao modifique nada daqui para baixo!
float nota = 0;

void testa_soma() {
    cout << "Testando soma. Quatro testes valendo 0.5 cada." << endl;
    
    if(soma("4","4") == "4") {
        nota += .5;
        cout << " Passou no teste 1 de soma." << endl;
    }
    if(soma("151115727451828646838272",
         "174449211009120179071170507") ==
         "174600326736572007718008779") {
        nota += .5;
        cout << " Passou no teste 2 de soma." << endl;
    }
    if(soma("-90","17") == "-73") {
        nota += .5;
        cout << " Passou no teste 3 de soma." << endl;
    }
    if(soma("1341068619663964900807",
             "-984770902183611232881") ==
             "356297717480353667926") {
        nota += .5;
        cout << " Passou no teste 4 de soma." << endl;
    }
}

void testa_mul_lento() {
    cout << "Testando multiplicacao quadratica. Cinco testes valendo 0.5 cada." << endl;
    
    ifstream f("teste-trab1.txt");
    string a, b, ab;
    int n;
    clock_t t;
    
    for(int i=1; i<=5; i++) {
        f >> a;
        f >> b;
        f >> ab;
        n = ab.length();
        t = clock();
 
        if(mul_lento(a, b) == ab) {
            nota += .5;

            cout << " Passou no teste "<< i << " de mul_lento (" << n << " algarismos) em "
                << (float)(clock() - t) / CLOCKS_PER_SEC
                << " segundos." << endl;
        }
    }
}

void testa_mul_rapido() {
    cout << "Testando multiplicacao sub-quadratica. Onze testes valendo 0.5 cada." << endl;
    
    ifstream f("teste-trab1.txt");
    string a, b, ab;
    int n;
    clock_t t;
    
    for(int i=1; i<=11; i++) {
        f >> a;
        f >> b;
        f >> ab;
        n = ab.length();
        t = clock();
 
        if(mul_rapido(a, b) == ab) {
            nota += .5;

            cout << " Passou no teste "<< i << " de mul_rapido (" << n << " algarismos) em "
                << (float)(clock() - t) / CLOCKS_PER_SEC
                << " segundos." << endl;
        }
    }
}

int main() {
    testa_soma();
    testa_mul_lento();
    testa_mul_rapido();
    
    cout << "Nota total: " << nota << endl;
    return 0;
}
