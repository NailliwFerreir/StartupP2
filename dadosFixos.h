#ifndef DADOS_H_INCLUDE
#define DADOS_H_INCLUDE
#include "menu.h"
//substituir pela quantidade de projetos fixos criados
void toTest(prjt pjt[max])//ja deixa os projetos criados
{
    int i=0;
    //C?digo do Projeto
    pjt[i].codigo=i+1;
    //Gerente
    strcpy(pjt[i].gerente,"Brasil");
    //Data de entrega prevista para o projeto.
    pjt[i].datapj.dia= 24;
    pjt[i].datapj.mes= 11;
    pjt[i].datapj.ano= 2022;
    //Cliente
    strcpy(pjt[i].cliente,"Servia");
    //Despesas associadas com o projeto, sendo as principais:
    //Sal?rio com Desenvolvedores
    pjt[i].despesas.salario_dev=2000;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=3000;
    //Valor pago para o Deslocamento de reuni?es
    pjt[i].despesas.deslocReunioes=700;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=1500;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=15000;
    i++;
//-------------------------------------------------------------------------------------------------
    //C?digo do Projeto
    pjt[i].codigo=i+1;
    //Gerente
    strcpy(pjt[i].gerente,"Brasil");
    //Data de entrega prevista para o projeto.
    pjt[i].datapj.dia= 28;
    pjt[i].datapj.mes= 11;
    pjt[i].datapj.ano= 2022;
    //Cliente
    strcpy(pjt[i].cliente,"Suica");
    //Despesas associadas com o projeto, sendo as principais:
    //Sal?rio com Desenvolvedores
    pjt[i].despesas.salario_dev=1500;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=900;
    //Valor pago para o Deslocamento de reuni?es
    pjt[i].despesas.deslocReunioes=600;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=150;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=12000;
    i++;
//-------------------------------------------------------------------------------------------------
    //C?digo do Projeto
    pjt[i].codigo=i+1;
    //Gerente
    strcpy(pjt[i].gerente,"Lucia");
    //Data de entrega prevista para o projeto.
    pjt[i].datapj.dia= 4;
    pjt[i].datapj.mes= 12;
    pjt[i].datapj.ano= 2022;
    //Cliente
    strcpy(pjt[i].cliente,"Alunos");
    //Despesas associadas com o projeto, sendo as principais:
    //Sal?rio com Desenvolvedores
    pjt[i].despesas.salario_dev=1700;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=1500;
    //Valor pago para o Deslocamento de reuni?es
    pjt[i].despesas.deslocReunioes=1000;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=120;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=14000;
//-------------------------------------------------------------------------------------------------
}
#endif
