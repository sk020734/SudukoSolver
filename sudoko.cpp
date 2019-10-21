#include <bits/stdc++.h>
using namespace std;

class board{
    int mat[9][9];
    public:
    board();
    void getboard();
    bool solve();
    void display();
    void display2();
    bool safe(int,int,int);
    bool complete();
    pair<int,int> vacant();
};

board :: board(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
                mat[i][j] = 0;
}
void board :: getboard(){
    cout << "Enter the state of the board\n";
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
              cin >> mat[i][j]; 
}

void board ::  display(){
        for(int i=0;i<9;i++){
            if(i&&i%3==0)
                cout<<"-------  ------  -----\n";
           for(int j=0;j<9;j++)
              if(j && (j)%3==0)
                cout<<" | "<<mat[i][j];
                    else
                cout<<" "<<mat[i][j];
          
          cout << endl;  
        }

}
bool board :: complete(){
    for(int i=0;i<9;i++) 
        for(int j=0;j<9;j++) 
            if(mat[i][j]==0) return false;
    return true;        
}

bool board :: solve(){
    if(complete()) return true;
    pair<int,int> p1;
    p1 =  vacant();
    int row = p1.first;
    int col = p1.second;

    for(int i=1;i<=9;i++){
            if(safe(row,col,i)){
                mat[row][col] = i;
           
            if(solve()) return true;
            
                mat[row][col] = 0;
            
           } 
        } 
     return false;
}

bool board :: safe(int row,int col,int num){
    
    for(int i=0;i<9;i++){
        if(mat[row][i]==num) 
           return false;
    }
    
    for(int i=0;i<9;i++){
        if(mat[i][col]==num) return false;
    }
   
    for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (mat[i + row - row % 3][j + col - col%3] == num) 
			{
				return false;
}
  
    return true;
}
pair<int,int> board :: vacant(){
     int row,col;
     pair<int,int> p;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]==0){
                    p.first  =  i;
                    p.second = j; 
                     return p;
                }
            }
        }                            
}

int main(){
   board ob;
       ob.getboard();
       if(ob.solve()) ob.display();      
       else cout << " Solution Does not exist";


 return 0;
}
