#include <iostream>
#include <fstream>
#include <cmath>

// Codigo tomado del Laboratorio
using namespace std;

// variable constantes globales
const double g = 9.8; 
const double K = 0.7;
double vox = 10;
double voy = 10;
const double T = (2*voy)/g;
const double n = 1;
const double DeltaT = 0.01;


// declaracion de funciones
double fy0(double t, double y0, double y1); // derivada de y0
double fy1(double t, double y0, double y1); // derivada de y1
double fx0(double t, double x0, double x1); // derivada de x0
double fx1(double t, double x0, double x1); // derivada de x1
void rk4(double t, double h, double & y0, double & y1, double & x0, double & x1); // metodo de runge kutta 4 orden
void Pro(double t);

int main(void){
    
   ofstream outfile;
   outfile.open("rk4.dat");
    
  double x, time, y;
  x = 0;
  y = 0;
    
  for(time = 0; time <= T; time += DeltaT){
    outfile << x << "\t" << y << endl;
    rk4(time, DeltaT, y, voy, x, vox);
  } 
  outfile.close();
  Pro(DeltaT, x, y);

  return 0;
}

double fy0(double t, double y0, double y1){
  return y1;
}

double fy1(double t, double y0, double y1, double x1){
  return (-g-K*pow(y1, n)*y1/(sqrt(pow(x1, 2)+pow(y1, 2))));
}

double fx0(double t, double x0, double x1){
  return x1;
}

double fx1(double t, double y0, double y1, double x1){
  return (-K*pow(x1, n)*x1/(sqrt(pow(x1, 2)+pow(y1, 2))));
}

void rk4(double t, double h, double & y0, double & y1, double & x0, double & x1){
    
  double k10, k11, k20, k21, k30, k31, k40, k41;
    
  k10 = h*fy0(t, y0, y1);
  k11 = h*fy1(t, y0, y1, x1);
  k20 = h*fy0(t+h/2, y0 + k10/2, y1 + k11/2);
  k21 = h*fy1(t+h/2, y0 + k10/2, y1 + k11/2, y1);
  k30 = h*fy0(t+h/2, y0 + k20/2, y1 + k21/2);
  k31 = h*fy1(t+h/2, y0 + k20/2, y1 + k21/2, y1);
  k40 = h*fy0(t + h, y0 + k30, y1 + k31);
  k41 = h*fy1(t + h, y0 + k30, y1 + k31, y1);

  y0 = y0 + (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
  y1 = y1 + (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
    
  k10 = h*fx0(t, x0, x1);
  k11 = h*fx1(t, x0, x1, y1);
  k20 = h*fx0(t+h/2, x0 + k10/2, x1 + k11/2);
  k21 = h*fx1(t+h/2, x0 + k10/2, x1 + k11/2, y1);
  k30 = h*fx0(t+h/2, x0 + k20/2, x1 + k21/2);
  k31 = h*fx1(t+h/2, x0 + k20/2, x1 + k21/2, y1);
  k40 = h*fx0(t + h, x0 + k30, x1 + k31);
  k41 = h*fx1(t + h, x0 + k30, x1 + k31, y1);

  x0 = x0 + (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
  x1 = x1 + (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
}

void Pro(double t, double x, double y){
    
   ofstream outfile;
   outfile.open("Pro.dat");
	
   x = 10*time;
   y = 10*time - (1/2)*g*pow(time,2);
    
    for(time = 0; time <= T; time += DeltaT){
    outfile << x << "\t" << y << endl;
  } 
    outfile.close(); 
}