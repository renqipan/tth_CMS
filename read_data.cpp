#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void read_data()
{
    ifstream infile;
    infile.open("xgboost.CSV");
    if(!infile) cout<<"error"<<endl;
    if(infile){
        string str;
        float t1;
        cout<<"write data into an array"<<endl;
        float a[27846][2];
        float *p=&a[0][0];
        while(infile>>t1){
            *p=t1;
            p++;
        }
         infile.close();
        for(int i=1000;i<1100;i++)
        {   for(int j=0;j<2;j++)
               cout<<a[i][j]<<"\t";
             cout<<endl;
        }
} 
    return 0;

}