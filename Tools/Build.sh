#!/usr/bin/env bash

cd ./LinC

make $1 
if [ $1 == "build" ]
then
    echo ""
    dotnet run ../Tests/test1.lua
fi
