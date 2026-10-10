
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_linha(char *texto, int tamanho){
    if(fgets(texto, tamanho, stdin) == NULL){
        return 0;
    }

    size_t comprimento = strlen(texto);

    if(comprimento > 0 && texto[comprimento - 1] == '\n'){
        texto[comprimento - 1] = '\0';
        return 1;
    }

    int c;
    while((c = getchar()) != '\n' && c != EOF){
        // Limpa o restante da entrada
    }

    return -1;
}

int ler_inteiro(int minimo, int maximo, int *valor){
    char entrada[128];
    char *fim;
    long numero;

    while(1){
        if(!fgets(entrada, sizeof(entrada), stdin)){
            return 0;
        }

        size_t comprimento = strlen(entrada);

        if(comprimento > 0 && entrada[comprimento - 1] != '\n'){
            int c;
            while((c = getchar()) != '\n' && c != EOF){
                // Limpa o restante da entrada
            }

            printf("Entrada muito longa. Tente novamente: ");
            continue;
        }

        numero = strtol(entrada, &fim, 10);

        if(entrada == fim){
            printf("Erro: digite um numero inteiro: ");
            continue;
        }

        while(*fim == ' ' || *fim == '\t'){
            fim++;
        }

        if(*fim != '\n' && *fim != '\0'){
            printf("Erro: digite somente um numero inteiro: ");
            continue;
        }

        if(numero < minimo || numero > maximo){
            printf("Erro: digite um valor entre %d a %d: ",
                   minimo, maximo);
            continue;
        }

        *valor = (int)numero;
        return 1;
    }
}


// Verificar se é primo
int primo(int num){
    if(num < 2)
        return 0;

    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)
            return 0;
    }

    return 1;
}


// Gerar sequência matemática
int gerar_sequencia(int *sequencia, int tamanho, int opcao){
    switch(opcao){
        case 1: // PA
            for(int i = 0; i < tamanho; i++){
                sequencia[i] = 5 + (i * 3);
            }
            return 1;

        case 2: // PG
            for(int i = 0; i < tamanho; i++){
                if(i == 0)
                    sequencia[i] = 2;
                else
                    sequencia[i] = sequencia[i - 1] * 2;
            }
            return 1;

        case 3: // Fibonacci
            if(tamanho >= 1)
                sequencia[0] = 1;

            if(tamanho >= 2)
                sequencia[1] = 1;

            for(int i = 2; i < tamanho; i++){
                sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
            }
            return 1;

        case 4: // Primos
        {
            int encontrado = 0;
            int candidato = 2;

            while(encontrado < tamanho){
                if(primo(candidato)){
                    sequencia[encontrado] = candidato;
                    encontrado++;
                }
                candidato++;
            }
            return 1;
        }

        default:
            return 0;
    }
}


// Criptografar
void criptografar(char *original, char *criptografada,
                  int shift, int *sequencia, int tamanho){
    for(int i = 0; i < tamanho; i++){
        char c = original[i];
        int deslocamento_total = (shift + sequencia[i]) % 26;

        if(c >= 'a' && c <= 'z'){
            criptografada[i] =
                ((c - 'a' + deslocamento_total) % 26) + 'a';
        }else if(c >= 'A' && c <= 'Z'){
            criptografada[i] =
                ((c - 'A' + deslocamento_total) % 26) + 'A';
        }else{
            criptografada[i] = c;
        }
    }

    criptografada[tamanho] = '\0';
}


// Descriptografar
void descriptografar(char *criptografada, char *original,
                     int shift, int *sequencia, int tamanho){
    for(int i = 0; i < tamanho; i++){
        char c = criptografada[i];
        int deslocamento_total = (shift + sequencia[i]) % 26;

        if(c >= 'a' && c <= 'z'){
            original[i] =
                ((c - 'a' - deslocamento_total + 26) % 26) + 'a';
        }else if(c >= 'A' && c <= 'Z'){
            original[i] =
                ((c - 'A' - deslocamento_total + 26) % 26) + 'A';
        }else{
            original[i] = c;
        }
    }

    original[tamanho] = '\0';
}


// Validar palavra
int palavra_valida(char *palavra){
    int tamanho = strlen(palavra);

    if(tamanho == 0){
        printf("Erro: a palavra nao pode estar vazia.\n");
        return 0;
    }

    if(tamanho > 15){
        printf("Erro: a palavra deve ter no maximo 15 letras.\n");
        return 0;
    }

    for(int i = 0; i < tamanho; i++){
        if(!((palavra[i] >= 'a' && palavra[i] <= 'z') ||
             (palavra[i] >= 'A' && palavra[i] <= 'Z'))){
            printf("Erro: use apenas letras sem acentos ou caracteres especiais.\n");
            return 0;
        }
    }

    return 1;
}


// Escolher sequência
int escolher_sequencia(){
    int opcao;

    printf("\nEscolha a sequencia matematica:\n");
    printf("1 - Progressao Aritmetica (PA)\n");
    printf("2 - Progressao Geometrica (PG)\n");
    printf("3 - Fibonacci\n");
    printf("4 - Numeros Primos\n");
    printf("Opcao: ");

    if(!ler_inteiro(1, 4, &opcao)){
        return -1;
    }

    return opcao;
}


int main(){
    char palavra[128];
    char resultado[16];
    int shift;
    int opcao;
    int tamanho_texto;
    int menu = 0;

    while(menu != 3){
        printf("\n1 - Criptografar\n");
        printf("2 - Descriptografar\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");

        if(!ler_inteiro(1, 3, &menu)){
            break;
        }

        if(menu == 3){
            printf("\nPrograma encerrado.\n");
            break;
        }

        // Pedir palavra novamente se estiver inválida
        while(1){
            printf("\nDigite uma palavra de ate 15 letras: ");

            int status = ler_linha(palavra, sizeof(palavra));

            if(status == 0){
                printf("\nEntrada encerrada.\n");
                return 0;
            }

            if(status == -1){
                printf("Entrada muito longa. Tente novamente.\n");
                continue;
            }

            if(palavra_valida(palavra)){
                break;
            }
        }

        printf("Digite o SHIFT (0 a 1000000): ");

        if(!ler_inteiro(0, 1000000, &shift)){
            break;
        }

        opcao = escolher_sequencia();

        if(opcao == -1){
            break;
        }

        tamanho_texto = strlen(palavra);

        int *sequencia = malloc(tamanho_texto * sizeof(int));

        if(sequencia == NULL){
            printf("Erro de alocacao de memoria.\n");
            continue;
        }

        if(!gerar_sequencia(sequencia, tamanho_texto, opcao)){
            printf("Erro ao gerar a sequencia.\n");
            free(sequencia);
            continue;
        }

        if(menu == 1){
            criptografar(palavra, resultado, shift,
                         sequencia, tamanho_texto);

            printf("\n--- RESULTADO ---\n");
            printf("Palavra original: %s\n", palavra);
            printf("Palavra criptografada: %s\n", resultado);
        }else{
            descriptografar(palavra, resultado, shift,
                            sequencia, tamanho_texto);

            printf("\n--- RESULTADO ---\n");
            printf("Palavra criptografada: %s\n", palavra);
            printf("Palavra original: %s\n", resultado);
        }

        FILE *arquivo = fopen("resultado_criptografia.txt", "a");

        if(arquivo == NULL){
            printf("Erro ao abrir o arquivo de log.\n");
        }else{
            if(menu == 1){
                fprintf(arquivo,
                    "[CRIPTOGRAFIA] Original: %s | Resultado: %s | SHIFT: %d | Tipo: %d | Letras: %d\n",
                    palavra, resultado, shift, opcao, tamanho_texto);
            }else{
                fprintf(arquivo,
                    "[DESCRIPTOGRAFIA] Entrada: %s | Resultado: %s | SHIFT: %d | Tipo: %d | Letras: %d\n",
                    palavra, resultado, shift, opcao, tamanho_texto);
            }

            fclose(arquivo);
            printf("\nRegistro salvo no arquivo de log.\n");
        }

        free(sequencia);

        printf("\nOperacao concluida!\n");
        printf("Voltando ao menu principal...\n");
    }

    return 0;
}
