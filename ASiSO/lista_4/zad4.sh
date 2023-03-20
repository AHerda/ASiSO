#!/bin/bash

find $1 -type f -print0 | xargs -0 -I x bash -c $'echo -n $(sha256sum  -- "x") " "; echo $(wc -c -- "x") | cut -f1 -d " "' | sort -nr --key=3 | uniq --check-chars=64 -D | cut -c 66- | column -t --table-columns Path,Bytes
