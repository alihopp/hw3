#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// declaration of functions
void rnd_val(double *p,const int N);
 
// Note: function mean_val, var_val can also be written in one function!
void mean_val(double *p, const int N, double &mean), var_val(double *p, const int N, double &mean, double &var);


// main function
int main(){
   const int N = 10;
   double p[N];
   double mean, var;
  
   srand(time(NULL)); // Note: without there is no random array values
   
   rnd_val(p,N);
   mean_val(p,N,mean);
   var_val(p,N,mean,var);

 
   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;

   return 0;
}

//--------------------------------------------------------------
// array of random value in the interval [0,1]
void rnd_val(double *p, const int N)
{
  for(int i=0; i<N; i++) // NOT: i<=N, reason: starting counting from i=0
     {
       p[i] = (double) rand()/(RAND_MAX); 
       // cout << i <<" " << p[i] << endl;     
     }
}

//---------------------------------------------------------------
// calculating mean value of array
void mean_val(double *p, const int N, double &mean)
{
   mean = 0;
   for(int i=0; i<N; i++)
    {
      mean += p[i]/N; // alternative: mean = mean + p[i]/N
    }
}

//----------------------------------------------------------------
// calculating variance value of array from mean
void var_val(double *p, const int N, double &mean, double &var) 
{
   var = 0;
   for(int i=0; i<N; i++)
     {
       var += pow(p[i]-mean,2.0)/N; // alternative: var = ((p[i]-mean)/N)*((p[i]-mean)/N)
     }
}
//----------------------------------------------------------------
