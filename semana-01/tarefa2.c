#include <math.h>
#include <stdio.h>

int main() {
    float con = 0;
    float seno = 0;
    float tang = 0;
    float ang = 0;

    printf("Digite o valor do cosseno: ");
    scanf("%f", &con);

    ang = acos(con);
    seno = sin(ang);
    tang = tan(ang);
    
    ang = ang*(180/M_PI);
    
    printf("\nSeno: %f", seno);
    printf("\nTangente: %f", tang);
    printf("\nAngulo: %f", ang);


    return 0;
}
