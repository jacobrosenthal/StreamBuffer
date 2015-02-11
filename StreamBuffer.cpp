#include "StreamBuffer.h"

StreamBuffer::StreamBuffer(ringbuffer &writebuf, ringbuffer &readbuf)
  : _writebuf(&writebuf)
  , _readbuf(&readbuf)
{}

StreamBuffer::~StreamBuffer() {
  this->_writebuf = 0;
  this->_readbuf = 0;
}

int StreamBuffer::available() {
  return _readbuf->available();
}

int StreamBuffer::peek() {
  if (_readbuf->available()) {
    return _readbuf->peek();
  } else {
    return -1;
  }
}

// have to have but not certain theres anything for it to do
void StreamBuffer::flush() {}

int StreamBuffer::read() {
  // if the head isn't ahead of the tail, we don't have any characters
  if (_readbuf->available()) {
    return _readbuf->pop();
  } else {
    return -1;
  }
}

size_t StreamBuffer::write(uint8_t c) {
  _writebuf->push(c);
  return 1;
}

size_t StreamBuffer::write(const uint8_t *buffer, size_t size) {
  size_t n = 0;
  while (size--) {
    _writebuf->push(*buffer++);
    n++;
  }
  return n;
}
