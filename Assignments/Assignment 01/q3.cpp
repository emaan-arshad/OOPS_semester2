/*
Emaan Arshad 23I-2560 
Q 3
*/



#include<iostream>
#include<string>
#include <cstdlib>
#include <cmath>   

using namespace std;

class ChessPiece{
	private:
	    string name;
	    string color;
	    char symbol;
	
	public:
		// Default constructor with initializer list initializing a white pawn
		ChessPiece() : name("Pawn"), symbol('P'), color("white") {}
		
		ChessPiece(string aName, char aSymbol, string aColor) {
			name = aName;
			color = aColor;
			symbol = aSymbol;
		}
		// Setter methods
		void setName(string aName) {
			name = aName;
		}
		void setColor(string aColor) {
			color = aColor;
		}
		void setSymbol(char aSymbol) {
			symbol = aSymbol;
		}
		// Getter methods
		string getName() const {
			return name;
		}
		string getColor() const {
			return color;
	    }
	    char getSymbol() const {
			return symbol;
	    }
		
};

class ChessBoard{
	public:
		ChessPiece* board[8][8];
		
	    ChessBoard() {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                board[i][j] = nullptr;
            }
        }
        
        // Upper case symbols are for white team and lower case symbols are for black team
        // Initialize all the white pieces with DMA
        board[0][0] = new ChessPiece("Rook", 'R', "white");
        board[0][1] = new ChessPiece("Knight", 'N', "white");
        board[0][2] = new ChessPiece("Bishop", 'B', "white");
        board[0][3] = new ChessPiece("Queen", 'Q', "white");
        board[0][4] = new ChessPiece("King", 'K', "white");
        board[0][5] = new ChessPiece("Bishop", 'B', "white");
        board[0][6] = new ChessPiece("Knight", 'N', "white");
        board[0][7] = new ChessPiece("Rook", 'R', "white");
        // Initializing a whole row of pawns
		for(int i = 0; i < 8; i++) {
            board[1][i] = new ChessPiece("Pawn", 'P', "white");
        }

        // Initialize all the black pieces with DMA
        // Row of pawns
		for (int i = 0; i < 8; i++) {
            board[6][i] = new ChessPiece("Pawn", 'p', "black");
        }
        board[7][0] = new ChessPiece("Rook", 'r', "black");
        board[7][1] = new ChessPiece("Knight", 'n', "black");
        board[7][2] = new ChessPiece("Bishop", 'b', "black");
        board[7][3] = new ChessPiece("Queen", 'q', "black");
        board[7][4] = new ChessPiece("King", 'k', "black");
        board[7][5] = new ChessPiece("Bishop", 'b', "black");
        board[7][6] = new ChessPiece("Knight", 'n', "black");
        board[7][7] = new ChessPiece("Rook", 'r', "black");
    }

    // Destructor
    ~ChessBoard() {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                delete board[i][j];
            }
        }
    }

    // Display the chessboard (kept constant as it's like a getter method)
    void display() const {
        cout << "  a b c d e f g h " << endl;
        for(int i = 0; i < 8; i++) {
        	// Mentioning the row numbers
            cout << 8 - i << " ";
            for(int j = 0; j < 8; j++) {
                if (board[i][j] == nullptr) {
                    cout << ". ";
                } else {
                	// Symbol of the required pawn will be printed on the board
                    cout << board[i][j]->getSymbol() << " ";
                }
            }
            cout << 8 - i << endl;
        }
        cout << "  a b c d e f g h " << endl;
    }
    
   bool movePiece(string& source, string& destination) {
    // Converting source and destination strings to row and column numerical values
    // Initial coordinates
    int sourceRow = 8 - (source[1] - '0');
    int sourceCol = source[0] - 'a';
    // Coordinates where the piece is supposed to go
    int destRow = 8 - (destination[1] - '0');
    int destCol = destination[0] - 'a';

    // Limits validation for rows and columns
    if (sourceRow < 0 || sourceRow >= 8 || sourceCol < 0 || sourceCol >= 8 || destRow < 0 || destRow >= 8 || destCol < 0 || destCol >= 8) {
        cout << "Invalid coordinates." << endl;
        return false;
    }

    // Getting the pointer to the chesspiece at the source position
    ChessPiece* piece = board[sourceRow][sourceCol];

    // Checks if there is already a piece at the source position using nullptr that we initialized before
    if (piece == nullptr) {
        cout << "There is no piece at the source position." << endl;
        return false;
    }

    // Checks if the destination position is occupied by a piece of the same color
    if (board[destRow][destCol] != nullptr && board[destRow][destCol]->getColor() == piece->getColor()) {
        cout << "Cannot move piece to the destination position occupied by a piece of the same color." << endl;
        return false;
    }

    // Checks if the move is valid based on the type of piece
    char symbol = piece->getSymbol();
    // Knight movement
    if (symbol == 'N' || symbol == 'n') { 
        // Calculate the difference in row and column indices
        // abs() function returns the absolute value of any integer like the sign is ignored
        int rowDiff = abs(destRow - sourceRow);
        int colDiff = abs(destCol - sourceCol);

        // Checks if knight movement is possible in L shape by checking for 2 possible scenarios when this happens
        if ((rowDiff == 1 && colDiff == 2) || (rowDiff == 2 && colDiff == 1)) {
            // Move the knight to the destination position
            delete board[destRow][destCol]; // Remove or capture the piece at the destination if any
            board[destRow][destCol] = piece; // Make the move of the piece
            board[sourceRow][sourceCol] = nullptr; // Set the source position to empty
            cout << "Moved knight from " << source << " to " << destination << endl;
            return true;
        } else {
            cout << "Invalid move for the knight piece." << endl;
            return false;
        }
    // Now implementing logic for pawns
    } else if (symbol == 'P' || symbol == 'p') { 
        // See if it's the first move of the pawn because here it can move one or two steps
        // Ternary operator used to find if pawn is in the initial position or not
		int initialRow = piece->getColor() == "white" ? 6 : 1;
		// -1 to move up and 1 to move down
        int step = piece->getColor() == "white" ? -1 : 1;
        // Scenario where an attempt to make a double movement is made
        if (sourceRow == initialRow && destCol == sourceCol && (destRow == sourceRow + step || destRow == sourceRow + 2 * step)) {
            // Checks if there is no piece in the path for a two-step move
            if (destRow == sourceRow + 2 * step && board[sourceRow + step][sourceCol]) {
                cout << "Cannot move pawn. A piece is in the way." << endl;
                return false;
            }

            // Move pawn to the destination position
            delete board[destRow][destCol]; // Deleting the piece if any at the destination
            board[destRow][destCol] = piece; // Move the piece to the destination
            board[sourceRow][sourceCol] = nullptr; // Set the source position to empty
            cout << "Moved pawn from " << source << " to " << destination << endl;
            return true;
        // Scenario where a single movement move is being made
        } else if (destCol == sourceCol && destRow == sourceRow + step) {
            // Check if the destination position is empty
            if (!board[destRow][destCol]) {
                // Move the pawn to the destination position
                delete board[destRow][destCol]; 
                board[destRow][destCol] = piece;
                board[sourceRow][sourceCol] = nullptr; 
                cout << "Moved pawn from " << source << " to " << destination << endl;
                return true;
            } else {
                cout << "Cannot move the pawn as the destination position is occupied." << endl;
                return false;
            }
        } else {
            cout << "Invalid move for the pawn." << endl;
            return false;
        }
    } else {
        cout << "This movement is not supported for this piece." << endl;
        return false;
    }

    // Perform the move by updating the new position with the piece and the old position with a nullptr
    board[destRow][destCol] = piece;
    board[sourceRow][sourceCol] = nullptr;

    return true;
}

};

int main() {
	cout<<"EMAAN ARSHAD 23I2560\n";
	ChessBoard board;
	board.display();
    
	// Scenario where a valid move was made	
	string source = "b8";
    string destination = "a6";
    cout << "Is move from b8 to a6 valid? " << (board.movePiece(source, destination) ? "Yes" : "No") << endl;
    
    // A scenario where an invalid move was made
    source = "b8";
    destination = "d7";
    cout << "\n\nIs move from b8 to d7 valid? " << (board.movePiece(source, destination) ? "Yes" : "No") << endl;


    // Display the updated status of the board
    cout << "\n\nBoard with the knight moved shown" << endl;
    board.display();
    
    string source2 = "a2";
    string destination2 = "a3";
    cout << "Is move from a2 to a4 valid? " << (board.movePiece(source2, destination2) ? "Yes" : "No") << endl;

    // Display the updated status of the board
    cout << "\nBoard with the pawn moved shown:" << endl;
    board.display();
}
