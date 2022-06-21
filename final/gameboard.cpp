#include "gameboard.h"
#include "game_mode.h"
#include <QtDebug>
gameboard::gameboard(QObject *parent) : QObject(parent), firecount(0)
{
    srand(time(nullptr));
    for(int i=0;i<10;i++)
        for(int j=0;j<5;j++)
            board[i][j]=nullptr;
    timer = new QTimer();   //폭탄생성

    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++){
            board[i][j]= new bomb(rand()%4);
        }

}

void gameboard::change_direction(const int x,const int y){
   board[x][y]->changedir();
}

bomb* gameboard::get_bomb(const int x, const int y){
    return board[x][y];
}

int gameboard::get_bomb_dir(const int x, const int y){
    return board[x][y]->direction();
}

bomb* (*gameboard::get_all_bomb())[5]
{
    return board;
}


void gameboard::generatebomb(){
    //기존에 존재하던 폭탄 위로 올리기
    for(int i=0;i<5;i++)
        for(int j=8;j>=0;j--){
            if(board[j][i]!=nullptr){
                if(j!=8){
                   board[j+1][i]=board[j][i];
                }
                else if(j==8){
                    emit gameover();
                    return;
                }
                board[j+1][i]=board[j][i];
            }
        }
   //새로운 줄 추가
   for(int i=0;i<5;i++)
       board[0][i]= new bomb(rand()%4);

   //여기서 gameend check!
   for(int k=0;k<5;k++){
       if(board[9][k]!=nullptr)
       {
           qDebug() << "12";
           emit gameover();

           return;
       }
   }
}



void gameboard::fallbomb(){
    int c=1;
    while(c){
        c=0;
    for(int i=0;i<5;i++)
        for(int j=2;j<9;j++){ //높이가 0일때는 아직 나오지 않은 폭탄이므로 터질 수 없음.
            if(board[j-1][i]==nullptr && board[j][i] != nullptr){
                board[j-1][i]=board[j][i];
                board[j][i]=nullptr;
                c++;

        }
    //while문을 거치게 되면 모든 폭탄이 완전히 내려오게 된다. 그러므로 한 칸씩 내려오는 것을 print하고 싶다면,
    //이 사이에 출력문을 넣거나 while문의 역할을 하는 것을 다른데서 만들어주자.
    }
    }
}
void gameboard::catchfire(int x, int y) //미완
{
    /*
     * signal로 불의 위치가 온다.
     * slot에서 불의 위치와 그 위치의 폭탄의 심지가 불을 향해있는지 검사한다.
     * 그리고 아래의 구문은 위의 경우가 true일 경우에 실행한다.
    */
    int sc=0;
    int xpos[4]={1,0,-1,0};
    int ypos[4]={0,1,0,-1};
    std::pair<int,int> p={y,x};
    std::vector<std::pair<int,int>> a[10];
    std::queue<std::pair<int,int>> next;
    std::queue<std::pair<int,int>> present;
    std::queue<std::pair<int,int>> search;
    for(int j=0;j<5;j++)
        for(int i=0;i<10;i++)
            visited[i][j]=false;
    next.push(p);
    visited[y][x] = true;

    delete board[y][x];
    sc++;
    board[y][x]=nullptr;

    emit board_change();

        while(!next.empty()){
            for(size_t i=0;i<next.size();i++){
                present.push(next.front());
                next.pop();
            }
            while(!present.empty()){
                std::pair<int,int> f = present.front();
                present.pop();
                search.push(f);
            }
            clock_t start=clock();
            while(clock()-start<200)
                ;

            while(!search.empty()){
                std::pair<int,int> f= search.front();
                int y=f.first;
                int x=f.second;
                search.pop();

                for(int i=0; i<4; i++){

                    int newx= x+xpos[i];
                    int newy= y+ypos[i];
                    if((x+xpos[i]<5 && x+xpos[i]>-1) && (y+ypos[i]<9 && y+ypos[i]>0)){
                        if(!visited[newy][newx]){  // 방문하지 않았다면..
                            if (board[newy][newx] == nullptr)
                            {
                                visited[newy][newx] = true;
                                continue;
                            }
                            else if(board[newy][newx]->direction()==0 && xpos[i]==0 && ypos[i]==-1){ //direction==0, 오른쪽
                            next.push(std::pair<int,int>(y+ypos[i],x+xpos[i]));
                            visited[newy][newx] = true;

                            delete board[newy][newx];
                            sc++;
                            board[newy][newx]=nullptr;
                            //출력부
                            emit board_change();
                            }
                            else if(board[newy][newx]->direction()==1 && xpos[i]==-1 && ypos[i]==0){ //direction==1, 아래
                            next.push(std::pair<int,int>(y+ypos[i],x+xpos[i]));
                            visited[newy][newx] = true;

                            delete board[newy][newx];
                            sc++;
                            board[newy][newx]=nullptr;
                            //출력부
                            emit board_change();
                            }
                            else if(board[newy][newx]->direction()==2 && xpos[i]==0 && ypos[i]==1){ //direction==2, 왼쪽
                            next.push(std::pair<int,int>(y+ypos[i],x+xpos[i]));
                            visited[newy][newx] = true;

                            delete board[newy][newx];
                            sc++;
                            board[newy][newx]=nullptr;
                            //출력부
                            emit board_change();
                            }
                            else if(board[newy][newx]->direction()==3 && xpos[i]==1 && ypos[i]==0){ //direction ==3 위
                            next.push(std::pair<int,int>(y+ypos[i],x+xpos[i]));
                            visited[newy][newx] = true;

                            delete board[newy][newx];
                            sc++;
                            board[newy][newx]=nullptr;
                            //출력부
                            emit board_change();
                            }
                        }
                    }
                }
            }
        }

        emit start();
        emit score (100*sc);
        qDebug()<<sc<<endl;
}

void gameboard::is_explode(int x, int y){
    //changepos signal은 x에 왼, 오른쪽이 오고
    //y에 y좌표가 온다.
    if(x==0 && y!=0){
        if (board[y][x]==nullptr){
            return;
        }
        else if(board[y][0]->direction()==3){
           emit stop();
           catchfire(0, y);
        }
    }
    else if(x==1 && y!=0){
        if (board[y][4]==nullptr){
            return;
        }
        else if(board[y][4]->direction()==1){
           emit stop();
           catchfire(4, y);
        }
    }
    fallbomb();
}
