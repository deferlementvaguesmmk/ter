#include "HLL.cxx"


int main()
{
  int N=100;
  double* U,X;
  U= new double[N];
  X= new double[N];
  double Xmax=5.0, Xmin=0.0, dx = (Xmax-Xmin)/N, x=Xmin;
  double Tmax=1.0,Tmin=0.0,dt=0.01;
  
  for (int i = 0 ; i < N ; i++)
    {
      if (x<3.14159265359)
	U[i]=1+sin(x);
      else
	U[i]=1;
      x += dx;
    }
  
  HLL hll(N,U,Xmin,dx,dt,0.99,2.01);
  
  
  hll.Write("test.dat");
 
  
  
}
