IPC
======================

[ipc]: https://github.com/percy00010/os/tree/master/ipc

  - [IPC](#ipc)
  - [Use](#use)
  - [Examples](#examples)

## IPC ##
  Inter Process Comunication - OS
## Use ##

### Steps ###
    - open terminal (Ctrl+Alt+T)
    - compile program with make,
    - go to bin directory (cd bin)
    - open 5 terminals
    - run:
      - 1. ./jm-receive.exe
      - 2. ./jm-shm.exe
      - 3. ./jm-signal.exe
      - 4. ./jm-pipe.exe
      - 5. ./jm-mqc.exe

  In the pipe and signal, any is executed, only that first in jm-pipe.exe the PID of jm-signal.exe is filled, then the jm-signal.exe is filled with the PID of jm-pipe.exe. Necessarily in that order. Synchronous signal
## Examples

<!--:sparkles: :camel: :boom:-->

* * *
[Percy Maldonado Quispe UCSP](https://github.com/percy00010)
