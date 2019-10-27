#include <iostream>
 #include <cstdlib>
 #include <conio.h>
 #include <windows.h>
using namespace std;
bool gameOver;
const int width = 30;
const int height = 30;
int x, y, fruitA, fruitB, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection { Stop=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup () {

gameOver = false;
dir= Stop;
x= width/2;
y= height/2;
fruitA= rand() % width;
fruitB= rand() % height;
score=0;
}

void Draw() {
system("cls");
for (int i = 0;i < width+2; i++)
     cout<<"#";

cout<< endl;

for (int i = 0; i < width; i++)
{

    for (int j = 0;j < width; j++)
       {
             if(j==0)
                cout<<"#";
         if(i==y && j==x)
            cout<< "0";
         else if(i==fruitA && j==fruitB)
            cout<<"F";

         else
         { bool print = false;
             for ( int k = 0; k < nTail; k++)
             {
                 if(tailX[k]==j && tailY[k]==i)
                   {
                    cout<<"o";
                    print = true;
                   }



             }

                        if (!print)
                         cout<<" ";

         }


            if(j==width-1)
             cout<<"#";

       }
       cout<<endl;
}


for (int i = 0;i < width+2; i++)
     cout<<"#";

cout<<endl;
cout<< "Score:"<<score<<endl;
cout<<"Game by Constantinescu George-Gabriel"<<endl;
cout<<"Credits to Nvitanovic for tutorial"<<endl;

}

void Logic() {
int prevX = tailX[0];
int prevY = tailY[0];
int prev2X, prev2Y;
tailX[0]= x;
tailY[0]= y;
for( int i = 1; i < nTail; i++)
{
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;


}


switch(dir)
{

case LEFT:
    x--;
    break;
case RIGHT:
    x++;
    break;
case UP:
    y--;
    break;
case DOWN:
    y++;
    break;
default:
    break;




}
//if (x > width || x<0 || y>height || y<0)
  //  gameOver = true;
if(x>=width) x = 0; else if(x<0) x = width - 1;
if(y>=height) y = 0; else if(y<0) y = height - 1;
for(int i = 0; i < nTail; i++)
    if (tailX[i]==x && tailY[i]==y)
          gameOver= true;
if(x == fruitB && y == fruitA)
{

   score = score+10;
    fruitA = rand() % width;
    fruitB = rand() % height;
     nTail++;

}



}

void Input() {

if(_kbhit()) {

    switch(_getch())
    {
    case 'a':
        dir= LEFT;
        break;
    case 'd' :
        dir= RIGHT;
        break;
    case 'w':
        dir= UP;
        break;
    case 's':
      dir= DOWN;
      break;
    case 'x':
        gameOver = true;
        cout<<"why you press x retard?";
        break;
    }

}


}

int main(){
Setup();
while(!gameOver) {

    Draw();
    Input();
    Logic();
    Sleep(10);

}


    return 0;
}
