#pragma once



#define NOT(X) !(X)
#define ADD(A, B) ((A) + (B))
#define SUB(A, B) ((A) - (B))

#define IN(P) fastPinMode(P, INPUT)
#define OUT(P) fastPinMode(P, OUTPUT)

#define SET(P, STAT) fastDigitalWrite(P, STAT)
#define EN(P) SET(P, ENABLE)
#define DIS(P) SET(P, DISABLE)
#define POS(P) SET(P, POSITIVE)
#define NEG(P) SET(P, NEGATIVE)
#define OPEN(P) SET(P, POSITIVE)
#define CLOSE(P) SET(P, NEGATIVE)
#define WATER(P) OPEN(P)
#define BLEACH(P) CLOSE(P)
#define CCW(P) POS(P)
#define CW(P) NEG(P)

#define GET(P) fastDigitalRead(P)

#define POS_NUM(n) return (n > 0);
#define NEG_NUM(n) return (n < 0);

// Macros for bit masks
#define cu(x)      ({__typeof__(x) _x = (x); (_x)*(_x)*(_x);})
#define RADIANS(d) ((d)*float(M_PI)/180.0f)
#define DEGREES(r) ((r)*180.0f/float(M_PI))
#define HYPOT2(x,y) (sq(x)+sq(y))
#define NORMSQ(x,y,z) (sq(x)+sq(y)+sq(z))

#define CIRCLE_AREA(R) (float(M_PI) * sq(float(R)))
#define CIRCLE_CIRC(R) (2 * float(M_PI) * float(R))

#define SIGN(a) ({__typeof__(a) _a = (a); (_a>0)-(_a<0);})
#define IS_POWER_OF_2(x) ((x) && !((x) & ((x) - 1)))

// Macros to make a string from a macro
#define STRINGIFY_(M) #M
#define STRINGIFY(M) STRINGIFY_(M)

// Maths
#define ABS(a) ({__typeof__(a) _a = (a); _a >= 0 ? _a : -_a;})

// Option Testing
#define _CAT(a,V...) a##V
#define CAT(a,V...) _CAT(a,V)

#define _ISENA_     ~,1
#define _ISENA_1    ~,1
#define _ISENA_0x1  ~,1
#define _ISENA_true ~,1
#define _ISENA(V...)        IS_PROBE(V)
#define IS_PROBE(V...) SECOND(V, 0)     // Get the second item passed, or 0

#define _ENA_1(O)           _ISENA(CAT(_IS,CAT(ENA_, O)))
#define _DIS_1(O)           NOT(_ENA_1(O))
//#define ENABLED(V...)       DO(ENA,&&,V)
//#define DISABLED(V...)      DO(DIS,&&,V)
//#define COUNT_ENABLED(V...) DO(ENA,+,V)

#define TERN(O,A,B)         _TERN(_ENA_1(O),B,A)    // OPTION ? 'A' : 'B'
#define TERN0(O,A)          _TERN(_ENA_1(O),0,A)    // OPTION ? 'A' : '0'
#define TERN1(O,A)          _TERN(_ENA_1(O),1,A)    // OPTION ? 'A' : '1'
#define TERN_(O,A)          _TERN(_ENA_1(O),,A)     // OPTION ? 'A' : '<nul>'
#define _TERN(E,V...)       __TERN(_CAT(T_,E),V)    // Prepend 'T_' to get 'T_0' or 'T_1'
#define __TERN(T,V...)      ___TERN(_CAT(_NO,T),V)  // Prepend '_NO' to get '_NOT_0' or '_NOT_1'
#define ___TERN(P,V...)     THIRD(P,V)              // If first argument has a comma, A. Else B.

// Primitives supporting precompiler REPEAT
#define FIRST(a,...)     a
#define SECOND(a,b,...)  b
#define THIRD(a,b,c,...) c