#!/bin/bash

find $1 -type f -print0 | xargs -0 -I x bash -c 'echo -n $(sha256sum x) " "; echo $(wc -c x) | cut -d " " -f 1' | sort -nr --key=3 | uniq --check-chars=64 --all-repeated=separate | awk '{print $2 "|" $3}' | column -t -s "|" --table-columns Path,Bytes
