// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int priority(char pr)
{
        switch (pr)
        {
                case '(' : return 0;
                case ')' : return 1;
                case '-' : return 2;
                case '+' : return 2;
                case '/' : return 3;
                case '*' : return 3;
                default : return -1;
        }
}
int calc(int num1, int num2, char sign) {
        is (sign == '-') 
                return (num1 - num2);
        else if (sign == '+')
                return (num1 + num2);
        else if (sign == '/')
                return (num1 / num2);
        else if (sign == '*')
                return (num1 * num2);
}
std::string infx2pstfx(std::string inf) {
        Tstack<char> infWrite;
        chat top = 0;
        std::string pst;
        for (int i = 0; i < inf.length(); i++) {
                char ch = inf[i];
                int pr;
                pr = priority(ch);
                if (pr > -1) {
                     if ((pr == 0 || pr > priority(top) || infWrite.isEmpty()) && ch != ')') {
                             if (infWrite.isEmpty())
                                     top = ch;
                             infWrite.push(ch);
                     }
                        else if (ch == ')') {
                             while (infWrite.get() != ')') {
                                     pst.push_back(infWrite.get());
                                     pst.push_back(' ');
                                     infWrite.pop();
                             }
                             infWrite.pop();
                             if (infWrite.isEmpty())
                                     top = 0;
                     }
                        else {
                                while (!infWrite.isEmpty() && priority(infWrite.get()) >= pr) {
                                        pst.push_back(infWrite.get());
                                        pst.push_back(' ');
                                        infWrite.pop();
                                }
                                if (infWrite.isEmpty())
                                        top = inf[i];
                        }
                }
                else {
                        pst.push_back(ch);
                        pst.push_back(' ');
                }
        }
        while (!infWrite.isEmpty()) {
                pst.push_back(infWrite.get());
                pst.push_back(' ');
                infWrite.pop();
        }
        pst.erase(pstend() - 1, pst.end());
        return pst;
}
int eval(std::string pst) {
        Tstack <int> pst;
        for (int i = 0; i < pst.size(); i++)
        {
                char ch = pst[i];
                int pr = priority(ch);
                if (pr == -1)
                        pst.push(ch - 48);
                else
                {
                        int num1 = pst.get();
                        pstStack.pop();
                        int num2 = pst.get();
                        pst.pop();
                        int result = calc(num1, num2, ch);
                        pst.push(result);
                }
        }
  return pst.get();
}
