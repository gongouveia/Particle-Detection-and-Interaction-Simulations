

#ifndef BoxMullerGenerator_h
#define BoxMullerGenerator_h 1


class Muller {

// m onde está centrada
// s desvio padrão
public:
float box_muller(int m, float s) {                     
float x1, x2, w, y1;
static float y2;
static int use_last = 0;

if (use_last) {
    y1 = y2;
    use_last = 0;
}
else {
    do {
        x1 = 2.0 * ((double)rand() / (RAND_MAX)) - 1.0;
        x2 = 2.0 * ((double)rand() / (RAND_MAX)) - 1.0;
        w = x1 * x1 + x2 * x2;
    } while (w >= 1.0);

    w = sqrt((-2.0 * log(w)) / w);
    y1 = x1 * w;
    y2 = x2 * w;
    use_last = 1;
}

return(m + y1 * s);
}


}mulls;

#endif
