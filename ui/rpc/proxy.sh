#!/bin/bash
set -e

eval "$(go env)"
if [ ! -x "$GOPATH/bin/grpcwebproxy" ]; then
    go get "github.com/improbable-eng/grpc-web/go/grpcwebproxy"
fi

"$GOPATH/bin/grpcwebproxy" --allow_all_origins --backend_addr="localhost:50051" --run_tls_server=false
