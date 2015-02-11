#ifndef _StreamBuffer_H
#define _StreamBuffer_H

#include "Arduino.h"
#include "ringbuffer.h"

class StreamBuffer : public Stream {
 public:
    StreamBuffer(ringbuffer &writebuf, ringbuffer &readbuf);
    ~StreamBuffer();

    int available();
    int peek();
    void flush();

    int read();

    size_t write(uint8_t c);
    size_t write(const uint8_t *buffer, size_t size);

 private:
    ringbuffer *_readbuf;
    ringbuffer *_writebuf;
};

#endif  // _StreamBuffer_H
