#include <stdio.h>
int main(){
 double sf, v, nv;  
 char name[20];
 
 scanf("%s", name);
 scanf("%lf", &sf);
 scanf("%lf", &v);
 
 nv = (v * 0.15) + sf;
 printf("TOTAL = %.2lf\n", nv);
 
 return 0;   
}