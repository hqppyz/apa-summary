#include <stdio.h>
#include <stdlib.h>
#include "es1.h"
#include "es2.h"
#include "es3.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("ERROR: You must specify the exercise number.");
        return 1;
    }

    int es = atoi(argv[1]);
    switch (es) {
        case 1:
            return es1main(argc, argv);
        case 2:
            return es2main(argc, argv);
		case 3:
			return es3main(argc, argv);
    }
}

