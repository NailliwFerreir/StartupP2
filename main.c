#include "dadosFixos.h"
#include "menu.h"
#define max 3// ou 30
#define names 50

int main (){
    system("cls");
    prjt projetos[max];
    toTest(projetos);//para inserir dados fixos da biblioteca
    //inserirPj(projetos);//função para inserir no terminal manualmente
    menu(projetos);
    return 0;
}
