#include <stdio.h>

int main(){
  char painel[61];
  int testes,k;
  long long unsigned muda;
  scanf("%d",&testes);
  for (int i = 0; i < testes; i++){
    scanf("%s %llu",painel, &muda);
    int j = 0;
    while(muda!=0){
      
      if ((muda%2)==1){
        if(painel[j] == 'X')
          painel[j] = 'O';
        else {
          k = 0;
          while(painel[j+k]){
            if (painel[j+k]=='X'){
              painel[j+k] = 'O';
              break;
            }
            else
              painel[j+k] = 'X';
            k++;
          }
        }
      }
      j++;
      muda = muda/2;
    }
    printf("%s\n",painel);
  }
  return 0;
}
