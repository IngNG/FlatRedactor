#include "TXLib.h"

bool knopka(int x, int y)
{
    if (txMouseX() > x       and
        txMouseX() < x + 180 and
        txMouseY() > y       and
        txMouseY() < y + 50  and
        txMouseButtons() & 1)
    {

        return true;
    }

    return false;
}

struct Knopka
{
	int x;
	int y;
	int x2;
	int y2;
	const char* text;
	string textMessage;
	const char* headerMessage;

    void drawButton()
    {
        txDrawText(x, y, x2, y2, text);
    }

    void showMessage()
    {
        if (knopka(x,y) and textMessage != "")
        {
            if (headerMessage != "" and headerMessage != nullptr)
            {
                txMessageBox(textMessage.c_str(), headerMessage);
            }
            else
            {
                txMessageBox(textMessage.c_str());
            }
        }
    }
};

void risovatKnopki(const int COLICHEs, Knopka topMenu[],string selected_category)
{
        for (int n = 0; n < COLICHEs; n++)
        {
            txSetColor(TX_WHITE);
            if (topMenu[n].textMessage == selected_category)
            {
                txSetColor(TX_RED);
            }
            topMenu[n].drawButton();
        }
}
