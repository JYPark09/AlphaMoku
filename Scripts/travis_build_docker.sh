#!/usr/bin/env bash

set -e

if [ $# -eq 0 ]
  then
    docker build -t jyp10987/alphamoku .
else
    docker build -f $1 -t jyp10987/alphamoku:$2 .
fi

docker run jyp10987/alphamoku
