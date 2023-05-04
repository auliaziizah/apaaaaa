#include <stdio.h>

double ln(double nilai) {
    double result = 0.0;
    double y = (nilai - 1) / (nilai + 1);
    double power = y;
    double term = power;
    int count = 1;
    while (term > 1e-15 || term < -1e-15) {
        result = result + term;
        power = power * y * y;
        term = power / (2 * count + 1);
        count++;
    }
    return 2 * result;
}

double logaritmaBebas(double nilai, double basis){
	double lnX, lnY, hasil;
	lnX = ln(nilai);
	lnY = ln(basis);
	hasil = lnX / lnY;
	return hasil;
}

int main() {
    double nilai, basis, result;
    
    printf("Masukkan angka: ");
    scanf("%lf", &nilai);
    printf("Masukkan basis: ");
    scanf("%lf", &basis);
    
    if (nilai > 0 && basis > 0 ){
	    result = logaritmaBebas(nilai, basis);
	    printf("Log%.lf(%.lf) = %.5lf", basis, nilai, result);
	}
	else {
		printf("\nInvalid input");
	}
}
