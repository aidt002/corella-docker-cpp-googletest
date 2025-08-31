#!/bin/sh

DOCKER_TAG=${1:-my-app}
DOCKER_DEFAULT_PLATFORM=$2

if [ -n "$DOCKER_DEFAULT_PLATFORM" ]; then
    docker build --progress=plain --platform "$DOCKER_DEFAULT_PLATFORM" -t "$DOCKER_TAG" .
else
    docker build --progress=plain -t "$DOCKER_TAG" .
fi
