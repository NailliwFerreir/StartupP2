#include "dadosFixos.h"
#include "menu.h"
#define names 50

int main (){
    prjt projetos[max];
    /*substituir inserirPj() por toTest() para mudar p/ os dados fixos da biblioteca dadosFixos */
    inserirPj(projetos);//toTest(projetos);
    menuPrincipal(projetos);
    return 0;
}
