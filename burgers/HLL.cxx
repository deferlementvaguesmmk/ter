#include "HLL.hxx"


HLL::
HLL(int taille_, double* X_,double* U_,double Xmin_,double dx_,double dt_,double lambda1_, double lambda2_)
{
  taille=taille_;
  X=X_;
  U=U_;
  Xmin=Xmin_;
  dx=dx_;
  lambda1=lambda1_;
  lambda2=lambda2_;
}

double* HLL::
GetU(){return U;}

void HLL::
Write(const string name)
{
  ofstream file_out(name.data());
  for ( int i = 0 ; i < taille ; i++)
    file_out<<Xmin+i*dx<<" "<<X[i] <<'\n';
  file_out.close();
}

void HLL::
Advance()
{
  //double 
  
  return ;
}
