#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<windef.h>
#include<conio.h>
#include <time.h>
#include<thread>
#include<ctime>
#include<mutex>
#include<random>
#include<dos.h> 
#include<CommCtrl.h>
#define ICON_SIZE 80
#define NUMWIDTH 3
#define NUMHEIGHT 5
using namespace std;
HWND desktop;
HWND GetDesktopHandle()//��Ҫ��ȡ������;����ֻ��ȡһ�Σ�ʣ����һ�������Getdesktop������ȡ
{//////////����һ
    HWND DesktopHandle = GetDesktopWindow();
    HWND WorkerWHandle = NULL;
    HWND SHELLDLLDefViewHandle = NULL;
    HWND SysListView32Handle = NULL;
    HWND ProgmanHandle = NULL;
    ProgmanHandle = FindWindowExA(DesktopHandle, NULL, "Progman", NULL);
    SHELLDLLDefViewHandle = FindWindowExA(ProgmanHandle, NULL, "SHELLDLL_DefView", NULL);
    if (SHELLDLLDefViewHandle == NULL) {
        WorkerWHandle = FindWindowExA(DesktopHandle, WorkerWHandle, "WorkerW", NULL);
        SHELLDLLDefViewHandle = FindWindowExA(WorkerWHandle, NULL, "SHELLDLL_DefView", NULL);
        while (SHELLDLLDefViewHandle == NULL && WorkerWHandle != NULL) {
            WorkerWHandle = FindWindowExA(DesktopHandle, WorkerWHandle, "WorkerW", NULL);
            SHELLDLLDefViewHandle = FindWindowExA(WorkerWHandle, NULL, "SHELLDLL_DefView", NULL);
        }
    }
    SysListView32Handle = FindWindowExA(SHELLDLLDefViewHandle, NULL, "SysListView32", NULL);
    return SysListView32Handle;
}


void Gameinit()//��Ϸ��ʼ��������ͼ�꣬
{
    desktop = GetDesktopHandle();
    //��������ʽȡ��/////////////////////////////////////////////////////////////////
    DWORD style = ListView_GetExtendedListViewStyle(desktop, GWL_EXSTYLE);
    if (style & LVS_EX_SNAPTOGRID)
    {
        ListView_SetExtendedListViewStyle(desktop, style & ~LVS_EX_SNAPTOGRID);
    }
    ///////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////��ȡ�ؼ�����
    int iconCount, Width, Height;
    iconCount = SendMessage(desktop, LVM_GETITEMCOUNT, 0, 0);
    //Get  Systemϵͳ
    //   Metrics ������ָ��
    //   SM_CXSCREEN
    // //GetSystemMetrics
    //����ָ����ϵͳָ���ϵͳ�������á�
   // ��ע�⣬ GetSystemMetrics ����������ά�ȶ�������Ϊ��λ��
    Width = GetSystemMetrics(SM_CXSCREEN) * 1.5; //��ȡ��Ļ�ķֱ���(��)
    Height = GetSystemMetrics(SM_CYSCREEN) * 1.5;//���豸���õ�DPI���ţ�ʹ��Ϊ150%;���Ի�ȡʹ�������1.5
    //����λ��Ϊ  x=30   y=1380  ���½�λ��,
//������Ļ�߽�Ϊ
    int screenx = 30;
    int screeny = Height - 220;
    RECT rect;
    POINT iconposition;

    //��������ͼ��
    for (int i = 0; i < iconCount; i++)
    {
        ListView_SetItemPosition(desktop, i, screenx, screeny);
        //////////�ƶ�λ�ú���
        /*SendMessageA(desktop, LVM_SETITEMPOSITION, i, (screeny << 16) + screenx);*/
    }////////////����λ�ú���
    std::cout << "Width:" << Width << "   " << "Height" << Height <<std:: endl;
}
void Gameinit2()
{
    desktop = GetDesktopHandle();
    int iconCount = SendMessage(desktop, LVM_GETITEMCOUNT, 0, 0);
    for(int i=0;i<iconCount;i++)
    {
        random_device rd;
        uniform_int_distribution<int> ranX(0, 2560);
        uniform_int_distribution<int> ranY(0, 1600);
        SendMessage(desktop, LVM_SETITEMPOSITION, i, MAKELPARAM(ranX(rd), ranY(rd)));
    }
}
int d0[5][3] = { {1,1,1},
                 {1,0,1},
                 {1,0,1},
                 {1,0,1},
                 {1,1,1} };
int d1[5][3] = { {0,0,1},
                 {0,0,1},
                 {0,0,1},
                 {0,0,1},
                 {0,0,1} };
int d2[5][3] = { {1,1,1},
                 {0,0,1},
                 {1,1,1},
                 {1,0,0},
                 {1,1,1} };
int d3[5][3] = { {1,1,1},
                 {0,0,1},
                 {1,1,1},
                 {0,0,1},
                 {1,1,1} };
int d4[5][3] = { {1,0,1},
                 {1,0,1},
                 {1,1,1},
                 {0,0,1},
                 {0,0,1} };
int d5[5][3] = { {1,1,1},
                 {1,0,0},
                 {1,1,1},
                 {0,0,1},
                 {1,1,1} };
int d6[5][3] = { {1,1,1},
                 {1,0,0},
                 {1,1,1},
                 {1,0,1},
                 {1,1,1} };
int d7[5][3] = { {1,1,1},
                 {0,0,1},
                 {0,0,1},
                 {0,0,1},
                 {0,0,1} };
int d8[5][3] = { {1,1,1},
                 {1,0,1},
                 {1,1,1},
                 {1,0,1},
                 {1,1,1} };
int d9[5][3] = { {1,1,1},
                 {1,0,1},
                 {1,1,1},
                 {0,0,1},
                 {1,1,1} };

int(*arrayx[10])[5][3] = { &d0, &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9 };
    POINT Second={1000,700 };
    POINT Second0 = { 1320,700 };
    POINT Minute{ 1600,220 };
    POINT Minute0{ 1920,220 };
    POINT Hour{ 420,220 };
    POINT Hour0 = { 740,220 };
    POINT(arrPOINT[6]) = { Second0 ,Second ,Minute0 ,Minute ,Hour0,Hour };
    int Secondarr[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,78,79,90};
    int Secondarr0[16] = { 13,14,15,16,17,18,19,20,21,22,23,24,25,80,81 ,91};
    int Minutearr[16] = {  26,27,28,29,30,31,32,33,34,35,36,37,38,82,83 ,92};
    int Minutearr0[16] = { 39,40,41,42,43,44,45,46,47,48,49,50,51 ,84,85,93};
    int Hourarr[16] = { 52,53,54,55,56,57,58,59,60,61,62,63,64, 86,87,94};
    int Hourarr0[16] = { 65,66,67,68,69,70,71,72,73,74,75,76,77,88,89 ,95};
    int* arrayarrs[16] = {  Secondarr0, Secondarr, Minutearr0,Minutearr, Hourarr0, Hourarr };
void SetPosition(int numberposition,int number )//aΪ�ĸ�λ�õ�����0Ϊ��ĸ�λ���Դ�����
{
    std::mutex mtx;
    int h = 0;
    for (int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mtx.lock();
            if ((*arrayx[number])[i][j] == 1)
            {
                ListView_SetItemPosition(desktop, arrayarrs[numberposition][h++],
                    arrPOINT[numberposition].x + j * ICON_SIZE, arrPOINT[numberposition].y + i * ICON_SIZE);
            }
            else {
                ListView_SetItemPosition(desktop, arrayarrs[numberposition][h++], 30, 1380);
            }
            mtx.unlock();
        }
   }
}
void Timeinit(short &_sec0,short&_sec1,short&_min0,short &_min1,short& _hour0,short&_hour1)
{
    int a = 0;
    time_t nowtime;
    time(&nowtime);
    tm ptime;
    localtime_s(&ptime, &nowtime);
    _sec0 = ptime.tm_sec % 10; _sec1 = ptime.tm_sec / 10;
    _min0 = ptime.tm_min % 10; _min1 = ptime.tm_min / 10;
    _hour0 = ptime.tm_hour % 10; _hour1 = ptime.tm_hour / 10;
    thread sec0(SetPosition, 0, _sec0);sec0.detach();
    thread sec1(SetPosition, 1, _sec1);sec1.detach();
    thread min0(SetPosition, 2, _min0);min0.detach();
    thread min1(SetPosition, 3, _min1);min1.detach();
    thread hour0(SetPosition, 4, _hour0);hour0.detach();
    thread hour1(SetPosition, 5, _hour1);hour1.detach();
}
void ClockMode()
{
    Gameinit();//��ʼ��λ��
    short sec0, sec1, min0, min1,hour0,hour1;
    clock_t start_t, end_t;
    Timeinit(sec0, sec1, min0, min1, hour0, hour1);
    while(true)
    {
        start_t = clock();sec0++;
        if(sec0<=9)
        {
            SetPosition(0, sec0);
        }
        else if(sec0 == 10) {
            sec0 = 0;sec1++;
            if (sec1 == 6)goto sec1_6;
            SetPosition(0, sec0);
            SetPosition(1, sec1);
        }
        sec1_6:
        if (sec1 == 6) {
            sec1 = 0;min0++;
            if (min0 == 10)goto min0_10;
            SetPosition(1, sec1);
            SetPosition(2, min0);
        }
        min0_10:
        if (min0 == 10) {
            min0 = 0;min1++;
            if (min1 == 6)goto min1_6;
            SetPosition(2, min0);
            SetPosition(3, min1);
        }
        min1_6:
        if (min1 == 6) {
            min1 = 0; hour0++;
            if (hour0 == 10)goto hour0_10;
            SetPosition(3, min1);
            SetPosition(4, hour0);
        }
        hour0_10:
        if (hour0 == 10) {
            hour0 = 0;hour1++;
            if (hour1 == 6)break;
            SetPosition(4, hour0);
            SetPosition(5, hour1);
        } if (hour1 == 2 && hour0 == 4) {
            hour0 = 0;hour1 = 0;
            min0 = 0;min1 = 0;
            sec0 = 0;sec1 = 0;
        thread h0(  SetPosition,4, hour0); h0.detach();
        thread h1(  SetPosition,5, hour1);h1.detach();
        thread m0( SetPosition,2, min0); m0.detach();
        thread m1( SetPosition,3, min1); m1.detach();
        thread s0( SetPosition,0, sec0);s0.detach();
        thread s1(SetPosition, 1, sec1); s1.detach();
        }
        end_t = clock();
        std::cout << "��������ʱ�䣺" << end_t - start_t << endl;
        Sleep(1000-(double)(end_t-start_t));
    }
}
int main()
{
   // ClockMode01();
   ClockMode();
}