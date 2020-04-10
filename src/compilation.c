#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <string.h>
#include <dirent.h>

#include "getInstruction.c"
#include "getNumberOfBytes.c"
#include "functions.c"
#include "operations.c"
#include "hex2mneumonic.h"
#include "toHex.c"