if you have errors running, it will probably tell you it couldn't find a dll. They should be in your packages directory. If you need help, just shoot me a message on slack
- Sam B.


Hey guys just wanted to share a few things!
1. #pragma once is a better, more modern version of header guards. It is avalible on VC++, gcc and clang. We should prefer it to header guards. It is really bad to put both in a file though as it can cause link time errors
2. It is good practice to always put your system headers above your project headers to avoid link time errors. So instead of:
``` C++
#include "item.h"
#include <vector>
```
We should prefer:
``` C++
#include <vector>
#include "item.h"
```

These will help us avoid annoying errors!
Thanks!!! -Sam B.
