#include<stdio.h>
#include <stdlib.h>

int grid[9];
//Game Board design
void Gameboard(){
	system("cls");
	printf("=============================================================\n");
    printf("           *** --------TIC TAC TOE--------- ***              \n");
    printf("=============================================================\n");
    printf("\n");
    printf("\t\t\t     |     |      \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",grid[0],grid[1],grid[2]);
    printf("\t\t\t_____|_____|_____ \n");
    printf("\t\t\t     |     |      \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",grid[3],grid[4],grid[5]);
    printf("\t\t\t_____|_____|_____ \n");
    printf("\t\t\t     |     |      \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",grid[6],grid[7],grid[8]);
    printf("\t\t\t     |     |      \n");
}

void Winstatus(int player,FILE *file){
        Gameboard();
        sleep(1);
        system("cls");
        if (player==1) {     //Show that you are the winner
            printf("\n\n\n\n\n\n\t\t\tYou are the winner.Great job!\n\n");
            system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'You are the winner! Great job\')))\"");
            fprintf(file, "Result : You are the winner. Great job!\n");
        }
        else{    //Show if winner is Player 2
            printf("\n\n\n\n\n\n\t\t\tohh.Player 2 is the winner.You lost!\n\n");
			system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'ohh!Player 2 is the winner!You lost\')))\"");
            fprintf(file, "Result : Player 2 is the winner! You lost\n");
        }
        exit(1);
}

int main(){
	int index, player,i,count,choice;
	char sign, sign1, sign2;
    char name1[20];
    char name2[20];
	int n;
        system("cls");
        printf("\t\t\t=============================================================\n");
        printf("\t\t\t      *** (•_•) -------- TIC TAC TOE--------- (•_•) ***      \n");
        printf("\t\t\t=============================================================\n");
        printf("\n");
        printf("\t\t\t*** Select the Game Type ***\n\n");
        printf("\t\t\t 1. PLAY WITH ANOTHER PLAYER\n");
        printf("\t\t\t 2. PLAY WITH COMPUTER\n\n");
        printf("\nEnter Game Type Number : ");
        scanf("%d", &n);
        if(n == 2){
     		FILE *file;
     		file= fopen("GameInfo.txt","a"); //open a file in append mode
 
    		for (i = 0; i < 9; i++){
       			grid[i] = ' ';
     		}
 
     		printf("\nPlayer 1 ---> Enter your name : ");
     		scanf("%s",name1);
     		printf("\nPlayer 2 ---> Computer");
     		
     		printf("\n\nChoose a 'X' or 'O' sign continue the Game...\n");
     		printf("\n1.Enter no 1 if you like to choose X as a sign ---> ");      //Player 1 choose X or O
     		printf("\n2.Enter no 2 if you like to choose O as a sign ---> \n");

     		printf("\nEnter your choice: ");
     		scanf("%d",&choice);

     		(choice==1)? (sign1='X',sign2 ='O' ): (sign1='O',sign2='X'); 

     		fprintf(file,"\n{ Game : Player Vs Computer }");   //Save the game type in the file
     		fprintf(file,"\n{ %s ---> Player_1 } and { Computer ---> Player_2 } Move\n",name1); 
    		fprintf(file,"==============================================================================\n");
 
    		while (count < 9) {
        		Gameboard();
        		if (count % 2 == 0) {
        			sign = sign1;
            		player = 1;
            		printf("\n\nEnter your index(1-9) %s: ",name1);  //Enter your index number in the your turn
            		scanf("%d", &index);
            		sleep(1);
 
        		} else {
        			sign = sign2;
            		player = 2;
            		index = (rand()% 10) + 1;   //Enter random index number by computer
            		printf("\n\n Computer's Random index: %d",index);
           			sleep(1);
        		}
 	
        		if(index < 1 || index > 9) {
           		 	printf("\nAllowed index is 1 to 9!!"); //check whether allow index or not
            		sleep(1);
            		continue;
        		}
 
        		if (grid[index - 1] == 'X'  || grid[index - 1] == 'O'){
           			printf("\nPosition is Already Taken!!");  //check whether before used index or not
            		sleep(1);
            		continue;
        		}
 
        		if(player==1){
            		fprintf(file, "Player 1 - %c    ---->  %d\n",sign1, index); //write indexes that related to X in the file
        		}else{
            		fprintf(file, "Player 2 - %c    ---->  %d\n",sign2, index); //write indexes that related to O in the file
       			}
 
       		 	grid[index - 1] = sign;
 
 				//Identify the player who wins the game 
 				//horizontal pattern
        		if ((grid[0] == sign && grid[1] == sign && grid[2] == sign) ||   
            		(grid[3] == sign && grid[4] == sign && grid[5] ==  sign)||
            		(grid[6] == sign && grid[7] == sign && grid[8] ==  sign)) {
 
                	Winstatus(player,file);
        		}
 				//Vertical pattern
        		if((grid[0] == sign && grid[3] == sign && grid[6] == sign) ||
            		(grid[1] == sign && grid[4] == sign && grid[7] ==  sign) ||
           			(grid[2] == sign && grid[5] == sign && grid[8] ==  sign)) {
 
               		Winstatus(player,file);
        		}
 				//Diagonal pattern
        		if((grid[0] == sign && grid[4] == sign && grid[8] == sign) ||
            		(grid[2] == sign && grid[4] == sign && grid[6] ==  sign)){
 
                	Winstatus(player,file);
        		}
        		count++;
        		
     		}
       			if(player!=1 || player!=2){  //Check that the match ends in a draw
           			system("cls");
           			printf("\n\n\n\n\n\n\t\t\t The Match is draw! Try again...\n\n");
           			system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'The Match is draw! Try again...\')))\"");
           			fprintf(file, "Result : The Match is draw! Try again...\n");
     		}
       		fclose(file);
       		return 0;
	}
        else if (n == 1){
     		FILE *file;
     		file= fopen("GameInfo.txt","a"); //open a file in append mode and write data into a file
 
    		for (i = 0; i < 9; i++){
       				grid[i] = ' ';
     		}
 			printf("\nPlayer 1 ---> Enter Player 1 name : ");
     		scanf("%s",name1);
     		printf("Player 2 ---> Enter Player 2 name : ");
     		scanf("%s",name2);
     		
     		printf("\n\nChoose a 'X' or 'O' sign continue the Game...\n");
     		printf("\n1.Enter no 1 if you like to choose X as a sign ---> ");      
     		printf("\n2.Enter no 2 if you like to choose O as a sign --->\n");

     		printf("\nEnter your choice: ");
     		scanf("%d",&choice);

     		(choice==1)? (sign1='X',sign2 ='O' ): (sign1='O',sign2='X'); //Determining the sign selected by a player.
     		
     		fprintf(file,"\n{ Game : Player Vs Player }");
     		fprintf(file,"\n{ %s ---> Player_1 } and { %s ---> Player_2 }Moves\n",name1,name2);
    		fprintf(file,"===================================================================\n");
 
    		while (count < 9) {
        		Gameboard();
        		if (count % 2 == 0) {
            		sign = sign1;
            		player = 1;
            		printf("\n\nEnter your index(1-9) %s: ",name1);  //Enter your index number in the your turn
            		scanf("%d", &index);
        		} else {
            		sign = sign2;
            		player = 2;
            		printf("\n\nEnter your index(1-9) %s: ",name2);  //Enter your index number in the Player 2 turn
            		scanf("%d", &index);
        		}
        		if(index < 1 || index > 9) {
           		 	printf("\nAllowed index is 1 to 9!! Select another index"); //check whether allow index or not
            		sleep(1);
            		continue;
        		}
        		if (grid[index - 1] == 'X' || grid[index - 1] == 'O') {
           			printf("\nPosition Already Taken!! Select another index\n");  //check whether before used index or not
            		sleep(1);
            		continue;
        		}
 
        		if(player==1){
            		fprintf(file, "Player 1 - %c  ---->  %d\n",sign1, index); //write indexes that related to X in the file
        		}else{
            		fprintf(file, "Player 2 - %c  ---->  %d\n",sign2, index); //write indexes that related to O in the file
       			}
 
       		 	grid[index - 1] = sign;
        		
        		//Checking the parity of the place values chosen by the winning or losing player of the match
 
        		if ((grid[0] == sign && grid[1] == sign && grid[2] == sign) ||   
            		(grid[3] == sign && grid[4] == sign && grid[5] ==  sign)||
            		(grid[6] == sign && grid[7] == sign && grid[8] ==  sign)) {
            		
 					sleep(3);
                	Winstatus(player,file);
        		}
 
        		if((grid[0] == sign && grid[3] == sign && grid[6] == sign) ||
            		(grid[1] == sign && grid[4] == sign && grid[7] ==  sign) ||
           			(grid[2] == sign && grid[5] == sign && grid[8] ==  sign)) {
 					sleep(3);
               		Winstatus(player,file);
        		}
 
        		if((grid[0] == sign && grid[4] == sign && grid[8] == sign) ||
            		(grid[2] == sign && grid[4] == sign && grid[6] ==  sign)){
 					sleep(3);
                	Winstatus(player,file);
        		}
        		
        		count++;
     		}
       			if(player!=1 || player!=2){ 
				    sleep(3); //Check that the match ends in a draw
           			system("cls");
           			printf("\n\n\n\n\n\n\t\t\tThe Match is draw! Try again...\n\n");
           			system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'The Match is draw! Try again...\')))\"");
           			fprintf(file, "Result : The Match is draw! Try again...\n");
     		}
       		fclose(file);
       		return 0;
	}	
}



