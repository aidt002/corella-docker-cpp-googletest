FROM alpine:3.21.3@sha256:a8560b36e8b8210634f77d9f7f9efd7ffa463e380b75e2e74aff4511df3ef88c

# Install build dependencies
RUN apk add --no-cache \
      alpine-sdk \
      clang \
      cmake \
      samurai \
      git \
      valgrind \
      linux-headers

WORKDIR /app

# Copy all source files and build configuration
COPY CMakeLists.txt .
COPY include ./include
COPY src ./src
COPY tests ./tests

# Configure and build dependencies
RUN cmake -S . -B build-deps

COPY run_tests.sh ./

CMD ["sh"] 