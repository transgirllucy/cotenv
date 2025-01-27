# cotenv.h 

Simple single header dotenv library in C 

# Build Example / Tests

Just compile the build.c or tests.c using

```command
 cc build.c -o build
```

# Quick Example

```c 
// cotenv.c 

#include <stdio.h>
#include "cotenv.h"

int main(int argc, char **argv) {
	load_cotenv(".env");

	const char *world = getenv("WORLD");
	if (world) {
		printf("Hello %s", world);
	} else {
		printf("WORLD not found");
	}
}

```


# References

- https://github.com/tsoding/nob.h?
- https://github.com/Isty001/dotenv-c
