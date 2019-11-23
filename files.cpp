#pragma once
#include <string>
#include <fstream>
#include "TXLib.h"
#include "Windows.h"

using namespace std;


string selectFile(HWND hWnd)
{
	const int SIZE = 100;
	char nameFile[SIZE];
	OPENFILENAMEA ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = nameFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = SIZE;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_CREATEPROMPT;

	GetOpenFileNameA(&ofn);
	return nameFile;
}

int get_height(string adress)
{
    unsigned char info[54];
    FILE* f = fopen(adress.c_str(), "rb");
    fread(info, sizeof(unsigned char), 54, f);
    int height = *(int*)&info[22];

    return height;
}

int get_width(string adress)
{
    unsigned char info[54];
    FILE* f = fopen(adress.c_str (), "rb");
    fread(info, sizeof(unsigned char), 54, f);
    int width = *(int*)&info[18];


    return width;
}




int readFromFile(Picture kartincaUP[])
{
    int last_num_obj = 0;
    setlocale(0,"");
	string filename = selectFile(txWindow());
    ifstream file (filename);
    string stroka_x;
    string stroka_y;
    string stroka_adress;






    while (file.good())
    {
        getline(file,stroka_x);

        if (stroka_x.size() > 1)
        {
            getline(file,stroka_y);
            getline(file,stroka_adress);

             kartincaUP[last_num_obj] = {
                stroka_adress,
                atoi(stroka_x.c_str()),
                atoi(stroka_y.c_str()),
                0,
                0,
                "",
                txLoadImage(stroka_adress.c_str()),
                0,
                0,
                true
            };
            last_num_obj = last_num_obj + 1;
        }
    }

    file.close();


    return last_num_obj;
}

 void saveToFile(int last_num_obj, Picture kartincaUP[])
 {
    ofstream file1 ("123.txt");

    for (int i = 0; i < last_num_obj; i++)
    {
        file1 << kartincaUP[i].x << endl;
        file1 << kartincaUP[i].y << endl;
         file1 << kartincaUP[i].adress << endl;
     }

    file1.close();
}

