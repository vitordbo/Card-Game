#include <iostream> 
#include <fstream> 
#include <windows.h>
#include <stdlib.h>  // numeros aleatorios
#include <ctime>
#include "Jogo.h"
using namespace std;

/* 
Aluno: V�tor Duarte Bezerra de Oliveira
Fiz um jogo de cartas com base no FIFA 21, no modo Ultimate team (modo de jogo mais popular, o jogo depende de cartas, que podem ser ganhadas em packs
ou compradas com moedas), as cartas s�o feitas com base em eventos especiais ou em uma boa atua��o do jogador especifico. Escolhi algumas cartas (minhas favoritas)
e coloquei no meu jogo ( no FIFA temos 6 atributos gerais => velocidade, finaliza��o, passe, drible, defesa(optei por n�o usar pois todas as cartas usadas s�o de atacantes)
e fisico.
caso queira conferir as cartas do jogo, ou at� ver o aspecto das cartas o site www.futbin.com cont�m todas as cartas do jogo
*/

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
   
	/*
    Em sua inicializa��o, o �Jogo� deve ler o arquivo bin�rio de dados e passar as
    informa��es para um vetor din�mico de cartas, cujo tamanho deve ser igual a
    quantidade de cartas armazenadas no arquivo. Uma vez lido, o arquivo deve ser fechado
    antes de iniciar a partida. O arquivo n�o deve ser alterado pelo Jogo
   */

	fstream fin;
	char cabecalho[] = "BARALHO";
	unsigned short QuantCartas = 0;

	// lendo informa��es do arquivo baralho.dat 
	fin.open("../baralho.dat", ios_base::in | ios_base::binary);
	fin.read((char*)&cabecalho, sizeof(char) * 7);    // lendo cabe�alho
	fin.read((char*)&QuantCartas,sizeof(unsigned short));   // lendo quantidade de cartas

	// criando vetor din�mico 
	baralho* VetorDinBaralho = new baralho[QuantCartas];
	
	// pontua��es dos jogadores => v�o ser criadas refer�ncias para eles na fun��o placar
	int pontua��oJog1 = 0;
	int somaPontua��oUm = 0;
	int pontua��oJog2 = 0;
	int somaPontua��oDois = 0;
	
	// variaveis que v�o ser passadas para a fun��o placar e servir�o de compara��o para o aumento do placar do jogo 
	int velocidaeJog1 = 0, finalizaJog1 = 0, passeJog1 = 0, dribleJog1 = 0, fisicoJog1 = 0;
	int velocidadeJog2=0, finalizaJog2=0, passeJog2=0, dribleJog2=0, fisicoJog2=0;

    // verificando se o arquivo abriu com sucesso 
	if (fin.is_open())     
	{
		if (strcmp(cabecalho, "BARALHO") == 0)   // se tiver o cabe�alho correto => "BARALHO"
		{
			for (int i = 0; i < QuantCartas; i++)   // copiando as cartas para o vetor din�mico de baralho (vetor que vai conter as cartas do arquivo baralho.dat)
			{
				fin.read((char*)&VetorDinBaralho[i], sizeof(baralho));
			}

		}
		else  // caso n�o encontre o cabe�alho => "BARALHO"
		{
			cout << "O arquivo n�o cont�m o cabe�alho" << endl; 
			return EXIT_FAILURE;

		}
	}
	else   // caso venha a dar algum outro tipo de erro ao ler o aqruivo baralho.dat
	{
		cout << "Erro ao ler o arquivo" << endl;
		return EXIT_FAILURE;

	}
	fin.close(); // fechando a leitura anterior

	// come�o do jogo
	int EscolhAtributo;  // atributo que o usuario vai escolher (caracteristicas da carta)

	cout << "Super Trunfo FIFA 21" << endl;
	cout << "--------------------" << endl;
	cout << "Iniciar nova partida? [S/N] ";
	char escolha; // escolha para iniciar o jogo => Sim ou N�o
	cin >> escolha;
	
	while (escolha != 'N' && escolha != 'n')  // enquanto o usuario n�o escolher N ou n (n�o)
	{
		char jogadorUm[30];    // recebe o nome do Jogador Um
		char jogadorDois[30];  // recebe o nome do Jogador Dois

		if (escolha == 's' || escolha == 'S')   // Se a escolha for para iniciar o jogo 
		{
			// recebendo nome dos jogadores da partida
			cout << "Jogador 1: ";
			cin >> jogadorUm;
			cout << "Jogador 2: ";
     		cin >> jogadorDois;
			cout << "--------------------" << endl;

		/*
		 O jogo deve inicialmente selecionar 4 cartas aleat�rias do baralho (as cartas sorteadas
		  podem ser iguais) para cada jogador e armazen�-las em dois vetores est�ticos, um para
		  cada jogador. Os vetores n�o devem guardar diretamente os dados das cartas escolhidas,
		  eles devem guardar apenas ponteiros, que devem apontar para as cartas no vetor baralho.
		*/

			baralho* CartasJogadorUm[4];
			baralho* CartasJogadorDois[4];


			// numeros aleatorios

			srand(time(NULL)); // forma explicada no lab 04 para sempre gerar n�meros difrentes 
			
			int n1Jog1, n2Jog1, n3Jog1, n4Jog1;  // numeros do jogador 1 => quatro numeros sorteados que correspondem a 4 cartas do baralho 
			
	       // limitando sorteio para n�meros menores que a quantidade total de cartas no baralho 
			n1Jog1 = rand() % QuantCartas;  
			n2Jog1 = rand() % QuantCartas;
			n3Jog1 = rand() % QuantCartas;
			n4Jog1 = rand() % QuantCartas;

			// passando as cartas (com base no n�mero sorteado) para o baralho do primeiro jogador 
			CartasJogadorUm[0] = &VetorDinBaralho[n1Jog1];
			CartasJogadorUm[1] = &VetorDinBaralho[n2Jog1];
			CartasJogadorUm[2] = &VetorDinBaralho[n3Jog1];
			CartasJogadorUm[3] = &VetorDinBaralho[n4Jog1];
			
			// jogador dois
			// numeros do jogador 2 => quatro numeros sorteados que correspondem a 4 cartas do baralho 
			int n1Jog2;
			int n2Jog2;
			int n3Jog2;
			int n4Jog2;

			// limitando sorteio para n�meros menores que a quantidade total de cartas no baralho 
			n1Jog2 = rand() % QuantCartas;
			n2Jog2 = rand() % QuantCartas;
			n3Jog2 = rand() % QuantCartas;
			n4Jog2 = rand() % QuantCartas;

			// passando as cartas (com base no n�mero sorteado) para o baralho do segundo jogador 
			CartasJogadorDois[0] = &VetorDinBaralho[n1Jog2];
			CartasJogadorDois[1] = &VetorDinBaralho[n2Jog2];
			CartasJogadorDois[2] = &VetorDinBaralho[n3Jog2];
			CartasJogadorDois[3] = &VetorDinBaralho[n4Jog2];
			
			cout << endl;

			// primeira rodada
			// fun��o que mostra o nome do jogador que est� na partida
			MostraNomeJogador(jogadorUm);
			
			// carta que foi sortedado para o primeiro jogador
			cout << CartasJogadorUm[0]->nome << " ";
			cout << endl;

			// fun��o que mostra o menu do jogo => caracteristicas a serem escolhidas para serem comparadas
		    MenuDoJogo();
			
			cin >> EscolhAtributo;  // caracteristica a ser comparada
			cout << endl;
		    
			MostraNomeJogador(jogadorUm);
			cout << CartasJogadorUm[0]->nome << " ";
			
			switch (EscolhAtributo)  // com base no atributo que o usuario escolher para comparar => vai entrar no switch e escrever esse atributo e atribuir em uma =>
			{                      // variavel que vai ser passada para a fun��o Placar e posteriormente comparada com outra a outra caracteristica para gerar o placar 
			case 1:
				cout << "| " << CartasJogadorUm[0]->velocidade << " " << endl;
				velocidaeJog1 = CartasJogadorUm[0]->velocidade;
				break;
			case 2:
				cout << "| " << CartasJogadorUm[0]->finaliza��o << " " << endl;
				finalizaJog1 = CartasJogadorUm[0]->finaliza��o;
				break;
			case 3:
				cout << "| " << CartasJogadorUm[0]->passe << " " << endl;
				passeJog1 = CartasJogadorUm[0]->passe;
				break;
			case 4:
				cout << "| " << CartasJogadorUm[0]->drible << " " << endl;
				dribleJog1 = CartasJogadorUm[0]->drible;
				break;
			case 5:
				cout << "| " << CartasJogadorUm[0]->fisico << " " << endl;
				fisicoJog1 = CartasJogadorUm[0]->fisico;
				break;

			default:
				cout << "Atributo n�o existe, escolha novamente";
				cin >> EscolhAtributo;
				break;
			}
		
			MostraNomeJogador(jogadorDois);
			cout << CartasJogadorDois[0]->nome << " ";
			
			switch (EscolhAtributo)  // com base no atributo que o usuario escolher para comparar => vai entrar no switch e escrever esse atributo e atribuir em uma =>
			{                        // variavel que vai ser passada para a fun��o Placar e posteriormente comparada com outra a outra caracteristica para gerar o placar 
			case 1:
				cout << "| " << CartasJogadorDois[0]->velocidade << " " << endl;
				velocidadeJog2 = CartasJogadorDois[0]->velocidade;
				break;
			case 2:
				cout << "| " << CartasJogadorDois[0]->finaliza��o << " " << endl;
				finalizaJog2 = CartasJogadorDois[0]->finaliza��o;
				break;
			case 3:
				cout << "| " << CartasJogadorDois[0]->passe << " " << endl;
				passeJog2 = CartasJogadorDois[0]->passe;
				break;
			case 4:
				cout << "| " << CartasJogadorDois[0]->drible << " " << endl;
				dribleJog2 = CartasJogadorDois[0]->drible;
				break;
			case 5:
				cout << "| " << CartasJogadorDois[0]->fisico << " " << endl;
				fisicoJog2 = CartasJogadorDois[0]->fisico;
				break;

			default:
				cout << "Atributo n�o existe, escolha novamente";
				cin >> EscolhAtributo;
				break;
			}
		
			cout << "Placar: " << jogadorUm;
			
			// fun��o placar => vai receber o atributo, pegar a respectiva caracteristica do jogador 1 e a respectiva caracteristica do jogador dois
			// e comparar (comparar para gerar pontua��o)  => usando referencias vai sempre manter atualizado o placar de forma correta 
			Placar(EscolhAtributo, velocidaeJog1, velocidadeJog2, finalizaJog1, finalizaJog2, passeJog1, passeJog2,
				dribleJog1, dribleJog2, fisicoJog1, fisicoJog2, pontua��oJog1, pontua��oJog2, somaPontua��oUm, somaPontua��oDois);
			
			cout << jogadorDois;
			cout << "\n---------------\n" << endl;


			//segunda rodada => (mesma base da primeira rodada) 
			MostraNomeJogador(jogadorDois);
			cout << endl << endl;
			cout << "Carta: ";
			cout << CartasJogadorDois[1]->nome << " ";
			cout << endl;

			MenuDoJogo();
			cin >> EscolhAtributo; 
			cout << endl;

			MostraNomeJogador(jogadorDois);
			cout << CartasJogadorDois[1]->nome << " ";

			switch (EscolhAtributo)   // com base no atributo que o usuario escolher para comparar => vai entrar no switch e escrever esse atributo e atribuir em uma =>
			{                        // variavel que vai ser passada para a fun��o Placar e posteriormente comparada com outra a outra caracteristica para gerar o placar       
			case 1:
				cout << "| " << CartasJogadorDois[1]->velocidade << " " << endl;
				velocidadeJog2 = CartasJogadorDois[1]->velocidade;
				break;
			case 2:
				cout << "| " << CartasJogadorDois[1]->finaliza��o << " " << endl;
				finalizaJog2 = CartasJogadorDois[1]->finaliza��o;
				break;
			case 3:
				cout << "| " << CartasJogadorDois[1]->passe << " " << endl;
				passeJog2 = CartasJogadorDois[1]->passe;
				break;
			case 4:
				cout << "| " << CartasJogadorDois[1]->drible << " " << endl;
				dribleJog2 = CartasJogadorDois[1]->drible;
				break;
			case 5:
				cout << "| " << CartasJogadorDois[1]->fisico << " " << endl;
				fisicoJog2 = CartasJogadorDois[1]->fisico;
				break;
			default:
				cout << "Atributo n�o existe, escolha novamente";
				cin >> EscolhAtributo;
				break;
			}
			
			MostraNomeJogador(jogadorUm);
			cout << CartasJogadorUm[1]->nome << " ";

			switch (EscolhAtributo)  // com base no atributo que o usuario escolher para comparar => vai entrar no switch e escrever esse atributo e atribuir em uma =>
			{                       // variavel que vai ser passada para a fun��o Placar e posteriormente comparada com outra a outra caracteristica para gerar o placar      
			case 1:
				cout << "| " << CartasJogadorUm[1]->velocidade << " " << endl;
				velocidaeJog1 = CartasJogadorUm[1]->velocidade;
				break;
			case 2:
				cout << "| " << CartasJogadorUm[1]->finaliza��o << " " << endl;
				finalizaJog1 = CartasJogadorUm[1]->finaliza��o;
				break;
			case 3:
				cout << "| " << CartasJogadorUm[1]->passe << " " << endl;
				passeJog1 = CartasJogadorUm[1]->passe;
				break;
			case 4:
				cout << "| " << CartasJogadorUm[1]->drible << " " << endl;
				dribleJog1 = CartasJogadorUm[1]->drible;
				break;
			case 5:
				cout << "| " << CartasJogadorUm[1]->fisico << " " << endl;
				fisicoJog1 = CartasJogadorUm[1]->fisico;
				break;
			default:
				cout << "Atributo n�o existe, escolha novamente";
				cin >> EscolhAtributo;
				break;
			}
			
			cout << "\nPlacar: " << jogadorUm;
	
			// fun��o placar => vai receber o atributo, pegar a respectiva caracteristica do jogador 1 e a respectiva caracteristica do jogador dois
	        // e comparar (comparar para gerar pontua��o)  => usando referencias vai sempre manter atualizado o placar de forma correta 
			Placar(EscolhAtributo, velocidaeJog1, velocidadeJog2, finalizaJog1, finalizaJog2, passeJog1, passeJog2,
				dribleJog1, dribleJog2, fisicoJog1, fisicoJog2, pontua��oJog1, pontua��oJog2, somaPontua��oUm, somaPontua��oDois);
			cout << jogadorDois;
			cout << "\n---------------\n" << endl;


			// terceira rodada (mesma forma que as anteriores) 
			MostraNomeJogador(jogadorUm);
			cout << endl << endl;
			cout << "Carta: ";
			cout << CartasJogadorUm[2]->nome << " ";
			cout << endl;

			MenuDoJogo();
			cin >> EscolhAtributo; 
			cout << endl;
			MostraNomeJogador(jogadorUm);
			cout << CartasJogadorUm[2]->nome << " ";
			 
			switch (EscolhAtributo)  
			{
			case 1:
				cout << "| " << CartasJogadorUm[2]->velocidade << " " << endl;
				velocidaeJog1 = CartasJogadorUm[2]->velocidade;
				break;
			case 2:
				cout << "| " << CartasJogadorUm[2]->finaliza��o << " " << endl;
				finalizaJog1 = CartasJogadorUm[2]->finaliza��o;
				break;
			case 3:
				cout << "| " << CartasJogadorUm[2]->passe << " " << endl;
				passeJog1 = CartasJogadorUm[2]->passe;
				break;
			case 4:
				cout << "| " << CartasJogadorUm[2]->drible << " " << endl;
				dribleJog1 = CartasJogadorUm[2]->drible;
				break;
			case 5:
				cout << "| " << CartasJogadorUm[2]->fisico << " " << endl;
				fisicoJog1 = CartasJogadorUm[2]->fisico;
				break;
			default:
				cout << "Atributo n�o existe, escolha novamente";
				cin >> EscolhAtributo;
				break;
			}

			MostraNomeJogador(jogadorDois);
			cout << CartasJogadorDois[2]->nome << " ";

			switch (EscolhAtributo)
			{
			case 1:
				cout << "| " << CartasJogadorDois[2]->velocidade << " " << endl;
				velocidadeJog2 = CartasJogadorDois[2]->velocidade;
				break;
			case 2:
				cout << "| " << CartasJogadorDois[2]->finaliza��o << " " << endl;
				finalizaJog2 = CartasJogadorDois[2]->finaliza��o;
				break;
			case 3:
				cout << "| " << CartasJogadorDois[2]->passe << " " << endl;
				passeJog2 = CartasJogadorDois[2]->passe;
				break;
			case 4:
				cout << "| " << CartasJogadorDois[2]->drible << " " << endl;
				dribleJog2 = CartasJogadorDois[2]->drible;
				break;
			case 5:
				cout << "| " << CartasJogadorDois[2]->fisico << " " << endl;
				fisicoJog2 = CartasJogadorDois[2]->fisico;
				break;
			default:
				cout << "Atributo n�o existe, escolha novamente";
				cin >> EscolhAtributo;
				break;
			}

			cout << "\nPlacar: " << jogadorUm;
			Placar(EscolhAtributo, velocidaeJog1, velocidadeJog2, finalizaJog1, finalizaJog2, passeJog1, passeJog2,
				dribleJog1, dribleJog2, fisicoJog1, fisicoJog2, pontua��oJog1, pontua��oJog2, somaPontua��oUm, somaPontua��oDois);

			cout << jogadorDois;
			cout << "\n---------------\n" << endl;


			// quarta rodada (mesma base das anteriores)
			MostraNomeJogador(jogadorDois);
			cout << endl << endl;

			cout << "Carta: ";
			cout << CartasJogadorDois[3]->nome << " ";
			cout << endl;

			MenuDoJogo();
			cin >> EscolhAtributo;
			cout << endl;

			MostraNomeJogador(jogadorDois);
			cout << CartasJogadorDois[3]->nome << " ";
			

			switch (EscolhAtributo)
			{
			case 1:
				cout << "| " << CartasJogadorDois[3]->velocidade << " " << endl;
				velocidadeJog2 = CartasJogadorDois[3]->velocidade;
				break;
			case 2:
				cout << "| " << CartasJogadorDois[3]->finaliza��o << " " << endl;
				finalizaJog2 = CartasJogadorDois[3]->finaliza��o;
				break;
			case 3:
				cout << "| " << CartasJogadorDois[3]->passe << " " << endl;
				passeJog2 = CartasJogadorDois[3]->passe;
				break;
			case 4:
				cout << "| " << CartasJogadorDois[3]->drible << " " << endl;
				dribleJog2 = CartasJogadorDois[3]->drible;
				break;
			case 5:
				cout << "| " << CartasJogadorDois[3]->fisico << " " << endl;
				fisicoJog2 = CartasJogadorDois[3]->fisico;
				break;
			default:
				cout << "Atributo n�o existe, escolha novamente";
				cin >> EscolhAtributo;
				break;
			}

			MostraNomeJogador(jogadorUm);
			cout << CartasJogadorUm[3]->nome << " ";

			switch (EscolhAtributo)  
			{
			case 1:
				cout << "| " << CartasJogadorUm[3]->velocidade << " " << endl;
				velocidaeJog1 = CartasJogadorUm[3]->velocidade;
				break;
			case 2:
				cout << "| " << CartasJogadorUm[3]->finaliza��o << " " << endl;
				finalizaJog1 = CartasJogadorUm[3]->finaliza��o;
				break;
			case 3:
				cout << "| " << CartasJogadorUm[3]->passe << " " << endl;
				passeJog1 = CartasJogadorUm[3]->passe;
				break;
			case 4:
				cout << "| " << CartasJogadorUm[3]->drible << " " << endl;
				dribleJog1 = CartasJogadorUm[3]->drible;
				break;
			case 5:
				cout << "| " << CartasJogadorUm[3]->fisico << " " << endl;
				fisicoJog1 = CartasJogadorUm[3]->fisico;
				break;
			default:
				cout << "Atributo n�o existe, escolha novamente";
				cin >> EscolhAtributo;
				break;
			}

			// placar final do jogo 
			cout << "Final: " << jogadorUm;
			Placar(EscolhAtributo, velocidaeJog1, velocidadeJog2, finalizaJog1, finalizaJog2, passeJog1, passeJog2,
				dribleJog1, dribleJog2, fisicoJog1, fisicoJog2, pontua��oJog1, pontua��oJog2, somaPontua��oUm, somaPontua��oDois);

			cout << jogadorDois;
			cout << "\n---------------" << endl;

			cout << "Obrigado por jogar Super Trunfo do FIFA 21!!" << endl;

			// zerando pontua��o caso queira come�ar outro jogo
			pontua��oJog1 = 0;
		    somaPontua��oUm = 0;
	        pontua��oJog2 = 0;
		    somaPontua��oDois = 0;
		}
		else  // caso o usuario tinha digitado diferente de n ou N, mas n�o tenha digitado s ou S = > avisa que t� errado
		{
			cout << "Digito errado, por favor, escolha novamente!" << endl;
			cout << endl;
		}
		
		// menu para come�ar outra partida 
		cout << "\nSuper Trunfo Fifa 21" << endl;
		cout << "--------------------" << endl;
		cout << "Iniciar nova partida? [S/N] ";
		cin >> escolha;
	
	}
   
	// caso n�o queira jogar 
	cout << "Fica para a pr�xima!" << endl;
	delete[] VetorDinBaralho;  // deletando vetor din�mico
	return 0;
}

