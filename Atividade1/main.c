#include <stdio.h>
#include <stdlib.h>

int sobraUm( int vet[], int tam){
    int sobrouUm = 0;
    int c = 0;
    int num = -1;
    for (c = 0; c < tam; c++){
        if (vet[c] != -1){
            num = vet[c];
            sobrouUm++;
            if (sobrouUm == 2)
                return -1;
        }
    }

    return num;
}

void preencherVet(int vet[], int tam){
    for (int c = 0; c < tam; c++) vet[c] = c + 1;
}

int suicida(int numeroPessoas){

    if (numeroPessoas < 2){
        perror("Se a sua tribo tem menos de 2 pessoas eh melhor vc parar de desculpas e se matar logo burrao\n");
        exit(1);
    }

    int vet[numeroPessoas];
    preencherVet(vet,numeroPessoas);

    int morrer = 0;    
    int c = 0;
    int sobrevivente = -1;
    while (1){
        if (morrer == 1 && vet[c] != -1){
            vet[c] = -1;
            morrer = 0;
        }else if (vet[c] != -1){
            morrer = 1;
        }

        sobrevivente = sobraUm(vet,numeroPessoas);
        if( sobrevivente != -1 ){
            return sobrevivente;
        }
        
        if (c == numeroPessoas - 1){
            c = 0;
        }else {
            c++;
        }
    }
}

int main(){
    int pessoas;
    printf("Quantas pessoas tem na sua tribo -> ");
    if (scanf("%d", &pessoas) == 0){
        perror("Se a sua tribo tem menos de 2 pessoas eh melhor vc parar de desculpas e se matar logo burrao\n");
        exit(1);
    }

    int sobrevivente = suicida(pessoas);
    printf("Numa tribo de %d pessoas, a pessoa de posicao numero %d tera a responsibilidade de se suicidar no final!\n",pessoas,sobrevivente);

    return 0;

}