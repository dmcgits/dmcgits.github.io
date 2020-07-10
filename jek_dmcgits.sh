#!/bin/bash

dmcgits="/mnt/hgfs/w/dmcgits.io"
jekyll_docker_cmd="docker-compose up"

export DOCKER_HOST=127.0.0.1:4000
cd $dmcgits
$jekyll_docker_cmd

