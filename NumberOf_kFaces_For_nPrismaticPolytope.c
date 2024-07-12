// Calculate number of k-dimesional faces for n-dimensional Prismatic Polytope

#include <stdio.h>
#include <math.h>

// Function Prototypes
int NumberOf_kFaces_For_nPrismaticPolytope(int* m_b_ptr, int* n_d_ptr, int* k_f_ptr);
unsigned long long int  ComputeCoeff(int p,int q);
unsigned long long int pCq(int p, int q);
unsigned long long int factorial(int num);


void main()
{
    // Declare Variables
    int n_dimension, k_faces, m_base = 3, result;

    while(1)
    {
        // Take User Inputs.
        printf("\n Enter a number 'm' of the m-sided base 2D Polygon: \n");
        scanf("%d", &m_base);
        printf("\n Enter a number 'n' of the n-dimensional Polytope: \n");
        scanf("%d", &n_dimension);
        printf("\n Enter a number 'k' of the n-dimensional Faces: \n");
        scanf("%d", &k_faces);

        // Make sure m >=3 and n > k.
        if((m_base < 3) || (n_dimension < k_faces))
        {
            printf("\n INVALID INPUT \n");
        }
        else
        {
            // Compute and print the output.
            result = NumberOf_kFaces_For_nPrismaticPolytope(&m_base, &n_dimension, &k_faces);
            printf("\n The number of %d-faces for a Prismatic %d-dimensional Polytope with a %d-sided base 2D polygon is: \n%d \n\n", k_faces, n_dimension, m_base, result);
        }
    }
    
}

int NumberOf_kFaces_For_nPrismaticPolytope(int* m_b_ptr, int* n_d_ptr, int* k_f_ptr)
{
    // Dereferencing the pointers.
    int n_dimension = *n_d_ptr, k_faces = *k_f_ptr, m_base = *m_b_ptr;
    unsigned long long int result = 0;

    // Calculate p and q for combination formula
    int p = n_dimension - 2, q = 0;

    for(q = 0; q <= k_faces; q++)
    {
        unsigned long long int coeff = 0; int component;
        if(k_faces - q > 2)
        {
            component = 0;
        }
        else if(k_faces - q == 2)
        {
            component = 1;
            coeff = ComputeCoeff(p,q);
        }
        else
        {
            component = m_base;
            coeff = ComputeCoeff(p,q);
        }
        result = result + (coeff * component);
        // printf("\n coeff = %d \n", coeff);
        // printf("\n component = %d \n", component);
        // printf("\n result = %d \n", result);
    }

    return result;
}

unsigned long long int ComputeCoeff(int p,int q)
{
    // Compute the Coefficient for the combination of p,q.
    unsigned long long int result = 0;

    result = (pow(2, p - q)) * pCq(p,q);

    return result;
}

unsigned long long int pCq(int p, int q)
{
    // Check for the condition.
    if(q > p)
    {
        return 0;
    }
    else
    {
        return factorial(p) / (factorial(q) * factorial(p - q));
    }
    
}

unsigned long long int factorial(int n)
{
    // Compute the Factorial of 'n'.
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}