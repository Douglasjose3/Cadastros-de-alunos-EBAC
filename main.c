#include <stdio.h> //Biblioteca de comunicação com o usuário.
#include <stdlib.h> //Biblioteca de alocação de espaços em memória.
#include <locale.h> //Biblioteca de alocação de textos por região.
#include <string.h> //Biblioteca responsável por cuidar das strings.

int registrar() { //Funcão responsável por cadastrar os ususários no sistema.
    char arquivo[500]; //Inicio da criação de variáveis/string.
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char profissão[40];
    char observação[500]; //Final da criação de variáveis/string.

    printf("Digite o CPF para cadastro: "); //Coletando as informações do usuário.
    scanf("%s", cpf); //Salva as informações da string.

    strcpy(arquivo, cpf); //Responsável por copiar os valores das strings.

    FILE *file; //Cria o arquivo.
    file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever.

    file = fopen(arquivo, "a");
    fprintf(file, "CPF: ");

    fprintf(file, cpf); //Salvar o valor da variável.
    fclose(file); //Fecho o arquivo.

    file = fopen(arquivo, "a"); //Virgula ou separação entre as informações.
    fprintf(file, " | Nome: ");
    fclose(file);

    printf("Digite o NOME para cadastro! ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a"); //Virgula
    fprintf(file, " | Sobrenome: ");
    fclose(file);

    printf("Digite o SOBRENOME para cadastro! ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, " | Profissão: ");
    fclose(file);

    printf("Digite a PROFISSÃO para cadastro! ");
    scanf("%s", profissão);

    file = fopen(arquivo, "a");
    fprintf(file, profissão);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, " | Observação: ");
    fclose(file);

    printf("OBSERVAÇÃO!\n");
    scanf("%s", observação);

    file = fopen(arquivo, "a");
    fprintf(file, observação);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ".");
    fclose(file);

    getchar();

}

int consultar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF do aluno: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL){
        printf("Não foi possível localizar essa informação!");
    }

    while (fgets(conteudo, 200, file) != NULL){ //while: enquanto tiver.
        printf("\nEssas são as informações do usuário:\n");
        printf("%s", conteudo);
        printf("\n\n");
    }

    getchar();
}

int deletar() {
    char cpf[40];

    printf("Digiete o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL){
        printf("\n\nO Usuário foi deletado com sucesso!\n\n");
        getchar();
        system("clear");
    }

}

int main() {
    int senha, senhaValida = 123456;

    printf("Digite sua senha: ");
    scanf("%d", &senha);

    while (senha != senhaValida){ //Enquanto senha for diferente (!=) de senhaValida.
        printf("Senha invalida!\n\nDigite novamente a senha correta: ");
        scanf("%d", &senha);
    }

    printf("Seja ben vindo ao menu principal!\n");

    int opcao=0; //Definindo a variável
    int laco=1;

    for(laco=1;laco=1;) {
        system("clear"); //Limpa todas as msgs anteriores, usar clear no lugar de cls.
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.

        printf("Olá! Bem vindo a Central de Cadastros da EBAC.\n"); //Início do menu.
        printf("\nEscolha a opção desejada no menu:\n\n");
        printf("\t1 - Registro de novos alunos.\n");
        printf("\t2 - Consultar cadastros dos ativos e inativos.\n");
        printf("\t3 - Deletar cadastros inativos.\n");
        printf("\n Digite aqui a opção: "); //Fim do menu.

        scanf("%d", &opcao); //Armazenando a esolha do usuário.
        system("clear"); //Limpa todas as msgs anteriores, usar clear no lugar de cls.

        switch(opcao) { //Início do menu.
            case 1:
            registrar(); //chamada de funções.
            break;
            case 2:
            consultar();
            break;
            case 3:
            deletar();
            break;

            default:
                printf("\nEssa opção não está disponível!\n\n");
                getchar();
        } //Fim do menu.
    }
}
