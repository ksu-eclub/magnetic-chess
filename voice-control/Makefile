GEN_SOURCES = \
	server/magnetic_chess/chess_service.pb.go

SOURCES = $(GEN_SOURCES) \
	server/abi.go \
	server/gatt.go \
	server/grpc.go \
	server/move.go \
	server/Run.go \
	server/state.go \
	main.go

EXE_NAME = voice-control

.PHONY: all
all: $(EXE_NAME)

.PHONY: clean
clean:
	rm -rf $(EXE_NAME) $(GEN_SOURCES)

$(EXE_NAME): $(SOURCES)
	go build
	sudo setcap 'cap_net_raw,cap_net_admin=eip' $@

server/magnetic_chess/chess_service.pb.go: ../logic/rpc/chess_service.proto
	protoc -I../logic/rpc $< --go_out=plugins=grpc:server/magnetic_chess
