
#include <stdio.h>
#define MAX 10


int *recebe_notas(float *, int, int *);
void conta_notas(int *, int, int *, int *);
int percent_aprov(int *, int *);

int main(int argc, char const *argv[]) {

float NOTAS[MAX];
int i, *p1, p2, p3, APR[MAX], APROVADOS = 0, REPROVADOS = 0;

printf("\n-----------------------------------------------------------------\n\n");
printf("DIGITE 10 NOTAS: ");

for ( i = 0; i < MAX; i++) {

  scanf("%f",&NOTAS[i]);

  while(NOTAS[i] < 0 || NOTAS[i] > 10) {
    printf("NOTA INVÁLIDA, DIGITE NOVAMENTE A [%dª] NOTA \n", i + 1);
    scanf("%f",&NOTAS[i]);
  }
}

p1 = recebe_notas(NOTAS, MAX, APR);
conta_notas(APR, MAX, &APROVADOS, &REPROVADOS);

printf("\n-----------------------------------------------------------------\n\n");
printf("Quntidade de aprovados: %d.\n", APROVADOS);
printf("Quantidade de reprovados: %d.\n", REPROVADOS);

p3 = percent_aprov(&APROVADOS, &REPROVADOS);

printf("Percentual de aprovados: %d%%.\n", APROVADOS);
printf("Percentual de reprovados: %d%%.\n", REPROVADOS);
printf("Mais de metade da turma foi aprovada? [1]SIM | [0]NÃO: RESPOSTA[%d].\n", p3);
printf("\n-----------------------------------------------------------------\n");

return 0;
}

int *recebe_notas(float *NOTAS_FUNCAO, int N, int *APR_FUNCAO){

  int i, APR[N];

  for (i = 0; i < N; i++) {
    if (*(NOTAS_FUNCAO + i) >= 6.0)
        *(APR_FUNCAO + i) = 1;

    else
        *(APR_FUNCAO + i) = 0;
  }

return APR_FUNCAO;
}

void conta_notas(int *APR_FUNCAO, int N, int *APROVADOS_FUNCAO, int *REPROVADOS_FUNCAO){

  int i;

  for (i = 0; i < N; i++) {

    if (*(APR_FUNCAO + i) == 1)
      (*APROVADOS_FUNCAO)++;
    else
      (*REPROVADOS_FUNCAO)++;
  }
}

int percent_aprov(int *APROVADOS_FUNCAO, int *REPROVADOS_FUNCAO){

  *APROVADOS_FUNCAO = *APROVADOS_FUNCAO * 10;
  *REPROVADOS_FUNCAO = *REPROVADOS_FUNCAO * 10;

  if (*APROVADOS_FUNCAO > 50)
    return 1;
  else
    return 0;
}
