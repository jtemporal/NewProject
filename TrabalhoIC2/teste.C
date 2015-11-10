// bibliotecas
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//declarando funcoes
float relacaoRproduto(float R[], bool relacao);

//programa principal
int main (void){
    // declaracao
    int a;
    float R;
    int kgA;
    int kgB;
    float relA; //para relacao R/A
    float relB; //para relacao R/B
    float pi;
    float Ra[100]; //para armazenar os valores de R para A em kg
    float Rb[100]; //para armazenar os valores de R para B em kg
    
    // inicializacao
    pi = 3.14;
    
    // calcula R para A e B no intervalo de 1 a 100 kg
    for ( int i=0; i<100; i++ ){
        //printf("entrou no for %d",i);
        a = i+1;
        Ra[i] = (float)(0.5 * a) + ((2.56 * (float)sqrt(a)) * cos(pow((float)(2 * pi * a)/100,2)));
        Rb[i] = (float)(0.5 * a) + ((float)(1.58 * a) * pow(sin((float)(2 * pi * a)/100),2));
        // para visualizar os valores Ra
        printf("\nForam gerados %f com %dkg de A", Ra[i], i);
        printf("\nForam gerados %f com %dkg de B", Rb[i], i);
    }// fim for
    
    // para achar os maiores valores das relações
    relA = relacaoRproduto(Ra, true);
    relB = relacaoRproduto(Rb, true);
    kgA = relacaoRproduto(Ra, false);
    kgB = relacaoRproduto(Rb, false);
    printf("\nR/A maximo = %f\nObtido com %dkg de A",relA, kgA);
    printf("\nR/B maximo = %f\nObtido com %dkg de B",relB, kgB);
    
    return 0;
}

// funcoes
// retorna o valor da relacao R/produto maxima se relacao == true
// retorna quantos quilos faz a relacao R/produto maxima se relacao == false
float relacaoRproduto(float R[], bool relacao){
    
    float r;
    float prox;
    float atual;
    int aux;
    
    r = 0;
    
    for (int i=19; i<98; i++){
        atual = R[i]/(i+1);
        prox = R[i+1]/(i+2);
        if ((atual > prox) && (atual > r)){
            r = atual;
            aux = i;
        }//fim if
    }//fim for
    if (relacao)
        return r;
    else
        return aux+1;
}
