#ifndef MENU_H_INCLUDE
#define MENU_H_INCLUDE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
#define max 3
#define names 50

typedef struct Data//Estrutura de data
{
    int dia,mes,ano;
}data;
typedef struct Despesa//Estrutura de despesas
{
    float salario_dev,hrextra,
    deslocReunioes,outrosGastos,receitaDoProjeto;
}despesa;
typedef struct projeto//Projetos da empresa
{
    int codigo;
    char gerente[names];
    char cliente[names];
    data datapj;
    despesa despesas;
}prjt;
void controle (prjt pjt[]){//Funcao para retornar ao Menu ou sair
    setlocale(LC_ALL,"portuguese");
    int contrl= 0;
    printf("\nDigite o número correspondente ao comando para executá-lo!\n");
    printf("\n1-Retornar ao menu inicial\n2-Sair do Programa\n\n");
    scanf("%d",&contrl);
        if((contrl>2)||(contrl<1))
    {
        printf("\nOps não conheço essa opção...\nDigite uma opção válida!!\n\n");
        system("pause");
    }
    switch (contrl)
    {
        case 1: menu(pjt);
        break;
        case 2: system("cls");
                printf("\nAté mais!!!\n \n");
                system("pause");
                exit(1);
        break;
        default: system("cls");
            controle(pjt);
        break;
    }
}

void inserirPj (prjt pjt[]){//Funcao para inserir projeto
    setlocale(LC_ALL,"portuguese");
    int i;
    for (i=0;i<max;i++)
    {
    system("cls");
    pjt[i].codigo=i+1;
    printf("\nEste Projeto é o de código número: %d .",pjt[i].codigo);
    char gerente[100];
    do{
        printf("\nDigite o nome do(a) Gerente:\n");
        fflush(stdin);
        gets(gerente);
        if(strlen(gerente)>50)
        {
            printf("\nAbrevie o nome (máximo de 50 caracteres)!\n");
        }
    }while(strlen(gerente)>50);
    strcpy(pjt[i].gerente,gerente);

    char cliente[100];
    do
    {
        printf("\nDigite o nome do(a) Cliente:\n");
        fflush(stdin);
        gets(cliente);
        if(strlen(cliente)>50)
        {
            printf("\nAbrevie o nome (maximo de 50 caracteres)\n");
        }
    }while(strlen(cliente)>50);
    strcpy(pjt[i].cliente,cliente);

    printf("\nInsira a data de previsão de entrega do projeto\n");
    scanf("%d %d %d",&pjt[i].datapj.dia,&pjt[i].datapj.mes,&pjt[i].datapj.ano);

    system("pause");
    system("cls");

    printf("\nEste Projeto é o de codigo número: %d .",pjt[i].codigo);
    printf("\nAgora vamos para as despesas do projeto.");

    printf("\n \nDigite o salário dos desenvolvedores: ");
    scanf("%f",&pjt[i].despesas.salario_dev);

    printf("\nDigite o valor gasto em horas extras: ");
    scanf("%f",&pjt[i].despesas.hrextra);

    printf("\nDigite o valor do deslocamento para as reuniões: ");
    scanf("%f",&pjt[i].despesas.deslocReunioes);

    printf("\nDigite os outros gastos do Projeto: ");
    scanf("%f",&pjt[i].despesas.outrosGastos);

    printf("\nDigite o valor da receita do Projeto: ");
    scanf("%f",&pjt[i].despesas.receitaDoProjeto);
    system("cls");
    }
    system("cls");
    printf("\nVoce inseriu todos os projetos agora será direcionado ao menu!\n \n");
    system("pause");
}

void opcao1 (prjt pjt[]){//Feito...O lucro Total dos projetos em andamento...
    system("cls");
    setlocale(LC_ALL,"portuguese");
    float lucro=0;
    int i;
    for ( i = 0; i < max; i++)
    {
        lucro=lucro+((pjt[i].despesas.receitaDoProjeto)-(pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev));
    }
    printf("\nO lucro de todos os projetos em andamentos: R$%.2f \n \n",lucro);
    system("pause");
    system("cls");
    controle(pjt);
}

void opcao2 (prjt pjt[]){//Feito...Quantos projetos estão atrasados
    system("cls");
    setlocale(LC_ALL,"portuguese");
    int i,cont=0;
    data data_atual ;
    printf("Digite o dia/mes/ano neste formato (00 00 0000) para fazer a pesquisa dos projetos atrasados\n");
    scanf("%d %d %d", &data_atual.dia, &data_atual.mes, &data_atual.ano);
    for(i=0;i<max;i++){
        if(data_atual.ano<pjt[i].datapj.ano)
        {
            printf("\nEste projeto de codigo %d está atrasado do(a) gerente : %s.\n",pjt[i].codigo,pjt[i].gerente);
            cont++;
        }else if(data_atual.mes<pjt[i].datapj.mes)
        {
            printf("\nEste projeto de codigo %d está atrasado do(a) gerente : %s.\n",pjt[i].codigo,pjt[i].gerente);
            cont++;
        }else if(data_atual.dia<pjt[i].datapj.dia)
        {
            printf("\nEste projeto de codigo %d está atrasado do(a) gerente : %s.\n",pjt[i].codigo,pjt[i].gerente);
            cont++;
        }
    }
    switch (cont)
    {
    case 0: printf("\nNenhum projeto atrasado.\n \n");
        break;
    case 1: printf("\nSomente %d projeto com atraso.\n \n",cont);
        break;
    default: printf("\nNo total são %d projetos com atraso\n \n",cont);
        break;
    }
    system("pause");
    system("cls");
    controle(pjt);
}

void opcao3 (prjt pjt[]){//Funcionando...Feito...O código do pjt e o nome do gerente do pjt com maior gasto com horas extras
    system("cls");
    setlocale(LC_ALL,"portuguese");
    int i=0,pos=0;
    float maior=0;
    maior=pjt[i].despesas.hrextra;
    for ( i = 1; i < max; i++)
    {
        if(maior<pjt[i].despesas.hrextra)
        {
            maior=pjt[i].despesas.hrextra;
            pos=i;
        }
    }

    printf("\nO projeto com maior gasto em horas extras é o projeto de código número: %d.\nE o seu gerente é : %s\n \n",pjt[pos].codigo,pjt[pos].gerente);

    system("pause");
    system("cls");
    controle(pjt);
}

void opcao4 (prjt pjt[]){//Funcionando...Feito...O código do pjt e o nome do gerente com o pjt com maior gasto total
    system("cls");
    setlocale(LC_ALL,"portuguese");
    int i=0,pos=0;
    float gastottl=0,compare=0;
    gastottl=pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev;
    for  (i=1;i<max;i++)
    {
        compare=pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev;
        if(compare>gastottl)
        {
            gastottl=compare;
            pos=i;
        }
    }
    printf("\nO projeto com maior gasto total é o projeto de código número: %d.\nE o seu gerente é : %s\n \n",pjt[pos].codigo,pjt[pos].gerente);

    system("pause");
    system("cls");
    controle(pjt);
}

void opcao5 (prjt pjt[]){//Funcionando...Dado o nome de um gerente:Código do projeto,Cliente,Data prevista de Entrega,Lucro
    system("cls");
    setlocale(LC_ALL,"portuguese");
    int i,retorno=0,cont=0;
    char gerente[100];

    printf("\nDigite o nome do Gerente:\n");
    fflush(stdin);
    gets(gerente);
    for (i=0;i<max;i++)
    {
        retorno=strcmp(gerente,pjt[i].gerente);
        if(retorno==0){
            cont++;
            printf("\nEste é o projeto de número: %d\n\nNome do(a) cliente: %s.\nData prevista de entrega: %d/%d/%d\nO lucro deste projeto é cerca de R$%.2f reais.\n \n",pjt[i].codigo,pjt[i].cliente,pjt[i].datapj.dia,pjt[i].datapj.mes,pjt[i].datapj.ano,((pjt[i].despesas.receitaDoProjeto)-(pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev)));
        }
    }
    if(cont==0){
        printf("\nOps não achei este gerente!!\n \n");

    }
    system("pause");
    system("cls");
    controle(pjt);
}

void opcao6 (prjt pjt[]){//Funcionando...Dado o nome do cliente imprimir:Código do projeto,Gerente,Data prevista de Entrega,Custo Total
    system("cls");
    setlocale(LC_ALL,"portuguese");
    int i,retorno=0,cont=0;
    char cliente[100];

        printf("\nDigite o nome do Cliente:\n");
        fflush(stdin);
        gets(cliente);
        for (i=0;i<max;i++)
        {
            retorno=strcmp(cliente,pjt[i].cliente);
            if(retorno==0){
                cont++;
                printf("\nEste é o projeto de número: %d\n\nNome do(a) gerente: %s .\nData prevista de entrega: %d/%d/%d\nO custo deste projeto é cerca de R$%.2f reais.\n \n",pjt[i].codigo,pjt[i].gerente,pjt[i].datapj.dia,pjt[i].datapj.mes,pjt[i].datapj.ano,((pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev)));
            }
        }
        if(cont==0){
            printf("\nOps não achei este cliente!!\n");
        }
    system("pause");
    system("cls");
    controle(pjt);
}

void menu (prjt pjt[]){//Menu inicial
    setlocale(LC_ALL,"portuguese");
    int comando=0;
    system("cls");
    printf("\nDigite o número correspondente ao comando para executá-lo!\n");
    printf("\n1-Lucro total dos projetos em andamento.\n2-Projetos atrasados\n3-Projeto com maior gasto com horas extras.\n4-Projeto de maior gasto\n5-Pesquisa por gerencia\n6-Pesquisa por cliente\n7-Sair\n");
    scanf("%d",&comando);
    if((comando>7)||(comando<1))
    {
        printf("\nOps acho que não conheco essa opção...\nDigite uma opção válida!!\n\n");
        system("pause");
    }
    switch (comando)
    {
        case 1: opcao1(pjt);
        break;
        case 2: opcao2(pjt);
        break;
        case 3: opcao3(pjt);
        break;
        case 4: opcao4(pjt);
        break;
        case 5: opcao5(pjt);
        break;
        case 6: opcao6(pjt);
        break;
        case 7: system("cls");
                printf("\nAté mais!!!\n \n");
                system("pause");
                exit(1);
        break;
        default:menu(pjt);
        break;
    }
}

#endif
