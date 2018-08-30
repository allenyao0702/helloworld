#include <iostream>
#include <vector>

using namespace std;

const int Demension=9;


class Board{
private:
    int row_=Demension;
    int col_=Demension;
    bool done=false;
    vector<vector<int>>* board_;
public:

    Board(){
        board_ = new vector<vector<int>>(9,vector<int>(9,0));
    }

    ~Board(){
        delete board_;
    }

    void Fill(vector<vector<int>>& values){
        for(int i=0;i<row_;i++){
            for(int j=0;j<col_;j++)
            {
                (*board_)[i][j]=values[i][j];
            }
        }
    }

    void Solve(){

    }
};


void possibleValues(vector<vector<int>>& a, int x, int y, vector<int>& p)
{
    if (x<0 || x>8 ||y<0||y>8)
        return ;
    p={1,2,3,4,5,6,7,8,9};
    for (int i = 0; i<9; i++)
	{
		if (a[x][i] != 0)
		{
			int pos = a[x][i]-1;
			p[pos] = -1;
		}
	}
	for (int j = 0; j<9; j++)
	{
		if ((a[j])[y] != 0)
		{
			int pos = (a[j])[y]-1;
			p[pos] = -1;
		}
	}

    int bucket_x=x/3;
    int bucket_y=y/3;
    int bucket_posx=x%3;
    int bucket_posy=y%3;
    for (int i=bucket_x*3;i<bucket_x*3+3;i++)
    {
        for (int j=bucket_y*3;j<bucket_y*3+3;j++)
        {
            if (a[i][j]!=0)
            {
                p[(a[i])[j]-1]=-1;
            }
        }
    }
    //return &p;
    //return [];
}

int main()
{
    //cout<<"hel"<<endl;
    //return 0;
    vector<vector<int>> a={
    {6,2,1,0,0,4,0,9,3},
    {8,0,0,3,5,2,6,0,0},
    {3,7,5,0,0,0,4,2,0},
    {9,5,8,2,3,7,1,0,0},
    {0,1,6,4,9,8,0,0,0},
    {4,3,2,6,0,5,7,0,9},
    {0,8,0,0,4,0,2,1,0},
    {1,0,9,7,0,0,0,0,0},
    {0,6,7,5,8,1,0,3,0}
    };
    int x,y;
    x=3;
    y=3;
    
    int bucket_x=x/3;
    int bucket_y=y/3;
    int bucket_posx=x%3;
    int bucket_posy=y%3;
    vector<int> possible;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<"start"<<endl;
            possibleValues(a, i, j, possible);
            if (possible.size()==1)
            {
               a[i][j]=possible[0];
            }
            cout<<"{";
            for(int x=0;x<9;x++)
            {
               if (possible[x]!=-1)
                   cout<<possible[x]<<",";
            }
            cout<<"}"<<endl;
            
        }
    }
 
    
    cout<<"end"<<endl;
    return 0;
}





