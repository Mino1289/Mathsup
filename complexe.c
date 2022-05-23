#include <complexe.h>

void printComplexe(Complexe z, Boolean wparenthesis) {
    if (wparenthesis) {
        printf("(");
    }
    if (z.real != 0) {
        printf("%.1f", z.real);
    }
    if (z.imag > 0) {
        if (z.real != 0) {
            printf(" + ");
        }
        if (z.imag == 1) {
            printf("i");
        } else {
            printf("%.1f*i", z.imag);
        }
    } else if (z.imag < 0) {
        if (z.real != 0) {
            printf(" - ");
        }
        if (z.imag == -1) {
            printf("i");
        } else {
            printf("%.1f*i", -z.imag);
        }
    }
    if (wparenthesis) {
        printf(")");
    }    
}

Complexe addComplexe(Complexe z1, Complexe z2) {
    Complexe z;
    z.real = z1.real + z2.real;
    z.imag = z1.imag + z2.imag;
    return z;
}

Complexe subComplexe(Complexe z1, Complexe z2) {
    Complexe z;
    z.real = z1.real - z2.real;
    z.imag = z1.imag - z2.imag;
    return z;
}

Complexe conjugateComplexe(Complexe z) {
    Complexe zConjugate;
    zConjugate.real = z.real;
    zConjugate.imag = -z.imag;
    return zConjugate;
}

double moduleComplexe(Complexe z) {
    return sqrt(z.real * z.real + z.imag * z.imag);
}

double argumentComplexe(Complexe z) {
    return atan2(z.imag, z.real);
}

Complexe multComplexebyScalar(Complexe z, double scalar) {
    Complexe z1;
    z1.real = z.real * scalar;
    z1.imag = z.imag * scalar;
    return z1;
}

Complexe multComplexebyComplexe(Complexe z1, Complexe z2) {
    Complexe z;
    z.real = z1.real * z2.real - z1.imag * z2.imag;
    z.imag = z1.real * z2.imag + z1.imag * z2.real;
    return z;
}

Complexe inverseComplexe(Complexe z) {
    Complexe zInverse;
    double module = moduleComplexe(z);

    zInverse.real = z.real / (module * module);
    zInverse.imag = -z.imag / (module * module);
    return zInverse;
}

Complexe divComplexebyComplexe(Complexe z1, Complexe z2) {
    Complexe z = inverseComplexe(z2);    
    z = multComplexebyComplexe(z,z1);
    return z;
}

Complexe powerComplexe(Complexe z, int n) {
    Complexe z1;
    if (z.imag == 0) {
        z1.real = pow(z.real, n);
        z1.imag = 0;
    } else if (z.real == 0) {
        if (n % 4 == 0) {
            z1.real = pow(z.imag, n);
            z1.imag = 0;
        } else if (n % 4 == 1) {
            z1.real = 0;
            z1.imag = pow(z.imag, n);
        } else if (n % 4 == 2) {
            z1.real = -pow(z.imag, n);
            z1.imag = 0;
        } else if (n % 4 == 3) {
            z1.real = 0;
            z1.imag = -pow(z.imag, n);
        } else {
            // we should never get here
            fprintf(stderr, "ERROR: n mod 4 != 0/1/2/3\n");
        }
    } else {
        double module = moduleComplexe(z), arg = argumentComplexe(z);
        z1.real = pow(module, n) * cos(n * arg);
        z1.imag = pow(module, n) * sin(n * arg);
    }
    return z1;
}