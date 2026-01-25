//
//
//
//
//
//
//
//
//
//
//
//
//---------------------------유의사항------------------------------ 
//
//    게임창을 전체화면 하지 마세요  
//    CapsLock이 꺼져있는지 확인하세요  
//
//    게임점수를 저장할 때 부적절한 단어를 포함하지 마세요  
//    기록을 저장하고 게임창을 나가거나 아무 키를 눌러 종료합니다  
//
//    C코드를 수정하지마세요.
//    (만일 수정하였다면, Ctrl+Z 를 계속 눌러 되돌리세요) 
//
//-----------------------------------------------------------------
//
//-----------------------권한자 유의사항---------------------------
//
//    게임이 실행이 되지 않는다면 게임제작자를 부르세요  
//
//    처음 파일을 열 때 '도구(T) -> 컴파일러 설정(C) - >
//    컴파일러 추가 명령 사용 -> " -std=c++14 " 입력
//
//    부적절한 닉네임이 점수창에 있다면 게임제작자를 부르세요  
//
//-----------------------------------------------------------------
//
//
//                'F10'을 눌러 게임을 시작합니다. 
//
//     
//
//
//
//
//
//
//
//
//
//
//
//
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <vector>
#include <math.h>

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#define OPTYPE 11      //option     
#define BLOCK 7

#define NAME 1
#define SCORE 2
#define ALLCLEARED 3
#define PUYOCLEARED 4
#define MAXCHAIN 5

#define CALL 1000000
#define CPUYO 100

using namespace std;
using std::thread;
std::string Path = "text.txt";
std::ifstream readFile(Path);
std::ofstream writeFile(Path);
ofstream fout;
ifstream fin;

int mov_x,mov_y,mov_x1,mov_y1,mov,mov1;
char but;

int i,j,i1,j1,i2,j2;
int map[25][14];
int balmap[25][14];
int entime;
int turn;

int score=0;
int maxscore1,maxscore2,maxscore3,maxscore4,maxscore5,maxscore6,maxscore7,maxscore8,maxscore9,maxscore10,maxscore11,maxscore12,maxscore13,maxscore14,maxscore15;
char file_input[100];
unsigned long long file_int,powtrans;
char name[10];

int block_rand=0;

int diff_select=1;  //normal 
int start_select=0;
int op_select=0;  //None 
int stand_select=0;  //sweet
int option[OPTYPE-1];
int blocktype;
int fall;
int puyoclearspeed = 150;
int chain,destroy,chaintime,subdestroy,fallscore;
int fallscore_plus=0; 
int bomb_fallscore_not_remove=0; 
int chain_x[20]={0,1,8,16,32,64,96,128,192,224,256,288,320,352,384,416,448,480,512};
int commap[14][14];

int puyocleared=1,allcleared=1,maxchain=1; //임시숫자 
int tact,wordlot;

char code[8];      //코드 입력 

int limit=1;  //움직임 제한 //임시숫지  1

int othertact[7];  //레인보우 

int iceheight=12,icenum=1;   //임시숫자 1 

int sandwich_plus=1;

char rev_mov[4]={'a','d','w','s'};

int gravity;
int gravity_use=1;//1=사용안함  0=사용함  

///////////////////////도전과제 변수
 
char dis_chall[1000][32];

int chall_type[12]={0,6,10,15,20,25,29,33,38,42,44,48};
int chall_type_plus[12]={0,0,0,0,0,0,0,0,0,0,0,0};   //0,0,0,0,0,0,0,0,0,0,0,0  5,3,4,4,4,3,3,4,3,1,3,1

int chall_say_time=-1;

int chall_obstruct=0,chall_sandwich=0,chall_sandwich_score=0,chall_bomb=6,chall_limit=0,chall_secret=0; 

char dis_chall_copy[1000][32]={
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Acheive 10000 score        "},//1
{"   or more                    "},//2
{"  [1]2 3 4 5                  "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 100000 score       "},
{"   or more                    "},
{"   1[2]3 4 5                  "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 1000000 score      "},
{"   or more                    "},
{"   1 2[3]4 5                  "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 10000000 score     "},
{"   or more                    "},
{"   1 2 3[4]5                  "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 99999999 score     "},
{"   or more                    "},
{"   1 2 3 4[5]                 "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Acheive 5 chain or more    "},//1
{"                              "},//2
{"  [1]2 3                      "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 10 chain or more   "},
{"                              "},
{"   1[2]3                      "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 15 chain or more   "},
{"                              "},
{"   1 2[3]                     "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Acheive 1 all-cleared      "},//1
{"   or more in a play          "},//2
{"  [1]2 3 4                    "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 2 all-cleared      "},
{"   or more in a play          "},
{"   1[2]3 4                    "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 3 all-cleared      "},
{"   or more in a play          "},
{"   1 2[3]4                    "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 3 all-cleared      "},
{"   before 100 puyos clear     "},
{"   1 2 3[4]                   "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Destroy 100 puyos          "},//1
{"   or more in a play          "},//2
{"  [1]2 3 4                    "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 500 puyos          "},
{"   or more in a play          "},
{"   1[2]3 4                    "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 1000 puyos         "},
{"   or more in a play          "},
{"   1 2[3]4                    "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 5000 puyos         "},
{"   or more in a play          "},
{"   1 2 3[4]                   "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Destroy 10 obstruct        "},//1
{"   puyos or more in a play    "},//2
{"  [1]2 3 4                    "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 30 obstruct        "},
{"   puyos or more in a play    "},
{"   1[2]3 4                    "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 50 obstruct        "},
{"   puyos or more in a play    "},
{"   1 2[3]4                    "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 100 obstruct       "},
{"   puyos or more in a play    "},
{"   1 2 3[4]                   "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Make 5 sandwiches          "},//1
{"   or more in a play          "},//2
{"  [1]2 3                      "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 7 chains or more   "},
{"   when sandwich exists       "},
{"   1[2]3                      "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Get 1000000 score          "},
{"   when sandwich exists       "},
{"   1 2[3]                     "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Destroy a bomb             "},//1
{"   before being 2 count       "},//2
{"  [1]2 3                      "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy a bomb             "},
{"   before being 3 count       "},
{"   1[2]3                      "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy a bomb             "},
{"   before being 4 count       "},
{"   1 2[3]                     "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Acheive 15000 score        "},//1
{"   not using all limits       "},//2
{"  [1]2 3 4                    "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 60000 score        "},
{"   not using all limits       "},
{"   1[2]3 4                    "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")---------------------------("},
{"   Acheive 100000 score       "},
{"   not using all limits       "},
{"   1 2[3]4                    "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Acheive 300000 score       "},
{"   not using all limits       "},
{"   1 2 3[4]                   "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Achieve 3 chains           "},//1
{"   in the rainbow option      "},//2
{"  [1]2 3                      "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Achieve 5 chains           "},
{"   in the rainbow option      "},
{"   1[2]3                      "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Achieve 8 chains           "},
{"   in the rainbow option      "},
{"   1 2[3]                     "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Achieve 7 chains and       "},
{"   all-cleared when reversed  "},
{"  [1]                         "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 300 star puyos     "},
{"   in Sweet handicap          "},
{"  [1]2 3                      "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 300 star puyos     "},
{"   in Normal handicap         "},
{"   1[2]3                      "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"   Destroy 300 star puyos     "},
{"   in Spicy handicap          "},
{"   1 2[3]                     "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},//0
{"   Find any Secret            "},//1
{"                              "},//2
{"  [1]                         "},//3
{")----------------------------("},//4
{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"},
{")----------------------------("},
{"                              "},
{"          COMPLETED!          "},
{"                              "},
{")----------------------------("},

}; 

/////////////////////////////////////////////////////////////////////////
void textcolor(int foreground, int background) //글자색 
{ 
int color=foreground+background*16; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}


void Gotxy(int x, int y)          //gotxy
{
	COORD Pos={y+3,x+2};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void chall_say(){   //도전과제 달성 표시 
	chall_say_time=0;
	
	fout.open("challenge.txt");//도전과제   
i=0;
file_int=0;
while(i<=11){
	powtrans=pow(10,i);
	file_int+=chall_type_plus[i]*powtrans;
	i+=1;
}
fout<<file_int;
fout.close();
	
	Gotxy(17,1);
	textcolor(WHITE,BLACK);
	cout<<"                         ";
	Sleep(100);
	Gotxy(17,1);
	textcolor(WHITE,LIGHTGREEN);
	cout<<"Acheiving Challenge !!!";
	Gotxy(17,22);
	textcolor(LIGHTGREEN,BLACK);
	cout<<"▶";

	
}
/////////////////////////////////////////////////////////////////////////

void namelegth(){
	i=0;
	while(i<=1000){
		if(name[i]!=' '){
		wordlot+=1;
		if(wordlot>12&&name[i]!=' ')        //최대 글자수 12 
		name[i]=' ';	
		i+=1;
		}
		
		
	}
}

void filecopy(char from_n[100], char to_n[100],char from_r[100], char to_r[100],char from_s[100], char to_s[100]){
	fin.open(from_n); 
    fout.open(to_n);
    fout << fin.rdbuf(); 
    fout.close();
    fin.close();
    fin.open(from_r); 
    fout.open(to_r);
    fout << fin.rdbuf(); 
    fout.close();
    fin.close();
    fin.open(from_s); 
    fout.open(to_s);
    fout << fin.rdbuf(); 
    fout.close();
    fin.close();
}

//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void file_read1(int file){
	ifstream fin;
	if(file==1){
		fin.open("name1.txt");         //maxsscore
fin>>file_input;
Gotxy(9,2);
textcolor(YELLOW,BLACK);
printf("１ ☆%s☆ ",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score1.txt");         //maxsscore
fin>>file_int;
Gotxy(9,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record1.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(9,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record1.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(9,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record1.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(9,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}
}

void file_read2(int file){
	ifstream fin;
	if(file==1){
		fin.open("name2.txt");         //maxsscore
fin>>file_input;
Gotxy(11,2);
textcolor(LIGHTGRAY,BLACK);
printf("２ ＊%s＊",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score2.txt");         //maxsscore
fin>>file_int;
Gotxy(11,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record2.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(11,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record2.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(11,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record2.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(11,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}

void file_read3(int file){
	ifstream fin;
	if(file==1){
		fin.open("name3.txt");         //maxsscore
fin>>file_input;
Gotxy(13,2);
textcolor(BROWN,BLACK);
printf("３ %s",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score3.txt");         //maxsscore
fin>>file_int;
Gotxy(13,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record3.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(13,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record3.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(13,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record3.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(13,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}
}
void file_read4(int file){
	ifstream fin;
	if(file==1){
		fin.open("name4.txt");         //maxsscore
fin>>file_input;
Gotxy(15,2);
textcolor(WHITE,BLACK);
printf("４ %s",file_input);
fin.close();
	}
	else if(file==2){
		fin.open("score4.txt");         //maxsscore
fin>>file_int;
Gotxy(15,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record4.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(15,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record4.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(15,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record4.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(15,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}
void file_read5(int file){
	ifstream fin;
	if(file==1){
		fin.open("name5.txt");         //maxsscore
fin>>file_input;
Gotxy(17,2);
textcolor(WHITE,BLACK);
printf("５ %s",file_input);
fin.close();
	}
	else if(file==2){
		fin.open("score5.txt");         //maxsscore
fin>>file_int;
Gotxy(17,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record5.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(17,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record5.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(17,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record5.txt");         //maxsscore
fin>>file_int;
file_int=file_int%100;
Gotxy(17,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}
void file_read6(int file){
	ifstream fin;
	if(file==1){
		fin.open("name6.txt");         //maxsscore
fin>>file_input;
Gotxy(9,2);
textcolor(YELLOW,BLACK);
printf("１ ☆%s☆ ",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score6.txt");         //maxsscore
fin>>file_int;
Gotxy(9,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record6.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(9,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record6.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(9,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record6.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(9,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}
}

void file_read7(int file){
	ifstream fin;
	if(file==1){
		fin.open("name7.txt");         //maxsscore
fin>>file_input;
Gotxy(11,2);
textcolor(LIGHTGRAY,BLACK);
printf("２ ＊%s＊",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score7.txt");         //maxsscore
fin>>file_int;
Gotxy(11,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record7.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(11,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record7.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(11,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record7.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(11,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}

void file_read8(int file){
	ifstream fin;
	if(file==1){
		fin.open("name8.txt");         //maxsscore
fin>>file_input;
Gotxy(13,2);
textcolor(BROWN,BLACK);
printf("３ %s",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score8.txt");         //maxsscore
fin>>file_int;
Gotxy(13,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record8.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(13,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record8.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(13,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record8.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(13,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}
}
void file_read9(int file){
	ifstream fin;
	if(file==1){
		fin.open("name9.txt");         //maxsscore
fin>>file_input;
Gotxy(15,2);
textcolor(WHITE,BLACK);
printf("４ %s",file_input);
fin.close();
	}
	else if(file==2){
		fin.open("score9.txt");         //maxsscore
fin>>file_int;
Gotxy(15,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record9.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(15,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record9.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(15,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record9.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(15,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}
void file_read10(int file){
	ifstream fin;
	if(file==1){
		fin.open("name10.txt");         //maxsscore
fin>>file_input;
Gotxy(17,2);
textcolor(WHITE,BLACK);
printf("５ %s",file_input);
fin.close();
	}
	else if(file==2){
		fin.open("score10.txt");         //maxsscore
fin>>file_int;
Gotxy(17,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record10.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(17,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record10.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(17,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record10.txt");         //maxsscore
fin>>file_int;
file_int=file_int%100;
Gotxy(17,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}
void file_read11(int file){
	ifstream fin;
	if(file==1){
		fin.open("name11.txt");         //maxsscore
fin>>file_input;
Gotxy(9,2);
textcolor(YELLOW,BLACK);
printf("１ ☆%s☆ ",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score11.txt");         //maxsscore
fin>>file_int;
Gotxy(9,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record11.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(9,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record11.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(9,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record11.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(9,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}
}

void file_read12(int file){
	ifstream fin;
	if(file==1){
		fin.open("name12.txt");         //maxsscore
fin>>file_input;
Gotxy(11,2);
textcolor(LIGHTGRAY,BLACK);
printf("２ ＊%s＊",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score12.txt");         //maxsscore
fin>>file_int;
Gotxy(11,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record12.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(11,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record12.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(11,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record12.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(11,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}

void file_read13(int file){
	ifstream fin;
	if(file==1){
		fin.open("name13.txt");         //maxsscore
fin>>file_input;
Gotxy(13,2);
textcolor(BROWN,BLACK);
printf("３ %s",file_input);
textcolor(WHITE,BLACK);
fin.close();
	}
	else if(file==2){
		fin.open("score13.txt");         //maxsscore
fin>>file_int;
Gotxy(13,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record13.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(13,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record13.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(13,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record13.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(13,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}
}
void file_read14(int file){
	ifstream fin;
	if(file==1){
		fin.open("name14.txt");         //maxsscore
fin>>file_input;
Gotxy(15,2);
textcolor(WHITE,BLACK);
printf("４ %s",file_input);
fin.close();
	}
	else if(file==2){
		fin.open("score14.txt");         //maxsscore
fin>>file_int;
Gotxy(15,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record14.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(15,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record14.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(15,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record14.txt");         //maxsscore
fin>>file_int;
file_int=file_int%CPUYO;
Gotxy(15,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}
void file_read15(int file){
	ifstream fin;
	if(file==1){
		fin.open("name15.txt");         //maxsscore
fin>>file_input;
Gotxy(17,2);
textcolor(WHITE,BLACK);
printf("５ %s",file_input);
fin.close();
	}
	else if(file==2){
		fin.open("score15.txt");         //maxsscore
fin>>file_int;
Gotxy(17,22);
printf("| ");
printf("%d",file_int);
fin.close();
	}
	else if(file==3){
		fin.open("record15.txt");         //maxsscore
fin>>file_int;
file_int=(file_int-file_int%CALL)/CALL;
Gotxy(17,32);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==4){
		fin.open("record15.txt");         //maxsscore
fin>>file_int;
file_int=(file_int%CALL-file_int%CPUYO)/CPUYO;
Gotxy(17,42);
printf("| ");
printf("%d",file_int);
fin.close();
}
else if(file==5){
		fin.open("record15.txt");         //maxsscore
fin>>file_int;
file_int=file_int%100;
Gotxy(17,52);
printf("| ");
printf("%d",file_int);
fin.close();
	}	
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void puyo(){       //뿌요뿌요 멥 설정에 따른 블럭 설정 
	i=0;
	j=0;
while(i<=24){
	while(j<=13){
		if(map[i][j]==1&&j>0&&i<18&&i>=2){                   //초록  
			textcolor(LIGHTGREEN,BLACK);
			Gotxy(j,i);
			if(option[1]!=1&&option[0]!=1)
	cout <<"●"<<endl;
	        if(option[1]==1)
	cout <<"○"<<endl;                   //버블  
	if(option[0]==1){
	textcolor(CYAN,BLACK);
	cout <<"★"<<endl;              //speed
}
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==1&&j>0&&i>=18){
			textcolor(LIGHTGREEN,BLACK);
			Gotxy(j,i);
			if(option[0]!=1)
	cout <<"◐"<<endl;
	if(option[0]==1){
	textcolor(CYAN,BLACK);
	cout <<"☆"<<endl;              //speed
}
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==1+BLOCK&&j>=0&&i<=15){
			textcolor(LIGHTGREEN,BLACK);
			if(option[0]==1)
	textcolor(CYAN,BLACK);
			Gotxy(j,i);
	cout <<"ㆍ"<<endl;
	textcolor(WHITE,BLACK);
		}
	    if(map[i][j]==2&&j>0&&i<18&&i>=2){                   //파랑 
			if(option[8]!=1)
			textcolor(BLUE,BLACK);
			else if(option[8]==1)
			textcolor(LIGHTRED,BLACK);  //샌드위치  
			Gotxy(j,i);
			if(option[1]!=1&&option[0]!=1)
	cout <<"●"<<endl;
	if(option[1]==1)
	cout <<"○"<<endl;            //버블 
	if(option[0]==1){
	textcolor(WHITE,BLACK);
	cout <<"★"<<endl;       //speed
	}
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==2&&j>0&&i>=18){
			if(option[8]!=1)
			textcolor(BLUE,BLACK);
			else if(option[8]==1)
			textcolor(LIGHTRED,BLACK);  //샌드위치  
			Gotxy(j,i);
	if(option[0]!=1)		
	cout <<"◐"<<endl;
	if(option[0]==1){
	textcolor(WHITE,BLACK);
	cout <<"☆"<<endl; 	
	}	             //speed
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==2+BLOCK&&j>=0&&i<=15){
			if(option[8]!=1)
			textcolor(BLUE,BLACK);
			else if(option[8]==1)
			textcolor(LIGHTRED,BLACK);  //샌드위치  
			if(option[0]==1)
	textcolor(WHITE,BLACK);
			Gotxy(j,i);
	cout <<"ㆍ"<<endl;
	textcolor(WHITE,BLACK);
		}
		if(map[i][j]==3&&j>0&&i<18&&i>=2){                   //빨강 
			textcolor(RED,BLACK);
			Gotxy(j,i);
			if(option[1]!=1&&option[0]!=1)
	cout <<"●"<<endl;
	if(option[1]==1)            //버블 
	cout <<"○"<<endl;
	else if(option[0]==1){
	textcolor(BROWN,BLACK);
	cout <<"★"<<endl;              //speed
	textcolor(WHITE,BLACK);
}
		}
		else if(map[i][j]==3&&j>0&&i>=18){
			textcolor(RED,BLACK);
			Gotxy(j,i);
	if(option[0]!=1)		
	cout <<"◐"<<endl;
	if(option[0]==1){
	textcolor(BROWN,BLACK);
	cout <<"☆"<<endl; 
	textcolor(WHITE,BLACK);
		}
	}
		else if(map[i][j]==3+BLOCK&&j>=0&&i<=15){
		if(option[0]!=1)		
	textcolor(RED,BLACK);
	if(option[0]==1)
	textcolor(BROWN,BLACK);
			Gotxy(j,i);
	cout <<"ㆍ"<<endl;
	textcolor(WHITE,BLACK);
		}
		if(map[i][j]==4&&j>0&&i<18&&i>=2){                   //노랑  
			textcolor(BROWN,BLACK);
			Gotxy(j,i);
			if(option[1]!=1&&option[0]!=1)
	cout <<"●"<<endl;
	if(option[1]==1)
	cout <<"○"<<endl;            //버블 
	else if(option[0]==1){
	textcolor(LIGHTRED,BLACK);
	cout <<"★"<<endl;              //speed
	textcolor(WHITE,BLACK);
}
		}
		else if(map[i][j]==4&&j>0&&i>=18){
			textcolor(BROWN,BLACK);
			Gotxy(j,i);
	if(option[0]!=1)		
	cout <<"◐"<<endl;
	if(option[0]==1){
	textcolor(LIGHTRED,BLACK);
	cout <<"☆"<<endl; 
}
	textcolor(WHITE,BLACK);
		}	
		else if(map[i][j]==4+BLOCK&&j>=0&&i<=15){
			if(option[0]!=1)		
	textcolor(BROWN,BLACK);
	if(option[0]==1)
	textcolor(LIGHTRED,BLACK);
			Gotxy(j,i);
	cout <<"ㆍ"<<endl;
	textcolor(WHITE,BLACK);
		}
		if(map[i][j]==5&&j>0&&i<18&&i>=2){                   //보라  
			textcolor(MAGENTA,BLACK);
			Gotxy(j,i);
			if(option[1]!=1)
	cout <<"●"<<endl;
	if(option[1]==1){
	textcolor(LIGHTGRAY,BLACK);
	cout <<"⊙"<<endl;
}
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==5&&j>0&&i>=18){
			if(option[1]!=1){
				textcolor(MAGENTA,BLACK);
				Gotxy(j,i);
	cout <<"◐"<<endl;
			}
	if(option[1]==1){
	textcolor(LIGHTGRAY,BLACK);			
			Gotxy(j,i);
	cout <<"⊙"<<endl;
}
	textcolor(WHITE,BLACK);
		}	
		else if(map[i][j]==5+BLOCK&&j>=0&&i<=15){
			if(option[1]!=1)
	textcolor(MAGENTA,BLACK);
	if(option[1]==1){
	textcolor(LIGHTGRAY,BLACK);
}
			Gotxy(j,i);
	cout <<"ㆍ"<<endl;
	textcolor(WHITE,BLACK);
		}
		if(map[i][j]==6&&j>0&&i<18&&i>=2){                   //레인보우  
			textcolor(LIGHTMAGENTA,BLACK);
			Gotxy(j,i);
	cout <<"●"<<endl;
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==6&&j>0&&i>=18){
			textcolor(LIGHTMAGENTA,BLACK);
			Gotxy(j,i);
	cout <<"◐"<<endl;
	textcolor(WHITE,BLACK);
		}	
		else if(map[i][j]==6+BLOCK&&j>=0&&i<=15){
			textcolor(MAGENTA,BLACK);
			Gotxy(j,i);
	cout <<"ㆍ"<<endl;
	textcolor(WHITE,BLACK);
		}
		
		if(map[i][j]==7&&j>0&&i<18&&i>=2){                   //레인보우  
			textcolor(CYAN,BLACK);
			Gotxy(j,i);
	cout <<"●"<<endl;
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==7&&j>0&&i>=18){
			textcolor(CYAN,BLACK);
			Gotxy(j,i);
	cout <<"◐"<<endl;
	textcolor(WHITE,BLACK);
		}	
		else if(map[i][j]==7+BLOCK&&j>=0&&i<=15){
			textcolor(CYAN,BLACK);
			Gotxy(j,i);
	cout <<"ㆍ"<<endl;
	textcolor(WHITE,BLACK);
		}                                              //레인보우 
		
		if(map[i][j]==100){
			if(rev_mov[0]=='a'&&option[8]!=1)
	textcolor(BLACK,LIGHTBLUE);           //reverse 
	else if(rev_mov[0]=='d')
	textcolor(BLACK,BROWN);
	else if(option[8]==1&&sandwich_plus!=1)   //샌드위치  
	textcolor(BLACK,LIGHTMAGENTA);
	else if(option[8]==1&&sandwich_plus==1)   //샌드위치  
	textcolor(BLACK,LIGHTBLUE);
			Gotxy(j,i);
	cout <<" "<<endl;
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==101){       //limit
	textcolor(WHITE,LIGHTBLUE);
			Gotxy(j,i);
	cout <<"^"<<endl;
	textcolor(WHITE,BLACK);
		}
		else if(map[i][j]==99){       //limit
	textcolor(BLACK,LIGHTBLUE);
			Gotxy(j,i);
	cout <<"^"<<endl;
	textcolor(WHITE,BLACK);
		}
        else if(map[i][j]==98){       //limit
	if(rev_mov[0]=='a'&&option[8]!=1)
	textcolor(LIGHTBLUE,BLACK);           //reverse 
	else if(rev_mov[0]=='d')
	textcolor(BROWN,BLACK);
	else if(option[8]==1&&sandwich_plus!=1)   //샌드위치  
	textcolor(LIGHTMAGENTA,BLACK);
	else if(option[8]==1&&sandwich_plus==1)   //샌드위치  
	textcolor(LIGHTBLUE,BLACK);
			Gotxy(j,i);
	cout <<"■"<<endl;
	textcolor(WHITE,BLACK);
		}
		
		if(map[i][j]==30&&j>0&&i<18&&i>=2){                   //방해뿌요 
			textcolor(LIGHTGRAY,BLACK);
			Gotxy(j,i);
	cout <<"⊙"<<endl;
	textcolor(WHITE,BLACK);
		}
    if(map[6][1]==0&&i==6&&j==1){         //x표시  
		Gotxy(1,6);
	textcolor(RED,BLACK);
	cout << "Ｘ" <<endl;
	textcolor(WHITE,BLACK);
}

if(option[7]==1){
	if(map[i][j]==1001&&j>0&&i<18&&i>=2){                   //초록       //얼음  
			textcolor(LIGHTGREEN,CYAN);
			Gotxy(j,i);
	cout <<"●"<<endl;
	textcolor(WHITE,BLACK);
		}
	    if(map[i][j]==1002&&j>0&&i<18&&i>=2){                   //파랑 
			textcolor(BLUE,CYAN);
			Gotxy(j,i);
	cout <<"●"<<endl;
	textcolor(WHITE,BLACK);
		}
		if(map[i][j]==1003&&j>0&&i<18&&i>=2){                   //빨강 
			textcolor(RED,CYAN);
			Gotxy(j,i);
	cout <<"●"<<endl;
	textcolor(WHITE,BLACK);
		}
		if(map[i][j]==1004&&j>0&&i<18&&i>=2){                   //노랑  
			textcolor(BROWN,CYAN);
			Gotxy(j,i);
			if(option[1]!=1)
	cout <<"●"<<endl;
	textcolor(WHITE,BLACK);
		}
		if(map[i][j]==1005&&j>0&&i<18&&i>=2){                   //보라  
			textcolor(MAGENTA,CYAN);
			Gotxy(j,i);
	cout <<"●"<<endl;
	textcolor(WHITE,BLACK);
		}
} 



	if(map[i][j]==50&&j>=0&&i<=15){                           //폭탄 
			textcolor(WHITE,BLACK);
			Gotxy(j,i);
	cout <<"⑤"<<endl;
	textcolor(WHITE,BLACK);
		}
	if(map[i][j]==51&&j>=0&&i<=15){
			textcolor(WHITE,BLACK);
			Gotxy(j,i);
	cout <<"④"<<endl;
	textcolor(WHITE,BLACK);
		}
	if(map[i][j]==52&&j>=0&&i<=15){
			textcolor(WHITE,BLACK);
			Gotxy(j,i);
	cout <<"③"<<endl;
	textcolor(WHITE,BLACK);
		}
	if(map[i][j]==53&&j>=0&&i<=15){
			textcolor(WHITE,BLACK);
			Gotxy(j,i);
	cout <<"②"<<endl;
	textcolor(WHITE,BLACK);
		}
	if(map[i][j]==54&&j>=0&&i<=15){
			textcolor(WHITE,BLACK);
			Gotxy(j,i);
	cout <<"①"<<endl;
	textcolor(WHITE,BLACK);
		}	
	if(map[i][j]==55&&j>=0&&i<=15){
			textcolor(WHITE,BLACK);
			Gotxy(j,i);
	cout <<"ⓞ"<<endl;
	textcolor(WHITE,BLACK);
		}
		
	if(map[i][j]==150&&j>=0&&i<=15&&option[8]==1){                           //샌드위치  
			textcolor(BROWN,BLACK);
			Gotxy(j,i);
	cout <<"三"<<endl;
	textcolor(BROWN,BLACK);
		}
	if(map[i][j]==151&&j>=0&&i<=15&&option[8]==1){                           //샌드위치  
			textcolor(BROWN,BLACK);
			Gotxy(j,i);
	cout <<"二"<<endl;
	textcolor(BROWN,BLACK);
		}
	if(map[i][j]==152&&j>=0&&i<=15&&option[8]==1){                           //샌드위치  
			textcolor(BROWN,BLACK);
			Gotxy(j,i);
	cout <<"一"<<endl;
	textcolor(BROWN,BLACK);
		}		
						

		j+=1;
	}
	j=0;
	i+=1;
}
////////////////////////////////
tact=0;       //터짐 감지 상수 tact
i=0;
	j=0;
while(i<=24){        //감지 
	while(j<=13){
		if(map[i][j]==20){
			tact+=1;
		}
j+=1;
	}
	j=0;
	i+=1;
}
if(tact>=1){        //감지가 됐을 때 
	i=0;
	j=0;
while(i<=24){
	while(j<=13){
if(map[i][j]==20){
			textcolor(WHITE,BLACK);
			Gotxy(j,i);
			if(option[1]!=1&&option[0]!=1)
	cout <<"※"<<endl;            //버블
	if(option[1]==1)
	cout <<"◎"<<endl;
	if(option[0]==1)        //speed
	cout <<"☆"<<endl;
	if(option[1]!=1&&option[0]!=1)
	map[i][j]+=1;
	if(option[1]==1)
	map[i][j]+=3;
	if(option[0]==1)
	map[i][j]+=3;
		}
	j+=1;
	}
	j=0;
	i+=1;
}
if(option[1]!=1&&option[0]!=1){            //버블 
	Sleep(puyoclearspeed);	     // Basic : 150
i=0;
	j=0;
while(i<=24){
	while(j<=13){
if(map[i][j]==21){
			textcolor(LIGHTGRAY,BLACK);
			Gotxy(j,i);
	cout <<"  "<<endl;
	map[i][j]+=1;
		}
	j+=1;
	}
	j=0;
	i+=1;
}
Sleep(puyoclearspeed);		     // Basic : 150
i=0;
	j=0;
while(i<=24){
	while(j<=13){
if(map[i][j]==22){
			textcolor(LIGHTGRAY,BLACK);
			Gotxy(j,i);
	if(option[0]!=1)		
	cout <<"※"<<endl;
	map[i][j]+=1;
		}
	j+=1;
	}
	j=0;
	i+=1;
}
}
Sleep(puyoclearspeed);		     // Basic : 150
i=0;
	j=0;
while(i<=24){
	while(j<=13){
if(map[i][j]==23){
			textcolor(LIGHTGRAY,BLACK);
			Gotxy(j,i);
	cout <<"  "<<endl;
	map[i][j]=0;
	textcolor(WHITE,BLACK);
		}
	j+=1;
	}
	j=0;
	i+=1;
}

tact=0;
}                      //감지 종료 

}


/////////////////////////////////////////////////////////////////////////


void blockbreak(){
	
	destroy=0;
	i=0;
	j=0;
	while(i<=14){
		while(j<=14){
			commap[i][j]=0;
			j+=1;
		}
		j=0;
		i+=1;
	}
	
	i=0;
	j=0;
	while(i<=14){      //얼음모드를 위해서 map으로 비교하던 것을 balmap으로 대신 비교  
		while(j<=14){
			balmap[i][j]=map[i][j];
			if(balmap[i][j]>=1001&&option[7]==1) // 이 지점  
			balmap[i][j]-=1000;
			j+=1;
		}
		j=0;
		i+=1;
	}
	
i=0;
j=0;
while(i<=16){
	while(j<=14){
		if(option[1]!=1){
			if(balmap[i][j]>=1&&balmap[i][j]<=7){
 if(balmap[i][j]==balmap[i][j+1]&&balmap[i][j+1]==balmap[i][j+2]&&balmap[i][j+2]==balmap[i][j+3]) {    // 가로 
	commap[i][j]=1;
	commap[i][j+1]=1;
	commap[i][j+2]=1;
	commap[i][j+3]=1;
}	
       else if(balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+4][j]&&balmap[i][j]==balmap[i+6][j]) {    // 세로  
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+4][j]=1;
	commap[i+6][j]=1;
}
       else if(balmap[i][j]==balmap[i][j+1]&&balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+2][j+1]) {    // 네모  
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i][j+1]=1;
	commap[i+2][j+1]=1;
}		
else if(balmap[i][j]==balmap[i+2][j+1]&&balmap[i][j]==balmap[i][j+1]&&balmap[i][j]==balmap[i-2][j+1]) {    // ㅗ
	commap[i][j]=1;
	commap[i+2][j+1]=1;
	commap[i][j+1]=1;
	commap[i-2][j+1]=1;
}
else if(balmap[i][j]==balmap[i+2][j+1]&&balmap[i][j]==balmap[i][j+1]&&balmap[i][j]==balmap[i][j+2]) {    // ㅏ  
	commap[i][j]=1;
	commap[i+2][j+1]=1;
	commap[i][j+1]=1;
	commap[i][j+2]=1;
}
else if(balmap[i][j]==balmap[i-2][j+1]&&balmap[i][j]==balmap[i][j+1]&&balmap[i][j]==balmap[i][j+2]) {    // ㅓ  
	commap[i][j]=1;
	commap[i-2][j+1]=1;
	commap[i][j+1]=1;
	commap[i][j+2]=1;
}
else if(balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+2][j+1]&&balmap[i][j]==balmap[i+4][j]) {    // ㅜ 
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+2][j+1]=1;
	commap[i+4][j]=1;
}
else if(balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+2][j+1]&&balmap[i][j]==balmap[i+2][j+2]) {    // '|  
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+2][j+1]=1;
	commap[i+2][j+2]=1;
}
else if(balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+2][j-1]&&balmap[i][j]==balmap[i+2][j-2]) {    // .|  
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+2][j-1]=1;
	commap[i+2][j-2]=1;
}
else if(balmap[i][j]==balmap[i-2][j]&&balmap[i][j]==balmap[i-2][j+1]&&balmap[i][j]==balmap[i-2][j+2]) {    // |'  
	commap[i][j]=1;
	commap[i-2][j]=1;
	commap[i-2][j+1]=1;
	commap[i-2][j+2]=1;
}
else if(balmap[i][j]==balmap[i-2][j]&&balmap[i][j]==balmap[i-2][j-1]&&balmap[i][j]==balmap[i-2][j-2]) {    // |. 
	commap[i][j]=1;
	commap[i-2][j]=1;
	commap[i-2][j-1]=1;
	commap[i-2][j-2]=1;
}
else if(balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+4][j]&&balmap[i][j]==balmap[i+4][j+1]) {    // ㄱ1 
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+4][j]=1;
	commap[i+4][j+1]=1;
}
else if(balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+4][j]&&balmap[i][j]==balmap[i][j+1]) {    // ㄱ2 
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+4][j]=1;
	commap[i][j+1]=1;
}
else if(balmap[i][j]==balmap[i][j+1]&&balmap[i][j]==balmap[i+2][j+1]&&balmap[i][j]==balmap[i+4][j+1]) {    // ㄴ1 
	commap[i][j]=1;
	commap[i][j+1]=1;
	commap[i+2][j+1]=1;
	commap[i+4][j+1]=1;
}
else if(balmap[i][j]==balmap[i][j+1]&&balmap[i][j]==balmap[i-2][j+1]&&balmap[i][j]==balmap[i-4][j+1]) {    // ㄴ2 
	commap[i][j]=1;
	commap[i][j+1]=1;
	commap[i-2][j+1]=1;
	commap[i-4][j+1]=1;
}
else if(balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+2][j+1]&&balmap[i][j]==balmap[i+4][j+1]) {    // z1 
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+2][j+1]=1;
	commap[i+4][j+1]=1;
}
else if(balmap[i][j]==balmap[i+2][j]&&balmap[i][j]==balmap[i+2][j-1]&&balmap[i][j]==balmap[i+4][j-1]) {    // z2 
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+2][j-1]=1;
	commap[i+4][j-1]=1;
}
else if(balmap[i][j]==balmap[i][j+1]&&balmap[i][j]==balmap[i+2][j+1]&&balmap[i][j]==balmap[i+2][j+2]) {    // z3 
	commap[i][j]=1;
	commap[i][j+1]=1;
	commap[i+2][j+1]=1;
	commap[i+2][j+2]=1;
}
else if(balmap[i][j]==balmap[i][j-1]&&balmap[i][j]==balmap[i+2][j-1]&&balmap[i][j]==balmap[i+2][j-2]) {    // z4 
	commap[i][j]=1;
	commap[i][j-1]=1;
	commap[i+2][j-1]=1;
	commap[i+2][j-2]=1;
}
		}
	}
	else if(option[1]==1){            //버블 
		if(map[i][j]==1||map[i][j]==2||map[i][j]==3||map[i][j]==4){   //난이도 어려움 일떄 '5'는 제외 (방해뿌요)  
		if(map[i][j]==map[i][j+1]&&map[i][j+1]==map[i][j+2]) {    // 가로 
	commap[i][j]=1;
	commap[i][j+1]=1;
	commap[i][j+2]=1;
}
else if(map[i][j]==map[i+2][j]&&map[i][j]==map[i+4][j]) {    // 세로  
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+4][j]=1;
}
else if(map[i][j]==map[i+2][j]&&map[i][j]==map[i+2][j+1]) {    // ㄱ1  
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+2][j+1]=1;
}
else if(map[i][j]==map[i+2][j]&&map[i][j]==map[i][j+1]) {    // ㄱ2  
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i][j+1]=1;
}
else if(map[i][j]==map[i][j+1]&&map[i][j]==map[i+2][j+1]) {    // ㄴ1  
	commap[i][j]=1;
	commap[i][j+1]=1;
	commap[i+2][j+1]=1;
}
else if(map[i][j]==map[i+2][j]&&map[i][j]==map[i+2][j-1]) {    // ㄴ2  
	commap[i][j]=1;
	commap[i+2][j]=1;
	commap[i+2][j-1]=1;
}
		}
	}	
	j+=1;
		 }		
	j=0;
	i+=2;
}
j=1;
i=2;
i1=0;
while(j<=12&&option[6]==1){//레인보우 
	while(i<=12){
		while(i1<=6){
	if(map[i][j]==i1+1)
	othertact[i1]=1;
	i1+=1;	
	}
	i1=0;
	i+=2;
}
i=2;	
if(othertact[1]+othertact[2]+othertact[3]+othertact[4]+othertact[5]+othertact[6]+othertact[0]>=5&&option[6]==1){    
			i1=2;
			while(i1<=12){
				if(map[i1][j]!=0)
			commap[i1][j]=1;
			i1+=2;	
			}			
	        othertact[1]=0;
	        othertact[2]=0;
	        othertact[3]=0;
	        othertact[4]=0;
	        othertact[5]=0;
	        othertact[6]=0;
	        othertact[0]=0;
		}
else{
	othertact[1]=0;
	        othertact[2]=0;
	        othertact[3]=0;
	        othertact[4]=0;
	        othertact[5]=0;
	        othertact[6]=0;
	        othertact[0]=0;
}		
		j+=1;
	}

if(option[8]==1){
	i=0;
	j=0;
	while(i<=14){
		while(j<=14){
			if(map[i][j]==4&&map[i][j-4]==4&&map[i][j]*map[i][j-1]*map[i][j-2]*map[i][j-3]*map[i][j-4]==96){     //샌드위치  
	map[i][j-4]=0;
	map[i][j-3]=0;
	map[i][j-2]=0;
	map[i][j-1]=0;
	map[i][j]=150;
	chall_sandwich+=1;	
	}
	j+=1;
		}
		j=0;
		i+=2;
	} 
	
	
}

i=2;
j=0;
while(i<=14){
	while(j<=14){
		if(commap[i][j]==1){
		if(map[i][j]>=1&&map[i][j]<=7)
		map[i][j]=20;
		else if(map[i][j]>=1001&&map[i][j]<=1005&&option[7]==1)   //얼음  
		map[i][j]-=1000;
		
		
		destroy+=1;	
		score+=10; 
		puyocleared+=1;
		if(option[1]==1){
		if(map[i+2][j]==5){       //버블 난이도 어려움 방해뿌요 
		map[i+2][j]=20;
		destroy+=1;	
		chall_obstruct+=1;
		score+=10;
		}		
		if(map[i][j+1]==5){
		map[i][j+1]=20;
		destroy+=1;
		chall_obstruct+=1;
		score+=10;	
		}		
		if(map[i-2][j]==5){
		map[i-2][j]=20;
		destroy+=1;
		chall_obstruct+=1;
		score+=10;	
		}		
		if(map[i][j-1]==5){
		map[i][j-1]=20;
		destroy+=1;
		chall_obstruct+=1;
		score+=10;	
		}
		}
		
		if(option[2]==1){
		if(map[i+2][j]==30){       //방해뿌요 
		map[i+2][j]=20;
		destroy+=1;	
		chall_obstruct+=1;
		score+=10;
		}		
		if(map[i][j+1]==30){
		map[i][j+1]=20;
		destroy+=1;
		chall_obstruct+=1;
		score+=10;	
		}		
		if(map[i-2][j]==30){
		map[i-2][j]=20;
		destroy+=1;
		chall_obstruct+=1;
		score+=10;	
		}		
		if(map[i][j-1]==30){
		map[i][j-1]=20;
		destroy+=1;
		chall_obstruct+=1;
		score+=10;	
		}
		}
		bomb_fallscore_not_remove=0;
		if(option[3]==1){
			if(map[i+2][j]>=50&&map[i+2][j]<=55){       //폭탄 
		destroy+=1;	
		score+=(destroy*20)*(chain+1)*fallscore_plus;
	//	fall+=(map[i+2][j]-49)/2;    //하강 속도 초기화 
	    chall_bomb=map[i+2][j]-50;
		map[i+2][j]=20;
		bomb_fallscore_not_remove=1; 
		}		
		if(map[i][j+1]>=50&&map[i][j+1]<=55){
		destroy+=1;
		score+=(destroy*20)*(chain+1)*fallscore_plus;
	//	fall+=(map[i][j+1]-49)/2;    //하강 속도 초기화 
	chall_bomb=map[i][j+1]-50;
		map[i][j+1]=20;
		bomb_fallscore_not_remove=1;
		}		
		if(map[i-2][j]>=50&&map[i-2][j]<=55){
		destroy+=1;
		score+=(destroy*20)*(chain+1)*fallscore_plus;
	//	fall+=(map[i-2][j]-49)/2;    //하강 속도 초기화 
	chall_bomb=map[i-2][j]-50;
		map[i-2][j]=20;
		bomb_fallscore_not_remove=1;
		}		
		if(map[i][j-1]>=50&&map[i][j-1]<=55){
		destroy+=1;
		score+=(destroy*20)*(chain+1)*fallscore_plus;
	//	fall+=(map[i][j-1]-49)/2;    //하강 속도 초기화 
	chall_bomb=map[i][j-1]-50;
		map[i][j-1]=20;
		bomb_fallscore_not_remove=1;
		}
		}
		bomb_fallscore_not_remove=0;

		}
		
	j+=1;
		 }		
	j=0;
	i+=1;
}
subdestroy=destroy;
if(option[1]!=1){
while(subdestroy>=4){
	chain+=1;
	subdestroy-=4;
	chaintime=0;
}	
}
else if(option[1]==1){            //버블 
	while(subdestroy>=3){
	chain+=1;
	subdestroy-=3;
	chaintime=0;
}
	
}

if(option[0]!=1&&option[4]!=1&&option[5]!=1&&option[8]!=1)          
score+=(destroy*10+fallscore_plus)*chain_x[chain];//    점수계산 
else if(option[0]==1)
score+=(destroy*50+fallscore_plus)*chain_x[chain]*chain;//    점수계산
else if(option[4]==1)
score+=(destroy*10+fallscore_plus)*chain_x[chain]*(limit*0.2+1);//    점수계산
else if(option[5]==1){
	if(rev_mov[0]=='d')           //reverse 
	score+=(destroy*10+fallscore_plus)*chain_x[chain];//    점수계산
	else if(rev_mov[0]=='a')
	score+=(2*chain_x[chain])*(destroy*50+2*fallscore_plus);//    점수계산
}
else if(option[8]==1){
score+=(destroy*5+fallscore_plus)*chain_x[chain]*sandwich_plus;//    점수계산	
if(sandwich_plus>1)
chall_sandwich_score+=(destroy*5+fallscore_plus)*chain_x[chain]*sandwich_plus;//도전과제 
}

Gotxy(15,4);
textcolor(WHITE,LIGHTRED);
if(chain>=1&&chain<10){
	Sleep(50);
	cout<<chain<<" combo!";
}
else if(chain>=10){
	Sleep(50);
	cout<<chain<<" combo!!";
}



	
}

/////////////////////////////////////////////////////////////////////////


void startset(){                          //시작, 재시작 
	
	
	gravity=0;
	
	
	if(diff_select%3==0)
	limit=8;  //움직임 제한 
	if(diff_select%3==1)
	limit=6;  //움직임 제한
	if(diff_select%3==2)
	limit=5;  //움직임 제한
	
	i=0;
	j=0;
	while(j<=12){
		while(i<=12){
			if(map[i][j]>=50&&map[i][j]<=55){   //폭탄 하강 속도, 타이머  
			map[i][j]+=1;
        //    fall-=0.5;
			}			
		i+=1;
	}
	i=0;
	j+=1;
	}

	if(option[3]==1){
		tact=0;          //감지상수 tact
	}	
		srand((unsigned int)time(NULL));
   if(rand()%100<=70&&option[2]==1){
   	if(rand()%5==0){
   		if(map[2][1]==0)
   		map[2][1]=30;
	   }
	else if(rand()%5==1){
		if(map[4][1]==0)
		map[4][1]=30;
	   }
	else if(rand()%5==2){
		if(map[8][1]==0)
		map[8][1]=30;
	   }
	else if(rand()%5==3){
		if(map[10][1]==0)
		map[10][1]=30;
	   }
	else if(rand()%5==4){
		if(map[12][1]==0)
		map[12][1]=30;
	   }            
   } 
   tact=0;          //폭탄 없음 감지상수 tact
	i=0;
	j=0;
	while(j<=12){
		while(i<=12){
			if(map[i][j]>=50&&map[i][j]<=55){
			tact+=1;
			}
		i+=1;
	}
	i=0;
	j+=1;
	}
	if(tact==0&&option[3]==1){       //폭탄 랜덤 
   	if(rand()%5==0){
   		if(map[2][1]==0)
   		map[2][1]=50;
	   }
	else if(rand()%5==1){
		if(map[4][1]==0)
		map[4][1]=50;
	   }
	else if(rand()%5==2){
		if(map[8][1]==0)
		map[8][1]=50;
	   }
	else if(rand()%5==3){
		if(map[10][1]==0)
		map[10][1]=50;
	   }
	else if(rand()%5==4){
		if(map[12][1]==0)
		map[12][1]=50;
	   }            
   }	
   
    
	
	
	
	
	
	 //블럭 설치 전 종료감지 
	
	turn=1;
		mov_x=3*2;
	mov_y=1;
	mov_x1=3*2;
	mov_y1=0;



	if(block_rand==0)	{
		map[18][4]=1+rand()%blocktype;
	map[18][3]=1+rand()%blocktype;
	map[17][1]=1+rand()%blocktype;
	map[17][2]=1+rand()%blocktype;	
	map[mov_x][mov_y]=1+rand()%blocktype;
	mov=map[mov_x][mov_y];
	map[mov_x1][mov_y1]=1+rand()%blocktype;
	mov1=map[mov_x1][mov_y1];
	}	
	else if(block_rand>=1){
		
		
		
		if(rev_mov[0]=='d'&&option[5]==1){
		rev_mov[0]='a';
		rev_mov[1]='d';
		rev_mov[2]='w';
		rev_mov[3]='s';
	}
	else if(rev_mov[0]=='a'&&option[5]==1){          //reverse
	 rev_mov[0]='d';
	 rev_mov[1]='a';
	 rev_mov[2]='s';
	 rev_mov[3]='w';
	}
	
	map[mov_x][mov_y]=map[17][2];
	mov=map[mov_x][mov_y];
	map[mov_x1][mov_y1]=map[17][1];
	mov1=map[mov_x1][mov_y1];
	map[17][1]=map[18][3];
	map[17][2]=map[18][4];
	map[18][4]=1+rand()%blocktype;
	map[18][3]=1+rand()%blocktype;	
	}	
	block_rand+=1;	//처음 시작 감지를 위한 상수 (0이 시작) 
	if(option[0]==1){ //스피드 
		fall=7;
		fall-=(map[mov_x][mov_y]+map[mov_x1][mov_y1]+1)*0.5;
	}
}

/////////////////////////////////////////////////////////////////////////

void dis_mov(void){         //움직였을 때 아래 블럭 위치 표시 
	if(turn==3){
	i=0;
	j=0;
	while(i<=14){
		while(j<=13){
			if(map[i][j]==12||map[i][j]==11||map[i][j]==14||map[i][j]==13||map[i][j]==8||map[i][j]==9||map[i][j]==10)
			map[i][j]=0;
			j+=1;
		}
		j=0;
		i+=1;
	}
	j=1;
	while(map[mov_x1][mov_y1+j]==0){
		j+=1;
	}
	if(map[mov_x1][j+mov_y1-1]==0&&j+mov_y1-1!=mov_y1)
	map[mov_x1][j+mov_y1-1]=mov1+BLOCK;
	j=2;
	while(map[mov_x][j+mov_y]==0){
		j+=1;
	}
	if(map[mov_x][j+mov_y-1]==0&&j+mov_y-1!=mov_y)
	map[mov_x][j+mov_y-1]=mov+BLOCK;
}
else if(turn==1){
	i=0;
	j=0;
	while(i<=14){
		while(j<=13){
			if(map[i][j]==12||map[i][j]==11||map[i][j]==14||map[i][j]==13||map[i][j]==8||map[i][j]==9||map[i][j]==10)
			map[i][j]=0;
			j+=1;
		}
		j=0;
		i+=1;
	}
	j=1;
	while(map[mov_x][j+mov_y]==0){
		j+=1;
	}
	if(map[mov_x][j+mov_y-1]==0&&j+mov_y-1!=mov_y)
	map[mov_x][j+mov_y-1]=mov+BLOCK;
	j=2;
	while(map[mov_x1][mov_y1+j]==0){
		j+=1;
	}
	if(map[mov_x1][j+mov_y1-2]==0&&j+mov_y1-2!=mov_y1)
	map[mov_x1][j+mov_y1-2]=mov1+BLOCK;	
}
else if(turn==2||turn==4){
	i=0;
	j=0;
	while(i<=14){
		while(j<=13){
			if(map[i][j]==12||map[i][j]==11||map[i][j]==14||map[i][j]==13||map[i][j]==8||map[i][j]==9||map[i][j]==10)
			map[i][j]=0;
			j+=1;
		}
		j=0;
		i+=1;
	}
	j=1;
	while(map[mov_x][j+mov_y]==0){
		j+=1;
	}
	if(map[mov_x][j+mov_y-1]==0&&j+mov_y-1!=mov_y)
	map[mov_x][j+mov_y-1]=mov+BLOCK;
	j=1;
	while(map[mov_x1][mov_y1+j]==0){
		j+=1;
	}
	if(map[mov_x1][j+mov_y1-1]==0&&j+mov_y1-1!=mov_y1)
	map[mov_x1][j+mov_y1-1]=mov1+BLOCK;	
}
}

/////////////////////////////////////////////////////////////////////////

void unit_time(){	            //하강 
int block;


	Sleep(20);
	if(chall_say_time>=0)    //도전과제 달성 표시 시간 
		chall_say_time+=1;
	    if(chall_say_time>=21){
		Gotxy(17,1);
		textcolor(BLACK,BLACK);
		cout<<"                         ";
		chall_say_time=-1;
		}
	
	if(chain>maxchain){
		maxchain=chain;
	}                       //맥스 체인 
			
	if(chaintime>=12&&chain>=1&&bomb_fallscore_not_remove==0){       //연쇄 			
			chain=0;
			chaintime=0;
			if(option[7]!=1) //얼음  
			fallscore_plus=0;         //합산 
			else if(option[7]==1&&fallscore_plus>=100)
			fallscore_plus=50;		
			
			Gotxy(15,4);
			textcolor(BLACK,BLACK);
            printf("          ");        //combo 메세지 삭제 
		}	
if(entime>=fall){
	if(block_rand>=2){
	tact=0;          //all cleared 감지상수 tact          //  
	i=0;
	j=12;
	while(j>=2){
		while(i<=12){
			if(map[i][j]==1||map[i][j]==2||map[i][j]==3||map[i][j]==4||map[i][j]==5||map[i][j]==6||map[i][j]==7||map[i][j]==30)
			tact+=1;	
		i+=1;
	}
	i=0;
	j-=1;
	}	
	if(tact==0){
		allcleared+=1;
	}
	tact=0;   //공중에 있는 블럭 감지 상수             
}
	i=2;
	j=1;
	while(i<=12){
		while(j<=12){
			if(map[i][j]!=0&&map[i][j]!=11&&map[i][j]!=14&&map[i][j]!=13&&map[i][j]!=8&&map[i][j]!=9&&map[i][j]!=10&&map[i][j]!=12){
				if(map[i][j+1]==0){
					if(i!=mov_x&&j!=mov_y){
					tact+=1;	
					}
				}
				
			}
			else if(map[i][j]==20||map[i][j]==21||map[i][j]==22||map[i][j]==23||map[i][j]==24)
			tact+=1;
			j+=1;
		}
		j=1;
		i+=2;
	}
	if(tact==0){
	dis_mov();
	if(mov_y<13||mov_y1<13){
			if(turn!=3&&mov_y<13){
				mov_y+=1;
	mov_y1+=1;
	map[mov_x][mov_y-1]=0;
	map[mov_x1][mov_y1-1]=0;
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;
			}
	if(turn==3&&mov_y1<13){
				mov_y+=1;
	mov_y1+=1;
	map[mov_x][mov_y-1]=0;
	map[mov_x1][mov_y1-1]=0;
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;
			}
				
	}	
	}
	
	srand((unsigned int)time(NULL));
	
	if(option[7]==1){                  //얼음  
    icenum=2*(rand()%6)+2;
    if(map[icenum][iceheight]>=1&&map[icenum][iceheight]<=5&&rand()%101<=31)
   	map[icenum][iceheight]+=1000;
   	if(map[2][iceheight]>1000&&map[4][iceheight]>1000&&map[6][iceheight]>1000&&map[8][iceheight]>1000&&map[12][iceheight]>1000&&map[12][iceheight]>1000)
   	iceheight-=1;
   	if(iceheight<=1)
   	iceheight=12;
  }	
   	
   	if(option[8]==1){                  //샌드위치 
   i=0;
   j=0;
   while(i<=14){
   		while(j<=14){
   			if(map[i][j]>=150&&map[i][j]<=152)
   			sandwich_plus=chain_x[chain]+2;
   			if(map[i][j]==150&&rand()%15==0)
   			map[i][j]=151;
   			if(map[i][j]==151&&rand()%15==1)
   			map[i][j]=152;
   			if(map[i][j]==152&&rand()%15==2){
   			map[i][j]=0;	
   			sandwich_plus=1;
			   }
   			
			   
			   j+=1;
		   }
		   j=0;
		   i+=2;
   }
   
   }
	entime=0;
	
}



i=2;         //중력 
	j=1;
	while(i<=12){
		while(j<=12){
			if(map[i][j]!=0&&map[i][j+1]==0&&gravity==0){//아래 중력 
				if(j!=mov_y1||i!=mov_x1){
					if(j!=mov_y||i!=mov_x){
					block=map[i][j];
				map[i][j]=0;
				map[i][j+1]=block;	
					}
			}
			}
			else if(map[i][j]!=0&&map[i-1][j]==0&&gravity==1){//왼쪽 중력 
				if(map[i][j]>=1&&map[i][j]<=BLOCK) {
				if(map[i-2][j]==0||map[i-2][j]==1+BLOCK||map[i-2][j]==2+BLOCK||map[i-2][j]==3+BLOCK||map[i-2][j]==4+BLOCK||map[i-2][j]==5+BLOCK){
			    	if(j!=mov_y1||i!=mov_x1){
					if(j!=mov_y||i!=mov_x){
					block=map[i][j];
				map[i][j]=0;
				map[i-2][j]=block;	
					}
				}	
					}
					
				}	
			} 
			else if(map[i][j]!=0&&gravity==2){//오른쪽 중력 
			    if(map[i][j]>=1&&map[i][j]<=BLOCK) {
			    	if(map[i+2][j]==0||map[i+2][j]==1+BLOCK||map[i+2][j]==2+BLOCK||map[i+2][j]==3+BLOCK||map[i+2][j]==4+BLOCK||map[i+2][j]==5+BLOCK){
			    	if(j!=mov_y1||i!=mov_x1){
					if(j!=mov_y||i!=mov_x){
					block=map[i][j];
				map[i][j]=0;
				map[i+2][j]=block;	
					}
				}	
					}
					
				}							
		}
			if(map[i][j]==5&&map[i][j+1]>=0&&map[i][j+1]<=4&&option[1]==1){   //버블 
				if(j!=mov_y1||i!=mov_x1){
					if(j!=mov_y||i!=mov_x){
					block=map[i][j];
				map[i][j]=0;
				map[i][j+1]=block;	
					}
				}
				
			}
			j+=1;
		}
		j=1;
		i+=1;
	}	
	
	
		
		
				
}

/////////////////////////////////////////////////////////////////////////


void moving(void){      //움직임 관리 
if(kbhit()){
but=_getch();
if(but==rev_mov[0]&&limit>=1){        //왼쪽 
	if(option[4]==1)    //움직임 제한 
limit-=1;
	if(turn!=4&&mov_x>2&&map[mov_x-2][mov_y]==0){
map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
mov_x-=2;
mov_x1-=2;
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;
}
if(turn==4&&mov_x1>2&&map[mov_x1-2][mov_y1]==0){
map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
mov_x-=2;
 mov_x1-=2;
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;
}
dis_mov();
}
	            
else if(but==rev_mov[1]&&limit>=1){          //오른쪽 
	if(option[4]==1)    //움직임 제한 
limit-=1;
	if(turn!=2&&mov_x<12&&map[mov_x+2][mov_y]==0){
	map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
	mov_x+=2;
	mov_x1+=2;

	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;	
	}
	if(turn==2&&mov_x1<12&&map[mov_x1+2][mov_y1]==0){
map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
	mov_x+=2;
	mov_x1+=2;

	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;	
	}
	dis_mov();
}
				
else if(but==rev_mov[3]&&mov_y<=10&&mov_y1<=10){              //아래 
	if((turn==1&&map[mov_x][mov_y+1]==0)||(turn!=1&&map[mov_x1][mov_y1+1]==0)){
	dis_mov();
	if(mov_y<13||mov_y1<13){
		fallscore=0;
		score+=1;
		fallscore+=1;
		fallscore_plus+=1;
		if(turn!=3){
			map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
	mov_y+=1;
	mov_y1+=1;
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;
			}
	if(turn==3&&mov_y<13){
		map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
	mov_y1+=1;
	mov_y+=1;
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;
			}
	}
	dis_mov();	
	}
	
}
else if(but==rev_mov[2]&&limit>=1){              //돌리기 
	if(option[4]==1)    //움직임 제한 
limit-=1;
	if(mov_y<13||mov_y1<13){
		if(mov_y==mov_y1&&mov_x<mov_x1){             //2->3
	mov_y1+=1;
	mov_x1-=2;
	map[mov_x][mov_y]=0;
	map[mov_x1+2][mov_y1-1]=0;
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;
	turn=3;
}
else if(mov_y==mov_y1&&mov_x>mov_x1&&mov_y>1){             //4->1
	mov_y1-=1;
	mov_x1+=2;
	map[mov_x][mov_y]=0;
	map[mov_x1-2][mov_y1+1]=0;
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;
	turn=1;
}
else if(mov_x==mov_x1&&mov_y>mov_y1){             //1->2
map[mov_x][mov_y]=0;
	map[mov_x1][mov_y1]=0;
	if(mov_x<12&&map[mov_x+2][mov_y]==0){
	mov_y1+=1;
	mov_x1+=2;
	turn=2;	
	}	
	if(mov_x==12&&map[mov_x-2][mov_y]==0&&map[mov_x1-2][mov_y1]==0){ 
	mov_x-=2;
	mov_x1-=2;
	mov_y1+=1;
	mov_x1+=2;
	turn=2;	
	}
    if(map[mov_x+2][mov_y]!=0&&map[mov_x-2][mov_y]==0&&map[mov_x1-2][mov_y1]==0){
	mov_x-=2;
	mov_x1-=2;
	mov_y1+=1;
	mov_x1+=2;	
	turn=2;
	}
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;	
	
}
else if(mov_x==mov_x1&&mov_y<mov_y1){             //3->4
	map[mov_x][mov_y]=0;
	map[mov_x1][mov_y1]=0;
	if(mov_x>2&&map[mov_x-2][mov_y]==0){
	mov_y1-=1;
	mov_x1-=2;
	turn=4;	
	}	
	if(mov_x==2&&map[mov_x+2][mov_y]==0&&map[mov_x1+2][mov_y1]==0){
	mov_x+=2;
	mov_x1+=2;
	mov_y1-=1;
	mov_x1-=2;	
	turn=4;
	}
	if(map[mov_x-2][mov_y]!=0&&map[mov_x+2][mov_y]==0&&map[mov_x1+2][mov_y1]==0){
	mov_x+=2;
	mov_x1+=2;
	mov_y1-=1;
	mov_x1-=2;	
	turn=4;
	}
	map[mov_x][mov_y]=mov;
	map[mov_x1][mov_y1]=mov1;	
}
	}
	dis_mov();	
}
else if(but==' '&&mov_y>=0){          //강제 하강  
	if(mov_y<13||mov_y1<13){
		fallscore=0;
		if(turn==1&&mov_y<13){
while(map[mov_x][1+mov_y]==0){
	map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
mov_y+=1;
mov_y1+=1;
map[mov_x][mov_y]=mov;
map[mov_x1][mov_y1]=mov1;
		score+=1;
		fallscore+=1;
		fallscore_plus+=1;
}
			}
	else if(turn==2||turn==4){
while(map[mov_x][mov_y+1]==0&&map[mov_x1][mov_y1+1]==0){
	map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
mov_y+=1;
mov_y1+=1;
map[mov_x][mov_y]=mov;
map[mov_x1][mov_y1]=mov1; 
score+=1;
		fallscore+=1;
		fallscore_plus+=1;
}
			}
	else if(turn==3&&mov_y<13){
while(map[mov_x1][1+mov_y1]==0){
	map[mov_x][mov_y]=0;
map[mov_x1][mov_y1]=0;
mov_y1+=1;
mov_y+=1;
map[mov_x1][mov_y1]=mov1;
map[mov_x][mov_y]=mov;    
score+=1;
		fallscore+=1;
		fallscore_plus+=1;  
}
			}
	}
startset();	
}
else if(but=='j'&&option[9]==1){          //중력 방향 왼 
gravity=1; 
}
else if(but=='k'&&option[9]==1){          //중력 방향 왼 
gravity=0; 
}
else if(but=='l'&&option[9]==1){          //중력 방향 왼 
gravity=2; 
}
dis_mov();		    					
	}
}



/////////////////////////////////////////////////////////////////////////


void mapping(){     //멥 설정 
	i=1;
	j=0;
while(i<=13){
//	if(option[4]!=1)      //위치 제한		
	if(option[9]!=1)
	map[i][j]=100;
	if(i!=13||i!=12)
	map[i][j+13]=102; //점수와 겿침방지  		
	i+=1;		
	
	}
	if(option[9]==1){
		Gotxy(0,1);
	textcolor(WHITE,LIGHTBLUE);
	if(gravity==1)
	printf("     |←|    ");
	else if(gravity==0)
	printf("     |↓|    ");
	else if(gravity==2)
	printf("     |→|    ");
	textcolor(WHITE,BLACK);
	}	

//	if(option[4]==1){	          //위치 제한
//		Gotxy(0,1);
//	textcolor(WHITE,LIGHTBLUE);
//	printf("   LIMIT : %d ",limit);
//	textcolor(WHITE,BLACK);
//	}
	
i=1;
	j=0;	
while(j<=13){
	
	if(option[4]!=1){
	if(j!=0)
	map[i][j]=100;
	if(j!=13)
	map[i+13][j]=100;	
	}		
	else{
		if(j>11-limit&&j<=11){
			map[i][j]=101;
        	map[i+13][j]=101;
		}
		else if(j<=11-limit&&j>=2){
			map[i][j]=99;
        	map[i+13][j]=99;
        	
		}
		map[i][0]=100;
		map[i+13][0]=100;
		map[i][1]=100;
		map[i+13][1]=100;
		map[i][12]=100;
		map[i+13][12]=100;
		map[i][13]=100;
		map[i+13][13]=100;
	}
	
	
	j+=1;
	}
	
	j=0;	
while(j<=5){        //미리 	블럭 표시  
			
	map[16][j]=100;
	map[20][j]=100;	
	j+=1;
	}
i=16;	
while(i<=20){
			
	map[i][0]=100;
	map[i][5]=100;	
	i+=1;
	}
	
	
	Gotxy(13,2);
	if(rev_mov[0]=='a'&&option[8]!=1)
	textcolor(WHITE,LIGHTBLUE);           //reverse 
	else if(rev_mov[0]=='d')
	textcolor(WHITE,BROWN);
	else if(option[8]==1&&sandwich_plus!=1)   //샌드위치  
	textcolor(WHITE,LIGHTMAGENTA);
	else if(option[8]==1&&sandwich_plus==1)   //샌드위치  
	textcolor(WHITE,LIGHTBLUE);
	printf("  ");
	if(score<10)
	printf("0");
	if(score<100)
	printf("0");
	if(score<1000)
	printf("0");
	if(score<10000)
	printf("0");
	if(score<100000)
	printf("0");
	if(score<1000000)
	printf("0");
	if(score<10000000)
	printf("0");
	printf("%d ",score);
	textcolor(WHITE,BLACK);	
	
	if(rev_mov[0]=='a'){          //reverse 
	if(option[9]!=1){
		Gotxy(10,16);
    printf("| a/d : Left/Right");
    Gotxy(11,16);
    printf("| s/Space : Down/Drop");
    Gotxy(12,16);
    printf("| w : Rotate");
	}
	else if(option[9]==1){
		Gotxy(9,16);
    printf("| a/d : Left/Right");
    Gotxy(10,16);
    printf("| s/Space : Down/Drop");
    Gotxy(11,16);
    printf("| w : Rotate");
    Gotxy(12,16);
    printf("| j/k/l : Left/Down/Right (Gravity)");
	}
		
	}	
	
    else if(rev_mov[0]=='d'){
    	Gotxy(10,16);
    printf("| d/a : Left/Right");
    Gotxy(11,16);
    printf("| w/Space : Down/Drop");
    Gotxy(12,16);
    printf("| s : Rotate");
	}

map[1][0]=98;
map[13][13]=98;       //멥 양쪽 끝의 엣지  
	
	
}
/////////////////////////////////////////////////////////////////////////
void CursorView()             //커서 삭제 
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
/////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
int main(){         //메인 함수

vector <string> diffname = {"Sweet","Normal","Spicy"};
vector<string> optionname = {"None","Speed Star","Burble","Obstruct","Bomb","Limit","Reverse","Rainbow","Freeze","Sandwich","Gravity"};
SetConsoleTitle(TEXT("뿌요뿌요"));  //이름 바꾸기 
CursorView(); 
///////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
Gotxy(12,13);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(LIGHTRED,BLACK);
printf("▶");
Sleep(10);
system("cls");
Gotxy(4,12);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(WHITE,LIGHTRED);
printf("  ");
textcolor(LIGHTRED,BLACK);
printf("▶");
Sleep(10);
system("cls");
Gotxy(4,11);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(WHITE,LIGHTRED);
printf("    ");
textcolor(LIGHTRED,BLACK);
printf("▶");
Sleep(10);
system("cls");
Gotxy(4,10);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(WHITE,LIGHTRED);
printf("      ");
textcolor(LIGHTRED,BLACK);
printf("▶");
Sleep(10);
system("cls");
Gotxy(4,8);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(WHITE,LIGHTRED);
printf("    ＰＯ    ");
textcolor(LIGHTRED,BLACK);
printf("▶");
Sleep(10);
system("cls");
Gotxy(4,6);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(WHITE,LIGHTRED);
printf("    ＰＵＹＯ    ");
textcolor(LIGHTRED,BLACK);
printf("▶");
Sleep(10);
system("cls");
Gotxy(4,4);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(WHITE,LIGHTRED);
printf("    ＰＵＹＵＹＯ    ");
textcolor(LIGHTRED,BLACK);
printf("▶");
Sleep(10);
system("cls");
Gotxy(4,2);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(WHITE,LIGHTRED);
printf("    ＰＵＹＯ ＰＵＹＯ    ");
textcolor(LIGHTRED,BLACK);
printf("▶");
///////////////////////////////////////////////////////////
while(1){
Gotxy(2,1);
textcolor(RED,BLACK);
printf("●");
Gotxy(0,14);
textcolor(LIGHTGREEN,BLACK);
printf("●");
Gotxy(1,25);
textcolor(BLUE,BLACK);
printf("●");
Gotxy(8,30);
textcolor(BROWN,BLACK);
printf("●");
Gotxy(10,19);
textcolor(MAGENTA,BLACK);
printf("●");
Gotxy(10,10);
textcolor(LIGHTGREEN,BLACK);
printf("●");
Gotxy(8,2);
textcolor(BROWN,BLACK);
printf("●");
///////////////////

Gotxy(4,2);
textcolor(LIGHTRED,BLACK);
printf("◀");
textcolor(WHITE,LIGHTRED);
printf("    ＰＵＹＯ ＰＵＹＯ    ");
textcolor(LIGHTRED,BLACK);
printf("▶");
textcolor(WHITE,BLACK);
///////////////////
Gotxy(6,2);
printf("     Press 'q' To Start   ");
Sleep(250);

if(kbhit()){
but=_getch();
if(but=='q'){
	blocktype=4;
	fall=10;
	limit=6; //normal
	diff_select=1;         //기본 난이도 
goto Manu;
}

}

Gotxy(6,2);
printf("                          ");
Sleep(250);



}
///////////////////////////////////////////////////////////
Manu :
	system("cls");
	////////////////////////////////////////////////////////////	
	while(1){	
	if(start_select!=0){
	Gotxy(2,6);	
	textcolor(BROWN,BLACK);
	printf("  ■");
	textcolor(WHITE,BROWN);
	printf("          ");
	Gotxy(3,6);
	textcolor(BROWN,BLACK);
	printf("■");
	textcolor(WHITE,BROWN);
    printf("ＳＴＡＲＴ");
    textcolor(BROWN,BLACK);
    printf("■");
    Gotxy(4,6);
    textcolor(WHITE,BROWN);
    printf("          ");
    textcolor(BROWN,BLACK);
    printf("■  ");
	}
	else if(start_select==0){
	Gotxy(2,6);	
	textcolor(WHITE,BLACK);
	printf("  ■");
	textcolor(BROWN,WHITE);
	printf("          ");
	Gotxy(3,6);
	textcolor(WHITE,BLACK);
	printf("■");
	textcolor(BROWN,WHITE);
    printf("ＳＴＡＲＴ");
    textcolor(WHITE,BLACK);
    printf("■");
    Gotxy(4,6);
    textcolor(BROWN,WHITE);
    printf("          ");
    textcolor(WHITE,BLACK);
    printf("■  ");
	}
    if(start_select!=3){
	Gotxy(6,2);	
	textcolor(LIGHTRED,BLACK);
	printf("  ■");
	textcolor(WHITE,LIGHTRED);
	printf("          ");
	Gotxy(7,2);
	textcolor(LIGHTRED,BLACK);
	printf("■");
	textcolor(WHITE,LIGHTRED);
    printf("  OPTION  ");
    textcolor(LIGHTRED,BLACK);
    printf("■");
    Gotxy(8,2);
    textcolor(WHITE,LIGHTRED);
    printf("          ");
    textcolor(LIGHTRED,BLACK);
    printf("■  ");
	}
	else if(start_select==3){
	Gotxy(6,2);	
	textcolor(WHITE,BLACK);
	printf("  ■");
	textcolor(LIGHTRED,WHITE);
	printf("          ");
	Gotxy(7,2);
	textcolor(WHITE,BLACK);
	printf("■");
	textcolor(LIGHTRED,WHITE);
    printf("  OPTION  ");
    textcolor(WHITE,BLACK);
    printf("■");
    Gotxy(8,2);
    textcolor(LIGHTRED,WHITE);
    printf("          ");
    textcolor(WHITE,BLACK);
    printf("■  ");
	}
    if(start_select!=4){
	Gotxy(6,17);	
	textcolor(CYAN,BLACK);
	printf("  ■");
	textcolor(WHITE,CYAN);
	printf("          ");
	Gotxy(7,17);
	textcolor(CYAN,BLACK);
	printf("■");
	textcolor(WHITE,CYAN);
    printf(" HANDICAP ");
    textcolor(CYAN,BLACK);
    printf("■");
    Gotxy(8,17);
    textcolor(WHITE,CYAN);
    printf("          ");
    textcolor(CYAN,BLACK);
    printf("■  ");
	}
	else if(start_select==4){
	Gotxy(6,17);	
	textcolor(WHITE,BLACK);
	printf("  ■");
	textcolor(CYAN,WHITE);
	printf("          ");
	Gotxy(7,17);
	textcolor(WHITE,BLACK);
	printf("■");
	textcolor(CYAN,WHITE);
    printf(" HANDICAP ");
    textcolor(WHITE,BLACK);
    printf("■");
    Gotxy(8,17);
    textcolor(CYAN,WHITE);
    printf("          ");
    textcolor(WHITE,BLACK);
    printf("■  ");
	}
    if(start_select!=1){
	Gotxy(2,21);	
	textcolor(LIGHTMAGENTA,BLACK);
	printf("  ■");
	textcolor(WHITE,LIGHTMAGENTA);
	printf("          ");
	Gotxy(3,21);
	textcolor(LIGHTMAGENTA,BLACK);
	printf("■");
	textcolor(WHITE,LIGHTMAGENTA);
    printf(" STANDING ");
    textcolor(LIGHTMAGENTA,BLACK);
    printf("■");
    Gotxy(4,21);
    textcolor(WHITE,LIGHTMAGENTA);
    printf("          ");
    textcolor(LIGHTMAGENTA,BLACK);
    printf("■  ");
	}
	else if(start_select==1){
	Gotxy(2,21);	
	textcolor(WHITE,BLACK);
	printf("  ■");
	textcolor(LIGHTMAGENTA,WHITE);
	printf("          ");
	Gotxy(3,21);
	textcolor(WHITE,BLACK);
	printf("■");
	textcolor(LIGHTMAGENTA,WHITE);
    printf(" STANDING ");
    textcolor(WHITE,BLACK);
    printf("■");
    Gotxy(4,21);
    textcolor(LIGHTMAGENTA,WHITE);
    printf("          ");
    textcolor(WHITE,BLACK);
    printf("■  ");
	}
	if(start_select!=2){
	Gotxy(2,36);	
	textcolor(LIGHTBLUE,BLACK);
	printf("  ■");
	textcolor(WHITE,LIGHTBLUE);
	printf("          ");
	Gotxy(3,36);
	textcolor(LIGHTBLUE,BLACK);
	printf("■");
	textcolor(WHITE,LIGHTBLUE);
    printf("   CODE   ");
    textcolor(LIGHTBLUE,BLACK);
    printf("■");
    Gotxy(4,36);
    textcolor(WHITE,LIGHTBLUE);
    printf("          ");
    textcolor(LIGHTBLUE,BLACK);
    printf("■  ");
	}
	else if(start_select==2){
	Gotxy(2,36);	
	textcolor(WHITE,BLACK);
	printf("  ■");
	textcolor(LIGHTBLUE,WHITE);
	printf("          ");
	Gotxy(3,36);
	textcolor(WHITE,BLACK);
	printf("■");
	textcolor(LIGHTBLUE,WHITE);
    printf("   CODE   ");
    textcolor(WHITE,BLACK);
    printf("■");
    Gotxy(4,36);
    textcolor(LIGHTBLUE,WHITE);
    printf("          ");
    textcolor(WHITE,BLACK);
    printf("■  ");
	}
	if(start_select!=5){
	Gotxy(6,32);	
	textcolor(LIGHTGREEN,BLACK);
	printf("  ■");
	textcolor(WHITE,LIGHTGREEN);
	printf("          ");
	Gotxy(7,32);
	textcolor(LIGHTGREEN,BLACK);
	printf("■");
	textcolor(WHITE,LIGHTGREEN);
    printf("CHALLENGE!");
    textcolor(LIGHTGREEN,BLACK);
    printf("■");
    Gotxy(8,32);
    textcolor(WHITE,LIGHTGREEN);
    printf("          ");
    textcolor(LIGHTGREEN,BLACK);
    printf("■  ");
	}
	else if(start_select==5){
	Gotxy(6,32);	
	textcolor(WHITE,BLACK);
	printf("  ■");
	textcolor(LIGHTGREEN,WHITE);
	printf("          ");
	Gotxy(7,32);
	textcolor(WHITE,BLACK);
	printf("■");
	textcolor(LIGHTGREEN,WHITE);
    printf("CHALLENGE!");
    textcolor(WHITE,BLACK);
    printf("■");
    Gotxy(8,32);
    textcolor(LIGHTGREEN,WHITE);
    printf("          ");
    textcolor(WHITE,BLACK);
    printf("■  ");
	}
////////////////////////////////////////////////////////////       //난이도 옵션 선택 디스플래잉  
textcolor(WHITE,BLACK);
Gotxy(12,20);
cout<<"| Handicap : "<<diffname.at(diff_select%3);
Gotxy(13,20);
cout<<"| Option : "<<optionname.at(op_select%OPTYPE);
////////////////////////////////////////////////////////////
    if(kbhit()){
but=_getch();
if(but=='w'){
	if(start_select>=3)
	start_select-=3;
}
else if(but=='s'){
	if(start_select<3)
	start_select+=3;
}
else if(but=='a'){
	if(start_select==1||start_select==2||start_select==4||start_select==5)
	start_select-=1;
    else if(start_select==0||start_select==3)
	start_select+=2;
}
else if(but=='d'){
	if(start_select==1||start_select==0||start_select==4||start_select==3)
	start_select+=1;
	else if(start_select==2||start_select==5)
	start_select-=2;
}
else if(but=='q'){
	if(start_select==0)
	goto Start;
	else if(start_select==3)
	goto Option;
	else if(start_select==4)
	goto Diff;
	else if(start_select==1){
	stand_select=0;
	goto Standing;	
}
	else if(start_select==5)
	goto Chall;
	else if(start_select==2)
	goto Code;
	
}	
}
textcolor(WHITE,BLACK);
Gotxy(12,2);
    printf("w/a/s/d : Move");
    Gotxy(13,2);
    printf("q : Select");
	}
	///////////////////////////////////////////////////////////
Standing :
	system("cls");
	
	while(1){
if(stand_select%3!=0)
textcolor(WHITE,CYAN);
else if(stand_select%3==0)
textcolor(CYAN,WHITE);		
Gotxy(5,12);	
printf("  Sweet!  ");
textcolor(WHITE,BLACK);	
if(stand_select%3!=1)
textcolor(WHITE,CYAN);	
else if(stand_select%3==1)
textcolor(CYAN,WHITE);
Gotxy(5,24);	
printf("  Normal  ");
textcolor(WHITE,BLACK);
if(stand_select%3!=2)
textcolor(WHITE,CYAN);
else if(stand_select%3==2)
textcolor(CYAN,WHITE);
Gotxy(5,36);	
printf("  Spicy!  ");
textcolor(WHITE,BLACK);		
		
		
Gotxy(7,2);	
printf("   Name");	
Gotxy(7,22);	
printf("| Score");
Gotxy(7,32);	
printf("| All_C");
Gotxy(7,42);	
printf("| Puyo_C");
Gotxy(7,52);	
printf("| Maxchain");

if(stand_select%3==0){

	file_read1(NAME);
file_read1(SCORE);
file_read1(ALLCLEARED);
file_read1(PUYOCLEARED);
file_read1(MAXCHAIN);

file_read2(NAME);
file_read2(SCORE);
file_read2(ALLCLEARED);
file_read2(PUYOCLEARED);
file_read2(MAXCHAIN);

file_read3(NAME);
file_read3(SCORE);
file_read3(ALLCLEARED);
file_read3(PUYOCLEARED);
file_read3(MAXCHAIN);

file_read4(NAME);
file_read4(SCORE);
file_read4(ALLCLEARED);
file_read4(PUYOCLEARED);
file_read4(MAXCHAIN);


file_read5(NAME);
file_read5(SCORE);
file_read5(ALLCLEARED);
file_read5(PUYOCLEARED);
file_read5(MAXCHAIN);
}
else if(stand_select%3==1){

file_read6(NAME);
file_read6(SCORE);
file_read6(ALLCLEARED);
file_read6(PUYOCLEARED);
file_read6(MAXCHAIN);

file_read7(NAME);
file_read7(SCORE);
file_read7(ALLCLEARED);
file_read7(PUYOCLEARED);
file_read7(MAXCHAIN);

file_read8(NAME);
file_read8(SCORE);
file_read8(ALLCLEARED);
file_read8(PUYOCLEARED);
file_read8(MAXCHAIN);

file_read9(NAME);
file_read9(SCORE);
file_read9(ALLCLEARED);
file_read9(PUYOCLEARED);
file_read9(MAXCHAIN);

	file_read10(NAME);
file_read10(SCORE);
file_read10(ALLCLEARED);
file_read10(PUYOCLEARED);
file_read10(MAXCHAIN);
}
else if(stand_select%3==2){
	file_read11(NAME);
file_read11(SCORE);
file_read11(ALLCLEARED);
file_read11(PUYOCLEARED);
file_read11(MAXCHAIN);

file_read12(NAME);
file_read12(SCORE);
file_read12(ALLCLEARED);
file_read12(PUYOCLEARED);
file_read12(MAXCHAIN);

file_read13(NAME);
file_read13(SCORE);
file_read13(ALLCLEARED);
file_read13(PUYOCLEARED);
file_read13(MAXCHAIN);

file_read14(NAME);
file_read14(SCORE);
file_read14(ALLCLEARED);
file_read14(PUYOCLEARED);
file_read14(MAXCHAIN);

	file_read15(NAME);
file_read15(SCORE);
file_read15(ALLCLEARED);
file_read15(PUYOCLEARED);
file_read15(MAXCHAIN);
}

	Gotxy(2,22);
	textcolor(WHITE,CYAN);
    printf("   Standing   ");
    Gotxy(20,2);
    textcolor(WHITE,BLACK);
    printf("a/d : left/Right");
    Gotxy(21,2);
    textcolor(WHITE,BLACK);
    printf("q : Out");
    
	if(kbhit()){      //클릭 감지 
but=_getch();

if(but=='a'||but=='d'){
if(but=='a'){
	stand_select-=1;
	if(stand_select==-1)
	stand_select=2;
}
else if(but=='d'){
	stand_select+=1;
}
i=0;
		j=8;
		while(i<=60){
			while(j<=19){
				Gotxy(j,i);
				printf(" ");
				j+=1;
			}
			j=8;
			i+=1;
		}	
}

else if(but=='q'){
	goto Manu;
}
}

}
///////////////////////////////////////////////////////////
Diff :
	system("cls");
	while(1){
	Gotxy(2,10);
	textcolor(WHITE,CYAN);
    printf("   Handicap   ");
    Gotxy(5,12);
    textcolor(WHITE,BLACK);
    printf("■");
    textcolor(CYAN,WHITE);
    printf("  ▲  ");
    textcolor(WHITE,BLACK);
    printf("■");
    
    if(diff_select%3==0){         //Sweet 
    Gotxy(6,12);
    textcolor(YELLOW,WHITE);
    printf("■");
    textcolor(BROWN,YELLOW);
    printf("      ");
    textcolor(YELLOW,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(BROWN,YELLOW);
    printf("  Sweet!  ");
	Gotxy(8,12);
    textcolor(YELLOW,WHITE);
    printf("■");
    textcolor(BROWN,YELLOW);
    printf("      ");
    textcolor(YELLOW,WHITE);
    printf("■");
	blocktype=3;
	fall=14;
	limit=8;          //위치 제한	
	}
	else if(diff_select%3==1){         //Normal 
    Gotxy(6,12);
    textcolor(BROWN,WHITE);
    printf("■");
    textcolor(BROWN,BROWN);
    printf("      ");
    textcolor(BROWN,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(YELLOW,BROWN);
    printf("  Normal  ");
	Gotxy(8,12);	
	textcolor(BROWN,WHITE);
    printf("■");
    textcolor(BROWN,BROWN);
    printf("      ");
    textcolor(BROWN,WHITE);
    printf("■");
	blocktype=4;
	fall=10;
	limit=6;          //위치 제한	
	}
	else if(diff_select%3==2){         //Spicy
    Gotxy(6,12);
    textcolor(RED,WHITE);
    printf("■");
    textcolor(RED,RED);
    printf("      ");
    textcolor(RED,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,RED);
    printf("  Spicy!  ");
	Gotxy(8,12);	
	textcolor(RED,WHITE);
    printf("■");
    textcolor(RED,RED);
    printf("      ");
    textcolor(RED,WHITE);
    printf("■");	
    blocktype=5;
	fall=7;
	limit=5;          //위치 제한
	}
	
    Gotxy(9,12);
    textcolor(WHITE,BLACK);
    printf("■");
    textcolor(CYAN,WHITE);
    printf("  ▼  ");
    textcolor(WHITE,BLACK);
    printf("■");	
    Gotxy(13,2);
    printf("w/s : Up/Down");
    Gotxy(14,2);
    printf("q : Select & Out");

	if(kbhit()){
but=_getch();
if(but=='w'){
	if(diff_select>=1)
	diff_select-=1;
	else if(diff_select==0)
	diff_select=2;
}
else if(but=='s'){
	diff_select+=1;
	if(diff_select>=3)
	diff_select=0;
}
else if(but=='q'){
	goto Manu;
}	
}
	}
	///////////////////////////////////////////////////////////
	Option :
		option[0]=0;
		option[1]=0;
		option[2]=0;
		option[3]=0;
		option[4]=0;
		option[5]=0;
		option[6]=0;
		option[7]=0;
		option[8]=0;
		option[9]=0;
	system("cls");
	while(1){
	Gotxy(2,10);
	textcolor(WHITE,CYAN);
    printf("    Option    ");
    Gotxy(5,12);
    textcolor(WHITE,BLACK);
    printf("■");
    textcolor(CYAN,WHITE);
    printf("  ▲  ");
    textcolor(WHITE,BLACK);
    printf("■");
    
    if(op_select%OPTYPE==0){         //None 
	Gotxy(6,12);
    textcolor(LIGHTGRAY,WHITE);
    printf("■");
    textcolor(WHITE,LIGHTGRAY);
    printf("      ");
    textcolor(LIGHTGRAY,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,LIGHTGRAY);
    printf("   None   ");
	Gotxy(8,12);
    textcolor(LIGHTGRAY,WHITE);
    printf("■");
    textcolor(WHITE,LIGHTGRAY);
    printf("      ");
    textcolor(LIGHTGRAY,WHITE);
    printf("■");	
    textcolor(DARKGRAY,BLACK);
    Gotxy(11,3);
    textcolor(DARKGRAY,BLACK);
	printf("                                ");
	}
    else if(op_select%OPTYPE==1){         //Speed
    Gotxy(6,12);
    textcolor(BROWN,WHITE);
    printf("★");
    textcolor(BROWN,YELLOW);
    printf("      ");
    textcolor(BROWN,WHITE);
    printf("★");
    Gotxy(7,12);
    textcolor(BROWN,YELLOW);
    printf("Speed Star");
	Gotxy(8,12);
    textcolor(BROWN,WHITE);
    printf("★");
    textcolor(BROWN,YELLOW);
    printf("      ");
    textcolor(BROWN,WHITE);
    printf("★");
	}
	else if(op_select%OPTYPE==2){         //burble 
    Gotxy(6,12);
    textcolor(LIGHTBLUE,WHITE);
    printf("■");
    textcolor(WHITE,LIGHTBLUE);
    printf("      ");
    textcolor(LIGHTBLUE,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,LIGHTBLUE);
    printf("  Burble  ");
	Gotxy(8,12);	
    textcolor(LIGHTBLUE,WHITE);
    printf("■");
    textcolor(WHITE,LIGHTBLUE);
    printf("      ");
    textcolor(LIGHTBLUE,WHITE);
    printf("■");	
	}
	else if(op_select%OPTYPE==3){         //Obstruct
    Gotxy(6,12);
    textcolor(DARKGRAY,WHITE);
    printf("■");
    textcolor(DARKGRAY,DARKGRAY);
    printf("      ");
    textcolor(DARKGRAY,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,DARKGRAY);
    printf(" Obstruct ");
	Gotxy(8,12);	
	textcolor(DARKGRAY,WHITE);
    printf("■");
    textcolor(DARKGRAY,DARKGRAY);
    printf("      ");
    textcolor(DARKGRAY,WHITE);
    printf("■");	
	}
	else if(op_select%OPTYPE==4){         //Bomb
    Gotxy(6,12);
    textcolor(RED,WHITE);
    printf("■");
    textcolor(RED,RED);
    printf("      ");
    textcolor(RED,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,RED);
    printf("   Bomb   ");
	Gotxy(8,12);	
	textcolor(RED,WHITE);
    printf("■");
    textcolor(RED,RED);
    printf("      ");
    textcolor(RED,WHITE);
    printf("■");	
	}
	else if(op_select%OPTYPE==5){         //Limit
    Gotxy(6,12);
    textcolor(LIGHTRED,WHITE);
    printf("■");
    textcolor(RED,LIGHTRED);
    printf("      ");
    textcolor(LIGHTRED,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,LIGHTRED);
    printf("  Limit!  ");
	Gotxy(8,12);	
	textcolor(LIGHTRED,WHITE);
    printf("■");
    textcolor(RED,LIGHTRED);
    printf("      ");
    textcolor(LIGHTRED,WHITE);
    printf("■");	
	}
	else if(op_select%OPTYPE==6){         //Reverse
    Gotxy(6,12);
    textcolor(BROWN,WHITE);
    printf("■");
    textcolor(RED,BROWN);
    printf("      ");
    textcolor(BROWN,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,LIGHTBLUE);
    printf(" Reve");
    textcolor(WHITE,BROWN);
    printf("rse! ");
	Gotxy(8,12);	
	textcolor(LIGHTBLUE,WHITE);
    printf("■");
    textcolor(RED,LIGHTBLUE);
    printf("      ");
    textcolor(LIGHTBLUE,WHITE);
    printf("■");	
	}
else if(op_select%OPTYPE==7){         //Rainbow
    Gotxy(6,12);
    textcolor(LIGHTGREEN,WHITE);
    printf("■");
    textcolor(RED,LIGHTMAGENTA);
    printf("      ");
    textcolor(CYAN,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,LIGHTRED);
    printf(" Rainbow! ");
	Gotxy(8,12);	
	textcolor(CYAN,WHITE);
    printf("■");
    textcolor(RED,LIGHTMAGENTA);
    printf("      ");
    textcolor(LIGHTGREEN,WHITE);
    printf("■");	
	}
else if(op_select%OPTYPE==8){         //Freeze
    Gotxy(6,12);
    textcolor(LIGHTBLUE,WHITE);
    printf("■");
    textcolor(BLACK,CYAN);
    printf("      ");
    textcolor(LIGHTBLUE,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,CYAN);
    printf("  Freeze  ");
	Gotxy(8,12);	
	textcolor(LIGHTBLUE,WHITE);
    printf("■");
    textcolor(BLACK,CYAN);
    printf("      ");
    textcolor(LIGHTBLUE,WHITE);
    printf("■");	   
	}
else if(op_select%OPTYPE==9){         //sandwich
    Gotxy(6,12);
    textcolor(BROWN,WHITE);
    printf("■");
    textcolor(BROWN,BROWN);
    printf("      ");
    textcolor(BROWN,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,LIGHTRED);
    printf(" Sand");
    Gotxy(7,17);
    textcolor(WHITE,LIGHTGREEN);
    printf("wich ");
	Gotxy(8,12);	
	textcolor(BROWN,WHITE);
    printf("■");
    textcolor(BROWN,BROWN);
    printf("      ");
    textcolor(BROWN,WHITE);
    printf("■");	
	}	
	else if(op_select%OPTYPE==10){         //Freeze
    Gotxy(6,12);
    textcolor(LIGHTMAGENTA,WHITE);
    printf("■");
    textcolor(BLACK,MAGENTA);
    printf("      ");
    textcolor(LIGHTMAGENTA,WHITE);
    printf("■");
    Gotxy(7,12);
    textcolor(WHITE,MAGENTA);
    printf(" Gravity! ");
	Gotxy(8,12);	
	textcolor(LIGHTMAGENTA,WHITE);
    printf("■");
    textcolor(BLACK,MAGENTA);
    printf("      ");
    textcolor(LIGHTMAGENTA,WHITE);
    printf("■");	
	}
if(op_select%OPTYPE!=0){
	Gotxy(11,3);
    textcolor(DARKGRAY,BLACK);
    printf("(Score Is Recorded Only In None)");
}	
    Gotxy(9,12);
    textcolor(WHITE,BLACK);
    printf("■");
    textcolor(CYAN,WHITE);
    printf("  ▼  ");
    textcolor(WHITE,BLACK);
    printf("■");	
    Gotxy(14,2);
    printf("w/s : Up/Down");
    Gotxy(15,2);
    printf("q : Select & Out");
    Gotxy(16,2);
    printf("0~9 : Shortcut key");
    
	if(kbhit()){
but=_getch();
if(but=='w'){
	if(op_select==0)
	op_select=OPTYPE-gravity_use;
	if(op_select>=1)
	op_select-=1;	
}
else if(but=='s'){
	op_select+=1;
	if(op_select==OPTYPE-gravity_use)
	op_select=0;
}


else if(but=='q'){
	if(op_select%OPTYPE==1){
	option[0]=1;            //스피드 
	}
	else if(op_select%OPTYPE==2){
	option[1]=1;
		            //버블 
	}
	else if(op_select%OPTYPE==3){
	option[2]=1;	            //방해뿌요 
	}
	else if(op_select%OPTYPE==4){
	option[3]=1;	            //폭탄 
	}
	else if(op_select%OPTYPE==5){
	option[4]=1;	            //움직임 제한 
	}
	else if(op_select%OPTYPE==6){
	option[5]=1;	            //reverse
	
	}
	else if(op_select%OPTYPE==7){
	option[6]=1;	            //레인보우 
	}
	else if(op_select%OPTYPE==8){
	option[7]=1;	            //얼음 
	}
	else if(op_select%OPTYPE==9){
	option[8]=1;	            //샌드위치  
	}
	else if(op_select%OPTYPE==10){
	option[9]=1;	            //중력   
	}
	goto Manu;
}
else if(but=='0')
op_select=0;
else if(but=='1')
op_select=1;	
else if(but=='2')
op_select=2;	
else if(but=='3')
op_select=3;	
else if(but=='4')
op_select=4;	
else if(but=='5')
op_select=5;
else if(but=='6')
op_select=6;	
else if(but=='7')
op_select=7;	
else if(but=='8')
op_select=8;	
else if(but=='9')
op_select=9;		
	
}
}
/////////////////////////////////////////
///////////////////////////////////////////
Chall :
system("cls");

fin.open("challenge.txt");//도전과제   
fin>>file_int;
fin.close();
i=0;
while(i<=11){
	powtrans=pow(10,i);
	chall_type_plus[i]=(file_int%(powtrans*10)-file_int%powtrans)/powtrans;
	i+=1;
}
i2=0;
i1=1;
j1=0;
while(j1<=11){   //돚전과제 개수 
	i=6*(chall_type[j1]+ chall_type_plus[j1]);
	j=0;
	while(j<=31){
		while(i<=6*(chall_type[j1]+ chall_type_plus[j1])+6){
			dis_chall[i-6*(chall_type[j1]+ chall_type_plus[j1])+6*j1][j]=dis_chall_copy[i][j];
			i+=1;
		}
		i=6*(chall_type[j1]+ chall_type_plus[j1]);
		j+=1;
}
j1+=1;
}

	while(1){
	
		Gotxy(2,10);
	textcolor(WHITE,CYAN);
    printf("  Challenge!  ");
  //////////////////////////////////   스크롤  
    textcolor(DARKGRAY,DARKGRAY);
    j=0;
    while(j<=16){
    	if(i2/3.2!=j){
    	Gotxy(j+5,33);
    	printf(" ");	
		}   
    j+=1;
	}
	textcolor(LIGHTGRAY,LIGHTGRAY);
    Gotxy(i2/3.2+5,33);
    printf(" ");
  ////////////////////////////////////  
Gotxy(4,5);
textcolor(WHITE,BLACK);
    printf("■");
    textcolor(CYAN,WHITE);
    printf("         ▲         ");
    textcolor(WHITE,BLACK);
    printf("■");
    
i=0;
j=0;
while(j<=31){
	while(i<=16){
	if(dis_chall[i+i1][j]!='~'){
		if(((i+i1)/6)%2==0)
		textcolor(WHITE,CYAN);
		else if(((i+i1)/6)%2==1)
		textcolor(WHITE,LIGHTBLUE);  //색깔 번갈아감  
	}	
	else if(dis_chall[i+i1][j]=='~')
	textcolor(BLACK,BLACK);
	if((i+i1)%6==4&&j>=2&&j<=27&&dis_chall[i+i1][3]=='1')//완료한 상태가 아닌 상태일 때 도전과제 단계 흰색 바탕 
	textcolor(DARKGRAY,WHITE);
	Gotxy(i+5,j+2);
		cout<<dis_chall[i+i1][j];
	i+=1;		
	}
	i=0;
	j+=1;
}
Gotxy(22,5);
textcolor(WHITE,BLACK);
    printf("■");
    textcolor(CYAN,WHITE);
    printf("         ▼         ");
    textcolor(WHITE,BLACK);
    printf("■");
    textcolor(WHITE,BLACK);
    Gotxy(24,2);
    printf("w/s : Up/Down");
    Gotxy(25,2);
    printf("q : Out");
    
	if(kbhit()){
but=_getch();
if(but=='w'){
	if(i1!=1){
	i1-=1;	
	i2-=1;
	}
	
}
else if(but=='s'){      //한 개 추가될 때 마다 +6 
	if(i1!=55){
	i1+=1;	
	i2+=1;
	}
	
}
else if(but=='q'){
		goto Manu;
}
}
}
////////////////////////////////////////
    Code :
    	i1=0;
    	i=0;
    	while(i<=7){
    		code[i]=' ';
    		i+=1;
		}
	system("cls");
	Gotxy(2,9);
	textcolor(WHITE,CYAN);
    printf("    Code!    ");	
    Gotxy(6,5);
    textcolor(WHITE,BLACK);
    printf("■");
    textcolor(WHITE,WHITE);
    printf("                 ");
    textcolor(WHITE,BLACK);
    printf("■");
	
	if(i1==0)
	textcolor(BLACK,WHITE);
	else if(i1>=2&&i1<=4)
	textcolor(RED,WHITE);
	else if(i1>=6&&i1<=8)
	textcolor(LIGHTRED,WHITE);
	else if(i1>=10&&i1<=14)
	textcolor(BROWN,WHITE);
	else if(i1==16)
	textcolor(LIGHTGREEN,WHITE);
    Gotxy(7,5);
	printf("ㆍ");
	Gotxy(7,24);
	printf("ㆍ");
	i=0;
    while(i<=16){
    if(i%2==1)
    textcolor(WHITE,DARKGRAY);
    else if(i%2==0)
    textcolor(WHITE,WHITE);
	Gotxy(7,7+i);
	printf(" ");
		i+=1;
	}
	textcolor(WHITE,WHITE);
	Gotxy(8,5);
    textcolor(WHITE,BLACK);
    printf("■");
    textcolor(WHITE,WHITE);
    printf("                 ");
    textcolor(WHITE,BLACK);
    printf("■");
    //////////
	while(1){
	
	if(i1==0)
	textcolor(BLACK,WHITE);
	else if(i1>=2&&i1<=4)
	textcolor(RED,WHITE);
	else if(i1>=6&&i1<=8)
	textcolor(LIGHTRED,WHITE);
	else if(i1>=10&&i1<=14)
	textcolor(BROWN,WHITE);
	else if(i1==16)
	textcolor(LIGHTGREEN,WHITE);
    Gotxy(7,5);
	printf("ㆍ");
	Gotxy(7,24);
	printf("ㆍ");
	textcolor(WHITE,BLACK);
	
/////////////////////////		
	if(kbhit()){  
but=_getch();
if(but!='q'&&but!=0x08&&but!=0x0D&&but!=' '&&i1<=14){
textcolor(WHITE,DARKGRAY);
Gotxy(7,8+i1);
cout<<but;       
code[i1/2]=but;	
i1+=2;
}
else if(but==0x08){    //backspace 감지 
	if(i1>0)
	i1-=2;
	textcolor(DARKGRAY,DARKGRAY);
	Gotxy(7,8+i1);
	printf(" ");
	code[i1/2]=' ';	
	
}	
else if(but=='q'){
	goto Manu;
}		
////////////////
else if(but==0x0D){
if(code[0]=='S'&&code[1]=='T'&&code[2]=='r'&&code[3]=='e'&&code[4]=='s'&&code[5]=='e'&&code[6]=='t'){
	if(code[7]=='1'){
		fout.open("name1.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score1.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record1.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name2.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score2.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record2.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name3.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score3.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record3.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name4.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score4.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record4.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name5.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score5.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record5.txt");         //maxsscore
fout<<"0";
fout.close();
}
else if(code[7]=='2'){
		fout.open("name6.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score6.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record6.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name7.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score7.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record7.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name8.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score8.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record8.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name9.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score9.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record9.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name10.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score10.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record10.txt");         //maxsscore
fout<<"0";
fout.close();
}
else if(code[7]=='3'){
		fout.open("name11.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score11.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record11.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name12.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score12.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record12.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name13.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score13.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record13.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name14.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score14.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record14.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("name15.txt");         //maxsscore
fout<<"none";
fout.close();
		fout.open("score15.txt");         //maxsscore
fout<<"0";
fout.close();
fout.open("record15.txt");         //maxsscore
fout<<"0";
fout.close();
}
}
else if(code[0]=='c'&&code[1]=='h'&&code[2]=='a'&&code[3]=='l'&&code[4]=='l'&&code[5]=='1'&&code[6]=='0'&&code[7]=='2'){

	fout.open("challenge.txt");//도전과제   
i=0;
while(i<=11){
	chall_type_plus[i]=0;
	i+=1;
}
file_int=0;
fout<<file_int;
fout.close();
	
}
else if(code[0]=='G'&&code[1]=='V'&&code[2]=='-'&&code[3]=='-'&&code[4]=='t'&&code[5]=='r'&&code[6]=='u'&&code[7]=='e'){
gravity_use=0;
}
else if(code[0]=='G'&&code[1]=='V'&&code[2]=='-'&&code[3]=='f'&&code[4]=='a'&&code[5]=='l'&&code[6]=='s'&&code[7]=='e'){
gravity_use=1;
}
else if(code[0]=='p'&&code[1]=='u'&&code[2]=='y'&&code[3]=='o'&&code[4]=='p'&&code[5]=='u'&&code[6]=='y'&&code[7]=='o'){  //이스터애그 
if(chall_type_plus[11]==0){
chall_type_plus[11]=1;
chall_say();
}
system("cls");
goto Start;
}
goto Manu;
}
}
textcolor(DARKGRAY,BLACK);
Gotxy(11,2);
printf("(Don't Use Korean)");
textcolor(WHITE,BLACK);
Gotxy(14,2);
printf("Enter : Input");
Gotxy(15,2);
printf("q : Out");
}
	
////////////////////////////////////////////////////////////
///////////////////////////////////////////////
////////////////////////////////////////////////////////
	Start :
	
	
	
	gravity=0;
	
	if(option[0]==1){	
	blocktype-=1;
	fall=7;	            //스피드 
	}
	else if(option[6]==1){
           //레인보우 
	blocktype=7;
	}
	else if(option[5]==1){
		fall*=1.3;
	}
	else if(option[1]==1){
	fall+=3;	
	}
	else if(option[8]==1){
           //얼음 
	blocktype=4;
	}
		
	system("cls");
	mapping();
	puyo();	
	Gotxy(6,3);
	textcolor(LIGHTRED,BLACK);
	cout<<"Ｒｅａｄｙ?"<<endl;
	Sleep(700);
	Gotxy(6,3);
	cout<<"Ｓｔａｒｔ!"<<endl;
	Sleep(500);
	textcolor(WHITE,BLACK);

	
//	textcolor(BROWN,BLACK);
//	Gotxy(-1,2);
//	cout<<"▲";
//	Gotxy(-1,12);
//	cout<<"▲";
//	Gotxy(-2,5);
//	cout<<"▲";
//	Gotxy(-2,7);
//	cout<<"▲";
//	Gotxy(-2,9);
//	cout<<"▲";
//	textcolor(BLACK,BROWN);
//	Gotxy(-1,4);
//	cout<<":";
//	Gotxy(-1,11);
//	cout<<":";
//	Gotxy(-1,5);
//	cout<<":";
//	Gotxy(-1,10);
//	cout<<":";	
//	Gotxy(-1,6);
//	cout<<"◈◈";
	startset();
	for(;;){
		//system("cls");
		mapping();	
		entime+=1;
		
		
		if(chain>=1)    //체인타임  
		chaintime+=1;
		
		i=2;
		j=0;
		while(i<=12){
			while(j<=11){
				j+=1;
				if(map[i][j]==0){
					Gotxy(j,i);
				textcolor(BLACK,BLACK);
				printf("  ");	    //화면 깜빡거림 방지 
				}
				
				
				
			}
			i+=2;
			j=0;
		}
		j=0;
		while(j<=12){
			j+=1;
			Gotxy(j,15);
				textcolor(BLACK,BLACK);
				printf(" ");   //옆 깜빡임 버그 해결 전까지의 방지  
			Gotxy(j,0);
				textcolor(BLACK,BLACK);
				printf(" ");	
		}
		
		
	puyo();	
	thread t2(moving);
	puyo();
	thread t1(unit_time);	
	puyo();
	if(mov_y>=12||mov_y1>=12){
	startset();	
	}
	else if(turn==1&&map[mov_x][mov_y+1]!=0&&map[mov_x][mov_y+1]!=11&&map[mov_x][mov_y+1]!=12&&map[mov_x][mov_y+1]!=14&&map[mov_x][mov_y+1]!=13&&map[mov_x][mov_y+1]!=8&&map[mov_x][mov_y+1]!=9&&map[mov_x][mov_y+1]!=10){             //블럭이 땅에 닿고 재시작 감지 

	startset();	
	}
	else if(turn==2||turn==4){
		if(map[mov_x][mov_y+1]==0&&map[mov_x1][mov_y1+1]!=0&&map[mov_x1][mov_y1+1]!=11&&map[mov_x1][mov_y1+1]!=12&&map[mov_x1][mov_y1+1]!=14&&map[mov_x1][mov_y1+1]!=13&&map[mov_x1][mov_y1+1]!=8&&map[mov_x1][mov_y1+1]!=9&&map[mov_x1][mov_y1+1]!=10){
		startset();
		}	
		else if(map[mov_x][mov_y+1]>=11&&map[mov_x][mov_y+1]<=17&&map[mov_x1][mov_y1+1]!=0&&map[mov_x1][mov_y1+1]!=11&&map[mov_x1][mov_y1+1]!=12&&map[mov_x1][mov_y1+1]!=14&&map[mov_x1][mov_y1+1]!=13&&map[mov_x1][mov_y1+1]!=8&&map[mov_x1][mov_y1+1]!=9&&map[mov_x1][mov_y1+1]!=10){
		startset();
		}
		else if(map[mov_x][mov_y+1]!=0){
        if(map[mov_x1][mov_y1+1]==0||map[mov_x][mov_y+1]==11||map[mov_x][mov_y+1]==12||map[mov_x][mov_y+1]==14||map[mov_x][mov_y+1]==13||map[mov_x][mov_y+1]==8||map[mov_x][mov_y+1]!=9||map[mov_x][mov_y+1]==10)
		startset();
		}
		else if(map[mov_x][mov_y+1]!=0&&map[mov_x1][mov_y1+1]!=0&&map[mov_x][mov_y+1]!=11&&map[mov_x][mov_y+1]!=12&&map[mov_x][mov_y+1]!=14&&map[mov_x][mov_y+1]!=13&&map[mov_x][mov_y+1]!=8&&map[mov_x][mov_y+1]!=9&&map[mov_x][mov_y+1]!=10){

		startset();
		}
	}
	else if(turn==3&&map[mov_x1][mov_y1+1]!=0&&map[mov_x1][mov_y1+1]!=11&&map[mov_x1][mov_y1+1]!=12&&map[mov_x1][mov_y1+1]!=14&&map[mov_x1][mov_y1+1]!=13&&map[mov_x1][mov_y1+1]!=8&&map[mov_x1][mov_y1+1]!=9&&map[mov_x1][mov_y1+1]!=10){

	startset();	
	}
	i=0;
	j=1;
	while(i<=12){
		while(j<=12){
			if(map[i][j]==56){        //여기서 터짐 폭탄  
			map[i][j]=20;    //하강 속도 초기화  
//			if(diff_select%3==0){
//				fall=14;
//			}
//			else if(diff_select%3==1){
//				fall=10;
//			}
//			else if(diff_select%3==2){
//				fall=7;
//			}
			i1=-4;
			j1=-2;
			while(i1<=4){
				while(j1<=2){
					i2=i+i1;
					j2=j+j1;
					if(i2<0)
					break;
					if(j2<0)
					break;
					if(map[i2][j2]>=1&&map[i2][j2]<=7){
						map[i2][j2]=20;
						if(score>=500+score/10)
						score-=500+score/10;
					}
					j1+=1;
				}
				j1=-2;
				i1+=2;
			}
			break; 
			}
			j+=1;
		}
		j=0;
		i+=2;
	}
	
	
	
	tact=0;   //공중에 있는 블럭 감지 상수 
	i=2;
	j=1;
	while(i<=12){
		while(j<=12){
			if(map[i][j]!=0&&map[i][j]!=11&&map[i][j]!=12&&map[i][j]!=14&&map[i][j]!=13&&map[i][j]!=8&&map[i][j]!=9&&map[i][j]!=10){
				if(map[i][j+1]==0&&map[i][j]!=11&&map[i][j]!=12&&map[i][j]!=14&&map[i][j]!=13&&map[i][j]!=8&&map[i][j]!=9&&map[i][j]!=10)
				if(i!=mov_x&&j!=mov_y){
					tact+=1;	
					}
			}
			j+=1;
		}
		j=1;
		i+=2;
	}
	if(tact==0){           //뿌요 파괴 
	if(turn==1&&map[mov_x][mov_y+1]!=1&&map[mov_x][mov_y+1]!=2&&map[mov_x][mov_y+1]!=3&&map[mov_x][mov_y+1]!=4&&map[mov_x][mov_y+1]!=5&&map[mov_x][mov_y+1]!=6&&map[mov_x][mov_y+1]!=7&&mov_y<=2)
	blockbreak();
	else if(turn!=1&&map[mov_x1][mov_y1+1]!=1&&map[mov_x1][mov_y1+1]!=2&&map[mov_x1][mov_y1+1]!=3&&map[mov_x1][mov_y1+1]!=4&&map[mov_x1][mov_y1+1]!=5&&map[mov_x1][mov_y1+1]!=6&&map[mov_x1][mov_y1+1]!=7&&mov_y1<=2)
	blockbreak();	
	}
	tact=0;
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// 도전과제 감지	
if(score>=10000&&chall_type_plus[0]==0){
chall_type_plus[0]+=1;
chall_say();
}
else if(score>=100000&&chall_type_plus[0]==1){
	chall_type_plus[0]+=1;
	chall_say();
}
else if(score>=1000000&&chall_type_plus[0]==2){
	chall_type_plus[0]+=1;
	chall_say();
}
else if(score>=10000000&&chall_type_plus[0]==3){
	chall_type_plus[0]+=1;
	chall_say();
}
else if(score>=99999999&&chall_type[0]==4){
	chall_type_plus[0]+=1;
	chall_say();
}

if(maxchain>=5&&chall_type_plus[1]==0){
chall_type_plus[1]+=1;
chall_say();
}
else if(maxchain>=10&&chall_type_plus[1]==1){
	chall_type_plus[1]+=1;
	chall_say();
}
else if(maxchain>=15&&chall_type_plus[1]==2){
	chall_type_plus[1]+=1;
	chall_say();
}

if(allcleared-1>=1&&chall_type_plus[2]==0){//임시숫자로 인해 -1 
chall_type_plus[2]+=1;
chall_say();
}
else if(allcleared-1>=2&&chall_type_plus[2]==1){
	chall_type_plus[2]+=1;
	chall_say();
}
else if(allcleared-1>=3&&chall_type_plus[2]==2){
	chall_type_plus[2]+=1;
	chall_say();
}
else if(puyocleared-1<=100&&allcleared-1>=3&&chall_type_plus[2]==3){
	chall_type_plus[2]+=1;
	chall_say();
}

if(puyocleared-1>=100&&chall_type_plus[3]==0){//임시숫자로 인해 -1 
chall_type_plus[3]+=1;
chall_say();
}
else if(puyocleared-1>=500&&chall_type_plus[3]==1){
	chall_type_plus[3]+=1;
	chall_say();
}
else if(puyocleared-1>=1000&&chall_type_plus[3]==2){
	chall_type_plus[3]+=1;
	chall_say();
}
else if(puyocleared-1>=5000&&chall_type_plus[3]==3){
	chall_type_plus[3]+=1;
	chall_say();
}

if(chall_obstruct>=10&&chall_type_plus[4]==0){
chall_type_plus[4]+=1;
chall_say();
}
else if(chall_obstruct>=30&&chall_type_plus[4]==1){
	chall_type_plus[4]+=1;
	chall_say();
}
else if(chall_obstruct>=50&&chall_type_plus[4]==2){
	chall_type_plus[4]+=1;
	chall_say();
}
else if(chall_obstruct>=100&&chall_type_plus[4]==3){
	chall_type_plus[4]+=1;
	chall_say();
}

if(chall_sandwich>=5&&chall_type_plus[5]==0){
chall_type_plus[5]+=1;
chall_say();
}
else if(sandwich_plus>1&&maxchain>=7&&chall_type_plus[5]==1){
	chall_type_plus[5]+=1;
	chall_say();
}
else if(sandwich_plus>1&&chall_sandwich_score>=1000000&&chall_type_plus[5]==2){
	chall_type_plus[5]+=1;
	chall_say();
}

if(chall_bomb<=2&&chall_type_plus[6]==0){
chall_type_plus[6]+=1;
chall_say();
chall_bomb=6;
}
else if(chall_bomb<=1&&chall_type_plus[6]==1){
	chall_type_plus[6]+=1;
	chall_say();
	chall_bomb=6;
}
else if(chall_bomb<=0&&chall_type_plus[6]==2){
	chall_type_plus[6]+=1;
	chall_say();
	chall_bomb=6;
}

if(limit==0)
chall_limit+=1;
if(chall_limit==0&&score>=15000&&option[4]==1&&chall_type_plus[7]==0){
chall_type_plus[7]+=1;
chall_say();
}
else if(chall_limit==0&&score>=60000&&option[4]==1&&chall_type_plus[7]==1){
	chall_type_plus[7]+=1;
	chall_say();
}
else if(chall_limit==0&&score>=100000&&option[4]==1&&chall_type_plus[7]==2){
	chall_type_plus[7]+=1;
	chall_say();
}
else if(chall_limit==0&&score>=300000&&option[4]==1&&chall_type_plus[7]==3){
	chall_type_plus[7]+=1;
	chall_say();
}

if(maxchain>=3&&option[6]==1&&chall_type_plus[8]==0){
chall_type_plus[8]+=1;
chall_say();
}
else if(maxchain>=5&&option[6]==1&&chall_type_plus[8]==1){
	chall_type_plus[8]+=1;
	chall_say();
}
else if(maxchain>=8&&option[6]==1&&chall_type_plus[8]==2){
	chall_type_plus[8]+=1;
	chall_say();
}

if(maxchain>=7&&allcleared>=1&&rev_mov[0]=='a'&&option[5]==1&&chall_type_plus[9]==0){
chall_type_plus[9]+=1;
chall_say();
}

if(puyocleared>=300&&option[0]==1&&diff_select==0&&chall_type_plus[10]==0){
chall_type_plus[10]+=1;
chall_say();
}
else if(puyocleared>=300&&option[0]==1&&diff_select==1&&chall_type_plus[10]==1){
	chall_type_plus[10]+=1;
	chall_say();
}
else if(puyocleared>=300&&option[0]==1&&diff_select==2&&chall_type_plus[10]==2){
	chall_type_plus[10]+=1;
	chall_say();
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////	
	if(map[6][2]==1||map[6][2]==2||map[6][2]==3||map[6][2]==4||map[6][2]==5||map[6][2]==6||map[6][2]==7||score>=99999999){
		if(map[6][3]==1||map[6][3]==2||map[6][3]==3||map[6][3]==4||map[6][3]==5||map[6][3]==6||map[6][3]==7||score>=99999999){
			if(map[6][1]==1||map[6][1]==2||map[6][1]==3||map[6][1]==4||map[6][1]==5||map[6][1]==6||map[6][1]==7||score>=99999999){
				if(map[6][4]==1||map[6][4]==2||map[6][4]==3||map[6][4]==4||map[6][4]==5||map[6][4]==6||map[6][4]==7||score>=99999999){
					if(score>=99999999){
						score=99999999;
						mapping();
					}
					j=0;
		while(j<=12){
			j+=1;
			Gotxy(j,15);
				textcolor(BLACK,BLACK);
				printf(" ");   //옆 깜빡임 버그 해결 전까지의 방지  
			Gotxy(j,0);
				textcolor(BLACK,BLACK);
				printf(" ");	
		}
					
					i1=0;
					j1=1;
					puyoclearspeed=50;        ////
					while(j1<=12){
						while(i1<=12){
							if(map[i1][j1]>=1&&map[i1][j1]<=7||map[i1][j1]==30||map[i1][j1]>=50&&map[i1][j1]<=55||map[i1][j1]>=1001&&map[i1][j1]<=1005)
							map[i1][j1]=20;
							i1+=2;
						}
						puyo();
						j1+=1;
						i1=0;
					}
										
system("cls");
puyocleared-=1;
allcleared-=1;
//if(maxchain==1)
//maxchain-=1;


			Gotxy(1,2);
if(option[5]!=1)      //reverse
textcolor(WHITE,LIGHTBLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("ＰＵＹＯＳ     ");
if(option[5]!=1)      //reverse
textcolor(WHITE,BLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("               ");
Gotxy(2,2);
if(option[5]!=1)      //reverse
textcolor(WHITE,LIGHTBLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("ＣＬＥＡＲＥＤ ");
if(option[5]!=1)      //reverse
textcolor(WHITE,BLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("               ");
Sleep(200);
Gotxy(5,2);
if(option[5]!=1)      //reverse
textcolor(WHITE,LIGHTBLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("ＡＬＬ         ");
if(option[5]!=1)      //reverse
textcolor(WHITE,BLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("               ");
Gotxy(6,2);
if(option[5]!=1)      //reverse
textcolor(WHITE,LIGHTBLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("ＣＬＥＡＲＥＤ ");
if(option[5]!=1)      //reverse
textcolor(WHITE,BLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("               ");
Sleep(200);
Gotxy(9,2);
if(option[5]!=1)      //reverse
textcolor(WHITE,LIGHTBLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("ＭＡＸ         ");
if(option[5]!=1)      //reverse
textcolor(WHITE,BLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("               ");
Gotxy(10,2);
if(option[5]!=1)      //reverse
textcolor(WHITE,LIGHTBLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("ＣＨＡＩＮ     ");
if(option[5]!=1)      //reverse
textcolor(WHITE,BLUE);
else if(option[5]==1)      //reverse
textcolor(WHITE,BROWN);
printf("               ");
Sleep(200);
Gotxy(13,2);
if(option[5]!=1)      //reverse
textcolor(WHITE,BROWN);
else if(option[5]==1)      //reverse
textcolor(WHITE,LIGHTBLUE);
printf("ＴＯＴＡＬ     ");
if(option[5]!=1)      //reverse
textcolor(WHITE,BROWN);
else if(option[5]==1)      //reverse
textcolor(WHITE,BLUE);
printf("               ");
Gotxy(14,2);
if(option[5]!=1)      //reverse
textcolor(WHITE,BROWN);
else if(option[5]==1)      //reverse
textcolor(WHITE,LIGHTBLUE);
printf("ＳＣＯＲＥ     ");

if(diff_select%3==0){
fin.open("score1.txt");
fin>>maxscore1;
fin.close();
}
else if(diff_select%3==1){
fin.open("score6.txt");
fin>>maxscore6;
fin.close();
}
else if(diff_select%3==2){
fin.open("score11.txt");
fin>>maxscore11;
fin.close();
}
///////////////////////////////////////////////////////////
if(option[5]!=1)      //reverse
textcolor(WHITE,BROWN);
else if(option[5]==1)      //reverse
textcolor(WHITE,BLUE);
printf("      ");
if(op_select%OPTYPE==0){
if(diff_select%3==0){
	if(maxscore1<10)
	printf(" ");
	if(maxscore1<100)
	printf(" ");
	if(maxscore1<1000)
	printf(" ");
	if(maxscore1<10000)
	printf(" ");
	if(maxscore1<100000)
	printf(" ");
	if(maxscore1<1000000)
	printf(" ");
	if(maxscore1<10000000)
	printf(" ");	
}
else if(diff_select%3==1){
	if(maxscore6<10)
	printf(" ");
	if(maxscore6<100)
	printf(" ");
	if(maxscore6<1000)
	printf(" ");
	if(maxscore6<10000)
	printf(" ");
	if(maxscore6<100000)
	printf(" ");
	if(maxscore6<1000000)
	printf(" ");
	if(maxscore6<10000000)
	printf(" ");	
	}
else if(diff_select%3==2){
	if(maxscore11<10)
	printf(" ");
	if(maxscore11<100)
	printf(" ");
	if(maxscore11<1000)
	printf(" ");
	if(maxscore11<10000)
	printf(" ");
	if(maxscore11<100000)
	printf(" ");
	if(maxscore11<1000000)
	printf(" ");
	if(maxscore11<10000000)
	printf(" ");	
	}
}
	if(op_select%OPTYPE==0&&diff_select%3==0)
	printf("%d ",maxscore1);
	else if(op_select%OPTYPE==0&&diff_select%3==1)
	printf("%d ",maxscore6);
	else if(op_select%OPTYPE==0&&diff_select%3==2)
	printf("%d ",maxscore11);
	if(op_select%OPTYPE!=0&&option[5]!=1)
	printf("         ");
	if(option[5]==1)
	printf("         ");
	
Sleep(100);	
Gotxy(3,2);	
textcolor(WHITE,BLACK);
printf("         ");
if(option[5]!=1)      //reverse
textcolor(WHITE,CYAN);
else if(option[5]==1)      //reverse
textcolor(BROWN,YELLOW);
if(puyocleared<10)
	printf(" ");
	if(puyocleared<100)
	printf(" ");
	if(puyocleared<1000)
	printf(" ");
	if(puyocleared<10000)
	printf(" ");
	if(puyocleared<100000)
	printf(" ");
	if(puyocleared<1000000)
	printf(" ");
	if(puyocleared<10000000)
	printf("             ");
	printf("%d ",puyocleared);
	textcolor(WHITE,BLACK);
Sleep(100);	
Gotxy(7,2);	
textcolor(WHITE,BLACK);
printf("         ");
if(option[5]!=1)      //reverse
textcolor(WHITE,CYAN);
else if(option[5]==1)      //reverse
textcolor(BROWN,YELLOW);
if(allcleared<10)
	printf(" ");
	if(allcleared<100)
	printf(" ");
	if(allcleared<1000)
	printf(" ");
	if(allcleared<10000)
	printf(" ");
	if(allcleared<100000)
	printf(" ");
	if(allcleared<1000000)
	printf(" ");
	if(allcleared<10000000)
	printf("             ");
	printf("%d ",allcleared);	
Sleep(100);	
Gotxy(11,2);	
textcolor(WHITE,BLACK);
printf("         ");
if(option[5]!=1)      //reverse
textcolor(WHITE,CYAN);
else if(option[5]==1)      //reverse
textcolor(BROWN,YELLOW);
if(maxchain<10)
	printf(" ");
	if(maxchain<100)
	printf(" ");
	if(maxchain<1000)
	printf(" ");
	if(maxchain<10000)
	printf(" ");
	if(maxchain<100000)
	printf(" ");
	if(maxchain<1000000)
	printf(" ");
	if(maxchain<10000000)
	printf("             ");
	printf("%d ",maxchain);	
Sleep(100);	
Gotxy(15,2);
textcolor(WHITE,BLACK);
printf("         ");
if(option[5]!=1)      //reverse
textcolor(BROWN,YELLOW);
else if(option[5]==1)      //reverse
textcolor(WHITE,CYAN);
	if(score<10)
	printf(" ");
	if(score<100)
	printf(" ");
	if(score<1000)
	printf(" ");
	if(score<10000)
	printf(" ");
	if(score<100000)
	printf(" ");
	if(score<1000000)
	printf(" ");
	if(score<10000000)
	printf(" ");
	printf("            ");
	printf("%d ",score);
	textcolor(WHITE,BLACK);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(diff_select%3==0){
fin.open("score1.txt");
fin>>maxscore1;
fin.close();
fin.open("score2.txt");
fin>>maxscore2;
fin.close();
fin.open("score3.txt");
fin>>maxscore3;
fin.close();
fin.open("score4.txt");
fin>>maxscore4;
fin.close();
fin.open("score5.txt");
fin>>maxscore5;
fin.close();
}
else if(diff_select%3==1){
fin.open("score6.txt");
fin>>maxscore6;
fin.close();
fin.open("score7.txt");
fin>>maxscore7;
fin.close();
fin.open("score8.txt");
fin>>maxscore8;
fin.close();
fin.open("score9.txt");
fin>>maxscore9;
fin.close();
fin.open("score10.txt");
fin>>maxscore10;
fin.close();
}
else if(diff_select%3==2){
fin.open("score11.txt");
fin>>maxscore11;
fin.close();
fin.open("score12.txt");
fin>>maxscore12;
fin.close();
fin.open("score13.txt");
fin>>maxscore13;
fin.close();
fin.open("score14.txt");
fin>>maxscore14;
fin.close();
fin.open("score15.txt");
fin>>maxscore15 ;
fin.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
while(score>maxscore5&&op_select%OPTYPE==0&&diff_select%3==0){
Gotxy(17,2);
printf("      Press 'q' To Record");
Sleep(250);
if(kbhit()){
	but=_getch();
if(but=='q'){
	if(op_select%OPTYPE==0){                          //스코어 기록 
textcolor(DARKGRAY,BLACK);
Gotxy(17,2);
printf("                              ");
Gotxy(19,2);
printf("   (Don't Include Blank)");
Gotxy(20,2);
printf("   (Max Name Length Is 12 (Korea is 6) )");	
textcolor(WHITE,BLACK);
Gotxy(22,2);
printf("Enter : Record");
textcolor(WHITE,BLACK);
Gotxy(17,2);            // name 입력  

if(score>maxscore1){  
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name4.txt","name5.txt","record4.txt","record5.txt","score4.txt","score5.txt");
filecopy("name3.txt","name4.txt","record3.txt","record4.txt","score3.txt","score4.txt");
filecopy("name2.txt","name3.txt","record2.txt","record3.txt","score2.txt","score3.txt");
filecopy("name1.txt","name2.txt","record1.txt","record2.txt","score1.txt","score2.txt");
fout.close();
fout.open("name1.txt");
fout<<name<<endl;
fout.close();
fout.open("score1.txt");
fout<<score<<endl;
fout.close();
fout.open("record1.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore2&&score<=maxscore1+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name4.txt","name5.txt","record4.txt","record5.txt","score4.txt","score5.txt");
filecopy("name3.txt","name4.txt","record3.txt","record4.txt","score3.txt","score4.txt");
filecopy("name2.txt","name3.txt","record2.txt","record3.txt","score2.txt","score3.txt");

fout.close();
fout.open("name2.txt");
fout<<name<<endl;
fout.close();
fout.open("score2.txt");
fout<<score<<endl;
fout.close();
fout.open("record2.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore3&&score<=maxscore2+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name4.txt","name5.txt","record4.txt","record5.txt","score4.txt","score5.txt");
filecopy("name3.txt","name4.txt","record3.txt","record4.txt","score3.txt","score4.txt");

fout.close();
fout.open("name3.txt");
fout<<name<<endl;
fout.close();
fout.open("score3.txt");
fout<<score<<endl;
fout.close();
fout.open("record3.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore4&&score<=maxscore3+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name4.txt","name5.txt","record4.txt","record5.txt","score4.txt","score5.txt");

fout.close();
fout.open("name4.txt");
fout<<name<<endl;
fout.close();
fout.open("score4.txt");
fout<<score<<endl;
fout.close();
fout.open("record4.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore5&&score<=maxscore4+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
fout.close();
fout.open("name5.txt");
fout<<name<<endl;
fout.close();
fout.open("score5.txt");
fout<<score<<endl;
fout.close();
fout.open("record5.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
}

}
}
Gotxy(17,2);
printf("                           ");
Sleep(250);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
while(score>maxscore10&&op_select%OPTYPE==0&&diff_select%3==1){
Gotxy(17,2);
printf("      Press 'q' To Record");
Sleep(250);
if(kbhit()){
	but=_getch();
if(but=='q'){
	if(op_select%OPTYPE==0){                          //스코어 기록 
textcolor(DARKGRAY,BLACK);
Gotxy(17,2);
printf("                              ");
Gotxy(19,2);
printf("   (Don't Include Blank)");
Gotxy(20,2);
printf("   (Max Name Length Is 12 (Korea is 6) )");	
textcolor(WHITE,BLACK);
Gotxy(22,2);
printf("Enter : Record");
textcolor(WHITE,BLACK);
Gotxy(17,2);            // name 입력  

if(score>maxscore6){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name9.txt","name10.txt","record9.txt","record10.txt","score9.txt","score10.txt");
filecopy("name8.txt","name9.txt","record8.txt","record9.txt","score8.txt","score9.txt");
filecopy("name7.txt","name8.txt","record7.txt","record8.txt","score7.txt","score8.txt");
filecopy("name6.txt","name7.txt","record6.txt","record7.txt","score6.txt","score7.txt");
fout.close();
fout.open("name6.txt");
fout<<name<<endl;
fout.close();
fout.open("score6.txt");
fout<<score<<endl;
fout.close();
fout.open("record6.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore7&&score<=maxscore6+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name9.txt","name10.txt","record9.txt","record10.txt","score9.txt","score10.txt");
filecopy("name8.txt","name9.txt","record8.txt","record9.txt","score8.txt","score9.txt");
filecopy("name7.txt","name8.txt","record7.txt","record8.txt","score7.txt","score8.txt");

fout.close();
fout.open("name7.txt");
fout<<name<<endl;
fout.close();
fout.open("score7.txt");
fout<<score<<endl;
fout.close();
fout.open("record7.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore8&&score<=maxscore7+1){	
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name9.txt","name10.txt","record9.txt","record10.txt","score9.txt","score10.txt");
filecopy("name8.txt","name9.txt","record8.txt","record9.txt","score8.txt","score9.txt");

fout.close();
fout.open("name8.txt");
fout<<name<<endl;
fout.close();
fout.open("score8.txt");
fout<<score<<endl;
fout.close();
fout.open("record8.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore9&&score<=maxscore8+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name9.txt","name10.txt","record9.txt","record10.txt","score9.txt","score10.txt");

fout.close();
fout.open("name9.txt");
fout<<name<<endl;
fout.close();
fout.open("score9.txt");
fout<<score<<endl;
fout.close();
fout.open("record9.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore10&&score<=maxscore9+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
fout.close();
fout.open("name10.txt");
fout<<name<<endl;
fout.close();
fout.open("score10.txt");
fout<<score<<endl;
fout.close();
fout.open("record10.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
}

}
}
Gotxy(17,2);
printf("                           ");
Sleep(250);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
while(score>maxscore15&&op_select%OPTYPE==0&&diff_select%3==2){
Gotxy(17,2);
printf("      Press 'q' To Record");
Sleep(250);
if(kbhit()){
	but=_getch();
if(but=='q'){
	if(op_select%OPTYPE==0){                          //스코어 기록 
textcolor(DARKGRAY,BLACK);
Gotxy(17,2);
printf("                              ");
Gotxy(19,2);
printf("   (Don't Include Blank)");
Gotxy(20,2);
printf("   (Max Name Length Is 12 (Korean is 6) )");	
textcolor(WHITE,BLACK);
Gotxy(22,2);
printf("Enter : Record");
textcolor(WHITE,BLACK);
Gotxy(17,2);            // name 입력  

if(score>maxscore11){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name14.txt","name15.txt","record14.txt","record15.txt","score14.txt","score15.txt");
filecopy("name13.txt","name14.txt","record13.txt","record14.txt","score13.txt","score14.txt");
filecopy("name12.txt","name13.txt","record12.txt","record13.txt","score12.txt","score13.txt");
filecopy("name11.txt","name12.txt","record11.txt","record12.txt","score11.txt","score12.txt");
fout.close();
fout.open("name11.txt");
fout<<name<<endl;
fout.close();
fout.open("score11.txt");
fout<<score<<endl;
fout.close();
fout.open("record11.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore12&&score<=maxscore11+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name14.txt","name15.txt","record14.txt","record15.txt","score14.txt","score15.txt");
filecopy("name13.txt","name14.txt","record13.txt","record14.txt","score13.txt","score14.txt");
filecopy("name12.txt","name13.txt","record12.txt","record13.txt","score12.txt","score13.txt");
fout.close();
fout.open("name12.txt");
fout<<name<<endl;
fout.close();
fout.open("score12.txt");
fout<<score<<endl;
fout.close();
fout.open("record12.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore13&&score<=maxscore12+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
filecopy("name14.txt","name15.txt","record14.txt","record15.txt","score14.txt","score15.txt");
filecopy("name13.txt","name14.txt","record13.txt","record14.txt","score13.txt","score14.txt");

fout.close();
fout.open("name13.txt");
fout<<name<<endl;
fout.close();
fout.open("score13.txt");
fout<<score<<endl;
fout.close();
fout.open("record13.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore14&&score<=maxscore13+1){
	printf("   NAME : ");
scanf("%s",&name);
filecopy("name14.txt","name15.txt","record14.txt","record15.txt","score14.txt","score15.txt");
namelegth();
fout.close();
fout.open("name14.txt");
fout<<name<<endl;
fout.close();
fout.open("score14.txt");
fout<<score<<endl;
fout.close();
fout.open("record14.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
else if(score>maxscore15&&score<=maxscore14+1){
	printf("   NAME : ");
scanf("%s",&name);
namelegth();
fout.close();
fout.open("name15.txt");
fout<<name<<endl;
fout.close();
fout.open("score15.txt");
fout<<score<<endl;
fout.close();
fout.open("record15.txt");
fout<<allcleared*CALL+puyocleared*CPUYO+maxchain<<endl;
fout.close();
Gotxy(22,2);
exit(0);
}
}

}
}
Gotxy(17,2);
printf("                           ");
Sleep(250);
}
Gotxy(22,2);
exit(0);
}
	}
}
	}         	
	
	
            //종료 감지 
	                                       //종료 끝 
///////////////////////////////////////////////	
	t1.join();
	t2.join();
	
	}
	

	
}
