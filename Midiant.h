#ifndef __MIDIANT__H__
#define __MIDIANT__H__


#include <stdlib.h>

class Midiant{
    public:
    int pot,btn;
    Midiant(int btn);
    Midiant(int btn, int pot);
    typedef void (click)(void);//Função de callback para a função BtnClick
    typedef void clickParam(int i);
    void Btn(clickParam* cb);//Função BtnClick que irá clicar de forma correta
    void Pot(clickParam* cb);
    void BtnCB(click* cb);
    
    
    private:
    bool ativa,desativa,aNot,dNot;
    int btnSize;
    int validaPot,valCompare;

    
};
#endif  //!__MIDIANT__H__