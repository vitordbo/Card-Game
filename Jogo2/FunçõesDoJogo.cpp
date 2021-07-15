#include <iostream> 
#include <windows.h>
#include "Jogo.h"
using namespace std;


void Placar(int escolha, int velo, int veloj2, int finali, int finaj2, int passe, int passej2,
	int drible, int driblej2, int fisico, int fisicoj2, int& pontuaJog1, int& PontuaJog2, int& SomaPontUm, int& SomaPontDois)
{
	switch (escolha)  // com base no atributo escolhido vai comparar 
	{
	case 1:   // atributo = velocidade
		if (velo > veloj2)  // se a velocidade do jogador 1 for maior que a do jogador 2 
		{
			pontuaJog1 = 2;  // pontuaçao
			PontuaJog2 = 0;
			SomaPontUm += pontuaJog1;  // somatorio da pontuação
			SomaPontDois += PontuaJog2;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";  // motrando o somatorio => para poder funcionar nas outras rodadas (uso de referencias facilitou)
		}
		if (velo < veloj2)  // se a velocidade do joagdor 2 for maior que a do jogador 1 
		{
			pontuaJog1 = 0;
			PontuaJog2 = 2;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (velo == veloj2)  // se forem iguais 
		{
			pontuaJog1 = 1;
			PontuaJog2 = 1;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		break;

	case 2:  // atributo = finalização  // mesmas situações do caso 1, porém com atributos diferentes
		if (finali > finaj2)
		{
			pontuaJog1 = 2;
			PontuaJog2 = 0;
			SomaPontUm += pontuaJog1;
			SomaPontDois += PontuaJog2;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (finali < finaj2)
		{
			pontuaJog1 = 0;
			PontuaJog2 = 2;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (finali == finaj2)
		{
			pontuaJog1 = 1;
			PontuaJog2 = 1;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		break;

	case 3:  // atributo = passe  // mesmas situações do caso 1 e 2 porém com atributos diferentes
		if (passe > passej2)
		{
			pontuaJog1 = 2;
			PontuaJog2 = 0;
			SomaPontUm += pontuaJog1;
			SomaPontDois += PontuaJog2;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (passe < passej2)
		{
			pontuaJog1 = 0;
			PontuaJog2 = 2;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (passe == passej2)
		{
			pontuaJog1 = 1;
			PontuaJog2 = 1;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		break;

	case 4: // atributo = drible  // mesmas situações do caso 1,2 e 3 porém com atributos diferentes
		if (drible > driblej2)
		{
			pontuaJog1 = 2;
			PontuaJog2 = 0;
			SomaPontUm += pontuaJog1;
			SomaPontDois += PontuaJog2;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (drible < driblej2)
		{
			pontuaJog1 = 0;
			PontuaJog2 = 2;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (drible == driblej2)
		{
			pontuaJog1 = 1;
			PontuaJog2 = 1;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		break;

	case 5:  // atributo = fisico  // mesmas situações do caso 1,2,3 e 4 porém com atributos diferentes
		if (fisico > fisicoj2)
		{
			pontuaJog1 = 2;
			PontuaJog2 = 0;
			SomaPontUm += pontuaJog1;
			SomaPontDois += PontuaJog2;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (fisico < fisicoj2)
		{
			pontuaJog1 = 0;
			PontuaJog2 = 2;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		if (fisico == fisicoj2)
		{
			pontuaJog1 = 1;
			PontuaJog2 = 1;
			SomaPontDois += PontuaJog2;
			SomaPontUm += pontuaJog1;
			cout << " " << SomaPontUm << " X " << SomaPontDois << " ";
		}
		break;
	default:
		cout << "Por favor, escolha uma das opçoes!" << endl;
	}
}

// mostra o menu do jogo => usuario poder escolher o atributo a ser comparado  
void MenuDoJogo()
{
	cout << "1. Velocidade" << endl;
	cout << "2. Finalização" << endl;
	cout << "3. Passe" << endl;
	cout << "4. Drible" << endl;
	cout << "5. Físico" << endl;

	cout << "Escolha o atributo: " << " [ ] \b\b\b";

}

// escreve o nome do jogador
void MostraNomeJogador(char JogadorNome[30])
{
	cout << "[" << JogadorNome << "] ";
}
