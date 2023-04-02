#!/bin/bash

echo $(curl -s https://api.chucknorris.io/jokes/random | jq -r .value)


curl -s $(curl -s https://api.thecatapi.com/v1/images/search | jq -r .[].url) > image.jpg
catimg image.jpg
rm image.jpg
