window.addEventListener("wasmLoaded", () => {
  try {
    Module.throwException();
  } catch (exception) {
    console.log(Module.getExceptionMessage(exception));
  }
});

const scriptTag = document.createElement("script");
scriptTag.src = "./bin/result.js";
document.body.appendChild(scriptTag);
