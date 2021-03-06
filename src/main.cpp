// Copyright 2017 <Parham Alvani>

#include "Loole.h"

#include <nan.h>
#include <stdio.h>

#include <string>

NAN_METHOD(createFifo) {
    if (!info[0]->IsString()) {
        return Nan::ThrowError("name must be a string");
    }
    Nan::Utf8String name(info[0]);

    if (!info[1]->IsFunction()) {
        return Nan::ThrowError("callback must be a function");
    }
    v8::Local<v8::Function> callback = info[1].As<v8::Function>();

    Nan::AsyncQueueWorker(new Loole(*new std::string(*name),
                new Nan::Callback(callback)));
}

NAN_METHOD(createPipe) {
    if (!info[0]->IsFunction()) {
        return Nan::ThrowError("callback must be a function");
    }
    v8::Local<v8::Function> callback = info[0].As<v8::Function>();

    Nan::AsyncQueueWorker(new Loole(new Nan::Callback(callback)));
}

NAN_MODULE_INIT(init) {
      Nan::Set(target,
              Nan::New<v8::String>("createFifo").ToLocalChecked(),
              Nan::GetFunction(
                  Nan::New<v8::FunctionTemplate>(createFifo)).ToLocalChecked());
      Nan::Set(target,
              Nan::New<v8::String>("createPipe").ToLocalChecked(),
              Nan::GetFunction(
                  Nan::New<v8::FunctionTemplate>(createPipe)).ToLocalChecked());
}

NODE_MODULE(loole, init)
