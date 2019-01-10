 
#include<iostream.h>

int main()
{   system("color 4E");
    unsigned int i;
	int player = 0;                       // Current player number - 1 or 2
	int winner = 0;                       // The winning player number
	int choice = 0;                       // Chosen square
	unsigned int row = 0;                 // Row index for a square
	unsigned int column = 0;              // Column index for a square
	char board[3][3] = {                  // The board
						{'1','2','3'},            // Initial values are characters '1' to '9'
						{'4','5','6'},            // used to select a vacant square
						{'7','8','9'}             // for a player's turn.
				   };
       //clrscr();
  // The main game loop. The game continues for up to 9 turns  // as long as there is no winner
	for( i= 0; i < 9 && winner == 0; ++i)
	{    // Display the board
	cout<<"\n";

	   cout<<board[0][0]<<" | "<< board[0][1]<<" | "<< board[0][2];
		cout<<"\n---+---+---\n";
		cout<< board[1][0]<<" | "<< board[1][1]<<" | "<< board[1][2];
		cout<<"\n---+---+---\n";
	   cout<< board[2][0]<<" | " <<board[2][1]<<" | " <<board[2][2];

		player = i%2 + 1;                   // Select player
    // Get valid player square selection
			do
			{  char s1;
			  if(player==1)
			    s1='X';
			    else
			     s1='O';

			cout<<"\nPlayer "<<player<<"please enter a valid square number for where you want to place your "<<s1<<endl;
				cin>>choice;
			row = --choice/3;                 // Get row index of square
				column = choice % 3;              // Get column index of square
			}while(choice < 0 || choice > 8|| board[row][column] > '9');
    // Insert player symbol
			board[row][column] = (player == 1) ? 'X' : 'O';
    // Check for a winning line – diagonals first
			if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||       (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
				winner = player;
			else
			{      // Check rows and columns for a winning line
				for(unsigned int line = 0; line <= 2; ++line)
			{
					if((board[line][0] == board[line][1] && board[line][0] == board[line][2]) || 
					          (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
				winner = player;
			}
			}
	}  // Game is over so display the final board
				cout<<"\n";
	cout<<board[0][0]<<" | "<< board[0][1]<<" | "<< board[0][2]<<endl;
		cout<<"---+---+---\n";
		cout<< board[1][0]<<" | "<< board[1][1]<<" | "<< board[1][2]<<endl;
		cout<<"---+---+---\n";
	    cout<< board[2][0]<<" | " <<board[2][1]<<" | " <<board[2][2];
     // Display result message
    if(winner)
    cout<<"\nCongratulations, player "<<winner<<" YOU ARE THE WINNER!\n" ;
    else
    cout<<"\nHow boring, it is a draw\n";
   
    return 0;

}
