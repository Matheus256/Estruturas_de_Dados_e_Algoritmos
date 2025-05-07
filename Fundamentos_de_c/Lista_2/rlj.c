#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char entrada[21],R[7],L[7],J[7];
  int resultado;
  while(scanf("%s",entrada)!= EOF){
    int k = 0;
    while(entrada[k]!='+'){
      R[k]=entrada[k];
      k++;
    }
    R[k]='\0';
    //printf("%s\n",R);
    int j=0;
    k++;
    while(entrada[k+j]!='='){
      L[j]=entrada[k+j];
      j++;
    }
    L[j]='\0';
    //printf("%s\n",L);
    int v=0;
    k=k+j+1;
    while(entrada[k+v]){
      J[v]=entrada[k+v];
      v++;
    }
    J[v]='\0';
    //printf("%s\n",J);
    if (strcmp(R,"R")==0)
      resultado = atoi(J) - atoi(L);
    else if (strcmp(L,"L")==0)
      resultado = atoi(J) - atoi(R);
    else
      resultado = atoi(R) + atoi(L);
    printf("%d\n",resultado);
  }
  return 0;
}
