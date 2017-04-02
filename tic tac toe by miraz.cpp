#include<iostream>
#include<cstring>
using namespace std;

void screen();
int checkWin(int i);
string arr[3][3]={"1","2","3","4","5","6","7","8","9"};

int main()
{
    string inp;
    int count;
    for(int i=1;i<=2;i++)
    {
        screen();
        cout<<"Player "<<i<<"'s turn: ";
        cin>>inp;
        count=0;
        if(inp[0]>='1'&&inp[0]<='9')
        {
            for(int row=0;row<3;row++)
                for(int col=0;col<3;col++)
                {
                    if(arr[row][col]==inp)
                    {
                        if(i==1)
                            arr[row][col]="X";
                        else
                            arr[row][col]="O";
                        count++;
                    }
                }
        }
        if(count==0)
        {
            i--;
            cout<<"Invalid Move"<<endl;
            cin.ignore();
			cin.get();
        }
        if(checkWin(i)==1)
        {
            screen();
            cout<<"=====>Player "<<i<<" win<====="<<endl;
            cin.ignore();
            cin.get();
            break;
        }
        else if(checkWin(i)==0)
        {
            screen();
            cout<<"=====>Game Draw<====="<<endl;
            cin.ignore();
            cin.get();
            break;
        }

        if(i==2)
            i=0;
    }
    return 0;
}

int checkWin(int i)
{
    if(arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2])
       return 1;
    else if(arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2])
       return 1;
    else if(arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2])
       return 1;
    else if(arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0])
       return 1;
    else if(arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1])
       return 1;
    else if(arr[0][2]==arr[1][2]&&arr[1][2]==arr[2][2])
       return 1;
    else if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])
       return 1;
    else if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])
       return 1;
    else if(arr[0][0]!="1"&&arr[0][1]!="2"&&arr[0][2]!="3"&&arr[1][0]!="4"&&arr[1][1]!="5"&&arr[1][2]!="6"&&arr[2][0]!="7"&&arr[2][1]!="8"&&arr[2][2]!="9")
        return 0;
    else
        return -1;
}

void screen()
{
    cout<<"\n"<<endl;
    cout<<"\t\tTic Tac Toe\t\t"<<endl;
    cout<<"\tPlayer-1(X)\tPlayer-2(O)\t"<<endl;
    cout<<"\t \t|\t \t|\t \t"<<endl;
    cout<<"\t"<<arr[0][0]<<"\t"<<"|"<<"\t"<<arr[0][1]<<"\t"<<"|"<<"\t"<<arr[0][2]<<"\t"<<endl;
    cout<<"\t \t|\t \t|\t \t"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"\t \t|\t \t|\t \t"<<endl;
    cout<<"\t"<<arr[1][0]<<"\t"<<"|"<<"\t"<<arr[1][1]<<"\t"<<"|"<<"\t"<<arr[1][2]<<"\t"<<endl;
    cout<<"\t \t|\t \t|\t \t"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"\t \t|\t \t|\t \t"<<endl;
    cout<<"\t"<<arr[2][0]<<"\t"<<"|"<<"\t"<<arr[2][1]<<"\t"<<"|"<<"\t"<<arr[2][2]<<"\t"<<endl;
    cout<<"\t \t|\t \t|\t \t"<<endl;
    cout<<endl;
}

