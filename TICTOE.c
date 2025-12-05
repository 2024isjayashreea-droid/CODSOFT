#include <stdio.h>
#define PLAYER 'X'
#define AI_SYM 'O'
#define EMPTY ' '

char arr[3][3];

void board() {
    for(int i = 0; i < 3; i++) {          
        for(int j = 0; j < 3; j++) {       
            printf(" %c", arr[i][j]);  
            if(j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if(i < 2) {
            printf("--|--|--\n");   
        }
    }
}

void input() {
    int row, col;
    printf("enter the row and column you choose (0-2): ");
    scanf("%d %d", &row, &col);
    if(row >= 0 && row < 3 && col >= 0 && col < 3 && arr[row][col] == EMPTY) {
        arr[row][col] = PLAYER;
    } else {
        printf("Invalid move, try again.\n");
        input(); 
    }
}

void AI() {
    
    for(int i=0;i<3;i++){
        if(arr[i][0]==arr[i][1] && arr[i][2]==EMPTY && arr[i][0]!=EMPTY){
            arr[i][2]=AI_SYM;return;}
        if(arr[i][1]==arr[i][2] && arr[i][0]==EMPTY && arr[i][1]!=EMPTY){
            arr[i][0]=AI_SYM;return;}
        if(arr[i][0]==arr[i][2] && arr[i][1]==EMPTY && arr[i][0]!=EMPTY){
            arr[i][1]=AI_SYM;return;}
        if(arr[0][i]==arr[1][i] && arr[2][i]==EMPTY && arr[0][i]!=EMPTY){
            arr[2][i]=AI_SYM;return;}
        if(arr[1][i]==arr[2][i] && arr[0][i]==EMPTY && arr[1][i]!=EMPTY){
            arr[0][i]=AI_SYM;return;}
        if(arr[0][i]==arr[2][i] && arr[1][i]==EMPTY && arr[0][i]!=EMPTY){
            arr[1][i]=AI_SYM;return;}
    }
    if(arr[0][0]==arr[1][1] && arr[2][2]==EMPTY && arr[0][0]!=EMPTY){
        arr[2][2]=AI_SYM;return;}
    if(arr[0][2]==arr[1][1] && arr[2][0]==EMPTY && arr[0][2]!=EMPTY){
        arr[2][0]=AI_SYM;return;}
    if(arr[1][1]==EMPTY){
        arr[1][1]=AI_SYM;
        return;
    } 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==EMPTY){
                arr[i][j]=AI_SYM;
                return;
            }    
        }
    }
}

   
int winner() {
    
    for(int i = 0; i < 3; i++) {
        if(arr[i][0] != EMPTY && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            printf("Winner is %c\n", arr[i][0]);
            return 1;
        }
    }
    
    for(int j = 0; j < 3; j++) {
        if(arr[0][j] != EMPTY && arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j]) {
            printf("Winner is %c\n", arr[0][j]);
            return 1;
        }
    }
    
    if(arr[0][0] != EMPTY && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        printf("Winner is %c\n", arr[0][0]);
        return 1;
    }
    if(arr[0][2] != EMPTY && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
        printf("Winner is %c\n", arr[0][2]);
        return 1;
    }
    return 0;
}
int is_draw() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(arr[i][j] == EMPTY){
                return 0;
            }
    return 1;
}

int main() {
    
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            arr[i][j] = EMPTY;

    
    for(int turn=0; turn<5; turn++) {
                     
        input();              
        if(winner()) break;   
        board();
        if(is_draw()){
            printf("It's a draw!\n");
            break;
        }
        printf("\n");              

        AI();                 
        if(winner()) break;   
        board();  
        if(is_draw()){
            printf("It's a draw!\n");
            break;
        }            
    }
   
    printf("Game over.\n");
    return 0;
}
