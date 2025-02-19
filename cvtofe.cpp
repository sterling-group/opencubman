/* cvtofe.cpp */
/* Contour Value (CV) to Fraction of Electrons (FE) Program */
/* Modified by Markus G. S. Weiss on 2024-11-04 */
/* This program is distributed "as is" WITHOUT ANY WARRANTY; see the LICENSE file for more details. */
/* This file is part of OpenCubMan and is licensed under the GNU General Public License v2.0. */
/* Based on the original work by Maciej Haranczyk and Prof. Maciej Gutowski. */
/* See the LICENSE and AUTHORS files for details. */
/*
 * Reference:
 * Haranczyk, M., & Gutowski, M. (2008). Visualization of molecular orbitals and the related electron densities.
 * Journal of Chemical Theory and Computation, 4(5), 689-693. https://doi.org/10.1021/ct800043a
 */

#include "opencubman.h"

int main(int argc, char* argv[])
{
    Cube cube1;
    double cv;

    if (argc >= 3)
    {
        // Parse input arguments
        cv = atof(argv[2]);

        // Read cube file with auto-detection
        cube1.read_cube(argv[1]);

        // Allocate and sort data
        cube1.sort_allocate();
        cube1.sortf();

        // Calculate Fraction of Electrons (FE) for given Contour Value (CV)
        double fe = cube1.x_forw(cv);

        // Output result
        printf("CV = %.4lf FE = %.4lf\n", cv, fe);
    }
    else
    {
        // Print help message
        cout << " O P E N C U B M A N   P A C K A G E   version 1.00 " << endl;
        cout << endl;
        cout << " Contour Value (CV) to Fraction of Electrons (FE) Program " << endl << endl;
        cout << " This program reads a cube file and calculates the FE corresponding to a selected CV." << endl << endl;
        cout << " Usage: cvtofe input.cube CV" << endl << endl;
        cout << " The program auto-detects the cube file format (Orca or Q-Chem) and data type (density or orbital)." << endl;
        cout << " If needed, please ensure that the first two lines of the cube file contain appropriate information." << endl;
    }

    return 0;
}

