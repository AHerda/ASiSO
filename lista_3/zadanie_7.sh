find . -type f -print0 | xargs -0 -I x bash -c 'mv "x" $(echo "x" | tr [:upper:] [:lower:])'
