#ifndef SOLUTION_HO_H
#define SOLUTION_HO_H

class Solution1DHO
{
    private:
        int n;
        double m;
        double w;

    public:
        Solution1DHO(int n, double m, double w);

        int factN(int n);

        double calcHamilton(double z);

        double calcSolution(double z);

        double calcFacile(double z);

        void exportPoints(double min_z, double max_z, int nb_points, bool easy_mode);
};

#endif // SOLUTION_HO_H