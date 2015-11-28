#ifndef HYDRO2D_GRID
#define HYDRO2D_GRID

struct parList;

struct grid
{
    int nx1;
    int nx2;
    int nx1_int;
    int nx2_int;
    int ng;
    int nc;
    int nq;
    double x1min;
    double x1max;
    double x2min;
    double x2max;
    double t;
    double *x1;
    double *x2;
    double *prim;
    double *cons;
    double *cons_rk;
    double *grad;
    double PLM;
};

const static struct grid GRID_DEFAULT = {
    .nx1 = 0,
    .nx2 = 0,
    .nx1_int = 0,
    .nx2_int = 0,
    .ng = 0,
    .nc = 0,
    .nq = 0,
    .x1min = 0.0,
    .x1max = 1.0,
    .x2min = 0.0,
    .x2max = 1.0,
    .t = 0.0,
    .x1 = NULL,
    .x2 = NULL,
    .prim = NULL,
    .cons = NULL,
    .cons_rk = NULL,
    .grad = NULL,
    .PLM = 1.5
};

void (*reconstruction)(struct grid *);

int set_reconstruction(struct parList *pars);
void make_grid(struct grid *g, struct parList *pars);
void free_grid(struct grid *g);

void interpolate_constant(struct grid *g);
void interpolate_plm(struct grid *g);
void copy_to_rk(struct grid *g);
void update_cons(struct grid *g, double fac1, double fac2);
void update_cons_rk(struct grid *g, double fac1, double fac2);
void update_x(struct grid *g, double fac1, double fac2);
void update_x_rk(struct grid *g, double fac1, double fac2);

#endif
