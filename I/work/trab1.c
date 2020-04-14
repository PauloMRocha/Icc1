#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

int main(void){
  //iniciação de variaveis basicas
  int tent = 3, seed, n_seq = 0, n_val = 0, cont = 1, input;
  int total_score = 0;
  char dif;
  //int time;

  //declarando array onde ficará a sequencia
  int seq[9];

  //coletando os dados de inicializaçao
  scanf("%d %c", &seed, &dif);

  srand(seed);

  //definindo o valor das variaveis de acordo com a dificuldade
  switch(dif){
    case 'F':
    n_seq = 3;
    n_val = 5;
  //  time  = 5;
    break;

    case 'I':
    n_seq = 4;
    n_val = 7;
    //time  = 7;
    break;

    case 'A':
    n_seq = 5;
    n_val = 9;
  //  time  = 10;
    break;
  }

  // o jogo
  while(tent > 0 && cont <= n_seq){
    //gerando sequencia
    for(int i = 0; i < n_val; i++){
      seq[i] = (rand() % 10);
    }
    int prim_erro = 1, score = (10*n_val);//declarando variaveis que resetam para cara cada Sequencia

    //loop em que o jogador fica preso até acertar a sequencia ou zerar as tentativas
    while(tent > 0){
      int erros = 0;// declaração da pontuação (reseta a antes de cada tentativa de resposta)

      //printando a sequencai
      printf("Sequencia #%d:\n", cont);
      for(int i = 0; i < n_val; i++){
        printf("%d ", seq[i]);
      }
      printf("\n");
      //sleep(time);
      //system("clear");

      //compara a resposta do jogador com a sequencia gerada
      for(int i = 0; i < n_val; i++){
        scanf("%d", &input);
        if(input != seq[i]){
          erros++;
          score -= 10;
        }
      }

      //computando a pontuação caso a resposta esteja correta
      if(erros == 0){
        if(prim_erro == 1) total_score += score;
        cont++;
        printf("Correto!\n");
        printf("Tentativas disponiveis: %d\n", tent);
        printf("Pontuacao: %d\n", total_score);
        break;//sai do loop para gerar outra sequencia
      }else{
        tent--;
        printf("Incorreto!\n");

        if(prim_erro == 1){//contabiliza a pontuação para a primeira vez que o jogador erra a Sequencia
          total_score += score;
          prim_erro = 0;
        }else{//contabiliza a pontuação para os proximos erros
          if(tent > 0){
           total_score -= erros*10;
         }
        }
        if(total_score < 0) total_score = 0;//limita a menor pontuação como 0
        printf("Tentativas disponiveis: %d\n", tent);
        printf("Pontuacao: %d\n", total_score);
        continue;
      }
    }
  }
  if(tent <= 0){
    printf("Nao ha mais tentativas disponiveis... Tente novamente!\n");
  }else{
	 printf("Otima memoria! Parabens!!!\n");
  }

  return 0;
}
