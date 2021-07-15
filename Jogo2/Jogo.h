#pragma once

struct baralho
{
	char nome[30];      // nome do jogador
	int velocidade;     // velocidade do jogador
	int finalização;    // finalização do jogador 
	int passe;          // passe do jogador 
	int drible;         // drible do jogador 
	int fisico;         // fisico do jogador 
};

// funçoes usadas 
// função que mostra e atualiza o placar de forma correta => usando referencias
void Placar(int escolha, int velo, int veloj2, int finali, int finaj2, int passe, int passej2,
	int drible, int driblej2, int fisico, int fisicoj2, int& pontuaJog1, int& PontuaJog2, int& SomaPontUm, int& SomaPontDois);

// funçao que mostra o nome dos participantes do jogo 
void MostraNomeJogador(char JogadorNome[30]);

// função que mostra o menu (caracteristicas que podem ser escolhidas para serem comparadas)
void MenuDoJogo(); 