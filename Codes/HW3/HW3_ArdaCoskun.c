#include <stdio.h>
#include <unistd.h>

int main(){
  short int s=0, m=0, h=0;
  
 start:
  printf("%0.2d:%0.2d:%0.2d\n", h, m, s);
  s++;
  if(s == 60){
    s = 0;
    m++;
  }
  if(m == 60){
    m = 0;
    h++;
  }
  if(h == 24){
    h = 0;
  }
  sleep(1);
  goto start;

  return 0;
}
