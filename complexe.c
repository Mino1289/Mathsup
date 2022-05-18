#include <complexe.h>

void printComplexe(Complexe z) {
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
    z.real *= scalar;
    z.imag *= scalar;
    return z;
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