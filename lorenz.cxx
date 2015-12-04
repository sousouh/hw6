#include <iostream>

using namespace std;

void RK(double* k, double x, double y,double z){
 double a,b,c;  
 a=10.;
 b=28.;
 c=8./3.;

   k[0] = a*(y - x);
   k[1] = x*(b - z) - y;
   k[2] = x*y - c*z;

}

int main(){
 int N;
 double dt;
 double x,y,z;

 double k1[3];
 double k2[3];
 double k3[3];
 double k4[3];

 x=1.;
 y=1.;
 z=1.;

 N=100001;
 dt=100./(N-1.);
 
 cout << "0.0" << "\t" << x << "\t" << y << "\t" << z << endl;
 
 for(double t=dt; t<=100.; t+=dt){
   
   RK(k1,x,y,z);
   RK(k2,x+(dt/2.)*k1[0],y+(dt/2.)*k1[1],z+(dt/2.)*k1[2]);
   RK(k3,x+(dt/2.)*k2[0],y+(dt/2.)*k2[1],z+(dt/2.)*k2[2]);
   RK(k4,x+(dt*k3[0]),y+(dt*k3[1]),z+(dt*k3[2]));
   
   x += (dt/6.)*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
   y += (dt/6.)*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);
   z += (dt/6.)*(k1[2] + 2*k2[2] + 2*k3[2] + k4[2]);

   
   cout << t << "\t" << x << "\t" << y << "\t" << z << endl;
   
 }
 
  return 0;
}