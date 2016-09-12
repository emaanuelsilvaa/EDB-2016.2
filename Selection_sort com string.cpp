//Código da ordenação SelectionSort com strings
void ordenar_selecao_nome() {
    int i,j,indmin;
    string min, aux;
    for(i=0; i< (tam-1); i++) {
        strcpy(min,vetor[i]);
        indmin = i;
        for(j=i+1; j<tam; j++) {
            if(strcmp(vetor[j],min)<0)
                strcpy(min,vetor[j]);
                indmin = j;
        }
        if(strcmp(vetor[i], min)>0) {
            strcpy(aux, vetor[i]);
            strcpy(vetor[i], vetor[indmin]);
            strcpy(vetor[indmin], aux);
        }
    }
}
