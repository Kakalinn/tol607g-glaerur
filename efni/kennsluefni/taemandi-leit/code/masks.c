#include <stdio.h>

int einstokungur(int x) { return 1 << x; }                                      // Skilar bitakenni fyrir einstökunginn {x}.
int fyllimengi(int k) { return ~k; }                                            // Skilar bitakenni fyrir fyllimengi bitkennisins k.
int sammengi(int j, int k) { return j|k; }                                      // Skilar bitakenni sammengis bitakennanna j og k.
int snidmengi(int j, int k) { return j&k; }                                     // Skilar bitakenni sniðmengis bitakennanna j og k.
int samhverfur_mismunur(int j, int k) { return j^k; }                           // Skilar bitakenni samhverfs mismunar bitakennanna j og k.
int mismunur(int j, int k) { return j&(~k); }                                   // Skilar bitakenni mismunar bitakennanna j og k.
int inniheldur(int k, int x) { return k&(1 << x); }                             // Skilar hvort x sé í menginu sem svarar til bitakennisins k.

int main()
{
    return 0;
}
