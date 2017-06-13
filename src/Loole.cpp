// Copyright 2017 <Parham Alvani>

#include "Loole.h"

#include <nan.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string>
#include <cstring>

Loole::Loole(const std::string& name, Nan::Callback *callback)
    : AsyncWorker(callback) {
    this->path = name;
    this->errorMsg = "";
}

Loole::Loole(Nan::Callback *callback)
    : AsyncWorker(callback) {
    this->path = "";
    this->errorMsg = "";
}

void Loole::Execute() {
    int status;

    if (this->path.empty()) {
        status = pipe(this->fds);
    } else {
        status = mkfifo(this->path.c_str(), 0777);
    }
    if (!status) {
        char buf[1024];
        if (!strerror_r(errno, buf, 1024)) {
            this->errorMsg = std::string(buf);
        }
    }
}

void Loole::HandleOKCallback() {
    if (!this->errorMsg.empty()) {
        v8::Local<v8::Value> argv[] = {
            Nan::Error(this->errorMsg.c_str())
        };
        this->callback->Call(1, argv);
    } else if (!this->path.empty()) {
        v8::Local<v8::Value> argv[] = {
            Nan::Null()
        };
        this->callback->Call(1, argv);
    } else {
        v8::Local<v8::Value> argv[] = {
            Nan::Null(),
            Nan::New<v8::Number>(this->fds[0]),
            Nan::New<v8::Number>(this->fds[1])
        };
        this->callback->Call(3, argv);
    }
}
