all: randmst struct weight r malloc

randmst: randmst.c
	gcc randmst.c -o randmst

struct: struct.h
	gcc struct.h -o struct
     
weight: weight.h
	gcc weight.h -o weight

r: r.h
	gcc r.h -o r

malloc: malloc.h
	gcc malloc.h -o malloc

