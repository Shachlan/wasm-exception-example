build:
	mkdir -p bin && \
	emcc example.cpp -o ./bin/result.js \
			-s WASM=1 \
			-s DISABLE_EXCEPTION_CATCHING=0 \
			--bind
