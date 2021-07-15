#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <fstream> 
#include<cstring> 
#include <windows.h>
using namespace std;

//cono o programa s� ficou com a struct e somente com uma fun��o, n�o criei o arquivo .h e nem o arquivo para as fun��es

struct baralho
{
	char nome[30];             // nome do jogador
	int velocidade;           // velocidade do jogador
	int finaliza��o;         // finaliza��o do jogador 
	int passe;              // passe do jogador 
	int drible;            // drible do jogador 
	int fisico;           // fisico do jogador 
};

// fun��o que mostra o menu do jogo
void menu();

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	baralho VetorBaralho[32];

	/*
	O arquivo bin�rio deve iniciar com um cabe�alho de 72bits, sendo 56 bits formados
	  pelos caracteres BARALHO e os 16 bits seguintes sendo um valor unsigned short com a
	  quantidade de cartas armazenadas no arquivo. Na hora de ler o arquivo, o programa
	  deve verificar se o arquivo cont�m a palavra BARALHO nos 56 bits iniciais, e usar o valor
	  da quantidade de cartas armazenadas para simplificar a leitura do arquivo
	*/

	char cabecalho[] = "BARALHO"; // cabe�alho que vai servir de teste no jogo
	unsigned short TotalDeCartas = 0;
	int contador = 0; 
	int importador = 0;  
	
	/*
	O vetor deve ser preenchido com as cartas vindas de um arquivo bin�rio toda vez que o
		usu�rio entrar no gerador.
		O conte�do v�lido do vetor deve ser gravado no mesmo
		arquivo bin�rio toda vez que o usu�rio sair do gerador
	*/

	ifstream fin;
	cout << "Lendo do bin�rio" << endl;

	fin.open("../baralho.dat", ios_base::binary);

	if (!fin.is_open())     //se o arquivo nao foi aberto
	{
		cout << "Arquivo nao existente" << endl;

		// caso n�o exista => criando um novo 
		ofstream fout;

		cout << "Criando arquivo" << endl;
		fout.open("../baralho.dat", ios_base::binary, ios_base::trunc);

		if (!fout.is_open()) //se deu erro 
		{
			cout << "Arquivo nao foi criado";
		}
		else
		{
			 fout.write((char*)"BARALHO", 7); //escrevendo o nome BARALHO nos 7 primeiros b
			 fout.write((char*)&TotalDeCartas, 2);
			cout << "Arquivo criado com suecesso. " << endl;
		}
		fout.close();
	}
	else     //caso j� exista o arquivo
	{
		fin.read((char*)cabecalho, 7); // ver se tem o cabe�alho
		if (!strcmp(cabecalho, "BARALHO")) //compara se o cabe�alho � igual a BARALHO
		{
			fin.read((char*)&TotalDeCartas, 2);  // recebbe o n�mero de cartas
			for (int i = 0; i < TotalDeCartas; i++)
			{
				fin.read((char*)&VetorBaralho[i], sizeof(baralho));  // passando do arquivo para o vetor 
			}
			cout << "Arquivo lido para o vetor." << endl;
		}
		else
		{
			cout << "Erro ao ler do arquivo";
		}
	}
	fin.close();

	

	menu();   // menu das escolhas

	char escolha;
	cin >> escolha;


	while (escolha != 's' && escolha != 'S') // enquanto escolha diferente de sair
	{
		switch (escolha)
		{
		case 'c': // caso cadastrar
		case 'C':

			cout << "Cadastrar carta" << endl;
			cout << "---------------" << endl;
			cout << "Nome:\t";
			cin.ignore();
			if (TotalDeCartas != 0)  
			{
				cin >> VetorBaralho[TotalDeCartas].nome;
				cout << "Velocidade:\t";
				cin >> VetorBaralho[TotalDeCartas].velocidade;
				cout << "Finaliza��o:\t";
				cin >> VetorBaralho[TotalDeCartas].finaliza��o;
				cout << "Passe:\t";
				cin >> VetorBaralho[TotalDeCartas].passe;
				cout << "Drible:\t";
				cin >> VetorBaralho[TotalDeCartas].drible;
				cout << "Fisico:\t";
				cin >> VetorBaralho[TotalDeCartas].fisico;
				cout << endl;
				TotalDeCartas++;
			}
			else   // igual a 0 => grava na posi��o 0 e aumenta no final 
			{
				cin >> VetorBaralho[TotalDeCartas].nome;
				cout << "Velocidade:\t";
				cin >> VetorBaralho[TotalDeCartas].velocidade;
				cout << "Finaliza��o:\t";
				cin >> VetorBaralho[TotalDeCartas].finaliza��o;
				cout << "Passe:\t";
				cin >> VetorBaralho[TotalDeCartas].passe;
				cout << "Drible:\t";
				cin >> VetorBaralho[TotalDeCartas].drible;
				cout << "Fisico:\t";
				cin >> VetorBaralho[TotalDeCartas].fisico;
				cout << endl;
				TotalDeCartas++;
			}
			break;


		case 'i':  // caso importar
		case 'I':

			cout << "Importar carta" << endl;
			cout << "---------------" << endl;
			cout << "Arquivo: ";
			char nomeArquivo[35];
			cin >> nomeArquivo;

			cout << endl;
			cout << "Importando deste arquivo " << endl;
			
			fin.open(nomeArquivo,ios_base::in);
			if (!fin.is_open())      //se o arquivo nao foi aberto
			{
				cout << "Arquivo nao aberto" << endl;
			}
			
			// passando as cartas importadas para o vetorBaralho
			for (int i = TotalDeCartas; fin.good() && !fin.eof(); i++)
			{
				fin >> VetorBaralho[i].nome;
				fin >> VetorBaralho[i].velocidade;
				fin >> VetorBaralho[i].finaliza��o; 
				fin >> VetorBaralho[i].passe;
				fin >> VetorBaralho[i].drible;
				fin >> VetorBaralho[i].fisico;
				contador++; // para somar com a quantidade (caso alguma carta j� tivesse sido cadastrada)
			}
			fin.close();

			for (int i = TotalDeCartas; i < contador; i++)  // escrevendo as cartas importadas
			{
				cout << VetorBaralho[i].nome << " ";
				cout << VetorBaralho[i].velocidade << " ";
				cout << VetorBaralho[i].finaliza��o << " ";
				cout << VetorBaralho[i].passe << " ";
				cout << VetorBaralho[i].drible << " ";
				cout << VetorBaralho[i].fisico << " ";
				cout << endl;
			}

			TotalDeCartas = contador + TotalDeCartas;  // o que j� tinha mais o que foi importado 
			cout << endl;
			break;

		case 'a':   // caso atualizar 
		case 'A':  

			cout << "Atualizar carta" << endl;
			cout << "---------------" << endl;

			for (int i = 0; i < TotalDeCartas; i++) {

				cout << (i + 1) << ")" << " " << VetorBaralho[i].nome << endl; // mostra a lista das cartas para o usuario escolher 
			}

			cout << endl;
			cout << "Digite o numero da carta: [ ] \b\b\b";    // escolha do usuario
			int NumeroAtualiza��o;
			cin >> NumeroAtualiza��o;

			cout << endl;
			cout << "Alterando Carta " << VetorBaralho[NumeroAtualiza��o - 1].nome << " :" << endl;  // -1 porque o primeiro na lista � igual a 1 

			// alterando a carta => lista (mostrada pro usuario) come�a com 1 e vetores come�am com 0 => por isso o -1
			cout << "Nome:\t";
			cin >> VetorBaralho[TotalDeCartas - 1].nome;
			cout << "Velocidade:\t";
			cin >> VetorBaralho[TotalDeCartas - 1].velocidade;
			cout << "Finaliza��o:\t";
			cin >> VetorBaralho[TotalDeCartas - 1].finaliza��o;
			cout << "Passe:\t";
			cin >> VetorBaralho[TotalDeCartas - 1].passe;
			cout << "Drible:\t";
			cin >> VetorBaralho[TotalDeCartas - 1].drible;
			cout << "Fisico:\t";
			cin >> VetorBaralho[TotalDeCartas - 1].fisico;
			cout << endl;
			break;


		case 'e':  // caso excluir 
		case 'E':
			cout << "Excluir Carta" << endl;
			cout << "-------------" << endl;

			for (int i = 0; i < TotalDeCartas; i++) 
			{

				cout << (i + 1) << ")" << " " << VetorBaralho[i].nome << endl; // mostra a lista das cartas para o usuario escolher 
			}

			cout << endl;
			cout << "Digite o numero da carta: [ ] \b\b\b";
			int NumApagar;
			cin >> NumApagar;

			//Ex: Se o usuario apagar a 3 => passar a quarta carta para a posi��o 3 e assim por diante => trocar as outras de posi��o
			char nome[30];
			strcpy(nome, VetorBaralho[NumApagar - 1].nome); // menos um pois o vetor come�a em 0 e a contagem pro usuario come�a em 1  e -1 para diminuir o vetor
			strcpy(VetorBaralho[NumApagar - 1].nome, VetorBaralho[TotalDeCartas - 1].nome);

			VetorBaralho[NumApagar - 1].velocidade = VetorBaralho[TotalDeCartas - 1].velocidade;
			VetorBaralho[NumApagar - 1].finaliza��o = VetorBaralho[TotalDeCartas - 1].finaliza��o;
			VetorBaralho[NumApagar - 1].passe = VetorBaralho[TotalDeCartas - 1].passe;
			VetorBaralho[NumApagar - 1].drible = VetorBaralho[TotalDeCartas - 1].drible;
			VetorBaralho[NumApagar - 1].fisico = VetorBaralho[TotalDeCartas - 1].fisico;
			TotalDeCartas--;

			cout << "Carta " << nome << " foi excluida do baralho." << endl;
			cout << endl;
			break;

		case 'l':  // caso listar 
		case 'L':

			cout << "Cartas no Baralho" << endl;
			cout << "-----------------" << endl;

			for (int i = 0; i < TotalDeCartas; i++)
			{
				cout << "#" << (i + 1) << " ";  // come�a com 1 na lista e vai mostrando todas as cartas salvas no vetor
				cout << VetorBaralho[i].nome << " ";
				cout << VetorBaralho[i].velocidade << " ";
				cout << VetorBaralho[i].finaliza��o << " ";
				cout << VetorBaralho[i].passe << " ";
				cout << VetorBaralho[i].drible << " ";
				cout << VetorBaralho[i].fisico << " ";
				cout << endl;

			}

			cout << endl;
			break;

		default:
			cout << "Est� n�o � uma op��o, esolha outra!" << endl;
			break;
		}

		menu(); // menu novamente 
		cin >> escolha;   // esolha novamente 
		cout << endl;

	}

	// fim do while => usuario digitou s ou S
	fin.close();
	cout << "Voc� saiu do gerador";
	cout << endl;


	// salvando antes de fechar o gerador 
	// para poder ser usado no Jogo.cpp
	ofstream EscreveSalvabin;	
	EscreveSalvabin.open("../baralho.dat", ios_base::binary, ios_base::trunc);
	
	if (!EscreveSalvabin.is_open())   //se deu erro
	{
		cout << "Erro ao abrir o arquivo";
	}

	else
	{
		EscreveSalvabin.write((char*)"BARALHO", 7);        // Escreve BARALHO para servir de cabe�alho
		EscreveSalvabin.write((char*)&TotalDeCartas, 2);   // Escreve o total de cartas 
		for (int i = 0; i < TotalDeCartas; i++)   
		{
			EscreveSalvabin.write((char*)&VetorBaralho[i], sizeof(baralho));  // escreve todo o vetoBaralho no arquivo binario
		}
		cout << "Baralho salvo" << endl;  // s� confirmando 
	}
	EscreveSalvabin.close();   // fecahndo a escrita para salvar

	return 0;
}

// fun��o que mostra o menu 
void menu()
{
	cout << "Gerador de Cartas" << endl;
	cout << "-----------------" << endl;
	cout << "(C)adastrar" << endl;
	cout << "(I)mportar" << endl;
	cout << "(A)lterar" << endl;
	cout << "(E)xcluir" << endl;
	cout << "(L)istar" << endl;
	cout << "(S)air" << endl;
	cout << endl;
	cout << "Escolha uma opcao [ ] \b\b\b";
}