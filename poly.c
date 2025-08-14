#include<stdio.h>
struct poly{
int coeff;
int expo;
}poly1[10],poly2[10],poly3[20];
void main(){
int i=1,j=1,k=1,n1,n2;
printf("enter the no of terms first polynomial ");
scanf("%d",&n1);
for(i=1;i<=n1;i++){
printf("enter the coeff ");
scanf("%d",&poly1[i].coeff);
printf("enter the expo ");
scanf("%d",&poly1[i].expo);
}
printf("enter the no of terms 2nd polynomial ");
scanf("%d",&n2);
for(i=1;i<=n2;i++){
printf("enter the coeff ");
scanf("%d",&poly2[i].coeff);
printf("enter the expo ");
scanf("%d",&poly2[i].expo);
}
i=1;
j=1;

while(i<=n1&&j<=n2){
///case1
if(poly1[i].expo==poly2[j].expo){
poly3[k].coeff=poly1[i].coeff+poly2[j].coeff;
poly3[k].expo=poly1[i].expo;
i++;
j++;
k++;
}
///case2
if(poly1[i].expo>poly2[j].expo){
poly3[k].coeff=poly1[i].coeff;
poly3[k].expo=poly1[i].expo;
i++;
k++;
}
///case3
if(poly1[i].expo<poly2[j].expo){
poly3[k].coeff=poly2[j].coeff;
poly3[k].expo=poly2[j].expo;
j++;
k++;
}
}
while(i<n1){
poly3[k].coeff=poly1[i].coeff;
poly3[k].expo=poly1[i].expo;
i++;
k++;
}

while(j<n2){
poly3[k].coeff=poly2[j].coeff;
poly3[k].expo=poly2[j].expo;
j++;
k++;
}
printf("\n");
for(i=1;i<k;i++){
if(i<k-1){
printf("%d(x)^%d+",poly3[i].coeff,poly3[i].expo);
}
else {
printf("%d(x)^%d\n",poly3[i].coeff,poly3[i].expo);
}
}
}

