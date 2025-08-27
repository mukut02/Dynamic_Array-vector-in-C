#include<stdio.h>
#include<stdlib.h>

#define cout printf
#define cin scanf

typedef struct vector{
   int* data;
   int size;
   int capacity;
} vector;

vector* initilise(vector* v){
    v->size =0; // empty vector
    v->capacity =4; // intial capacity
    v->data = (int *)malloc(sizeof(int)*v->capacity);
    return v;
}

void resize(vector* v){
    v->capacity*=2; // HUGE PERFORMANCE enhancement if done doubled instead of +1
    v->data = (int *)realloc(v->data, v->capacity*sizeof(int)); // x -> 2*x x(old size)
}

void push_back(vector* v,int val){
    if(v->size==v->capacity) resize(v); // create room bruh
    v->data[v->size++]=val;
}

void insert(vector* v,int pos,int val){
    if(pos<0 || pos>v->size){
        cout("Invalid insertion!!\n");
        return;
    }
    if(v->size == v->capacity) resize(v);
    for(int i=v->size;i>pos;--i){
        v->data[i] = v->data[i-1]; // right shift
    }
    v->data[pos]=val;
    v->size++;
}

void delete(vector* v,int pos){
    if(pos<0 || pos>v->size){
        cout("Invalid deletion!!\n");
        return;
    }
    
    for(int i=pos;i<v->size-1;++i){
       v->data[i]=v->data[i+1];
    }
    v->size--;
}

void printVector(vector* v){
    cout("[ ");
    for(int i=0;i<v->size;++i){
        cout("%d ",v->data[i]);
    }
    cout("]\n ");
}

int isEmpty(vector* v){
    return v->size==0;
}

void freeVector(vector* v){
    free(v->data);
    v->data=NULL;
    v->size=0;
    v->capacity=0;
}


int main(){
    vector *v;
    initilise(v);
    for(int i=0;i<10;++i){
        push_back(v, i);
        // cout("index : %d, capacity: %d, size: %d \n",i,v->capacity,v->size);
    }
    insert(v,5,50);
    delete(v,0);
    printVector(v);
}
