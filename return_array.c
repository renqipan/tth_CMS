
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
 
#include <vector>
int *getRandom(int tt[4],char pp )
{
   static int  r[4];
 if(pp=='E') cout<<"energy"<<endl;
if(pp=='m')cout<<"mass"<<endl;
  for (int i = 0; i < 4; ++i)
  {
    r[i] = tt[i]+i;
   // cout << r[i] << endl;
  }
 
  return r;
}
 
// 要调用上面定义函数的主函数
int return_array ()
{
   // 一个指向整数的指针
   int *p,*m;
 int kk[4]={1,2,3,4};
 int yy[4]={2,3,4,1};
   p = getRandom(kk,'E');
   for ( int i = 0; i < 4; i++ )
   {
      cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }

  m = getRandom(yy,'m');
   for ( int i = 0; i < 4; i++ )
   {
      cout << "*(m + " << i << ") : ";
       cout << *(m + i) << endl;
   }
 
   return 0;
}
