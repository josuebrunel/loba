#!/bin/sh

status=0

BIN_DIR="/home/godbod/Documents/NetCom/bin"

ps cax | grep loba > /dev/null

if [ $? -eq 0 ]
then
   echo "Process is running"
else
   echo "Launching loba"
   ${BIN_DIR}/loba &
fi

return $status
