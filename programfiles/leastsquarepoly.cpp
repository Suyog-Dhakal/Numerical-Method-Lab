//#include <iostream>
//#include <vector>
//#include <cmath>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    try
    {
        int n, degree;
        cout << "Enter number of entries: ";
        cin >> n;
        cout << "Enter the degree of polynomial: ";
        cin >> degree;
        if (n < degree)
            throw 0;
        pair<float, float> value, ans;
        vector<pair<float, float>> valueVec;
        vector<float> column(degree + 2);
        vector<vector<float>> matrix;

        for (int i = 0; i <= degree; i++)
        {
            matrix.push_back(column);
        }

        float a, b, c;
        for (int i = 0; i < n; i++)
        {
            cout << "x" << i + 1 << ": ";
            cin >> value.first;
            cout << "y" << i + 1 << ": ";
            cin >> value.second;
            cout << endl;
            valueVec.push_back(value);
        }
        int p = 0;
        float y;
        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= degree; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    matrix[i][j] += pow(valueVec[k].first, p + j);
                    if (j == 0)
                        matrix[i][degree + 1] += pow(valueVec[k].first, p) * valueVec[k].second;
                }
            }
            p++;
        }

        //Solving
        //Augmented Matrix
        cout << "\nIn Augmented form: " << endl;
        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= degree + 1; j++)
            {
                if (j == degree + 1)
                    cout << ":\t";
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        //Row Operations on the Matrix
        for (int j = 0; j <= degree; j++)
        {
            for (int i = 0; i <= degree; i++)
            {
                if ((int)matrix[j][j] == 0)
                    throw 1;
                float ratio = (matrix[i][j] / matrix[j][j]);
                for (int k = 0; k <= degree + 1; k++)
                {
                    if (i != j)
                    {
                        matrix[i][k] -= (ratio)*matrix[j][k];
                    }
                    if (k == degree + 1)
                        cout << ":\t";
                    printf("%.2f\t", matrix[i][k]);
                }
                cout << endl;
            }
            cout << endl;
        }

        //Displaying Unknown values
        cout << "The unknowns are" << endl;
        int count = 0;
        for (int i = 0; i <= degree; i++)
        {
            char var = (char)('a' + i);
            cout << var << " = " << matrix[count][degree + 1] / matrix[count][count] << endl;
            count++;
        }
        matrix.clear();
    }
    catch (int n)
    {
        if (n == 0)
            cout << "Exception: Number of entries is less than degree" << endl;
        else
            cout << "Exception: Equation has no solution" << endl;
    }
}
