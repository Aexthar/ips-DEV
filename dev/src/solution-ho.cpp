#include "../hdr/solution-ho.h"
#include <armadillo>
#include "../hdr/constants.h"
#include <iostream>
#include <fstream>

Solution1DHO::Solution1DHO(int n, double m, double w) : n(n), m(m), w(w)
{

}

int Solution1DHO::factN(int n){
    int fact_n = 1;
    for(int i = 0; i <n ; i++)
    {
        fact_n = fact_n*(n - i);
    }

    return(fact_n); 
}

double Solution1DHO::calcHamilton(double z)
{
    double h0 = 1;
    double h1 = 2*z;
    double hn;

    if(n == 0)
    {
        return(h0);
    } 
    else if(n == 1)
    {
        return(h1);
    }
    else
    {
        for(int i = 2; i <= n; i++)
        {
            hn = 2*z*h1 - 2*n*h0;
            h0 = h1;
            h1 = hn;
        }
        return(hn);
    }
}

double Solution1DHO::calcSolution(double z)
{
    double psi;
    double hn = this->calcHamilton(sqrt(m*w/hbar)*z);
    double fact_n = (double)factN(n);

    psi = (1/sqrt(pow(2, n)*fact_n))*pow(m*w/(arma::datum::pi*hbar), 1/4)*exp(-(m*w*z*z)/(2*hbar))*hn;

    return psi;
}

double Solution1DHO::calcFacile(double z)
{
    double psi;
    double hn = this->calcHamilton(sqrt(m_facile*w_facile/hbar_facile)*z);
    double fact_n = (double)factN(n);

    psi = (1/sqrt(pow(2,n)*fact_n))*pow(m_facile*w_facile/(arma::datum::pi*hbar_facile), 1/4)*exp(-(m_facile*w_facile*z*z)/(2*hbar_facile))*hn;

    return psi;
}

void Solution1DHO::exportPoints(double min_z, double max_z, int nb_points, bool easy_mode)
{
    std::vector<double> x_axis;
    std::vector<double> z_axis;

    for(int i = 0; i <= nb_points; i++)
    {
        x_axis.push_back((double)min_z + (max_z - min_z)*i/nb_points);
    }

    if(easy_mode)
    {
        for(double x: x_axis)
        {
            z_axis.push_back(calcFacile(x));
        }
    }
    else
    {
       for(double x: x_axis)
       {
            z_axis.push_back(calcSolution(x));
        } 
    }

    std::ofstream res_file;
    res_file.open("../../out/res.csv");

    for(int i = 0;i<= nb_points;i++)
    {
        res_file << x_axis[i];
        res_file << ",";
        res_file << z_axis[i];
        res_file << "\n";
    }

    res_file.close();
   
}