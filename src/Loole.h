// Copyright 2017 <Parham Alvani>

#ifndef SRC_LOOLE_H_
#define SRC_LOOLE_H_

#include <nan.h>

#include <string>

class Loole : public Nan::AsyncWorker {
 public:
     Loole(const std::string& name, Nan::Callback *callback);

     void Execute();

     void HandleOKCallback();
 private:
     std::string path;
};

#endif  // SRC_LOOLE_H_
