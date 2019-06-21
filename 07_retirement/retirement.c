#include<stdio.h>
#include<stdlib.h>

//Define Struct
struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;


//Interest Function per month
double interest(double initial, double r_o_r)
{
  double ans = (initial * (r_o_r / 12));
  return ans;
}

//Print balance every month Function
double total_balance_when_working_retired(double initial, int startAge, retire_info b)
{
  int x, y;
  double z = 0;

  for(int i = startAge; i <= (startAge + b.months - 1); i++)
    {
      //To show years
      x = i / 12;

      //To show remaining months as a remainder
      y = i % 12;

      printf("Age %3d month %2d you have $%.2f\n", x, y, initial); 
      z = interest(initial, b.rate_of_return);
      initial += (z + b.contribution);
    }
  return initial;
}


//retirement function
void retirement(int startAge, double initial, retire_info w, retire_info r)
{
  //Function call when working
  initial = total_balance_when_working_retired(initial, startAge, w);
  startAge = (startAge + w.months);
  //Function call when retired
  total_balance_when_working_retired(initial, startAge, r);
}

//Main Function
int main()
{
  retire_info working;
  retire_info retired;

//working variable data of type struct myaccount: Months, Contribution in $, ROR per year
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045;
  
//retired variable data of type struct myaccount: Months, Contribution in $, ROR per year
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01;
  
//calling function retirement with Age = 327 Months, Savings = $21,345, structs working and retired
  retirement(327, 21345, working, retired);
  
  return 0;
}

