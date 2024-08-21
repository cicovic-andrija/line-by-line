#ifndef LBL_DT_INTPAIR_H
#define LBL_DT_INTPAIR_H

/* dt_intpair.h */

typedef struct _intpair {
    int first;
    int second;
}
intpair;

typedef struct _intkv {
    int key;
    int val;
}
intkv;

typedef struct _intopt {
    int none;
    int i;
}
intopt;

#define OPT_INIT_NONE { 1, 0 }

#endif /* LBL_DT_INTPAIR_H */
