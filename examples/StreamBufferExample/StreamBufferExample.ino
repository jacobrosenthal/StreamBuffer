//in and out and in. Forever
//abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcab

#include <StreamBuffer.h>
#include <ringbuffer.h>

ringbuffer rx(50);
ringbuffer tx(50);
StreamBuffer stream(rx,tx);
StreamBuffer externalaccess(tx,rx);

void setup() {
  Serial.begin(9600);

  externalaccess.write('a');
  externalaccess.write('b');
  externalaccess.write('c');
  
  delay(5000);
}

void loop() {

  while(stream.available()){
    char c = (char)stream.read();
    Serial.print(c);
    stream.write(c);
  }
    
  while(externalaccess.available()){
    char c = (char)externalaccess.read();
    Serial.print(c);
    externalaccess.write(c);
  }
}