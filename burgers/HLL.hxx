#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>

using namespace std;




class HLL
{
private :
  int taille;
  double *U, *X; 
  double lambda1,lambda2,Xmin,dx,dt;
public :
  HLL(int taille_, double* X_,double* U_,double Xmin_,double dx_,double dt_,double lambda1_,double lambda2_);
  double* GetU();
  void Write(const string name);
  void Advance();
};
