#include <iostream>
#include "calcu-obj_n_fct.h"

using namespace std;

int main()
{
	cout << verde << "Caluculator" << limpar << endl;

	char snal; //variavel que define a operacao que sera executada
	cout << magenta << "Select the signal of operation to be carried out: " << endl;
	cout << ciano << "'Sum (+)' 'Subtraction (-)' 'Multiplication (.)' 'Division (/)'" << amarelo << endl;
 	cout << ciano << " 'X² (!)' '√X (*)' 'Y% of X (%)' 'X up to Y'(&) " << amarelo << endl;

 	int validate = 0; //variavel para validadar se uma opcao digitada foi aceita ou nao
	float A, B; //variveis para executar as operacoes

	do { //essa linha inicia uma expecie de ~filtro~ da entrada
		validate = 0; //inicia a variavel de validacao (+1 se for permitida e -1 caso contrario)
		cin >> snal; //recebe a ordem da operacao a ser efetuada (filtrada por >do{ }while<)

		switch (snal) //separa os blocos de operacao
        {
            case '+': //soma
            {
                cout << magenta << "Type the first number: " << amarelo;
                cin >> A;
                cout << magenta << "Type the second number: " << amarelo;
                cin >> B;

                basics::Soma conta(A, B); //Vai na função "basics" e chama a classe "Soma" para criar o objeto "conta()"
                cout << ciano << ">The results is: " << limpar << conta.somar() << endl; //exibe o resultado da função "somar" atribuida a variavel "conta"

                validate++;
            break;
            }

			case '-': //subtracao
            {
                cout << magenta << "Type the first number: " << amarelo;
                cin >> A;
                cout << magenta << "Type the second number: " << amarelo;
                cin >> B;

                basics::Subtracao reduzir(A, B);
                cout << ciano << ">The results is: " << limpar << reduzir.subtrair() << endl;
                validate++;
            break;
            }

			case '.': //multiplicacao
            {
				cout << magenta << "Type the first number: " << amarelo;
                cin >> A;
                cout << magenta << "Type the second number: " << amarelo;
                cin >> B;

                basics::Multiplicacao produto(A, B);
                cout << ciano << ">The results is: " << limpar << produto.multiplicar() << endl;
                validate++;
			break;
            }

			case '/': //divisao
            {
                do { //>do{ }while< para nao permitir divisao por 0
                    cout << magenta << "Type the first number: " << amarelo;
                    cin >> A;
                    cout << magenta << "Type the second number: " << amarelo;
                    cin >> B;
                    if (A == 0 || B == 0)
                    {
                        cout << vermelho << "Is not possible to divide by 0" << endl;
                    }
				} while (A == 0 || B == 0);

				basics::Divisao dividir(A, B);
				cout << ciano << ">The results is: " << limpar << dividir.quociente() << endl;
				validate++;
			break;
            }

			case '!': //elvar ao quadrado
            {
				cout << magenta << "Type a number to be squared: " << amarelo;
				cin >> A;

				extraz::Potencia quadrado(A);
				cout << ciano << ">The square of " << A << " is: " << limpar << quadrado.ente() << endl;
				validate++;
			break;
            }

			case '*': //radiciacao
				do {
					cout << magenta << "Type a number: " << amarelo;
					cin >> A;

					if (A < 0)
                    {
                        cout << vermelho << "for negatives numbers, doens't exists real roots" << limpar << endl;
                    }
                    else
                    {
                        cout << ciano << "√" << A << " = " << limpar << extraz::root_sqr(A) << endl;

                        validate++;
                    }
				} while (A < 0);
			break;

            case '%': //porcentagem
            {
                cout << magenta << "Type the pourcentage of number: " << amarelo;
                cin >> A;

                cout << magenta << "Type the number: " << amarelo;
                cin >> B;
                extraz::Porcentagem luby(A, B); // cria um objeto
                cout << ciano << ">" << A << "% of " << B << " is "<< limpar << luby.calcular() << endl; // executa o objeto criado

                validate++;
            break;
            }

            case '&':
            {
                cout << magenta << "The number: " << amarelo;
                cin >> A;

                cout << magenta << "When upped to: " << amarelo;
                cin >> B;

                extraz::Elevar expo(A, B);
                cout << ciano << "\nresults in: " << limpar << expo.elevate() << endl;
                validate++;
            break;
            }

            default: //bloco que recebe quais quiser entradas nao aceitas
                cout << vermelho << "Select a valid option" << amarelo << endl;

				validate--; // ln20, essa variavel esta ao final de cada bloco bem antes de um >break;<
            break;              // essa e a  unica vez em que ela é operada por ]--[, nas outras ela usa ]++[.
		}

	} while (validate != 1); //reinicia a filtragem caso $validate = -1 (ln102) ou encerra o programa caso $validate = 1

	return 0;
}
