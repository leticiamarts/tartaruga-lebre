#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int inicio(int posicao){
    if(posicao < 1){
        return 1;
    }
}


void finalizar(int posicaoLebre, int posicaoTartaruga){
    if(posicaoLebre >= 70 && posicaoTartaruga < 70){
        printf("Vitória da LEBRE!!\n");
    }
    else{
        if(posicaoTartaruga >= 70 && posicaoLebre < 70){
            printf("Vitória da TARTARUGA!!\n");
        }
        else{
            if(posicaoLebre >= 70 && posicaoTartaruga >= 70){
                printf("EMPATE!!\n");
            }
        }
    }
}

int funcaoPosicaoTartaruga(int numeroMovimento){
    if(1 <= numeroMovimento <= 5){
        return 3;
    }
    else{
        if((numeroMovimento == 6) || (numeroMovimento == 7)){
            return - 6;
        }
        else{
            return 1;
        }
    }
}

int funcaoPosicaoLebre(int numeroMovimento){
    if((numeroMovimento == 1) || (numeroMovimento == 2)){
        return 0;
    }
    else{
        if((numeroMovimento == 3) || (numeroMovimento == 4)){
            return 9;
        }
        else{
            if(numeroMovimento == 5){
                return -1;
            }
            else{
                if(6 <= numeroMovimento <= 8){
                    return 1;
                }
                else{
                    return -2;
                }
            }
        }
    }
}

void corrida(int posicaoLebre, int posicaoTartaruga){
    int i;
    
    for(i = 1; i<= 70; i++){
        if((posicaoLebre == i) && (posicaoTartaruga == i)){
            printf("OUCH!!!");
        }
        else{
            printf("*");
        }
        
        if(i == posicaoTartaruga){
            printf("T");
        }
        if(i == posicaoLebre){
            printf("L");
        }
        else{
            printf("*");
        }
    }
    fflush(stdout);
}


int main(){
    int posicaoLebre = 1, posicaoTartaruga = 1, movimentoLebre, movimentoTartaruga;

    system("cls");
    srand(time(NULL));
    while((posicaoLebre < 70) && (posicaoTartaruga < 70)){
        posicaoLebre = inicio(posicaoLebre);
        movimentoLebre = rand() % 10 + 1;
        posicaoLebre = posicaoLebre + funcaoPosicaoLebre(movimentoLebre);
        posicaoTartaruga = inicio(posicaoTartaruga);
        movimentoTartaruga = rand() % 10 + 1;
        posicaoTartaruga = posicaoTartaruga + funcaoPosicaoTartaruga(movimentoTartaruga);
        corrida(posicaoLebre, posicaoTartaruga);
        Sleep(500);
        system("cls");
        finalizar(posicaoLebre, posicaoTartaruga);
    }

    return 0;
}