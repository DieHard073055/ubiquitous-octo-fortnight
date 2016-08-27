#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEFT        0
#define RIGHT       1
#define TOP         2
#define BOTTOM      3

#define MOVE        20
#define PLACE_WALL  21

typedef struct{
    int x;     //Wall x coordinate
    int y;     //Wall y coordinate
    char o[2];    //Wall orientation
}WALL;

typedef struct{
    int id;     //Player ID
    int x;      //Player x coordinate
    int y;      //Player y coordinate
    int w;      //Player wall count
}PLAYER;

typedef struct{
    int w;      //Board width
    int h;      //Board height
    int p;      //Number of players in the game
    int id;     //Your id
    int wc;     //Total wall count
    int m_x;    //Your x-coordinate
    int m_y;    //Your y-coordinate

    WALL * walls;
    PLAYER * players;

}GAME;

GAME * setup();
PLAYER * update_players(GAME * g);
WALL * update_walls(GAME * g);
int game_process(GAME * g);
void move(GAME * g, int action);
void move_right(GAME * g, int action);
void move_down(GAME * g, int action);

int main()
{
    int ACTION = 0;
    GAME * g = setup();
    d("main():42: Game g has been assigned!\n");

    while(1){

        //update players stats
        (g)->players = update_players(g);
        d("main():48: (g)->players has been assigned!\n");

        //update wall stats
        (g)->walls = update_walls(g);
        d("main():52: (g)->walls has been assigned!\n");

        //process the updated results
        ACTION = game_process(g);
        //do an action
        move(g, ACTION);
        

    }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

         // action: LEFT, RIGHT, UP, DOWN or "putX putY putOrientation" to place a wall
    free(g);
}

GAME * setup(){

    d("setup():69: function start\n");
    GAME * g;
    char data[10];

    g = (GAME*) malloc (sizeof(GAME*));

    scanf("%d%d%d%d", &(g)->w, &(g)->h, &(g)->p, &(g)->id);
    fflush(stdin);
    d("setup(): Variable recieved | width :");sprintf(data, "%d", (g)->w);d(data);d("\n");
    d("setup(): Variable recieved | Height :");sprintf(data, "%d", (g)->h);d(data);d("\n");    
    d("setup(): Variable recieved | Players :");sprintf(data, "%d", (g)->p);d(data);d("\n");    
    d("setup(): Variable recieved | ID :");sprintf(data, "%d", (g)->id);d(data);d("\n");    

    d("setup():82: function end\n");

    return g;
}

PLAYER * update_players(GAME * g){

    d("update_players():89: function start\n");
    PLAYER * p;
    char data[10];


    p = (PLAYER*) malloc (((g)->p) * sizeof(PLAYER*) );

    for (int i = 0; i < (g)->p; ++i)
    {
        scanf("%d%d%d", &(p[i]).x, &(p[i]).y, &(p[i]).w);
        fflush(stdin);
        d("update_players(): Variable recieved | (p[");sprintf(data, "%d", i);d(data);d("])->x :");sprintf(data, "%d", (p[i]).x);d(data);d("\n");
        d("update_players(): Variable recieved | (p[");sprintf(data, "%d", i);d(data);d("])->y :");sprintf(data, "%d", (p[i]).y);d(data);d("\n");
        d("update_players(): Variable recieved | (p[");sprintf(data, "%d", i);d(data);d("])->w :");sprintf(data, "%d", (p[i]).w);d(data);d("\n");
    }

    (g)->m_x = p[(g)->id].x;
    (g)->m_y = p[(g)->id].y;
    
    d("update_players():98: function end\n");
    return p;
}

WALL * update_walls(GAME * g){

    d("update_walls():107: function start\n");
    WALL * w;
    char data[10];

    scanf("%d", &(g)->wc);
    w = (WALL*) malloc (((g)->wc) * sizeof(WALL*) );

    for (int i = 0; i < (g)->wc; ++i)
    {
        scanf("%d%d%s", &(w[i]).x, &(w[i]).y, (w[i]).o);
        fflush(stdin);
        d("update_walls(): Variable recieved | (w[");sprintf(data, "%d", i);d(data);d("])->x :");sprintf(data, "%d", (w[i]).x);d(data);d("\n");
        d("update_walls(): Variable recieved | (w[");sprintf(data, "%d", i);d(data);d("])->y :");sprintf(data, "%d", (w[i]).y);d(data);d("\n");
        d("update_walls(): Variable recieved | (w[");sprintf(data, "%d", i);d(data);d("])->o :");sprintf(data, "%s", (w[i]).o);d(data);d("\n");
    }

    d("update_walls():117: function end\n");
    return w;
}
int game_process(GAME * g){
    d("game_process():135: function start\n");

    d("game_process():135: function end\n");
    return MOVE;

}
void move(GAME * g, int action){
    d("move():147: function start\n");
    
    switch((g)->id){
        case LEFT:
            move_right(g, action);
        break;
        case RIGHT:
            move_left(g, action);
        break;
        case TOP:
             move_down(g, action);
        break;
    }
    d("move():147: function end\n");
}
void move_right(GAME * g, int action){
    d("move_right():206: function start\n");
    int m = 0;
    char data[10];
    for (int i = 0; i < (g)->wc; ++i)
    {
            //If there is a wall right next to you
            /*           wall
                    [You]  |
                           |
            */ 
        d("move_right(): my.x : ");sprintf(data, "%d", (g)->m_x);d(data);d(" wall x : ");sprintf(data, "%d", ((g)->walls[i]).x);d(data);d("\n");
        d("move_right(): my.y : ");sprintf(data, "%d", (g)->m_y);d(data);d(" wall y : ");sprintf(data, "%d", ((g)->walls[i]).y);d(data);d("\n");
        if(     (g)->m_x + 1 == ((g)->walls[i]).x &&
                (g)->m_y == ((g)->walls[i]).y/* && 
                strcmp(((g)->walls[i]).o, "V")    */
            ){
                d("move_right(): Obstacle right in front!\n");
                //try to move up
                if((g)->m_y > 0){
                    printf("UP\n");
                }else{
                //else move down
                    printf("DOWN\n");
                }
                m =1;
            }
            //If there is a wall right next to you
            /*           wall
                           |
                    [You]  |
            */

        else if(   
                (g)->m_x + 1 == ((g)->walls[i]).x &&
                (g)->m_y - 1 == ((g)->walls[i]).y /*&& 
                strcmp(((g)->walls[i]).o, "V")       */
            ){
                d("move_right(): Obstacle right in front above!\n");
                //try to move down
                if((g)->m_y < (g)->h){
                    printf("DOWN\n");
                }else{
                    printf("UP\n");
                }
                m =1;
            }
    }

     if(!m)printf("RIGHT\n");
    d("move_right():266: function end\n");
}
void move_left(GAME * g, int action){
    d("move_left():206: function start\n");
    int m = 0;
    char data[10];
    for (int i = 0; i < (g)->wc; ++i)
    {
            //If there is a wall right next to you
            /*           wall
                    [You]  |
                           |
            */ 
        d("move_left(): my.x : ");sprintf(data, "%d", (g)->m_x);d(data);d(" wall x : ");sprintf(data, "%d", ((g)->walls[i]).x);d(data);d("\n");
        d("move_left(): my.y : ");sprintf(data, "%d", (g)->m_y);d(data);d(" wall y : ");sprintf(data, "%d", ((g)->walls[i]).y);d(data);d("\n");
        if(     (g)->m_x == ((g)->walls[i]).x &&
                (g)->m_y == ((g)->walls[i]).y/* && 
                strcmp(((g)->walls[i]).o, "V")    */
            ){
                d("move_left(): Obstacle right in front!\n");
                //try to move up
                if((g)->m_y > 0){
                    printf("UP\n");
                }else{
                //else move down
                    printf("DOWN\n");
                }
                m =1;
            }
            //If there is a wall right next to you
            /*           wall
                           |
                    [You]  |
            */

        else if(   
                (g)->m_x     == ((g)->walls[i]).x &&
                (g)->m_y - 1 == ((g)->walls[i]).y /*&& 
                strcmp(((g)->walls[i]).o, "V")       */
            ){
                d("move_left(): Obstacle right in front above!\n");
                //try to move down
                if((g)->m_y < (g)->h){
                    printf("DOWN\n");
                }else{
                    printf("UP\n");
                }
                m =1;
            }
    
    }
    if(!m)printf("LEFT\n");
    d("move_left():266: function end\n");
}
void move_down(GAME * g, int action){
    d("move_down():206: function start\n");
    int m = 0;
    char data[10];
    for (int i = 0; i < (g)->wc; ++i)
    {
            //If there is a wall right next to you
            /*           wall
                    [You]  |
                           |
            */ 
        d("move_down(): my.x : ");sprintf(data, "%d", (g)->m_x);d(data);d(" wall x : ");sprintf(data, "%d", ((g)->walls[i]).x);d(data);d("\n");
        d("move_down(): my.y : ");sprintf(data, "%d", (g)->m_y);d(data);d(" wall y : ");sprintf(data, "%d", ((g)->walls[i]).y);d(data);d("\n");
        if(     (g)->m_x == ((g)->walls[i]).x &&
                (g)->m_y + 1 == ((g)->walls[i]).y/* && 
                strcmp(((g)->walls[i]).o, "V")    */
            ){
                d("move_down(): Obstacle right in front!\n");
                //try to move up
                if((g)->m_x > 0){
                    printf("LEFT\n");
                }else{
                //else move down
                    printf("RIGHT\n");
                }
                m =1;
            }
            //If there is a wall right next to you
            /*           wall
                           |
                    [You]  |
            */

        else if(   
                (g)->m_x == ((g)->walls[i]).x &&
                (g)->m_y + 1 == ((g)->walls[i]).y /*&& 
                strcmp(((g)->walls[i]).o, "V")       */
            ){
                d("move_down(): Obstacle right in front above!\n");
                //try to move down
                if((g)->m_x < (g)->h){
                    printf("RIGHT\n");
                }else{
                    printf("LEFT\n");
                }
                m =1;
            }
        else if(   
                (g)->m_x + 1 == ((g)->walls[i]).x &&
                (g)->m_y == ((g)->walls[i]).y /*&& 
                strcmp(((g)->walls[i]).o, "V")       */
            ){
                d("move_down(): Obstacle right in front above!\n");
                //try to move down
                if((g)->m_x < (g)->h){
                    printf("RIGHT\n");
                }else{
                    printf("LEFT\n");
                }
                m =1;
            }
    }

     if(!m)printf("DOWN\n");
    d("move_down():266: function end\n");
}
void d(const char * msg){
    fprintf(stderr, msg);
}
