# Word_Scramble
#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
void user(string o[],string s[],int n,string h[])
{
    int i,choice;
    float score;
    string g;
    cout<<"Get ready to play"<<endl;
    cout<<"No. of words are"<<n<<endl;
    for(i=0;i<n;)
    {
        cout<<"Your word is"<<endl;
        cout<<s[i]<<endl;
        cout<<"Your guess is??"<<endl;
        cin>>g;
        if(o[i]==g)
        {
            cout<<"Correct"<<endl;
            score=score+1;
            cout<<"Score:"<<score<<endl;
            i++;
        }
        else
        {
             cout<<"Incorrect"<<endl;
             cout<<"If you want a hint press 1 otherwise 2 for next word"<<endl;
             cin>>choice;
             if(choice==1)
             {
                 cout<<h[i]<<endl;
                 score=score-0.5;
                 cin>>g;
                  if(o[i]==g)
                  {
                  cout<<"Correct"<<endl;
                   score=score+1;
                   cout<<"Score:"<<score<<endl;
                   i++;
                    }
                   else i++;
                 
             }
             else if(choice==2)
             {
                 i++;
             }
        }
        if(i==n)
        cout<<"Game over";
    }
}
string scramble(string a)
{
    int i,index;
    string temp;
    int len=a.size();
    index=rand()%len;
    for(i=0;i<len;i++)
    {
        temp[i]=a[index];
        a[index]=a[i];
        a[i]=temp[i];
    }
    return a;
}
void admin()
{
    int i,j,n;
    string b[100],o[100],s[100],h[100];
    
    cout<<"enter the no. of words"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>b[i];
        o[i]=b[i];
        s[i]=scramble(b[i]);
    }
    for(i=0;i<n;i++)
    {
    cout<<"Original word"<<" "<<o[i]<<endl;
    cout<<"Scrambled word"<<" "<<s[i]<<endl;
    }
    cout<<"Enter the hints for each word"<<endl;
    cin.ignore();
    for(i=0;i<n;i++)
    {
    getline(cin,h[i]);
    cout<<h[i]<<endl;
    }
    user(o,s,n,h);
}

int main() {
admin();
	return 0;
}

