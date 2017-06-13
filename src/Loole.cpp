// Copyright 2017 <Parham Alvani>

#include "Loole.h"

#include <nan.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string>

Loole::Loole(const std::string& name, Nan::Callback *callback) : AsyncWorker(callback) {
    this->path = name;
}

void Loole::Execute() {
    mknod(this->path.c_str(), S_IFIFO, 0);
}

void Loole::HandleOKCallback() {
    this->callback->Call(0, NULL);
}
