#include "TXLib.h"
   struct  Picture
   {
    int x  ;
    int y ;
    int shirina;
    int vasota;
    HDC pic;
   };

   void drawPic (Picture vk)
   {
    txBitBlt(txDC(), vk.x, vk.y, vk.shirina, vk.vasota, vk.pic);
   }

bool knopka(int x, int y)
{
    if (txMouseX() > x and
          txMouseX() < x + 120 and
          txMouseY() > y and
          txMouseY() < y + 50 and
          txMouseButtons() &1)
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
	const char* textMessage;

void drawButton()
{
			txDrawText(x,y,x2,y2,text);
}

void showMessage()
{
			if (knopka(x,y)and textMessage != "" )
			{
				txMessageBox(textMessage);
			}
}
};




int main()
{
    txCreateWindow (1200, 800);

    HDC  brick= txLoadImage ("Pics\\Wall\\brick.bmp");
    HDC wood = txLoadImage ("Pics\\Wall\\wood.bmp");
    HDC  background  = txLoadImage ("Pics\\��� 2.bmp");

    bool exitProgram = false;

    int pageNumber = 0;

    Knopka b[5];
    b[0] = {530,270,650,320,"������","" };
    b[1] = {530,320,650,370,"����������", "��������"};
    b[2] = {530,370,650,420,"���������", "��������� ����������"};
    b[3] = {530,420,650,470,"����������","C����� �����"};
    b[4] = {530,470,650,520,"�����",""};


    while(!exitProgram)
    {
        txBegin();

        if (pageNumber == 0)
        {
			txBitBlt (txDC(), 0, 0, 1200, 800, background, 0, 0);
			txSetFillColor(TX_WHITE);
			txSetColor(TX_WHITE);
			/*Win32::RoundRect (txDC(), 450, 230, 750,730,50,50); */

			txSelectFont("Arial", 40);
			txDrawText(300,100,900,150,"������ ���� ��������");



		for (int n = 0;   n < 5; n++)
		  {
			b[n].drawButton();
			b[n].showMessage();
			}



			if(knopka(b[0].x + 20,b[0].y))
			{
				 pageNumber = 1;
			}
			if (knopka(b[4].x + 20,b[4].y))
			{
				exitProgram = true;
			}
		}

        /* txSetFillColor (TX_YELLOW);

        txRectangle (425, 270, 775, 382); */

        if (pageNumber == 1 )
        {

				txSetFillColor (TX_GRAY);
				txRectangle ( 10 , 100 , 1200 - 150 , 800 - 2 );


				txDrawText(55,20,180,70,"������");
			if(knopka(55,20))
          {
          }

			txDrawText(255,20,380,70,"�����");
			if(knopka(240,40))
			{
			 }

			txDrawText(455,20,580,70,"�����");
			if(knopka(440,40))
			{
			 }

			txDrawText(655,20,780,70,"�������");
			if(knopka(640,40))
			{
			 }

			txDrawText(855,20,980,70,"�����");
			if(knopka(840,40))
			{
			}

			  /*
				HDC  pic = txLoadImage ("Pics\\Furniture\\����� 1.bmp");
				Win32::TransparentBlt (txDC(), 1090, 110, 75, 190, pic, 0, 0, 185, 451, TX_WHITE);
				txDeleteDC(pic);

				HDC  pic2 = txLoadImage ("Pics\\Furniture\\����� 2.bmp");
				Win32::TransparentBlt (txDC(), 1090, 320, 75, 190, pic2, 0, 0, 185, 451, TX_WHITE);
				txDeleteDC(pic2);

				HDC  pic3 = txLoadImage ("Pics\\Furniture\\����� 3.bmp");
				Win32::TransparentBlt (txDC(), 1060, 540, 120, 60, pic3, 0, 0, 451, 185, TX_WHITE);
				txDeleteDC(pic3);

				HDC  pic4 = txLoadImage ("Pics\\Furniture\\����� 4.bmp");
				Win32::TransparentBlt (txDC(), 1060, 630, 120, 60, pic4, 0, 0, 451, 185, TX_WHITE);
				txDeleteDC(pic4);
								   */

				Win32::TransparentBlt (txDC(), 1060, 630, 100, 100, brick, 0, 0, 100, 100, TX_WHITE);

				Win32::TransparentBlt (txDC(), 1060, 520, 100, 100, wood, 0, 0, 100, 100, TX_WHITE);
        }



        txSleep(10);
        txEnd();



    }

    txDisableAutoPause();
    txDeleteDC(background);


    txDeleteDC(brick);
    txDeleteDC(wood);

    return 0;
}
