#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define N 100
using namespace std;

typedef struct{
char name[N];
int weight;
int price;
}Goods;

void backpack(Goods *goods, int length, int limit){
int form[N][N]={0};
for(int i=1;i<=length;i++){
    for(int j=1;j<=limit;j++){
        if(j>=goods[i-1].weight){
            form[i][j]=max(form[i-1][j],form[i-1][j-goods[i-1].weight]+goods[i-1].price);
        }
        else{
            form[i][j]=form[i-1][j];
        }
    }
}
cout<<"The max value: "<<form[length][limit];
}

int max(int a, int b){
if(a>=b){
    return a;
}
else{
    return b;
}
}

int main(){
Goods goods[N];
int length,limit;
cout<<"Please input limit: ";
cin>>limit;
cout<<"Please input goods length: ";
cin>>length;
cout<<"Please input goods data: "<<endl;
for(int i=0;i<length;i++){
    cin>>goods[i].name>>goods[i].weight>>goods[i].price;
}
cout<<endl;
backpack(goods,length,limit);
}
