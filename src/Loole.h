// Copyright 2017 <Parham Alvani>

#ifndef SRC_LOOLE_H_
#define SRC_LOOLE_H_

#include <nan.h>

#include <string>

class Loole : public Nan::AsyncWorker {
 public:
     Loole(const std::string& name, Nan::Callback *callback);
     explicit Loole(Nan::Callback *callback);

     void Execute();

     void HandleOKCallback();

     static void unlink(const std::string& name);
 private:
     std::string path;
     std::string errorMsg;
     int fds[2];
};

#endif  // SRC_LOOLE_H_
