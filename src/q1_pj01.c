
#include <stdio.h>
#define MAX 10


  float fneuronio(float *, float *, float, int);

  int main(int argc, char const *argv[]) {

    float ENTRADA[MAX], PESOS[MAX], SOMAP, T;
    int i, sucess;

    //SOMAP > T = CÉLULA EXITADA
    //SOMAP < T = CÉLULA INIBIDA

    printf("\n-----------------------------------------------------------------\n");
    printf("DIGITE 10 VALORES REIAS DE ENTRADA: \n");
    printf("-----------------------------------------------------------------\n");

    for ( i = 0; i < 10; i++) {

      scanf("%f",&ENTRADA[i]);

    }

    printf("-----------------------------------------------------------------\n");
    printf("AGORA DIGITE 10 VALORES REIAS PARA PESOS: \n");
    printf("-----------------------------------------------------------------\n");

    for ( i = 0; i < 10; i++) {

      scanf("%f",&PESOS[i]);

    }

    printf("-----------------------------------------------------------------\n");
    printf("POR FIM, DIGITE O VALOR DE T: \n");
    printf("-----------------------------------------------------------------\n");

    scanf("%f",&T);

    sucess = fneuronio(ENTRADA, PESOS, T, MAX);

    if (sucess == 1) {
      printf("-----------------------------------------------------------------\n");
      printf("Neurônio ativado!\n");
      printf("-----------------------------------------------------------------\n");
    }
    else {
      printf("-----------------------------------------------------------------\n");
      printf("Neurônio inibido!\n");
      printf("-----------------------------------------------------------------\n");
    }
    return 0;
  }

  float fneuronio(float *ENTRADA_FUNCAO, float *PESOS_FUNCAO, float T_FUNCAO, int MAX_FUNCAO){

    int i;
    float SOMAP = 0;

    for (i = 0; i < MAX_FUNCAO; i++) {

      SOMAP = SOMAP + *(ENTRADA_FUNCAO + i) * *(PESOS_FUNCAO + i);
    }

    if (SOMAP > T_FUNCAO)

      return 1;

    else

      return 0;

  }
