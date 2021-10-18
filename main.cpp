#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>

using namespace std;

void somap1p2(int mat_dados[2][10], int vaium, int vet_resultado[10]){ // Soma P1 P2 CHECKSUM

	int i;

	for(i=9; i>=0; i--){
                if(mat_dados[0][i] == 0 && mat_dados[1][i] == 0 && vaium == 0){  // soma bit a bit da direita para a esquerda
                    vet_resultado[i]=0;
                    vaium = 0;
                } else if(mat_dados[0][i] == 0 && mat_dados[1][i] == 0 && vaium == 1){
                    vet_resultado[i]=1;
                    vaium = 0;
                } else if(mat_dados[0][i] == 1 && mat_dados[1][i] == 1 && vaium == 0){
                    vet_resultado[i]=0;
                    vaium = 1;
                } else if(mat_dados[0][i] == 1 && mat_dados[1][i] == 1 && vaium == 1){
                    vet_resultado[i]=1;
                    vaium = 1;
                } else if(mat_dados[0][i] == 1 && mat_dados[1][i] == 0 && vaium == 0){
                    vet_resultado[i]=1;
                    vaium = 0;
                } else if(mat_dados[0][i] == 0 && mat_dados[1][i] == 1 && vaium == 0){
                    vet_resultado[i]=1;
                    vaium = 0;
                } else if(mat_dados[0][i] == 1 && mat_dados[1][i] == 0 && vaium == 1){
                    vet_resultado[i]=0;
                    vaium = 1;
                } else if (mat_dados[0][i] == 0 && mat_dados[1][i] == 1 && vaium == 1){
                    vet_resultado[i]=0;
                    vaium = 1;
                }
            }
}

void vetresult_vetvaium(int vet_resultado[10],int vet_vaium[10], int auxiliar){ // Soma vet_resultado e vetor bit a mais

	int i;

            for(i=9; i>=0; i--){
                    if(vet_resultado[i] == 0 && vet_vaium[i] == 0 && auxiliar == 0){    // caso bit a mais na resultante da direita para a esquerda
                        vet_resultado[i]=0;
                        auxiliar = 0;
                    } else if(vet_resultado[i] == 0 && vet_vaium[i] == 0 && auxiliar == 1){
                        vet_resultado[i]=1;
                       auxiliar = 0;
                    } else if(vet_resultado[i] == 1 && vet_vaium[i] == 1 && auxiliar == 0){
                        vet_resultado[i]=0;
                       auxiliar = 1;
                    } else if(vet_resultado[i] == 1 && vet_vaium[i] == 1 && auxiliar == 1){
                        vet_resultado[i]=1;
                        auxiliar = 1;
                    } else if(vet_resultado[i] == 1 && vet_vaium[i] == 0 && auxiliar == 0){
                        vet_resultado[i]=1;
                        auxiliar = 0;
                    } else if(vet_resultado[i] == 0 && vet_vaium[i] == 1 && auxiliar == 0){
                        vet_resultado[i]=1;
                        auxiliar = 0;
                    } else if(vet_resultado[i] == 1 && vet_vaium[i] == 0 && auxiliar == 1){
                        vet_resultado[i]=0;
                        auxiliar = 1;
                    } else if (vet_resultado[i] == 0 && vet_vaium[i] == 1 && auxiliar == 1){
                        vet_resultado[i]=0;
                        auxiliar = 1;
                    }
                    if(auxiliar==0){
                        break;
                    }
                }
}

int main(){


       int TAM=0, i, aux=0, j;

// começo checksum ****

        int mat_dados[2][10]={0}, vet_resultado[10]={0}, vai_um=0, vet_vaium[10]={0,0,0,0,0,0,0,0,0,1}, vet_EDC[10]={0};

        // declaração das palvras
        printf("\nDigite a primeira palavras de dados desejada, com um espaco entre os bits: \n");// declaração das palavras
        scanf("%d%d%d%d%d%d%d%d%d%d", &mat_dados[0][0],&mat_dados[0][1],&mat_dados[0][2],&mat_dados[0][3],&mat_dados[0][4],&mat_dados[0][5],&mat_dados[0][6],&mat_dados[0][7],&mat_dados[0][8],&mat_dados[0][9]);

        printf("\nDigite a segunda palavras de dados desejada, com um espaco entre os bits: \n");
        scanf("%d%d%d%d%d%d%d%d%d%d", &mat_dados[1][0],&mat_dados[1][1],&mat_dados[1][2],&mat_dados[1][3],&mat_dados[1][4],&mat_dados[1][5],&mat_dados[1][6],&mat_dados[1][7],&mat_dados[1][8],&mat_dados[1][9]);


       { //Soma da palavra1 e palavra2 **********************************************
           somap1p2(mat_dados,vai_um,vet_resultado);


            if(vai_um == 1){            // caso bit a mais (vai um)

                vetresult_vetvaium(vet_resultado,vet_vaium,aux);
            }
        }

        {
            vai_um = 0;
            aux = 0;

            for(i=9; i>=0; i--){
                if(vet_resultado[i] == 0 && mat_dados[2][i] == 0 && vai_um == 0){ // soma bit a bit da direita para a esquerda
                    vet_resultado[i]=0;
                    vai_um = 0;
                } else if(vet_resultado[i] == 0 && mat_dados[2][i] == 0 && vai_um == 1){
                    vet_resultado[i]=1;
                    vai_um = 0;
                } else if(vet_resultado[i] == 1 && mat_dados[2][i] == 1 && vai_um == 0){
                    vet_resultado[i]=0;
                    vai_um = 1;
                } else if(vet_resultado[i] == 1 && mat_dados[2][i] == 1 && vai_um == 1){
                    vet_resultado[i]=1;
                    vai_um = 1;
                } else if(vet_resultado[i] == 1 && mat_dados[2][i] == 0 && vai_um == 0){
                    vet_resultado[i]=1;
                    vai_um = 0;
                } else if (vet_resultado[i] == 0 && mat_dados[2][i] == 1 && vai_um == 0){
                    vet_resultado[i]=1;
                    vai_um = 0;
                } else if(vet_resultado[i] == 1 && mat_dados[2][i] == 0 && vai_um == 1){
                    vet_resultado[i]=0;
                    vai_um = 1;
                } else if (vet_resultado[i] == 0 && mat_dados[2][i] == 1 && vai_um == 1){
                    vet_resultado[i]=0;
                    vai_um = 1;
                }
            }

            if(vai_um == 1){ // caso bit a mais (vai um)

               vetresult_vetvaium(vet_resultado,vet_vaium,aux);
            }
        }

        printf("\n\nMENSAGEM ENVIADA\n"); // mensagem de emissor ou soma de p1 com p2
        for(i=0; i<10; i++){
            printf("%d ", vet_resultado[i]);
        }

        { //complemento de 2 ou inversão da mensagem enviada ( inversao da soma de p1 com p2 )
            for(i=0; i<10; i++){
                vet_EDC[i]=!vet_resultado[i];
            }
        }

        printf("\n\nEDC\n"); // impressão do EDC
        for(i=0; i<10; i++){
            printf("%d ", vet_EDC[i]);
        }



        printf("\n\nMENSAGEM RECEBIDA\n"); // impressão da mensagem recebida (EDC invertido)
        for(i=0; i<10; i++){
            printf("%d ", vet_resultado[i]);
        }

        {
            vai_um = 0;
            aux = 0;

            for(i=9; i>=0; i--){        //Soma da palavra resultante com EDC
                if(vet_resultado[i] == 0 && vet_EDC[i] == 0 && vai_um == 0){ // soma da palavra resultante da direita para a aesqueda com o EDC
                    vet_resultado[i]=0;
                    vai_um = 0;
                } else if(vet_resultado[i] == 0 && vet_EDC[i] == 0 && vai_um == 1){
                    vet_resultado[i]=1;
                    vai_um = 0;
                } else if(vet_resultado[i] == 1 && vet_EDC[i] == 1 && vai_um == 0){
                    vet_resultado[i]=0;
                    vai_um = 1;
                } else if(vet_resultado[i] == 1 && vet_EDC[i] == 1 && vai_um == 1){
                    vet_resultado[i]=1;
                    vai_um = 1;
                } else if(vet_resultado[i] == 1 && vet_EDC[i] == 0 && vai_um == 0){
                    vet_resultado[i]=1;
                    vai_um = 0;
                } else if (vet_resultado[i] == 0 && vet_EDC[i] == 1 && vai_um == 0){
                    vet_resultado[i]=1;
                    vai_um = 0;
                } else if(vet_resultado[i] == 1 && vet_EDC[i] == 0 && vai_um == 1){
                    vet_resultado[i]=0;
                    vai_um = 1;
                } else if (vet_resultado[i] == 0 && vet_EDC[i] == 1 && vai_um == 1){
                    vet_resultado[i]=0;
                    vai_um = 1;
                }
            }

            if(vai_um == 1){ // caso bit a mais (vai um)

                vetresult_vetvaium(vet_resultado,vet_vaium,aux);
            }
        }

        int erro=0; //  confirmação da existencia de erro caso a mensagem esteja zerada ou nao .
        printf("\n\nMENSAGEM DE VERIFICACAO\n");
        for(i=0; i<10; i++){
            printf("%d ", vet_resultado[i]);
            if(vet_resultado[i]==0){
                erro=1;
            }
        }

        if(erro == 1){ // empressão da mensagem de erro
            printf("\n\nMENSAGEM CONTEM ERRO\n\n");
        } else {
            printf("\n\nMENSAGEM NAO CONTEM ERRO\n\n");
        }

        return 0;
    }
