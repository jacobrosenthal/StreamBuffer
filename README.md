#StreamBuffer

Arduino Stream object that buffers data. You'll need to download and import ringbuffer as well. By creating a second StreamBuffer object reversing the read and write ringbuffers you can allows read what the other StreamBuffer writes.

##Install
As usual, download zip, unzip and rename to remove the dash character and place in your Arduino Libraries folder, on MacOSX ~/Documents/Arduino/libraries/

##Use
Create a StreamBuffer.
```cpp
#include <StreamBuffer.h>
#include <ringbuffer.h>

ringbuffer rx(50);
ringbuffer tx(50);
StreamBuffer stream(rx,tx);
StreamBuffer externalaccess(tx,rx);
```

Now you can do all the usual read/writey stuff to stream and get that data out from externalaccess
```cpp
stream.write('a');
char c = externalaccess.read(); // 'a'
```
