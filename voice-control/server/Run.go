package server

var errCh = make(chan error)

// Run the server
func Run() error {
	go grpcInit()
	go gattInit()
	err := <-errCh
	grpcCleanup()
	return err
}
