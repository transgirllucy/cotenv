# cotenv.h 

Simple single header dotenv library in C 

# Build Example

Just compile the build.c using

```command
 cc build.c -o build
```

# Quick Example

```c 
// cotenv.c 

#include <stdio.h>
#include "cotenv.h"

int main(int argc, char **argv) {
	if(load_cotenv(".env") != 0 {
		return EXIT_FAILURE
	}
	
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
