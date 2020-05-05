// Copyright (c) 2019 Lightricks. All rights reserved.
// Created by Shachar Langbeheim.

#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/html5.h>

using emscripten::allow_raw_pointers;

int main() {
  EM_ASM(window.dispatchEvent(new CustomEvent("wasmLoaded")););
  return 0;
}

namespace example {

void throwException() { throw std::runtime_error("Check it out!"); }

std::string getExceptionMessage(int exceptionPtr) {
  return std::string(reinterpret_cast<std::exception *>(exceptionPtr)->what());
}

} // namespace example

EMSCRIPTEN_BINDINGS(Bindings) {
  emscripten::function("throwException", &example::throwException);
  emscripten::function("getExceptionMessage", &example::getExceptionMessage);
};
