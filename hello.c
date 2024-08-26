#include<stdio.h>

int main(){

int synaBankBalance = 1000000;
int costTV = 50000;

int numberOfTV = 0;

if (synaBankBalance > costTV)
{
    numberOfTV = numberOfTV + 1;
}
else if (costTV == 50000)
{
    numberOfTV += 1; // i +=1  i = i + 1
}
if (numberOfTV > 0){
    numberOfTV += 1;
}
else {
    numberOfTV += 1;
}


printf("%d",numberOfTV);

}