all: r struct weight prim randmst

r: r.h
	gcc r.h -o r

struct: struct.h
	gcc struct.h -o struct

weight: weight.h
	gcc weight.h -o weight

prim: prim.h
	gcc prim.h -o prim

randmst: randmst.c
	gcc randmst.c -o randmst