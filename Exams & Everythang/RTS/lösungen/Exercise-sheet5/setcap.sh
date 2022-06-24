#!/bin/bash
sudo setcap CAP_IPC_LOCK,CAP_SYS_NICE,CAP_SYS_TIME+eip $1
echo -n "Capabilities set to: "
sudo getcap $1
