#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"
#include "files.cpp"

//integer constant that mean lenght of pictures array
const int PICT_LEN = 14;
const int START_PAGE = 0;

void drawPeremennya(int x, int y, int perem)
{
	char str[100];
	sprintf(str, "%d", perem);
	txTextOut(x, y, str);
}
void drawPeremennya(int x, int y, bool perem)
{
	if (perem == true)
		txTextOut(x, y, "true");
	else
		txTextOut(x, y, "true");
}

int main()
{
    txCreateWindow(1200, 800);
    HDC background = txLoadImage("Pics\\Background2.bmp");

    const int VARIANTS_WIDTH = 150;

    bool exitProgram = false;
    int last_num_obj = 0;
    int bylo_kartinok = 0;

    char* selected_category = "";
    int pageNumber = 0;

    Picture kartinkaVCentreEkrana[1000];

    Picture pic[PICT_LEN];
    pic[0] = {1090, 110,  75, 190, "Pics\\Furniture\\Divan1.bmp",  "Divan"};
    pic[1] = {1090, 320,  75, 190, "Pics\\Furniture\\Divan2.bmp",  "Divan"};
    pic[2] = {1090, 110,  75, 190, "Pics\\Cover\\Cover1.bmp",      "Cover"};
    pic[3] = {1090, 320,  75, 190, "Pics\\Cover\\Cover3.bmp",      "Cover"};
    pic[4] = {1070, 580, 120,  50, "Pics\\Furniture\\Divan3.bmp",  "Divan"};
    pic[5] = {1070, 640, 120,  50, "Pics\\Furniture\\Divan4.bmp",  "Divan"};
    pic[6] = {1090, 110, 100, 100, "Pics\\Furniture\\������1.bmp", "Chair"};
    pic[7] = {1090, 220, 100, 100, "Pics\\Furniture\\������2.bmp", "Chair"};
    pic[8] = {1090, 330, 100, 100, "Pics\\Furniture\\������3.bmp", "Chair"};
    pic[9] = {1090, 440, 100, 100, "Pics\\Furniture\\Stul1.bmp",   "Chair"};
    pic[10] ={1090, 550, 100, 100, "Pics\\Furniture\\Stul2.bmp",   "Chair"};
    pic[11] ={1090, 110,  75,  75, "Pics\\Wall\\brick.bmp",        "Wall"};
    pic[12] ={1090, 320,  75,  75, "Pics\\Wall\\mel.bmp",          "Wall"};
    pic[13] ={1090, 580,  75,  75, "Pics\\Wall\\wood.bmp",         "Wall"};

    for (int i = 0; i < PICT_LEN; i++)
    {
		pic[i].img = txLoadImage(pic[i].adress.c_str());
		pic[i].src_shirina = get_width(pic[i].adress.c_str());
		pic[i].src_vasota=get_height (pic[i].adress.c_str());
		pic[i].visible = true;
    }
    /*int sum = 0;
    for (int i = 0; i < PICT_LEN; i++)
    {
        if (pic[i].category == "Cover")
        sum = sum+1;
    }
    int nomer = 0;
    for (int i = 0; i < PICT_LEN; i++)
    {
        if (pic[i].category == "Cover")
        {
            pic[i].x =  100 + 600 * sum
            nomer = nomer+1;
        }
    }

    cout << sum;
    txSleep(1000);
    */
    Knopka mainMenu[6];
    mainMenu[0] = {500, 270, 680, 320, "������"};
    mainMenu[1] = {500, 320, 680, 370, "����������"};
    mainMenu[2] = {500, 370, 680, 420, "���������",  "��������� ����������", "������"};
    mainMenu[3] = {500, 420, 680, 470, "����������", "C����� �����",        "�����"};
    mainMenu[4] = {500, 470, 680, 520,  "�����"};

    Knopka topMenu[6];
    topMenu[0] = {55,20,180,70,"������","Divan" };
    topMenu[1] = {255,20,380,70,"�����", "Divan"};
    topMenu[2] = {455,20,580,70,"�����", "Wall"};
    topMenu[3] = {655,20,780,70,"������","Chair"};
    topMenu[4] = {855,20,980,70,"�����","Cover"};
    topMenu[5] = {1055,20,1180,70,"�����",""};



    int vybrannaya_kartinka  = -100;
    while(!exitProgram)
    {
        txBegin();

        if (pageNumber == START_PAGE)
        {
            txBitBlt (txDC(), 0, 0, 1200, 800, background, 0, 0);
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);

            txSelectFont("Arial", 40);
            txDrawText(300,100,900,150,"������ ���� ��������");

            for (int n = 0; n < 5; n++)
            {
                mainMenu[n].drawButton();
                mainMenu[n].showMessage();
            }

            if (knopka(mainMenu[0].x + 20,mainMenu[0].y))
            {
                pageNumber = 1;
            }
            if (knopka(mainMenu[4].x + 20,mainMenu[4].y))
            {
                exitProgram = true;
            }
            //continued
            if (knopka(mainMenu[1].x + 20,mainMenu[1].y))
            {
                last_num_obj = bylo_kartinok;
                pageNumber = 1;
            }
        }

        if (pageNumber == 1)
        {
            //mouse
            for (int i = 0; i < last_num_obj ; i++)
            {
                if (kartinkaVCentreEkrana[vybrannaya_kartinka].knopka2())
                {
                    kartinkaVCentreEkrana[vybrannaya_kartinka].clickedBlock = true;
                }

                if ((txMouseButtons() & 1) && kartinkaVCentreEkrana[i].clickedBlock)
                {
                    kartinkaVCentreEkrana[vybrannaya_kartinka].x = txMouseX() - kartinkaVCentreEkrana[vybrannaya_kartinka].shirina/2;
                    kartinkaVCentreEkrana[vybrannaya_kartinka].y = txMouseY() - kartinkaVCentreEkrana[vybrannaya_kartinka].vasota/2;

                    drawPic(kartinkaVCentreEkrana[i]);
                }

                if (!(txMouseButtons() & 1) && kartinkaVCentreEkrana[i].clickedBlock)
                {
                   kartinkaVCentreEkrana[vybrannaya_kartinka].clickedBlock = false;
                   vybrannaya_kartinka = -10 ;
                }
            }


       //granica
         for (int i = 0; i < last_num_obj ; i++)
         {
                  if (kartinkaVCentreEkrana[i].x < 10)
                  {
                   kartinkaVCentreEkrana[i].x = 10 ;
                  }
                  if (kartinkaVCentreEkrana[i].y < 100)
                  {
                  kartinkaVCentreEkrana[i].y = 100;
                   }
                  if (kartinkaVCentreEkrana[i].x + kartinkaVCentreEkrana[i].shirina > 1000)
                   {
                   kartinkaVCentreEkrana[i].x = txGetExtentX()- VARIANTS_WIDTH - kartinkaVCentreEkrana[i].shirina;
                   }
                  if (kartinkaVCentreEkrana[i].y + kartinkaVCentreEkrana[i].vasota > txGetExtentY())
                  {
                  kartinkaVCentreEkrana[i].y = txGetExtentY()- kartinkaVCentreEkrana[i].vasota;
                  }
        }

            txBitBlt(txDC(), 0, 0, txGetExtentX(), 800, background, 0, 0);

            txSetFillColor(TX_GRAY);
			txSetColor(TX_WHITE);
            txRectangle(10, 100, 1200 - VARIANTS_WIDTH, txGetExtentY() - 2);

            if (knopka(1200 - VARIANTS_WIDTH,30))
            {
               pageNumber = START_PAGE;
               bylo_kartinok = last_num_obj;
               last_num_obj = 0;
            }

            //peremeshenie
           for(int i = 0; i < last_num_obj; i++)
           {
            if(kartinkaVCentreEkrana[i].knopka2())
            {
              vybrannaya_kartinka = i;
            }
           }

           if(vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_LEFT))
           {
            kartinkaVCentreEkrana[vybrannaya_kartinka].x -= 3;
           }

           if(vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_RIGHT))
           {
            kartinkaVCentreEkrana[vybrannaya_kartinka].x += 3;
           }
           if(vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_UP))
           {
            kartinkaVCentreEkrana[vybrannaya_kartinka].y -= 3;
           }
           if(vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_DOWN))
           {
            kartinkaVCentreEkrana[vybrannaya_kartinka].y += 3;
           }

           if(vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_DELETE))
           {
            kartinkaVCentreEkrana[vybrannaya_kartinka] = kartinkaVCentreEkrana[last_num_obj - 1];
            last_num_obj -= 1 ;
            vybrannaya_kartinka = - 100 ;
           }



            //Top buttons
            for (int n = 0; n < 6; n++)
            {
				txSetColor(TX_WHITE);
                if (topMenu[n].textMessage == selected_category)
                {
				txSetColor(TX_RED);
                }
                topMenu[n].drawButton();
            }

            //Right pictures�
            for (int i = 0; i < PICT_LEN; i++)
            {
                if (pic[i].category == selected_category)
                {
                    drawPic(pic[i]);
                }
            }

            for (int i = 0; i < last_num_obj; i++)
            {
                if (kartinkaVCentreEkrana[i].visible)
                {
                if (i == vybrannaya_kartinka)
                {
                Picture vk = kartinkaVCentreEkrana[i];

                txSetColor(TX_RED, 3);
					txRectangle (vk.x-2, vk.y-2, vk.x + vk.shirina+2, vk.y + vk.vasota+2);
                }
                    drawPic(kartinkaVCentreEkrana[i]);
                }
            }

            for (int n = 0; n < 5; n++)
            {
                if (knopka(topMenu[n].x,topMenu[n].y))
                {
                    selected_category = topMenu[n].textMessage;
                }
            }

            for (int i = 0; i < PICT_LEN; i++)
            {
                if (selected_category == pic[i].category and pic[i].knopka())
                {
                    int x = random (10,  1050 - pic[i].shirina);
                    int y = random (100, 800 - pic[i].vasota);

                    kartinkaVCentreEkrana[last_num_obj] = {
                        x,
                        y,
                        pic[i].shirina,
                        pic[i].vasota,
                        pic[i].adress,
                        pic[i].category,
                        pic[i].img,
                        pic[i].src_shirina,
                        pic[i].src_vasota,
                        true
                    };

                    last_num_obj++;
                }
            }

            if (GetAsyncKeyState(VK_ESCAPE))
            {
                exitProgram = true;
            }
        }
        /*
       drawPeremennya(100,100,kartinkaVCentreEkrana[0].src_shirina );
       drawPeremennya(200,100,kartinkaVCentreEkrana[0].clickedBlock );

       drawPeremennya(100,140,kartinkaVCentreEkrana[1].src_shirina );
       drawPeremennya(200,140,kartinkaVCentreEkrana[1].clickedBlock );
           */

        txSleep(10);
        txEnd();
    }

    txDisableAutoPause();
    txDeleteDC(background);

    for (int i = 0; i < PICT_LEN; i++)
    {
        txDeleteDC(pic[i].img);
    }

    return 0;
}
